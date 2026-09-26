/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x156660. */
int __cdecl port_extract_receive(int a1, int a2, int a3)
{
  int result; // eax

  if ( !a1 ) /*0x156668*/
    return 4; /*0x15666a*/
  result = ipc_object_copyin_compat(a1, a2, 5, 1, a3); /*0x156681*/
  if ( result ) /*0x156688*/
    return 4; /*0x15668a*/
  return result; /*0x156671*/
}
