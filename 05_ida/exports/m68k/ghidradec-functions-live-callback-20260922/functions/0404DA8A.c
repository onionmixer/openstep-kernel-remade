
void _mfs_sync(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = _vm_info_version;
  puVar4 = _vm_info_queue;
  while ((undefined4 **)puVar4 != &_vm_info_queue) {
    puVar1 = (undefined4 *)puVar4[9];
    iVar3 = iVar2;
    if ((*(byte *)(puVar4 + 0xd) & 0x40) != 0) {
      _vmp_get(puVar4);
      _vmp_push(puVar4);
      _vmp_put(puVar4);
      iVar3 = iVar2 + 2;
    }
    iVar2 = _vm_info_version;
    puVar4 = _vm_info_queue;
    if (_vm_info_version == iVar3) {
      iVar2 = iVar3;
      puVar4 = puVar1;
    }
  }
  return;
}

