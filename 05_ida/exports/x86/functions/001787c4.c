/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1787c4. */
int __cdecl vm_mem_ppi(unsigned int a1)
{
  int v1; // ebx
  _DWORD *v2; // eax
  unsigned int v3; // edx
  char *v5; // [esp+Ch] [ebp-8h]

  v1 = 0; /*0x1787d0*/
  v5 = (char *)&mem_region; /*0x1787d2*/
  if ( &mem_region >= (_UNKNOWN *)((char *)&mem_region + 28 * num_regions) ) /*0x1787ef*/
LABEL_7:
    panic(aMemPpi); /*0x17882e*/
  v2 = &unk_1F6E6C; /*0x1787fc*/
  while ( 1 ) /*0x178804*/
  {
    v3 = v2[2]; /*0x178804*/
    if ( a1 >= v3 && v2[3] > a1 ) /*0x17880e*/
      return v1 + ((a1 - v3) >> page_shift); /*0x17883b*/
    v1 += *v2; /*0x178820*/
    v2 += 7; /*0x178822*/
    v5 += 28; /*0x178825*/
    if ( v5 >= (char *)&mem_region + 28 * num_regions ) /*0x17882c*/
      goto LABEL_7; /*0x17882c*/
  }
}
