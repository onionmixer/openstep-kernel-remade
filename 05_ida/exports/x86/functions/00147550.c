/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x147550. */
int __cdecl ipc_kmsg_free(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 8); /*0x147556*/
  if ( result == -2 ) /*0x14755c*/
    return KernDeviceInterruptMsgRelease(a1); /*0x147569*/
  if ( result != -1 ) /*0x14755e*/
  {
    if ( result == -3 ) /*0x147563*/
      return netipc_msg_release(a1); /*0x147575*/
    else
      return kfree(a1, *(_DWORD *)(a1 + 8)); /*0x147582*/
  }
  return result; /*0x147570*/
}
