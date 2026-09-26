/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1622b0. */
int __cdecl sub_1622B0(int a1, _DWORD *a2, _WORD *a3)
{
  unsigned int v4; // esi

  if ( *a2 <= 0xFu ) /*0x1622bf*/
    return 0; /*0x1622c1*/
  *(_BYTE *)a1 |= 0x80u; /*0x1622c8*/
  *(_WORD *)(a1 + 2) = 12; /*0x1622cb*/
  v4 = *(_DWORD *)(a1 + 12); /*0x1622d1*/
  if ( v4 <= 0x400 ) /*0x1622da*/
  {
    copywithin(*(_DWORD *)(a1 + 8), a1 + 12, *(_DWORD *)(a1 + 12)); /*0x1622f1*/
    *(_DWORD *)(a1 + 8) = 0; /*0x1622f6*/
    *(_WORD *)(a1 + 2) += v4; /*0x1622fd*/
  }
  else
  {
    *(_DWORD *)(a1 + 8) = 2; /*0x1622dc*/
  }
  *a3 = kdp; /*0x16230b*/
  *a2 = *(unsigned __int16 *)(a1 + 2); /*0x162312*/
  return 1; /*0x16231c*/
}
