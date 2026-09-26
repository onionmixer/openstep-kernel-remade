
undefined4 _ttymodem(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = _ttynty(param_1);
  uVar1 = *(uint *)(param_1 + 0x3e);
  if (((uVar1 & 2) == 0) && ((*(byte *)(param_1 + 0x3b) & 0x10) != 0)) {
    if (param_2 == 0) {
      if ((uVar1 & 0x100) == 0) {
        *(uint *)(param_1 + 0x3e) = uVar1 | 0x100;
        (**(code **)(DAT_40b0ad4 + (uint)*(byte *)(param_1 + 0x38) * 0x2c))(param_1,0);
      }
    }
    else {
      *(uint *)(param_1 + 0x3e) = uVar1 & 0xfffffeff;
      _ttstart(param_1);
    }
  }
  else if (param_2 == 0) {
    uVar1 = *(uint *)(param_1 + 0x3e);
    *(uint *)(param_1 + 0x3e) = uVar1 & 0xffffffef;
    if ((((uVar1 & 4) != 0) && (-1 < *(sword *)(iVar2 + 0x12))) &&
       (_ttwakeup(param_1), (*(byte *)(param_1 + 0x3a) & 1) == 0)) {
      _gsignal((int)*(sword *)(param_1 + 0x42),1);
      _gsignal((int)*(sword *)(param_1 + 0x42),0x13);
      _ttyflush(param_1,3);
      return 0;
    }
  }
  else {
    *(uint *)(param_1 + 0x3e) = *(uint *)(param_1 + 0x3e) | 0x10;
    _wakeup(param_1);
  }
  return 1;
}

