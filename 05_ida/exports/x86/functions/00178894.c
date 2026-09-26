/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x178894. */
int __cdecl vm_phys_to_vm_page(unsigned int a1)
{
  _DWORD *v1; // edi
  _DWORD *i; // edx

  v1 = &mem_region; /*0x17889d*/
  if ( &mem_region >= (_UNKNOWN *)((char *)&mem_region + 28 * num_regions) ) /*0x1788b7*/
    return 0; /*0x1788ee*/
  for ( i = &unk_1F6E64; i[4] > a1 || i[5] <= a1; i += 7 ) /*0x1788c6*/
  {
    v1 += 7; /*0x1788e7*/
    if ( v1 >= (_DWORD *)&mem_region + 7 * num_regions ) /*0x1788ec*/
      return 0; /*0x1788ec*/
  }
  return *v1 + 48 * ((a1 >> page_shift) - *i); /*0x1788f3*/
}
