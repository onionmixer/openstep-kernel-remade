/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16d5b4. */
kern_return_t pnotify_start()
{
  thread_act_t child_act; // [esp+0h] [ebp-8h] BYREF
  mach_msg_type_number_t ledgersCnt; // [esp+4h] [ebp-4h] BYREF

  task_create(kernel_task, nullptr, (mach_msg_type_number_t)&ledgersCnt, child_act, (task_t *)ledgersCnt); /*0x16d5c7*/
  task_deallocate(ledgersCnt); /*0x16d5d0*/
  thread_create(ledgersCnt, &child_act); /*0x16d5dd*/
  thread_deallocate(child_act); /*0x16d5e6*/
  thread_start(child_act, (int)notify_server_loop); /*0x16d5f4*/
  return thread_resume(child_act); /*0x16d605*/
}
