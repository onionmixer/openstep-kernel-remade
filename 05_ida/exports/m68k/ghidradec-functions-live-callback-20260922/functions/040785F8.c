
word _od_status(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  word wVar2;
  char cVar3;
  
  cVar3 = '\0';
  iVar1 = _od_drive_cmd(param_1,param_2,param_4,param_5 & 0xc | 2);
  if (iVar1 == 0) {
    _delay(0x96);
    *(undefined *)(param_3 + 7) = 0;
    *(undefined *)(param_3 + 7) = 0x20;
    wVar2 = (word)(byte)(cVar3 << 4);
    if ((param_5 & 1) != 0) {
      iVar1 = 1;
      do {
        if ((*(byte *)(param_3 + 4) & 1) != 0) {
          if (iVar1 < 0x989681) {
            return *(word *)(param_3 + 8);
          }
          break;
        }
        _delay(1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < 0x989681);
      *(undefined *)(param_1 + 599) = 0x3a;
      *(undefined *)(param_1 + 0x260) = 0;
      wVar2 = 0xffff;
    }
  }
  else {
    wVar2 = 0xffff;
  }
  return wVar2;
}

