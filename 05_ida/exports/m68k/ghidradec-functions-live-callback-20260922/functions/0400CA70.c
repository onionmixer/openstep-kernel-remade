
undefined4 _soo_select(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x16);
  if (param_2 == 1) {
    if ((((*(sword *)(iVar3 + 0x22) != 0) || ((*(byte *)(iVar3 + 7) & 0x20) != 0)) ||
        (*(sword *)(iVar3 + 0x1e) != 0)) || (*(sword *)(iVar3 + 0x50) != 0)) {
      return 1;
    }
  }
  else {
    if (1 < param_2) {
      if (param_2 != 2) {
        return 0;
      }
      iVar2 = (uint)*(word *)(iVar3 + 0x3e) - (uint)*(word *)(iVar3 + 0x3c);
      iVar1 = (uint)*(word *)(iVar3 + 0x3a) - (uint)*(word *)(iVar3 + 0x38);
      if (iVar2 < iVar1) {
        iVar1 = iVar2;
      }
      if ((((0 < iVar1) &&
           (((*(byte *)(iVar3 + 7) & 2) != 0 || ((*(byte *)(*(int *)(iVar3 + 0xc) + 9) & 4) == 0))))
          || ((*(byte *)(iVar3 + 7) & 0x10) != 0)) || (*(sword *)(iVar3 + 0x50) != 0)) {
        return 1;
      }
      iVar3 = iVar3 + 0x38;
      goto loc_400CB42;
    }
    if (param_2 != 0) {
      return 0;
    }
    if ((*(sword *)(iVar3 + 0x52) != 0) || ((*(byte *)(iVar3 + 7) & 0x40) != 0)) {
      return 1;
    }
  }
  iVar3 = iVar3 + 0x22;
loc_400CB42:
  _sbselqueue(iVar3);
  return 0;
}

