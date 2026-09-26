
undefined4 _mfs_fsync_invalidate(int *param_1,uint param_2)

{
  int iVar1;
  sword sVar2;
  undefined4 uVar3;
  
  iVar1 = *param_1;
  if ((iVar1 == 0) || ((*(byte *)(iVar1 + 0x34) & 8) == 0)) {
    uVar3 = 0;
  }
  else {
    if ((char)*(byte *)(iVar1 + 0x34) < '\0') {
      _vm_info_dequeue(iVar1);
    }
    *(sword *)(iVar1 + 6) = *(sword *)(iVar1 + 6) + 1;
    if ((param_2 & 1) == 0) {
      _vmp_push_all(iVar1);
    }
    if ((param_2 & 2) == 0) {
      *(byte *)(iVar1 + 0x34) = *(byte *)(iVar1 + 0x34) & 0xef;
      _vmp_invalidate(iVar1);
    }
    sVar2 = *(sword *)(iVar1 + 6);
    *(sword *)(iVar1 + 6) = sVar2 + -1;
    if (sVar2 == 1) {
      _vm_info_enqueue(iVar1);
    }
    uVar3 = *(undefined4 *)(iVar1 + 0x30);
  }
  return uVar3;
}
