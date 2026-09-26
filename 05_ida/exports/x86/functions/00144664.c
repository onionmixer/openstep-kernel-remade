/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x144664. */
int __cdecl sub_144664(int a1, __int16 a2, __int16 a3)
{
  __int16 v3; // bx
  __int16 v4; // si

  v3 = a2; /*0x14466d*/
  v4 = a3; /*0x144671*/
  if ( a2 == -1 ) /*0x144679*/
    v3 = *(_WORD *)(a1 + 104); /*0x14467b*/
  if ( a3 == -1 ) /*0x144683*/
    v4 = *(_WORD *)(a1 + 106); /*0x144685*/
  if ( (*(_WORD *)(*(_DWORD *)(active_u + 28) + 2) != v3 || *(_WORD *)(a1 + 104) != v3 || !groupmember(v4)) && !suser() ) /*0x1446ad*/
    return 1; /*0x1446b6*/
  *(_WORD *)(a1 + 104) = v3; /*0x1446c0*/
  *(_WORD *)(a1 + 106) = v4; /*0x1446c4*/
  *(_BYTE *)(a1 + 68) |= 0x40u; /*0x1446c8*/
  if ( *(_WORD *)(*(_DWORD *)(active_u + 28) + 2) ) /*0x1446d4*/
    *(_WORD *)(a1 + 100) &= 0xF3FFu; /*0x1446db*/
  return 0; /*0x1446e6*/
}
