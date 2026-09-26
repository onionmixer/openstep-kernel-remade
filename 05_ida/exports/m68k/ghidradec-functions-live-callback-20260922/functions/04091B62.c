
byte _rtc_real_read(char param_1)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  
  *_scr2 = *_scr2 & 0xfffff9ff | 0x100;
  _delay(1);
  iVar3 = 0;
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
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  bVar2 = 0;
  iVar3 = 0;
  do {
    uVar1 = *_scr2;
    *_scr2 = uVar1 & 0xfffffbff | 0x200;
    _delay(1);
    bVar2 = bVar2 << 1;
    *_scr2 = uVar1 & 0xfffffbff;
    _delay(1);
    if ((*_scr2 & 0x400) != 0) {
      bVar2 = bVar2 | 1;
    }
    _delay(1);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  *_scr2 = *_scr2 & 0xfffff8ff;
  return bVar2;
}

