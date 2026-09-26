
/* WARNING: Removing unreachable block (ram,0xf00f0124) */
/* WARNING: Removing unreachable block (ram,0xf00f0134) */

undefined8 sub_F00F00E4(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined4 unaff_l0;
  uint *puVar3;
  undefined4 unaff_l1;
  uint uVar4;
  uint uVar5;
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
  puVar3 = (uint *)param_1[8];
  uVar4 = *puVar3;
  uVar1 = (puVar3[1] + 1) * 4;
  uVar5 = *param_2;
  if (uVar1 < (uVar4 + 1) * 3 || uVar1 + (uVar4 + 1) * -3 == 0) {
    puVar3[1] = puVar3[1] + 1;
  }
  else {
    if ((param_1[4] & 0x20) == 0) {
      puVar3 = param_1;
      sub_F00EFE48();
      uVar4 = *puVar3;
      uVar1 = puVar3[1];
    }
    else {
      sub_F00F018C(param_1);
      uVar1 = puVar3[1];
    }
    puVar3[1] = uVar1 + 1;
  }
  while( true ) {
    uVar5 = uVar5 & uVar4;
    puVar2 = (uint *)puVar3[uVar5 + 2];
    puVar3[uVar5 + 2] = (uint)param_2;
    if (puVar2 == (uint *)0x0) break;
    uVar5 = uVar5 + 1;
    param_2 = puVar2;
  }
  return CONCAT44(param_2,param_1);
}

