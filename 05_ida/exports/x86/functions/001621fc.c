/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1621fc. */
int __cdecl sub_1621FC(int a1, _DWORD *a2, _WORD *a3)
{
  if ( *a2 <= 0xBu ) /*0x16220c*/
    return 0; /*0x162238*/
  *(_BYTE *)a1 |= 0x80u; /*0x16220e*/
  *(_WORD *)(a1 + 2) = 8; /*0x162211*/
  dword_1F66B0 = 0; /*0x162217*/
  *a3 = kdp; /*0x162228*/
  *a2 = *(unsigned __int16 *)(a1 + 2); /*0x16222f*/
  return 1; /*0x16223a*/
}
