/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16236c. */
int __cdecl sub_16236C(int a1, _DWORD *a2, _WORD *a3)
{
  int v3; // eax

  if ( *a2 <= 7u ) /*0x16237d*/
    return 0; /*0x1623d0*/
  *(_BYTE *)a1 |= 0x80u; /*0x16237f*/
  *(_WORD *)(a1 + 2) = 12; /*0x162382*/
  *(_DWORD *)(a1 + 8) = 0; /*0x162388*/
  *(_DWORD *)(a1 + 12) = 0; /*0x16238f*/
  *(_DWORD *)(a1 + 16) = 0x40000000; /*0x162396*/
  *(_DWORD *)(a1 + 20) = 7; /*0x16239d*/
  v3 = *(_DWORD *)(a1 + 8); /*0x1623a4*/
  *(_DWORD *)(a1 + 8) = v3 + 1; /*0x1623aa*/
  *(_WORD *)(a1 + 2) += 4 * (3 * v3 + 3); /*0x1623b4*/
  *a3 = kdp; /*0x1623bf*/
  *a2 = *(unsigned __int16 *)(a1 + 2); /*0x1623c6*/
  return 1; /*0x1623d5*/
}
