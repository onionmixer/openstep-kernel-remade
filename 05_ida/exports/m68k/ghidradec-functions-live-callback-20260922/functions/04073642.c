
undefined4 _np_wait_printer_ready(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = _np_getgpi(param_1,param_1 + 0x11b);
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else if (*(int *)(param_1 + 0x126) != 2) {
    do {
      if ((*(int *)(param_1 + 0x126) == 6) && ((*(uint *)(param_1 + 0x106) & 0x100) != 0)) {
        return 0x51;
      }
      if ((*(int *)(param_1 + 0x126) == 0) || (*(int *)(param_1 + 0x126) == 7)) {
        return 0x50;
      }
      if ((*(uint *)(param_1 + 0x106) & 0x100) != 0) {
        return 0x23;
      }
      _sleep((int *)(param_1 + 0x126),0x28);
    } while (*(int *)(param_1 + 0x126) != 2);
  }
  return uVar2;
}

