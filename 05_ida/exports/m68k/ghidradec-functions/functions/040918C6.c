
undefined4 _rtc_write(byte param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  param_1 = param_1 | 0x80;
  *_scr2 = *_scr2 & 0xfffff9ff | 0x100;
  _delay(1);
  iVar3 = 0;
  do {
    uVar1 = *_scr2 & 0xfffffbff;
    if ((char)param_1 < '\0') {
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
  iVar3 = 0;
  do {
    uVar1 = *_scr2 & 0xfffffbff;
    if (param_2 < '\0') {
      uVar1 = uVar1 | 0x400;
    }
    *_scr2 = uVar1;
    _delay(1);
    *_scr2 = uVar1 | 0x200;
    _delay(1);
    *_scr2 = CONCAT22((sword)(uVar1 >> 0x10),(sword)(uVar1 | 0x200)) & 0xfffffdff;
    param_2 = param_2 << 1;
    _delay(1);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  uVar1 = *_scr2;
  uVar2 = uVar1 & 0xfffff8ff;
  *_scr2 = uVar2;
  return CONCAT22((sword)(uVar1 >> 0x10),(word)(byte)(((int)uVar2 < 0) << 3 | (uVar2 == 0) << 2));
}
