/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cd284. */
id __cdecl sub_1CD284(id a1)
{
  int *v1; // eax
  _BYTE *v2; // edx
  int v3; // edx
  _BYTE *v4; // eax
  _DWORD *v5; // edx
  _DWORD *v6; // eax
  int v7; // eax

  v1 = *((int **)a1 + 1); /*0x1cd28b*/
  v2 = a1; /*0x1cd28e*/
  if ( (*((_BYTE *)a1 + 16) & 2) == 0 ) /*0x1cd294*/
    v2 = *(_BYTE **)a1; /*0x1cd296*/
  if ( (v2[16] & 4) == 0 ) /*0x1cd29c*/
  {
    if ( v1 ) /*0x1cd2a0*/
    {
      v3 = *((_DWORD *)a1 + 1); /*0x1cd2a2*/
      if ( (v1[4] & 2) == 0 ) /*0x1cd2a8*/
        v3 = *v1; /*0x1cd2aa*/
      if ( (*(_BYTE *)(v3 + 16) & 4) == 0 ) /*0x1cd2b0*/
        sub_1CD284(*((id *)a1 + 1)); /*0x1cd2b3*/
    }
    v4 = a1; /*0x1cd2bb*/
    if ( (*((_BYTE *)a1 + 16) & 2) == 0 ) /*0x1cd2c1*/
      v4 = *(_BYTE **)a1; /*0x1cd2c3*/
    if ( (v4[16] & 4) == 0 ) /*0x1cd2c9*/
    {
      v5 = a1; /*0x1cd2cb*/
      if ( (*((_BYTE *)a1 + 16) & 2) == 0 ) /*0x1cd2d1*/
        v5 = *(_DWORD **)a1; /*0x1cd2d3*/
      v6 = a1; /*0x1cd2d5*/
      if ( (*((_BYTE *)a1 + 16) & 2) == 0 ) /*0x1cd2db*/
        v6 = *(_DWORD **)a1; /*0x1cd2dd*/
      v7 = v6[4]; /*0x1cd2df*/
      LOBYTE(v7) = v7 | 4; /*0x1cd2e2*/
      v5[4] = v7; /*0x1cd2e4*/
      objc_msgSend(a1, sel_initialize); /*0x1cd2ef*/
    }
  }
  return a1; /*0x1cd2f6*/
}
