/* 
 * Copyright (c) 1988 NeXT, Inc.
 */
/*
 * HISTORY
 * 14-Feb-90  Gregg Kellogg (gk) at NeXT
 *	Get rid of snd_task_name in favor of new task_name in bsd/init_main.c
 *
 * 10-Dec-88  Gregg Kellogg (gk) at NeXT
 *	Created.
 *
 */ 

/*
 * plan 646 (D148, D013, D024, D123): the 1997 m68k snd_unix.c.  NeXTMach
 * mk-108.1 nextdev/snd_unix.c with the 1997 changes written from the
 * original bytes [0x408833a, 0x408844e) (plan 645):
 *	thread_start() takes two arguments (no THREAD_SYSTEMMODE)
 *	port_deallocate() takes the IPC space: current_task()->itk_space and
 *	snd_var.task_space (D123)
 * The store snd_var.task_port = PORT_NULL is kept as NeXTMach has it; the
 * compiler drops it, the bytes are the same without it (user decision D148).
 * Lines marked plan 646 differ from NeXTMach.
 */
#import <sound.h>
#if	NSOUND > 0

/*
 * Routines to make unix happy.
 * ioctl	- to get the device port returned.
 */

#import <sys/param.h>
#import <sys/ioctl.h>
#import <sys/errno.h>
#import <kern/kern_port.h>
#import <nextdev/snd_var.h>
#import <sys/user.h>

extern snd_var_t snd_var;

snd_unix_ioctl(dev, cmd, datap, flag)
	dev_t	dev;
	int	cmd, flag;
	int	*datap;
{
	msg_header_t msg;
	port_t lport;
	task_t newtask;

	if (cmd != SOUNDIOCDEVPORT)
		return(EINVAL);

	if (!snd_var.task_port) {
		thread_t snd_th;
		
		snd_var.task_port = PORT_NULL;
		(void) task_create(kernel_task, FALSE, &newtask);
		(void) thread_create(newtask, &snd_th);
		thread_start(snd_th, snd_server_loop);	/* plan 646 (D024): 1997 two arguments, 0x4088380 */
		(void) thread_resume(snd_th);
		if (snd_var.task_port == PORT_NULL) {
			assert_wait((int)&snd_var.task_port, FALSE);
			thread_block();
		}
	}
	object_copyin(current_task(), *datap, MSG_TYPE_PORT, FALSE, datap);
	object_copyin(snd_var.task, snd_var.dev_port, MSG_TYPE_PORT, FALSE,
			&lport);

	msg.msg_simple = TRUE;
	msg.msg_size = sizeof(msg);
	msg.msg_type = MSG_TYPE_NORMAL;
	msg.msg_local_port = (port_t)lport;
	msg.msg_remote_port = *(port_t *)datap;
	msg.msg_id = SND_MSG_RET_DEVICE;

	msg_send_from_kernel(&msg, MSG_OPTION_NONE, 0);

	port_deallocate(current_task()->itk_space, *(port_t *)datap);	/* plan 646 (D024): 1997 IPC space, 0x408841e */
	port_deallocate(snd_var.task_space, lport);	/* plan 646 (D024, D123): 1997 IPC space, 0x4088438 */

	return(0);
}
#endif	NSOUND > 0


