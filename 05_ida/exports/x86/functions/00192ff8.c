/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x192ff8. */
unsigned __int32 __cdecl byte_swap_cylgroup(int a1)
{
  int v1; // ecx
  unsigned int *v2; // edx
  int v3; // ecx
  unsigned int *v4; // edx
  int v5; // ecx
  unsigned int *v6; // edx
  int v7; // ecx
  _WORD *v8; // edx
  unsigned __int32 result; // eax

  *(_DWORD *)(a1 + 8) = _byteswap_ulong(*(_DWORD *)(a1 + 8)); /*0x193004*/
  *(_DWORD *)(a1 + 12) = _byteswap_ulong(*(_DWORD *)(a1 + 12)); /*0x19300c*/
  *(_WORD *)(a1 + 16) = __ROR2__(*(_WORD *)(a1 + 16), 8); /*0x193017*/
  *(_WORD *)(a1 + 18) = __ROR2__(*(_WORD *)(a1 + 18), 8); /*0x193023*/
  *(_DWORD *)(a1 + 20) = _byteswap_ulong(*(_DWORD *)(a1 + 20)); /*0x19302c*/
  v1 = 0; /*0x19302f*/
  v2 = (unsigned int *)(a1 + 24); /*0x193031*/
  do /*0x193041*/
  {
    *v2 = _byteswap_ulong(*v2); /*0x193038*/
    ++v2; /*0x19303a*/
    ++v1; /*0x19303d*/
  }
  while ( v1 < 4 ); /*0x193041*/
  *(_DWORD *)(a1 + 40) = _byteswap_ulong(*(_DWORD *)(a1 + 40)); /*0x193048*/
  *(_DWORD *)(a1 + 44) = _byteswap_ulong(*(_DWORD *)(a1 + 44)); /*0x193050*/
  *(_DWORD *)(a1 + 48) = _byteswap_ulong(*(_DWORD *)(a1 + 48)); /*0x193058*/
  v3 = 0; /*0x19305b*/
  v4 = (unsigned int *)(a1 + 52); /*0x19305d*/
  do /*0x19306d*/
  {
    *v4 = _byteswap_ulong(*v4); /*0x193064*/
    ++v4; /*0x193066*/
    ++v3; /*0x193069*/
  }
  while ( v3 < 8 ); /*0x19306d*/
  v5 = 0; /*0x19306f*/
  v6 = (unsigned int *)(a1 + 84); /*0x193071*/
  do /*0x193081*/
  {
    *v6 = _byteswap_ulong(*v6); /*0x193078*/
    ++v6; /*0x19307a*/
    ++v5; /*0x19307d*/
  }
  while ( v5 < 32 ); /*0x193081*/
  v7 = 0; /*0x193083*/
  v8 = (_WORD *)(a1 + 212); /*0x193085*/
  do /*0x1930a0*/
  {
    *v8 = __ROR2__(*v8, 8); /*0x193093*/
    ++v8; /*0x193096*/
    ++v7; /*0x193099*/
  }
  while ( v7 < 256 ); /*0x1930a0*/
  result = _byteswap_ulong(*(_DWORD *)(a1 + 980)); /*0x1930a8*/
  *(_DWORD *)(a1 + 980) = result; /*0x1930aa*/
  return result; /*0x1930b0*/
}
