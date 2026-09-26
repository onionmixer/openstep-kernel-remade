/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x163d74. */
int __cdecl compute_my_priority(_DWORD *a1)
{
  int result; // eax

  result = a1[20] - (a1[27] >> 25); /*0x163d85*/
  if ( result < 0 ) /*0x163d89*/
    result = 0; /*0x163d8b*/
  a1[22] = result; /*0x163d8d*/
  return result; /*0x163d92*/
}
