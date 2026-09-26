
void sub_4080388(void)

{
  uint uVar1;
  uint uVar2;
  word wStack_24;
  undefined uStack_22;
  byte bStack_21;
  undefined2 uStack_20;
  
  _nvram_check(&wStack_24);
  uVar1 = CONCAT31(CONCAT21(wStack_24,uStack_22),bStack_21) & 0xfc0fffff;
  wStack_24 = (word)(uVar1 >> 0x10) | (word)(((wRam040b508a & 0x3f) << 0x14) >> 0x10);
  uVar2 = CONCAT22((sword)uVar1,uStack_20) & 0xfc0fffff;
  uVar1 = uVar2 | (wRam040b508e & 0x3f) << 0x14;
  uStack_22 = (undefined)(uVar1 >> 0x18);
  bStack_21 = (byte)(uVar1 >> 0x10);
  uStack_20 = (undefined2)uVar2;
  bStack_21 = bStack_21 & 0xf3 | (byte)((dword_40B5084 & 1) << 2) | (byte)((dword_40B5080 & 1) << 3)
  ;
  _nvram_set(&wStack_24);
  return;
}

