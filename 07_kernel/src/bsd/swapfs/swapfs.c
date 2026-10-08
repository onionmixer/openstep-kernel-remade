/*
 * swapfs.c - compressed swap file system (plans 378, 387, 388; D054).
 *
 * Written for this project from the OPENSTEP 4.2 kernel bytes (D024,
 * __text [0x13a588, 0x13b714), __data [0x1dd7b4, 0x1dd964)).  No reference
 * tree has this file; the name and place are inferred from the link order
 * (after specfs, before ufs) and the "swapfs_grow" strings.
 */

#import <mach/boolean.h>
#import <sys/param.h>
#import <sys/systm.h>
#import <sys/user.h>
#import <sys/file.h>
#import <sys/vnode.h>
#import <sys/vfs.h>
#import <sys/errno.h>
#import <mach/mach_types.h>
#import <vm/vm_page.h>
#import <vm/vm_map.h>
#import <vm/vm_kern.h>
#import <kern/kalloc.h>
#import <kern/mfs.h>

/*
 * plan 397 (D058, D024; no evidence for this text): unreferenced constant
 * "swapfs" in the original __TEXT,__const (0x1d1276, 7 B, byte aligned).
 * Its name is not known.
 */
static const char swapfs_const_name[] = "swapfs";

/*
 * Map entry for each page of the swap space: block of the backing file
 * that holds the page, and the fragments used inside that block.
 */
struct swapfs_map {
	u_int		sm_block:24,
			sm_nfrag:4,
			sm_pos:4;
};

struct swapfs_data {
	vm_size_t	sd_fragsize;	/* page_size / 8 */
	u_long		sd_nmap;	/* map entries */
	struct vnode	*sd_vp;		/* backing file */
	struct swapfs_map *sd_map;
	u_long		sd_mappages;
	u_char		*sd_bitmap;	/* free fragments per block */
	u_long		sd_bitpages;
	u_long		sd_hipage;
	u_long		sd_hint;
	vm_offset_t	sd_rbuf;	/* read cache */
	vm_offset_t	sd_rphys;
	long		sd_rblock;
	u_char		sd_rdirty;
	vm_offset_t	sd_wbuf;	/* write cache */
	vm_offset_t	sd_wphys;
	vm_offset_t	sd_cbuf;	/* compression buffer */
	long		sd_wblock;
	u_char		sd_refcnt;
	u_char		sd_flags;
};

#define SD_LOCKED	0x1
#define SD_WANTED	0x2

struct swapnode {
	struct vnode	sn_vnode;
	struct swapfs_data sn_data;
};

#define VTOSN(vp)	((struct swapnode *)(vp)->v_data)

static struct vnodeops swapfs_vnodeops;
static int swapfs_getstats();

int	swapfs_cangrow = 1;
int	swapfs_enabled = 0;
int	compress_window_size = 20;
int	compress_threashold = 5;
int	compress_enable = 1;
int	compress_backoff_on = 0;
int	compress_backoff_off = 0;
int	compress_backoff_cnt;
int	compress_backoff_window;
int	maxswapdevice;
vm_map_t swapfs_bit_map;
vm_map_t swapfs_rem_map;

static struct {
	int	cin;
	int	rhit;
	int	whit;
	int	rflush;
	int	cout;
	int	wsame;
	int	rsame;
	int	wflush;
	int	winval;
	int	rinval;
	int	uout;
	int	uin;
	int	hintblock;
	int	newblock;
	u_long	maxblock;
	u_long	hipage;
	int	hist[9];
} swapfs_stats;

struct logswap {
	vm_offset_t	ls_offset;
	int		ls_page;
	u_char		ls_nfrag:4,
			ls_pos:4;
	char		ls_type;
};

int		logswapindex;
struct logswap	logswp[2000];

void
logswap(int type, vm_offset_t offset, int page, char nfrag, char pos)
{
	if (logswapindex >= 2000)
		logswapindex = 0;
	logswp[logswapindex].ls_offset = offset;
	logswp[logswapindex].ls_page = page;
	logswp[logswapindex].ls_nfrag = nfrag;
	logswp[logswapindex].ls_pos = pos;
	logswp[logswapindex].ls_type = type;
	logswapindex++;
}

static inline int
swapfs_fit(u_char *bits, int nfrag)
{
	u_char b = *bits;
	int mask;
	unsigned i;

	if (b == 0)
		return (-1);
	mask = (1 << nfrag) - 1;
	for (i = 0; i < 9 - nfrag; i++) {
		if ((b & mask) == mask) {
			*bits &= ~(mask << i);
			return (i);
		}
		b >>= 1;
	}
	return (-1);
}

static inline int
swapfs_findblock(struct swapfs_data *sd, int nfrag, u_long *blockp)
{
	u_long i;
	int full = 0xff;	/* plan 378: compared as an int (original movzx, cmp reg) */

	for (i = 0; i < sd->sd_hipage; i++)
		if (sd->sd_bitmap[i] == full) {
			*blockp = i;
			return (swapfs_fit(&sd->sd_bitmap[i], nfrag));
		}
	return (-1);
}

static int
swapfs_alloc(struct swapfs_data *sd, vm_offset_t offset, vm_size_t size,
	vm_offset_t *foffp, vm_offset_t *fragoffp)
{
	u_long block;
	u_long page = offset / page_size;
	u_long nfrag = size / sd->sd_fragsize;
	int pos;

	if (sd->sd_map[page].sm_nfrag == 0) {
		sd->sd_bitmap[page] = 0xff;
		if (page >= sd->sd_hipage)
			swapfs_stats.hipage = sd->sd_hipage = page + 1;
	} else {
		u_long oblock = sd->sd_map[page].sm_block;
		int onfrag = sd->sd_map[page].sm_nfrag;
		int opos = sd->sd_map[page].sm_pos;

		sd->sd_bitmap[oblock] |= ((1 << onfrag) - 1) << opos;
	}
	if (sd->sd_hint == sd->sd_rblock / page_size ||
	    sd->sd_hint == sd->sd_wblock / page_size)
		pos = swapfs_fit(&sd->sd_bitmap[sd->sd_hint], nfrag);
	else
		pos = -1;
	if (pos >= 0) {
		block = sd->sd_hint;
		swapfs_stats.hintblock++;
	} else {
		pos = swapfs_findblock(sd, nfrag, &block);
		if (pos < 0)
			goto fail;
		swapfs_stats.newblock++;
	}
	if (pos < 0)
		goto fail;
	sd->sd_map[page].sm_block = block;
	sd->sd_map[page].sm_pos = pos;
	sd->sd_map[page].sm_nfrag = nfrag;
	*foffp = block * page_size;
	*fragoffp = pos * sd->sd_fragsize;
	if (nfrag != page_size / sd->sd_fragsize)
		sd->sd_hint = block;
	if (swapfs_stats.maxblock < block)
		swapfs_stats.maxblock = block;
	return (1);
fail:
	return (0);
}

int
compress_data(vm_offset_t src, vm_size_t size, char *dst)
{
	int *p = (int *)src;
	int nwords = (size + 3) / 4;
	u_char *flags = (u_char *)dst + 4;
	char *out = &dst[(size + 3) / 32 + 4];
	u_char f = 0;
	int last = 0;
	int n = 0;
	unsigned i;

	while (n < nwords) {
		for (i = 0; i <= 7 && n < nwords; i++, n++) {
			f <<= 1;
			if (last != *p) {
				f |= 1;
				last = *p;
				*(int *)out = *p;
				out += 4;
				if (size == out - dst)
					return (size);
			}
			p++;
		}
		*flags++ = f;
	}
	*(int *)dst = size;
	return (out - dst);
}

int
uncompress_data(char *src, vm_size_t srcsize, vm_offset_t dst, vm_size_t size)
{
	int nwords = (size + 3) / 4;
	char *flags = &src[4];
	int *in = (int *)&src[(size + 3) / 32 + 4];
	int *p = (int *)dst;
	int last = 0;
	int n = 0;
	char f;
	unsigned i;

	while (n < nwords) {
		f = *flags++;
		for (i = 0; i <= 7 && n < nwords; i++, n++) {
			if (f < 0)
				*p++ = last = *in++;
			else
				*p++ = last;
			f <<= 1;
		}
	}
	return (nwords);
}

static inline int
swapfs_write(struct vnode *vp, vm_offset_t addr, vm_size_t size,
	vm_offset_t offset)
{
	vm_size_t end = offset + size;

	if (vp->vm_info->vnode_size < end)
		vp->vm_info->vnode_size = end;
	return (VOP_PAGEOUT(vp, addr, size, offset));
}

static inline void
swapfs_lock(struct vnode *vp)
{
	struct swapfs_data *sd = &VTOSN(vp)->sn_data;

	while (sd->sd_flags & SD_LOCKED) {
		sd->sd_flags |= SD_WANTED;
		sleep((caddr_t)&sd->sd_flags, PINOD);
	}
	sd->sd_flags |= SD_LOCKED;
}

static inline void
swapfs_unlock(struct vnode *vp)
{
	struct swapfs_data *sd = &VTOSN(vp)->sn_data;
	u_char flags = sd->sd_flags;

	sd->sd_flags = flags & ~SD_LOCKED;
	if (flags & SD_WANTED) {
		sd->sd_flags = flags & ~(SD_LOCKED|SD_WANTED);
		wakeup((caddr_t)&sd->sd_flags);
	}
}

static inline vm_size_t
swapfs_getmap(struct swapfs_data *sd, vm_offset_t offset, vm_offset_t *foffp,
	vm_offset_t *fragoffp)
{
	u_long page = offset / page_size;

	if (page >= sd->sd_nmap) {
		if (swapfs_cangrow == 1)
			panic("paging in beyond end-of-file");
		*foffp = offset;
		*fragoffp = 0;
		return (page_size);
	} else if (sd->sd_map[page].sm_nfrag == 0) {
		printf("pagein from uninitialized data\n");
		*foffp = offset;
		*fragoffp = 0;
		return (page_size);
	} else {
		*foffp = sd->sd_map[page].sm_block * page_size;
		*fragoffp = sd->sd_map[page].sm_pos * sd->sd_fragsize;
		return (sd->sd_map[page].sm_nfrag * sd->sd_fragsize);
	}
}

static inline int
swapfs_rcache(struct swapfs_data *sd, vm_offset_t block, vm_offset_t off,
	vm_offset_t *srcp)
{
	struct vm_page page_s;
	int error;

	swapfs_stats.cin++;
	if (sd->sd_rblock == block) {
		swapfs_stats.rhit++;
		*srcp = off + sd->sd_rbuf;
		return (0);
	}
	if (sd->sd_wblock == block) {
		swapfs_stats.whit++;
		*srcp = off + sd->sd_wbuf;
		return (0);
	}
	if (sd->sd_rdirty) {
		swapfs_stats.rflush++;
		error = swapfs_write(sd->sd_vp, sd->sd_rphys, page_size,
		    sd->sd_rblock);
		if (error) {
			printf("cannot flush input cache!\n");
			return (error);
		}
		sd->sd_rdirty = 0;
	}
	sd->sd_rblock = -1;
	page_s.phys_addr = sd->sd_rphys;
	error = VOP_PAGEIN(sd->sd_vp, &page_s, block);
	if (error == 0) {
		sd->sd_rblock = block;
		*srcp = off + sd->sd_rbuf;
	}
	return (error);
}

static pager_return_t
swapfs_pagein(struct vnode *vp, vm_page_t m, vm_offset_t offset)
{
	struct swapfs_data *sd = &VTOSN(vp)->sn_data;
	vm_offset_t foff;
	vm_offset_t fragoff;
	vm_size_t csize;
	vm_offset_t src;
	int error;

	swapfs_lock(vp);
	csize = swapfs_getmap(sd, offset, &foff, &fragoff);
	if (csize == page_size) {
		swapfs_stats.uin++;
		error = VOP_PAGEIN(sd->sd_vp, m, foff);
		swapfs_unlock(vp);
		return (error);
	}
	if (error = swapfs_rcache(sd, foff, fragoff, &src)) {
		swapfs_unlock(vp);
		return (error);
	}
	uncompress_data_to_phys(src, csize, m->phys_addr, page_size,
	    (int)foff / 8192);
	swapfs_unlock(vp);
	return (0);
}

int	swpgotcha = 0;

static inline int
swapfs_wcache(struct swapfs_data *sd, vm_offset_t src, vm_offset_t block,
	vm_offset_t off, vm_size_t size)
{
	struct vm_page page_s;
	int error;

	swapfs_stats.cout++;
	*(u_short *)src = block >> 13;
	if (block == sd->sd_wblock) {
		swapfs_stats.wsame++;
		compress_backoff_cnt++;
		bcopy((caddr_t)src, (caddr_t)(off + sd->sd_wbuf), size);
		if (sd->sd_rblock == block) {
			swpgotcha++;
			sd->sd_rblock = -1;
			sd->sd_rdirty = 0;
		}
		return (0);
	}
	if (sd->sd_rblock == block) {
		swapfs_stats.rsame++;
		compress_backoff_cnt++;
		bcopy((caddr_t)src, (caddr_t)(off + sd->sd_rbuf), size);
		sd->sd_rdirty = 1;
		return (0);
	}
	if (sd->sd_wblock != -1) {
		swapfs_stats.wflush++;
		error = swapfs_write(sd->sd_vp, sd->sd_wphys, page_size,
		    sd->sd_wblock);
		if (error) {
			printf("cannot flush output cache!\n");
			return (error);
		}
	}
	sd->sd_wblock = block;
	bcopy((caddr_t)src, (caddr_t)(off + sd->sd_wbuf), size);
	return (0);
}

static inline void
swapfs_invalidate(struct swapfs_data *sd, vm_offset_t block)
{
	if (sd->sd_wblock == block) {
		swapfs_stats.winval++;
		sd->sd_wblock = -1;
	}
	if (sd->sd_rblock == block) {
		swapfs_stats.rinval++;
		sd->sd_rblock = -1;
		sd->sd_rdirty = 0;
	}
}

static inline int
swapfs_grow(struct vnode *vp)
{
	struct swapfs_data *sd = &VTOSN(vp)->sn_data;
	vm_size_t size = (sd->sd_mappages + 1) * page_size;
	vm_offset_t addr;

	addr = kmem_mb_alloc(swapfs_rem_map, page_size);
	if (addr == 0)
		return (0);
	if (addr != (vm_offset_t)sd->sd_map + sd->sd_mappages * page_size)
		panic("swapfs_grow: bad rem");
	sd->sd_nmap = size / 4;
	sd->sd_mappages++;
	if (sd->sd_nmap > sd->sd_bitpages * page_size) {
		addr = kmem_mb_alloc(swapfs_bit_map, page_size);
		if (addr == 0) {
			sd->sd_mappages--;
			size = sd->sd_mappages * page_size;
			sd->sd_nmap = size / 4;
			return (0);
		}
		if (addr != (vm_offset_t)sd->sd_bitmap + page_size * sd->sd_bitpages)
			panic("swapfs_grow: bad freelist");
		sd->sd_bitpages++;
	}
	return (1);
}

static pager_return_t
swapfs_pageout(struct vnode *vp, vm_offset_t addr, vm_size_t size,
	vm_offset_t offset)
{
	struct swapfs_data *sd = &VTOSN(vp)->sn_data;
	vm_offset_t foff;
	vm_offset_t fragoff;
	vm_size_t csize;
	int error;

	swapfs_lock(vp);
	if (size != page_size)
		panic("csize != PAGE_SIZE: shouldn't happen\n");
	if (offset >= sd->sd_nmap * page_size && swapfs_cangrow == 1) {
		if (!swapfs_grow(vp))
			swapfs_cangrow = 0;
	}
	if (offset >= sd->sd_nmap * page_size) {
		logswap(1, offset, offset >> 13, 8, 0);
		error = swapfs_write(sd->sd_vp, addr, size, offset);
		swapfs_unlock(vp);
		return (error);
	}
	csize = compress_data_from_phys(addr, page_size, sd->sd_cbuf);
	if (compress_backoff_window >= compress_window_size) {
		if (compress_backoff_cnt >= compress_threashold) {
			compress_enable = 1;
			compress_backoff_on++;
			compress_backoff_cnt = 0;
		} else {
			compress_enable = 0;
			compress_backoff_off++;
			compress_backoff_cnt = compress_threashold;
		}
		compress_backoff_window = 0;
	}
	if (compress_enable == 0)
		csize = page_size;
	compress_backoff_window++;
	swapfs_stats.hist[csize / (page_size >> 3)]++;
	csize = (csize + sd->sd_fragsize - 1) / sd->sd_fragsize * sd->sd_fragsize;
	if (!swapfs_alloc(sd, offset, csize, &foff, &fragoff)) {
		printf("couldn't allocate an offset!\n");
		swapfs_unlock(vp);
		return (2);
	}
	if (csize >= page_size) {
		swapfs_invalidate(sd, foff);
		swapfs_stats.uout++;
		logswap(2, offset, (int)foff / 8192, (int)csize / 1024,
		    (int)fragoff / 1024);
		error = swapfs_write(sd->sd_vp, addr, size, foff);
		goto out;
	}
	logswap(3, offset, (int)foff / 8192, (int)csize / 1024,
	    (int)fragoff / 1024);
	error = swapfs_wcache(sd, sd->sd_cbuf, foff, fragoff, csize);
out:
	swapfs_unlock(vp);
	return (error);
}

static int
swapfs_mount(struct vfs *vfsp, char *path, caddr_t data)
{
	char *fname;
	struct file *fp;
	struct vnode *vp;
	struct swapnode *sn;
	vm_offset_t rbuf, wbuf, cbuf;
	vm_offset_t min, max;
	vm_size_t nmap;
	int error;

	if (maxswapdevice > 0)
		return (EBUSY);
	if (error = copyin(data, (caddr_t)&fname, sizeof (fname)))
		return (error);
	if (error = getvnodefp(fname, &fp))
		return (error);
	vp = (struct vnode *)fp->f_data;
	if (vp->v_type != VREG) {
		vn_rele(vp);
		return (ENOTDIR);
	}
	VN_HOLD(vp);
	/*
	 * plan 388: the three buffers come from one allocation, stepped
	 * through with sn before sn gets the node (original [0x13b35c, 0x13b383)).
	 */
	sn = (struct swapnode *)kalloc(page_size * 3);
	rbuf = (vm_offset_t)sn;
	sn = (struct swapnode *)((vm_offset_t)sn + page_size);
	wbuf = (vm_offset_t)sn;
	cbuf = wbuf + page_size;
	sn = (struct swapnode *)kalloc(sizeof (struct swapnode));
	bzero((caddr_t)sn, sizeof (struct swapnode));
	swapfs_bit_map = kmem_suballoc(kernel_map, &min, &max, 0x19000, FALSE);
	swapfs_rem_map = kmem_suballoc(kernel_map, &min, &max, 0x19000, FALSE);
	sn->sn_data.sd_bitpages = 1;
	sn->sn_data.sd_bitmap = (u_char *)kmem_mb_alloc(swapfs_bit_map, page_size);
	sn->sn_data.sd_map = (struct swapfs_map *)kmem_mb_alloc(swapfs_rem_map, page_size);
	sn->sn_data.sd_mappages = 1;
	nmap = page_size / 4;
	sn->sn_data.sd_nmap = nmap;
	sn->sn_data.sd_fragsize = page_size / 8;
	sn->sn_data.sd_rblock = -1;
	sn->sn_data.sd_rdirty = 0;
	sn->sn_data.sd_wblock = -1;
	sn->sn_data.sd_hint = 0;
	sn->sn_data.sd_hipage = 0;
	sn->sn_data.sd_refcnt = 0;
	sn->sn_data.sd_vp = vp;
	sn->sn_data.sd_rbuf = rbuf;
	sn->sn_data.sd_rphys = pmap_resident_extract(pmap_kernel(), rbuf);
	sn->sn_data.sd_wbuf = wbuf;
	sn->sn_data.sd_wphys = pmap_resident_extract(pmap_kernel(), wbuf);
	sn->sn_data.sd_cbuf = cbuf;
	bzero((caddr_t)sn->sn_data.sd_map, nmap * 4);
	VN_INIT(&sn->sn_vnode, vfsp, VREG, vp->v_rdev);
	sn->sn_vnode.v_flag |= VROOT;
	sn->sn_vnode.v_op = &swapfs_vnodeops;
	sn->sn_vnode.vm_info = 0;
	vm_info_init(&sn->sn_vnode);
	crhold(u.u_cred);
	sn->sn_vnode.vm_info->cred = u.u_cred;
	sn->sn_vnode.v_data = (caddr_t)sn;
	crhold(u.u_cred);
	vp->vm_info->cred = u.u_cred;
	vfsp->vfs_data = (caddr_t)sn;
	vfsp->vfs_fsid = vp->v_vfsp->vfs_fsid;
	vfsp->vfs_fsid.val[1] |= 0xc000;
	sysent[21].sy_narg = 1;
	sysent[21].sy_parallel = 0;
	sysent[21].sy_call = swapfs_getstats;
	maxswapdevice++;
	swapfs_enabled = 1;
	return (0);
}

static int
swapfs_getstats()
{
	struct a {
		caddr_t	buf;
	} *uap = (struct a *)u.u_ap;

	u.u_error = copyout((caddr_t)&swapfs_stats, uap->buf,
	    sizeof (swapfs_stats));
}

static int
swapfs_getattr(struct vnode *vp, struct vattr *vap, struct ucred *cred)
{
	struct swapnode *sn = VTOSN(vp);
	int error;

	if (error = VOP_GETATTR(sn->sn_data.sd_vp, vap, cred))
		return (error);
	vap->va_size = sn->sn_data.sd_hipage * page_size;
	vap->va_blocksize = page_size;
	vap->va_blocks = vap->va_size >> 9;
	vap->va_fsid |= 0xc000;
	return (0);
}

static int
swapfs_setattr(struct vnode *vp, struct vattr *vap, struct ucred *cred)
{
	struct swapnode *sn = VTOSN(vp);
	vm_size_t size = sn->sn_data.sd_hipage * page_size;
	int error;

	if (vap->va_size < size)
		vap->va_size = size;
	if (error = VOP_SETATTR(sn->sn_data.sd_vp, vap, cred))
		return (error);
	sn->sn_data.sd_vp->vm_info->vnode_size = vap->va_size;
	return (0);
}

static int
swapfs_inactive(struct vnode *vp)
{
	struct swapnode *sn = VTOSN(vp);

	if (sn->sn_data.sd_refcnt)
		sn->sn_data.sd_refcnt--;
	return (0);
}

static int
swapfs_nlinks(struct vnode *vp, int *l)
{
	*l = 1;
	return (0);
}

static int
swapfs_unmount(struct vfs *vfsp)
{
	vn_rele(VTOSN((struct vnode *)vfsp->vfs_data)->sn_data.sd_vp);
	return (0);
}

static int
swapfs_root(struct vfs *vfsp, struct vnode **vpp)
{
	struct vnode *vp = (struct vnode *)vfsp->vfs_data;

	VTOSN(vp)->sn_data.sd_refcnt++;
	*vpp = vp;
	vp->v_count++;
	return (0);
}

static int
swapfs_statfs(struct vfs *vfsp, struct statfs *sbp)
{
	struct vfs *rvfsp = VTOSN((struct vnode *)vfsp->vfs_data)->sn_data.sd_vp->v_vfsp;
	int error;

	if (error = VFS_STATFS(rvfsp, sbp))
		return (error);
	sbp->f_fsid.val[1] |= 0xc000;
	return (0);
}

static int
swapfs_sync()
{
	return (0);
}

static int
swapfs_invalop()
{
	return (EINVAL);
}

static int
swapfs_devblocksize()
{
	return (1024);
}

struct vfsops swapfs_vfsops = {
	swapfs_mount,
	swapfs_unmount,
	swapfs_root,
	swapfs_statfs,
	swapfs_sync,
	swapfs_invalop,
	swapfs_invalop
};

static struct vnodeops swapfs_vnodeops = {
	swapfs_invalop,		/* open */
	swapfs_invalop,		/* close */
	swapfs_invalop,		/* rdwr */
	swapfs_invalop,		/* ioctl */
	swapfs_invalop,		/* select */
	swapfs_getattr,
	swapfs_setattr,
	swapfs_invalop,		/* access */
	swapfs_invalop,		/* lookup */
	swapfs_invalop,		/* create */
	swapfs_invalop,		/* remove */
	swapfs_invalop,		/* link */
	swapfs_invalop,		/* rename */
	swapfs_invalop,		/* mkdir */
	swapfs_invalop,		/* rmdir */
	swapfs_invalop,		/* readdir */
	swapfs_invalop,		/* symlink */
	swapfs_invalop,		/* readlink */
	swapfs_invalop,		/* fsync */
	swapfs_inactive,
	swapfs_invalop,		/* bmap */
	swapfs_invalop,		/* strategy */
	swapfs_invalop,		/* bread */
	swapfs_invalop,		/* brelse */
	swapfs_invalop,		/* lockctl */
	swapfs_invalop,		/* fid */
	swapfs_invalop,		/* dump */
	swapfs_invalop,		/* cmp */
	swapfs_invalop,		/* realvp */
	swapfs_pagein,
	swapfs_pageout,
	swapfs_nlinks,
	swapfs_devblocksize,
	0,			/* prepagein */
	0			/* apageout */
};
