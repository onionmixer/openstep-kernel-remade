
undefined8 _od_drive_cmd(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x210);
  _od_block_async(param_1,param_2);
  *(undefined *)(iVar1 + 7) = 0;
  *(byte *)(iVar1 + 6) = (byte)(param_2 + -0x40c3e18 >> 5) | 0x80;
  _delay(2);
  iVar4 = 1;
  do {
    if ((*(byte *)(iVar1 + 4) & 1) != 0) break;
    _delay(1);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x2001);
  iVar3 = iVar4 / 1;
  if (iVar4 % 1 == 0) {
    *(undefined *)(iVar1 + 7) = 0;
  }
  if (iVar4 < 0x2001) {
    *(sword *)(param_1 + 0x25a) = (sword)param_3;
    *(char *)(iVar1 + 8) = (char)((uint)param_3 >> 8);
    *(char *)(iVar1 + 9) = (char)param_3;
    iVar4 = 1;
    do {
      if ((*(byte *)(iVar1 + 4) & 1) == 0) break;
      _delay(1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x2001);
    iVar3 = iVar4 / 1;
    if (iVar4 % 1 == 0) {
      *(undefined *)(iVar1 + 7) = 0;
    }
    if (iVar4 < 0x2001) {
      if ((param_4 & 9) == 0) {
        *(uint *)(param_1 + 0x220) = *(uint *)(param_1 + 0x220) | 0x8000000;
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) | 1;
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xf3;
        if (((param_3 == 0x5200) || (param_3 == 0x5300)) || (param_3 == 0x5600)) {
          *(undefined *)(param_1 + 0x260) = 0x10;
        }
        else {
          *(undefined *)(param_1 + 0x260) = 6;
        }
      }
      else {
        *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xf2;
      }
      if ((param_4 & 1) != 0) {
        do {
        } while ((*(byte *)(iVar1 + 4) & 1) == 0);
      }
      uVar2 = 0;
      goto loc_40775F8;
    }
    *(undefined *)(param_1 + 599) = 0x3b;
  }
  else {
    *(undefined *)(param_1 + 599) = 0x3a;
  }
  *(undefined *)(param_1 + 0x260) = 0;
  uVar2 = 0xffffffff;
loc_40775F8:
  return CONCAT44(uVar2,iVar3);
}

