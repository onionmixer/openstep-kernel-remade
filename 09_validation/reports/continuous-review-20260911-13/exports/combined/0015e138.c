
void _vm_info_enqueue(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)DAT_001f64d4;
  if (puVar3 == &_vm_info_queue) {
    _vm_info_queue = param_1;
  }
  else {
    puVar3[10] = param_1;
  }
  *(undefined4 **)(param_1 + 0x2c) = puVar3;
  *(undefined4 **)(param_1 + 0x28) = &_vm_info_queue;
  DAT_001f64d4 = param_1;
  *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) | 1;
  uVar1 = _mfs_files_mapped;
  iVar2 = _mfs_files_mapped;
  _mfs_files_mapped = iVar2 + 1;
  uVar1 = _mfs_files_mapped;
  uVar1 = _mfs_files_mapped;
  uVar1 = _mfs_files_mapped;
  uVar1 = _vm_info_version;
  iVar2 = _vm_info_version;
  _vm_info_version = iVar2 + 1;
  uVar1 = _vm_info_version;
  uVar1 = _vm_info_version;
  uVar1 = _vm_info_version;
  return;
}

