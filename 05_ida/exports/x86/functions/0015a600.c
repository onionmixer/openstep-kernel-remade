/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15a600. */
int __cdecl port_reference(int a1)
{
  int result; // eax

  result = a1; /*0x15a603*/
  if ( a1 ) /*0x15a608*/
    return ipc_port_copy_send(a1); /*0x15a60b*/
  return result; /*0x15a612*/
}
