/*
 * machdep/i386/unix_signal.c -- BSD signal delivery on i386 (plan 258).
 *
 * Written for this project from the OPENSTEP 4.2 x86 kernel object
 * [0x1934ec, 0x193a98) (D024).  The signal bookkeeping of sendsig and
 * sigreturn follows NeXTMach next/machdep.c (notice below, D013); the
 * i386 register and selector handling follows the original bytes and
 * Darwin 0.1 machdep/i386/unix_signal.c was consulted for its
 * structure only, so that part may resemble it (D027).
 */

/*
 * The following notice is from NeXTMach mk-108.1 next/machdep.c:
 *
 * Copyright (c) 1987, 1988, 1989 NeXT, Inc.
 */

#import <mach/mach_types.h>
#import <mach/exception.h>

#import <sys/param.h>
#import <sys/proc.h>
#import <sys/user.h>
#import <machine/psl.h>

#import <machdep/i386/sel_inline.h>

#import <pc_support.h>
#if	PC_SUPPORT
#import <machdep/i386/pc_support/PCmiscInline.h>
#endif

/*
 * Send an interrupt to process (NeXTMach next/machdep.c:1082, with
 * the i386 frame).
 */
sendsig(p, sig, mask)
	int (*p)(), sig, mask;
{
    struct sigframe {
	int			sig;
	int			code;
	struct sigcontext *	scp;
    }				frame, *fp;
    struct sigcontext		context, *scp;
    int				oonstack;
    thread_t			thread = current_thread();
    thread_saved_state_t *	saved_state = USER_REGS(thread);

    oonstack = u.u_onstack;
    if (!u.u_onstack && (u.u_sigonstack & sigmask(sig))) {
	scp = (struct sigcontext *)u.u_sigsp - 1;
	u.u_onstack = 1;
    } else
	scp = (struct sigcontext *)saved_state->frame.esp - 1;
    fp = (struct sigframe *)scp - 1;

    /*
     * Build the argument list for the signal handler.
     */
    frame.sig = sig;
    if (sig == SIGILL || sig == SIGFPE) {	/* plan 258: no SIGEMT */
	frame.code = u.u_code;
	u.u_code = 0;
    } else
	frame.code = 0;
    frame.scp = scp;
    if (copyout((caddr_t)&frame, (caddr_t)fp, sizeof (frame)))
	goto bad;

#if	PC_SUPPORT
    {
	PCcontext_t	context = threadPCContext(thread);

	if (context && context->running) {
	    oonstack |= 02;
	    context->running = FALSE;
	}
    }
#endif

    /*
     * Build the signal context to be used by sigreturn.
     */
    context.sc_onstack = oonstack;
    context.sc_mask = mask;
    context.sc_eax = saved_state->regs.eax;
    context.sc_ebx = saved_state->regs.ebx;
    context.sc_ecx = saved_state->regs.ecx;
    context.sc_edx = saved_state->regs.edx;
    context.sc_edi = saved_state->regs.edi;
    context.sc_esi = saved_state->regs.esi;
    context.sc_ebp = saved_state->regs.ebp;
    context.sc_esp = saved_state->frame.esp;
    context.sc_ss = sel_to_selector(saved_state->frame.ss);
    context.sc_eflags = saved_state->frame.eflags;
    context.sc_eip = saved_state->frame.eip;
    context.sc_cs = sel_to_selector(saved_state->frame.cs);
    if (saved_state->frame.eflags & EFL_VM) {
	context.sc_ds = saved_state->frame.v_ds;
	context.sc_es = saved_state->frame.v_es;
	context.sc_fs = saved_state->frame.v_fs;
	context.sc_gs = saved_state->frame.v_gs;

	saved_state->frame.eflags &= ~EFL_VM;
    }
    else {
	context.sc_ds = sel_to_selector(saved_state->regs.ds);
	context.sc_es = sel_to_selector(saved_state->regs.es);
	context.sc_fs = sel_to_selector(saved_state->regs.fs);
	context.sc_gs = sel_to_selector(saved_state->regs.gs);
    }
    if (copyout((caddr_t)&context, (caddr_t)scp, sizeof (context)))
	goto bad;

    saved_state->frame.eip = (unsigned int)p;
    saved_state->frame.cs = UCODE_SEL;

    saved_state->frame.esp = (unsigned int)fp;
    saved_state->frame.ss = UDATA_SEL;

    saved_state->regs.ds = UDATA_SEL;
    saved_state->regs.es = UDATA_SEL;
    saved_state->regs.fs = NULL_SEL;
    saved_state->regs.gs = NULL_SEL;

    return;

bad:
    u.u_signal[SIGILL] = SIG_DFL;
    sig = sigmask(SIGILL);
    u.u_procp->p_sigignore &= ~sig;
    u.u_procp->p_sigcatch &= ~sig;
    u.u_procp->p_sigmask &= ~sig;
    psignal(u.u_procp, SIGILL);
    return;
}

/*
 * System call to clean up after a signal handler (NeXTMach
 * next/machdep.c:1172): restore the mask, the stack state and the
 * registers from the context left by sendsig.
 */
sigreturn()
{
    struct a {
	struct sigcontext *sigcntxp;
    } *uap = (struct a *)u.u_ap;
    struct sigcontext		context;
    thread_t			thread = current_thread();
    thread_saved_state_t *	saved_state = USER_REGS(thread);

    if (copyin((caddr_t)uap->sigcntxp, (caddr_t)&context,
						sizeof (context)))
	return;

    if ((context.sc_eflags & EFL_VM) == 0 &&
	   (!valid_user_code_selector(context.sc_cs) ||
	    !valid_user_data_selector(context.sc_ds) ||
	    !valid_user_data_selector(context.sc_es) ||
	    !valid_user_data_selector(context.sc_fs) ||
	    !valid_user_data_selector(context.sc_gs) ||
	    !valid_user_stack_selector(context.sc_ss))
	)
	return;

    u.u_eosys = JUSTRETURN;
    u.u_onstack = context.sc_onstack & 01;
    u.u_procp->p_sigmask = context.sc_mask &~
	(sigmask(SIGKILL)|sigmask(SIGCONT)|sigmask(SIGSTOP));

    saved_state->regs.eax = context.sc_eax;
    saved_state->regs.ebx = context.sc_ebx;
    saved_state->regs.ecx = context.sc_ecx;
    saved_state->regs.edx = context.sc_edx;
    saved_state->regs.edi = context.sc_edi;
    saved_state->regs.esi = context.sc_esi;
    saved_state->regs.ebp = context.sc_ebp;

    saved_state->frame.esp = context.sc_esp;
    saved_state->frame.ss = selector_to_sel(context.sc_ss);
    saved_state->frame.eflags = context.sc_eflags;
    saved_state->frame.eflags &= ~EFL_USERCLR;
    saved_state->frame.eflags |= EFL_USERSET;
    saved_state->frame.eip = context.sc_eip;
    saved_state->frame.cs = selector_to_sel(context.sc_cs);

    if (context.sc_eflags & EFL_VM) {
	saved_state->regs.ds = NULL_SEL;
	saved_state->regs.es = NULL_SEL;
	saved_state->regs.fs = NULL_SEL;
	saved_state->regs.gs = NULL_SEL;

	saved_state->frame.v_ds = context.sc_ds;
	saved_state->frame.v_es = context.sc_es;
	saved_state->frame.v_fs = context.sc_fs;
	saved_state->frame.v_gs = context.sc_gs;

	saved_state->frame.eflags |= EFL_VM;
    }
    else {
	saved_state->regs.ds = selector_to_sel(context.sc_ds);
	saved_state->regs.es = selector_to_sel(context.sc_es);
	saved_state->regs.fs = selector_to_sel(context.sc_fs);
	saved_state->regs.gs = selector_to_sel(context.sc_gs);
    }

#if	PC_SUPPORT
    if (context.sc_onstack & 02) {
	PCcontext_t	context = threadPCContext(thread);

	if (context)
	    context->running = TRUE;
    }
#endif
}

boolean_t
machine_exception(
    int		exception,
    int		code,
    int		subcode,
    int		*unix_signal,
    int		*unix_code
)
{
    switch (exception) {

    case EXC_BAD_INSTRUCTION:
	*unix_signal = SIGILL;
	*unix_code = code;
	break;

    case EXC_ARITHMETIC:
	*unix_signal = SIGFPE;
	*unix_code = code;
	break;

    default:
	return (FALSE);
    }

    return (TRUE);
}
