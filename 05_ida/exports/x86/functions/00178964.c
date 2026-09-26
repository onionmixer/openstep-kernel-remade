/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x178964. */
int __cdecl vm_alloc_from_regions(int a1, int a2)
{
  char *v2; // ebx
  void **v3; // ecx
  int result; // eax

  v2 = (char *)&mem_region; /*0x17896d*/
  if ( &mem_region >= (_UNKNOWN *)((char *)&mem_region + 28 * num_regions) ) /*0x178987*/
LABEL_6:
    panic(aVmMemAllocFrom); /*0x1789bb*/
  v3 = &dword_1F6E74; /*0x178991*/
  while ( 1 ) /*0x17899e*/
  {
    result = -a2 & ((unsigned int)*v3 + a2 - 1); /*0x17899e*/
    if ( (unsigned int)v3[1] >= result + a1 ) /*0x1789a8*/
      break; /*0x1789a8*/
    v3 += 7; /*0x1789b0*/
    v2 += 28; /*0x1789b3*/
    if ( (char *)&mem_region + 28 * num_regions <= v2 ) /*0x1789b9*/
      goto LABEL_6; /*0x1789b9*/
  }
  *v3 = (void *)(result + a1); /*0x1789aa*/
  return result; /*0x1789c8*/
}
