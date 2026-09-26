
void _vm_info_dequeue(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0x24);
  puVar2 = *(undefined4 **)(param_1 + 0x28);
  puVar3 = puVar2;
  if ((undefined4 **)puVar1 != &_vm_info_queue) {
    puVar1[10] = puVar2;
    puVar3 = dword_40C23D0;
  }
  dword_40C23D0 = puVar3;
  if ((undefined4 **)puVar2 != &_vm_info_queue) {
    puVar2[9] = puVar1;
    puVar1 = _vm_info_queue;
  }
  _vm_info_queue = puVar1;
  *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) & 0x7f;
  _mfs_files_mapped = _mfs_files_mapped + -1;
  _vm_info_version = _vm_info_version + 1;
  return;
}

