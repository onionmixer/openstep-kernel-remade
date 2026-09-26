
/* WARNING: Removing unreachable block (ram,0xf00ace70) */
/* WARNING: Removing unreachable block (ram,0xf00acea8) */
/* WARNING: Removing unreachable block (ram,0xf00acf58) */
/* WARNING: Removing unreachable block (ram,0xf00acd6c) */
/* WARNING: Removing unreachable block (ram,0xf00acd90) */
/* WARNING: Removing unreachable block (ram,0xf00acf84) */
/* WARNING: Removing unreachable block (ram,0xf00aced8) */
/* WARNING: Removing unreachable block (ram,0xf00ace44) */
/* WARNING: Removing unreachable block (ram,0xf00acdc8) */

undefined8 sub_F00ACD30(int param_1,uint *param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  uint uVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar7;
  undefined4 unaff_i1;
  uint uVar8;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  uVar8 = *param_2;
  uVar3 = uVar8 >> 0xe & 0x1f;
  uVar6 = uVar8 >> 0x19;
  uVar7 = uVar8 & 0x1f;
  if ((uVar8 & 0x2000) == 0) {
    _read_iureg(uVar3,param_3,param_4,(undefined *)((int)register0x00000038 + -0xc),param_1);
    if (uVar3 != 0) {
      uVar2 = 6;
      goto locret_F00ACFC4;
    }
    _read_iureg(uVar7,param_3,param_4,(undefined *)((int)register0x00000038 + -0x10),param_1);
    uVar2 = 6;
    if (uVar7 != 0) goto locret_F00ACFC4;
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
  }
  else {
    *(int *)((int)register0x00000038 + -0xc) = (int)(uVar8 << 0x13) >> 0x13;
    _read_iureg(uVar3,param_3,param_4,(undefined *)((int)register0x00000038 + -0x10),param_1);
    uVar2 = 6;
    if (uVar3 != 0) goto locret_F00ACFC4;
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
  }
  *(int *)((int)register0x00000038 + -0xc) = iVar1 + *(int *)((int)register0x00000038 + -0x10);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)((int)register0x00000038 + -0xc);
  switch(uVar8 >> 0x13 & 7) {
  case :
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    __fp_read_word(uVar2,(undefined *)((int)register0x00000038 + -0x14),param_1);
    if (uVar2 != 0) goto locret_F00ACFC4;
    *(undefined4 *)(param_5 + (uVar6 & 0x1f) * 4) = *(undefined4 *)((int)register0x00000038 + -0x14)
    ;
    break;
  case :
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    __fp_read_word(uVar2,(undefined *)((int)register0x00000038 + -0x14),param_1);
    if (uVar2 != 0) goto locret_F00ACFC4;
    *(undefined4 *)(param_5 + 0x80) = *(undefined4 *)((int)register0x00000038 + -0x14);
    break;
  :
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_3 + 4);
    uVar2 = 3;
    goto locret_F00ACFC4;
  case :
    uVar3 = *(uint *)((int)register0x00000038 + -0xc);
    uVar2 = 5;
    if ((uVar3 & 7) != 0) goto locret_F00ACFC4;
    __fp_read_word(uVar3,(undefined *)((int)register0x00000038 + -0x14),param_1);
    uVar2 = uVar3;
    if (uVar3 != 0) goto locret_F00ACFC4;
    iVar5 = (uVar6 & 0x1e) * 4;
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    *(undefined4 *)(param_5 + iVar5) = *(undefined4 *)((int)register0x00000038 + -0x14);
    uVar2 = iVar1 + 4;
    __fp_read_word(uVar2,(undefined *)((int)register0x00000038 + -0x14),param_1);
    if (uVar2 != 0) goto locret_F00ACFC4;
    *(undefined4 *)(iVar5 + param_5 + 4) = *(undefined4 *)((int)register0x00000038 + -0x14);
    break;
  case :
    uVar3 = *(uint *)(param_5 + (uVar6 & 0x1f) * 4);
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    *(uint *)((int)register0x00000038 + -0x14) = uVar3;
    goto loc_F00ACF84;
  case :
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    uVar3 = *(uint *)(param_5 + 0x80) & 0xffcfefff | 0xe0000;
    *(uint *)((int)register0x00000038 + -0x14) = uVar3;
    goto loc_F00ACF84;
  case :
    uVar3 = *(uint *)((int)register0x00000038 + -0xc);
    uVar2 = 5;
    if ((uVar3 & 7) != 0) goto locret_F00ACFC4;
    iVar1 = (uVar6 & 0x1e) * 4;
    uVar4 = *(undefined4 *)(param_5 + iVar1);
    *(undefined4 *)((int)register0x00000038 + -0x14) = uVar4;
    __fp_write_word(uVar3,uVar4,param_1);
    uVar2 = uVar3;
    if (uVar3 != 0) goto locret_F00ACFC4;
    uVar3 = *(uint *)(iVar1 + param_5 + 4);
    *(uint *)((int)register0x00000038 + -0x14) = uVar3;
    uVar2 = *(int *)((int)register0x00000038 + -0xc) + 4;
loc_F00ACF84:
    __fp_write_word(uVar2,uVar3,param_1);
    if (uVar2 != 0) goto locret_F00ACFC4;
  }
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_3 + 8);
  *(int *)(param_3 + 8) = *(int *)(param_3 + 8) + 4;
  uVar2 = 0;
locret_F00ACFC4:
  return CONCAT44(uVar8,uVar2);
}

