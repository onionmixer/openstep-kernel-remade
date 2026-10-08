/*
 * kern/mach_fat.c -- choose the architecture of a fat file (plan 260).
 *
 * Written for this project from the OPENSTEP 4.2 x86 kernel object
 * [0x15c948, 0x15ca74) (D024).  Darwin 0.1 kern/mach_fat.c, a later
 * form that reads the header in place, was consulted for structure
 * only; this one maps the fat_arch table through the vnode pager.  The
 * selection loop is fixed by the bytes and may resemble Darwin's
 * (D027).
 */

#import <sys/param.h>
#import <sys/types.h>
#import <sys/uio.h>
#import <sys/vnode.h>

#import <kern/mfs.h>
#import <vm/vm_kern.h>
#import <vm/vnode_pager.h>
#import <mach/kern_return.h>
#import <mach/vm_param.h>
#import <mach/machine.h>
#import <mach-o/fat.h>
#import <architecture/byte_order.h>

/* load results (values as in Darwin 0.1 kern/mach_loader.h) */
typedef int	load_return_t;

#define LOAD_SUCCESS		0
#define LOAD_BADARCH		1	/* CPU type/subtype not found */
#define LOAD_BADMACHO		2	/* malformed mach-o file */
#define LOAD_NOSPACE		5	/* No VM available */

extern kern_return_t	vm_allocate_with_pager();
extern int		grade_cpu_subtype();

load_return_t
fatfile_getarch(
	struct vnode		*vp,
	struct fat_header	*header,
	struct fat_arch		*archret)
{
	vm_pager_t		pager;
	vm_offset_t		addr;
	vm_size_t		size;
	load_return_t		lret;
	struct machine_slot	*ms;
	struct fat_arch		*arch;
	struct fat_arch		*best_arch;
	int			grade;
	int			best_grade;
	int			nfat_arch;
	int			end_of_archs;

	pager = vnode_pager_setup(vp, FALSE, TRUE);

	/*
	 * The fat_arch table must lie within the file.
	 */
	nfat_arch = NXSwapBigLongToHost(header->nfat_arch);
	end_of_archs = sizeof(struct fat_header)
		+ nfat_arch * sizeof(struct fat_arch);
	if (end_of_archs > vp->vm_info->vnode_size)
		return(LOAD_BADMACHO);

	size = round_page(end_of_archs);
	if (size <= 0)
		return(LOAD_BADMACHO);

	/*
	 * Map the table into the kernel's map.
	 */
	addr = 0;
	if (vm_allocate_with_pager(kernel_map, &addr, size, TRUE, pager,
	    (vm_offset_t) 0) != KERN_SUCCESS)
		return(LOAD_NOSPACE);

	/*
	 * Take the arch of this cpu type with the best subtype grade.
	 */
	ms = &machine_slot[0];		/* plan 260: one cpu */
	best_arch = NULL;
	best_grade = 0;
	arch = (struct fat_arch *) (addr + sizeof(struct fat_header));
	for (; nfat_arch-- > 0; arch++) {
		if (NXSwapBigIntToHost(arch->cputype) != ms->cpu_type)
			continue;

		grade = grade_cpu_subtype(NXSwapBigIntToHost(arch->cpusubtype));

		if (grade > best_grade) {
			best_grade = grade;
			best_arch = arch;
		}
	}

	if (best_arch == NULL) {
		lret = LOAD_BADARCH;
	} else {
		archret->cputype	=
			    NXSwapBigIntToHost(best_arch->cputype);
		archret->cpusubtype	=
			    NXSwapBigIntToHost(best_arch->cpusubtype);
		archret->offset		=
			    NXSwapBigLongToHost(best_arch->offset);
		archret->size		=
			    NXSwapBigLongToHost(best_arch->size);
		archret->align		=
			    NXSwapBigLongToHost(best_arch->align);
		lret = LOAD_SUCCESS;
	}

	vm_map_remove(kernel_map, addr, addr + size);

	return(lret);
}
