
/* WARNING: Removing unreachable block (ram,0xf004f534) */
/* WARNING: Removing unreachable block (ram,0xf004f504) */
/* WARNING: Removing unreachable block (ram,0xf004f49c) */
/* WARNING: Removing unreachable block (ram,0xf004f600) */
/* WARNING: Removing unreachable block (ram,0xf004f67c) */
/* WARNING: Removing unreachable block (ram,0xf004f70c) */
/* WARNING: Removing unreachable block (ram,0xf004f6cc) */
/* WARNING: Removing unreachable block (ram,0xf004f578) */
/* WARNING: Removing unreachable block (ram,0xf004f740) */
/* WARNING: Removing unreachable block (ram,0xf004f6b0) */
/* WARNING: Removing unreachable block (ram,0xf004f63c) */
/* WARNING: Removing unreachable block (ram,0xf004f778) */
/* WARNING: Removing unreachable block (ram,0xf004f614) */
/* WARNING: Removing unreachable block (ram,0xf004f4dc) */
/* WARNING: Removing unreachable block (ram,0xf004f518) */
/* WARNING: Removing unreachable block (ram,0xf004f53c) */
/* WARNING: Removing unreachable block (ram,0xf004f478) */

undefined4 sub_F004F460(void)

{
  word wVar1;
  bool bVar2;
  word *pwVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined8 in_o0_1;
  int iVar7;
  int iVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  pwVar3 = (word *)((qword)in_o0_1 >> 0x20);
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
  while (iVar4 = sub_F004F92C(pwVar3), iVar4 != 0) {
    iVar8 = 0;
    if ((*pwVar3 & 1) != 0) {
      sub_F004FCE0(pwVar3);
      return 0xb;
    }
    iVar7 = *(int *)(iVar4 + 0xc);
    iVar5 = *(int *)(iVar7 + 0x14);
    while ((iVar5 != 0 && (bVar2 = iVar8 < 0x32, iVar8 = iVar8 + 1, bVar2))) {
      iVar7 = *(int *)(*(int *)(*(int *)(iVar7 + 0x14) + 0x14) + 0xc);
      if (iVar7 == *(int *)(pwVar3 + 6)) {
        sub_F004FCE0(pwVar3);
        return 0x4e;
      }
      iVar5 = *(int *)(iVar7 + 0x14);
    }
    *(int *)(pwVar3 + 10) = iVar4;
    sub_F004FB6C(iVar4);
    *(word **)(*(int *)(pwVar3 + 6) + 0x14) = pwVar3;
    iVar8 = _sleep(pwVar3);
    *(undefined4 *)(*(int *)(pwVar3 + 6) + 0x14) = 0;
    if (iVar8 != 0) {
      sub_F004FBB0(iVar4);
      sub_F004FCE0(pwVar3);
      return 4;
    }
  }
  bVar2 = true;
  *(int *)((int)register0x00000038 + -0xc) = *(int *)(pwVar3 + 8) + 4;
loc_F004F56C:
  uVar6 = sub_F004F98C();
  switch(uVar6) {
  case :
    if (!bVar2) {
      return 0;
    }
    **(undefined4 **)((int)register0x00000038 + -0xc) = pwVar3;
    *(undefined4 *)(pwVar3 + 10) = *(undefined4 *)((int)register0x00000038 + -0x10);
    return 0;
  case :
    iVar4 = *(int *)((int)register0x00000038 + -0x10);
    if (pwVar3[1] == 1) {
      if (*(sword *)(*(int *)((int)register0x00000038 + -0x10) + 2) != 2) {
        wVar1 = pwVar3[1];
        goto loc_F004F610;
      }
      sub_F004FCA4(*(int *)((int)register0x00000038 + -0x10));
      iVar4 = *(int *)((int)register0x00000038 + -0x10);
    }
    wVar1 = pwVar3[1];
loc_F004F610:
    *(word *)(iVar4 + 2) = wVar1;
    sub_F004FCE0();
    return 0;
  case :
    if (*(word *)(*(int *)((int)register0x00000038 + -0x10) + 2) == pwVar3[1]) {
      sub_F004FCE0(pwVar3);
      return 0;
    }
    if (*(int *)(*(int *)((int)register0x00000038 + -0x10) + 4) == *(int *)(pwVar3 + 2)) {
      **(undefined4 **)((int)register0x00000038 + -0xc) = pwVar3;
      iVar4 = *(int *)((int)register0x00000038 + -0x10);
      *(int *)(pwVar3 + 10) = iVar4;
      *(int *)(iVar4 + 4) = *(int *)(pwVar3 + 4) + 1;
    }
    else {
      sub_F004FBF8();
    }
    break;
  case :
    if ((pwVar3[1] == 1) && (*(sword *)(*(int *)((int)register0x00000038 + -0x10) + 2) == 2)) {
      sub_F004FCA4(*(int *)((int)register0x00000038 + -0x10));
    }
    else {
      *(undefined4 *)(pwVar3 + 0xc) =
           *(undefined4 *)(*(int *)((int)register0x00000038 + -0x10) + 0x18);
      sub_F004FB6C(pwVar3);
    }
    if (bVar2) {
      bVar2 = false;
      **(undefined4 **)((int)register0x00000038 + -0xc) = pwVar3;
      uVar6 = *(undefined4 *)(*(int *)((int)register0x00000038 + -0x10) + 0x14);
      *(word **)((int)register0x00000038 + -0xc) = pwVar3 + 10;
      *(undefined4 *)(pwVar3 + 10) = uVar6;
    }
    else {
      *(undefined4 *)*(undefined8 *)((int)register0x00000038 + -0x10) =
           *(undefined4 *)
            ((int)((qword)*(undefined8 *)((int)register0x00000038 + -0x10) >> 0x20) + 0x14);
    }
    sub_F004FCE0(*(undefined4 *)((int)register0x00000038 + -0x10));
    goto loc_F004F56C;
  case :
    goto loc_F004F71C;
  case :
    if (bVar2) {
      **(undefined4 **)((int)register0x00000038 + -0xc) = pwVar3;
      *(undefined4 *)(pwVar3 + 10) = *(undefined4 *)((int)register0x00000038 + -0x10);
    }
    *(int *)(*(int *)((int)register0x00000038 + -0x10) + 4) = *(int *)(pwVar3 + 4) + 1;
    break;
  :
    return 0;
  }
  sub_F004FCA4(0);
  return 0;
loc_F004F71C:
  iVar4 = *(int *)((int)register0x00000038 + -0x10);
  *(word **)((int)register0x00000038 + -0xc) = pwVar3 + 10;
  *(undefined4 *)(pwVar3 + 10) = *(undefined4 *)(iVar4 + 0x14);
  *(word **)(iVar4 + 0x14) = pwVar3;
  bVar2 = false;
  *(int *)(iVar4 + 8) = *(int *)(pwVar3 + 2) + -1;
  sub_F004FCA4();
  goto loc_F004F56C;
}

