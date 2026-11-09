/* plan 753 (D104, D167, D168, D024) the 1997 m68k locore.s from NeXTMach next/locore.s; changed lines are marked plan 744-753.  Names that are this project's, not the original source's (D168): R_A6, THREAD_TASK, TASK_U_ADDRESS, FSAVE_BIT, IRSO1997, IMM0, IMM1, move_space_done;
 * the values are from the original bytes (the define block).  NeXTMach text that no longer affects the object (unused defines and macros, NCPUS/FIXME/NIPLMEAS parts) is kept (D168). */
/* plan 754 (D167, D168, D024) BEGIN: assym constants and T_* (the define block; values from the original bytes, project names marked in their lines) */
#define	REGS 0
#define	R_D0 0
#define	R_SP 60
#define	R_A6 56	/* plan 745: a6 slot of the 16-register frame (14*4; R_SP is 15*4); this project's name (not the original source's), value from the original bytes (D168) */
#define	FSIZE 28
#define	R_SR 64
#define	R_PC 66
#define	FMT 70
#define	VOR 70
#define	FAKE_SIZE 72
#define	SSW 74
#define	FAULTADDR 80
#define	STAGEB 100
#define	SIZEOF_NORMAL6 4
#define	SIZEOF_SHORTBUS 24
#define	SIZEOF_LONGBUS 84
#define	SIZEOF_ACCESS 52
#define	FAULTD_BIT 8
#define	FAULTB_BIT 14
#define	FAULTC_BIT 15
#define	READ_BIT 6
#define	SSW_040 76
#define	FAULTADDR_040 84
#define	ATC_BIT 10
#define	RW_BIT 8
#define	MA_BIT 11
#define	LK_BIT 9
#define	SIZEOF_PCB 416
#define	FLAGS 84
#define	AST 84
#define	FSAVE_BIT 6	/* plan 750, D168: original bclr/bset #6,a0@(84) around fsave (pcb flags bit; plan 743); this project's name (not the original source's), value from the original bytes */
#define	T_STRAY 0x00	/* plan 753: NeXTMach next/trap.h:17; original mmu_type entry at 0x4002170 */
#define	T_BUSERR 0x08	/* plan 753: original movel #8,sp@- at 0x4002158; same value as 07 trap.c */
#define	T_ADDRERR 0x0c	/* plan 753: original movel #12,sp@- at 0x4001f7e; same value as 07 trap.c */
#define	T_MMU_BUSERR 0x400	/* plan 753: original mmu_type entry 0x4002164; same value as 07 trap.c */
#define	T_MMU_LIMIT 0x404	/* plan 753: original mmu_type entry 0x4002168; same value as 07 trap.c */
#define	T_MMU_SUPER 0x408	/* plan 753: original mmu_type entry 0x400216c; same value as 07 trap.c */
#define	T_MMU_WRITE 0x40c	/* plan 753: original mmu_type entry 0x4002174; same value as 07 trap.c */
#define	T_MMU_INVALID 0x410	/* plan 753: original mmu_type entry 0x4002178 and movel #1040,d2 at 0x4002014; same value as 07 trap.c */
#define	TT1 88
#define	PCB_TT1 7
#define	AST_SCHED_BIT 4	/* plan 743: original btst #4 */
#define	TRACE_AST_BIT 2
#define	TRACE_USER_BIT 1
#define	FPC_INT 92
#define	FPC_EXT 404
#define	FPC_REGS 308
#define	THREAD_USER_REG 80
#define	SAVED_REGS 72
#define	SR_TSINGLE_BIT 15
#define	SR_SUPER_BIT 13
#define	VM_PROT_READ 1
#define	VM_PROT_WRITE 2
#define	P_LINK 0
#define	P_RLINK 4
#define	P_PRI 17
#define	P_STAT 19
#define	P_CURSIG 23
#define	P_SIG 24
#define	P_FLAG 40
#define	SSLEEP 1
#define	SRUN 3
#define	V_SWTCH 0
#define	V_TRAP 4
#define	V_SYSCALL 8
#define	V_INTR 12
#define	V_SOFT 16
#define	V_PDMA 20
#define	V_FAULTS 92
#define	V_PGREC 52
#define	V_FASTPGREC 112
#define	NMBCLUSTERS 512
#define	U_PROCP 0
#define	U_RU 358
#define	RU_MINFLT 32
#define	U_ERROR 100
#define	U_AR0 0
#define	THREAD_PCB 36
#define	THREAD_TASK 12	/* plan 746: original trap3 movl a1@(12),a1 (thread->task); this project's name (not the original source's), value from the original bytes (plan 743; D168) */
#define	TASK_U_ADDRESS 48	/* plan 746: original trap3 movl a1@(48),a1 (task->u_address); this project's name (not the original source's), value from the original bytes (plan 743; D168) */
#define	THREAD_RECOVER 112
#define	THREAD_AST 372
#define	AST_ZILCH 0
#define	UTHREAD 300
#define	UTASK 304

#define	IMM0 0	/* plan 745 (D167): INTRARG argument for ipl1: the body adds the # (the NeXT cpp drops an argument that starts with #) */
#define	IMM1 1	/* plan 745 (D167): INTRARG argument for ipl2 */
/* plan 754 END */
#define	D25B	1
#define	D43B	1
#define	D50D	0

/* 
 * Copyright (c) 1987, 1988 NeXT, Inc.
 *
 * HISTORY
 * 22-Aug-90  John Seamons (jks) at NeXT
 *	Added back in cache_inval_page.  This just does a cpushp on the 040.
 *
 * 31-May-90  Gregg Kellogg (gk) at NeXT
 *	Added simple_lock routines for non-debugging single_cpu case
 *	so that loadable servers will work.
 *
 * 29-Mar-90  John Seamons (jks) at NeXT
 *	Added back the cache flush trap for Sun binary compatibility.
 *
 * 06-Mar-90  Gregg Kellogg (gk) at NeXT
 *	Added AST_ZILCH and THREAD_AST in place of
 *	THREAD_EXIT_CODE and THREAD_EXIT.
 *
 * 28-Feb_90  John Seamons (jks) at NeXT
 *	Changed cpu_type variable to be referenced as a byte, not a long.
 *
 * 16-Feb-88  John Seamons (jks) at NeXT
 *	Updated to Mach release 2.
 *
 * 20-Nov-86  John Seamons (jks) at NeXT
 *	Ported to NeXT.
 */ 

#import <cpus.h>
#import <cputypes.h>
#import <iplmeas.h>
#import <eventmeter.h>
#import <mach_ldebug.h>

/* plan 753 (D104, D168, D024) BEGIN: the include lines of the 07 staging (D104): m68k/ and mach/ headers for next/ and sys/kern_return.h; next/pcb.h and next/trap.h are not included (the assym constants are the define block, the T_* are defined above) */
#import <mach/kern_return.h>
#import <sys/errno.h>
#import <sys/reboot.h>

#import <m68k/cframe.h>
#import <mach/m68k/vm_param.h>
#import <m68k/vmparam.h>
#import <next/cpu.h>
#import <m68k/psl.h>
#import <m68k/mmu.h>
#import <m68k/reg.h>
#import <m68k/spl.h>
/* plan 753 END */

/* plan 744 (D167, D024) BEGIN: _sdata and the global _start_text removed (not in the original symbol table) */
/* plan 744 END */
	.text
	.globl	_start
_start:
	jmp	entry		// so start = lowest address in text seg

_start_text:
ZERO_PHYS:			// lowest address in object file

	/*
	 *	This is the interrupt stack that is switched to on
	 *	interrupt entry.  This keeps the size of individual
	 *	pre-thread kernel stacks smaller.  It is at the start of
	 *	the text segment so that we get a redzone for free.
	 *	Since the kernel text is direct mapped, references
	 *	that fall off the front will fault.
	 */

/* plan 744 (D167, D024) BEGIN: _intstacks (original 0x4000318 = _start+8; global _intstack and _eintstack are not in the original symbol table) */
	.align	2
	.globl	_intstacks
_intstacks:
	.skip	INTSTACK_SIZE
_eintstack:
/* plan 744 END */

	.data
#ifdef	DEBUG
	.globl	_lastsyscall
_lastsyscall:
	.long	0
#endif	DEBUG

#if	FIXME
	/*
	 *	We need a "fake" PCB to hold the values of the other
	 *	stack pointers during initialization (before we have
	 *	a real PCB).  We need one per CPU.
	 */

	.data
_startup_pcb:
	.skip	SIZEOF_PCB
#endif	FIXME

#if	NCPUS > 1
_start_lock:			// startup interlock
	.byte 0
_master_lock:			// master processor init interlock
	.byte 0
#endif	NCPUS > 1

	.globl	_cache
_cache:
	.long	0

	/*
	 *	The kernel is linked to start at the beginning of physical
	 *	memory in slot zero (0x04000000).  Absolute addressing
	 *	can be used right away even before the MMU is enabled.
	 *
	 *	Multiprocessor systems share the text/data/bss of
	 *	slot zero across the bus, however they maintain
	 *	their own kernel and interrupt stacks.
	 *	FIXME: setup seperate interrupt stack!
	 */

	.text
entry:
/* plan 749 (D167, D024) BEGIN: entry (original 0x4001318, 172 B): interrupt stack first, _m68k_init instead of _NeXT_init */
	lea	_eintstack,a0		// interrupt stack, with the monitor stack pointer saved on it
	movl	sp,a0@-
	movl	a0,sp
	movl	#0,a6
	jsr	_m68k_init
	addqw	#4,sp
/* plan 749 END */
	cmpb	#MC68030,_cpu_type
	beq	1f
	movl	#0,d0				// disable MMU
//	movc	d0,tc
	.long	0x4e7b0003
//	movc	d0,itt1				// disable previous TT1
	.long	0x4e7b0005
//	movc	d0,dtt1
	.long	0x4e7b0007
//	cinva	bc				// flush cache
	.word	0xf4d8
//	pflusha					// flush TLB
	.word	0xf518
/* plan 749 (D167, D024) BEGIN: original symbol name _m68k_kernel_mmu_* (NeXTMach _NeXT_kernel_mmu_*) */
	movl	_m68k_kernel_mmu_rp+4,d0	// only load rp_ptbr portion for 68040
/* plan 749 END */
//	movc	d0,srp
	.long	0x4e7b0807
/* plan 749 (D167, D024) BEGIN: original symbol name _m68k_kernel_mmu_* (NeXTMach _NeXT_kernel_mmu_*) */
	movl	_m68k_kernel_mmu_040_tt,d0
/* plan 749 END */
//	movc	d0,itt0
	.long	0x4e7b0004
//	movc	d0,dtt0
	.long	0x4e7b0006
/* plan 749 (D167, D024) BEGIN: original symbol name _m68k_kernel_mmu_* (NeXTMach _NeXT_kernel_mmu_*) */
	movl	_m68k_kernel_mmu_040_tc,d0
/* plan 749 END */
//	movc	d0,tc
	.long	0x4e7b0003
	bra	2f
1:
/* plan 749 (D167, D024) BEGIN: original symbol name _m68k_kernel_mmu_* (NeXTMach _NeXT_kernel_mmu_*) */
//	pmove	_m68k_kernel_mmu_030_tt,tt0	// transparently map kernel
/* plan 749 END */
	.long	0xf0390800
/* plan 749 (D167, D024) BEGIN: original symbol name _m68k_kernel_mmu_* (NeXTMach _NeXT_kernel_mmu_*) */
	.long	_m68k_kernel_mmu_030_tt
/* plan 749 END */
/* plan 749 (D167, D024) BEGIN: original symbol name _m68k_kernel_mmu_* (NeXTMach _NeXT_kernel_mmu_*) */
//	pmove	_m68k_kernel_mmu_rp,srp	// reconfigure MMU
/* plan 749 END */
	.long	0xf0394800
/* plan 749 (D167, D024) BEGIN: original symbol name _m68k_kernel_mmu_* (NeXTMach _NeXT_kernel_mmu_*) */
	.long	_m68k_kernel_mmu_rp
/* plan 749 END */
/* plan 749 (D167, D024) BEGIN: original symbol name _m68k_kernel_mmu_* (NeXTMach _NeXT_kernel_mmu_*) */
//	pmove	_m68k_kernel_mmu_030_tc,tc
/* plan 749 END */
	.long	0xf0394000
/* plan 749 (D167, D024) BEGIN: original symbol name _m68k_kernel_mmu_* (NeXTMach _NeXT_kernel_mmu_*) */
	.long	_m68k_kernel_mmu_030_tc
/* plan 749 END */
2:
	movl	_cache,d0		// enable cache
	movc	d0,cacr
/* plan 749 (D167, D024) BEGIN: the interrupt stack switch and the a6 clear are at the start of entry */
/* plan 749 END */

	/*
	 *  Record the fsave stack frame version number
	 */
	 .data
	 .globl		_fpu_version
_fpu_version:
	.long	1
	.text
	cmpb	#MC68040,_cpu_type
	bne	5f
	frestore _fpu_version		// restore null frame to reset FPU
	fmovel	_fpu_version,fp0	// so we get an 'idle' frame..
	fsave	_fpu_version		// ..when the fsave is done
5:
	jsr	_startup_early		// early initializaion
	jsr	_setup_main		// returns initial thread in d0
/* plan 749 (D167, D024) BEGIN: the end of entry (original 0x40013b6-0x40013c4): the initial thread to _start_initial_context; the NeXTMach PCB set-up, rte, _main, _start_init and _thread_bootstrap are not in the 1997 unit */
	movl	d0,sp@-
	jsr	_start_initial_context
/* plan 749 END */

PROCENTRY (curipl)
	movw	sr,d0
	lsrl	#8,d0
	andl	#7,d0
	PROCEXIT

#ifdef DEBUG
	.globl	_callsite
_callsite:
	movl	a6@(4),d0
	rts

	.globl	_getfp
_getfp:
	movl	a6,d0
	rts
#endif DEBUG

PROCENTRY (pflush_super)
	cmpb	#MC68030,_cpu_type
	beq	1f

	/* need to flush I/D cache when changing page attributes */
#if	D25B || D43B
	nop
#endif	D25B || D43B
//	cpusha	bc
	.word	0xf4f8
//	pflusha
	.word	0xf518
	bra	2f
1:
//	pflush	#0x14,#0x4
	.long	0xf0003094
2:
	PROCEXIT

PROCENTRY (pflush_user)
	cmpb	#MC68030,_cpu_type
	beq	1f

	/* need to flush I/D cache when changing page attributes */
#if	D25B || D43B
	nop
#endif	D25B || D43B
//	cpusha	bc
	.word	0xf4f8
//	pflushan
	.word	0xf510
	bra	2f
1:
//	pflush	#0x10,#0x4
	.long	0xf0003090
2:
	PROCEXIT

/* plan 751 (D167, D024) BEGIN: _tlb_update_read (original 0x4001412; NeXTMach pload_read) */
PROCENTRY (tlb_update_read)
/* plan 751 END */
	movl	a_p0,d0
	movl	a_p1,a0
	cmpb	#MC68030,_cpu_type
	beq	1f
	movc	dfc,d1
	movc	d0,dfc
//	ptestr	a0@
	.word	0xf568
	movc	d1,dfc
	bra	2f
1:
//	pload	#0x8,a0@,READ
	.long	0xf0102208
2:
	PROCEXIT

/* plan 751 (D167, D024) BEGIN: _tlb_update_write (original 0x4001440; NeXTMach pload_write) */
PROCENTRY (tlb_update_write)
/* plan 751 END */
	movl	a_p0,d0
	movl	a_p1,a0
	cmpb	#MC68030,_cpu_type
	beq	1f
	movc	dfc,d1
	movc	d0,dfc
/* plan 751 (D167, D024) BEGIN: original _tlb_update_write has ptestw (0xf548) */
#define	PTESTW_BUG	0
/* plan 751 END */
#if	PTESTW_BUG
//	ptestr	a0@
	.word	0xf568
#else	PTESTW_BUG
//	ptestw	a0@
	.word	0xf548
#endif	PTESTW_BUG
	movc	d1,dfc
	bra	2f
1:
//	pload	#0x8,a0@,WRITE
	.long	0xf0102008
2:
	PROCEXIT

PROCENTRY (pmove_crp)
	movl	a_p0,a0
	cmpb	#MC68030,_cpu_type
	beq	1f

	/* need to flush I/D cache when changing page attributes */
#if	D25B || D43B
	nop
#endif	D25B || D43B
//	cpusha	bc
	.word	0xf4f8
//	pflushan
	.word	0xf510
	movl	a0@(4),d0		// only load rp_ptbr portion for 68040
//	movc	d0,urp
	.long	0x4e7b0806
	bra	2f
1:
//	pmove	a0@,crp
	.long	0xf0104c00
2:
	PROCEXIT

PROCENTRY (pmove_tt1)
	movl	a_p0,a0
	cmpb	#MC68030,_cpu_type
	beq	1f
	movl	a0@,d0
//	movc	d0,itt1
	.long	0x4e7b0005
//	movc	d0,dtt1
	.long	0x4e7b0007
	bra	2f
1:
//	pmove	a0@,tt1
	.long	0xf0100c00
2:
	PROCEXIT

/* plan 751 (D167, D024) BEGIN: __move_space and _move_space_fault (original 0x40014be, 0x4001522; NeXTMach move_space) */
	.globl	__move_space
__move_space:
	link	a6,#0
	moveml	#0x2030,sp@-
	movl	_active_threads,a2
	movl	a2@(THREAD_RECOVER),sp@-
	movl	#_move_space_fault,a2@(THREAD_RECOVER)
	movl	a_p0,a0
	movl	a_p1,d0
	movc	dfc,d2
	movc	d0,dfc
	movl	a_p3,d0
	cmpl	#SIZE_LONG,a_p2
	bne	1f
	movsl	d0,a0@
	bra	3f
1:	cmpl	#SIZE_WORD,a_p2
	bne	2f
	movsw	d0,a0@
	bra	3f
2:	movsb	d0,a0@
3:	clrl	d0
move_space_done:
	movc	d2,dfc
	movl	sp@+,a2@(THREAD_RECOVER)
	moveml	sp@+,#0x0c04
	unlk	a6
	rts

	.globl	_move_space_fault
_move_space_fault:
	orl	a_p1,d0
	movl	a_p4,a3
	movl	d1,a3@
	movl	a_p5,a3
	movl	a0,a3@
	movl	a_p6,a3
	movl	a1,a3@
	jra	move_space_done
/* plan 751 END */

PROCENTRY (cache_push_page)
	movl	a_p0,a0
	cmpb	#MC68030,_cpu_type
	beq	1f
#if	D25B || D43B
	nop
#endif	D25B || D43B
//	cpushp	bc,a0@
	.word	0xf4f0
1:
	PROCEXIT

PROCENTRY (cache_inval_page)
	movl	a_p0,a0
	cmpb	#MC68030,_cpu_type
	beq	1f
#if	D25B || D43B
	nop
#endif	D25B || D43B
//	cpushp	bc,a0@
	.word	0xf4f0
	bra	2f
1:	movl	_cache,d0
	movc	d0,cacr
2:
	PROCEXIT

PROCENTRY (get_vbr)
	movc	vbr,d0
	PROCEXIT

PROCENTRY (set_vbr)
	movl	a_p0,d0
	movc	d0,vbr
	PROCEXIT

/* plan 744 (D167, D024) BEGIN: NeXTMach global_lock, bbcci and bbssi removed (not in the 1997 unit) */
/* plan 744 END */

/*
 *	WARNING FIXME:
 *		sfc & dfc not saved or restored
 *		assumes all counts are < 64K
 *		doesn't check for address wrap
 */

	.globl	_ALLOW_FAULT_START
_ALLOW_FAULT_START:

PROCENTRY (copyoutstr)			// (from_k, to_u, bytes, &copied)
	movl	#FC_USERD,d0		// set destination func code
	movc	d0,dfc
	movl	a_p0,a0			// from kernel
	movl	a_p1,a1			// to user
	movl	a_p2,d1			// byte count
	jle	copy_inval		// byte count < 0
	bra	2f
1:	movb	a0@+,d0
	movsb	d0,a1@+
	beq	3f			// null byte copied
2:	dbra	d1,1b
	addqw	#1,d1
3:	movl	a_p2,d0			// return # bytes copied
	subw	d1,d0
	extl	d0
	movl	a_p3,d1
	beq	copy_exit
	movl	d1,a0
	movl	d0,a0@
	bra	copy_exit

PROCENTRY (copyinstr)			// (from_u, to_k, bytes, &copied)
	movl	#FC_USERD,d0		// set source func code
	movc	d0,sfc
	movl	a_p0,a0			// from user
	movl	a_p1,a1			// to kernel
	movl	a_p2,d1			// byte count
	jle	copy_inval		// byte count < 0
	bra	2f
1:	movsb	a0@+,d0
	movb	d0,a1@+
	beq	3f			// null byte copied
2:	dbra	d1,1b
	addqw	#1,d1
3:	movl	a_p2,d0			// return # bytes copied
	subw	d1,d0
	extl	d0
	movl	a_p3,d1
	beq	copy_exit
	movl	d1,a0
	movl	d0,a0@
	bra	copy_exit

PROCENTRY (copystr)			// (from_k, to_k, bytes, &copied)
	// note: copystr does NOT catch faults
	movl	a_p0,a0			// from kernel
	movl	a_p1,a1			// to kernel
	movl	a_p2,d1			// byte count
	bra	2f
1:	movb	a0@+,a1@+
	beq	3f			// null byte copied
2:	dbra	d1,1b
	addqw	#1,d1
3:	movl	a_p2,d0			// return # bytes copied
	subw	d1,d0
	extl	d0
	movl	a_p3,d1
	beq	4f
	movl	d1,a0
	movl	d0,a0@
4:	clrl	d0
	PROCEXIT

#define	COPY_THRESH	64

/* plan 744 (D167, D024) BEGIN: _copyoutmsg alias of _copyout (original 0x400165e) */
	.globl	_copyoutmsg
_copyoutmsg:
/* plan 744 END */
PROCENTRY(copyout)
	movl	#FC_USERD,d0	// set destination func code
	movc	d0,dfc
	movl	a_p0,a0		// a0 = source address
	movl	a_p1,a1		// a1 = destination address
	movl	a_p2,d0		// d0 = length
	jeq	copy_exit	// byte count = 0
	jle	copy_inval	// byte count < 0

	movl	a1,d1		// compute dst - (dst & 3)
	negl	d1
	andl	#3,d1
	jra	2f

1:	movb	a0@+,d0		// copy bytes to get dst to long word boundary
	movsb	d0,a1@+
	subql	#1,a_p2		// update length
2:	dbeq	d1,1b		// byte count or alignment count exhausted

	movl	a_p2,d0	// d0 = length
3:	rorl	#2,d0		// longwords to move
	bra	5f
4:	movl	a0@+,d1
	movsl	d1,a1@+
5:	dbra	d0,4b
	roll	#2,d0

	btst	#1,d0		// copy last short
	jeq	6f
	movw	a0@+,d1
	movsw	d1,a1@+

6:	btst	#0,d0		// copy last byte
	jeq	copy_exit
	movb	a0@,d1
	movsb	d1,a1@

	bra	copy_exit

/* plan 744 (D167, D024) BEGIN: _copyinmsg alias of _copyin (original 0x40016d0) */
	.globl	_copyinmsg
_copyinmsg:
/* plan 744 END */
PROCENTRY(copyin)
	movl	#FC_USERD,d0	// set source func code
	movc	d0,sfc
	movl	a_p0,a0		// a0 = source address
	movl	a_p1,a1		// a1 = destination address
	movl	a_p2,d0		// d0 = length
	jeq	copy_exit	// byte count = 0
	jle	copy_inval	// byte count < 0

	movl	a1,d1		// compute dst - (dst & 3)
	negl	d1
	andl	#3,d1
	jra	2f

1:	movsb	a0@+,d0		// copy bytes to get dst to long word boundary
	movb	d0,a1@+
	subql	#1,a_p2		// update length
2:	dbeq	d1,1b		// byte count or alignment count exhausted

	movl	a_p2,d0		// d0 = length
3:	rorl	#2,d0		// longwords to move
	bra	5f
4:	movsl	a0@+,d1
	movl	d1,a1@+
5:	dbra	d0,4b
	roll	#2,d0

	btst	#1,d0		// copy last short
	jeq	6f
	movsw	a0@+,d1
	movw	d1,a1@+

6:	btst	#0,d0		// copy last byte
	jeq	copy_exit
	movsb	a0@,d1
	movb	d1,a1@

	bra	copy_exit

/*
 * "Safe" version of bcopy.  It will return EFAULT if there is a
 * error in a page fault caused by this routine.
 */

PROCENTRY(copywithin)
	movl	a_p0,a0		// a0 = source address
	movl	a_p1,a1		// a1 = destination address
	movl	a_p2,d0		// d0 = length
	jeq	copy_exit	// length == 0!
	jle	copy_inval

	cmpl	a0,a1
	jhi	rcopy		// gotta do reverse copy
	jeq	copy_exit	// src == dst!

	movl	a1,d1		// compute dst - (dst & 3)
	negl	d1
	andl	#3,d1
	jra	2f

1:	movb	a0@+,a1@+	// copy bytes to get dst to long word boundary
	subql	#1,d0
2:	dbeq	d1,1b		// byte count or alignment count exhausted

	movl	d0,d1		// 4 bytes moved per 2 byte instruction
	andl	#0x1c,d1	// so instruction offset is:
	lsrl	#1,d1		// 2 * (k - n % k)
	negl	d1
	addl	#18,d1		// + fudge term of 2 for indexed jump
	jmp	pc@(0,d1)	// now dive into middle of unrolled loop

3:	movl	a0@+,a1@+	// copy next <k> longs
	movl	a0@+,a1@+
	movl	a0@+,a1@+
	movl	a0@+,a1@+

	movl	a0@+,a1@+
	movl	a0@+,a1@+
	movl	a0@+,a1@+
	movl	a0@+,a1@+

	subl	#32,d0		// decrement loop count by k*4
	jge	3b

	btst	#1,d0		// copy last short
	jeq	4f
	movw	a0@+,a1@+

4:	btst	#0,d0		// copy last byte
	jeq	copy_exit
	movb	a0@,a1@

	bra	copy_exit

/*
 * Reverse copy
 */
rcopy:	addl	d0,a0		// point at end of source
	addl	d0,a1		// point at end of destination
	movl	a1,d1		// compute (dst & 3)
	andl	#3,d1
	jra	2f

1:	movb	a0@-,a1@-	// copy bytes to get src to long word boundary
	subql	#1,d0
2:	dbeq	d1,1b		// byte count or alignment count exhausted

	movl	d0,d1		// 4 bytes moved per 2 byte instruction
	andl	#0x1c,d1	// so instruction offset is:
	lsrl	#1,d1		// 2 * (k - n % k)
	negl	d1
	addl	#18,d1		// + fudge term of 2 for indexed jump
	jmp	pc@(0,d1)	// now dive into middle of unrolled loop

3:	movl	a0@-,a1@-	// copy next <k> longs
	movl	a0@-,a1@-
	movl	a0@-,a1@-
	movl	a0@-,a1@-

	movl	a0@-,a1@-
	movl	a0@-,a1@-
	movl	a0@-,a1@-
	movl	a0@-,a1@-

	subl	#32,d0		// decrement loop count by k*4
	jge	3b

	btst	#1,d0		// copy last short
	jeq	4f
	movw	a0@-,a1@-

4:	btst	#0,d0		// copy last byte
	jeq	copy_exit
	movb	a0@-,a1@-

	bra	copy_exit	// that's all folks!

copy_inval:
	movl	#EINVAL,d0
	PROCEXIT

/* plan 744 (D167, D024) BEGIN: _fault_error and _FAULT_ERROR (original 0x400182c) */
	.data
	.globl	_fault_error
_fault_error:
	.long	0
	.text
	.globl _FAULT_ERROR
_FAULT_ERROR:
	movl	_fault_error,d0
	PROCEXIT
/* plan 744 END */

copy_exit:
	clrl	d0
	PROCEXIT

	.globl	_ALLOW_FAULT_END
_ALLOW_FAULT_END:

	.globl	_fast_setjmp
_fast_setjmp:
	movl	sp@(4),a0
	movl	sp@,a0@
	movl	a6,a0@(44)
	movl	sp,a0@(48)
	clrl	d0
	rts

	.globl	_setjmp
_setjmp:
	movl	sp@(4),a0
	movl	sp@,a0@
	moveml	#0xfcfc,a0@(4)		// d2-d7, a2-a7
	clrl	d0
	rts

	.globl	_longjmp
_longjmp:
	movl	sp@(4),a0
	moveml	a0@(4),#0xfcfc		// d2-d7, a2-a7
	movl	a0@,sp@
	movl	#1,d0
	rts

	.data
	.globl	_probe_recover
_probe_recover:
	.long	0
	.text

PROCENTRY (probe_rb)
	movl	#1f,_probe_recover
	movl	a_p0,a0
	movb	a0@,d0
	clrl	_probe_recover
	movql	#1,d0
	bra	2f
1:
	clrl	_probe_recover
	clrl	d0
2:
	PROCEXIT

/* plan 751 (D167, D024) BEGIN: _probe_rl (original 0x4001898): probe_rb with a longword read */
PROCENTRY (probe_rl)
	movl	#1f,_probe_recover
	movl	a_p0,a0
	movl	a0@,d0
	clrl	_probe_recover
	movql	#1,d0
	bra	2f
1:
	clrl	_probe_recover
	clrl	d0
2:
	PROCEXIT
/* plan 751 END */

#if	MACH_LDEBUG && (NCPUS == 1)
/*
 * Debugging version in kern/lock.c used.
 */
#elif	(NCPUS == 1)
 	.globl	_simple_lock_init, _simple_lock, _simple_unlock
_simple_lock_init:
_simple_lock:
_simple_unlock:
	rts

	.globl	_simple_lock_try
_simple_lock_try:
	movl	#1,d0
	rts
#else	MACH_LDEBUG
	.globl	_simple_lock_init
_simple_lock_init:
PROCENTRY (simple_unlock)
	movl	a_p0,a0
	clrl	a0@
	PROCEXIT

PROCENTRY (simple_lock)
1:
	movl	a_p0,a0
	tas	a0@
	bne	1b
	PROCEXIT

PROCENTRY (simple_lock_try)
	clrl	d0
	movl	a_p0,a0
	tas	a0@
	bne	1f
	movl	#1,d0
1:	PROCEXIT
#endif	MACH_LDEBUG && (NCPUS == 1)

	.globl	_ovbcopy
_ovbcopy:
	jmp	_bcopy		// libc bcopy() handles overlap

	.globl	_blkclr
_blkclr:
	jmp	_bzero

#ifdef	notdef
PROCENTRY (em_chirp_build)
	movl	a_p0,a1
	movw	#0x3ff,d0		| make 1k points
	fmoveb	#0,fp0			| f0 = 0 = theta
	fmovecrx #0x00,fp1		| f1 = pi = delta theta
	fscales	#10,fp1			| f1 = 1024 Hz
	fscales	#-15,fp1		| f1 = 2pi/64k = pi/32k
	fmovex	fp1,fp2
	fscales	#-12,fp2
1:	fsinx	fp0,fp3			| f3 = sin theta
	faddx	fp1,fp0			| update theta
	faddx	fp2,fp1			| update freq
	fscales	#11,fp3			| scale to 12 bits
	fmovew	fp3,a1@			| store left result
	movw	a1@+,a1@+		| store right result
	dbra	d0,1b			| done?
	PROCEXIT
#endif

//----sched stuff----//
	.text

/* plan 744 (D167, D024) BEGIN: NeXTMach set_cpu_number removed (not in the 1997 unit) */
/* plan 744 END */

/*
 *	Save and load kernel context by saving kernel register state in
 *	the pcb (user registers are saved in the kernel stack).
 *	We also save and restore the floating-point coprocessor here.
 */
 null_frame:
 	.long	0
	
/* plan 750 (D167, D024) BEGIN: the switch_context family (original 0x40018d8-0x4001b3e, 614 B); NeXTMach _save_context, _load_context and loadfpregs are not in the 1997 unit */
	.globl	__switch_context
__switch_context:
	movl	sp@(4),a0
	bclr	#FSAVE_BIT,a0@(AST)
	fsave	a0@(FPC_INT)
	tstb	a0@(FPC_INT)
	beq	1f
	bset	#FSAVE_BIT,a0@(AST)
//	fmovem	fpcr/fpsr/fpiar,a0@(FPC_EXT)
	.long	0xf228bc00
	.word	FPC_EXT
//	fmovem	fp0-fp7,a0@(FPC_REGS)
	.long	0xf228f0ff
	.word	FPC_REGS
	nop
	frestore null_frame
1:
	movl	sp@+,a1
	moveml	#0xffff,a0@(REGS)
	movl	sp@(4),a0
	tstb	a0@(FPC_INT)
	beq	2f
//	fmovem	a0@(FPC_EXT),fpcr/fpsr/fpiar
	.long	0xf2289c00
	.word	FPC_EXT
//	fmovem	a0@(FPC_REGS),fp0-fp7
	.long	0xf228d0ff
	.word	FPC_REGS
2:	nop
	frestore a0@(FPC_INT)
	tstb	a0@(FPC_INT)
	bne	3f
	fmovel	#128,fpcr
3:	cmpb	#MC68030,_cpu_type
	beq	4f
	movl	a0@(TT1),d0
//	movc	d0,itt1
	.long	0x4e7b0005
//	movc	d0,dtt1
	.long	0x4e7b0007
	bra	5f
4:
//	pmove	a0@(TT1),tt1
	.long	0xf0280c00
	.word	TT1
5:
	movl	sp@(8),a0@(R_D0)
	movl	a0@(R_SP),sp
	cmpb	#MC68030,_cpu_type
	bne	6f
	movl	_cache,d0
	movc	d0,cacr
6:	moveml	a0@(REGS),#0x7fff
	jmp	a1@

	.globl	__switch_context_discard
__switch_context_discard:
	movl	sp@(4),a0
	bclr	#FSAVE_BIT,a0@(AST)
	fsave	a0@(FPC_INT)
	tstb	a0@(FPC_INT)
	beq	1f
	bset	#FSAVE_BIT,a0@(AST)
//	fmovem	fpcr/fpsr/fpiar,a0@(FPC_EXT)
	.long	0xf228bc00
	.word	FPC_EXT
//	fmovem	fp0-fp7,a0@(FPC_REGS)
	.long	0xf228f0ff
	.word	FPC_REGS
	nop
	frestore null_frame
1:
	addql	#4,sp
	movl	sp@(4),a0
	tstb	a0@(FPC_INT)
	beq	2f
//	fmovem	a0@(FPC_EXT),fpcr/fpsr/fpiar
	.long	0xf2289c00
	.word	FPC_EXT
//	fmovem	a0@(FPC_REGS),fp0-fp7
	.long	0xf228d0ff
	.word	FPC_REGS
2:	nop
	frestore a0@(FPC_INT)
	tstb	a0@(FPC_INT)
	bne	3f
	fmovel	#128,fpcr
3:	cmpb	#MC68030,_cpu_type
	beq	4f
	movl	a0@(TT1),d0
//	movc	d0,itt1
	.long	0x4e7b0005
//	movc	d0,dtt1
	.long	0x4e7b0007
	bra	5f
4:
//	pmove	a0@(TT1),tt1
	.long	0xf0280c00
	.word	TT1
5:
	movl	sp@(8),a0@(R_D0)
	movl	a0@(R_SP),sp
	cmpb	#MC68030,_cpu_type
	bne	6f
	movl	_cache,d0
	movc	d0,cacr
6:	moveml	a0@(REGS),#0x7fff
	jmp	a1@

	.globl	__switch_context0
__switch_context0:
	addql	#4,sp
	movl	sp@(4),a0
	tstb	a0@(FPC_INT)
	beq	2f
//	fmovem	a0@(FPC_EXT),fpcr/fpsr/fpiar
	.long	0xf2289c00
	.word	FPC_EXT
//	fmovem	a0@(FPC_REGS),fp0-fp7
	.long	0xf228d0ff
	.word	FPC_REGS
2:	nop
	frestore a0@(FPC_INT)
	tstb	a0@(FPC_INT)
	bne	3f
	fmovel	#128,fpcr
3:	cmpb	#MC68030,_cpu_type
	beq	4f
	movl	a0@(TT1),d0
//	movc	d0,itt1
	.long	0x4e7b0005
//	movc	d0,dtt1
	.long	0x4e7b0007
	bra	5f
4:
//	pmove	a0@(TT1),tt1
	.long	0xf0280c00
	.word	TT1
5:
	movl	sp@(8),a0@(R_D0)
	movl	a0@(R_SP),sp
	cmpb	#MC68030,_cpu_type
	bne	6f
	movl	_cache,d0
	movc	d0,cacr
6:	moveml	a0@(REGS),#0x7fff
	jmp	a1@

	.globl	__stack_handoff
__stack_handoff:
	movl	sp@(4),a0
	bclr	#FSAVE_BIT,a0@(AST)
	fsave	a0@(FPC_INT)
	tstb	a0@(FPC_INT)
	beq	1f
	bset	#FSAVE_BIT,a0@(AST)
//	fmovem	fpcr/fpsr/fpiar,a0@(FPC_EXT)
	.long	0xf228bc00
	.word	FPC_EXT
//	fmovem	fp0-fp7,a0@(FPC_REGS)
	.long	0xf228f0ff
	.word	FPC_REGS
	nop
	frestore null_frame
1:
	movl	sp@(8),a0
	tstb	a0@(FPC_INT)
	beq	2f
//	fmovem	a0@(FPC_EXT),fpcr/fpsr/fpiar
	.long	0xf2289c00
	.word	FPC_EXT
//	fmovem	a0@(FPC_REGS),fp0-fp7
	.long	0xf228d0ff
	.word	FPC_REGS
2:	nop
	frestore a0@(FPC_INT)
	tstb	a0@(FPC_INT)
	bne	3f
	fmovel	#128,fpcr
3:	cmpb	#MC68030,_cpu_type
	beq	4f
	movl	a0@(TT1),d0
//	movc	d0,itt1
	.long	0x4e7b0005
//	movc	d0,dtt1
	.long	0x4e7b0007
	bra	5f
4:
//	pmove	a0@(TT1),tt1
	.long	0xf0280c00
	.word	TT1
5:
	cmpb	#MC68030,_cpu_type
	bne	6f
	movl	_cache,d0
	movc	d0,cacr
6:	rts

	.globl	__return_with_state
__return_with_state:
	movl	sp@(4),sp
	movl	sp@(R_SP),a0
	movc	a0,usp
	moveml	sp@,#0x7fff
	addw	#R_SR,sp
	rte

	.globl	__stack_attach
__stack_attach:
	movl	d0,sp@-
	jsr	a2@

	.globl	_call_continuation
_call_continuation:
	movl	sp@(4),a0
	movl	_stack_pointers,sp
	movl	sp,a6
	jmp	a0@
/* plan 750 END */

//----traps----//

#define	DO_ALIGNMENT	clrw	sp@-;

#if	NIPLMEAS

#define	INTR_CALL_LIT(funclit, arg) \
	movl	arg,sp@-; \
	movl	\#funclit,sp@-; \
	jsr	_intr_call; \
	addql	\#8,sp;

#define	INTR_CALL_REG(funcreg, arg) \
	movl	arg,sp@-; \
	movl	funcreg,sp@-; \
	jsr	_intr_call; \
	addql	\#8,sp;

#define	INTR_CALL_REG0(funcreg) \
	clrl	sp@-; \
	movl	funcreg,sp@-; \
	jsr	_intr_call; \
	addql	\#8,sp;

#else NIPLMEAS

#define	INTR_CALL_LIT(funclit, arg) \
	movl	arg,sp@-; \
	jsr	funclit; \
	addql	\#4,sp;

#define	INTR_CALL_REG(funcreg, arg) \
	movl	arg,sp@-; \
	jsr	funcreg@; \
	addql	\#4,sp;

#define	INTR_CALL_REG0(funcreg) \
	jsr	funcreg@;

#endif NIPLMEAS

#if	GDB
#define	IRSO	(16*4+4)		/* interrupt register save offset */

#if	NIPLMEAS
#define	IPL_INTR() \
	clrl	d0; \
	movw	sp@(R_SR),d0; \
	movl	d0,sp@-; \
	jsr	_ipl_intr;		/* ipl_intr(old_sr) */ \
	addql	\#4,sp;
#else	NIPLMEAS
#define	IPL_INTR()
#endif	NIPLMEAS

#define	TRAP(name, type, fsize) \
	.globl	name; \
name: \
	movw	\#fsize,sp@-;		/* set r_fsize */ \
	DO_ALIGNMENT; \
	moveml	\#0xffff,sp@-; \
	movc	usp,a0; \
	movl	a0,sp@(R_SP); \
	movl	sp,a6;			/* special fp for gdb */ \
	addl	\#1,a6; \
	subw	\#12,sp;		/* dummy fcode, rw and faultaddr */ \
	movl	\#type,sp@-; \
	jra	trap;

#define	TRAPVEC(name) \
	.globl	name; \
name: \
	clrw	sp@-;			/* zero r_fsize */ \
	DO_ALIGNMENT; \
	moveml	\#0xffff,sp@-; \
	movc	usp,a0; \
	movl	a0,sp@(R_SP); \
	movl	sp,a6;			/* special fp for gdb */ \
	addl	\#1,a6; \
	movw	sp@(VOR),d0; 		/* get trap type from vor */ \
	andl	\#0xfff,d0; \
	subw	\#12,sp;		/* dummy fcode, rw and faultaddr */ \
	movl	d0,sp@-; \
	jra	trap;

/* plan 745 (D167, D024) BEGIN: NeXTMach INTRARG, INTRSCAN, INTRPOLL removed here (1997 forms follow #endif GDB) */
/* plan 745 END */
#else	GDB
#define	IRSO	(5*4)			/* interrupt register save offset */

#if	NIPLMEAS
#define	IPL_INTR() \
	clrl	d0; \
	movw	sp@(5*4),d0; \
	movl	d0,sp@-; \
	jsr	_ipl_intr;		/* ipl_intr(old_sr) */ \
	addql	\#4,sp;
#else	NIPLMEAS
#define	IPL_INTR()
#endif	NIPLMEAS

#define	TRAP(name, type, fsize) \
	.globl	name; \
name: \
	movw	\#fsize,sp@-;		/* set r_fsize */ \
	DO_ALIGNMENT; \
	moveml	\#0xffff,sp@-; \
	movc	usp,a0; \
	movl	a0,sp@(R_SP); \
	subw	\#12,sp;		/* dummy fcode, rw and faultaddr */ \
	movl	\#type,sp@-; \
	jra	trap;

#define	TRAPVEC(name) \
	.globl	name; \
name: \
	clrw	sp@-;			/* zero r_fsize */ \
	DO_ALIGNMENT; \
	moveml	\#0xffff,sp@-; \
	movc	usp,a0; \
	movl	a0,sp@(R_SP); \
	movw	sp@(VOR),d0; 		/* get trap type from vor */ \
	andl	\#0xfff,d0; \
	subw	\#12,sp;		/* dummy fcode, rw and faultaddr */ \
	movl	d0,sp@-; \
	jra	trap;

/* plan 745 (D167, D024) BEGIN: NeXTMach INTRARG, INTRSCAN, INTRPOLL removed here (1997 forms follow #endif GDB) */
/* plan 745 END */
#endif	GDB

/* plan 745 (D167, D024) BEGIN: INTRARG, INTRSCAN, INTRPOLL of the 1997 kernel (original 0x4001b8a-0x4001dfa: IPL 7 first, 16-register frame, stack switch, then the IPL of the handler) */
#define	IRSO1997	(16*4)		/* sr at 64 and pc at 66: the 1997 frame has no r_fsize word */

#define	INTRARG(name, mask, vector, arg, ra) \
	.globl	name; \
name: \
	orw	\#0x700,sr;		/* IPL 7 */ \
	moveml	\#0xffff,sp@-; \
	movc	usp,a0; \
	movl	a0,sp@(R_SP); \
	lea	sp@(R_A6),a6; \
	movl	sp,a2;			/* save sp */ \
	cmpl	\#_eintstack,sp;	/* on interrupt stack? */ \
	jls	1f; \
	lea	_eintstack,sp;		/* switch to interrupt stack */ \
1:	andw	\#mask,sr; \
	movl	\#arg,sp@-; \
	jsr	vector; \
	addql	\#4,sp; \
	jra	ra;			/* sp & regs restored in softint_rtn */

#define	INTRSCAN(name, mask, scanlist, scanarg, start, len) \
	.globl	name; \
name: \
	orw	\#0x700,sr;		/* IPL 7 */ \
	moveml	\#0xffff,sp@-; \
	movc	usp,a0; \
	movl	a0,sp@(R_SP); \
	lea	sp@(R_A6),a6; \
	movl	sp,a2;			/* save sp */ \
	cmpl	\#_eintstack,sp;	/* on interrupt stack? */ \
	jls	1f; \
	lea	_eintstack,sp;		/* switch to interrupt stack */ \
1:	andw	\#mask,sr; \
	movw	a2@(IRSO1997+0),d0;	/* push sr for timer */ \
	movl	d0,sp@-; \
	movl	a2@(IRSO1997+2),sp@-;	/* push pc */ \
2:	movl	_intrstat,a0; \
	movl	a0@,d0;			/* see who's interrupting */ \
	andl	_intr_mask,d0;		/* scan only if enabled */ \
	bfffo	d0{\#start:\#len},d1;	/* scan all bits each time */ \
	jne	1f; \
	addql	\#8,sp;			/* pop off sr and pc */ \
	jmp	intr_rtn;		/* sp & regs restored in intr_rtn */ \
1:	subl	\#start,d1;		/* reset origin */ \
	lea	scanarg,a0; \
	movl	a0@(0,d1:w:4),a1;	/* arg to interrupt routine */ \
	lea	scanlist,a0; \
	movl	a0@(0,d1:w:4),a0; \
	INTR_CALL_REG(a0,a1); \
	bra	2b;			/* keep looking until no more */

#define	INTRPOLL(name, mask, vector) \
	.globl	name; \
name: \
	orw	\#0x700,sr;		/* IPL 7 */ \
	moveml	\#0xffff,sp@-; \
	movc	usp,a0; \
	movl	a0,sp@(R_SP); \
	lea	sp@(R_A6),a6; \
	movl	sp,a2;			/* save sp */ \
	cmpl	\#_eintstack,sp;	/* on interrupt stack? */ \
	jls	1f; \
	lea	_eintstack,sp;		/* switch to interrupt stack */ \
1:	andw	\#mask,sr; \
	movl	\#vector,a4;		/* list of routines to poll */ \
2:	movl	a4@+,a1; \
	INTR_CALL_REG0(a1); \
	tstl	d0;			/* interrupt serviced? */ \
	beqs	2b;			/* no, keep looking */ \
	jra	intr_rtn;		/* sp & regs restored in intr_rtn */
/* plan 745 END */

/* plan 750 (D167, D024) BEGIN: the NeXTMach TRAPVEC/TRAP handlers stray badtrap illegal zerodiv check trapv privilege emu1010 emu1111 coproc format badintr spurious breakpt fpp mmu_config mmu_ill mmu_access are not in the 1997 unit */
/* plan 750 END */
/* plan 744 (D167, D024) BEGIN: TRAP(trace) removed; trace is a jump to std_trap near fpsp_frame_err */
/* plan 744 END */

/* plan 745 (D167, D024) BEGIN: std_trap (original 0x4001b3e, 76 B; NeXTMach has no std_trap) */
	.globl	std_trap
std_trap:
	moveml	#0xffff,sp@-
	movc	usp,a0
	movl	a0,sp@(R_SP)
	lea	sp@(R_A6),a6
	movw	sp@(VOR),d0		// get trap type from vor
	andl	#0xfff,d0
	movl	sp,a2
	cmpl	#_eintstack,sp
	jls	1f
	movl	_stack_pointers,a5
	cmpl	sp,a5
	jcs	2f
	subl	#4084,a5		// 4084 is the value in the bytes
	cmpl	sp,a5
	jcs	1f
2:	movl	_stack_pointers,sp
1:	movl	a2,sp@-
	subw	#12,sp			// dummy fcode, rw and faultaddr
	movl	d0,sp@-
	jra	trap
/* plan 745 END */

/* plan 745 (D167, D024) BEGIN: ipl1-ipl7 with the original sr masks */
	INTRARG(ipl1, 0xf1ff, _softint_run, IMM0, softint_rtn)
	INTRARG(ipl2, 0xf2ff, _softint_run, IMM1, softint_rtn)
	INTRSCAN(ipl3, 0xf3ff, _ipl3_scan, _ipl3_arg, I_IPL3_BASE, I_IPL3_BITS)
	INTRSCAN(ipl4, 0xf4ff, _ipl4_scan, _ipl4_arg, I_IPL4_BASE, I_IPL4_BITS)
	INTRPOLL(ipl5, 0xf5ff, _poll_intr)
	INTRSCAN(ipl6, 0xf6ff, _ipl6_scan, _ipl6_arg, I_IPL6_BASE, I_IPL6_BITS)
	INTRSCAN(ipl7, 0xf7ff, _ipl7_scan, _ipl7_arg, I_IPL7_BASE, I_IPL7_BITS)
/* plan 745 END */

/* plan 744 (D167, D024) BEGIN: _call_nmi (original 0x4001dfa: frame without r_fsize, sr at 64 and pc at 66) */
	.globl	_call_nmi
_call_nmi:
	subl	d0,d0
	movw	a2@(IRSO1997+0),d0		// push sr
	movl	d0,sp@-
	movl	a2@(IRSO1997+2),sp@-	// push pc
/* plan 744 END */
	movl	sp,sp@-			// push isp
	movc	usp,a0
	movl	a0,sp@-			// push usp
	movl	a2,sp@-			// push ksp
	jsr	_nmi
	addl	#20,sp
	rts

//
//	trap3 is used for fast Mach system calls.
//
//	Calling conventions are as follows:
//
//	d0	contains the system call number.
//	d1-d7	contains arguments.
//
//	On exit
//
//	d0	contains return value (a kern_return_t)
//
//	All registers are saved and restored (a big hit) to make
//	thread_get_state and thread_set_state work properly.  These
//	could perhaps still work without saving/restoring registers
//	if we committed to forcing the thread to take an AST and
//	get its registers saved that way.
//
	.globl	trap3
trap3:
/* plan 746 (D167, D024) BEGIN: trap3 (original 0x4001e1e, 170 B: no r_fsize word, kernel stack from _stack_pointers, 16-byte table entries, AST test by btst, return through a2) */
//
//	Save necessary state
//
	addql	#1,_cnt+V_SYSCALL
	moveml	#0xffff,sp@-		// save regs
	movc	usp,a0			// grab usp
	movl	a0,sp@(R_SP)		// and save it
	lea	sp@(R_A6),a6
	movl	sp,a2			// save sp
	movl	_stack_pointers,sp	// kernel stack
//
//	Read in args and call handler.  The entries of the syscall table are 16 bytes (lslw #4).
//
	tstl	d0			// syscall < 0?
	blt	3f			// yes, bad
	cmpl	_mach_trap_count,d0	// mach_trap_count < syscall number?
	bge	3f			// yes, bad
	lea	_mach_trap_table,a0	// get start of table
	lslw	#4,d0
	lea	a0@(d0:w),a0		// point at entry
	movl	a0@,d0			// grab arg count
	lea	argc_table,a1		// table pointer
	movl	a1@(d0:w:4),a1		// entry in table
	jmp	a1@			// jump indirect
3:	movl	#KERN_INVALID_ARGUMENT,d0
	jmp	5f
	.data
argc_table:
	.long	argc_0
	.long	argc_1
	.long	argc_2
	.long	argc_3
	.long	argc_4
	.long	argc_5
	.long	argc_6
	.long	argc_7
	.text
//	Following could perhaps be better done with moveml's
argc_7:	movl	d7,sp@-			// push arg and fall through
argc_6:	movl	d6,sp@-			// push arg and fall through
argc_5:	movl	d5,sp@-			// push arg and fall through
argc_4:	movl	d4,sp@-			// push arg and fall through
argc_3:	movl	d3,sp@-			// push arg and fall through
argc_2:	movl	d2,sp@-			// push arg and fall through
argc_1:	movl	d1,sp@-			// push arg and fall through
argc_0:
	movl	a0@(4),a0		// grab function pointer
	jsr	a0@			// go for it
5:	movl	d0,a2@(R_D0)		// save return code for later
	movl	_active_threads,a1
	movl	a1@(THREAD_PCB),a0
	btst	#AST_SCHED_BIT,a0@(AST)
	bne	7f			// AST requested, call check_for_ast
	movl	a1@(THREAD_TASK),a1
	movl	a1@(TASK_U_ADDRESS),a1
	movl	a1@(U_PROCP),a1		// proc table slot
	tstb	a1@(P_CURSIG)		// check cursig
	bne	7f			// there's a sig, call check_for_ast
	tstl	a1@(P_SIG)		// test sig bits
	beq	8f			// zero -> no sig
7:	movl	a2,sp@-
	jsr	_check_for_ast
8:	movl	a2,sp			// restore sp
	movl	sp@(R_SP),a0		// restore usp
	movc	a0,usp
	moveml	sp@,#0x7fff		// restore registers (exc. kernel sp)
	addw	#R_SR,sp		// pop register frame
	rte				// return to user
/* plan 746 END */

//
//	trap4 is used for fast Unix system calls.
//
//	Calling conventions are as follows:
//
//	d0	contains the system call number.
//	d1-d7	contains arguments.
//
//	On exit
//
//	d0	contains u.u_rval1 or if condition code has
//		carry set contains u.u_error.
//	d1	contains u.u_rval2
//
//
	.globl	trap4
trap4:
/* plan 746 (D167, D024) BEGIN: trap4 (original 0x4001ec8, 58 B: same entry and return as trap3, no AST or signal test) */
//
//	Save necessary state
//
	addql	#1,_cnt+V_SYSCALL
	moveml	#0xffff,sp@-		// save regs
	movc	usp,a0			// grab usp
	movl	a0,sp@(R_SP)		// and save it
	lea	sp@(R_A6),a6
	movl	sp,a2			// save sp
	movl	_stack_pointers,sp	// kernel stack
	movl	a2,sp@-
	jsr	_unix_syscall		// call handler
	movl	a2,sp			// restore sp
	movl	sp@(R_SP),a0		// restore usp
	movc	a0,usp
	moveml	sp@,#0x7fff		// restore registers (exc. kernel sp)
	addw	#R_SR,sp		// pop register frame
	rte				// return to user
/* plan 746 END */

//
//	traps 5 and 6 are used to retrieve/store a per thread register.
//	While it would nice to have real language support for this, I
//	am in a weak mood and will implement it this way.
//
	.globl	trap5
trap5:					// get users register
/* plan 744 (D167, D024) BEGIN: trap5 and trap6 read _active_threads directly (original 0x4001f02, 0x4001f12) */
	movl	_active_threads,a0	// current thread
/* plan 744 END */
	movl	a0@(THREAD_PCB),a0	// current pcb
	movl	a0@(THREAD_USER_REG),d0	// user's register
	rte				// done

	.globl	trap6
trap6:					// set users register
/* plan 754 (D167, D024) BEGIN: trap6 (original 0x4001f12): reads _active_threads directly and stores d0 (the NeXTMach movl d0,d1 and the d1 store are not in the 1997 unit) */
	movl	_active_threads,a0	// current thread
	movl	a0@(THREAD_PCB),a0	// current pcb
	movl	d0,a0@(THREAD_USER_REG)	// user's register
/* plan 754 END */
	rte				// done

/* plan 752 (D167, D024) BEGIN: the NeXTMach old UNIX syscall handler trap0 with syscall_recover, syscall_rtn and syscall_fault (144 B) is not in the 1997 unit */
/* plan 752 END */

/* exception handlers */
	.globl	addrerr
addrerr:
/* plan 747 (D167, D024) BEGIN: addrerr (original 0x4001f22, 116 B: no r_fsize word, no frame-size stores, the stack check of std_trap at label 3) */
	moveml	#0xffff,sp@-		// save regs
	movc	usp,a0			// save usp
	movl	a0,sp@(R_SP)
	lea	sp@(R_A6),a6
	bfextu	sp@(FMT){#0:#4},d0	// extract format bits
	cmpl	#EF_NORMAL6,d0		// 040 only
	bne	1f
	bra	3f
1:
	cmpl	#EF_SHORTBUS,d0		// 030 only
	bne	2f
	bra	3f
2:
	cmpl	#EF_LONGBUS,d0		// 030 only
	bne	4f
3:
	movl	sp,a2
	cmpl	#_eintstack,sp
	jls	5f
	movl	_stack_pointers,a5
	cmpl	sp,a5
	jcs	6f
	subl	#4084,a5
	cmpl	sp,a5
	jcs	5f
6:	movl	_stack_pointers,sp
5:	movl	a2,sp@-
	subw	#12,sp			// dummy fcode, rw and faultaddr
	movl	#T_ADDRERR,sp@-
	jra	trap
4:
	pea	1f
	jsr	_panic
	.data
1:	.asciz	"addrerr: bad exception stack format"
	.even
	.text
/* plan 747 END */

	.globl	buserr
buserr:
/* plan 748 (D167, D024) BEGIN: buserr entry (original 0x4001f96: no r_fsize word, a6 from lea) */
	moveml	#0xffff,sp@-		// save regs
	movc	usp,a0			// save usp
	movl	a0,sp@(R_SP)
	lea	sp@(R_A6),a6
	bfextu	sp@(FMT){#0:#4},d0	// extract format bits
	cmpl	#EF_ACCESS,d0		// 040 only
/* plan 748 END */
	jeq	access
	cmpl	#EF_SHORTBUS,d0		// 030 only
	jeq	short_bus
	cmpl	#EF_LONGBUS,d0		// 030 only
	jeq	long_bus
	pea	1f
	jsr	_panic
	.data
1:	.asciz	"buserr: bad exception stack format"
	.even
	.text

badfault:
	pea	1f
	jsr	_panic
	.data
1:	.asciz	"buserr: no fault indicated"
	.even
	.text

/* plan 748 (D167, D024) BEGIN: access: no frame-size store */
access:
/* plan 748 END */
	movl	#T_BUSERR,d2		// assume bus error
	movl	sp@(FAULTADDR_040),a0	// fault address
	movl	#VM_PROT_READ+VM_PROT_WRITE,d0	// read/write
	btst	#RW_BIT,sp@(SSW_040)
	beq	1f
	btst	#LK_BIT,sp@(SSW_040)
	bne	1f
	movl	#VM_PROT_READ,d0
1:	movw	sp@(SSW_040),d1		// function code (transfer mode)
	andl	#SS_TM,d1
	btst	#ATC_BIT,sp@(SSW_040)	// MMU fault?
	beq	2f			// no
	movl	#T_MMU_INVALID,d2	// indicate MMU error
	btst	#MA_BIT,sp@(SSW_040)	// misaligned fault addr is +4
	beq	2f
/* plan 748 (D167, D024) BEGIN: access: stack check and the frame pointer a2 pushed first (original 0x4002024) */
	addql	#4,a0
2:
	movl	sp,a2
	cmpl	#_eintstack,sp
	jls	5f
	movl	_stack_pointers,a5
	cmpl	sp,a5
	jcs	6f
	subl	#4084,a5
	cmpl	sp,a5
	jcs	5f
6:	movl	_stack_pointers,sp
5:	movl	a2,sp@-
	movl	a0,sp@-			// push fault address
	movl	d0,sp@-			// push rw
	movl	d1,sp@-			// push fcode
	movl	d2,sp@-			// push trap type
/* plan 748 END */
	jra	trap
	
/* plan 748 (D167, D024) BEGIN: short_bus: no frame-size store */
short_bus:
/* plan 748 END */
	btst	#FAULTD_BIT-8,sp@(SSW)	// data fault?
	bne	data_fault
	btst	#FAULTB_BIT-8,sp@(SSW)	// stage B fault?
	beq	1f
	movl	sp@(R_PC),a0		// yes, fault address is r_pc + 4
	addqw	#4,a0
	bra	inst_fault
1:	btst	#FAULTC_BIT-8,sp@(SSW)	// stage C fault?
	beq	badfault
	movl	sp@(R_PC),a0		// yes, fault address is r_pc + 2
	addqw	#2,a0
	bra	inst_fault

/* plan 748 (D167, D024) BEGIN: long_bus: no frame-size store */
long_bus:
/* plan 748 END */
	btst	#FAULTD_BIT-8,sp@(SSW)	// data fault?
	bne	data_fault
	btst	#FAULTB_BIT-8,sp@(SSW)	// stage B fault?
	beq	1f
	movl	sp@(STAGEB),a0		// yes, fault address is e_stageb
	bra	inst_fault
1:	btst	#FAULTC_BIT-8,sp@(SSW)	// stage C fault?
	beq	badfault
	movl	sp@(STAGEB),a0		// yes, fault address is e_stageb - 2
	subqw	#2,a0
	// fall into ...

inst_fault:
	movl	#1,d2			// indicate read
	movl	#FC_USERI,d1
	btst	#SR_SUPER_BIT-8,sp@(R_SR) // super mode?
	beq	call_trap
	movl	#FC_SUPERI,d1
	bra	call_trap

data_fault:
	movl	sp@(FAULTADDR),a0	// fault address is r_faultaddr
	movw	sp@(SSW),d1		// extract fcode
	andl	#SS_FCODE,d1
	bfextu	sp@(SSW+1){#0:#2},d2	// extract rmw & rw
	// fall into ...

call_trap:
	btst	#1,d2			// read/modify/write cycle?
	bne 	1f
	btst	#0,d2			// read cycle?
	beq 	1f
	movl	#VM_PROT_READ,d0
//	ptest	d1,a0@,7,READ		// see if MMU caused buserr
	.long	0xf0109e09
	bra	2f
1:	movl	#VM_PROT_READ+VM_PROT_WRITE,d0
//	ptest	d1,a0@,7,WRITE		// see if MMU caused buserr
	.long	0xf0109c09
/* plan 748 (D167, D024) BEGIN: call_trap: stack check and the frame pointer a2 pushed first (original 0x4002106) */
2:
	movl	sp,a2
	cmpl	#_eintstack,sp
	jls	5f
	movl	_stack_pointers,a5
	cmpl	sp,a5
	jcs	6f
	subl	#4084,a5
	cmpl	sp,a5
	jcs	5f
6:	movl	_stack_pointers,sp
5:	movl	a2,sp@-
	movl	a0,sp@-			// push fault address
	movl	d0,sp@-			// push rw
	movl	d1,sp@-			// push fcode
//	pmove	sr,mmu_status
/* plan 748 END */
	.long	0xf0396200
	.long	mmu_status
	bfffo	mmu_status{#0:#6},d0
	beq	not_mmu			// MMU did not cause buserr
	lea	mmu_type,a0
	movl	a0@(0,d0:w:4),sp@-	// push MMU trap type
	bra	trap
not_mmu:
	movl	#T_BUSERR,sp@-		// push trap type
	bra	trap

mmu_type:
	.long	T_MMU_BUSERR
	.long	T_MMU_LIMIT
	.long	T_MMU_SUPER
	.long	T_STRAY
	.long	T_MMU_WRITE
	.long	T_MMU_INVALID

	.data
mmu_status:
	.word	0
	.text

trap:
	addql	#1,_cnt+V_TRAP
	jsr	_trap
/* plan 748 (D167, D024) BEGIN: trap onward (original 0x400217c: no pop after _trap, return through a2 and d0, AST test in softint_rtn) */
	// fall into ...
trap_rtn:
	btst	#SR_SUPER_BIT-8,a2@(R_SR)
	bne	2f
	movl	a2@(R_SP),a0
	movc	a0,usp
2:	tstl	d0
	bne	5f
	movl	a2,sp
	moveml	sp@,#0x7fff
	addw	#R_SR,sp
	rte
5:	movl	a2,a0
	addl	d0,a0
	movl	a2@(R_PC),a0@(R_PC)
	movw	a2@(R_SR),a0@(R_SR)
	clrw	a0@(VOR)
	movl	a0,a2@(R_SP)
	movl	a2,sp
	moveml	sp@,#0xffff
	addw	#R_SR,sp
	rte

intr_rtn:
	addql	#1,_cnt+V_INTR
softint_rtn:
	btst	#SR_SUPER_BIT-8,a2@(IRSO1997)
	bne	2f
	movl	_active_threads,a0
	tstl	a0
	beq	2f
	movl	a0@(THREAD_PCB),a0
	btst	#AST_SCHED_BIT,a0@(AST)
	beq	2f
	movl	_stack_pointers,sp
	movl	a2,d0
	movl	d0,sp@-
	jsr	_check_for_ast
	lea	_eintstack,sp
	movl	a2@(R_SP),a0
	movc	a0,usp
2:	orw	#0x700,sr
	movl	a2,sp
	moveml	sp@,#0x7fff
	addw	#R_SR,sp
	rte
/* plan 748 END */

#if NIPLMEAS
	.globl	_splu_measured
_splu_measured:					// old_ipl=splu_measured(new_sr)
	jsr	_ipl_splu			// old_ipl = ipl_splu(pc,new_sr)
	movl	sp@(4),d1			// get new sr
	movw	d1,sr				// sr = new_sr
	rts

	.globl	_spld_measured
_spld_measured:					// old_ipl=spld_measured(new_sr)
	jsr	_ipl_spld			// old_ipl = ipl_spld(pc,new_sr)
	movl	sp@(4),d1			// get new sr
	movw	d1,sr				// sr = new_sr
	rts

#ifdef notdef
	.globl	_Rspl7
_Rspl7:
	clrl	d0
	movw	sr,d0
	movw	#0x2700,sr
	rts

	.globl	_Rsplx
_Rsplx:
	clrl	d0
	movw	sr,d0
	movl	sp@(4),d1
	movw	d1,sr
	rts
#endif notdef
#endif NIPLMEAS

/* plan 744 (D167, D024) BEGIN: fpsp_done, fpsp_frame_err, trace (original 0x400221e, 0x4002220, 0x4002232) */
	.globl	fpsp_done
fpsp_done:
	rte

	.globl	fpsp_frame_err
fpsp_frame_err:
	pea	1f
	jsr	_panic
	jra	fpsp_frame_err
	.data
1:	.asciz	"fpsp: frame format error"
	.even
	.text

	.globl	trace
trace:
	jmp	std_trap
/* plan 744 END */

/* plan 751 (D167, D024) BEGIN: _cache_push with the trap2 stub, and _mon_exit (original 0x4002238-0x4002284); NeXTMach trap2 is not in the 1997 unit */
PROCENTRY (cache_push)
	cmpb	#MC68030,_cpu_type
	beq	1f
#if	D25B || D43B
	nop
#endif	D25B || D43B
//	cpusha	bc
	.word	0xf4f8
	bra	2f
1:
	movl	_cache,d0
	movc	d0,cacr			// clear cache and enable it
2:
	PROCEXIT
trap2:
	jsr	_cache_push
	rte

	.globl	_mon_exit
_mon_exit:
	movw	sp@,d0
	andw	#0x2000,d0
	bne	1f
	jsr	_suser
	tstl	d0
	bne	1f
	rte
1:	movl	_boot_action,d0
	movl	_reboot_vector,a0
	jmp	a0@
/* plan 751 END */

/* plan 744 (D167, D024) BEGIN: _scb of the 1997 kernel: 72 vectors, std_trap for the unlisted (NeXTMach scb.s has 256 entries; original 0x40ada14) */
	.data
	.globl	_scb
_scb:
/* 0x000 */	.long	std_trap; .long	std_trap; .long	buserr; .long	addrerr
/* 0x010 */	.long	std_trap; .long	std_trap; .long	std_trap; .long	std_trap
/* 0x020 */	.long	std_trap; .long	std_trap; .long	std_trap; .long	fline
/* 0x030 */	.long	std_trap; .long	std_trap; .long	std_trap; .long	std_trap
/* 0x040 */	.long	std_trap; .long	std_trap; .long	std_trap; .long	std_trap
/* 0x050 */	.long	std_trap; .long	std_trap; .long	std_trap; .long	std_trap
/* 0x060 */	.long	std_trap; .long	ipl1; .long	ipl2; .long	ipl3
/* 0x070 */	.long	ipl4; .long	ipl5; .long	ipl6; .long	ipl7
/* 0x080 */	.long	std_trap; .long	std_trap; .long	trap2; .long	trap3
/* 0x090 */	.long	trap4; .long	trap5; .long	trap6; .long	std_trap
/* 0x0a0 */	.long	std_trap; .long	std_trap; .long	std_trap; .long	std_trap
/* 0x0b0 */	.long	std_trap; .long	std_trap; .long	std_trap; .long	std_trap
/* 0x0c0 */	.long	bsun; .long	inex; .long	dz; .long	unfl
/* 0x0d0 */	.long	operr; .long	ovfl; .long	snan; .long	unsupp
/* 0x0e0 */	.long	std_trap; .long	std_trap; .long	std_trap; .long	std_trap
/* 0x0f0 */	.long	std_trap; .long	std_trap; .long	std_trap; .long	std_trap
/* 0x100 */	.long	std_trap; .long	std_trap; .long	std_trap; .long	std_trap
/* 0x110 */	.long	std_trap; .long	std_trap; .long	std_trap; .long	std_trap
/* plan 744 END */
