
undefined8 binstr(void)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  uint uVar5;
  int in_D0;
  uint uVar6;
  undefined4 in_D1;
  sword sVar8;
  uint unaff_D2;
  uint unaff_D3;
  sword sVar9;
  char *in_A0;
  bool bVar10;
  word wVar7;
  
  bVar4 = true;
  uVar6 = in_D0 - 1;
  sVar9 = 0;
  do {
    while( true ) {
      uVar3 = unaff_D3 >> 0x1d;
      bVar1 = (int)unaff_D3 < 0;
      uVar2 = unaff_D2 & 0x80000000;
      uVar5 = unaff_D2 >> 0x1d;
      bVar10 = CARRY4(unaff_D3 * 2,unaff_D3 * 8);
      unaff_D3 = unaff_D3 * 10;
      unaff_D2 = (unaff_D2 << 1 | (uint)bVar1) + (uVar3 | unaff_D2 << 3) + (uint)bVar10;
      sVar8 = (word)uVar5 + (word)(uVar2 != 0) + (word)bVar10;
      if (!bVar4) break;
      sVar9 = sVar8 + sVar9 * 0x10;
      *in_A0 = (char)sVar9;
      bVar4 = false;
      wVar7 = (sword)uVar6 - 1;
      uVar6 = (uint)wVar7;
      in_A0 = in_A0 + 1;
      if (wVar7 == 0xffff) goto loc_409B1C6;
    }
    bVar4 = true;
    wVar7 = (sword)uVar6 - 1;
    uVar6 = (uint)wVar7;
    sVar9 = sVar8;
  } while (wVar7 != 0xffff);
  *in_A0 = (char)sVar8 * '\x10';
loc_409B1C6:
  return CONCAT44(in_D0,in_D1);
}

