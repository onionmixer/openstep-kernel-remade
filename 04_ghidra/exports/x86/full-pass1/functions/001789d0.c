/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001789d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _vm_object_init(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  _vm_object_zone = _zinit(0x58,_page_mask + 0x80000 & ~_page_mask,0,0,s_objects_001e0b40);
  _object_hash_zone = _zinit(0xc,0x19000,0,0,s_object_hash_zone_001e0b48);
  DAT_001f6f3c = &_vm_object_cached_list;
  _vm_object_cached_list = &_vm_object_cached_list;
  DAT_001f7354 = &_vm_object_list;
  __vm_object_list = &_vm_object_list;
  __vm_object_count = 0;
  _vm_cache_lock = 0;
  _vm_object_list_lock = 0;
  puVar1 = &_vm_object_hashtable;
  iVar2 = 0;
  do {
    *(undefined4 **)((int)&DAT_001f6f54 + iVar2) = puVar1;
    *puVar1 = puVar1;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + 8;
  } while ((int)puVar1 < 0x1f7349);
  _vm_cache_max = (_mem_size >> 0x14) * 0x32;
  if (0x9c4 < _vm_cache_max) {
    _vm_cache_max = 0x9c4;
  }
  _DAT_001f7378 = 1;
  _DAT_001f737a = 0;
  _DAT_001f7374 = 0;
  _DAT_001f73a4 = 0;
  _DAT_001f737c = 0;
  _DAT_001f7388 = 0;
  _DAT_001f7390 = 0;
  _DAT_001f7394 = 0;
  DAT_001f73aa = DAT_001f73aa & 0xfe;
  DAT_001f73a6 = DAT_001f73a6 & 0xf3 | 0x10;
  _DAT_001f738c = 0;
  _DAT_001f7380 = 0;
  _DAT_001f7384 = 0;
  _DAT_001f73b4 = 0;
  _DAT_001f73a8 = 2;
  _kernel_object = &_kernel_object_store;
  __vm_object_allocate(0x40000000,&_kernel_object_store);
  _vm_submap_object = &_vm_submap_object_store;
  __vm_object_allocate(0x40000000,&_vm_submap_object_store);
  return;
}

