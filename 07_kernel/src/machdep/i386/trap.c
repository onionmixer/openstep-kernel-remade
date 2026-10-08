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

/*
 * Copyright (c) 1992 NeXT Computer, Inc.
 *
 * Intel386 Family:	Trap handlers.
 *
 * HISTORY
 *
 * 13 April 1992 ? at NeXT
 *	Created.
 */
 
#import <gdb.h>

#import <mach/mach_types.h>
#import <mach/exception.h>

#import <kern/syscall_sw.h>
#import <kern/kdp.h>

#import <vm/vm_kern.h>

#import <machdep/i386/trap.h>
#import <machdep/i386/machdep_call.h>
#import <machdep/i386/cpu_inline.h>
#import <machdep/i386/fp_exported.h>
#import <machdep/i386/sel_inline.h>
#import <machdep/i386/err_inline.h>

#import <sys/kernel.h>
#import <sys/systm.h>
#import <sys/proc.h>
#import <sys/user.h>
#import <sys/syslog.h>
#import <sys/param.h>		/* plan 273: CHECK_SIGNALS */
#import <kern/ast.h>		/* plan 273 */
#import <kern/sched.h>		/* plan 273: csw_needed */

#define N_BACKTRACE		4	// number of backtrace frames to print

static
void
kernel_debug_trap(
	thread_saved_state_t	*saved_state
);
static
kern_return_t
kernel_pagefault(
	vm_offset_t		address,
	except_frame_t		*frame
);
static
boolean_t
kernel_try_recover(
	except_frame_t		*frame
);
static
void
kernel_recover_thread(
	thread_saved_state_t	*saved_state
);

void
_i386_backtrace(
	void			*frame,
	int			nframes
);

void	unix_syscall_return(int error);	/* plan 273 */

void
user_trap(
    thread_saved_state_t	*state
)
{
    except_frame_t		*frame = &state->frame;
    int				trapno;
    thread_t			thread;
    int				_exception, code = 0, subcode = 0;
    vm_offset_t			va;
    kern_return_t		result;
    int				uerror;
    struct proc			*p;
    struct timeval		syst;
    
    thread = current_thread();
    trapno = state->trapno;
    
    if (p = u.u_procp)		/* plan 273: 4.3BSD u area, as in NeXTMach next/trap.c */
	syst = u.u_ru.ru_stime;
    
    switch (trapno) {

    case T_ZERO_DIVIDE:
	_exception	= EXC_ARITHMETIC;
	code		= EXC_I386_ZERO_DIVIDE;
	break;
	
    case T_DEBUG:
	_exception	= EXC_BREAKPOINT;
	code		= EXC_I386_DEBUG;
	break;
	
    case T_BREAKPOINT:
	_exception	= EXC_BREAKPOINT;
	code		= EXC_I386_BREAKPOINT;
	break;
	
    case T_OVERFLOW:
    	_exception	= EXC_SOFTWARE;
	code		= EXC_I386_OVERFLOW;
	break;
	
    case T_BOUNDS_CHECK:
	_exception	= EXC_SOFTWARE;
	code		= EXC_I386_BOUNDS_CHECK;
	break;
	
    case T_INVALID_OPCODE:
	_exception	= EXC_BAD_INSTRUCTION;
	code		= EXC_I386_INVALID_OPCODE;
	break;
	
    case T_NOEXTENSION:
    	fp_noextension(state);
	goto out;
	
    case T_SEGMENT_NOTPRESENT:
    	_exception	= EXC_BAD_INSTRUCTION;
	code		= EXC_I386_SEGMENT_NOTPRESENT;
	subcode		= err_to_error_code(frame->err);
	break;
	
    case T_STACK_EXCEPTION:
	_exception	= EXC_BAD_INSTRUCTION;
	code		= EXC_I386_STACK_EXCEPTION;
	subcode		= err_to_error_code(frame->err);
	break;
	
    case T_GENERAL_PROTECTION:
	_exception	= EXC_BAD_INSTRUCTION;
	code		= EXC_I386_GENERAL_PROTECTION;
	subcode		= err_to_error_code(frame->err);
	break;
	
    case T_PAGE_FAULT:
    	va = cr2();
	uerror = u.u_error;	/* plan 273: as NeXTMach next/trap.c:410 */
	u.u_error = 0;
	result = vm_fault(thread->task->map, trunc_page(va),
			    frame->err.pgfault.wrtflt?
				VM_PROT_READ | VM_PROT_WRITE:
				VM_PROT_READ,
			    FALSE, 0);
	u.u_error = uerror;	/* plan 273 */
	if (result == KERN_SUCCESS)
	    goto out;

	_exception	= EXC_BAD_ACCESS;
	code		= result;
	subcode		= va;
	break;
    
    case T_EXTENSION_FAULT:
    	fp_extension_fault(state);
	goto out;
	
    case T_ALIGNMENT_CHECK:
	_exception	= EXC_SOFTWARE;
	code		= EXC_I386_ALIGNMENT_CHECK;
	break;
	
    default:
    	_exception	= EXC_BAD_INSTRUCTION;
	code		= trapno;
	break;
    }

    exception(_exception, code, subcode);
    /* NOTREACHED */
			    
out:
    if (p && u.u_prof.pr_scale) {	/* plan 273: u_prof, as NeXTMach next/trap.c:550 */
	int		ticks;
	struct timeval	*tv = &u.u_ru.ru_stime;
			
	ticks = ((tv->tv_sec - syst.tv_sec) * 1000 +
		    (tv->tv_usec - syst.tv_usec) / 1000) / (tick / 1000);
	if (ticks)
	    addupc(frame->eip, &u.u_prof, ticks);
    }

    thread_exception_return();
    /* NOTREACHED */
}

void
kernel_trap(
    thread_saved_state_t	*state
)
{
    except_frame_t		*frame = &state->frame;
    int				trapno;
    vm_offset_t			va;
    int				_exception, code = 0, subcode = 0;
    kern_return_t		result;
    int				uerror;
    
    trapno = state->trapno;
    
    switch (trapno) {

    case T_NOEXTENSION:
	/* ignore exception */;
	return;
	
    case T_EXTENSION_FAULT:
	fp_kernel_extension_fault(state);
	return;
	
    case T_DEBUG:
    case T_BREAKPOINT:
	kernel_debug_trap(state);
	return;
	
    case T_PAGE_FAULT:
	va = cr2();

	if (current_thread()) {	/* plan 273: save u.u_error, as NeXTMach next/trap.c:262 */
	    uerror = u.u_error;
	    u.u_error = 0;
	}
	
	if (va >= KERNEL_LINEAR_BASE)
	    result = kernel_pagefault(va, frame);
	else
	    result = vm_fault(current_task()->map, trunc_page(va),
				frame->err.pgfault.wrtflt?
				    VM_PROT_READ | VM_PROT_WRITE:
				    VM_PROT_READ,
				FALSE, 0);

	if (current_thread())	/* plan 273 */
	    u.u_error = uerror;

	if (result == KERN_SUCCESS)
	    return;
    
	if (kernel_try_recover(frame))
	    return;
	    
	if (va < KERNEL_LINEAR_BASE) {
	    /*
	     * This can happen on return to user mode
	     * when a private thread LDT contains
	     * unallocated virtual memory.  Send an
	     * exception RPC, after carefully piecing
	     * the thread state back together.
	     */
	    kernel_recover_thread(state);

	    _exception		= EXC_BAD_ACCESS;
	    code		= result;
	    subcode		= va;
	    exception_from_kernel(_exception, code, subcode);
	    thread_exception_return();
	    /* NOTREACHED */
	}
	break;
	
    case T_GENERAL_PROTECTION:
    case T_SEGMENT_NOTPRESENT:
    case T_STACK_EXCEPTION:
	if (frame->err.normal.tbl == ERR_LDT) {
	    /*
	     * This can happen on return to user mode
	     * when one of the segment registers refers
	     * to a descriptor that is invalid for some
	     * reason or another.  Send an exception RPC,
	     * after carefully piecing the thread state
	     * back together.
	     */
	    kernel_recover_thread(state);

	    _exception	= EXC_BAD_INSTRUCTION;
	    code	= trapno;
	    subcode	= err_to_error_code(frame->err);
	    exception_from_kernel(_exception, code, subcode);
	    thread_exception_return();
	    /* NOTREACHED */
	}
    	break;
	
    case T_INVALID_TSS:
    	if ((frame->eflags & EFL_NT) != 0) {
	    /*
	     * This can happen on return to user mode
	     * when a thread managed to set the NT flag
	     * and then entered the kernel through a call
	     * gate.  The fix is to redo the IRET, since
	     * the NT flag cannot be set at this point (we
	     * just came through a trap gate to get here).
	     */
	     kernel_recover_thread(state);
	     thread_exception_return();
	     /* NOTREACHED */
	}
	break;
    }
    
    if (kernel_try_recover(frame))
    	return;   

    /* plan 273: debugger path unconditional (the original kernel has GDB 0, as if_venip shows, yet keeps this path) */
    DoAlert("Kernel Trap", "");	/* plan 273: DoAlert in the original */
    printf("unexpected kernel trap %x eip %x\n", trapno, frame->eip);
    switch (trapno) {
    
    case T_ZERO_DIVIDE:
	_exception = EXC_ARITHMETIC;
	code = EXC_I386_ZERO_DIVIDE;
	break;
    
    case T_OVERFLOW:
	_exception = EXC_SOFTWARE;
	code = EXC_I386_OVERFLOW;
	break;
    
    case T_BOUNDS_CHECK:
	_exception = EXC_ARITHMETIC;
	code = EXC_I386_BOUNDS_CHECK;
	break;
    
    case T_INVALID_OPCODE:
	_exception = EXC_BAD_INSTRUCTION;
	code = EXC_I386_INVALID_OPCODE;
	break;
    
    case T_SEGMENT_NOTPRESENT:
	_exception = EXC_BAD_INSTRUCTION;
	code = EXC_I386_SEGMENT_NOTPRESENT;
	subcode	= err_to_error_code(frame->err);
	break;
    
    case T_STACK_EXCEPTION:
	_exception = EXC_BAD_INSTRUCTION;
	code = EXC_I386_STACK_EXCEPTION;
	subcode	= err_to_error_code(frame->err);
	break;
    
    case T_GENERAL_PROTECTION:
	_exception = EXC_BAD_INSTRUCTION;
	code = EXC_I386_GENERAL_PROTECTION;
	subcode	= err_to_error_code(frame->err);
	break;
	
    case T_PAGE_FAULT:
    	_exception = EXC_BAD_ACCESS;
	code = result;
	subcode = va;
	break;
    
    case T_ALIGNMENT_CHECK:
	_exception = EXC_SOFTWARE;
	code = EXC_I386_ALIGNMENT_CHECK;
	break;
	
    default:
    	_exception = EXC_BAD_INSTRUCTION;
	code = trapno;
	break;
    }

    _i386_backtrace(state->regs.ebp, N_BACKTRACE);

    kdp_raise_exception(_exception, code, subcode, state);
    DoRestore();
    panic("continued after kernel trap");
}

static
kern_return_t
kernel_pagefault(
    vm_offset_t			va,
    except_frame_t		*frame
)
{
    thread_t			thread = current_thread();
    vm_map_t			map;
    kern_return_t		result;

    if (thread == THREAD_NULL)
	map = kernel_map;
    else {
	map = thread->task->map;
	if (vm_map_pmap(map) != kernel_pmap)
	    map = kernel_map;
    }

    result = vm_fault(map, trunc_page(va - KERNEL_LINEAR_BASE),
			frame->err.pgfault.wrtflt?
			    VM_PROT_READ | VM_PROT_WRITE:
			    VM_PROT_READ,
			FALSE, 0);

    return (result);
}

static
void
kernel_debug_trap(
    thread_saved_state_t	*state
)
{
    except_frame_t		*frame = &state->frame;
    int				code;
    dr6_t			debug = (dr6_t) { 0 };
    extern void			unix_syscall_(void),
    				mach_kernel_trap_(void),
				machdep_call_(void);
    
    // Clear debug status
    set_dr6(debug);
    
    if (state->trapno == T_DEBUG) {
	if (	frame->eip == (unsigned int)unix_syscall_	||
		frame->eip == (unsigned int)mach_kernel_trap_ 	||
		frame->eip == (unsigned int)machdep_call_	) {
	    current_thread()->pcb->trace = TRUE;
	    frame->eflags &= ~EFL_TF;
	    return;
	}
	code = EXC_I386_DEBUG;
    }
    else
    	code = EXC_I386_BREAKPOINT;

    kdp_raise_exception(EXC_BREAKPOINT, code, 0, state);	/* plan 273: unconditional */
}

static
boolean_t
kernel_try_recover(
    except_frame_t	*frame
)
{
    vm_offset_t		recover = current_thread()->recover;
				
    if (recover != 0) {
        frame->eip = recover;
	frame->cs = KCS_SEL;
	frame->eflags &= ~EFL_DF;
    }
    else
	return (FALSE);
	
    current_thread()->recover = 0;
    
    return (TRUE);
}

static
void
kernel_recover_thread(
    thread_saved_state_t	*state
)
{
    thread_saved_state_t	*user_regs = USER_REGS(current_thread());
    vm_offset_t			stack_ptr = (vm_offset_t)&state->frame.esp;

    user_regs->frame.err = state->frame.err;
    
    if (stack_ptr > (vm_offset_t)&user_regs->regs.ds) {

    	user_regs->regs.eax = state->regs.eax;
    	user_regs->regs.ecx = state->regs.ecx;
    	user_regs->regs.edx = state->regs.edx;
    	user_regs->regs.ebx = state->regs.ebx;
    	user_regs->regs.ebp = state->regs.ebp;
    	user_regs->regs.esi = state->regs.esi;
    	user_regs->regs.edi = state->regs.edi;
	
	user_regs->regs.ds = state->regs.ds;
	user_regs->regs.es = state->regs.es;
    	user_regs->regs.fs = state->regs.fs;
    	user_regs->regs.gs = state->regs.gs;
    }
    else if (stack_ptr > (vm_offset_t)&user_regs->regs.es) {
	user_regs->regs.es = state->regs.es;
    	user_regs->regs.fs = state->regs.fs;
    	user_regs->regs.gs = state->regs.gs;
    }
    else if (stack_ptr > (vm_offset_t)&user_regs->regs.fs) {
    	user_regs->regs.fs = state->regs.fs;
    	user_regs->regs.gs = state->regs.gs;
    }
    else if (stack_ptr > (vm_offset_t)&user_regs->regs.gs)
    	user_regs->regs.gs = state->regs.gs;
}

static inline
void
check_for_trace(
    thread_saved_state_t	*state
)
{
    thread_t			thread = current_thread();
    
    if (thread->pcb->trace) {
	thread->pcb->trace = FALSE;
	state->frame.eflags |= EFL_TF;
    }
}

void
machdep_call(
    thread_saved_state_t	*state
)
{
    except_frame_t		*frame = &state->frame;
    regs_t			*regs = &state->regs;
    int				trapno, nargs;
    machdep_call_t		*entry;
    
    check_for_trace(state);
    
    trapno = regs->eax;
    if (trapno < 0 || trapno >= machdep_call_count) {
	regs->eax = (unsigned int)kern_invalid();

	thread_exception_return();
	/* NOTREACHED */
    }
    
    entry = &machdep_call_table[trapno];
    nargs = entry->nargs;

    if (nargs > 0) {
	int			args[nargs];

	if (copyin(frame->esp + sizeof (int),
		    args,
		    nargs * sizeof (int))) {

	    regs->eax = KERN_INVALID_ADDRESS;

	    thread_exception_return();
	    /* NOTREACHED */
	}

	asm volatile("
	    1:
	    mov (%2),%%eax;
	    pushl %%eax;
	    sub $4,%2;
	    dec %1;
	    jne 1b;
	    mov %3,%%eax;
	    call *%%eax;
	    mov %%eax,%0"
	    
	    : "=r" (regs->eax)
	    : "r" (nargs),
		"r" (&args[nargs - 1]),
		"g" (entry->routine)
	    : "ax", "cx", "dx", "sp");
    }
    else
	regs->eax = (unsigned int)(*entry->routine)();

    thread_exception_return();
    /* NOTREACHED */
}

void
mach_kernel_trap(
    thread_saved_state_t	*state
)
{
    except_frame_t		*frame = &state->frame;
    regs_t			*regs = &state->regs;
    int				trapno, nargs;
    mach_trap_t			*entry;
    
    check_for_trace(state);
    
    trapno = -(int)regs->eax;
    if (trapno < 0 || trapno >= mach_trap_count) {
	regs->eax = (unsigned int)kern_invalid();

	thread_exception_return();
	/* NOTREACHED */
    }
    
    entry = &mach_trap_table[trapno];
    nargs = entry->mach_trap_arg_count;

    if (nargs > 0) {
	int			args[nargs];

	if (copyin(frame->esp + sizeof (int),
		    args,
		    nargs * sizeof (int))) {

	    exception(EXC_BAD_ACCESS,
	    		KERN_INVALID_ADDRESS,
			frame->esp + sizeof (int));
	    /* NOTREACHED */
	}

	asm volatile("
	    1:
	    mov (%2),%%eax;
	    pushl %%eax;
	    sub $4,%2;
	    dec %1;
	    jne 1b;
	    mov %3,%%eax;
	    call *%%eax;
	    mov %%eax,%0"
	    
	    : "=r" (regs->eax)
	    : "r" (nargs),
		"r" (&args[nargs - 1]),
		"g" (entry->mach_trap_function)
	    : "ax", "cx", "dx", "sp");
    }
    else
	regs->eax = (unsigned int)(*entry->mach_trap_function)();

    thread_exception_return();
    /* NOTREACHED */
}

/*
 * plan 273: unix_syscall and unix_syscall_return use the 4.3BSD u area
 * (setjmp(&uu_qsave), uu_eosys, CS_RPAUSE), as NeXTMach mk-108.1
 * next/trap.c:865-1010; argument fetch as Darwin.
 */
void
unix_syscall(
    thread_saved_state_t	*state
)
{
    except_frame_t		*frame = &state->frame;
    regs_t			*regs = &state->regs;
    thread_t			thread = current_thread();
    struct uthread		*uthread;
    struct sysent		*callp;
    struct proc			*p;
    struct timeval		syst;
    int				nargs, error = 0;
    unsigned short		code;
    caddr_t			params;

    check_for_trace(state);

    uthread = thread->_uthread;
    uthread->uu_ar0 = (int *)state;
    if (p = u.u_procp)
	syst = u.u_ru.ru_stime;
    u.u_error = 0;

    code = regs->eax;
    params = (caddr_t)frame->esp + sizeof (int);
    callp = (code >= nsysent) ? &sysent[63] : &sysent[code];
    if (callp == sysent) {
	code = fuword(params);
	params += sizeof (int);
	callp = (code >= nsysent) ? &sysent[63] : &sysent[code];
    }

    if ((nargs = (callp->sy_narg * sizeof (int))) &&
	    (error = copyin(params, (caddr_t)uthread->uu_arg, nargs)) != 0) {
	regs->eax = error;
	frame->eflags |= EFL_CF;
	thread_exception_return();
	/* NOTREACHED */
    }

    uthread->uu_r.r_val1 = 0;
    uthread->uu_r.r_val2 = regs->edx;

    if (setjmp(&uthread->uu_qsave)) {
	if (uthread->uu_error == 0 && uthread->uu_eosys != RESTARTSYS)
	    error = EINTR;
    } else {
	uthread->uu_eosys = NORMALRETURN;
	uthread->uu_rpswhich = 0;	/* CS_RPAUSE */
	uthread->uu_rpsfs = 0;		/* CS_RPAUSE */
	(*(callp->sy_call))();
	error = uthread->uu_error;
    }

    unix_syscall_return(error);
}

void
unix_syscall_return(
    int				error
)
{
    thread_t			thread = current_thread();
    thread_saved_state_t	*state = USER_REGS(thread);
    struct uthread		*uthread = thread->_uthread;

/* BEGIN CS_RPAUSE */
    if (error) switch (error) {

    case ENOSPC:
	if (fspause(0))
	    u.u_eosys = RESTARTSYS;
	error = uthread->uu_error;	/* can change in fspause */
	break;

    case EAGAIN:	/* as in NeXTMach next/trap.c; these cases produce no code */
    case ENOMEM:
    case ENFILE:
	break;
    }
/* END CS_RPAUSE */

    if (uthread->uu_eosys == NORMALRETURN) {
	if (error) {
	    state->regs.eax = error;
	    state->frame.eflags |= EFL_CF;	/* carry bit */
	} else {
	    state->regs.eax = uthread->uu_r.r_val1;
	    state->regs.edx = uthread->uu_r.r_val2;
	    state->frame.eflags &= ~EFL_CF;
	}
    }
    else if (uthread->uu_eosys == RESTARTSYS)
	state->frame.eip -= 7;

    uthread->uu_error = error;

    thread_exception_return();
    /* NOTREACHED */
}


/*
 * plan 273: check_for_ast uses the u area (SOWEUPC, u_prof, issig/psig,
 * ru_nivcsw), as NeXTMach mk-108.1 next/trap.c:1101.
 */
void
check_for_ast(
    thread_saved_state_t	*state
)
{
    thread_t			thread = current_thread();
    struct proc			*p = u.u_procp;

    while (TRUE) {
	ast_t			reasons;
	int			mycpu = cpu_number();

	cli();		/* disable interrupts */

	reasons = ast_needed(mycpu);

	if (p) {
	    if ((p->p_flag & SOWEUPC) && u.u_prof.pr_scale) {
		addupc(state->frame.eip, &u.u_prof, 1);
		p->p_flag &= ~SOWEUPC;
	    }

	    ast_off(mycpu, AST_UNIX);

	    if (CHECK_SIGNALS(p, thread, thread->_uthread)) {
		if (p->p_cursig || issig(0))
		    psig();
		cli();
	    }
	}

	ast_off(mycpu, reasons);

	if (thread_should_halt(thread))
	    thread_halt_self();
	else
	if ((reasons & AST_BLOCK) ||
		csw_needed(thread, current_processor())) {
	    u.u_ru.ru_nivcsw++;
	    thread_block_with_continuation(thread_exception_return);
	}
	else
	if (reasons & AST_FP_EXTEN)
	    fp_ast(thread);
	else
	    break;
    }
}

typedef struct _cframe_t {
    struct _cframe_t	*prev;
    unsigned		caller;
    unsigned		args[0];
} cframe_t;


#define MAX_FRAME_DELTA		65536

void
_i386_backtrace(
    void			*_frame,
    int				nframes
)
{
	cframe_t	*frame = (cframe_t *)_frame;
	int i;

	for (i=0; i<nframes; i++) {
	    if ((vm_offset_t)frame < VM_MIN_KERNEL_ADDRESS ||
	        (vm_offset_t)frame > VM_MAX_KERNEL_ADDRESS) {
		goto invalid;
	    }
	    safe_prf("frame %x called by %x ",
		frame, frame->caller);
	    safe_prf("args %x %x %x %x\n",
		frame->args[0], frame->args[1],
		frame->args[2], frame->args[3]);
	    if ((frame->prev < frame) ||	/* wrong direction */
	    	((frame->prev - frame) > MAX_FRAME_DELTA)) {
		goto invalid;
	    }
	    frame = frame->prev;
	}
	return;
invalid:
	safe_prf("invalid frame pointer %x\n",frame->prev);
}
