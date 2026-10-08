/* 
 * Mach Operating System
 * Copyright (c) 1991,1990 Carnegie Mellon University
 * All Rights Reserved.
 * 
 * Permission to use, copy, modify and distribute this software and its
 * documentation is hereby granted, provided that both the copyright
 * notice and this permission notice appear in all copies of the
 * software, derivative works or modified versions, and any portions
 * thereof, and that both notices appear in supporting documentation.
 * 
 * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"
 * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR
 * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.
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

#include <norma_vm.h>
#include <mach_ipc_compat.h>	/* plan 265 */

#include <mach/boolean.h>
#include <mach/port.h>
#include <mach/message.h>
#include <mach/thread_status.h>
#include <kern/ast.h>
#include <kern/ipc_tt.h>
#include <kern/thread.h>
#include <kern/task.h>
#include <kern/ipc_kobject.h>
#include <vm/vm_map.h>
#include <vm/vm_user.h>
#include <ipc/port.h>
#include <ipc/ipc_kmsg.h>
#include <ipc/ipc_entry.h>
#include <ipc/ipc_object.h>
#include <ipc/ipc_mqueue.h>
#include <ipc/ipc_space.h>
#include <ipc/ipc_port.h>
#include <ipc/ipc_pset.h>
#include <ipc/ipc_thread.h>


/*
 *	Routine:	mach_msg_send_from_kernel
 *	Purpose:
 *		Send a message from the kernel.
 *
 *		This is used by the client side of KernelUser interfaces
 *		to implement SimpleRoutines.  Currently, this includes
 *		device_reply and memory_object messages.
 *	Conditions:
 *		Nothing locked.
 *	Returns:
 *		MACH_MSG_SUCCESS	Sent the message.
 *		MACH_SEND_INVALID_DATA	Bad destination port.
 */

mach_msg_return_t
mach_msg_send_from_kernel(
	mach_msg_header_t	*msg,
	mach_msg_size_t		send_size)
{
	ipc_kmsg_t kmsg;
	mach_msg_return_t mr;

	if (!MACH_PORT_VALID(msg->msgh_remote_port))
		return MACH_SEND_INVALID_DEST;

	mr = ipc_kmsg_get_from_kernel(msg, send_size, 0, &kmsg);	/* plan 265: delta 0 */
	if (mr != MACH_MSG_SUCCESS)
		panic("mach_msg_send_from_kernel");

	ipc_kmsg_copyin_from_kernel(kmsg);
	ipc_mqueue_send_always(kmsg);

	return MACH_MSG_SUCCESS;
}

/* plan 265: no mach_msg_rpc_from_kernel stub in the original object */

#if	NORMA_VM
/*
 *	Routine:	mach_msg_rpc_from_kernel
 *	Purpose:
 *		Send a message from the kernel and receive a reply.
 *		Uses ith_rpc_reply for the reply port.
 *
 *		This is used by the client side of KernelUser interfaces
 *		to implement Routines.
 *	Conditions:
 *		Nothing locked.
 *	Returns:
 *		MACH_MSG_SUCCESS	Sent the message.
 *		MACH_RCV_PORT_DIED	The reply port was deallocated.
 */

mach_msg_return_t
mach_msg_rpc_from_kernel(
	mach_msg_header_t	*msg,
	mach_msg_size_t		send_size,
	mach_msg_size_t		rcv_size)
{
	ipc_thread_t self = current_thread();
	ipc_port_t reply;
	ipc_kmsg_t kmsg;
	mach_port_seqno_t seqno;
	mach_msg_return_t mr;

	assert(MACH_PORT_VALID(msg->msgh_remote_port));
	assert(msg->msgh_local_port == MACH_PORT_NULL);

	mr = ipc_kmsg_get_from_kernel(msg, send_size, &kmsg);
	if (mr != MACH_MSG_SUCCESS)
		panic("mach_msg_rpc_from_kernel");

	ipc_kmsg_copyin_from_kernel(kmsg);

	ith_lock(self);
	assert(self->ith_self != IP_NULL);

	reply = self->ith_rpc_reply;
	if (reply == IP_NULL) {
		ith_unlock(self);
		reply = ipc_port_alloc_reply();
		ith_lock(self);
		if ((reply == IP_NULL) ||
		    (self->ith_rpc_reply != IP_NULL))
			panic("mach_msg_rpc_from_kernel");
		self->ith_rpc_reply = reply;
	}

	/* insert send-once right for the reply port */
	kmsg->ikm_header.msgh_local_port =
		(mach_port_t) ipc_port_make_sonce(reply);

	ipc_port_reference(reply);
	ith_unlock(self);

	ipc_mqueue_send_always(kmsg);

	for (;;) {
		ipc_mqueue_t mqueue;

		ip_lock(reply);
		if (!ip_active(reply)) {
			ip_unlock(reply);
			ipc_port_release(reply);
			return MACH_RCV_PORT_DIED;
		}

		assert(reply->ip_pset == IPS_NULL);
		mqueue = &reply->ip_messages;
		imq_lock(mqueue);
		ip_unlock(reply);

		mr = ipc_mqueue_receive(mqueue, MACH_MSG_OPTION_NONE,
					MACH_MSG_SIZE_MAX,
					MACH_MSG_TIMEOUT_NONE,
					FALSE, IMQ_NULL_CONTINUE,
					&kmsg, &seqno);
		/* mqueue is unlocked */
		if (mr == MACH_MSG_SUCCESS)
			break;

		assert((mr == MACH_RCV_INTERRUPTED) ||
		       (mr == MACH_RCV_PORT_DIED));

		while (thread_should_halt(self)) {
			/* don't terminate while holding a reference */
			if (self->ast & AST_TERMINATE)
				ipc_port_release(reply);
			thread_halt_self();
		}
	}
	ipc_port_release(reply);

	kmsg->ikm_header.msgh_seqno = seqno;

	if (rcv_size < kmsg->ikm_header.msgh_size) {
		ipc_kmsg_copyout_dest(kmsg, ipc_space_reply);
		ipc_kmsg_put_to_kernel(msg, kmsg, kmsg->ikm_header.msgh_size);
		return MACH_RCV_TOO_LARGE;
	}

	/*
	 *	We want to preserve rights and memory in reply!
	 *	We don't have to put them anywhere; just leave them
	 *	as they are.
	 */

	ipc_kmsg_copyout_to_kernel(kmsg, ipc_space_reply);
	ipc_kmsg_put_to_kernel(msg, kmsg, kmsg->ikm_header.msgh_size);
	return MACH_MSG_SUCCESS;
}
#endif	NORMA_VM

/*
 *	Routine:	mach_msg_abort_rpc
 *	Purpose:
 *		Destroy the thread's ith_rpc_reply port.
 *		This will interrupt a mach_msg_rpc_from_kernel
 *		with a MACH_RCV_PORT_DIED return code.
 *	Conditions:
 *		Nothing locked.
 */

void
mach_msg_abort_rpc(thread)
	ipc_thread_t thread;
{
	ipc_port_t reply = IP_NULL;

	ith_lock(thread);
	if (thread->ith_self != IP_NULL) {
		reply = thread->ith_rpc_reply;
		thread->ith_rpc_reply = IP_NULL;
	}
	ith_unlock(thread);

	if (reply != IP_NULL)
		ipc_port_dealloc_reply(reply);
}

/*
 *	Routine:	mach_msg
 *	Purpose:
 *		Like mach_msg_trap except that message buffers
 *		live in kernel space.  Doesn't handle any options.
 *
 *		This is used by in-kernel server threads to make
 *		kernel calls, to receive request messages, and
 *		to send reply messages.
 *	Conditions:
 *		Nothing locked.
 *	Returns:
 */

mach_msg_return_t
mach_msg(msg, option, send_size, rcv_size, rcv_name, time_out, notify)
	mach_msg_header_t *msg;
	mach_msg_option_t option;
	mach_msg_size_t send_size;
	mach_msg_size_t rcv_size;
	mach_port_t rcv_name;
	mach_msg_timeout_t time_out;
	mach_port_t notify;
{
	ipc_space_t space = current_space();
	vm_map_t map = current_map();
	ipc_kmsg_t kmsg;
	mach_port_seqno_t seqno;
	mach_msg_return_t mr;

	if (option & MACH_SEND_MSG) {
		mr = ipc_kmsg_get_from_kernel(msg, send_size, 0, &kmsg);	/* plan 265 */
		if (mr != MACH_MSG_SUCCESS)
			panic("mach_msg");

		mr = ipc_kmsg_copyin(kmsg, space, map, MACH_PORT_NULL);
		if (mr != MACH_MSG_SUCCESS) {
			ikm_free(kmsg);
			return mr;
		}

		do
			mr = ipc_mqueue_send(kmsg, MACH_MSG_OPTION_NONE,
					     MACH_MSG_TIMEOUT_NONE,
					     IMQ_NULL_CONTINUE);	/* plan 265 */
		while (mr == MACH_SEND_INTERRUPTED);
		assert(mr == MACH_MSG_SUCCESS);
	}

	if (option & MACH_RCV_MSG) {
		do {
			ipc_object_t object;
			ipc_mqueue_t mqueue;

			mr = ipc_mqueue_copyin(space, rcv_name,
					       &mqueue, &object);
			if (mr != MACH_MSG_SUCCESS)
				return mr;
			/* hold ref for object; mqueue is locked */

			mr = ipc_mqueue_receive(mqueue, MACH_MSG_OPTION_NONE,
						MACH_MSG_SIZE_MAX,
						MACH_MSG_TIMEOUT_NONE,
						FALSE, IMQ_NULL_CONTINUE,
						&kmsg, &seqno);
			/* mqueue is unlocked */
			ipc_object_release(object);
		} while (mr == MACH_RCV_INTERRUPTED);
		if (mr != MACH_MSG_SUCCESS)
			return mr;

		kmsg->ikm_header.msgh_seqno = seqno;

		if (rcv_size < kmsg->ikm_header.msgh_size) {
			ipc_kmsg_copyout_dest(kmsg, space);
			ipc_kmsg_put_to_kernel(msg, kmsg, sizeof *msg);
			return MACH_RCV_TOO_LARGE;
		}

		mr = ipc_kmsg_copyout(kmsg, space, map, MACH_PORT_NULL);
		if (mr != MACH_MSG_SUCCESS) {
			if ((mr &~ MACH_MSG_MASK) == MACH_RCV_BODY_ERROR) {
				ipc_kmsg_put_to_kernel(msg, kmsg,
						kmsg->ikm_header.msgh_size +
						kmsg->ikm_delta);	/* plan 265 */
			} else {
				ipc_kmsg_copyout_dest(kmsg, space);
				ipc_kmsg_put_to_kernel(msg, kmsg, sizeof *msg);
			}

			return mr;
		}

		ipc_kmsg_put_to_kernel(msg, kmsg, kmsg->ikm_header.msgh_size +
				       kmsg->ikm_delta);	/* plan 265 */
	}

	return MACH_MSG_SUCCESS;
}

#if	MACH_IPC_COMPAT
/*
 *	plan 265: old-IPC entry points.  Written from the original
 *	bytes (D024); the control flow the bytes require resembles
 *	Darwin 0.1 kern/ipc_mig.c, consulted for structure only (D027).
 */

msg_return_t
msg_send_from_kernel(msg, option, time_out)
	msg_header_t *msg;
	msg_option_t option;
	msg_timeout_t time_out;
{
	msg_size_t send_size = msg->msg_size;
	ipc_kmsg_t kmsg;
	integer_t send_delta = send_size;
	mach_msg_return_t mr;

	send_size = (send_size + 3) & ~3;	/* round up */
	send_delta -= send_size;

	mr = ipc_kmsg_get_from_kernel((mach_msg_header_t *) msg,
				      (mach_msg_size_t) send_size,
				      send_delta, &kmsg);
	if (mr != MACH_MSG_SUCCESS)
		return msg_return_translate(mr);

	ipc_kmsg_copyin_compat_from_kernel(kmsg);
	if (option & SEND_NOTIFY)
		panic("msg_send_from_kernel");
	else
		mr = ipc_mqueue_send(kmsg,
				     ((option & SEND_TIMEOUT) ?
				      MACH_SEND_TIMEOUT : MACH_MSG_OPTION_NONE) |
				     MACH_SEND_ALWAYS | MACH_SEND_SWITCH,
				     (mach_msg_timeout_t) time_out,
				     IMQ_NULL_CONTINUE);

	if (mr != MACH_MSG_SUCCESS)
		ipc_kmsg_destroy(kmsg);

	return msg_return_translate(mr);
}

msg_return_t
msg_send(msg, option, time_out)
	msg_header_t *msg;
	msg_option_t option;
	msg_timeout_t time_out;
{
	ipc_space_t space = current_space();
	vm_map_t map = current_map();
	msg_size_t send_size = msg->msg_size;
	ipc_kmsg_t kmsg;
	integer_t send_delta = send_size;
	mach_msg_return_t mr;

	send_size = (send_size + 3) & ~3;	/* round up */
	send_delta -= send_size;

	if (send_size > MSG_SIZE_MAX)
		return SEND_MSG_TOO_LARGE;

	mr = ipc_kmsg_get_from_kernel((mach_msg_header_t *) msg,
				      (mach_msg_size_t) send_size,
				      send_delta, &kmsg);
	if (mr != MACH_MSG_SUCCESS)
		return msg_return_translate(mr);

	mr = ipc_kmsg_copyin_compat(kmsg, space, map);
	if (mr != MACH_MSG_SUCCESS) {
		ikm_free(kmsg);
		return msg_return_translate(mr);
	}

	if (option & SEND_NOTIFY)
		panic("msg_send notify");
	else
		do {
			if (option & SEND_SWITCH)
				mr = ipc_mqueue_send(kmsg,
					((option & SEND_TIMEOUT) ?
					 MACH_SEND_TIMEOUT : MACH_MSG_OPTION_NONE) |
					MACH_SEND_SWITCH,
					(mach_msg_timeout_t) time_out,
					IMQ_NULL_CONTINUE);
			else
				mr = ipc_mqueue_send(kmsg,
					((option & SEND_TIMEOUT) ?
					 MACH_SEND_TIMEOUT : MACH_MSG_OPTION_NONE),
					(mach_msg_timeout_t) time_out,
					IMQ_NULL_CONTINUE);
			if (mr == MACH_SEND_INTERRUPTED) {
				while (thread_should_halt(current_thread()))
					thread_halt_self_with_continuation(
						(void (*)(void)) 0);
				if (option & SEND_INTERRUPT)
					break;
			}
		} while (mr == MACH_SEND_INTERRUPTED);

	if (mr != MACH_MSG_SUCCESS)
		ipc_kmsg_destroy(kmsg);

	return msg_return_translate(mr);
}

msg_return_t
msg_receive(msg, option, time_out)
	msg_header_t *msg;
	msg_option_t option;
	msg_timeout_t time_out;
{
	ipc_space_t space = current_space();
	vm_map_t map = current_map();
	port_name_t rcv_name = msg->msg_local_port;
	msg_size_t rcv_size = msg->msg_size;
	ipc_object_t object;
	ipc_mqueue_t mqueue;
	ipc_kmsg_t kmsg;
	mach_port_seqno_t seqno;
	mach_msg_return_t mr;

	do {
		mr = ipc_mqueue_copyin(space, (mach_port_t) rcv_name,
				       &mqueue, &object);
		if (mr != MACH_MSG_SUCCESS)
			return msg_return_translate(mr);
		/* hold ref for object; mqueue is locked */

		mr = ipc_mqueue_receive(mqueue,
					((option & RCV_TIMEOUT) ?
					 MACH_RCV_TIMEOUT : MACH_MSG_OPTION_NONE),
					(option & RCV_LARGE) ?
					 (mach_msg_size_t) rcv_size : MACH_MSG_SIZE_MAX,
					(mach_msg_timeout_t) time_out,
					FALSE, IMQ_NULL_CONTINUE,
					&kmsg, &seqno);
		/* mqueue is unlocked */
		ipc_object_release(object);
		if (mr == MACH_RCV_INTERRUPTED) {
			while (thread_should_halt(current_thread()))
				thread_halt_self_with_continuation(
					(void (*)(void)) 0);
			if (option & RCV_INTERRUPT)
				break;
		}
	} while (mr == MACH_RCV_INTERRUPTED);

	if (mr != MACH_MSG_SUCCESS) {
		if (mr == MACH_RCV_TOO_LARGE)
			msg->msg_size = (msg_size_t) (mach_msg_size_t) kmsg;
		return msg_return_translate(mr);
	}

	if (kmsg->ikm_header.msgh_size > (mach_msg_size_t) rcv_size) {
		ipc_kmsg_destroy(kmsg);
		return msg_return_translate(MACH_RCV_TOO_LARGE);
	}

	mr = ipc_kmsg_copyout_compat(kmsg, space, map);
	kmsg->ikm_header.msgh_size += kmsg->ikm_delta;
	ipc_kmsg_put_to_kernel((mach_msg_header_t *) msg, kmsg,
			       kmsg->ikm_header.msgh_size);
	return msg_return_translate(mr);
}

/*
 *	msg_rpc keeps a reference to the reply port carried in the
 *	request instead of looking the receive name up again, and
 *	hands requests for kernel objects straight to
 *	ipc_kobject_server.
 */

msg_return_t
msg_rpc(msg, option, rcv_size, send_timeout, rcv_timeout)
	msg_header_t *msg;	/* in/out */
	msg_option_t option;
	msg_size_t rcv_size;
	msg_timeout_t send_timeout;
	msg_timeout_t rcv_timeout;
{
	ipc_space_t space = current_space();
	vm_map_t map = current_map();
	msg_size_t send_size = msg->msg_size;
	ipc_port_t reply;
	ipc_pset_t pset;
	ipc_mqueue_t mqueue;
	ipc_kmsg_t kmsg;
	integer_t send_delta = send_size;
	mach_port_seqno_t seqno;
	mach_msg_return_t mr;

	send_size = (send_size + 3) & ~3;	/* round up */
	send_delta -= send_size;

	if (send_size > MSG_SIZE_MAX)
		return SEND_MSG_TOO_LARGE;

	mr = ipc_kmsg_get_from_kernel((mach_msg_header_t *) msg,
				      (mach_msg_size_t) send_size,
				      send_delta, &kmsg);
	if (mr != MACH_MSG_SUCCESS)
		return msg_return_translate(mr);

	mr = ipc_kmsg_copyin_compat(kmsg, space, map);
	if (mr != MACH_MSG_SUCCESS) {
		ikm_free(kmsg);
		return msg_return_translate(mr);
	}

	reply = (ipc_port_t) kmsg->ikm_header.msgh_local_port;
	if (IP_VALID(reply)) {
		ipc_port_t dest = (ipc_port_t) kmsg->ikm_header.msgh_remote_port;

		ipc_port_reference(reply);
		ip_lock(dest);

		if (dest->ip_receiver == ipc_space_kernel) {
			ip_unlock(dest);

			kmsg = ipc_kobject_server(kmsg);
			if (kmsg == IKM_NULL)
				goto receive_reply;

			ip_lock(reply);

			if (!ip_active(reply) ||
			    (reply->ip_receiver != space) ||
			    (reply->ip_pset != IPS_NULL) ||
			    (rcv_size < kmsg->ikm_header.msgh_size +
					kmsg->ikm_delta)) {
				ip_unlock(reply);
				ipc_mqueue_send_always(kmsg);
				goto receive_reply;
			}

			mqueue = &reply->ip_messages;
			imq_lock(mqueue);

			if ((ipc_thread_queue_first(&mqueue->imq_threads)
							!= ITH_NULL) ||
			    (ipc_kmsg_queue_first(&mqueue->imq_messages)
							!= IKM_NULL)) {
				imq_unlock(mqueue);
				ip_unlock(reply);
				ipc_mqueue_send_always(kmsg);
				goto receive_reply;
			}

			reply->ip_seqno++;
			imq_unlock(mqueue);

			ip_release(reply);
			ip_unlock(reply);

			goto copyout_reply;
		}

		ip_unlock(dest);
	}

	if (option & SEND_NOTIFY)
		panic("msg_rpc notify");
	else
		do {
			if (option & SEND_SWITCH)
				mr = ipc_mqueue_send(kmsg,
					((option & SEND_TIMEOUT) ?
					 MACH_SEND_TIMEOUT : MACH_MSG_OPTION_NONE) |
					MACH_SEND_SWITCH,
					(mach_msg_timeout_t) send_timeout,
					IMQ_NULL_CONTINUE);
			else
				mr = ipc_mqueue_send(kmsg,
					((option & SEND_TIMEOUT) ?
					 MACH_SEND_TIMEOUT : MACH_MSG_OPTION_NONE),
					(mach_msg_timeout_t) send_timeout,
					IMQ_NULL_CONTINUE);
			if (mr == MACH_SEND_INTERRUPTED) {
				while (thread_should_halt(current_thread()))
					thread_halt_self_with_continuation(
						(void (*)(void)) 0);
				if (option & SEND_INTERRUPT)
					break;
			}
		} while (mr == MACH_SEND_INTERRUPTED);

	if (mr != MACH_MSG_SUCCESS) {
		ipc_kmsg_destroy(kmsg);
		if (IP_VALID(reply))
			ipc_port_release(reply);
		return msg_return_translate(mr);
	}

    receive_reply:
	if (!IP_VALID(reply))
		return RCV_INVALID_PORT;

	ip_lock(reply);
	if (reply->ip_receiver != space) {
		ip_release(reply);
		ip_check_unlock(reply);
		return RCV_INVALID_PORT;
	}

	pset = reply->ip_pset;
	if (pset != IPS_NULL) {
		ips_lock(pset);
		if (ips_active(pset)) {
			ips_unlock(pset);
			ip_release(reply);
			ip_unlock(reply);
			return RCV_INVALID_PORT;
		}

		ipc_pset_remove(pset, reply);
		ips_check_unlock(pset);
	}

	mqueue = &reply->ip_messages;
	imq_lock(mqueue);
	ip_unlock(reply);

	mr = ipc_mqueue_receive(mqueue,
				((option & RCV_TIMEOUT) ?
				 MACH_RCV_TIMEOUT : MACH_MSG_OPTION_NONE),
				(option & RCV_LARGE) ?
				 (mach_msg_size_t) rcv_size : MACH_MSG_SIZE_MAX,
				(mach_msg_timeout_t) rcv_timeout,
				FALSE, IMQ_NULL_CONTINUE,
				&kmsg, &seqno);
	/* mqueue is unlocked */
	ipc_port_release(reply);
	if (mr != MACH_MSG_SUCCESS) {
		if (mr == MACH_RCV_INTERRUPTED) {
			while (thread_should_halt(current_thread()))
				thread_halt_self_with_continuation(
					(void (*)(void)) 0);
			msg->msg_size = rcv_size;
			if (!(option & RCV_INTERRUPT))
				return msg_receive(msg, option, rcv_timeout);
		} else if (mr == MACH_RCV_TOO_LARGE)
			msg->msg_size = (msg_size_t) (mach_msg_size_t) kmsg;

		return msg_return_translate(mr);
	}

	if (kmsg->ikm_header.msgh_size > (mach_msg_size_t) rcv_size) {
		ipc_kmsg_destroy(kmsg);
		return msg_return_translate(MACH_RCV_TOO_LARGE);
	}

    copyout_reply:
	mr = ipc_kmsg_copyout_compat(kmsg, space, map);
	kmsg->ikm_header.msgh_size += kmsg->ikm_delta;
	ipc_kmsg_put_to_kernel((mach_msg_header_t *) msg, kmsg,
			       kmsg->ikm_header.msgh_size);
	return msg_return_translate(mr);
}
#endif	/* MACH_IPC_COMPAT */

/*
 *	Routine:	mig_get_reply_port
 *	Purpose:
 *		Called by client side interfaces living in the kernel
 *		to get a reply port.  This port is used for
 *		mach_msg() calls which are kernel calls.
 */

mach_port_t
mig_get_reply_port(void)
{
	ipc_thread_t self = current_thread();

	if (self->ith_mig_reply == MACH_PORT_NULL)
		self->ith_mig_reply = mach_reply_port();

	return self->ith_mig_reply;
}

/*
 *	Routine:	mig_dealloc_reply_port
 *	Purpose:
 *		Called by client side interfaces to get rid of a reply port.
 *		Shouldn't ever be called inside the kernel, because
 *		kernel calls shouldn't prompt Mig to call it.
 */

void
mig_dealloc_reply_port(
	mach_port_t	reply_port)
{
	panic("mig_dealloc_reply_port");
}

/* plan 265: no mig_put_reply_port in the original object */

/*
 * mig_strncpy.c - by Joshua Block
 *
 * mig_strncp -- Bounded string copy.  Does what the library routine strncpy
 * OUGHT to do:  Copies the (null terminated) string in src into dest, a 
 * buffer of length len.  Assures that the copy is still null terminated
 * and doesn't overflow the buffer, truncating the copy if necessary.
 *
 * Parameters:
 * 
 *     dest - Pointer to destination buffer.
 * 
 *     src - Pointer to source string.
 * 
 *     len - Length of destination buffer.
 */
void mig_strncpy(dest, src, len)
char *dest, *src;
int len;
{
    int i;

    if (len <= 0)
	return;

    for (i=1; i<len; i++)
	if (! (*dest++ = *src++))
	    return;

    *dest = '\0';
    return;
}

/*
 * plan 265: the port_name_to_* and syscall_* routines of Mach4 are not
 * in the original object.
 */
