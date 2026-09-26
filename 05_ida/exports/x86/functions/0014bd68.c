/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x14bd68. */
int __cdecl ipc_object_destroy(int a1, unsigned int a2)
{
  int result; // eax

  result = a2; /*0x14bd6e*/
  if ( a2 == 17 ) /*0x14bd74*/
    return ipc_port_release_send(a1); /*0x14bd91*/
  if ( a2 > 0x11 ) /*0x14bd76*/
  {
    if ( a2 == 18 ) /*0x14bd87*/
      return ipc_notify_send_once(a1); /*0x14bd9d*/
  }
  else if ( a2 == 16 ) /*0x14bd7b*/
  {
    return ipc_port_release_receive(a1); /*0x14bda9*/
  }
  return result; /*0x14bd7f*/
}
