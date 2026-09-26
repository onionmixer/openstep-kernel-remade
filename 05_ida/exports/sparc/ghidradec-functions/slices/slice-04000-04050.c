/* GHIDRADEC_FUNCTION index=4000 start=0xf00be688 */

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
/* GHIDRADEC_FUNCTION index=4001 start=0xf00be93c */

/* WARNING: Removing unreachable block (ram,0xf00be95c) */

undefined8 sub_F00BE93C(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x18);
  if (iVar2 < 0) {
    iVar2 = iVar2 + 7;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  *(int *)(param_1 + 0x14) = iVar2 >> 3;
  .div(uVar1,0xc);
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4002 start=0xf00be970 */

/* WARNING: Removing unreachable block (ram,0xf00beba0) */
/* WARNING: Removing unreachable block (ram,0xf00beb90) */
/* WARNING: Removing unreachable block (ram,0xf00beb44) */
/* WARNING: Removing unreachable block (ram,0xf00beaf4) */
/* WARNING: Removing unreachable block (ram,0xf00beaa8) */
/* WARNING: Removing unreachable block (ram,0xf00bea4c) */
/* WARNING: Removing unreachable block (ram,0xf00bebc8) */
/* WARNING: Removing unreachable block (ram,0xf00bea00) */
/* WARNING: Removing unreachable block (ram,0xf00bebd4) */
/* WARNING: Removing unreachable block (ram,0xf00bea80) */
/* WARNING: Removing unreachable block (ram,0xf00beacc) */
/* WARNING: Removing unreachable block (ram,0xf00beb1c) */
/* WARNING: Removing unreachable block (ram,0xf00beb68) */
/* WARNING: Removing unreachable block (ram,0xf00beb98) */
/* WARNING: Removing unreachable block (ram,0xf00bebac) */
/* WARNING: Removing unreachable block (ram,0xf00be98c) */

undefined8
sub_F00BE970(int *param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar3;
  undefined4 unaff_i2;
  uint uVar4;
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
  if (param_2 < 0) {
    param_2 = param_2 + 7;
  }
  .div(param_3,0xc);
  uVar3 = (param_2 >> 3) * 8;
  uVar4 = param_3 * 0xc;
  uVar1 = *param_1 - 6;
  if (uVar1 <= uVar3 && uVar3 - uVar1 != 0) {
    uVar3 = uVar1;
  }
  uVar1 = param_1[1] - 6;
  if (uVar1 <= uVar4 && uVar4 - uVar1 != 0) {
    uVar4 = uVar1;
  }
  param_1[3] = *param_1 - uVar3 >> 1;
  param_1[6] = uVar3;
  param_1[8] = uVar4;
  param_1[4] = param_1[1] - uVar4 >> 1;
  param_1[3] = param_1[3] & 0xfffffff8;
  sub_F00BE93C(param_1);
  param_1[10] = 0;
  param_1[0x10] = 0;
  if (param_5 == 0) {
    param_1[9] = param_1[7] + -1;
    sub_F00BE688(param_1,param_4);
    sub_F00BE15C(param_1,10);
  }
  else {
    iVar2 = 0;
    if (param_6 != 0) {
      *(sword *)((int)register0x00000038 + -0x18) = (sword)param_1[3] + -10;
      *(sword *)((int)register0x00000038 + -0x16) = (sword)param_1[4] + -10;
      *(sword *)((int)register0x00000038 + -0x14) = (sword)uVar3 + 0x14;
      *(sword *)((int)register0x00000038 + -0x12) = (sword)uVar4 + 0x18;
      _sparcfbSaveRect(0,(undefined *)((int)register0x00000038 + -0x18));
      param_1[0x14] = iVar2;
    }
    param_1[9] = 0;
    param_1[0x10] = 0;
    sub_F00BDF90(param_1,param_1[3] + -3,param_1[4] + -3,uVar3 + 6,1,param_1[0xd]);
    sub_F00BDF90(param_1,param_1[3] + -2,param_1[4] + -2,uVar3 + 4,2,param_1[0xd]);
    sub_F00BDF90(param_1,param_1[3] + -2,param_1[4] + uVar4,uVar3 + 4,2,param_1[0xc]);
    sub_F00BDF90(param_1,param_1[3] + -3,param_1[4] + uVar4 + 2,uVar3 + 6,1,param_1[0xd]);
    sub_F00BDF90(param_1,param_1[3] + -3,param_1[4] + -3,1,uVar4 + 6,param_1[0xd]);
    sub_F00BDF90(param_1,param_1[3] + -2,param_1[4] + -2,2,uVar4 + 4,param_1[0xc]);
    sub_F00BDF90(param_1,param_1[3] + uVar3,param_1[4] + -2,2,uVar4 + 4,param_1[0xc]);
    sub_F00BDF90(param_1,param_1[3] + uVar3 + 2,param_1[4] + -3,1,uVar4 + 6,param_1[0xd]);
    sub_F00BDFFC(param_1);
    sub_F00BDF1C(param_1);
    sub_F00BE688(param_1,param_4);
  }
  return CONCAT44(uVar3,param_1);
}
/* GHIDRADEC_FUNCTION index=4003 start=0xf00bebe4 */

/* WARNING: Removing unreachable block (ram,0xf00bebf8) */
/* WARNING: Removing unreachable block (ram,0xf00bebec) */

undefined8 sub_F00BEBE4(int param_1,undefined4 param_2)

{
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
  _IOFree(*(undefined4 *)(param_1 + 0x1c),0x54);
  _IOFree(param_1,0x20);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4004 start=0xf00bec08 */

/* WARNING: Removing unreachable block (ram,0xf00becfc) */
/* WARNING: Removing unreachable block (ram,0xf00bed18) */
/* WARNING: Removing unreachable block (ram,0xf00beca0) */
/* WARNING: Removing unreachable block (ram,0xf00bece0) */
/* WARNING: Removing unreachable block (ram,0xf00bed24) */
/* WARNING: Removing unreachable block (ram,0xf00bec94) */

undefined8 sub_F00BEC08(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar2;
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
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  puVar2[0xb] = 0x666666;
  puVar2[0xc] = 0xffffff;
  puVar2[0xd] = 0;
  puVar2[0xe] = 0x666666;
  iVar1 = _sparcfbs;
  puVar2[0xf] = 0x999999;
  *puVar2 = *(undefined4 *)(iVar1 + 0x28);
  puVar2[1] = *(undefined4 *)(iVar1 + 0x2c);
  puVar2[0x11] = 0;
  *(undefined *)((int)puVar2 + 0x4a) = 0;
  iVar1 = (int)puVar2 + 2;
  while ((int)puVar2 <= iVar1 + -1) {
    *(undefined *)(iVar1 + 0x47) = 0;
    iVar1 = iVar1 + -1;
  }
  puVar2[0x13] = (int)puVar2 + 0x49;
  if ((param_3 != 0) && (puVar2[2] != 3)) {
    _sparcfbRestoreMode(0);
    sub_F00BE020(puVar2,puVar2[0xb]);
  }
  puVar2[2] = param_2;
  if (param_2 != 2) {
    if (param_2 < 3) {
      if (param_2 == 1) {
        _sparcfbRestoreMode(0);
        sub_F00BE970(puVar2,0x280,0x1e0,param_5,param_4,0);
        goto locret_F00BED2C;
      }
    }
    else if (param_2 == 3) {
      sub_F00BE970(puVar2,0x140,200,param_5,param_4,1);
      goto locret_F00BED2C;
    }
    _panic(DAT_f01209f8);
  }
locret_F00BED2C:
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4005 start=0xf00bed34 */

/* WARNING: Removing unreachable block (ram,0xf00bed60) */
/* WARNING: Removing unreachable block (ram,0xf00bed50) */

undefined8 sub_F00BED34(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (*(int *)(*(int *)(param_1 + 0x1c) + 8) == 3) {
    uVar1 = 0;
    _sparcfbRestoreRect(0,*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x50));
  }
  else {
    _IOLog(DAT_f0120a20);
    uVar1 = 0xffffffff;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=4006 start=0xf00bed74 */

/* WARNING: Removing unreachable block (ram,0xf00bedec) */

undefined8 sub_F00BED74(int param_1,sword *param_2)

{
  sword sVar1;
  sword sVar2;
  sword sVar3;
  undefined4 uVar4;
  int *piVar5;
  word wVar6;
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
  sVar1 = *param_2;
  piVar5 = *(int **)(param_1 + 0x1c);
  *(sword *)((int)register0x00000038 + -0x10) = sVar1;
  sVar2 = param_2[1];
  *(sword *)((int)register0x00000038 + -0xe) = sVar2;
  sVar3 = param_2[2];
  *(sword *)((int)register0x00000038 + -0xc) = sVar3;
  *(sword *)((int)register0x00000038 + -10) = param_2[3];
  wVar6 = sVar1 + (sword)(*piVar5 - 0x46cU >> 1);
  *(word *)((int)register0x00000038 + -0x10) = wVar6;
  uVar4 = 0;
  *(sword *)((int)register0x00000038 + -0xe) = sVar2 + (sword)(piVar5[1] - 0x340U >> 1);
  *(word *)((int)register0x00000038 + -0x10) = wVar6 & 0xfffc;
  *(word *)((int)register0x00000038 + -0xc) = sVar3 + 3U & 0xfffc;
  _sparcfbDrawRect(0,(undefined *)((int)register0x00000038 + -0x10),2,*(undefined4 *)(param_2 + 4));
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=4007 start=0xf00bedfc */

/* WARNING: Removing unreachable block (ram,0xf00beebc) */

sqword sub_F00BEDFC(int param_1,sword *param_2)

{
  sword sVar1;
  sword sVar2;
  sword sVar3;
  int iVar4;
  word wVar5;
  undefined4 uVar6;
  int *piVar7;
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
  sVar1 = *param_2;
  piVar7 = *(int **)(param_1 + 0x1c);
  *(sword *)((int)register0x00000038 + -0x10) = sVar1;
  sVar2 = param_2[1];
  *(sword *)((int)register0x00000038 + -0xe) = sVar2;
  sVar3 = param_2[2];
  *(sword *)((int)register0x00000038 + -0xc) = sVar3;
  *(sword *)((int)register0x00000038 + -10) = param_2[3];
  wVar5 = sVar1 + (sword)(*piVar7 - 0x46cU >> 1);
  *(word *)((int)register0x00000038 + -0x10) = wVar5;
  *(sword *)((int)register0x00000038 + -0xe) = sVar2 + (sword)(piVar7[1] - 0x340U >> 1);
  *(word *)((int)register0x00000038 + -0x10) = wVar5 & 0xfffc;
  *(word *)((int)register0x00000038 + -0xc) = sVar3 + 3U & 0xfffc;
  iVar4 = *(int *)(param_2 + 4);
  if (iVar4 == 1) {
    uVar6 = 0x999999;
  }
  else if (iVar4 < 2) {
    if (iVar4 == 0) {
      uVar6 = 0xffffff;
    }
    else {
      uVar6 = 0;
    }
  }
  else if (iVar4 == 2) {
    uVar6 = 0x666666;
  }
  else {
    uVar6 = 0;
  }
  _sparcfbFillRect(0,(undefined *)((int)register0x00000038 + -0x10),uVar6);
  return ZEXT48(param_2) << 0x20;
}
/* GHIDRADEC_FUNCTION index=4008 start=0xf00beecc */

/* WARNING: Removing unreachable block (ram,0xf00beed8) */

undefined8 sub_F00BEECC(int param_1,undefined4 param_2)

{
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
  sub_F00BE15C(*(undefined4 *)(param_1 + 0x1c),(int)(char)param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4009 start=0xf00beee8 */

undefined8 sub_F00BEEE8(int param_1,undefined2 *param_2)

{
  undefined4 *puVar1;
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
  puVar1 = *(undefined4 **)(param_1 + 0x1c);
  param_2[1] = (sword)puVar1[5];
  *param_2 = (sword)puVar1[7];
  param_2[2] = (sword)*puVar1;
  param_2[3] = (sword)puVar1[1];
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4010 start=0xf00befd0 */

/* WARNING: Removing unreachable block (ram,0xf00befdc) */

undefined8 sub_F00BEFD0(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
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
  uVar1 = _kernel_pmap;
  _pmap_extract(_kernel_pmap,param_2);
  return CONCAT44(param_2,uVar1 >> ((byte)_page_shift & 0x1f));
}
/* GHIDRADEC_FUNCTION index=4011 start=0xf00bf194 */

undefined8 sub_F00BF194(undefined8 *param_1,int param_2)

{
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
  undefined *puVar1;
  undefined4 unaff_i3;
  int iVar2;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  undefined4 auStack_10 [4];
  
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
  puVar1 = (undefined *)((int)register0x00000038 + -8);
  iVar2 = 0;
  *(undefined8 *)((int)register0x00000038 + -0x10) = *param_1;
  do {
    *(undefined4 *)(iVar2 + param_2) = *(undefined4 *)(puVar1 + -8);
    puVar1 = puVar1 + 4;
    iVar2 = iVar2 + 4;
  } while (puVar1 <= (undefined *)((int)register0x00000038 + -4));
  return CONCAT44(param_2,(undefined *)((int)register0x00000038 + -4));
}
/* GHIDRADEC_FUNCTION index=4012 start=0xf00bf1cc */

undefined8 sub_F00BF1CC(int param_1,undefined8 *param_2)

{
  undefined *puVar1;
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
  int iVar2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  undefined4 auStack_10 [4];
  
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
  puVar1 = (undefined *)((int)register0x00000038 + -8);
  iVar2 = 0;
  do {
    *(undefined4 *)(puVar1 + -8) = *(undefined4 *)(iVar2 + param_1);
    puVar1 = puVar1 + 4;
    iVar2 = iVar2 + 4;
  } while (puVar1 <= (undefined *)((int)register0x00000038 + -4));
  *param_2 = *(undefined8 *)((int)register0x00000038 + -0x10);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4013 start=0xf00bf204 */

/* WARNING: Removing unreachable block (ram,0xf00bf270) */
/* WARNING: Removing unreachable block (ram,0xf00bf240) */
/* WARNING: Removing unreachable block (ram,0xf00bf22c) */
/* WARNING: Removing unreachable block (ram,0xf00bf25c) */
/* WARNING: Removing unreachable block (ram,0xf00bf2a0) */
/* WARNING: Removing unreachable block (ram,0xf00bf210) */

undefined8 -[EventSrcPCKeyboard resetKeyboard](int param_1,undefined4 param_2)

{
  undefined7 *puVar1;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
  if (*(int *)(param_1 + 0x128) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x128),paFree);
  }
  puVar1 = paKeymap;
  _objc_msgSend(paKeymap,paAlloc);
  _objc_msgSend();
  *(undefined7 **)(param_1 + 0x128) = puVar1;
  _objc_msgSend();
  *(undefined8 *)(param_1 + 0x168) = 125000000;
  puVar1 = paUnlock;
  *(undefined8 *)(param_1 + 0x170) = 500000000;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),puVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4014 start=0xf00bf2b0 */

/* WARNING: Removing unreachable block (ram,0xf00bf304) */
/* WARNING: Removing unreachable block (ram,0xf00bf2cc) */
/* WARNING: Heritage AFTER dead removal. Example location: o3 : 0xf00bf304 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined8 -[EventSrcPCKeyboard scheduleAutoRepeat](int param_1,undefined4 param_2)

{
  int iVar1;
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
  if (*(char *)(param_1 + 0x154) == '\x01') {
    _ns_untimeout(sub_F00BF3FC,param_1);
    *(undefined *)(param_1 + 0x154) = 0;
    iVar1 = *(int *)(param_1 + 0x160);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x160);
  }
  if ((iVar1 != 0) || (*(int *)(param_1 + 0x164) != 0)) {
    _ns_abstimeout(sub_F00BF3FC,param_1,(int)((qword)*(undefined8 *)(param_1 + 0x160) >> 0x20),
                   (int)*(undefined8 *)(param_1 + 0x160),4);
    *(undefined *)(param_1 + 0x154) = 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4015 start=0xf00bf31c */

/* WARNING: Removing unreachable block (ram,0xf00bf3dc) */
/* WARNING: Removing unreachable block (ram,0xf00bf330) */
/* WARNING: Removing unreachable block (ram,0xf00bf3b4) */
/* WARNING: Removing unreachable block (ram,0xf00bf3ec) */
/* WARNING: Removing unreachable block (ram,0xf00bf320) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00bf3b4 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int -[EventSrcPCKeyboard autoRepeat](void)

{
  int iVar1;
  undefined8 in_o0_1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
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
  
  iVar1 = (int)((qword)in_o0_1 >> 0x20);
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
  _IOGetTimestamp((undefined *)((int)register0x00000038 + -0x18));
  _objc_msgSend();
  if (*(char *)(iVar1 + 0x154) != '\0') {
    *(undefined *)(iVar1 + 0x154) = 0;
    uVar2 = *(uint *)(iVar1 + 0x160);
    *(undefined *)(iVar1 + 0x14e) = 1;
    if ((((uVar2 != 0) || (*(int *)(iVar1 + 0x164) != 0)) &&
        (uVar2 <= *(uint *)((int)register0x00000038 + -0x18))) &&
       ((uVar2 != *(uint *)((int)register0x00000038 + -0x18) ||
        (*(uint *)(iVar1 + 0x164) <= *(uint *)((int)register0x00000038 + -0x14))))) {
      uVar3 = *(undefined8 *)((int)register0x00000038 + -0x18);
      *(undefined8 *)(iVar1 + 0x158) = uVar3;
      _objc_msgSend(iVar1,(int)in_o0_1,*(undefined4 *)(iVar1 + 0x150),(int)uVar3,iVar1 + 0x134);
      uVar2 = (uint)*(undefined8 *)(iVar1 + 0x160);
      uVar4 = (uint)*(undefined8 *)(iVar1 + 0x168);
      *(qword *)(iVar1 + 0x160) =
           CONCAT44((int)((qword)*(undefined8 *)(iVar1 + 0x160) >> 0x20) +
                    (int)((qword)*(undefined8 *)(iVar1 + 0x168) >> 0x20) + (uint)CARRY4(uVar2,uVar4)
                    ,uVar2 + uVar4);
    }
    *(undefined *)(iVar1 + 0x14e) = 0;
    _objc_msgSend(iVar1);
  }
  _objc_msgSend();
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=4016 start=0xf00bf3fc */

/* WARNING: Removing unreachable block (ram,0xf00bf408) */

undefined8 sub_F00BF3FC(undefined4 param_1,undefined4 param_2)

{
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
  _objc_msgSend(param_1,paAutorepeat);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4017 start=0xf00bf418 */

/* WARNING: Removing unreachable block (ram,0xf00bf490) */

undefined8 -[EventSrcPCKeyboard setRepeat:forCode:](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 in_o2_3;
  uint uVar3;
  uint uVar4;
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
  iVar2 = (int)((qword)in_o2_3 >> 0x20);
  if (*(char *)(param_1 + 0x14e) == '\0') {
    if (iVar2 == 10) {
      *(int *)(param_1 + 0x150) = (int)in_o2_3;
      uVar1 = paScheduleautore;
      uVar3 = (uint)*(undefined8 *)(param_1 + 0x170);
      uVar4 = (uint)*(undefined8 *)(param_1 + 0x158);
      *(qword *)(param_1 + 0x160) =
           CONCAT44((int)((qword)*(undefined8 *)(param_1 + 0x170) >> 0x20) +
                    (int)((qword)*(undefined8 *)(param_1 + 0x158) >> 0x20) +
                    (uint)CARRY4(uVar3,uVar4),uVar3 + uVar4);
    }
    else {
      if ((iVar2 != 0xb) || (*(int *)(param_1 + 0x150) != (int)in_o2_3)) goto locret_F00BF498;
      *(undefined4 *)(param_1 + 0x150) = 0xffffffff;
      uVar1 = paScheduleautore;
      *(undefined8 *)(param_1 + 0x160) = 0;
    }
    _objc_msgSend(param_1,uVar1);
  }
locret_F00BF498:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4018 start=0xf00bf4a0 */

/* WARNING: Removing unreachable block (ram,0xf00bf4cc) */
/* WARNING: Removing unreachable block (ram,0xf00bf4d8) */
/* WARNING: Removing unreachable block (ram,0xf00bf4ac) */

undefined8 -[EventSrcPCKeyboard initKeyboard](int param_1,undefined4 param_2)

{
  undefined *puVar1;
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
  puVar1 = aType5keyboard0_0;
  _IOGetObjectForDeviceName(aType5keyboard0_0,param_1 + 300);
  if (puVar1 != (undefined *)0x0) {
    _objc_msgSend(param_1,paStringfromretu,puVar1);
    _IOLog(aInitkeyboardCa,param_1);
    param_1 = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4019 start=0xf00bf4ec */

/* WARNING: Removing unreachable block (ram,0xf00bf544) */
/* WARNING: Removing unreachable block (ram,0xf00bf55c) */
/* WARNING: Removing unreachable block (ram,0xf00bf504) */

undefined8
-[EventSrcPCKeyboard keyboardEvent:flags:keyCode:charCode:charSet:originalCharCode:originalCharSet:]
          (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined8 in_o4_5;
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
  
  uVar1 = (undefined4)((qword)in_o4_5 >> 0x20);
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
  _objc_msgSend(param_1,paOwner_0);
  _objc_msgSend();
  _objc_msgSend(param_1,paSetrepeatForco,param_3,uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4020 start=0xf00bf56c */

/* WARNING: Removing unreachable block (ram,0xf00bf5a4) */
/* WARNING: Removing unreachable block (ram,0xf00bf5c4) */
/* WARNING: Removing unreachable block (ram,0xf00bf578) */

undefined8
-[EventSrcPCKeyboard keyboardSpecialEvent:flags:keyCode:specialty:]
          (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined8 in_o4_5;
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
  _objc_msgSend(param_1,paOwner_0);
  _objc_msgSend();
  if ((int)in_o4_5 != 4) {
    _objc_msgSend(param_1,paSetrepeatForco,param_3,(int)((qword)in_o4_5 >> 0x20));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4021 start=0xf00bf5d8 */

/* WARNING: Removing unreachable block (ram,0xf00bf5f4) */
/* WARNING: Removing unreachable block (ram,0xf00bf5e4) */

undefined8 -[EventSrcPCKeyboard updateEventFlags:](undefined4 param_1,undefined4 param_2)

{
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
  _objc_msgSend(param_1,paOwner_0);
  _objc_msgSend();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4022 start=0xf00bf604 */

undefined8 -[EventSrcPCKeyboard eventFlags](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x144));
}
/* GHIDRADEC_FUNCTION index=4023 start=0xf00bf614 */

undefined8 -[EventSrcPCKeyboard deviceFlags](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,*(undefined4 *)(param_1 + 0x144));
}
/* GHIDRADEC_FUNCTION index=4024 start=0xf00bf624 */

undefined8 -[EventSrcPCKeyboard setDeviceFlags:](int param_1,undefined4 param_2,undefined4 param_3)

{
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
  *(undefined4 *)(param_1 + 0x144) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4025 start=0xf00bf634 */

undefined8 -[EventSrcPCKeyboard alphaLock](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,(int)*(char *)(param_1 + 0x14c));
}
/* GHIDRADEC_FUNCTION index=4026 start=0xf00bf644 */

/* WARNING: Removing unreachable block (ram,0xf00bf65c) */

undefined8 -[EventSrcPCKeyboard setAlphaLock:](int param_1,undefined4 param_2,char param_3)

{
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
  *(char *)(param_1 + 0x14c) = param_3;
  _objc_msgSend(*(undefined4 *)(param_1 + 300),paSetalphalockfe,(int)param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4027 start=0xf00bf66c */

undefined8 -[EventSrcPCKeyboard charKeyActive](int param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,(int)*(char *)(param_1 + 0x14d));
}
/* GHIDRADEC_FUNCTION index=4028 start=0xf00bf67c */

undefined8 -[EventSrcPCKeyboard setCharKeyActive:](int param_1,undefined4 param_2,undefined param_3)

{
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
  *(undefined *)(param_1 + 0x14d) = param_3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4029 start=0xf00bf68c */

/* WARNING: Removing unreachable block (ram,0xf00bf750) */
/* WARNING: Removing unreachable block (ram,0xf00bf760) */
/* WARNING: Removing unreachable block (ram,0xf00bf734) */
/* WARNING: Heritage AFTER dead removal. Example location: o1 : 0xf00bf750 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

int -[EventSrcPCKeyboard dispatchKeyboardEvent:](undefined8 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 in_o0_1;
  undefined8 uVar3;
  undefined4 uVar4;
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
  
  iVar1 = (int)((qword)in_o0_1 >> 0x20);
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
  uVar3 = *param_1;
  *(undefined8 *)(iVar1 + 0x158) = uVar3;
  uVar2 = *(uint *)(param_1 + 1);
  if (uVar2 != 0x7f) {
    if (uVar2 == 99) {
      uVar4 = 2;
    }
    else if (uVar2 < 100) {
      if (uVar2 == 0x13) {
        uVar4 = 0x20;
      }
      else {
        uVar4 = 1;
        if (uVar2 != 0x4c) {
          uVar4 = 0;
        }
      }
    }
    else {
      uVar4 = 8;
      if (uVar2 != 0x78) {
        if (uVar2 < 0x79) {
          uVar4 = 4;
          if (uVar2 != 0x6e) {
            uVar4 = 0;
          }
        }
        else {
          uVar4 = 0x10;
          if (uVar2 != 0x7a) {
            uVar4 = 0;
          }
        }
      }
    }
    *(int *)(iVar1 + 0x148) = (int)((qword)uVar3 >> 0x20);
    _objc_msgSend();
    _objc_msgSend(*(undefined4 *)(iVar1 + 0x128),uVar4,*(undefined4 *)(param_1 + 1),
                  (int)*(char *)((int)param_1 + 0xc),iVar1 + 0x134);
    _objc_msgSend();
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=4030 start=0xf00bf770 */

/* WARNING: Removing unreachable block (ram,0xf00bf7bc) */
/* WARNING: Removing unreachable block (ram,0xf00bf788) */
/* WARNING: Removing unreachable block (ram,0xf00bf798) */
/* WARNING: Removing unreachable block (ram,0xf00bf7c8) */
/* WARNING: Removing unreachable block (ram,0xf00bf77c) */

undefined8 -[EventSrcPCKeyboard relinquishOwnershipRequest:](int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 uVar2;
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
  _objc_msgSend(param_1,paOwnerlock);
  _objc_msgSend();
  iVar1 = param_1;
  _objc_msgSend(param_1,paOwner_0);
  uVar2 = 0xfffffd2b;
  if (iVar1 == 0) {
    *(undefined *)(param_1 + 0x130) = 0;
    uVar2 = 0;
  }
  _objc_msgSend(param_1,paOwnerlock);
  _objc_msgSend();
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=4031 start=0xf00bf7d8 */

/* WARNING: Removing unreachable block (ram,0xf00bf834) */
/* WARNING: Removing unreachable block (ram,0xf00bf80c) */
/* WARNING: Removing unreachable block (ram,0xf00bf81c) */
/* WARNING: Removing unreachable block (ram,0xf00bf848) */
/* WARNING: Removing unreachable block (ram,0xf00bf7e8) */

undefined8 -[EventSrcPCKeyboard canBecomeOwner:](int param_1,undefined4 param_2,int param_3)

{
  undefined5 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
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
  iVar2 = param_3;
  _objc_msgSend(param_3,paBecomeowner,param_1);
  puVar1 = paName;
  if (iVar2 == 0) {
    *(undefined *)(param_1 + 0x130) = 1;
  }
  else {
    iVar3 = param_1;
    _objc_msgSend(param_1,paName);
    _objc_msgSend(param_3,puVar1);
    iVar4 = param_1;
    _objc_msgSend(param_1,paStringfromretu,iVar2);
    _IOLog(aSBecomeownerOf_1,iVar3,param_3,iVar4);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4032 start=0xf00bf864 */

/* WARNING: Removing unreachable block (ram,0xf00bf904) */
/* WARNING: Removing unreachable block (ram,0xf00bf8e0) */
/* WARNING: Removing unreachable block (ram,0xf00bf8b0) */
/* WARNING: Removing unreachable block (ram,0xf00bf890) */
/* WARNING: Removing unreachable block (ram,0xf00bf8c4) */
/* WARNING: Removing unreachable block (ram,0xf00bf8f4) */
/* WARNING: Removing unreachable block (ram,0xf00bf934) */
/* WARNING: Removing unreachable block (ram,0xf00bf870) */

undefined8 -[EventSrcPCKeyboard init](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d58;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  if (*(int *)(param_1 + 0x128) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x128),paFree);
  }
  uVar1 = paKeymap;
  _objc_msgSend(paKeymap,paAlloc);
  _objc_msgSend();
  *(undefined4 *)(param_1 + 0x128) = uVar1;
  _objc_msgSend();
  _objc_msgSend(param_1,paInitkeyboard);
  *(undefined8 *)(param_1 + 0x168) = 125000000;
  uVar1 = paUnlock;
  *(undefined8 *)(param_1 + 0x170) = 500000000;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4033 start=0xf00bf944 */

/* WARNING: Removing unreachable block (ram,0xf00bf9c4) */
/* WARNING: Removing unreachable block (ram,0xf00bf99c) */
/* WARNING: Removing unreachable block (ram,0xf00bf97c) */
/* WARNING: Removing unreachable block (ram,0xf00bf9b4) */
/* WARNING: Removing unreachable block (ram,0xf00bf9e0) */
/* WARNING: Removing unreachable block (ram,0xf00bf964) */

undefined8 +[EventSrcPCKeyboard probe](int param_1,undefined4 param_2)

{
  undefined (*pauVar1) [9];
  undefined7 *puVar2;
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
  if (dword_F0120AE8 == 0) {
    _objc_msgSend(param_1,paAlloc);
    puVar2 = paNxlock;
    dword_F0120AE8 = param_1;
    _objc_msgSend(paNxlock,paNew);
    pauVar1 = paSetname;
    iVar3 = dword_F0120AE8;
    *(undefined7 **)(dword_F0120AE8 + 0x124) = puVar2;
    _objc_msgSend(iVar3,pauVar1,aEventsrcpckeyb_0);
    _objc_msgSend(dword_F0120AE8,paSetdevicekind,aEventsrcpckeyb_1);
    iVar3 = dword_F0120AE8;
    _objc_msgSend(dword_F0120AE8,paInit);
    if (iVar3 == 0) {
      _objc_msgSend(dword_F0120AE8,paFree);
    }
  }
  return CONCAT44(param_2,dword_F0120AE8);
}
/* GHIDRADEC_FUNCTION index=4034 start=0xf00bf9f4 */

/* WARNING: Removing unreachable block (ram,0xf00bfa70) */
/* WARNING: Removing unreachable block (ram,0xf00bfa4c) */
/* WARNING: Removing unreachable block (ram,0xf00bfa2c) */
/* WARNING: Removing unreachable block (ram,0xf00bfa5c) */
/* WARNING: Removing unreachable block (ram,0xf00bfa8c) */
/* WARNING: Removing unreachable block (ram,0xf00bfa04) */

undefined8 -[EventSrcPCKeyboard free](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar3;
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
  uVar3 = *(undefined4 *)(param_1 + 0x124);
  _objc_msgSend(uVar3,paLock);
  dword_F0120AE8 = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  if (*(int *)(param_1 + 0x128) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x128),paFree);
  }
  if (*(int *)(param_1 + 300) != 0) {
    _objc_msgSend(*(int *)(param_1 + 300),paRelinquishowne_0,param_1);
  }
  _objc_msgSend(uVar3,paUnlock);
  uVar1 = paFree;
  _objc_msgSend(uVar3,paFree);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d58;
  _objc_msgSendSuper(puVar2,uVar1);
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4035 start=0xf00bfa9c */

/* WARNING: Removing unreachable block (ram,0xf00bfb5c) */
/* WARNING: Removing unreachable block (ram,0xf00bfc00) */
/* WARNING: Removing unreachable block (ram,0xf00bfba4) */
/* WARNING: Removing unreachable block (ram,0xf00bfb0c) */
/* WARNING: Removing unreachable block (ram,0xf00bfaec) */
/* WARNING: Removing unreachable block (ram,0xf00bfae0) */
/* WARNING: Removing unreachable block (ram,0xf00bfaf8) */
/* WARNING: Removing unreachable block (ram,0xf00bfb84) */
/* WARNING: Removing unreachable block (ram,0xf00bfbc8) */
/* WARNING: Removing unreachable block (ram,0xf00bfb38) */
/* WARNING: Removing unreachable block (ram,0xf00bfb74) */
/* WARNING: Removing unreachable block (ram,0xf00bfab4) */

undefined8
-[EventSrcPCKeyboard getIntValues:forParameter:count:]
          (int param_1,undefined4 param_2,int *param_3,int param_4,uint *param_5)

{
  undefined4 uVar1;
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
  undefined *puVar4;
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
  puVar4 = (undefined *)0xfffffd3e;
  uVar3 = *param_5;
  iVar2 = param_4;
  _strcmp(param_4,aEvsCurrentkeyr);
  if (iVar2 == 0) {
    if (uVar3 < 4) goto locret_F00BFC18;
    *param_5 = 4;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
    sub_F00BF194(param_1 + 0x170,param_3);
    sub_F00BF194(param_1 + 0x168,param_3 + 2);
    uVar1 = *(undefined4 *)(param_1 + 0x124);
  }
  else {
    iVar2 = param_4;
    _strcmp(param_4,aEvsCurrentkeym);
    if (iVar2 != 0) {
      iVar2 = param_4;
      _strcmp(param_4,aEvsEventdevice_0);
      if (iVar2 == 0) {
        *param_5 = 0;
        iVar2 = *(int *)(param_1 + 300);
        _objc_msgSend(iVar2,paInterfaceid);
        *param_3 = iVar2;
        param_3[2] = 1;
        param_3[1] = 0;
        iVar2 = *(int *)(param_1 + 300);
        puVar4 = (undefined *)0x0;
        _objc_msgSend(iVar2,paHandlerid);
        param_3[3] = iVar2;
        *param_5 = 4;
      }
      else {
        *(int *)((int)register0x00000038 + -0x10) = param_1;
        puVar4 = (undefined *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d58;
        _objc_msgSendSuper(puVar4,paGetintvaluesFo_0,param_3,param_4,param_5);
        if (puVar4 == (undefined *)0xfffffd39) {
          puVar4 = (undefined *)0xfffffd3e;
        }
      }
      goto locret_F00BFC18;
    }
    if (uVar3 == 0) goto locret_F00BFC18;
    *param_5 = 1;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
    iVar2 = *(int *)(param_1 + 0x128);
    if (iVar2 == 0) {
      *param_3 = 0;
    }
    else {
      _objc_msgSend(iVar2,paKeymappingleng);
      *param_3 = iVar2;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x124);
  }
  puVar4 = (undefined *)0x0;
  _objc_msgSend(uVar1,paUnlock);
locret_F00BFC18:
  return CONCAT44(param_2,puVar4);
}
/* GHIDRADEC_FUNCTION index=4036 start=0xf00bfc20 */

/* WARNING: Removing unreachable block (ram,0xf00bfcc4) */
/* WARNING: Removing unreachable block (ram,0xf00bfc9c) */
/* WARNING: Removing unreachable block (ram,0xf00bfc50) */
/* WARNING: Removing unreachable block (ram,0xf00bfc6c) */
/* WARNING: Removing unreachable block (ram,0xf00bfca8) */
/* WARNING: Removing unreachable block (ram,0xf00bfcf0) */
/* WARNING: Removing unreachable block (ram,0xf00bfc34) */

undefined8
-[EventSrcPCKeyboard getCharValues:forParameter:count:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,uint *param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
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
  uVar5 = *param_5;
  iVar1 = param_4;
  _strcmp(param_4,aEvsCurrentkeym_0);
  if (iVar1 == 0) {
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
    uVar4 = *(uint *)(param_1 + 0x128);
    if (uVar4 == 0) {
      puVar3 = (undefined *)0xfffffd27;
      uVar2 = *(undefined4 *)(param_1 + 0x124);
    }
    else {
      _objc_msgSend(uVar4,paKeymappingleng);
      if (uVar5 <= uVar4) {
        uVar4 = uVar5;
      }
      *param_5 = uVar4;
      puVar3 = (undefined *)0x0;
      _objc_msgSend(*(undefined4 *)(param_1 + 0x128),paKeymapping,0);
      _bcopy();
      uVar2 = *(undefined4 *)(param_1 + 0x124);
    }
    _objc_msgSend(uVar2,paUnlock);
  }
  else {
    *(int *)((int)register0x00000038 + -0x10) = param_1;
    puVar3 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d58;
    _objc_msgSendSuper(puVar3,paGetcharvaluesF_0,param_3,param_4,param_5);
    if (puVar3 == (undefined *)0xfffffd39) {
      puVar3 = (undefined *)0xfffffd3e;
    }
  }
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=4037 start=0xf00bfd10 */

/* WARNING: Removing unreachable block (ram,0xf00bfe80) */
/* WARNING: Removing unreachable block (ram,0xf00bfddc) */
/* WARNING: Removing unreachable block (ram,0xf00bfdac) */
/* WARNING: Removing unreachable block (ram,0xf00bfd48) */
/* WARNING: Removing unreachable block (ram,0xf00bfd54) */
/* WARNING: Removing unreachable block (ram,0xf00bfdd0) */
/* WARNING: Removing unreachable block (ram,0xf00bfe34) */
/* WARNING: Removing unreachable block (ram,0xf00bfe54) */
/* WARNING: Removing unreachable block (ram,0xf00bfd24) */

undefined8
-[EventSrcPCKeyboard setIntValues:forParameter:count:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  undefined (*pauVar2) [14];
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar4;
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
  puVar3 = (undefined *)0xfffffd3e;
  iVar1 = param_4;
  _strcmp(param_4,aEvsSetkeyrepea);
  if (iVar1 == 0) {
    if (param_5 != 2) goto locret_F00BFE98;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
    sub_F00BF1CC(param_3,param_1 + 0x168);
    bVar4 = *(int *)(param_1 + 0x168) != 0;
    pauVar2 = paUnlock;
    if (bVar4) {
      param_1 = *(int *)(param_1 + 0x124);
    }
    else if ((bVar4) || (*(uint *)(param_1 + 0x16c) < 16700000)) {
      *(undefined8 *)(param_1 + 0x168) = 16700000;
      param_1 = *(int *)(param_1 + 0x124);
      pauVar2 = paUnlock;
    }
    else {
      param_1 = *(int *)(param_1 + 0x124);
    }
  }
  else {
    iVar1 = param_4;
    _strcmp(param_4,aEvsSetinitialk);
    if (iVar1 == 0) {
      if (param_5 != 2) goto locret_F00BFE98;
      _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
      sub_F00BF1CC(param_3,param_1 + 0x170);
      bVar4 = *(int *)(param_1 + 0x170) != 0;
      pauVar2 = paUnlock;
      if (bVar4) {
        param_1 = *(int *)(param_1 + 0x124);
      }
      else if ((bVar4) || (*(uint *)(param_1 + 0x174) < 16700000)) {
        *(undefined8 *)(param_1 + 0x170) = 16700000;
        param_1 = *(int *)(param_1 + 0x124);
        pauVar2 = paUnlock;
      }
      else {
        param_1 = *(int *)(param_1 + 0x124);
      }
    }
    else {
      iVar1 = param_4;
      _strcmp(param_4,aEvsResetkeyboa_0);
      pauVar2 = paResetkeyboard;
      if (iVar1 != 0) {
        *(int *)((int)register0x00000038 + -0x10) = param_1;
        puVar3 = (undefined *)((int)register0x00000038 + -0x10);
        *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d58;
        _objc_msgSendSuper(puVar3,paSetintvaluesFo_0,param_3,param_4,param_5);
        if (puVar3 == (undefined *)0xfffffd39) {
          puVar3 = (undefined *)0xfffffd3e;
        }
        goto locret_F00BFE98;
      }
    }
  }
  puVar3 = (undefined *)0x0;
  _objc_msgSend(param_1,pauVar2);
locret_F00BFE98:
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=4038 start=0xf00bfea0 */

/* WARNING: Removing unreachable block (ram,0xf00bff70) */
/* WARNING: Removing unreachable block (ram,0xf00bff3c) */
/* WARNING: Removing unreachable block (ram,0xf00bff00) */
/* WARNING: Removing unreachable block (ram,0xf00bfed8) */
/* WARNING: Removing unreachable block (ram,0xf00bfec4) */
/* WARNING: Removing unreachable block (ram,0xf00bfee8) */
/* WARNING: Removing unreachable block (ram,0xf00bff18) */
/* WARNING: Removing unreachable block (ram,0xf00bff54) */
/* WARNING: Removing unreachable block (ram,0xf00bff9c) */
/* WARNING: Removing unreachable block (ram,0xf00bfeb0) */

undefined8
-[EventSrcPCKeyboard setCharValues:forParameter:count:]
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar4;
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
  puVar3 = (undefined *)0xfffffd3e;
  iVar1 = param_4;
  _strcmp(param_4,aEvsSetkeymappi);
  if (iVar1 == 0) {
    uVar2 = param_5;
    _IOMalloc(param_5);
    _bcopy(param_3,uVar2,param_5);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
    iVar4 = *(int *)(param_1 + 0x128);
    iVar1 = paKeymap;
    _objc_msgSend(paKeymap,paAlloc);
    _objc_msgSend();
    *(int *)(param_1 + 0x128) = iVar1;
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x128) = iVar4;
      uVar2 = *(undefined4 *)(param_1 + 0x124);
    }
    else {
      if (iVar4 != 0) {
        _objc_msgSend(iVar4,paFree);
      }
      puVar3 = (undefined *)0x0;
      _objc_msgSend(*(undefined4 *)(param_1 + 0x128),paSetdelegate,param_1);
      uVar2 = *(undefined4 *)(param_1 + 0x124);
    }
    _objc_msgSend(uVar2,paUnlock);
  }
  else {
    *(int *)((int)register0x00000038 + -0x10) = param_1;
    puVar3 = (undefined *)((int)register0x00000038 + -0x10);
    *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d58;
    _objc_msgSendSuper(puVar3,paSetcharvaluesF_0,param_3,param_4,param_5);
    if (puVar3 == (undefined *)0xfffffd39) {
      puVar3 = (undefined *)0xfffffd3e;
    }
  }
  return CONCAT44(param_2,puVar3);
}
/* GHIDRADEC_FUNCTION index=4039 start=0xf00bffbc */

/* WARNING: Removing unreachable block (ram,0xf00c0058) */
/* WARNING: Removing unreachable block (ram,0xf00c0020) */
/* WARNING: Removing unreachable block (ram,0xf00bfff4) */
/* WARNING: Removing unreachable block (ram,0xf00c0000) */
/* WARNING: Removing unreachable block (ram,0xf00c003c) */
/* WARNING: Removing unreachable block (ram,0xf00c0064) */
/* WARNING: Removing unreachable block (ram,0xf00bffe0) */

undefined8
-[EventSrcPCKeyboard relinquishOwnership:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined *puVar2;
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
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  uVar1 = paRelinquishowne_0;
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d58;
  _objc_msgSendSuper(puVar2,paRelinquishowne_0,param_3);
  _objc_msgSend(param_1,paOwnerlock);
  _objc_msgSend();
  _wserver_on = 0;
  if ((puVar2 == (undefined *)0x0) &&
     (iVar3 = param_1, _objc_msgSend(param_1,paOwner_0), iVar3 == 0)) {
    iVar3 = *(int *)(param_1 + 300);
    _objc_msgSend(iVar3,uVar1,param_1);
    if (iVar3 == 0) {
      *(undefined *)(param_1 + 0x130) = 0;
    }
  }
  _objc_msgSend(param_1,paOwnerlock);
  _objc_msgSend();
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=4040 start=0xf00c0074 */

/* WARNING: Removing unreachable block (ram,0xf00c0154) */
/* WARNING: Removing unreachable block (ram,0xf00c011c) */
/* WARNING: Removing unreachable block (ram,0xf00c00bc) */
/* WARNING: Removing unreachable block (ram,0xf00c00b0) */
/* WARNING: Removing unreachable block (ram,0xf00c00e8) */
/* WARNING: Removing unreachable block (ram,0xf00c0144) */
/* WARNING: Removing unreachable block (ram,0xf00c0160) */
/* WARNING: Removing unreachable block (ram,0xf00c009c) */

undefined8 -[EventSrcPCKeyboard becomeOwner:](int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined *puVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined *puVar5;
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
  
  uVar2 = uRamf0141d58;
  uVar1 = paBecomeowner;
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
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar5 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d58;
  puVar4 = puVar5;
  _objc_msgSendSuper(puVar5,paBecomeowner,param_3);
  _objc_msgSend(param_1,paOwnerlock);
  _objc_msgSend();
  if ((puVar4 == (undefined *)0x0) && (*(char *)(param_1 + 0x130) == '\0')) {
    iVar3 = *(int *)(param_1 + 300);
    _objc_msgSend(iVar3,uVar1,param_1);
    if (iVar3 == 0) {
      *(undefined *)(param_1 + 0x130) = 1;
      _wserver_on = 1;
    }
    else {
      iVar3 = *(int *)(param_1 + 300);
      _objc_msgSend(iVar3,paDesireownershi,param_1);
      if (iVar3 != 0) {
        *(int *)((int)register0x00000038 + -0x10) = param_1;
        *(undefined4 *)((int)register0x00000038 + -0xc) = uVar2;
        puVar4 = (undefined *)0xfffffd2b;
        _objc_msgSendSuper(puVar5,paRelinquishowne_0,param_3);
      }
    }
  }
  _objc_msgSend(param_1,paOwnerlock);
  _objc_msgSend();
  return CONCAT44(param_2,puVar4);
}
/* GHIDRADEC_FUNCTION index=4041 start=0xf00c0170 */

/* WARNING: Removing unreachable block (ram,0xf00c0228) */
/* WARNING: Removing unreachable block (ram,0xf00c01c8) */
/* WARNING: Removing unreachable block (ram,0xf00c0238) */
/* WARNING: Removing unreachable block (ram,0xf00c01bc) */

undefined8
-[EventSrcPCPointer scalePointerInX:andY:over:atRes:]
          (int param_1,undefined4 param_2,int *param_3,int *param_4,int param_5,undefined4 param_6)

{
  undefined4 unaff_l0;
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l1;
  int iVar5;
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
  int iVar6;
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
  iVar6 = *param_3;
  iVar5 = *param_4;
  iVar4 = iVar6;
  if (iVar6 < 0) {
    iVar4 = -iVar6;
  }
  iVar1 = iVar5;
  if (iVar5 < 0) {
    iVar1 = -iVar5;
  }
  if (param_5 == 0) {
    param_5 = 2;
  }
  uVar2 = (iVar4 + iVar1) * 0x3e;
  .umul(param_6,param_5);
  .udiv(uVar2,param_6);
  if ((uint)(int)*(sword *)(param_1 + 0x13c) < uVar2) {
    iVar1 = 1;
    iVar4 = param_1;
    if (*(int *)(param_1 + 0x138) < 2) {
      iVar3 = 0;
    }
    else {
      do {
        iVar3 = iVar1;
        if (uVar2 <= (uint)(int)*(sword *)(iVar4 + 0x13e)) {
          iVar3 = iVar3 + -1;
          break;
        }
        iVar1 = iVar3 + 1;
        iVar4 = iVar4 + 2;
      } while (iVar3 + 1 < *(int *)(param_1 + 0x138));
    }
    iVar4 = iVar3 * 2 + param_1;
    .umul(iVar6,(int)*(sword *)(iVar4 + 0x164));
    *param_3 = iVar6;
    .umul(iVar5,(int)*(sword *)(iVar4 + 0x164));
    *param_4 = iVar5;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4042 start=0xf00c024c */

/* WARNING: Removing unreachable block (ram,0xf00c02b0) */
/* WARNING: Removing unreachable block (ram,0xf00c0264) */

undefined8
-[EventSrcPCPointer setPointerScaling:data:]
          (int param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
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
  if (0x14 < param_3) {
    param_3 = 0x14;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
  uVar2 = 0;
  *(uint *)(param_1 + 0x138) = param_3;
  iVar1 = param_1;
  if (param_3 != 0) {
    do {
      uVar2 = uVar2 + 1;
      *(sword *)(iVar1 + 0x13c) = (sword)*param_4;
      *(sword *)(iVar1 + 0x164) = (sword)param_4[1];
      param_4 = param_4 + 2;
      iVar1 = iVar1 + 2;
    } while (uVar2 < param_3);
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paUnlock);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4043 start=0xf00c02c0 */

/* WARNING: Removing unreachable block (ram,0xf00c0334) */
/* WARNING: Removing unreachable block (ram,0xf00c02cc) */

undefined8
-[EventSrcPCPointer pointerScaling:data:](int param_1,undefined4 param_2,uint *param_3,int *param_4)

{
  undefined4 uVar1;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
  if (*(uint *)(param_1 + 0x138) < *param_3) {
    *param_3 = *(uint *)(param_1 + 0x138);
  }
  uVar3 = 0;
  iVar2 = param_1;
  if (*param_3 == 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x124);
  }
  else {
    do {
      uVar3 = uVar3 + 1;
      *param_4 = (int)*(sword *)(iVar2 + 0x13c);
      param_4[1] = (int)*(sword *)(iVar2 + 0x164);
      param_4 = param_4 + 2;
      iVar2 = iVar2 + 2;
    } while (uVar3 < *param_3);
    uVar1 = *(undefined4 *)(param_1 + 0x124);
  }
  _objc_msgSend(uVar1,paUnlock);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4044 start=0xf00c0344 */

/* WARNING: Removing unreachable block (ram,0xf00c03c4) */
/* WARNING: Removing unreachable block (ram,0xf00c0384) */
/* WARNING: Removing unreachable block (ram,0xf00c03b4) */
/* WARNING: Removing unreachable block (ram,0xf00c03a4) */
/* WARNING: Removing unreachable block (ram,0xf00c0354) */

undefined8 -[EventSrcPCPointer initPointer](int param_1,undefined4 param_2)

{
  undefined (*pauVar1) [16];
  undefined (*pauVar2) [12];
  undefined *puVar3;
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
  pauVar2 = paPcpointer;
  _objc_msgSend(paPcpointer,paActivepointerd);
  *(undefined (**) [12])(param_1 + 0x128) = pauVar2;
  pauVar1 = paSeteventtarget;
  if (pauVar2 == (undefined (*) [12])0x0) {
    puVar3 = aInitpointerCan;
  }
  else {
    _objc_msgSend();
    if (((uint)pauVar2 & 0xff) != 0) {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x128),pauVar1,param_1);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x128),pauVar1,param_1);
      goto locret_F00C03CC;
    }
    puVar3 = aInitpointerPcp;
  }
  param_1 = 0;
  _IOLog(puVar3);
locret_F00C03CC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4045 start=0xf00c03d4 */

/* WARNING: Removing unreachable block (ram,0xf00c03f4) */
/* WARNING: Removing unreachable block (ram,0xf00c0410) */
/* WARNING: Removing unreachable block (ram,0xf00c03e0) */

undefined8 -[EventSrcPCPointer resetPointer](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
  uVar1 = paUnlock;
  *(undefined4 *)(param_1 + 0x134) = 0;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),uVar1);
  _objc_msgSend(param_1,paSetpointerscal,5,unk_F00F91EC);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4046 start=0xf00c0420 */

/* WARNING: Removing unreachable block (ram,0xf00c055c) */
/* WARNING: Removing unreachable block (ram,0xf00c04f0) */
/* WARNING: Removing unreachable block (ram,0xf00c04c0) */
/* WARNING: Removing unreachable block (ram,0xf00c054c) */
/* WARNING: Removing unreachable block (ram,0xf00c0580) */
/* WARNING: Removing unreachable block (ram,0xf00c042c) */
/* WARNING: Heritage AFTER dead removal. Example location: o3 : 0xf00c04f0 */
/* WARNING: Restarted to delay deadcode elimination for space: register */

undefined8 -[EventSrcPCPointer dispatchPointerEvent:](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined8 *puVar3;
  undefined8 in_o2_3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  uint uVar7;
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
  
  puVar3 = (undefined8 *)((qword)in_o2_3 >> 0x20);
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
  uVar2 = *(uint *)(puVar3 + 1);
  uVar7 = uVar2 >> 0x16 & 4;
  if ((uVar2 & 0x2000000) != 0) {
    uVar7 = uVar7 | 1;
  }
  *(int *)((int)register0x00000038 + -0x14) = (int)(uVar2 << 8) >> 0x18;
  uVar4 = *puVar3;
  *(int *)((int)register0x00000038 + -0x18) = (*(int *)(puVar3 + 1) << 0x10) >> 0x18;
  uVar5 = (uint)uVar4;
  uVar2 = (int)((qword)uVar4 >> 0x20) << 8 | uVar5 >> 0x18;
  if (*(int *)(param_1 + 300) == 0) {
    uVar6 = 2;
  }
  else {
    uVar6 = uVar2 - *(int *)(param_1 + 300);
  }
  if ((uVar6 < 2) && (dword_F0120CC8 != 0)) {
    dword_F0120CC8 = 0;
    _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paUnlock);
    goto locret_F00C0588;
  }
  dword_F0120CC8 = dword_F0120CC8 + 1;
  _objc_msgSend(param_1,paScalepointerin,(undefined *)((int)register0x00000038 + -0x14),uVar5,uVar6,
                *(undefined4 *)(param_1 + 0x130));
  *(uint *)(param_1 + 300) = uVar2;
  if (*(int *)(param_1 + 0x134) == 0) {
    if (uVar7 == 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x124);
    }
    else {
loc_F00C0544:
      uVar1 = *(undefined4 *)(param_1 + 0x124);
    }
  }
  else {
    if (*(int *)(param_1 + 0x134) == 1) goto loc_F00C0544;
    uVar1 = *(undefined4 *)(param_1 + 0x124);
  }
  _objc_msgSend(uVar1,paUnlock);
  _objc_msgSend(param_1,paOwner_0);
  _objc_msgSend();
locret_F00C0588:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=4047 start=0xf00c0590 */

/* WARNING: Removing unreachable block (ram,0xf00c0628) */
/* WARNING: Removing unreachable block (ram,0xf00c0600) */
/* WARNING: Removing unreachable block (ram,0xf00c05c8) */
/* WARNING: Removing unreachable block (ram,0xf00c05e8) */
/* WARNING: Removing unreachable block (ram,0xf00c0614) */
/* WARNING: Removing unreachable block (ram,0xf00c0644) */
/* WARNING: Removing unreachable block (ram,0xf00c05b4) */

undefined8 -[EventSrcPCPointer init](int param_1,undefined4 param_2)

{
  undefined (*pauVar1) [12];
  int iVar2;
  undefined4 uVar3;
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
  iVar2 = *(int *)(param_1 + 0x124);
  if (iVar2 == 0) {
    uVar3 = paNxlock;
    _objc_msgSend(paNxlock,paNew);
    *(undefined4 *)(param_1 + 0x124) = uVar3;
    iVar2 = *(int *)(param_1 + 0x124);
  }
  _objc_msgSend(iVar2,paLock);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d80;
  _objc_msgSendSuper((undefined *)((int)register0x00000038 + -0x10),paInit);
  *(undefined4 *)(param_1 + 0x128) = 0;
  pauVar1 = paInitpointer;
  *(undefined4 *)(param_1 + 0x134) = 0;
  iVar2 = param_1;
  _objc_msgSend(param_1,pauVar1);
  uVar3 = *(undefined4 *)(param_1 + 0x128);
  _objc_msgSend(uVar3,paGetresolution);
  *(undefined4 *)(param_1 + 0x130) = uVar3;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paUnlock);
  _objc_msgSend(param_1,paSetpointerscal,5,unk_F00F91EC);
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=4048 start=0xf00c0654 */

/* WARNING: Removing unreachable block (ram,0xf00c06b4) */
/* WARNING: Removing unreachable block (ram,0xf00c068c) */
/* WARNING: Removing unreachable block (ram,0xf00c06a4) */
/* WARNING: Removing unreachable block (ram,0xf00c06d0) */
/* WARNING: Removing unreachable block (ram,0xf00c0674) */

undefined8 +[EventSrcPCPointer probe](int param_1,undefined4 param_2)

{
  int iVar1;
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
  if (dword_F0120C50 == 0) {
    _objc_msgSend(param_1,paAlloc);
    dword_F0120C50 = param_1;
    _objc_msgSend();
    _objc_msgSend(dword_F0120C50,paSetdevicekind,aEventsrcpcpoin_1);
    iVar1 = dword_F0120C50;
    _objc_msgSend(dword_F0120C50,paInit);
    if (iVar1 == 0) {
      _objc_msgSend(dword_F0120C50,paFree);
    }
  }
  return CONCAT44(param_2,dword_F0120C50);
}
/* GHIDRADEC_FUNCTION index=4049 start=0xf00c06e4 */

/* WARNING: Removing unreachable block (ram,0xf00c0740) */
/* WARNING: Removing unreachable block (ram,0xf00c071c) */
/* WARNING: Removing unreachable block (ram,0xf00c072c) */
/* WARNING: Removing unreachable block (ram,0xf00c075c) */
/* WARNING: Removing unreachable block (ram,0xf00c06f0) */

undefined8 -[EventSrcPCPointer free](int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar3;
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
  _objc_msgSend(*(undefined4 *)(param_1 + 0x124),paLock);
  uVar3 = *(undefined4 *)(param_1 + 0x124);
  dword_F0120C50 = 0;
  *(undefined4 *)(param_1 + 0x124) = 0;
  if (*(int *)(param_1 + 0x128) != 0) {
    _objc_msgSend(*(int *)(param_1 + 0x128),paSeteventtarget,0);
  }
  _objc_msgSend(uVar3,paUnlock);
  uVar1 = paFree;
  _objc_msgSend(uVar3,paFree);
  *(int *)((int)register0x00000038 + -0x10) = param_1;
  puVar2 = (undefined *)((int)register0x00000038 + -0x10);
  *(undefined4 *)((int)register0x00000038 + -0xc) = uRamf0141d80;
  _objc_msgSendSuper(puVar2,uVar1);
  return CONCAT44(param_2,puVar2);
}

