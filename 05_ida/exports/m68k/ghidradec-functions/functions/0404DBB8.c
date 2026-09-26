
undefined4 _mfs_invalidate(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x34) & 8) != 0)) {
    if (*(sword *)(iVar1 + 6) < 1) {
      _vmp_get(iVar1);
      _vmp_invalidate(iVar1);
      _vmp_put(iVar1);
    }
    else {
      *(byte *)(iVar1 + 0x34) = *(byte *)(iVar1 + 0x34) | 0x10;
    }
  }
  return *(undefined4 *)(iVar1 + 0x30);
}
