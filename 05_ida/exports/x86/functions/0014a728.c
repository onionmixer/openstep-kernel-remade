/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14a728. */
int __cdecl ipc_mqueue_changed(int a1, int a2)
{
  int result; // eax

  while ( 1 ) /*0x14a739*/
  {
    result = ipc_thread_dequeue(a1 + 8); /*0x14a739*/
    if ( !result ) /*0x14a743*/
      break; /*0x14a743*/
    *(_DWORD *)(result + 152) = a2; /*0x14a745*/
    thread_go(result); /*0x14a74c*/
  }
  return result; /*0x14a75b*/
}
