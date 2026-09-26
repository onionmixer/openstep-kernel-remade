/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1bd9a4. */
__int16 __cdecl put_disk_label(int a1, int a2)
{
  _DWORD *v2; // ebx
  int v3; // ecx
  unsigned int *v4; // edx
  __int16 result; // ax

  *(_DWORD *)a2 = _byteswap_ulong(*(_DWORD *)a1); /*0x1bd9b4*/
  *(_DWORD *)(a2 + 4) = _byteswap_ulong(*(_DWORD *)(a1 + 4)); /*0x1bd9bb*/
  *(_DWORD *)(a2 + 8) = _byteswap_ulong(*(_DWORD *)(a1 + 8)); /*0x1bd9c3*/
  bcopy((const void *)(a1 + 12), (void *)(a2 + 12), 0x18u); /*0x1bd9d0*/
  *(_DWORD *)(a2 + 36) = _byteswap_ulong(*(_DWORD *)(a1 + 36)); /*0x1bd9dd*/
  *(_DWORD *)(a2 + 40) = _byteswap_ulong(*(_DWORD *)(a1 + 40)); /*0x1bd9e5*/
  put_disktab((unsigned int *)(a1 + 44), (char *)(a2 + 44)); /*0x1bd9f0*/
  v2 = (_DWORD *)(a2 + 558); /*0x1bd9f5*/
  v3 = 0; /*0x1bd9fb*/
  v4 = (unsigned int *)(a1 + 576); /*0x1bd9fd*/
  do /*0x1bda17*/
  {
    *v2++ = _byteswap_ulong(*v4++); /*0x1bda08*/
    ++v3; /*0x1bda10*/
  }
  while ( v3 <= 1669 ); /*0x1bda17*/
  *(_WORD *)(a2 + 7238) = __ROR2__(*(_WORD *)(a1 + 7256), 8); /*0x1bda24*/
  result = __ROR2__(*(_WORD *)(a1 + 576), 8); /*0x1bda32*/
  *(_WORD *)(a2 + 558) = result; /*0x1bda36*/
  return result; /*0x1bda40*/
}
