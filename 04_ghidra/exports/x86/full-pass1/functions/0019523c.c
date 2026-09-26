/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019523c */

undefined4 _writetodc(int *param_1)

{
  uchar uVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  byte local_30;
  char local_2c;
  byte local_14 [16];
  
  uVar3 = _splusclock();
  if (DAT_001e36a8 != 0) {
    _outb(0x70,'\n');
    _outb(0x71,'&');
    _outb(0x70,'\v');
    _outb(0x71,'\x02');
    DAT_001e36a8 = 0;
  }
  _outb(0x70,'\r');
  _inb(0x71);
  do {
    _outb(0x70,'\n');
    uVar1 = _inb(0x71);
  } while ((char)uVar1 < '\0');
  iVar5 = 0;
  do {
    _outb(0x70,(uchar)iVar5);
    bVar2 = _inb(0x71);
    local_14[iVar5] = bVar2;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 0xe);
  _splx(uVar3);
  iVar5 = (*param_1 % 0x15180) / 0x3c;
  iVar4 = (*param_1 % 0x15180) % 0x3c;
  local_14[0] = (char)(iVar4 / 10) << 4 | (byte)(iVar4 % 10) & 0xf;
  iVar4 = iVar5 / 0x3c;
  iVar5 = iVar5 % 0x3c;
  local_14[2] = (char)(iVar5 / 10) << 4 | (byte)(iVar5 % 10) & 0xf;
  local_14[4] = (char)(iVar4 / 10) << 4 | (byte)(iVar4 % 10) & 0xf;
  iVar5 = *param_1 / 0x15180;
  local_14[6] = (byte)((iVar5 + 4) % 7);
  uVar6 = 0x7b2;
  iVar4 = 0x16d;
  if (0x16c < iVar5) {
    do {
      iVar5 = iVar5 - iVar4;
      uVar6 = uVar6 + 1;
      iVar4 = 0x16e;
      if ((uVar6 & 3) != 0) {
        iVar4 = 0x16d;
      }
    } while (iVar4 <= iVar5);
  }
  local_2c = (char)(((int)uVar6 % 100) / 10);
  local_30 = (byte)(((int)uVar6 % 100) % 10);
  local_14[9] = local_2c << 4 | local_30 & 0xf;
  local_30 = (byte)(((int)uVar6 / 100) / 10);
  iVar4 = 0;
  if (DAT_001e36ac <= iVar5) {
    piVar7 = &DAT_001e36ac;
    do {
      iVar5 = iVar5 - *piVar7;
      piVar7 = piVar7 + 1;
      iVar4 = iVar4 + 1;
    } while (*piVar7 <= iVar5);
  }
  DAT_001e36b0 = 0x1c;
  local_14[8] = (char)((iVar4 + 1) / 10) << 4 | (byte)((iVar4 + 1) % 10) & 0xf;
  local_14[7] = (char)((iVar5 + 1) / 10) << 4 | (byte)((iVar5 + 1) % 10) & 0xf;
  uVar3 = _splusclock();
  if (DAT_001e36a8 != 0) {
    _outb(0x70,'\n');
    _outb(0x71,'&');
    _outb(0x70,'\v');
    _outb(0x71,'\x02');
    DAT_001e36a8 = 0;
  }
  _outb(0x70,'\v');
  bVar2 = _inb(0x71);
  _outb(0x70,'\v');
  _outb(0x71,bVar2 | 0x80);
  iVar5 = 0;
  do {
    _outb(0x70,(uchar)iVar5);
    _outb(0x71,local_14[iVar5]);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 10);
  _outb(0x70,'2');
  _outb(0x71,local_30 << 4 | (byte)(((int)uVar6 / 100) % 10) & 0xf);
  _outb(0x70,'\v');
  _outb(0x71,bVar2 & 0x7f);
  _splx(uVar3);
  return 0;
}

