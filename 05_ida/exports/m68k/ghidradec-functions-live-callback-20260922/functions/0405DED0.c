
void _vm_map_deallocate(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x2c);
    *(int *)(param_1 + 0x2c) = iVar1 + -1;
    if (iVar1 == 1 || iVar1 + -1 < 0) {
      _lock_write(param_1);
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
      _vm_map_delete(param_1,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
      _pmap_destroy(*(undefined4 *)(param_1 + 0x20));
      _zfree(_vm_map_zone,param_1);
    }
  }
  return;
}

