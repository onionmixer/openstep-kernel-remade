/* 
 * Mach Operating System
 * Copyright (c) 1989 Carnegie-Mellon University
 * Copyright (c) 1988 Carnegie-Mellon University
 * Copyright (c) 1987 Carnegie-Mellon University
 * All rights reserved.  The CMU software License Agreement specifies
 * the terms and conditions for use and redistribution.
 */
/* 
 * HISTORY
 * $Log:	ast.c,v $
 * 18-May-90  Avadis Tevanian (avie) at NeXT
 *	Updates to use runq->high instead of runq->low.
 *
 * Revision 2.7  89/11/20  11:23:13  mja
 * 	Add MACH_FIXPRI support.  Don't need to update rq->low because
 * 	it's not lazy evaluated if fixed priority threads are allowed.
 * 	[89/11/15            dlb]
 * 
 * Revision 2.6  89/10/11  14:00:47  dlb
 * 	Change sched_pri to 0-31 from 0-127.
 * 	Update rq->low hint if it affects context switch check.
 * 	Extensive rewrite to request ast's for processor actions
 * 	       and support new Mach ast mechanism (incl. HW_AST).
 * 
 * Revision 2.5  89/04/05  13:03:02  rvb
 * 	Forward declaration of csw_check() as boolean_t.
 * 	[89/03/21            rvb]
 * 
 * Revision 2.4  89/02/25  18:00:04  gm0w
 * 	Changes for cleanup.
 * 
 *  4-May-88  David Black (dlb) at Carnegie-Mellon University
 *	Moved cpu not running check to ast_check().
 *	New preempt priority logic.
 *	Increment runrun if ast is for context switch.
 *	Give absolute priority to local run queues.
 *
 * 20-Apr-88  David Black (dlb) at Carnegie-Mellon University
 *	New signal check logic.
 *
 * 18-Nov-87  Avadis Tevanian (avie) at Carnegie-Mellon University
 *	Flushed conditionals, reset history.
 */ 

/*
 *
 *	This file contains routines to check whether an ast is needed.
 *
 *	ast_check() - check whether ast is needed for signal, or context
 *	switch.  Usually called by clock interrupt handler.
 *
 */

#import <cpus.h>
#import <mach_fixpri.h>

/* plan 198: hw_ast.h and machine/pcb.h of NeXTMach are not in this tree (MACHINE_AST in kern/ast.h; no pcb use) */
#import <machine/cpu.h>
#import <kern/ast.h>
#import <sys/param.h>
#import <sys/proc.h>
#import <kern/queue.h>
#import <kern/sched.h>
#import <sys/systm.h>
#import <kern/thread.h>
#import <sys/user.h>
#import <kern/processor.h>

#if	MACH_FIXPRI
#import <mach/policy.h>		/* plan 198: NeXTMach sys/policy.h */
#endif	MACH_FIXPRI

#ifndef	MACHINE_AST
volatile ast_t	need_ast[NCPUS];	/* plan 198: as declared by kern/ast.h */
#endif	MACHINE_AST
/* plan 441 (m68k) begin: the definition below is the same as Mach4
 * kernel/kern/ast.c:58 (also Darwin 0.1 kern/ast.c:82); Mach4's notice:
 */
/*
 * Mach Operating System
 * Copyright (c) 1991,1990,1989,1988,1987 Carnegie Mellon University.
 * Copyright (c) 1993,1994 The University of Utah and
 * the Computer Systems Laboratory (CSL).
 * All rights reserved.
 *
 * Permission to use, copy, modify and distribute this software and its
 * documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 *
 * CARNEGIE MELLON, THE UNIVERSITY OF UTAH AND CSL ALLOW FREE USE OF
 * THIS SOFTWARE IN ITS "AS IS" CONDITION, AND DISCLAIM ANY LIABILITY
 * OF ANY KIND FOR ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF
 * THIS SOFTWARE.
 *
 * Carnegie Mellon requests users of this software to return to
 *
 *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU
 *  School of Computer Science
 *  Carnegie Mellon University
 *  Pittsburgh PA 15213-3890
 *
 * any improvements or extensions that they make and grant Carnegie Mellon
 * the rights to redistribute these changes.
 */
volatile ast_t	need_ast[NCPUS];	/* plan 441 (m68k) end */

ast_init()
{
#ifndef	MACHINE_AST
	register int i;

	for (i=0; i<NCPUS; i++)
		need_ast[i] = 0;
#endif	MACHINE_AST
}

/*
 * plan 198 (authored, D024; original _ast_check 0x1566b0): reasons are
 * posted with ast_on(); the whole check runs at splsched; the signal
 * check comes first.
 */
ast_check()
{
	register struct proc	*p;
	register int		mycpu = cpu_number();
	register processor_t	myprocessor;
	register thread_t	thread = current_thread();
	register run_queue_t	rq;
	spl_t			s = splsched();

	/*
	 *	Check processor state for ast conditions.
	 */
	myprocessor = cpu_to_processor(mycpu);
	switch(myprocessor->state) {
	    case PROCESSOR_OFF_LINE:
	    case PROCESSOR_IDLE:
	    case PROCESSOR_DISPATCHING:
		/*
		 *	No ast.
		 */
	    	break;

#if	NCPUS > 1
	    case PROCESSOR_ASSIGN:
	    case PROCESSOR_SHUTDOWN:
		ast_on(mycpu, AST_BLOCK);
		break;
#endif	NCPUS > 1

	    case PROCESSOR_RUNNING:

		/*
		 *	Check for signals.
		 */
		p = u.u_procp;
		if (p && (p->p_cursig ||
		    (thread && SHOULDissig(p, thread->_uthread))))
			ast_on(mycpu, AST_UNIX);

		/*
		 *	Propagate thread ast to processor.  If we already
		 *	need an ast, don't look for more reasons.
		 */
		ast_propagate(thread, mycpu);
		if (ast_needed(mycpu))
			break;

		/*
		 *	Context switch check.  First check the easy cases.
		 */
		if (thread->state & TH_SUSP || myprocessor->runq.count > 0) {
			ast_on(mycpu, AST_BLOCK);
			break;
		}

#if	MACH_FIXPRI
		if (myprocessor->processor_set->policies & POLICY_FIXEDPRI) {
		    if (csw_needed(thread,myprocessor)) {
			ast_on(mycpu, AST_BLOCK);
			break;
		    }
		    else {
			/*
			 *	For fixed priority threads, set first_quantum
			 *	so entire new quantum is used.
			 */
			if (thread->policy == POLICY_FIXEDPRI)
			    myprocessor->first_quantum = TRUE;
		    }
		}
		else {
#endif	MACH_FIXPRI
		rq = &(myprocessor->processor_set->runq);
		if (!(myprocessor->first_quantum) && (rq->count > 0)) {
		    register queue_t 	q;

		    /*
		     *	Not the first quantum, and there may be something
		     *	in the processor_set runq: check the high hint.
		     */
		    q = rq->runq + *(volatile int *)&rq->high;	/* plan 198.2 */
		    if (queue_empty(q)) {
			register int i;

			simple_lock(&rq->lock);
			q = rq->runq + rq->high;
			if (rq->count > 0) {
			    for (i = rq->high; i >= 0; i--) {
				if (!(queue_empty(q)))
				    break;
				q--;
			    }
			    rq->high = i;
			}
			simple_unlock(&rq->lock);
		    }

		    if (rq->high >= thread->sched_pri) {
			ast_on(mycpu, AST_BLOCK);
			break;
		    }
		}
#if	MACH_FIXPRI
		}
#endif	MACH_FIXPRI
		break;

	    default:
		panic("ast_check: Bad processor state");
	}

	(void) splx(s);
}
