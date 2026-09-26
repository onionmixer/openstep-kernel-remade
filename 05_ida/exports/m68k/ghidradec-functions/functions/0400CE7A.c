
byte _ttyflush(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  char cVar6;
  byte bVar7;
  
  cVar3 = '\0';
  cVar4 = '\0';
  cVar6 = '\0';
  bVar7 = 0;
  if ((param_2 & 1) != 0) {
    do {
      iVar1 = _getc(param_1 + 0xc);
    } while (-1 < iVar1);
    cVar4 = param_1 < 0;
    cVar6 = '\0';
    bVar7 = 0;
    _wakeup(param_1);
  }
  if ((param_2 & 2) != 0) {
    _wakeup(param_1 + 0x18);
    *(word *)(param_1 + 0x40) = *(word *)(param_1 + 0x40) & 0xfeff;
    uVar2 = (uint)*(byte *)(param_1 + 0x38);
    cVar3 = uVar2 * 0xc < uVar2;
    (**(code **)(DAT_40b0ad4 + uVar2 * 0x2c))(param_1,param_2);
    do {
      iVar1 = _getc(param_1 + 0x18);
      cVar6 = '\0';
      bVar7 = 0;
      cVar4 = iVar1 < 0;
    } while (!(bool)cVar4);
  }
  bVar5 = (param_2 & 1) == 0;
  if (!bVar5) {
    do {
      iVar1 = _getc(param_1);
    } while (-1 < iVar1);
    *(undefined *)(param_1 + 0x49) = 0;
    *(undefined *)(param_1 + 0x4a) = 0;
    cVar6 = '\0';
    bVar7 = 0;
    uVar2 = *(uint *)(param_1 + 0x3e) & 0xff40ffff;
    *(uint *)(param_1 + 0x3e) = uVar2;
    cVar4 = (int)uVar2 < 0;
    bVar5 = uVar2 == 0;
  }
  return cVar3 << 4 | cVar4 << 3 | bVar5 << 2 | cVar6 << 1 | bVar7;
}
