/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12f384. */
__int16 __cdecl vattr_to_sattr(int a1, _DWORD *a2)
{
  __int16 v2; // ax
  __int16 result; // ax

  if ( *(_WORD *)(a1 + 4) == 0xFFFF ) /*0x12f396*/
    *a2 = -1; /*0x12f398*/
  else
    *a2 = *(unsigned __int16 *)(a1 + 4); /*0x12f3a5*/
  v2 = *(_WORD *)(a1 + 6); /*0x12f3a7*/
  if ( v2 == -1 ) /*0x12f3af*/
    a2[1] = -1; /*0x12f3b1*/
  else
    a2[1] = v2; /*0x12f3bd*/
  result = *(_WORD *)(a1 + 8); /*0x12f3c0*/
  if ( result == -1 ) /*0x12f3c8*/
    a2[2] = -1; /*0x12f3ca*/
  else
    a2[2] = result; /*0x12f3d5*/
  a2[3] = *(_DWORD *)(a1 + 24); /*0x12f3db*/
  a2[4] = *(_DWORD *)(a1 + 32); /*0x12f3e1*/
  a2[5] = *(_DWORD *)(a1 + 36); /*0x12f3e7*/
  a2[6] = *(_DWORD *)(a1 + 40); /*0x12f3ed*/
  a2[7] = *(_DWORD *)(a1 + 44); /*0x12f3f3*/
  return result; /*0x12f3f6*/
}
