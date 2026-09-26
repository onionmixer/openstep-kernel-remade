
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
  div(param_3,0xc);
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

