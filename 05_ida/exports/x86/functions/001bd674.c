/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bd674. */
__int16 __cdecl get_disk_label(int a1, int a2)
{
  unsigned int *v2; // ebx
  int v3; // ecx
  _DWORD *v4; // edx
  __int16 result; // ax

  *(_DWORD *)a2 = _byteswap_ulong(*(_DWORD *)a1); /*0x1bd684*/
  *(_DWORD *)(a2 + 4) = _byteswap_ulong(*(_DWORD *)(a1 + 4)); /*0x1bd68b*/
  *(_DWORD *)(a2 + 8) = _byteswap_ulong(*(_DWORD *)(a1 + 8)); /*0x1bd693*/
  bcopy((const void *)(a1 + 12), (void *)(a2 + 12), 0x18u); /*0x1bd6a0*/
  *(_DWORD *)(a2 + 36) = _byteswap_ulong(*(_DWORD *)(a1 + 36)); /*0x1bd6ad*/
  *(_DWORD *)(a2 + 40) = _byteswap_ulong(*(_DWORD *)(a1 + 40)); /*0x1bd6b5*/
  get_disktab((unsigned int *)(a1 + 44), (char *)(a2 + 44)); /*0x1bd6c0*/
  v2 = (unsigned int *)(a1 + 558); /*0x1bd6c5*/
  v3 = 0; /*0x1bd6cb*/
  v4 = (_DWORD *)(a2 + 576); /*0x1bd6cd*/
  do /*0x1bd6e7*/
  {
    *v4++ = _byteswap_ulong(*v2++); /*0x1bd6d8*/
    ++v3; /*0x1bd6e0*/
  }
  while ( v3 <= 1669 ); /*0x1bd6e7*/
  *(_WORD *)(a2 + 7256) = __ROR2__(*(_WORD *)(a1 + 7238), 8); /*0x1bd6f4*/
  result = __ROR2__(*(_WORD *)(a1 + 558), 8); /*0x1bd702*/
  *(_WORD *)(a2 + 576) = result; /*0x1bd706*/
  return result; /*0x1bd710*/
}
