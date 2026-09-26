/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1924a0. */
int __cdecl sub_1924A0(int a1)
{
  int v1; // eax

  v1 = *(_DWORD *)(active_threads + 116); /*0x1924ab*/
  if ( !v1 ) /*0x1924b0*/
    return 0; /*0x1924b2*/
  *(_DWORD *)(a1 + 4) = v1; /*0x1924b8*/
  *(_WORD *)(a1 + 8) = 8; /*0x1924bb*/
  *(_DWORD *)(a1 + 12) &= ~0x400u; /*0x1924c1*/
  *(_DWORD *)(active_threads + 116) = 0; /*0x1924cd*/
  return 1; /*0x1924b6*/
}
