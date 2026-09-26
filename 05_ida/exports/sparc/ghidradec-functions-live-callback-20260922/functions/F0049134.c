
/* WARNING: Removing unreachable block (ram,0xf0049370) */
/* WARNING: Removing unreachable block (ram,0xf0049340) */
/* WARNING: Removing unreachable block (ram,0xf0049190) */
/* WARNING: Removing unreachable block (ram,0xf0049318) */
/* WARNING: Removing unreachable block (ram,0xf0049204) */
/* WARNING: Removing unreachable block (ram,0xf00491e0) */
/* WARNING: Removing unreachable block (ram,0xf00491c0) */
/* WARNING: Removing unreachable block (ram,0xf00491d0) */
/* WARNING: Removing unreachable block (ram,0xf00491f4) */
/* WARNING: Removing unreachable block (ram,0xf0049304) */
/* WARNING: Removing unreachable block (ram,0xf0049180) */
/* WARNING: Removing unreachable block (ram,0xf0049338) */
/* WARNING: Removing unreachable block (ram,0xf004935c) */
/* WARNING: Removing unreachable block (ram,0xf0049378) */
/* WARNING: Removing unreachable block (ram,0xf0049148) */

undefined8 _blkpref(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 uVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar8;
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
  iVar6 = *(int *)(param_1 + 0x50);
  uVar7 = *(undefined4 *)(iVar6 + 0x5c);
  iVar8 = param_3;
  rem(param_3,uVar7);
  if ((iVar8 == 0) || (iVar8 = *(int *)(param_3 * 4 + param_4 + -4), iVar8 == 0)) {
    if (0xb < param_2) {
      if ((param_3 == 0) || (iVar8 = *(int *)(param_3 * 4 + param_4 + -4), iVar8 == 0)) {
        iVar3 = *(int *)(param_1 + 0x48);
        udiv(iVar3,*(undefined4 *)(iVar6 + 0xb8));
        iVar8 = param_2;
        div(param_2,uVar7);
        uVar5 = iVar3 + iVar8;
      }
      else {
        div(iVar8,*(undefined4 *)(iVar6 + 0xbc));
        uVar5 = iVar8 + 1;
      }
      iVar8 = *(int *)(iVar6 + 0x2c);
      rem(uVar5,iVar8);
      iVar3 = *(int *)(iVar6 + 0xc4);
      div(iVar3,iVar8);
      if ((int)uVar5 < iVar8) {
        bVar4 = (byte)*(undefined4 *)(iVar6 + 0x70);
        iVar1 = (int)uVar5 >> (bVar4 & 0x1f);
        uVar2 = uVar5;
        do {
          if (iVar3 <= *(int *)(*(int *)(iVar1 * 4 + iVar6 + 0x2d8) +
                                (uVar2 & ~*(uint *)(iVar6 + 0x6c)) * 0x10 + 4)) {
            *(uint *)(iVar6 + 0x2d4) = uVar2;
            iVar3 = *(int *)(iVar6 + 0xbc);
            umul(iVar3,uVar2);
            iVar8 = *(int *)(iVar6 + 0x38);
            goto loc_F0049380;
          }
          uVar2 = uVar2 + 1;
          iVar1 = (int)uVar2 >> (bVar4 & 0x1f);
        } while ((int)uVar2 < iVar8);
      }
      uVar2 = 0;
      iVar8 = 0;
      if (uVar5 < 0x80000000) {
        bVar4 = (byte)*(undefined4 *)(iVar6 + 0x70);
        iVar8 = 0 >> (bVar4 & 0x1f);
        do {
          if (iVar3 <= *(int *)(*(int *)(iVar8 * 4 + iVar6 + 0x2d8) +
                                (uVar2 & ~*(uint *)(iVar6 + 0x6c)) * 0x10 + 4)) {
            *(uint *)(iVar6 + 0x2d4) = uVar2;
            iVar3 = *(int *)(iVar6 + 0xbc);
            umul(iVar3,uVar2);
            iVar8 = *(int *)(iVar6 + 0x38);
            goto loc_F0049380;
          }
          uVar2 = uVar2 + 1;
          iVar8 = (int)uVar2 >> (bVar4 & 0x1f);
        } while ((int)uVar2 <= (int)uVar5);
        iVar8 = 0;
      }
      goto locret_F0049384;
    }
    uVar7 = *(undefined4 *)(param_1 + 0x48);
    udiv(uVar7,*(undefined4 *)(iVar6 + 0xb8));
    iVar3 = *(int *)(iVar6 + 0xbc);
    umul(iVar3,uVar7);
    iVar8 = *(int *)(iVar6 + 0x38);
  }
  else {
    iVar3 = *(int *)(iVar6 + 0x58);
    iVar8 = iVar8 + *(int *)(iVar6 + 0x38);
    if (iVar3 < param_3) {
      if (*(int *)(param_4 + (param_3 - iVar3) * 4) +
          (iVar3 << ((byte)*(undefined4 *)(iVar6 + 0x60) & 0x1f)) != iVar8) goto locret_F0049384;
      iVar3 = *(int *)(iVar6 + 0x40);
    }
    else {
      iVar3 = *(int *)(iVar6 + 0x40);
    }
    if (iVar3 == 0) goto locret_F0049384;
    umul(iVar3,*(undefined4 *)(iVar6 + 0x44));
    umul();
    div();
    iVar3 = iVar3 + -1 + *(int *)(iVar6 + 0x38);
    div(iVar3,*(int *)(iVar6 + 0x38));
    umul();
  }
loc_F0049380:
  iVar8 = iVar8 + iVar3;
locret_F0049384:
  return CONCAT44(param_2,iVar8);
}

