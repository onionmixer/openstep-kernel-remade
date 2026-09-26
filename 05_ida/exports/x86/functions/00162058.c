/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x162058. */
int __cdecl sub_162058(int a1, _DWORD *a2, _WORD *a3)
{
  if ( *a2 <= 0xBu ) /*0x162069*/
    return 0; /*0x16206d*/
  if ( !dword_1F66A8 ) /*0x162077*/
  {
    kdp = *(_WORD *)(a1 + 8); /*0x162094*/
    word_1F66B4 = *(_WORD *)(a1 + 10); /*0x16209f*/
    dword_1F66A8 = 1; /*0x1620a6*/
    dword_1F66A4 = *(unsigned __int8 *)(a1 + 1); /*0x1620b4*/
    goto LABEL_7; /*0x1620b4*/
  }
  if ( dword_1F66A4 == *(unsigned __int8 *)(a1 + 1) ) /*0x162083*/
  {
LABEL_7:
    *(_DWORD *)(a1 + 8) = 0; /*0x1620ba*/
    goto LABEL_8; /*0x1620ba*/
  }
  *(_DWORD *)(a1 + 8) = 1; /*0x162085*/
LABEL_8:
  *(_BYTE *)a1 |= 0x80u; /*0x1620c1*/
  *(_WORD *)(a1 + 2) = 12; /*0x1620c4*/
  *a3 = kdp; /*0x1620d1*/
  *a2 = *(unsigned __int16 *)(a1 + 2); /*0x1620d8*/
  return 1; /*0x1620e2*/
}
