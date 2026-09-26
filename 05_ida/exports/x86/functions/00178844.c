/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x178844. */
int __cdecl vm_valid_page(unsigned int a1)
{
  char *v1; // ecx
  int *i; // eax

  v1 = (char *)&mem_region; /*0x17884b*/
  if ( &mem_region >= (_UNKNOWN *)((char *)&mem_region + 28 * num_regions) ) /*0x178865*/
    return 0; /*0x17888a*/
  for ( i = &dword_1F6E78; *(i - 1) > a1 || *i <= a1; i += 7 ) /*0x178869*/
  {
    v1 += 28; /*0x178883*/
    if ( v1 >= (char *)&mem_region + 28 * num_regions ) /*0x178888*/
      return 0; /*0x178888*/
  }
  return 1; /*0x17888c*/
}
