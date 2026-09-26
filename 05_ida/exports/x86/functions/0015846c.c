/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15846c. */
int __cdecl mach_msg_send_from_kernel(_DWORD *a1, int a2)
{
  int v2; // eax
  int v4; // [esp+0h] [ebp-4h] BYREF

  v2 = a1[2]; /*0x158475*/
  if ( !v2 || v2 == -1 ) /*0x15847f*/
    return 268435459; /*0x158481*/
  if ( ipc_kmsg_get_from_kernel(a1, a2, 0, &v4) ) /*0x158497*/
    panic(aMachMsgSendFro); /*0x1584a8*/
  ipc_kmsg_copyin_from_kernel((_DWORD *)v4); /*0x1584b4*/
  ipc_mqueue_send(v4, 0x10000, 0, 0); /*0x1584c9*/
  return 0; /*0x158486*/
}
