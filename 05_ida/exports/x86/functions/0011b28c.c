/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11b28c. */
int *dnlc_init()
{
  int v0; // ecx
  int v1; // ebx
  int v2; // eax
  int v3; // edx
  int *result; // eax
  int v5; // edx

  dword_1E9BE8 = (int)&nc_lru; /*0x11b290*/
  dword_1E9BEC = (int)&nc_lru; /*0x11b29a*/
  v0 = 0; /*0x11b2a4*/
  if ( ncsize > 0 ) /*0x11b2ac*/
  {
    v1 = 0; /*0x11b2ae*/
    do /*0x11b2f0*/
    {
      v2 = v1 + ncache; /*0x11b2b5*/
      v3 = dword_1E9BE8; /*0x11b2b7*/
      dword_1E9BE8 = v2; /*0x11b2bd*/
      *(_DWORD *)(v2 + 8) = v3; /*0x11b2c2*/
      *(_DWORD *)(v3 + 12) = v2; /*0x11b2c5*/
      *(_DWORD *)(v2 + 12) = &nc_lru; /*0x11b2c8*/
      *(_DWORD *)(v2 + 4) = v2; /*0x11b2cf*/
      *(_DWORD *)v2 = v2; /*0x11b2d2*/
      *(_DWORD *)(v2 + 16) = 0; /*0x11b2d4*/
      *(_DWORD *)(v2 + 20) = 0; /*0x11b2db*/
      *(_BYTE *)(v2 + 68) = 0; /*0x11b2e2*/
      v1 += 72; /*0x11b2e6*/
      ++v0; /*0x11b2e9*/
    }
    while ( ncsize > v0 ); /*0x11b2f0*/
  }
  result = nc_hash; /*0x11b2f2*/
  v5 = 0; /*0x11b2f7*/
  do /*0x11b310*/
  {
    dword_1E99E4[v5] = (int)result; /*0x11b300*/
    *result = (int)result; /*0x11b306*/
    result += 2; /*0x11b308*/
    v5 += 2; /*0x11b30b*/
  }
  while ( (int)result <= (int)&unk_1E9BD8 ); /*0x11b310*/
  return result; /*0x11b312*/
}
