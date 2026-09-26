
/* WARNING: Removing unreachable block (ram,0xf00be924) */
/* WARNING: Removing unreachable block (ram,0xf00be8d8) */
/* WARNING: Removing unreachable block (ram,0xf00be858) */
/* WARNING: Removing unreachable block (ram,0xf00be7fc) */
/* WARNING: Removing unreachable block (ram,0xf00be78c) */
/* WARNING: Removing unreachable block (ram,0xf00be724) */
/* WARNING: Removing unreachable block (ram,0xf00be6bc) */
/* WARNING: Removing unreachable block (ram,0xf00be6c8) */
/* WARNING: Removing unreachable block (ram,0xf00be758) */
/* WARNING: Removing unreachable block (ram,0xf00be7d4) */
/* WARNING: Removing unreachable block (ram,0xf00be828) */
/* WARNING: Removing unreachable block (ram,0xf00be8a4) */
/* WARNING: Removing unreachable block (ram,0xf00be91c) */
/* WARNING: Removing unreachable block (ram,0xf00be774) */
/* WARNING: Removing unreachable block (ram,0xf00be694) */

undefined8 sub_F00BE688(int param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar7;
  undefined4 unaff_l6;
  undefined4 uVar8;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int iVar9;
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
  iVar7 = *(int *)(param_1 + 0x24);
  uVar8 = *(undefined4 *)(param_1 + 0x28);
  pcVar3 = param_2;
  _strlen();
  if ((pcVar3 == (char *)0x0) || (*(int *)(param_1 + 0x14) < (int)pcVar3)) {
    _IOLog(DAT_f01209d0,pcVar3);
  }
  else {
    sub_F00BDF1C(param_1);
    if (*(int *)(param_1 + 0x40) == 0) {
      uVar4 = *(undefined4 *)(param_1 + 0xc);
    }
    else {
      iVar7 = iVar7 + 2;
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -0x18;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 2;
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 0x18;
      uVar4 = *(undefined4 *)(param_1 + 0xc);
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
    sub_F00BDF90(param_1,uVar4,*(undefined4 *)(param_1 + 0x10),*(int *)(param_1 + 0x14) << 3,0x16,
                 *(undefined4 *)(param_1 + 0x34));
    iVar6 = *(int *)(param_1 + 0x10);
    uVar4 = *(undefined4 *)(param_1 + 0x24);
    *(int *)(param_1 + 0x10) = iVar6 + 6;
    iVar5 = (*(int *)(param_1 + 0x14) - (int)pcVar3) / 2;
    *(int *)(param_1 + 0x28) = iVar5;
    sub_F00BDF1C(param_1);
    cVar1 = *param_2;
    while (cVar2 = *param_2, cVar1 != '\0') {
      param_2 = param_2 + 1;
      sub_F00BE15C(param_1,(int)cVar2);
      cVar1 = *param_2;
    }
    sub_F00BDF1C(param_1);
    iVar9 = 0;
    *(sword *)((int)register0x00000038 + -0xe) =
         (sword)*(undefined4 *)(param_1 + 0x10) + (sword)uVar4 * 0xc;
    *(sword *)((int)register0x00000038 + -0x10) =
         (sword)*(undefined4 *)(param_1 + 0xc) + (sword)iVar5 * 8;
    *(sword *)((int)register0x00000038 + -0xc) = (sword)((int)pcVar3 << 3);
    *(undefined2 *)((int)register0x00000038 + -10) = 0xc;
    _sparcfbInvertRect(0,(undefined *)((int)register0x00000038 + -0x10));
    *(int *)(param_1 + 0x10) = iVar6;
    sub_F00BDF90(param_1,*(int *)(param_1 + 0xc) + -2,iVar6 + -2,*(int *)(param_1 + 0x18) + 4,2,
                 *(undefined4 *)(param_1 + 0x3c));
    sub_F00BDF90(param_1,*(int *)(param_1 + 0xc) + -2,*(int *)(param_1 + 0x10) + 0x13,
                 *(int *)(param_1 + 0x18) + 4,2,*(undefined4 *)(param_1 + 0x38));
    iVar5 = 0x17;
    do {
      iVar6 = iVar9 + -2;
      iVar9 = iVar9 + 1;
      sub_F00BDF90(param_1,*(int *)(param_1 + 0xc) + iVar6,*(int *)(param_1 + 0x10) + iVar6,1,iVar5,
                   *(undefined4 *)(param_1 + 0x3c));
      iVar5 = iVar5 + -2;
    } while (iVar9 < 2);
    param_2 = (char *)0x1;
    do {
      sub_F00BDF90(param_1,param_2 + *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x18) + -1,
                   *(int *)(param_1 + 0x10) - (int)param_2,1,(2 - (int)param_2) * -2 + 0x17,
                   *(undefined4 *)(param_1 + 0x38));
      param_2 = param_2 + 1;
    } while ((int)param_2 < 3);
    sub_F00BDF90(param_1,*(int *)(param_1 + 0xc) + -3,*(int *)(param_1 + 0x10) + 0x15,
                 *(int *)(param_1 + 0x18) + 6,1,*(undefined4 *)(param_1 + 0x34));
    *(undefined4 *)(param_1 + 0x28) = uVar8;
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 0x18;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -2;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -0x18;
    if (iVar7 < 1) {
      sub_F00BE038(param_1);
    }
    else {
      *(int *)(param_1 + 0x24) = iVar7 + -2;
    }
    sub_F00BDF1C(param_1);
    *(undefined4 *)(param_1 + 0x40) = 1;
  }
  return CONCAT44(param_2,param_1);
}

