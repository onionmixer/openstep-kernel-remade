
void _vm_info_enqueue(int param_1)

{
  if (dword_40C23D0 == &_vm_info_queue) {
    _vm_info_queue = param_1;
  }
  else {
    dword_40C23D0[9] = param_1;
  }
  *(undefined4 **)(param_1 + 0x28) = dword_40C23D0;
  *(int **)(param_1 + 0x24) = &_vm_info_queue;
  dword_40C23D0 = (undefined4 *)param_1;
  *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) | 0x80;
  _mfs_files_mapped = _mfs_files_mapped + 1;
  _vm_info_version = _vm_info_version + 1;
  return;
}

