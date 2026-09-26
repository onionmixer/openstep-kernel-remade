/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00195030 */

undefined4 _readtodc(int *param_1)

{
  uchar uVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  byte local_14 [4];
  byte local_10;
  byte local_d;
  byte local_c;
  byte local_b;
  
  iVar7 = 0;
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
  iVar6 = 0;
  do {
    _outb(0x70,(uchar)iVar6);
    bVar2 = _inb(0x71);
    local_14[iVar6] = bVar2;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xe);
  _splx(uVar3);
  uVar4 = (local_b & 0xf) + (char)(local_b >> 4) * 10;
  if (uVar4 < 0x46) {
    uVar4 = uVar4 + 100;
  }
  for (iVar6 = (char)(local_c >> 4) * 10 + (local_c & 0xf) + -2; -1 < iVar6; iVar6 = iVar6 + -1) {
    iVar7 = iVar7 + (&DAT_001e36ac)[iVar6];
  }
  DAT_001e36b0 = 0x1c;
  uVar5 = 0x46;
  if (0x46 < uVar4) {
    do {
      iVar6 = 0x16e;
      if ((uVar5 & 3) != 0) {
        iVar6 = 0x16d;
      }
      iVar7 = iVar7 + iVar6;
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < (int)uVar4);
  }
  *param_1 = ((local_10 & 0xf) + (char)(local_10 >> 4) * 10) * 0xe10 +
             (char)(local_14[0] >> 4) * 10 + (local_14[0] & 0xf) +
             ((char)(local_14[2] >> 4) * 10 + (local_14[2] & 0xf)) * 0x3c +
             ((char)(local_d >> 4) * 10 + (local_d & 0xf) + -1) * 0x15180 + iVar7 * 0x15180;
  return 0;
}

