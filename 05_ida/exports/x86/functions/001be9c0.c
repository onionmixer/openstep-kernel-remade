/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1be9c0. */
void audio_makeIMuLawTab()
{
  int v0; // ecx
  _WORD *v1; // eax
  int v2; // edx
  int v3; // ecx
  int v4; // ebx
  int v5; // esi
  _BYTE v6[1024]; // [esp+Ch] [ebp-800h] BYREF
  _DWORD __base[256]; // [esp+40Ch] [ebp-400h] BYREF

  if ( !dword_1E53CC ) /*0x1be9d3*/
  {
    dword_1E53CC = IOMalloc(0x4000u); /*0x1be9e3*/
    v0 = 0; /*0x1be9e8*/
    v1 = v6; /*0x1be9ed*/
    v2 = 0; /*0x1be9f5*/
    do /*0x1bea20*/
    {
      __base[v0] = v1; /*0x1be9f8*/
      *v1 = v0; /*0x1be9ff*/
      *(_WORD *)&v6[v2 + 2] = audio_muLaw[v0] >> 2; /*0x1bea0e*/
      v1 += 2; /*0x1bea13*/
      v2 += 4; /*0x1bea16*/
      ++v0; /*0x1bea19*/
    }
    while ( v0 <= 255 ); /*0x1bea20*/
    qsort(__base, 0x100u, 4u, _compar); /*0x1bea35*/
    v3 = 0; /*0x1bea3a*/
    v4 = 0; /*0x1bea3c*/
    v5 = -8192; /*0x1bea3e*/
    do /*0x1bea8b*/
    {
      if ( v4 <= 254 /*0x1bea6e*/
        && v5 - *(__int16 *)(__base[v4] + 2) > 0
        && v5 - *(__int16 *)(__base[v4] + 2) > *(__int16 *)(__base[v4 + 1] + 2) - v5 )
      {
        ++v4; /*0x1bea70*/
      }
      *(_BYTE *)(v3 + dword_1E53CC) = *(_BYTE *)__base[v4]; /*0x1bea80*/
      ++v3; /*0x1bea83*/
      ++v5; /*0x1bea84*/
    }
    while ( v3 <= 0x3FFF ); /*0x1bea8b*/
  }
}
