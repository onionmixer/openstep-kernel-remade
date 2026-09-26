
void _unmap_vnode(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  sword sVar3;
  int iStack_8;
  
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x34) & 8) != 0) {
    sVar3 = *(sword *)(iVar1 + 4);
    *(sword *)(iVar1 + 4) = sVar3 + -1;
    if ((sword)(sVar3 + -1) < 1) {
      *(sword *)(iVar1 + 4) = sVar3;
      (**(code **)(param_1[7] + 0x7c))(param_1,&iStack_8);
      sVar3 = *(sword *)(iVar1 + 4);
      *(sword *)(iVar1 + 4) = sVar3 + -1;
      if (iStack_8 == 0) {
        _mfs_memfree(iVar1,0);
      }
      else {
        uVar2 = *(undefined4 *)(iVar1 + 0x20);
        if ((_close_flush != 0) || ((*(byte *)(iVar1 + 0x34) & 0x20) != 0)) {
          *(sword *)(iVar1 + 4) = sVar3;
          _vmp_get(iVar1);
          _vmp_push(iVar1);
        }
        _vm_object_deactivate_pages(uVar2);
        if ((_close_flush != 0) || ((*(byte *)(iVar1 + 0x34) & 0x20) != 0)) {
          _vmp_put(iVar1);
          *(sword *)(iVar1 + 4) = *(sword *)(iVar1 + 4) + -1;
        }
      }
    }
  }
  return;
}
