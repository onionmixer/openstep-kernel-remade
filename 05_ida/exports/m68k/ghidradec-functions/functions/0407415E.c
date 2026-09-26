
undefined4 _np_select_common(byte param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = (sword)(word)param_1 * 0x14c;
  if (1 < param_1) {
    return 6;
  }
  if (param_2 == 0) {
    if ((*(int *)(DAT_40c3b2a + iVar1 + 0x20) == 6) || (*(int *)(DAT_40c3b2a + iVar1 + 0x20) == 0))
    {
      return 1;
    }
    iVar2 = _selthreadcache(iVar1 + 0x40c3b46);
    if (iVar2 == 0) {
      return 0;
    }
    uVar3 = *(uint *)(DAT_40c3b2a + iVar1) | 0x80;
  }
  else {
    if (param_2 != 2) {
      return 0;
    }
    if (param_3 != 0) {
      return 0;
    }
    if (*(int *)(DAT_40c3b2a + iVar1 + 0x20) == 2) {
      return 1;
    }
    iVar2 = _selthreadcache(iVar1 + 0x40c3b42);
    if (iVar2 == 0) {
      return 0;
    }
    uVar3 = *(uint *)(DAT_40c3b2a + iVar1) | 0x40;
  }
  *(uint *)(DAT_40c3b2a + iVar1) = uVar3;
  return 0;
}
