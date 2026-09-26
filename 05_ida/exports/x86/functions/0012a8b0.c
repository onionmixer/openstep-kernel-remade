/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12a8b0. */
int __cdecl tcp_quench(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 32); /*0x12a8b6*/
  if ( result ) /*0x12a8bb*/
    *(_WORD *)(result + 84) = *(_WORD *)(result + 24); /*0x12a8c1*/
  return result; /*0x12a8c7*/
}
