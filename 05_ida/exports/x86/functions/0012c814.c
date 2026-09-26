/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12c814. */
__int16 __cdecl vattr_to_nattr(int a1, _DWORD *a2)
{
  int v2; // eax
  __int16 v3; // cx
  __int16 v4; // cx

  LOWORD(v2) = a1; /*0x12c818*/
  *a2 = *(_DWORD *)a1; /*0x12c820*/
  if ( *(_WORD *)(a1 + 4) == 0xFFFF ) /*0x12c82b*/
    a2[1] = -1; /*0x12c82d*/
  else
    a2[1] = *(unsigned __int16 *)(a1 + 4); /*0x12c83e*/
  v3 = *(_WORD *)(a1 + 6); /*0x12c841*/
  if ( v3 == -1 ) /*0x12c849*/
    a2[3] = -1; /*0x12c84b*/
  else
    a2[3] = v3; /*0x12c857*/
  v4 = *(_WORD *)(a1 + 8); /*0x12c85a*/
  if ( v4 == -1 ) /*0x12c862*/
    a2[4] = -1; /*0x12c864*/
  else
    a2[4] = v4; /*0x12c873*/
  a2[9] = *(_DWORD *)(a1 + 12); /*0x12c879*/
  a2[10] = *(_DWORD *)(a1 + 16); /*0x12c87f*/
  a2[2] = *(__int16 *)(a1 + 20); /*0x12c886*/
  a2[5] = *(_DWORD *)(a1 + 24); /*0x12c88c*/
  a2[11] = *(_DWORD *)(a1 + 32); /*0x12c892*/
  a2[12] = *(_DWORD *)(a1 + 36); /*0x12c898*/
  a2[13] = *(_DWORD *)(a1 + 40); /*0x12c89e*/
  a2[14] = *(_DWORD *)(a1 + 44); /*0x12c8a4*/
  a2[15] = *(_DWORD *)(a1 + 48); /*0x12c8aa*/
  a2[16] = *(_DWORD *)(a1 + 52); /*0x12c8b0*/
  a2[7] = *(__int16 *)(a1 + 56); /*0x12c8b7*/
  a2[8] = *(_DWORD *)(a1 + 60); /*0x12c8bd*/
  a2[6] = *(_DWORD *)(a1 + 28); /*0x12c8c3*/
  if ( *(_DWORD *)a1 == 8 ) /*0x12c8c9*/
  {
    *a2 = 4; /*0x12c8cb*/
    a2[7] = -1; /*0x12c8d1*/
    v2 = a2[1]; /*0x12c8d8*/
    BYTE1(v2) = BYTE1(v2) & 0xF | 0x20; /*0x12c8de*/
    a2[1] = v2; /*0x12c8e1*/
  }
  return v2; /*0x12c8e4*/
}
