
void _mfs_cache_clear(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar1 = _vm_info_version;
  puVar2 = _vm_info_queue;
  while (puVar4 = puVar2, iVar3 = iVar1, (undefined4 **)puVar4 != &_vm_info_queue) {
    if (*(sword *)(puVar4 + 1) == 0) {
      _mfs_memfree(puVar4,1);
    }
    iVar1 = _vm_info_version;
    puVar2 = _vm_info_queue;
    if (_vm_info_version == iVar3) {
      iVar1 = iVar3;
      puVar2 = (undefined4 *)puVar4[9];
    }
  }
  return;
}
