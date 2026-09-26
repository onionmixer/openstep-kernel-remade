
void _vm_object_deallocate(int param_1)

{
  int iVar1;
  sword sVar2;
  
  while( true ) {
    if (param_1 == 0) {
      return;
    }
    sVar2 = *(sword *)(param_1 + 0x14);
    *(sword *)(param_1 + 0x14) = sVar2 + -1;
    if (sVar2 != 1) break;
    if ((*(byte *)(param_1 + 0x42) & 0x10) != 0) {
      if (0 < *(sword *)(param_1 + 0x16)) {
        iVar1 = param_1;
        if (dword_40C2DA4 != &_vm_object_cached_list) {
          *(int *)((int)dword_40C2DA4 + 0x46) = param_1;
          iVar1 = _vm_object_cached_list;
        }
        _vm_object_cached_list = iVar1;
        *(undefined4 **)(param_1 + 0x4a) = dword_40C2DA4;
        *(int **)(param_1 + 0x46) = &_vm_object_cached_list;
        _vm_object_cached = _vm_object_cached + 1;
        dword_40C2DA4 = (undefined4 *)param_1;
        _vm_object_deactivate_pages(param_1);
        _vm_object_cache_trim();
        return;
      }
      *(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) & 0xef;
    }
    _vm_object_remove(*(undefined4 *)(param_1 + 0x24));
    iVar1 = *(int *)(param_1 + 0x1c);
    _vm_object_terminate(param_1);
    param_1 = iVar1;
  }
  return;
}
