
undefined8 _ttsettermios(int *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar5;
  undefined4 unaff_i3;
  uint uVar6;
  undefined4 unaff_i4;
  uint uVar7;
  undefined4 unaff_i5;
  int iVar8;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  iVar8 = *param_1;
  uVar6 = 0;
  uVar3 = *param_2;
  uVar5 = 0;
  uVar7 = param_2[3];
  uVar4 = param_2[1];
  uVar1 = param_2[2];
  if ((uVar3 & 0x23e2) == 0) {
    bVar9 = (uVar3 & 2) == 0;
    if ((((uVar4 & 1) != 0) || (bVar9 = (uVar3 & 2) == 0, (uVar7 & 0xe0) != 0)) ||
       (bVar9 = (uVar3 & 2) == 0, (uVar1 & 0x1300) != 0x300)) goto loc_F001A980;
    uVar6 = 0x20;
  }
  else {
    bVar9 = (uVar3 & 2) == 0;
loc_F001A980:
    if (!bVar9) {
      uVar5 = 0x40000;
    }
    if ((uVar3 & 0x20) != 0) {
      uVar5 = uVar5 | 0x400000;
    }
    if ((uVar3 & 0x40) != 0) {
      uVar5 = uVar5 | 0x800000;
    }
    if ((uVar3 & 0x80) != 0) {
      uVar5 = uVar5 | 0x1000000;
    }
    if ((uVar3 & 0x200) != 0) {
      uVar5 = uVar5 | 0x4000000;
    }
    if ((uVar3 & 0x2000) != 0) {
      uVar5 = uVar5 | 0x8000000;
    }
    if ((uVar4 & 1) != 0) {
      uVar5 = uVar5 | 0x10000000;
    }
    if (((uVar4 & 2) == 0) || ((uVar3 & 0x100) == 0)) {
      if ((uVar4 & 2) != 0) {
        uVar5 = uVar5 | 0x20000000;
      }
      if ((uVar3 & 0x100) != 0) {
        uVar5 = uVar5 | 0x2000000;
      }
    }
    else {
      uVar6 = 0x10;
    }
    if ((uVar7 & 0x20) == 0) {
      uVar6 = uVar6 | 2;
    }
    if ((uVar7 & 0x40) != 0) {
      uVar5 = uVar5 | 8;
    }
    if ((uVar7 & 0x80) != 0) {
      uVar5 = uVar5 | 0x10;
    }
    if ((uVar1 & 0x1000) != 0) {
      uVar5 = uVar5 | 0x1000;
    }
    uVar2 = uVar1 & 0x300;
    if (uVar2 == 0x100) {
      uVar5 = uVar5 | 0x100;
    }
    else if (0x100 < uVar2) {
      if (uVar2 == 0x200) {
        uVar5 = uVar5 | 0x200;
      }
      else if ((uVar2 == 0x300) && (uVar5 = uVar5 | 0x300, (uVar1 & 0x1000) == 0)) {
        uVar2 = 0x200000;
        if ((uVar4 & 1) != 0) {
          uVar2 = 0x2000000;
        }
        uVar6 = uVar6 | uVar2;
        if ((uVar3 & 0x20) == 0) {
          uVar6 = uVar6 | 0x8000000;
        }
      }
    }
  }
  if ((uVar1 & 0x2000) != 0) {
    uVar6 = uVar6 | 0x40;
    goto loc_F001AB0C;
  }
  if ((uVar7 & 0x80) != 0) {
    if ((uVar1 & 0x40000) != 0) {
      uVar6 = uVar6 | 0xc0;
      goto loc_F001AB0C;
    }
    if ((uVar1 & 0x20000) != 0) goto loc_F001AB0C;
  }
  uVar6 = uVar6 | 0x80;
loc_F001AB0C:
  if ((uVar1 & 0x400) != 0) {
    uVar5 = uVar5 | 0x400;
  }
  if ((uVar1 & 0x800) != 0) {
    uVar5 = uVar5 | 0x800;
  }
  if ((uVar1 & 0x4000) == 0) {
    uVar6 = uVar6 | 0x1000000;
  }
  if ((uVar1 & 0x8000) != 0) {
    uVar5 = uVar5 | 0x8000;
  }
  if ((uVar1 & 0x10000) != 0) {
    uVar5 = uVar5 | 0x10000;
  }
  if ((uVar3 & 1) != 0) {
    uVar5 = uVar5 | 0x20000;
  }
  if ((uVar3 & 4) != 0) {
    uVar5 = uVar5 | 0x80000;
  }
  if ((uVar3 & 8) != 0) {
    uVar5 = uVar5 | 0x100000;
  }
  if ((uVar3 & 0x10) != 0) {
    uVar5 = uVar5 | 0x200000;
  }
  if ((uVar3 & 0x400) != 0) {
    uVar6 = uVar6 | 1;
  }
  if ((uVar3 & 0x800) == 0) {
    uVar6 = uVar6 | 0x40000000;
  }
  uVar6 = uVar6 | uVar4 & 0xff00;
  if ((uVar7 & 2) != 0) {
    uVar6 = uVar6 | 0x10000;
  }
  if ((uVar7 & 4) != 0) {
    uVar5 = uVar5 | 4;
  }
  if ((uVar7 & 1) != 0) {
    uVar6 = uVar6 | 0x4000000;
  }
  if ((uVar7 & 0x100) != 0) {
    uVar6 = uVar6 | 0x40000;
  }
  if ((uVar7 & 0x200) != 0) {
    uVar6 = uVar6 | 0x20000;
  }
  if ((uVar7 & 0x400) != 0) {
    uVar6 = uVar6 | 0x10000000;
  }
  if ((uVar7 & 0x10) != 0) {
    uVar5 = uVar5 | 2;
  }
  if ((uVar7 & 0x800) != 0) {
    uVar5 = uVar5 | 0x20;
  }
  if ((uVar7 & 0x4000000) != 0) {
    uVar6 = uVar6 | 4;
  }
  if ((uVar7 & 0x8000000) != 0) {
    uVar6 = uVar6 | 0x80000;
  }
  *(uint *)(*param_1 + 0x3c) = uVar6 | uVar7 & 0x80500008;
  param_1[4] = uVar5;
  *(undefined *)(iVar8 + 0x49) = *(undefined *)((int)param_2 + 0x21);
  *(undefined *)(iVar8 + 0x4a) = *(undefined *)((int)param_2 + 0x22);
  *(undefined *)(iVar8 + 0x4d) = *(undefined *)((int)param_2 + 0x12);
  *(undefined *)(iVar8 + 0x4e) = *(undefined *)((int)param_2 + 0x13);
  *(undefined *)(iVar8 + 0x4f) = *(undefined *)(param_2 + 5);
  *(undefined *)(iVar8 + 0x50) = *(undefined *)((int)param_2 + 0x15);
  *(undefined *)(iVar8 + 0x51) = *(undefined *)((int)param_2 + 0x17);
  *(undefined *)(iVar8 + 0x52) = *(undefined *)(param_2 + 6);
  *(undefined *)(iVar8 + 0x53) = *(undefined *)(param_2 + 4);
  *(undefined *)(iVar8 + 0x54) = *(undefined *)((int)param_2 + 0x11);
  *(undefined *)(iVar8 + 0x55) = *(undefined *)((int)param_2 + 0x16);
  *(undefined *)(iVar8 + 0x56) = *(undefined *)((int)param_2 + 0x1f);
  *(undefined *)(iVar8 + 0x57) = *(undefined *)(param_2 + 7);
  *(undefined *)(iVar8 + 0x58) = *(undefined *)((int)param_2 + 0x1e);
  *(undefined *)(iVar8 + 0x59) = *(undefined *)((int)param_2 + 0x1b);
  *(undefined *)(iVar8 + 0x5a) = *(undefined *)((int)param_2 + 0x1d);
  *(undefined *)((int)param_1 + 0x15) = *(undefined *)((int)param_2 + 0x19);
  *(undefined *)((int)param_1 + 0x16) = *(undefined *)((int)param_2 + 0x1a);
  *(undefined *)(param_1 + 5) = *(undefined *)(param_2 + 8);
  return CONCAT44(param_2,uVar4);
}

