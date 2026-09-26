/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x147770. */
int __cdecl ipc_kmsg_put_to_kernel(void *a1, int a2, size_t a3)
{
  int result; // eax

  bcopy((const void *)(a2 + 20), a1, a3); /*0x147783*/
  result = *(_DWORD *)(a2 + 8); /*0x14778b*/
  if ( result > 0 ) /*0x147790*/
    return kfree(a2, *(_DWORD *)(a2 + 8)); /*0x147790*/
  switch ( result ) /*0x147795*/
  {
    case -2: /*0x147795*/
      return KernDeviceInterruptMsgRelease(a2); /*0x1477a6*/
    case -1: /*0x147795*/
      return result; /*0x147797*/
    case -3: /*0x147795*/
      return netipc_msg_release(a2); /*0x1477a9*/
    default:
      return kfree(a2, *(_DWORD *)(a2 + 8)); /*0x1477b2*/
  }
}
