/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1621b4. */
int __cdecl sub_1621B4(int a1, _DWORD *a2, _WORD *a3)
{
  if ( *a2 <= 7u ) /*0x1621c4*/
    return 0; /*0x1621f0*/
  *(_BYTE *)a1 |= 0x80u; /*0x1621c6*/
  *(_WORD *)(a1 + 2) = 8; /*0x1621c9*/
  dword_1F66B0 = 1; /*0x1621cf*/
  *a3 = kdp; /*0x1621e0*/
  *a2 = *(unsigned __int16 *)(a1 + 2); /*0x1621e7*/
  return 1; /*0x1621f2*/
}
