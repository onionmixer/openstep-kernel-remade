/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1931b8. */
unsigned __int32 __cdecl byte_swap_inode_out(int a1, int a2)
{
  int v2; // esi
  int i; // edx
  int j; // edx
  unsigned int k; // edx
  unsigned __int32 result; // eax

  v2 = a1 + 100; /*0x1931c3*/
  *(_WORD *)a2 = __ROR2__(*(_WORD *)(a1 + 100), 8); /*0x1931ce*/
  *(_WORD *)(a2 + 2) = __ROR2__(*(_WORD *)(a1 + 102), 8); /*0x1931d9*/
  *(_WORD *)(a2 + 4) = __ROR2__(*(_WORD *)(a1 + 104), 8); /*0x1931e5*/
  *(_WORD *)(a2 + 6) = __ROR2__(*(_WORD *)(a1 + 106), 8); /*0x1931f1*/
  *(_DWORD *)(a2 + 8) = _byteswap_ulong(*(_DWORD *)(a1 + 112)); /*0x1931fa*/
  *(_DWORD *)(a2 + 12) = _byteswap_ulong(*(_DWORD *)(a1 + 108)); /*0x193202*/
  *(_DWORD *)(a2 + 16) = _byteswap_ulong(*(_DWORD *)(a1 + 116)); /*0x19320a*/
  *(_DWORD *)(a2 + 24) = _byteswap_ulong(*(_DWORD *)(a1 + 124)); /*0x193212*/
  *(_DWORD *)(a2 + 32) = _byteswap_ulong(*(_DWORD *)(a1 + 132)); /*0x19321d*/
  *(_DWORD *)(a2 + 20) = _byteswap_ulong(*(_DWORD *)(a1 + 120)); /*0x193225*/
  *(_DWORD *)(a2 + 28) = _byteswap_ulong(*(_DWORD *)(a1 + 128)); /*0x193230*/
  *(_DWORD *)(a2 + 36) = _byteswap_ulong(*(_DWORD *)(a1 + 136)); /*0x19323b*/
  *(_DWORD *)(a2 + 100) = _byteswap_ulong(*(_DWORD *)(a1 + 200)); /*0x193246*/
  if ( (*(_BYTE *)(a1 + 200) & 1) != 0 ) /*0x193250*/
  {
    bcopy((const void *)(a1 + 140), (void *)(a2 + 40), 0x3Cu); /*0x193289*/
  }
  else
  {
    for ( i = 0; i <= 11; ++i ) /*0x193252*/
      *(_DWORD *)(a2 + 4 * i + 40) = _byteswap_ulong(*(_DWORD *)(v2 + 4 * i + 40)); /*0x19325a*/
    for ( j = 0; j <= 2; ++j ) /*0x193264*/
      *(_DWORD *)(a2 + 4 * j + 88) = _byteswap_ulong(*(_DWORD *)(v2 + 4 * j + 88)); /*0x19326e*/
  }
  *(_DWORD *)(a2 + 104) = _byteswap_ulong(*(_DWORD *)(a1 + 204)); /*0x193293*/
  *(_DWORD *)(a2 + 108) = _byteswap_ulong(*(_DWORD *)(a1 + 208)); /*0x19329b*/
  for ( k = 0; k <= 3; ++k ) /*0x19329e*/
  {
    result = _byteswap_ulong(*(_DWORD *)(v2 + 4 * k + 112)); /*0x1932a4*/
    *(_DWORD *)(a2 + 4 * k + 112) = result; /*0x1932a6*/
  }
  return result; /*0x1932b3*/
}
