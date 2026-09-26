
qword _tcp_xmit_timer(int param_1)

{
  word wVar1;
  word wVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar4;
  undefined4 unaff_i2;
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
  DAT_f013a7bc._0_4_ = DAT_f013a7bc._0_4_ + 1;
  wVar1 = *(word *)(param_1 + 0x60);
  uVar4 = (uint)wVar1;
  if (uVar4 == 0) {
    *(sword *)(param_1 + 0x60) = *(sword *)(param_1 + 0x5a) << 3;
    *(sword *)(param_1 + 0x62) = *(sword *)(param_1 + 0x5a) << 1;
  }
  else {
    iVar3 = (uint)*(word *)(param_1 + 0x5a) - (((int)(uVar4 * 0x10000) >> 0x13) + 1);
    *(sword *)(param_1 + 0x60) = (sword)(uVar4 + iVar3);
    if ((int)((uVar4 + iVar3) * 0x10000) < 1) {
      *(undefined2 *)(param_1 + 0x60) = 1;
    }
    if (iVar3 * 0x10000 < 0) {
      iVar3 = -iVar3;
    }
    iVar3 = (uint)*(word *)(param_1 + 0x62) +
            (iVar3 - ((int)((uint)*(word *)(param_1 + 0x62) << 0x10) >> 0x12));
    *(sword *)(param_1 + 0x62) = (sword)iVar3;
    if (0 < iVar3 * 0x10000) {
      *(undefined2 *)(param_1 + 0x5a) = 0;
      goto loc_F00367BC;
    }
    *(undefined2 *)(param_1 + 0x62) = 1;
  }
  *(undefined2 *)(param_1 + 0x5a) = 0;
loc_F00367BC:
  *(undefined2 *)(param_1 + 0x12) = 0;
  iVar3 = (uint)*(word *)(param_1 + 0x62) + ((int)((uint)*(word *)(param_1 + 0x60) << 0x10) >> 0x13)
  ;
  *(sword *)(param_1 + 0x14) = (sword)iVar3;
  wVar2 = *(word *)(param_1 + 100);
  iVar3 = iVar3 * 0x10000 >> 0x10;
  if ((iVar3 < (int)(uint)wVar2) || (wVar2 = 0x80, 0x80 < iVar3)) {
    *(word *)(param_1 + 0x14) = wVar2;
  }
  *(undefined2 *)(param_1 + 0x6a) = 0;
  return (qword)CONCAT24(wVar1,param_1);
}

