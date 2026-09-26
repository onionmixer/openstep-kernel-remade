/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a614. */
int __cdecl port_release(int a1)
{
  int result; // eax

  result = a1; /*0x15a617*/
  if ( a1 ) /*0x15a61c*/
    return ipc_port_release_send(a1); /*0x15a61f*/
  return result; /*0x15a626*/
}
