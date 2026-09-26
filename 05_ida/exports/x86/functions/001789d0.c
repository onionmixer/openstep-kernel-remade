/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1789d0. */
int vm_object_init()
{
  int *v0; // eax
  int v1; // edx

  vm_object_zone = zinit(88, ~page_mask & (page_mask + 0x80000), 0, 0, (int)aObjects); /*0x1789f4*/
  object_hash_zone = zinit(12, 102400, 0, 0, (int)aObjectHashZone); /*0x178a0e*/
  dword_1F6F3C = (int)&vm_object_cached_list; /*0x178a13*/
  vm_object_cached_list = (int)&vm_object_cached_list; /*0x178a1d*/
  dword_1F7354 = (int)&vm_object_list; /*0x178a27*/
  vm_object_list = (int)&vm_object_list; /*0x178a31*/
  vm_object_count = 0; /*0x178a3b*/
  vm_cache_lock = 0; /*0x178a48*/
  vm_object_list_lock = 0; /*0x178a52*/
  v0 = vm_object_hashtable; /*0x178a5c*/
  v1 = 0; /*0x178a61*/
  do /*0x178a78*/
  {
    dword_1F6F54[v1] = (int)v0; /*0x178a68*/
    *v0 = (int)v0; /*0x178a6e*/
    v0 += 2; /*0x178a70*/
    v1 += 2; /*0x178a73*/
  }
  while ( (int)v0 <= (int)&unk_1F7348 ); /*0x178a78*/
  vm_cache_max = 50 * ((unsigned int)mem_size >> 20); /*0x178a8a*/
  if ( vm_cache_max > 2500 ) /*0x178a94*/
    vm_cache_max = 2500; /*0x178a96*/
  word_1F7378 = 1; /*0x178aa0*/
  word_1F737A = 0; /*0x178aa9*/
  dword_1F7374 = 0; /*0x178ab2*/
  word_1F73A4 = 0; /*0x178acd*/
  dword_1F737C = 0; /*0x178ad6*/
  dword_1F7388 = 0; /*0x178ae0*/
  dword_1F7390 = 0; /*0x178aea*/
  dword_1F7394 = 0; /*0x178af4*/
  byte_1F73AA &= ~1u; /*0x178b06*/
  byte_1F73A6 = byte_1F73A6 & 0xE3 | 0x10; /*0x178b0f*/
  dword_1F738C = 0; /*0x178b15*/
  dword_1F7380 = 0; /*0x178b1f*/
  dword_1F7384 = 0; /*0x178b29*/
  dword_1F73B4 = 0; /*0x178b33*/
  word_1F73A8 = 2; /*0x178b3d*/
  kernel_object = (int)&kernel_object_store; /*0x178b46*/
  _vm_object_allocate(0x40000000, &kernel_object_store); /*0x178b5a*/
  vm_submap_object = (int)&vm_submap_object_store; /*0x178b5f*/
  return _vm_object_allocate(0x40000000, &vm_submap_object_store); /*0x178b78*/
}
