
undefined4 _mfs_fsync(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_1;
  if ((iVar1 == 0) || ((*(byte *)(iVar1 + 0x34) & 8) == 0)) {
    uVar2 = 0;
  }
  else {
    _vmp_get(iVar1);
    _vmp_push(iVar1);
    _vmp_put(iVar1);
    uVar2 = *(undefined4 *)(iVar1 + 0x30);
  }
  return uVar2;
}

