/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1930b8. */
unsigned __int32 __cdecl byte_swap_inode_in(int a1, int a2)
{
  int v2; // esi
  unsigned __int32 v3; // eax
  int i; // edx
  int j; // edx
  unsigned int k; // edx
  unsigned __int32 result; // eax

  v2 = a2 + 100; /*0x1930c3*/
  *(_WORD *)(a2 + 100) = __ROR2__(*(_WORD *)a1, 8); /*0x1930cd*/
  *(_WORD *)(a2 + 102) = __ROR2__(*(_WORD *)(a1 + 2), 8); /*0x1930d9*/
  *(_WORD *)(a2 + 104) = __ROR2__(*(_WORD *)(a1 + 4), 8); /*0x1930e5*/
  *(_WORD *)(a2 + 106) = __ROR2__(*(_WORD *)(a1 + 6), 8); /*0x1930f1*/
  *(_DWORD *)(a2 + 108) = _byteswap_ulong(*(_DWORD *)(a1 + 12)); /*0x1930fa*/
  *(_DWORD *)(a2 + 112) = _byteswap_ulong(*(_DWORD *)(a1 + 8)); /*0x193102*/
  *(_DWORD *)(a2 + 116) = _byteswap_ulong(*(_DWORD *)(a1 + 16)); /*0x19310a*/
  *(_DWORD *)(a2 + 124) = _byteswap_ulong(*(_DWORD *)(a1 + 24)); /*0x193112*/
  *(_DWORD *)(a2 + 132) = _byteswap_ulong(*(_DWORD *)(a1 + 32)); /*0x19311a*/
  *(_DWORD *)(a2 + 120) = _byteswap_ulong(*(_DWORD *)(a1 + 20)); /*0x193125*/
  *(_DWORD *)(a2 + 128) = _byteswap_ulong(*(_DWORD *)(a1 + 28)); /*0x19312d*/
  *(_DWORD *)(a2 + 136) = _byteswap_ulong(*(_DWORD *)(a1 + 36)); /*0x193138*/
  v3 = _byteswap_ulong(*(_DWORD *)(a1 + 100)); /*0x193141*/
  *(_DWORD *)(a2 + 200) = v3; /*0x193143*/
  if ( (v3 & 1) != 0 ) /*0x19314b*/
  {
    bcopy((const void *)(a1 + 40), (void *)(a2 + 140), 0x3Cu); /*0x193185*/
  }
  else
  {
    for ( i = 0; i <= 11; ++i ) /*0x19314d*/
      *(_DWORD *)(v2 + 4 * i + 40) = _byteswap_ulong(*(_DWORD *)(a1 + 4 * i + 40)); /*0x193156*/
    for ( j = 0; j <= 2; ++j ) /*0x193160*/
      *(_DWORD *)(v2 + 4 * j + 88) = _byteswap_ulong(*(_DWORD *)(a1 + 4 * j + 88)); /*0x19316a*/
  }
  *(_DWORD *)(a2 + 204) = _byteswap_ulong(*(_DWORD *)(a1 + 104)); /*0x19318f*/
  *(_DWORD *)(a2 + 208) = _byteswap_ulong(*(_DWORD *)(a1 + 108)); /*0x193197*/
  for ( k = 0; k <= 3; ++k ) /*0x19319a*/
  {
    result = _byteswap_ulong(*(_DWORD *)(a1 + 4 * k + 112)); /*0x1931a0*/
    *(_DWORD *)(v2 + 4 * k + 112) = result; /*0x1931a2*/
  }
  return result; /*0x1931af*/
}
