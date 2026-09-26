
undefined8 _vik_1137125_wa(void)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  undefined4 unaff_i1;
  uint uVar5;
  undefined4 unaff_i2;
  uint uVar6;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar2 = 0;
  do {
    iVar2 = iVar2 + 0x20;
  } while (iVar2 < 0x8001);
  uVar6 = 0;
  uVar3 = 0x40000000;
  do {
    iVar2 = segment(0xe);
    *(undefined4 *)(uVar3 + iVar2) = 0;
    uVar4 = 0x4000000;
    uVar3 = 0x84000000;
    while( true ) {
      iVar2 = segment(0xe);
      *(undefined4 *)((uVar6 | uVar3) + iVar2) = 0;
      iVar2 = 0;
      uVar5 = uVar6 | uVar4;
      uVar3 = 0;
      do {
        iVar1 = segment(0xf);
        *(undefined4 *)((uVar5 | uVar3) + iVar1) = 0;
        iVar2 = iVar2 + 1;
        uVar3 = iVar2 * 8;
      } while (iVar2 < 4);
      uVar4 = uVar4 + 0x4000000;
      if (0xc000000 < (int)uVar4) break;
      uVar3 = uVar4 | 0x80000000;
    }
    uVar6 = uVar6 + 0x20;
    uVar3 = uVar6 | 0x40000000;
  } while ((int)uVar6 < 0xfe1);
  return CONCAT44(uVar5,uVar4);
}

