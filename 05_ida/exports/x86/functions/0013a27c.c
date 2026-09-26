/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13a27c. */
int __cdecl spec_setattr(int a1, _DWORD *a2, int a3)
{
  int v3; // ebx
  _DWORD *v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // ecx
  _DWORD v9[2]; // [esp+Ch] [ebp-8h] BYREF

  v3 = 0; /*0x13a288*/
  v4 = *(_DWORD **)(a1 + 48); /*0x13a28a*/
  v5 = v4[14]; /*0x13a28d*/
  if ( v5 ) /*0x13a292*/
  {
    a2[6] = -1; /*0x13a29b*/
    v6 = (*(int (__cdecl **)(int, _DWORD *, int))(*(_DWORD *)(v5 + 28) + 24))(v5, a2, a3); /*0x13a2b3*/
    if ( v6 ) /*0x13a2ba*/
      return v6; /*0x13a2ba*/
  }
  else
  {
    v6 = 0; /*0x13a294*/
  }
  if ( a2[10] != -1 ) /*0x13a2c3*/
  {
    v4[21] = a2[10]; /*0x13a2c8*/
    v4[22] = a2[11]; /*0x13a2ce*/
    v3 = 1; /*0x13a2d1*/
  }
  if ( a2[8] != -1 ) /*0x13a2d9*/
  {
    v4[19] = a2[8]; /*0x13a2de*/
    v4[20] = a2[9]; /*0x13a2e4*/
    ++v3; /*0x13a2e7*/
  }
  if ( v3 ) /*0x13a2ea*/
  {
    getthetime(v9); /*0x13a2f0*/
    v7 = v9[1]; /*0x13a2f8*/
    v4[23] = v9[0]; /*0x13a2fb*/
    v4[24] = v7; /*0x13a2fe*/
  }
  return v6; /*0x13a306*/
}
