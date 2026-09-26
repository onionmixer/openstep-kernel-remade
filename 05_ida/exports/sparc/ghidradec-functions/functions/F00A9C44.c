
/* WARNING: Removing unreachable block (ram,0xf00a9da4) */
/* WARNING: Removing unreachable block (ram,0xf00a9de4) */
/* WARNING: Removing unreachable block (ram,0xf00a9e24) */
/* WARNING: Removing unreachable block (ram,0xf00a9e64) */
/* WARNING: Removing unreachable block (ram,0xf00a9cf8) */
/* WARNING: Removing unreachable block (ram,0xf00a9c64) */
/* WARNING: Removing unreachable block (ram,0xf00a9cbc) */
/* WARNING: Removing unreachable block (ram,0xf00a9e84) */
/* WARNING: Removing unreachable block (ram,0xf00a9e44) */
/* WARNING: Removing unreachable block (ram,0xf00a9e04) */
/* WARNING: Removing unreachable block (ram,0xf00a9dc4) */
/* WARNING: Removing unreachable block (ram,0xf00a9eac) */
/* WARNING: Removing unreachable block (ram,0xf00a9c4c) */

undefined8 _simulate_unimp(int param_1,undefined4 param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 uVar4;
  undefined4 unaff_l5;
  int iVar5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
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
  uVar2 = *(uint *)(param_1 + 4);
  bVar1 = true;
  _fuword();
  if (uVar2 == 0xffffffff) {
    iVar6 = 0;
    goto locret_F00A9EDC;
  }
  _flush_user_windows_to_stack();
  if ((uVar2 & 0xc1f80000) == 0x81d80000) goto loc_F00A9C84;
  if (uVar2 >> 0x1e != 2) {
    iVar6 = 0;
    goto locret_F00A9EDC;
  }
  iVar5 = param_1 + 0xc;
  uVar4 = *(undefined4 *)(param_1 + 0x44);
  iVar6 = iVar5;
  sub_F00A96F0(iVar5,uVar4,uVar2 >> 0xe & 0x1f,(undefined *)((int)register0x00000038 + -0x14));
  if (iVar6 != 0) {
    iVar6 = -1;
    goto locret_F00A9EDC;
  }
  iVar6 = *(int *)((int)register0x00000038 + -0x14);
  if ((uVar2 >> 0xd & 1) == 0) {
    iVar3 = iVar5;
    sub_F00A96F0(iVar5,uVar4,uVar2 & 0x1f,(undefined *)((int)register0x00000038 + -0x14));
    if (iVar3 != 0) {
      iVar6 = -1;
      goto locret_F00A9EDC;
    }
    iVar3 = *(int *)((int)register0x00000038 + -0x14);
  }
  else {
    iVar3 = (int)(uVar2 << 0x13) >> 0x13;
  }
  switch(uVar2 >> 0x13 & 0x3f) {
  case :
    __ip_umul(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
    bVar7 = iVar6 == 1;
    break;
  case :
    __ip_mul(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
    bVar7 = iVar6 == 1;
    break;
  :
    iVar6 = 0;
    goto locret_F00A9EDC;
  case :
    __ip_udiv(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
    goto loc_F00A9E90;
  case :
    __ip_div(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
    goto loc_F00A9E90;
  case :
    __ip_umulcc(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
    bVar7 = iVar6 == 1;
    break;
  case :
    __ip_mulcc(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
    bVar7 = iVar6 == 1;
    break;
  case :
    __ip_udivcc(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
    goto loc_F00A9E90;
  case :
    __ip_divcc(iVar6,iVar3,(undefined *)((int)register0x00000038 + -0x10),param_1 + 0xc,param_1);
loc_F00A9E90:
    bVar1 = false;
    bVar7 = iVar6 == 1;
  }
  if (bVar7) {
    iVar6 = *(int *)((int)register0x00000038 + -0x10);
    sub_F00A975C(iVar6,iVar5,uVar4,uVar2 >> 0x19 & 0x1f);
    if (iVar6 == 0) {
      if (bVar1) {
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)((int)register0x00000038 + -0xc);
      }
loc_F00A9C84:
      iVar6 = 1;
    }
    else {
      iVar6 = -1;
    }
  }
locret_F00A9EDC:
  return CONCAT44(param_2,iVar6);
}
