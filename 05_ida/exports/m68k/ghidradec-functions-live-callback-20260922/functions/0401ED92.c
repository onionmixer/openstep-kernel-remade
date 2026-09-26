
uint _in_lnaof(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = _in_ifaddr;
  if ((int)param_1 < 0) {
    if ((param_1 & 0xc0000000) == 0x80000000) {
      uVar2 = param_1 & 0xffff0000;
      param_1 = param_1 & 0xffff;
    }
    else if ((param_1 & 0xe0000000) == 0xc0000000) {
      uVar2 = param_1 & 0xffffff00;
      param_1 = param_1 & 0xff;
    }
    else {
      if ((param_1 & 0xf0000000) != 0xe0000000) {
        return param_1;
      }
      param_1 = param_1 & 0xfffffff;
      uVar2 = 0xe0000000;
    }
  }
  else {
    uVar2 = param_1 & 0xff000000;
    param_1 = param_1 & 0xffffff;
  }
  while( true ) {
    if (iVar1 == 0) {
      return param_1;
    }
    if (uVar2 == *(uint *)(iVar1 + 0x28)) break;
    iVar1 = *(int *)(iVar1 + 0x40);
  }
  return param_1 & ~*(uint *)(iVar1 + 0x34);
}

