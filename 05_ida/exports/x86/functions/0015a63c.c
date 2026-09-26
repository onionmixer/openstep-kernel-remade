/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a63c. */
void __cdecl send_notification(task_inspect_t task, int a2, int a3)
{
  mach_port_t special_port; // [esp+0h] [ebp-4h] BYREF

  if ( a2 == 66 && !task_get_special_port(task, 2, &special_port) ) /*0x15a652*/
    ipc_notify_msg_accepted_compat(special_port, a3); /*0x15a666*/
}
