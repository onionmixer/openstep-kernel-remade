
undefined4 _ttselect(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _ttynty(param_1);
  if (param_2 == 1) {
    iVar2 = _ttnread(iVar1);
    if ((0 < iVar2) ||
       ((-1 < *(sword *)(iVar1 + 0x12) && ((*(byte *)(param_1 + 0x41) & 0x10) == 0)))) {
      return 1;
    }
    iVar1 = _selthreadcache(param_1 + 0x28);
    if (iVar1 != 0) {
      *(word *)(param_1 + 0x40) = *(word *)(param_1 + 0x40) | 0x800;
    }
  }
  else if (param_2 == 2) {
    if (*(int *)(param_1 + 0x18) <=
        (int)*(sword *)(_ttlowat + (*(byte *)(param_1 + 0x48) & 0x1f) * 2)) {
      return 1;
    }
    iVar1 = _selthreadcache(param_1 + 0x2c);
    if (iVar1 != 0) {
      *(word *)(param_1 + 0x40) = *(word *)(param_1 + 0x40) | 0x1000;
    }
  }
  return 0;
}

