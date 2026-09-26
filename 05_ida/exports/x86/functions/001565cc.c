/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1565cc. */
int __cdecl port_extract_send(int a1, int a2, int a3)
{
  int result; // eax

  if ( !a1 ) /*0x1565d4*/
    return 4; /*0x1565d6*/
  result = ipc_object_copyin_compat(a1, a2, 6, 1, a3); /*0x1565ed*/
  if ( result ) /*0x1565f4*/
    return 4; /*0x1565f6*/
  return result; /*0x1565dd*/
}
