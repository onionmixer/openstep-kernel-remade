
undefined8 _ttgettermios(int *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
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
  uint uVar6;
  undefined4 unaff_i3;
  uint uVar7;
  undefined4 unaff_i4;
  uint uVar8;
  undefined4 unaff_i5;
  uint uVar9;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar10;
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
  uVar4 = 0;
  uVar5 = 0;
  iVar1 = *param_1;
  uVar6 = 0;
  uVar9 = *(uint *)(iVar1 + 0x3c);
  uVar7 = 0;
  uVar8 = param_1[4];
  if ((uVar9 & 0x20) == 0) {
    if ((uVar8 & 0x40000) != 0) {
      uVar4 = 2;
    }
    if ((uVar8 & 0x400000) != 0) {
      uVar4 = uVar4 | 0x20;
    }
    if ((uVar8 & 0x800000) != 0) {
      uVar4 = uVar4 | 0x40;
    }
    if ((uVar8 & 0x1000000) != 0) {
      uVar4 = uVar4 | 0x80;
    }
    if ((uVar8 & 0x4000000) != 0) {
      uVar4 = uVar4 | 0x200;
    }
    if ((uVar8 & 0x8000000) != 0) {
      uVar4 = uVar4 | 0x2000;
    }
    uVar5 = (uint)((uVar8 & 0x10000000) != 0);
    if ((uVar9 & 0x10) == 0) {
      if ((uVar8 & 0x2000000) != 0) {
        uVar4 = uVar4 | 0x100;
      }
      if ((uVar8 & 0x20000000) != 0) goto loc_F001ADF0;
    }
    else {
      uVar4 = uVar4 | 0x100;
loc_F001ADF0:
      uVar5 = uVar5 | 2;
    }
    if ((uVar9 & 2) == 0) {
      uVar6 = 0x20;
    }
    if ((uVar8 & 8) != 0) {
      uVar6 = uVar6 | 0x40;
    }
    if ((uVar8 & 0x10) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    if ((uVar9 & 0xa200000) == 0) {
      if ((uVar8 & 0x1000) != 0) {
        uVar7 = 0x1000;
      }
      uVar2 = uVar8 & 0x300;
      if (uVar2 == 0x100) {
        uVar7 = uVar7 | 0x100;
      }
      else if (0x100 < uVar2) {
        if (uVar2 == 0x200) {
          uVar7 = uVar7 | 0x200;
        }
        else if (uVar2 == 0x300) {
          uVar7 = uVar7 | 0x300;
        }
      }
    }
    else {
      uVar7 = 0x300;
      if ((uVar9 & 0x8000000) != 0) {
        uVar4 = uVar4 & 0xffffffdf;
      }
      if ((uVar9 & 0x200000) != 0) {
        uVar5 = uVar5 & 0xfffffffe;
      }
    }
  }
  else {
    uVar7 = 0x300;
  }
  uVar2 = uVar9 & 0xc0;
  if (uVar2 == 0x40) {
    uVar3 = 0x2000;
loc_F001AED8:
    uVar7 = uVar7 | uVar3;
  }
  else {
    if (uVar2 < 0x41) {
      uVar3 = 0x20000;
      if (uVar2 != 0) {
        bVar10 = (uVar8 & 0x400) == 0;
        goto loc_F001AEE0;
      }
      goto loc_F001AED8;
    }
    if (uVar2 != 0x80) {
      uVar3 = 0x40000;
      if (uVar2 != 0xc0) {
        bVar10 = (uVar8 & 0x400) == 0;
        goto loc_F001AEE0;
      }
      goto loc_F001AED8;
    }
  }
  bVar10 = (uVar8 & 0x400) == 0;
loc_F001AEE0:
  if (!bVar10) {
    uVar7 = uVar7 | 0x400;
  }
  if ((uVar8 & 0x800) != 0) {
    uVar7 = uVar7 | 0x800;
  }
  if ((uVar9 & 0x1000000) == 0) {
    uVar7 = uVar7 | 0x4000;
  }
  if ((uVar8 & 0x8000) != 0) {
    uVar7 = uVar7 | 0x8000;
  }
  if ((uVar8 & 0x10000) != 0) {
    uVar7 = uVar7 | 0x10000;
  }
  if ((uVar8 & 0x20000) != 0) {
    uVar4 = uVar4 | 1;
  }
  if ((uVar8 & 0x80000) != 0) {
    uVar4 = uVar4 | 4;
  }
  if ((uVar8 & 0x100000) != 0) {
    uVar4 = uVar4 | 8;
  }
  if ((uVar8 & 0x200000) != 0) {
    uVar4 = uVar4 | 0x10;
  }
  if ((uVar9 & 1) != 0) {
    uVar4 = uVar4 | 0x400;
  }
  if ((uVar9 & 0x40000000) == 0) {
    uVar4 = uVar4 | 0x800;
  }
  if ((uVar9 & 0x10000) != 0) {
    uVar6 = uVar6 | 2;
  }
  if ((uVar8 & 4) != 0) {
    uVar6 = uVar6 | 4;
  }
  if ((uVar9 & 0x4000000) != 0) {
    uVar6 = uVar6 | 1;
  }
  if ((uVar9 & 0x40000) != 0) {
    uVar6 = uVar6 | 0x100;
  }
  if ((uVar9 & 0x20000) != 0) {
    uVar6 = uVar6 | 0x200;
  }
  if ((uVar9 & 0x10000000) != 0) {
    uVar6 = uVar6 | 0x400;
  }
  if ((uVar8 & 2) != 0) {
    uVar6 = uVar6 | 0x10;
  }
  if ((uVar8 & 0x20) != 0) {
    uVar6 = uVar6 | 0x800;
  }
  if ((uVar9 & 4) != 0) {
    uVar6 = uVar6 | 0x4000000;
  }
  if ((uVar9 & 0x80000) != 0) {
    uVar6 = uVar6 | 0x8000000;
  }
  *param_2 = uVar4;
  param_2[1] = uVar5 | uVar9 & 0xff00;
  param_2[3] = uVar6 | uVar9 & 0x80500008;
  param_2[2] = uVar7;
  *(undefined *)((int)param_2 + 0x21) = *(undefined *)(iVar1 + 0x49);
  *(undefined *)((int)param_2 + 0x22) = *(undefined *)(iVar1 + 0x4a);
  *(undefined *)((int)param_2 + 0x12) = *(undefined *)(iVar1 + 0x4d);
  *(undefined *)((int)param_2 + 0x13) = *(undefined *)(iVar1 + 0x4e);
  *(undefined *)(param_2 + 5) = *(undefined *)(iVar1 + 0x4f);
  *(undefined *)((int)param_2 + 0x15) = *(undefined *)(iVar1 + 0x50);
  *(undefined *)((int)param_2 + 0x17) = *(undefined *)(iVar1 + 0x51);
  *(undefined *)(param_2 + 6) = *(undefined *)(iVar1 + 0x52);
  *(undefined *)(param_2 + 4) = *(undefined *)(iVar1 + 0x53);
  *(undefined *)((int)param_2 + 0x11) = *(undefined *)(iVar1 + 0x54);
  *(undefined *)((int)param_2 + 0x16) = *(undefined *)(iVar1 + 0x55);
  *(undefined *)((int)param_2 + 0x1f) = *(undefined *)(iVar1 + 0x56);
  *(undefined *)(param_2 + 7) = *(undefined *)(iVar1 + 0x57);
  *(undefined *)((int)param_2 + 0x1e) = *(undefined *)(iVar1 + 0x58);
  *(undefined *)((int)param_2 + 0x1b) = *(undefined *)(iVar1 + 0x59);
  *(undefined *)((int)param_2 + 0x1d) = *(undefined *)(iVar1 + 0x5a);
  *(undefined *)((int)param_2 + 0x19) = *(undefined *)((int)param_1 + 0x15);
  *(undefined *)((int)param_2 + 0x1a) = *(undefined *)((int)param_1 + 0x16);
  *(undefined *)(param_2 + 8) = *(undefined *)(param_1 + 5);
  return CONCAT44(param_2,0x4000000);
}
