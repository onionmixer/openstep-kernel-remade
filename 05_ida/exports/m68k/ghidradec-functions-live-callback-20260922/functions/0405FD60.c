
void _vm_object_cache_trim(void)

{
  int iVar1;
  int iVar2;
  
  while( true ) {
    iVar1 = _vm_object_cached_list;
    if (_vm_object_cached <= _vm_cache_max) {
      return;
    }
    iVar2 = _vm_object_lookup(*(undefined4 *)(_vm_object_cached_list + 0x24));
    if (iVar2 != iVar1) break;
    _vm_object_cache_object(iVar1,0);
  }
                    /* WARNING: Subroutine does not return */
  _panic(aVmObjectDeacti);
}

