
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _vm_object_init(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  _vm_object_zone = _zinit(0x52,~_page_mask & _page_mask + 0x80000,0,0,&aObjects);
  _object_hash_zone = _zinit(0xc,0x19000,0,0,aObjectHashZone);
  dword_40C2DA4 = &_vm_object_cached_list;
  _vm_object_cached_list = &_vm_object_cached_list;
  dword_40C31B0 = &_vm_object_list;
  _vm_object_list = &_vm_object_list;
  _vm_object_count = 0;
  iVar1 = 0;
  puVar2 = &_vm_object_hashtable;
  do {
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    puVar2 = puVar2 + 2;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x80);
  _vm_cache_max = (_mem_size >> 0x14) * 0x32;
  if (0x9c4 < _vm_cache_max) {
    _vm_cache_max = 0x9c4;
  }
  word_40C31CC = 1;
  word_40C31CE = 0;
  dword_40C31C8 = 0;
  word_40C31F8 = 0;
  dword_40C31D0 = 0;
  dword_40C31DC = 0;
  dword_40C31E4 = 0;
  dword_40C31E8 = 0;
  _unk_40C31FC = (word)(byte_40C31FD & 0xf7);
  unk_40C31FA = unk_40C31FA & 0xcf | 8;
  dword_40C31E0 = 0;
  dword_40C31D4 = 0;
  dword_40C31D8 = 0;
  dword_40C3206 = 0;
  byte_40C31FB = byte_40C31FB & 0xf0;
  _unk_40C31FC = _unk_40C31FC & 0x2f | 0x20;
  _kernel_object = _kernel_object_store;
  __vm_object_allocate(0x4000000,_kernel_object_store);
  _vm_submap_object = _vm_submap_object_store;
  __vm_object_allocate(0x4000000,_vm_submap_object_store);
  return;
}
