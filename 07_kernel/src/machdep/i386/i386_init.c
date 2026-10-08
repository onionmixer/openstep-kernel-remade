/*
 * i386 kernel initialization and boot argument parsing (plan 248).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024).
 * Darwin 0.1 machdep/i386/i386_init.c was consulted for structure only.
 * getargs, isargsep, argstrcpy and getval are taken from NeXTMach
 * next/machargs.c (notice below) and edited to the form the original
 * kernel has (D013).
 */

/*
 * The following notice is from NeXTMach mk-108.1 next/machargs.c:
 *
 * Copyright (c) 1987, 1988 NeXT, Inc.
 */

/*
 * Lines marked "plan 400 (Darwin)" are the same declarations as Darwin 0.1
 * kernel/machdep/i386/i386_init.c:78-88 (kernel-1), whose notice is:
 */
/*
 * Copyright (c) 1999 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * "Portions Copyright (c) 1999 Apple Computer, Inc.  All Rights
 * Reserved.  This file contains Original Code and/or Modifications of
 * Original Code as defined in and that are subject to the Apple Public
 * Source License Version 1.0 (the 'License').  You may not use this file
 * except in compliance with the License.  Please obtain a copy of the
 * License at http://www.apple.com/publicsource and read it before using
 * this file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE OR NON-INFRINGEMENT.  Please see the
 * License for the specific language governing rights and limitations
 * under the License."
 * 
 * @APPLE_LICENSE_HEADER_END@
 */

#import <mach/mach_types.h>
#import <mach/machine.h>
#import <kern/mach_header.h>
#import <mach-o/loader.h>
#import <vm/vm_page.h>
#import <vm/pmap.h>

#import <machdep/i386/cpu_inline.h>
#import <machdep/i386/gdt.h>
#import <machdep/i386/idt.h>
#import <machdep/i386/configure.h>
#import <machdep/i386/intr_exported.h>
#import <machdep/i386/fp_exported.h>

#import <sys/reboot.h>
#import <sys/msgbuf.h>

/*
 * The boot loader's parameter block at physical 0x11000.  Only the
 * fields the kernel uses are named; the offsets are the original's.
 */
struct kernbootstruct {
	char		_pad0[2];
	char		bootString[0xae];	/* +0x002 */
	int		convmem;		/* +0x0b0 */
	int		extmem;			/* +0x0b4 */
	char		boot_file[0x80];	/* +0x0b8 */
	vm_offset_t	first_addr0;		/* +0x138 */
	char		_pad1[0x18];
	int		numBootDrivers;		/* +0x154 */
	char		_pad2[0x10];
	struct {
		vm_offset_t	address;
		vm_size_t	size;
	}		driverConfig[1];	/* +0x168 */
};
#define	KERNSTRUCT_ADDR	((struct kernbootstruct *) 0x11000)

extern int	nbuf;
extern char	rootdevice[];
static int	maxmem;

struct kernargs {
	char *name;
	int *i_ptr;
} kernargs[] = {
	"nbuf", &nbuf,
	"rootdev", (int *) rootdevice,
	"maxmem", &maxmem,
	0, 0,
};

#define	NBOOTFILE	64
char	boot_file[NBOOTFILE + 1];

static vm_offset_t	first_addr, last_addr;
static vm_offset_t	first_addr0, last_addr0;

vm_offset_t	virtual_avail, virtual_end;	/* plan 400 (Darwin): Darwin 0.1 i386_init.c:83 (was extern) */
vm_size_t	mem_size;			/* plan 400 (Darwin): Darwin 0.1 i386_init.c:88 (was extern) */
cpu_conf_t	cpu_config;			/* plan 400 (Darwin): Darwin 0.1 i386_init.c:78 */
struct mem_region	mem_region[2];		/* plan 400 (Darwin): Darwin 0.1 i386_init.c:85 */
int		num_regions;			/* plan 400 (Darwin): Darwin 0.1 i386_init.c:86 */
extern struct msgbuf	*pmsgbuf;

/* parameters passed from bootstrap loader */
int cnvmem = 0;		/* must be in .data section */
int extmem = 0;

static void	zero_fill_data(void);
static void	size_memory(void);
static void	machine_configure(void);

/*
 * Called from Protected mode,
 * flat 3G segmentation, paging disabled,
 * interrupts disabled.
 */
i386_init(void)
{
    register mem_region_t	rp;
    struct kernbootstruct	*kernBootStruct = KERNSTRUCT_ADDR;

    cnvmem = kernBootStruct->convmem;
    extmem = kernBootStruct->extmem;

    zero_fill_data();

    machine_configure();

    intr_initialize();

    us_spin_calibrate();

    page_size = 2*I386_PGBYTES;
    vm_set_page_size();

    getargs(kernBootStruct->bootString);

    size_memory();

    num_regions			= 1;

    rp				= (mem_region_t) &mem_region[0];
    rp->base_phys_addr =
	rp->first_phys_addr	= first_addr;
    rp->last_phys_addr		= last_addr;

    pmap_bootstrap(mem_region, num_regions, &virtual_avail, &virtual_end);

    locate_gdt((vm_offset_t) gdt + KERNEL_LINEAR_BASE);
    locate_idt((vm_offset_t) idt + KERNEL_LINEAR_BASE);

    dbf_init();

    /* console message buffer at the top of memory */
    mem_region[0].last_phys_addr -= round_page(sizeof (struct msgbuf));
    pmsgbuf = (struct msgbuf *) mem_region[0].last_phys_addr;
}

static
void
zero_fill_data(void)
{
    struct segment_command	*sgp;
    struct section		*sp;

    sgp = getsegbyname("__DATA");
    if (!sgp)
	return;

    sp = firstsect(sgp);
    if (!sp)
	return;

    do {
	if (sp->flags & S_ZEROFILL)
	    bzero(sp->addr, sp->size);
    } while (sp = nextsect(sgp, sp));
}

static inline
boolean_t
is486_or_higher(void)
{
    unsigned int	efl;

    efl = eflags();

    efl |= EFL_AC;
    set_eflags(efl);

    if ((efl & EFL_AC) == 0)
	return (FALSE);

    efl &= ~EFL_AC;
    set_eflags(efl);

    return (TRUE);
}

typedef struct _cpuid {
    unsigned int	step	:4,
			model	:4,
			family	:4,
			type	:2,
				:18;
} cpuid_t;

static inline
cpuid_t
cpuid(void)
{
    cpuid_t	value;

    asm volatile(
	"movl $1,%%eax; cpuid"
	    : "=a" (value)
	    :
	    : "ebx", "ecx", "edx");

    return (value);
}

#define EFL_ID		0x200000

static inline
boolean_t
is586(void)
{
    unsigned int	efl;
    cpuid_t		pid;

    efl = eflags();
    efl |= EFL_ID;
    set_eflags(efl);
    efl = eflags();
    if ((efl & EFL_ID) == 0)
	return (FALSE);
    pid = cpuid();
    efl &= ~EFL_ID;
    set_eflags(efl);
    if (pid.family != 5)
	return (FALSE);
    return (TRUE);
}

static
void
machine_configure(void)
{
    if (!is486_or_higher())
	for (;;)
	    asm volatile("hlt");

    enable_cache();

    fp_configure();

    machine_slot[0].is_cpu = TRUE;
    machine_slot[0].running = TRUE;

    machine_slot[0].cpu_type = CPU_TYPE_I386;

    if (is586())
	machine_slot[0].cpu_subtype = CPU_SUBTYPE_586;
    else if (cpu_config.fpu_type == FPU_HDW)
	machine_slot[0].cpu_subtype = CPU_SUBTYPE_486;
    else
	machine_slot[0].cpu_subtype = CPU_SUBTYPE_486SX;
}

static
void
size_memory(void)
{
    struct kernbootstruct	*kernBootStruct = KERNSTRUCT_ADDR;
    vm_offset_t		end_of_image, end_of_memory;
    int			i;
#define KB(x)		((x)*1024)

    end_of_image = getlastaddr();

    for (i=0; i < kernBootStruct->numBootDrivers; i++)
	end_of_image += kernBootStruct->driverConfig[i].size;

    if (maxmem)
	end_of_memory = KB(maxmem);
    else
	end_of_memory = KB(extmem);

    mem_size = end_of_memory;

    first_addr0 = round_page(kernBootStruct->first_addr0);
    last_addr0 = trunc_page(KB(cnvmem));

    first_addr = round_page(end_of_image);
    last_addr = trunc_page(end_of_memory);
#undef	KB
}

vm_offset_t
bios_extdata_addr(void)
{
    return (cnvmem * 1024);
}

vm_offset_t
alloc_cnvmem(
    vm_size_t	size,
    vm_offset_t	align
)
{
    static vm_offset_t	free_ptr, end_ptr;
    vm_offset_t		p;

    if (!free_ptr) {
	free_ptr = first_addr0;
	end_ptr = last_addr0;
    }

    p = (free_ptr + (align - 1)) & ~(align - 1);
    if ((p + size) > end_ptr)
	return ((vm_offset_t) 0);

    free_ptr = (p + size);

    return (p);
}

vm_offset_t
alloc_pages(
    vm_size_t	size
)
{
    vm_offset_t		p;

    {
	extern boolean_t	pmap_initialized;

	if (pmap_initialized)
	    panic("alloc_pages");
    }

    size = round_page(size);
    p = mem_region[0].first_phys_addr;
    mem_region[0].first_phys_addr += size;

    return (p);
}

/*
 * getargs, isargsep, argstrcpy, getval: NeXTMach next/machargs.c;
 * plan 248: no interactive mode, no printf, boot_file copied from the
 * boot struct, the flag letters a/s/d/f, the name compared up to '='
 * without cutting the string, argstrcpy terminates the copy.
 */
#define	NUM	0
#define	STR	1

getargs(char *args)
{
	extern char init_args[];
	char		*cp, c;
	struct kernargs *kp;
	extern int boothowto;
	int i;
	int val;
	struct kernbootstruct *kernBootStruct = KERNSTRUCT_ADDR;

	strncpy(boot_file, kernBootStruct->boot_file, NBOOTFILE);

	if (*args == 0) return 1;

	while(isargsep(*args)) args++;

	while (*args)
	{
		if (*args == '-')
		{
			char *ia = init_args;

			argstrcpy(args, init_args);
			do {
				switch (*ia) {
				    case 'a':
					boothowto |= RB_ASKNAME;
					break;
				    case 's':
					boothowto |= RB_SINGLE;
					break;
				    case 'd':
					boothowto |= RB_KDB;
					break;
				    case 'f':
#define RB_NOFP		0x00200000	/* don't use floating point */
				    	boothowto |= RB_NOFP;
					break;
				}
			} while (*ia && !isargsep(*ia++));
		}
		else
		{
			cp = args;
			while (!isargsep (*cp) && *cp != '=')
				cp++;
			if (*cp != '=')
				goto gotit;

			c = *cp;
			for(kp=kernargs;kp->name;kp++) {
				i = cp-args;
				if (strncmp(args, kp->name, i))
					continue;
				while (isargsep (*cp))
					cp++;
				if (*cp == '=' && c != '=') {
					args = cp+1;
					goto gotit;
				}

				switch (getval(cp, &val))
				{
					case NUM:
						*kp->i_ptr = val;
						break;
					case STR:
						argstrcpy(++cp, kp->i_ptr);
						break;
				}
				goto gotit;
			}
		}
gotit:
		/* Skip over current arg */
		while(!isargsep(*args)) args++;

		/* Skip leading white space (catch end of args) */
		while(*args && isargsep(*args)) args++;
	}

	return 0;
}

isargsep(c)
char c;
{
	if (c == ' ' || c == '\0' || c == '\t' || c == ',')
		return(1);
	else
		return(0);
}

argstrcpy(from, to)
char *from, *to;
{
	int i = 0;

	while (!isargsep(*from)) {
		i++;
		*to++ = *from++;
	}
	*to = 0;
	return(i);
}

getval(s, val)
register char *s;
int *val;
{
	register unsigned radix, intval;
	register unsigned char c;
	int sign = 1;

	if (*s == '=') {
		s++;
		if (*s == '-')
			sign = -1, s++;
		intval = *s++-'0';
		radix = 10;
		if (intval == 0)
			switch(*s) {

			case 'x':
				radix = 16;
				s++;
				break;

			case 'b':
				radix = 2;
				s++;
				break;

			case '0': case '1': case '2': case '3':
			case '4': case '5': case '6': case '7':
				intval = *s-'0';
				s++;
				radix = 8;
				break;

			default:
				if (!isargsep(*s))
					return (STR);
			}
		for(;;) {
			if (((c = *s++) >= '0') && (c <= '9'))
				c -= '0';
			else if ((c >= 'a') && (c <= 'f'))
				c -= 'a' - 10;
			else if ((c >= 'A') && (c <= 'F'))
				c -= 'A' - 10;
			else if (isargsep(c))
				break;
			else
				return (STR);
			if (c >= radix)
				return (STR);
			intval *= radix;
			intval += c;
		}
		*val = intval * sign;
		return (NUM);
	}
	*val = 1;
	return (NUM);
}
