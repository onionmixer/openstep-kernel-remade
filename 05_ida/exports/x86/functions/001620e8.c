/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1620e8. */
int __cdecl sub_1620E8(int a1, _DWORD *a2, _WORD *a3)
{
  if ( *a2 <= 7u || !dword_1F66A8 ) /*0x162101*/
    return 0; /*0x16215c*/
  *a3 = kdp; /*0x16210a*/
  word_1F66B4 = 0; /*0x16210d*/
  kdp = 0; /*0x162116*/
  dword_1F66A8 = 0; /*0x16211f*/
  dword_1F66B0 = 0; /*0x162129*/
  dword_1F66A4 = 0; /*0x162133*/
  byte_1F66B6 = 0; /*0x16213d*/
  *(_BYTE *)a1 |= 0x80u; /*0x162144*/
  *(_WORD *)(a1 + 2) = 8; /*0x162147*/
  *a2 = 8; /*0x16214d*/
  return 1; /*0x16215e*/
}
