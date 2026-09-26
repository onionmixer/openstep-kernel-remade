/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10dd68. */
int __cdecl ttychars(int a1)
{
  int v1; // eax

  v1 = ttynty(a1); /*0x10dd70*/
  *(_DWORD *)(a1 + 77) = ttydefaults; /*0x10dd7b*/
  *(_DWORD *)(a1 + 81) = dword_1DAF30; /*0x10dd84*/
  *(_DWORD *)(a1 + 85) = dword_1DAF34; /*0x10dd8d*/
  *(_WORD *)(a1 + 89) = word_1DAF38; /*0x10dd97*/
  *(_BYTE *)(v1 + 20) = 92; /*0x10dd9b*/
  *(_BYTE *)(v1 + 21) = 1; /*0x10dd9f*/
  *(_BYTE *)(v1 + 22) = 0; /*0x10dda3*/
  return ttysetspec((_DWORD *)v1); /*0x10ddad*/
}
