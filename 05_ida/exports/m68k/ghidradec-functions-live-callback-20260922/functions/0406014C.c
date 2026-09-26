
void _vm_object_cache_clear(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if ((undefined4 **)_vm_object_cached_list != &_vm_object_cached_list) {
    do {
      puVar1 = _vm_object_cached_list;
      puVar2 = (undefined4 *)_vm_object_lookup(_vm_object_cached_list[9]);
      if (puVar2 != puVar1) {
                    /* WARNING: Subroutine does not return */
        _panic(aVmObjectCacheC);
      }
      _vm_object_cache_object(puVar1,0);
    } while ((undefined4 **)_vm_object_cached_list != &_vm_object_cached_list);
  }
  return;
}

