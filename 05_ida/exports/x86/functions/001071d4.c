/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1071d4. */
int __cdecl munmap(void *a1, size_t a2)
{
  vm_address_t *v2; // eax
  vm_address_t v3; // ecx
  vm_size_t v4; // edx
  int result; // eax

  v2 = *(vm_address_t **)(dword_1E875C + 36); /*0x1071de*/
  v3 = *v2; /*0x1071e1*/
  v4 = v2[1]; /*0x1071e3*/
  result = page_mask; /*0x1071e6*/
  if ( (v3 & page_mask) != 0 || (v4 & page_mask) != 0 ) /*0x1071f1*/
  {
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x1071f3*/
  }
  else
  {
    result = vm_deallocate(*(_DWORD *)(*(_DWORD *)(active_threads + 12) + 12), v3, v4); /*0x10720a*/
    if ( result ) /*0x107211*/
    {
      result = dword_1E875C; /*0x107213*/
      *(_BYTE *)(dword_1E875C + 104) = 22; /*0x107218*/
    }
  }
  return result; /*0x10721c*/
}
