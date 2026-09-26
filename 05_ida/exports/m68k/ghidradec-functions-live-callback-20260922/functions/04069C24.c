
void _DoKbdEvent(int param_1,int param_2,undefined2 param_3)

{
  byte bVar1;
  
  bVar1 = *(byte *)(_curMapping + 2 + param_1);
  if (param_2 == 0) {
    if (-1 < (char)bVar1) {
      _AllKeysUp();
      return;
    }
    bVar1 = bVar1 & 0x7f;
  }
  else {
    bVar1 = bVar1 | 0x80;
  }
  *(uint *)(_evg + 0xc) = CONCAT22((sword)((uint)*(undefined4 *)(_evg + 0xc) >> 0x10),param_3);
  *(byte *)(_curMapping + 2 + param_1) = bVar1;
  if (param_2 == 0) {
    if ((bVar1 & 0x20) != 0) {
      _DoCharGen(_curMapping,param_1,0);
    }
    if ((bVar1 & 0x10) != 0) {
      _DoModCalc(_curMapping,param_1);
    }
  }
  else {
    if ((bVar1 & 0x10) != 0) {
      _DoModCalc(_curMapping,param_1);
    }
    if ((bVar1 & 0x20) != 0) {
      _DoCharGen(_curMapping,param_1,param_2);
    }
  }
  return;
}

