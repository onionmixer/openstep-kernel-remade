
void _mfs_memfree(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x34) < '\0') {
    _vm_info_dequeue(param_1);
  }
  _lock_write(param_1 + 0x18);
  if (*(sword *)(param_1 + 4) == 0) {
    *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) & 0xf7;
  }
  _mfs_map_remove(param_1,*(int *)(param_1 + 8),*(int *)(param_1 + 0xc) + *(int *)(param_1 + 8),
                  param_2);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  iVar1 = 0;
  if (*(sword *)(param_1 + 4) == 0) {
    iVar1 = *(int *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x20) = 0;
    if (*(int *)(param_1 + 0x2c) != 0) {
      _crfree(*(int *)(param_1 + 0x2c));
      *(undefined4 *)(param_1 + 0x2c) = 0;
    }
  }
  _lock_done(param_1 + 0x18);
  if (iVar1 != 0) {
    _vm_object_deallocate(iVar1);
  }
  return;
}
