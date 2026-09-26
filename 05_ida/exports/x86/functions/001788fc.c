/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1788fc. */
int __cdecl vm_region_to_vm_page(unsigned int a1)
{
  _DWORD *v1; // edi
  _DWORD *i; // edx

  v1 = &mem_region; /*0x178905*/
  if ( &mem_region >= (_UNKNOWN *)((char *)&mem_region + 28 * num_regions) ) /*0x17891f*/
    return 0; /*0x178956*/
  for ( i = &unk_1F6E64; i[4] > a1 || i[5] <= a1; i += 7 ) /*0x17892e*/
  {
    v1 += 7; /*0x17894f*/
    if ( v1 >= (_DWORD *)&mem_region + 7 * num_regions ) /*0x178954*/
      return 0; /*0x178954*/
  }
  return *v1 + 48 * ((a1 >> page_shift) - *i); /*0x17895b*/
}
