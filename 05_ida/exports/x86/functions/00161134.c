/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x161134. */
int pset_sys_bootstrap()
{
  int v0; // esi
  char *v1; // ebx
  int v2; // edi
  int result; // eax

  pset_init(&default_pset); /*0x16113f*/
  dword_1E9738 = 0; /*0x161144*/
  v0 = 0; /*0x16114e*/
  v1 = (char *)&processor_array; /*0x161153*/
  v2 = 0; /*0x161158*/
  do /*0x161178*/
  {
    processor_ptr[v2] = (int)v1; /*0x16115c*/
    processor_init(v1, v0); /*0x161164*/
    v1 += 328; /*0x16116c*/
    ++v2; /*0x161172*/
    ++v0; /*0x161175*/
  }
  while ( v0 <= 0 ); /*0x161178*/
  result = processor_ptr[master_cpu]; /*0x16117f*/
  master_processor = result; /*0x161186*/
  all_psets_lock = 0; /*0x16119f*/
  all_psets = (int)&default_pset; /*0x1611a9*/
  dword_1E9760 = (int)&all_psets; /*0x1611b3*/
  set = (processor_set_t)&all_psets; /*0x1611bd*/
  dword_1E9604 = (int)&default_pset; /*0x1611c7*/
  all_psets_count = 1; /*0x1611d1*/
  dword_1E9764 = 1; /*0x1611db*/
  dword_1E9738 = 0; /*0x1611e5*/
  return result; /*0x1611f2*/
}
