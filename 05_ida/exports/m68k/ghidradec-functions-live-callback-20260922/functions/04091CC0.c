
undefined4 _rtc_real_blkread(char param_1,byte *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  
  *_scr2 = *_scr2 & 0xfffff9ff | 0x100;
  _delay(1);
  iVar4 = 0;
  do {
    uVar1 = *_scr2 & 0xfffffbff;
    if (param_1 < '\0') {
      uVar1 = uVar1 | 0x400;
    }
    *_scr2 = uVar1;
    _delay(1);
    *_scr2 = uVar1 | 0x200;
    _delay(1);
    *_scr2 = CONCAT22((sword)(uVar1 >> 0x10),(sword)(uVar1 | 0x200)) & 0xfffffdff;
    param_1 = param_1 << 1;
    _delay(1);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  while (0 < param_3) {
    param_3 = param_3 + -1;
    bVar3 = 0;
    iVar4 = 0;
    do {
      uVar1 = *_scr2;
      *_scr2 = uVar1 & 0xfffffbff | 0x200;
      _delay(1);
      bVar3 = bVar3 << 1;
      *_scr2 = uVar1 & 0xfffffbff;
      _delay(1);
      if ((*_scr2 & 0x400) != 0) {
        bVar3 = bVar3 | 1;
      }
      _delay(1);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
    *param_2 = bVar3;
    param_2 = param_2 + 1;
  }
  uVar1 = *_scr2;
  uVar2 = uVar1 & 0xfffff8ff;
  *_scr2 = uVar2;
  return CONCAT22((sword)(uVar1 >> 0x10),(word)(byte)(((int)uVar2 < 0) << 3 | (uVar2 == 0) << 2));
}

