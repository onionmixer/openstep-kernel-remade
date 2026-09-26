/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12a9e0. */
int __cdecl tcp_canceltimers(int a1)
{
  int result; // eax

  for ( result = 3; result >= 0; --result ) /*0x12a9e6*/
    *(_WORD *)(a1 + 2 * result + 10) = 0; /*0x12a9ec*/
  return result; /*0x12a9f8*/
}
