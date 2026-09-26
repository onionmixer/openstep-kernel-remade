/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x162244. */
int __cdecl sub_162244(int a1, _DWORD *a2, _WORD *a3)
{
  if ( *a2 <= 0xFu ) /*0x162256*/
    return 0; /*0x162258*/
  if ( *(_DWORD *)(a1 + 12) <= 0x400u ) /*0x162264*/
  {
    copywithin(a1 + 16, *(_DWORD *)(a1 + 8), *(_DWORD *)(a1 + 12)); /*0x162279*/
    *(_DWORD *)(a1 + 8) = 0; /*0x16227e*/
  }
  else
  {
    *(_DWORD *)(a1 + 8) = 2; /*0x162266*/
  }
  *(_BYTE *)a1 |= 0x80u; /*0x162285*/
  *(_WORD *)(a1 + 2) = 12; /*0x162288*/
  *a3 = kdp; /*0x162295*/
  *a2 = *(unsigned __int16 *)(a1 + 2); /*0x16229c*/
  return 1; /*0x1622a6*/
}
