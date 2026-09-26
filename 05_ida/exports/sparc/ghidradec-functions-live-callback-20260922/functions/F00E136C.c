
undefined8 _check_label(word *param_1,int param_2)

{
  word wVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  word *pwVar5;
  undefined4 unaff_i3;
  uint uVar6;
  undefined4 unaff_i4;
  word *pwVar7;
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
  iVar2 = *(int *)param_1;
  if ((iVar2 == 0x4e655854) || (iVar2 == 0x646c5632)) {
    uVar3 = 0x1c48;
    pwVar7 = param_1 + 0xe23;
  }
  else {
    uVar3 = 0x230;
    if (iVar2 != 0x646c5633) {
      puVar4 = aBadDiskLabelMa;
      goto locret_F00E1470;
    }
    pwVar7 = param_1 + 0x117;
  }
  if (*(int *)(param_1 + 2) == param_2) {
    param_1[2] = 0;
    param_1[3] = 0;
    uVar3 = uVar3 >> 1;
    uVar6 = 0;
    wVar1 = *pwVar7;
    *pwVar7 = 0;
    pwVar5 = param_1;
    while (uVar3 = uVar3 - 1, uVar3 != 0xffffffff) {
      uVar6 = uVar6 + *pwVar5;
      pwVar5 = pwVar5 + 1;
    }
    uVar3 = (uVar6 >> 0x10) + (uVar6 & 0xffff);
    if (0xffff < uVar3) {
      uVar3 = uVar3 - 0xffff;
    }
    if ((uVar3 & 0xffff) == (uint)wVar1) {
      *(int *)(param_1 + 2) = param_2;
      *pwVar7 = wVar1;
      puVar4 = (undefined *)0x0;
    }
    else {
      puVar4 = aLabelChecksumE;
    }
  }
  else {
    puVar4 = aLabelInWrongLo;
  }
locret_F00E1470:
  return CONCAT44(param_2,puVar4);
}

