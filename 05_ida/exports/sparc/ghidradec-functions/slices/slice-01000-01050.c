/* GHIDRADEC_FUNCTION index=1000 start=0xf0049134 */

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
  .rem(param_3,uVar7);
  if ((iVar8 == 0) || (iVar8 = *(int *)(param_3 * 4 + param_4 + -4), iVar8 == 0)) {
    if (0xb < param_2) {
      if ((param_3 == 0) || (iVar8 = *(int *)(param_3 * 4 + param_4 + -4), iVar8 == 0)) {
        iVar3 = *(int *)(param_1 + 0x48);
        .udiv(iVar3,*(undefined4 *)(iVar6 + 0xb8));
        iVar8 = param_2;
        .div(param_2,uVar7);
        uVar5 = iVar3 + iVar8;
      }
      else {
        .div(iVar8,*(undefined4 *)(iVar6 + 0xbc));
        uVar5 = iVar8 + 1;
      }
      iVar8 = *(int *)(iVar6 + 0x2c);
      .rem(uVar5,iVar8);
      iVar3 = *(int *)(iVar6 + 0xc4);
      .div(iVar3,iVar8);
      if ((int)uVar5 < iVar8) {
        bVar4 = (byte)*(undefined4 *)(iVar6 + 0x70);
        iVar1 = (int)uVar5 >> (bVar4 & 0x1f);
        uVar2 = uVar5;
        do {
          if (iVar3 <= *(int *)(*(int *)(iVar1 * 4 + iVar6 + 0x2d8) +
                                (uVar2 & ~*(uint *)(iVar6 + 0x6c)) * 0x10 + 4)) {
            *(uint *)(iVar6 + 0x2d4) = uVar2;
            iVar3 = *(int *)(iVar6 + 0xbc);
            .umul(iVar3,uVar2);
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
            .umul(iVar3,uVar2);
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
    .udiv(uVar7,*(undefined4 *)(iVar6 + 0xb8));
    iVar3 = *(int *)(iVar6 + 0xbc);
    .umul(iVar3,uVar7);
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
    .umul(iVar3,*(undefined4 *)(iVar6 + 0x44));
    .umul();
    .div();
    iVar3 = iVar3 + -1 + *(int *)(iVar6 + 0x38);
    .div(iVar3,*(int *)(iVar6 + 0x38));
    .umul();
  }
loc_F0049380:
  iVar8 = iVar8 + iVar3;
locret_F0049384:
  return CONCAT44(param_2,iVar8);
}
/* GHIDRADEC_FUNCTION index=1001 start=0xf004938c */

/* WARNING: Removing unreachable block (ram,0xf004941c) */

undefined8 _hashalloc(int param_1,int param_2,undefined4 param_3,undefined4 param_4,code *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  iVar3 = *(int *)(param_1 + 0x50);
  iVar1 = param_1;
  (*param_5)(param_1,param_2,param_3,param_4);
  iVar2 = param_2;
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar3 + 0x2c);
    iVar4 = 1;
    if (1 < iVar1) {
      iVar2 = param_2 + 1;
      while( true ) {
        if (iVar1 <= iVar2) {
          iVar2 = iVar2 - iVar1;
        }
        iVar1 = param_1;
        (*param_5)(param_1,iVar2,0,param_4);
        iVar4 = iVar4 * 2;
        if (iVar1 != 0) goto locret_F0049474;
        iVar1 = *(int *)(iVar3 + 0x2c);
        if (iVar1 <= iVar4) break;
        iVar2 = iVar2 + iVar4;
      }
    }
    iVar2 = param_2 + 2;
    iVar1 = *(int *)(iVar3 + 0x2c);
    iVar4 = 2;
    .rem(iVar2,iVar1);
    if (2 < iVar1) {
      do {
        iVar1 = param_1;
        (*param_5)(param_1,iVar2,0,param_4);
        iVar2 = iVar2 + 1;
        if (iVar1 != 0) goto locret_F0049474;
        if (iVar2 == *(int *)(iVar3 + 0x2c)) {
          iVar2 = 0;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(iVar3 + 0x2c));
    }
    iVar1 = 0;
  }
locret_F0049474:
  return CONCAT44(iVar2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1002 start=0xf004947c */

/* WARNING: Removing unreachable block (ram,0xf0049734) */
/* WARNING: Removing unreachable block (ram,0xf0049574) */
/* WARNING: Removing unreachable block (ram,0xf004950c) */
/* WARNING: Removing unreachable block (ram,0xf0049530) */
/* WARNING: Removing unreachable block (ram,0xf0049588) */
/* WARNING: Removing unreachable block (ram,0xf0049564) */
/* WARNING: Removing unreachable block (ram,0xf00494f4) */

undefined8 _fragextend(int param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar7;
  int iVar8;
  undefined4 unaff_l3;
  uint uVar9;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  byte bVar11;
  int iVar10;
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
  iVar8 = *(int *)(param_1 + 0x50);
  bVar11 = (byte)*(undefined4 *)(iVar8 + 0x54);
  iVar10 = param_5 >> (bVar11 & 0x1f);
  if (param_5 - param_4 >> (bVar11 & 0x1f) <=
      *(int *)(*(int *)(((int)param_2 >> ((byte)*(undefined4 *)(iVar8 + 0x70) & 0x1f)) * 4 + iVar8 +
                       0x2d8) + (param_2 & ~*(uint *)(iVar8 + 0x6c)) * 0x10 + 0xc)) {
    uVar4 = *(int *)(iVar8 + 0x38) - 1;
    uVar9 = param_3 & uVar4;
    if ((int)((param_3 + iVar10) - 1 & uVar4) < (int)uVar9) {
      param_3 = 0;
      goto locret_F0049740;
    }
    iVar2 = *(int *)(iVar8 + 0xbc);
    puVar7 = *(uint **)(param_1 + 0x40);
    .umul(iVar2,param_2);
    iVar5 = *(int *)(iVar8 + 0x18);
    .umul(iVar5,param_2 & ~*(uint *)(iVar8 + 0x1c));
    _bread(puVar7,iVar2 + iVar5 + *(int *)(iVar8 + 0xc) <<
                  ((byte)*(undefined4 *)(iVar8 + 100) & 0x1f),*(undefined4 *)(iVar8 + 0xa0));
    uVar4 = puVar7[8];
    if (((*puVar7 & 4) == 0) && (*(int *)(uVar4 + 0x3d4) == 0x90255)) {
      _getthetime((undefined *)((int)register0x00000038 + -0x10));
      *(undefined4 *)(uVar4 + 8) = *(undefined4 *)((int)register0x00000038 + -0x10);
      uVar3 = param_3;
      .rem(param_3,*(undefined4 *)(iVar8 + 0xbc));
      iVar2 = param_4 >> ((byte)*(undefined4 *)(iVar8 + 0x54) & 0x1f);
      do {
        if (iVar10 <= iVar2) {
          iVar2 = iVar10;
          goto joined_r0xf00495f4;
        }
        iVar6 = uVar3 + iVar2;
        iVar5 = iVar6;
        if (iVar6 < 0) {
          iVar5 = iVar6 + 7;
        }
        iVar2 = iVar2 + 1;
      } while (((int)*(char *)((iVar5 >> 3) + uVar4 + 0x3d8) >>
                ((char)iVar6 + (char)(iVar5 >> 3) * -8 & 0x1fU) & 1U) != 0);
    }
    _brelse(puVar7);
  }
  param_3 = 0;
  goto locret_F0049740;
joined_r0xf00495f4:
  if ((int)(*(int *)(iVar8 + 0x38) - uVar9) <= iVar2) goto loc_F0049648;
  iVar6 = uVar3 + iVar2;
  iVar5 = iVar6;
  if (iVar6 < 0) {
    iVar5 = iVar6 + 7;
  }
  if (((int)*(char *)((iVar5 >> 3) + uVar4 + 0x3d8) >>
       ((char)iVar6 + (char)(iVar5 >> 3) * -8 & 0x1fU) & 1U) == 0) {
    bVar11 = (byte)*(undefined4 *)(iVar8 + 0x54);
    goto loc_F004964C;
  }
  iVar2 = iVar2 + 1;
  goto joined_r0xf00495f4;
loc_F0049648:
  bVar11 = (byte)*(undefined4 *)(iVar8 + 0x54);
loc_F004964C:
  iVar5 = (iVar2 - (param_4 >> (bVar11 & 0x1f))) * 4 + uVar4;
  *(int *)(iVar5 + 0x34) = *(int *)(iVar5 + 0x34) + -1;
  if (iVar2 != iVar10) {
    iVar2 = (iVar2 - iVar10) * 4 + uVar4;
    *(int *)(iVar2 + 0x34) = *(int *)(iVar2 + 0x34) + 1;
  }
  param_4 = param_4 >> ((byte)*(undefined4 *)(iVar8 + 0x54) & 0x1f);
  if (param_4 < iVar10) {
    do {
      iVar5 = uVar3 + param_4;
      iVar2 = iVar5;
      if (iVar5 < 0) {
        iVar2 = iVar5 + 7;
      }
      iVar6 = (iVar2 >> 3) + uVar4;
      *(byte *)(iVar6 + 0x3d8) =
           *(byte *)(iVar6 + 0x3d8) & ~(byte)(1 << ((char)iVar5 + (char)(iVar2 >> 3) * -8 & 0x1fU));
      *(int *)(uVar4 + 0x24) = *(int *)(uVar4 + 0x24) + -1;
      param_4 = param_4 + 1;
      *(int *)(iVar8 + 0xcc) = *(int *)(iVar8 + 0xcc) + -1;
      iVar2 = *(int *)(((int)param_2 >> ((byte)*(undefined4 *)(iVar8 + 0x70) & 0x1f)) * 4 + iVar8 +
                      0x2d8) + (param_2 & ~*(uint *)(iVar8 + 0x6c)) * 0x10;
      *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + -1;
    } while (param_4 < iVar10);
    cVar1 = *(char *)(iVar8 + 0xd0);
  }
  else {
    cVar1 = *(char *)(iVar8 + 0xd0);
  }
  *(char *)(iVar8 + 0xd0) = cVar1 + '\x01';
  _bdwrite(puVar7);
locret_F0049740:
  return CONCAT44(param_2,param_3);
}
/* GHIDRADEC_FUNCTION index=1003 start=0xf0049748 */

/* WARNING: Removing unreachable block (ram,0xf00499b4) */
/* WARNING: Removing unreachable block (ram,0xf00498d0) */
/* WARNING: Removing unreachable block (ram,0xf0049ac4) */
/* WARNING: Removing unreachable block (ram,0xf0049864) */
/* WARNING: Removing unreachable block (ram,0xf0049830) */
/* WARNING: Removing unreachable block (ram,0xf00497b8) */
/* WARNING: Removing unreachable block (ram,0xf00497dc) */
/* WARNING: Removing unreachable block (ram,0xf0049858) */
/* WARNING: Removing unreachable block (ram,0xf00499c8) */
/* WARNING: Removing unreachable block (ram,0xf0049ad0) */
/* WARNING: Removing unreachable block (ram,0xf00498dc) */
/* WARNING: Removing unreachable block (ram,0xf00499dc) */
/* WARNING: Removing unreachable block (ram,0xf00497a0) */

undefined8 _alloccg(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined4 unaff_l1;
  uint *puVar8;
  int iVar9;
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
  iVar9 = *(int *)(param_1 + 0x50);
  if (*(int *)(*(int *)(((int)param_2 >> ((byte)*(undefined4 *)(iVar9 + 0x70) & 0x1f)) * 4 + iVar9 +
                       0x2d8) + (param_2 & ~*(uint *)(iVar9 + 0x6c)) * 0x10 + 4) == 0) {
    if (param_4 == *(int *)(iVar9 + 0x30)) {
      iVar9 = 0;
      goto locret_F0049ADC;
    }
    iVar1 = *(int *)(iVar9 + 0xbc);
  }
  else {
    iVar1 = *(int *)(iVar9 + 0xbc);
  }
  puVar8 = *(uint **)(param_1 + 0x40);
  .umul(iVar1,param_2);
  iVar4 = *(int *)(iVar9 + 0x18);
  .umul(iVar4,param_2 & ~*(uint *)(iVar9 + 0x1c));
  _bread(puVar8,iVar1 + iVar4 + *(int *)(iVar9 + 0xc) << ((byte)*(undefined4 *)(iVar9 + 100) & 0x1f)
         ,*(undefined4 *)(iVar9 + 0xa0));
  uVar7 = puVar8[8];
  if ((((*puVar8 & 4) == 0) && (*(int *)(uVar7 + 0x3d4) == 0x90255)) &&
     ((*(int *)(uVar7 + 0x1c) != 0 || (param_4 != *(int *)(iVar9 + 0x30))))) {
    _getthetime((undefined *)((int)register0x00000038 + -0x10));
    *(undefined4 *)(uVar7 + 8) = *(undefined4 *)((int)register0x00000038 + -0x10);
    if (param_4 == *(int *)(iVar9 + 0x30)) {
      _alloccgblk(iVar9,uVar7,param_3);
      _bdwrite(puVar8);
      goto locret_F0049ADC;
    }
    param_4 = param_4 >> ((byte)*(undefined4 *)(iVar9 + 0x54) & 0x1f);
    iVar1 = param_4;
    if (param_4 < *(int *)(iVar9 + 0x38)) {
      iVar4 = param_4 * 4 + uVar7;
      do {
        if (*(int *)(iVar4 + 0x34) != 0) {
          iVar4 = *(int *)(iVar9 + 0x38);
          goto loc_F00498B0;
        }
        iVar1 = iVar1 + 1;
        iVar4 = iVar4 + 4;
      } while (iVar1 < *(int *)(iVar9 + 0x38));
    }
    iVar4 = *(int *)(iVar9 + 0x38);
loc_F00498B0:
    if (iVar1 == iVar4) {
      if (*(int *)(uVar7 + 0x1c) != 0) {
        iVar1 = iVar9;
        _alloccgblk(iVar9,uVar7,param_3);
        iVar4 = iVar1;
        .rem();
        iVar6 = param_4;
        if (param_4 < *(int *)(iVar9 + 0x38)) {
          do {
            iVar3 = iVar4 + iVar6;
            iVar2 = iVar3;
            if (iVar3 < 0) {
              iVar2 = iVar3 + 7;
            }
            iVar5 = (iVar2 >> 3) + uVar7;
            *(byte *)(iVar5 + 0x3d8) =
                 *(byte *)(iVar5 + 0x3d8) |
                 (byte)(1 << ((char)iVar3 + (char)(iVar2 >> 3) * -8 & 0x1fU));
            iVar6 = iVar6 + 1;
          } while (iVar6 < *(int *)(iVar9 + 0x38));
        }
        param_4 = *(int *)(iVar9 + 0x38) - param_4;
        *(int *)(uVar7 + 0x24) = *(int *)(uVar7 + 0x24) + param_4;
        *(int *)(iVar9 + 0xcc) = *(int *)(iVar9 + 0xcc) + param_4;
        iVar4 = *(int *)(((int)param_2 >> ((byte)*(undefined4 *)(iVar9 + 0x70) & 0x1f)) * 4 + iVar9
                        + 0x2d8) + (param_2 & ~*(uint *)(iVar9 + 0x6c)) * 0x10;
        *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + param_4;
        iVar4 = param_4 * 4 + uVar7;
        *(char *)(iVar9 + 0xd0) = *(char *)(iVar9 + 0xd0) + '\x01';
        *(int *)(iVar4 + 0x34) = *(int *)(iVar4 + 0x34) + 1;
        _bdwrite(puVar8);
        iVar9 = iVar1;
        goto locret_F0049ADC;
      }
    }
    else {
      iVar4 = iVar9;
      _mapsearch(iVar9,uVar7,param_3,iVar1);
      iVar6 = 0;
      if (-1 < iVar4) {
        if (param_4 < 1) {
          iVar6 = *(int *)(uVar7 + 0x24);
        }
        else {
          do {
            iVar3 = iVar4 + iVar6;
            iVar2 = iVar3;
            if (iVar3 < 0) {
              iVar2 = iVar3 + 7;
            }
            iVar6 = iVar6 + 1;
            iVar5 = (iVar2 >> 3) + uVar7;
            *(byte *)(iVar5 + 0x3d8) =
                 *(byte *)(iVar5 + 0x3d8) &
                 ~(byte)(1 << ((char)iVar3 + (char)(iVar2 >> 3) * -8 & 0x1fU));
          } while (iVar6 < param_4);
          iVar6 = *(int *)(uVar7 + 0x24);
        }
        *(int *)(uVar7 + 0x24) = iVar6 - param_4;
        *(int *)(iVar9 + 0xcc) = *(int *)(iVar9 + 0xcc) - param_4;
        iVar6 = *(int *)(((int)param_2 >> ((byte)*(undefined4 *)(iVar9 + 0x70) & 0x1f)) * 4 + iVar9
                        + 0x2d8) + (param_2 & ~*(uint *)(iVar9 + 0x6c)) * 0x10;
        *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) - param_4;
        iVar6 = iVar1 * 4 + uVar7;
        *(char *)(iVar9 + 0xd0) = *(char *)(iVar9 + 0xd0) + '\x01';
        *(int *)(iVar6 + 0x34) = *(int *)(iVar6 + 0x34) + -1;
        if (param_4 != iVar1) {
          iVar1 = (iVar1 - param_4) * 4 + uVar7;
          *(int *)(iVar1 + 0x34) = *(int *)(iVar1 + 0x34) + 1;
        }
        _bdwrite(puVar8);
        uVar7 = param_2;
        .umul(param_2,*(undefined4 *)(iVar9 + 0xbc));
        iVar9 = uVar7 + iVar4;
        goto locret_F0049ADC;
      }
    }
  }
  _brelse(puVar8);
  iVar9 = 0;
locret_F0049ADC:
  return CONCAT44(param_2,iVar9);
}
/* GHIDRADEC_FUNCTION index=1004 start=0xf0049ae4 */

/* WARNING: Removing unreachable block (ram,0xf0049e0c) */
/* WARNING: Removing unreachable block (ram,0xf0049df4) */
/* WARNING: Removing unreachable block (ram,0xf0049dcc) */
/* WARNING: Removing unreachable block (ram,0xf0049d48) */
/* WARNING: Removing unreachable block (ram,0xf0049b84) */
/* WARNING: Removing unreachable block (ram,0xf0049d28) */
/* WARNING: Removing unreachable block (ram,0xf0049cbc) */
/* WARNING: Removing unreachable block (ram,0xf0049c7c) */
/* WARNING: Removing unreachable block (ram,0xf0049c5c) */
/* WARNING: Removing unreachable block (ram,0xf0049bbc) */
/* WARNING: Removing unreachable block (ram,0xf0049b4c) */
/* WARNING: Removing unreachable block (ram,0xf0049b20) */
/* WARNING: Removing unreachable block (ram,0xf0049b3c) */
/* WARNING: Removing unreachable block (ram,0xf0049bb0) */
/* WARNING: Removing unreachable block (ram,0xf0049bc8) */
/* WARNING: Removing unreachable block (ram,0xf0049c6c) */
/* WARNING: Removing unreachable block (ram,0xf0049cb0) */
/* WARNING: Removing unreachable block (ram,0xf0049cdc) */
/* WARNING: Removing unreachable block (ram,0xf0049d34) */
/* WARNING: Removing unreachable block (ram,0xf0049b94) */
/* WARNING: Removing unreachable block (ram,0xf0049d74) */
/* WARNING: Removing unreachable block (ram,0xf0049ddc) */
/* WARNING: Removing unreachable block (ram,0xf0049e00) */
/* WARNING: Removing unreachable block (ram,0xf0049e4c) */
/* WARNING: Removing unreachable block (ram,0xf0049b08) */

undefined8 _alloccgblk(uint param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
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
  if (param_3 == 0) {
    uVar2 = *(uint *)(param_2 + 0x28);
loc_F0049D40:
    param_3 = param_1;
    _mapsearch(param_1,param_2,uVar2,*(undefined4 *)(param_1 + 0x38));
    if ((int)param_3 < 0) {
      iVar6 = 0;
      goto locret_F0049E58;
    }
    *(uint *)(param_2 + 0x28) = param_3;
  }
  else {
    param_3 = param_3 & -*(int *)(param_1 + 0x38);
    .rem(param_3,*(undefined4 *)(param_1 + 0xbc));
    uVar2 = param_1;
    _isblock(param_1,param_2 + 0x3d8,(int)param_3 >> ((byte)*(undefined4 *)(param_1 + 0x60) & 0x1f))
    ;
    if (uVar2 == 0) {
      iVar7 = *(int *)(param_1 + 0x7c);
      uVar1 = param_3;
      .umul(param_3,iVar7);
      iVar6 = *(int *)(param_1 + 0xac);
      uVar5 = uVar1;
      .div();
      uVar2 = param_3;
      if (*(int *)(uVar5 * 4 + param_2 + 0x54) != 0) {
        if (*(int *)(param_1 + 0x358) == 0) {
          .umul(iVar6,uVar5);
          uVar2 = iVar6 + -1 + iVar7;
          .div(uVar2,iVar7);
        }
        else {
          iVar8 = param_2 + uVar5 * 0x10 + 0xd4;
          .rem(uVar1,iVar6);
          uVar9 = *(undefined4 *)(param_1 + 0xa8);
          .rem();
          iVar7 = uVar1 << 3;
          .div(iVar7,uVar9);
          iVar6 = iVar7;
          if (iVar7 < 8) {
            iVar3 = iVar7 << 1;
            do {
              if (0 < *(sword *)(iVar3 + iVar8)) break;
              iVar6 = iVar6 + 1;
              iVar3 = iVar3 + 2;
            } while (iVar6 < 8);
          }
          iVar3 = iVar6 << 1;
          if (iVar6 == 8) {
            iVar6 = 0;
            iVar3 = 0;
            if (0 < iVar7) {
              iVar4 = 0;
              do {
                iVar3 = iVar6 << 1;
                if (0 < *(sword *)(iVar4 + iVar8)) goto loc_F0049C48;
                iVar6 = iVar6 + 1;
                iVar4 = iVar4 + 2;
              } while (iVar6 < iVar7);
              iVar3 = iVar6 * 2;
            }
          }
loc_F0049C48:
          if (0 < *(sword *)(iVar8 + iVar3)) {
            uVar1 = uVar5;
            .rem(uVar5,*(undefined4 *)(param_1 + 0x358));
            iVar7 = uVar5 - uVar1;
            .umul(iVar7,*(undefined4 *)(param_1 + 0xac));
            .div();
            iVar3 = iVar3 + uVar1 * 0x10 + param_1;
            if (*(sword *)(iVar3 + 0x35c) == -1) {
              _printf(aPosDIDFsS,uVar1,iVar6,param_1 + 0xd4);
              _panic(aAlloccgblkCylG);
            }
            iVar6 = (int)*(sword *)(iVar3 + 0x35c);
            while( true ) {
              uVar5 = param_1;
              _isblock(param_1,param_2 + 0x3d8,iVar7 + iVar6);
              if (uVar5 != 0) break;
              uVar5 = (uint)*(byte *)(param_1 + iVar6 + 0x560);
              if ((uVar5 == 0) || (0x1a9cU - iVar6 < uVar5)) {
                _printf(aPosDIDFsS_0,uVar1,iVar6,param_1 + 0xd4);
                _panic(aAlloccgblkCanT);
                goto loc_F0049D40;
              }
              iVar6 = iVar6 + uVar5;
            }
            param_3 = iVar7 + iVar6 << ((byte)*(undefined4 *)(param_1 + 0x60) & 0x1f);
            goto loc_F0049D68;
          }
        }
      }
      goto loc_F0049D40;
    }
  }
loc_F0049D68:
  _clrblock(param_1,param_2 + 0x3d8,(int)param_3 >> ((byte)*(undefined4 *)(param_1 + 0x60) & 0x1f));
  *(int *)(param_2 + 0x1c) = *(int *)(param_2 + 0x1c) + -1;
  *(int *)(param_1 + 0xc4) = *(int *)(param_1 + 0xc4) + -1;
  iVar6 = *(int *)(((int)*(uint *)(param_2 + 0xc) >> ((byte)*(undefined4 *)(param_1 + 0x70) & 0x1f))
                   * 4 + param_1 + 0x2d8) +
          (*(uint *)(param_2 + 0xc) & ~*(uint *)(param_1 + 0x6c)) * 0x10;
  *(int *)(iVar6 + 4) = *(int *)(iVar6 + 4) + -1;
  uVar2 = param_3;
  .umul(param_3,*(undefined4 *)(param_1 + 0x7c));
  uVar9 = *(undefined4 *)(param_1 + 0xac);
  uVar1 = uVar2;
  .div();
  .rem(uVar2,uVar9);
  uVar9 = *(undefined4 *)(param_1 + 0xa8);
  .rem();
  iVar6 = uVar2 << 3;
  .div(iVar6,uVar9);
  iVar6 = iVar6 * 2 + uVar1 * 0x10 + param_2;
  *(sword *)(iVar6 + 0xd4) = *(sword *)(iVar6 + 0xd4) + -1;
  iVar6 = uVar1 * 4 + param_2;
  *(int *)(iVar6 + 0x54) = *(int *)(iVar6 + 0x54) + -1;
  *(char *)(param_1 + 0xd0) = *(char *)(param_1 + 0xd0) + '\x01';
  iVar6 = *(int *)(param_2 + 0xc);
  .umul(iVar6,*(undefined4 *)(param_1 + 0xbc));
  iVar6 = iVar6 + param_3;
locret_F0049E58:
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=1005 start=0xf0049e60 */

/* WARNING: Removing unreachable block (ram,0xf004a158) */
/* WARNING: Removing unreachable block (ram,0xf004a064) */
/* WARNING: Removing unreachable block (ram,0xf004a018) */
/* WARNING: Removing unreachable block (ram,0xf0049fd0) */
/* WARNING: Removing unreachable block (ram,0xf0049f40) */
/* WARNING: Removing unreachable block (ram,0xf0049ee4) */
/* WARNING: Removing unreachable block (ram,0xf0049ec0) */
/* WARNING: Removing unreachable block (ram,0xf0049f28) */
/* WARNING: Removing unreachable block (ram,0xf0049f5c) */
/* WARNING: Removing unreachable block (ram,0xf0049ff4) */
/* WARNING: Removing unreachable block (ram,0xf004a024) */
/* WARNING: Removing unreachable block (ram,0xf004a070) */
/* WARNING: Removing unreachable block (ram,0xf004a164) */
/* WARNING: Removing unreachable block (ram,0xf0049ea8) */

undefined8 _ialloccg(int param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar6;
  uint uVar7;
  int iVar8;
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
  iVar8 = *(int *)(param_1 + 0x50);
  if (*(int *)(*(int *)(((int)param_2 >> ((byte)*(undefined4 *)(iVar8 + 0x70) & 0x1f)) * 4 + iVar8 +
                       0x2d8) + (param_2 & ~*(uint *)(iVar8 + 0x6c)) * 0x10 + 8) == 0) {
    param_3 = 0;
    goto locret_F004A170;
  }
  iVar2 = *(int *)(iVar8 + 0xbc);
  puVar6 = *(uint **)(param_1 + 0x40);
  .umul(iVar2,param_2);
  iVar5 = *(int *)(iVar8 + 0x18);
  .umul(iVar5,param_2 & ~*(uint *)(iVar8 + 0x1c));
  _bread(puVar6,iVar2 + iVar5 + *(int *)(iVar8 + 0xc) << ((byte)*(undefined4 *)(iVar8 + 100) & 0x1f)
         ,*(undefined4 *)(iVar8 + 0xa0));
  uVar7 = puVar6[8];
  if ((((*puVar6 & 4) != 0) || (*(int *)(uVar7 + 0x3d4) != 0x90255)) ||
     (*(int *)(uVar7 + 0x20) == 0)) {
    _brelse(puVar6);
    param_3 = 0;
    goto locret_F004A170;
  }
  _getthetime((undefined *)((int)register0x00000038 + -0x10));
  *(undefined4 *)(uVar7 + 8) = *(undefined4 *)((int)register0x00000038 + -0x10);
  if (param_3 == 0) {
loc_F0049F94:
    iVar5 = *(int *)(uVar7 + 0x30);
    iVar2 = iVar5;
    if (iVar5 < 0) {
      iVar2 = iVar5 + 7;
    }
    iVar5 = *(int *)(iVar8 + 0xb8) - iVar5;
    iVar3 = iVar5 + 7;
    iVar2 = iVar2 >> 3;
    if (iVar3 < 0) {
      iVar3 = iVar5 + 0xe;
    }
    iVar5 = 0xff;
    _skpc(0xff,iVar3 >> 3,uVar7 + iVar2 + 0x2d4);
    iVar3 = iVar2 + (iVar3 >> 3);
    if (iVar5 == 0) {
      iVar3 = iVar2 + 1;
      iVar5 = 0xff;
      _skpc(0xff,iVar3,uVar7 + 0x2d4);
      if (iVar5 == 0) {
        _printf(aCgSIrotorDFsS,param_2,*(undefined4 *)(uVar7 + 0x30),iVar8 + 0xd4);
        _panic(aIalloccgMapCor);
      }
    }
    param_3 = (iVar3 - iVar5) * 8;
    uVar4 = 1;
    do {
      uVar1 = (int)*(char *)(uVar7 + (iVar3 - iVar5) + 0x2d4) & uVar4;
      uVar4 = uVar4 * 2;
      if (uVar1 == 0) {
        *(int *)(uVar7 + 0x30) = param_3;
        goto loc_F004A07C;
      }
      param_3 = param_3 + 1;
    } while ((int)uVar4 < 0x100);
    _printf(aFsS,iVar8 + 0xd4);
    _panic(aIalloccgBlockN);
  }
  else {
    .rem(param_3,*(undefined4 *)(iVar8 + 0xb8));
    iVar2 = param_3;
    if (param_3 < 0) {
      iVar2 = param_3 + 7;
    }
    if (((int)*(char *)((iVar2 >> 3) + uVar7 + 0x2d4) >>
         ((char)param_3 + (char)(iVar2 >> 3) * -8 & 0x1fU) & 1U) != 0) goto loc_F0049F94;
  }
loc_F004A07C:
  iVar2 = param_3;
  if (param_3 < 0) {
    iVar2 = param_3 + 7;
  }
  iVar5 = (iVar2 >> 3) + uVar7;
  *(byte *)(iVar5 + 0x2d4) =
       *(byte *)(iVar5 + 0x2d4) | (byte)(1 << ((char)param_3 + (char)(iVar2 >> 3) * -8 & 0x1fU));
  *(int *)(uVar7 + 0x20) = *(int *)(uVar7 + 0x20) + -1;
  *(int *)(iVar8 + 200) = *(int *)(iVar8 + 200) + -1;
  iVar2 = *(int *)(((int)param_2 >> ((byte)*(undefined4 *)(iVar8 + 0x70) & 0x1f)) * 4 + iVar8 +
                  0x2d8) + (param_2 & ~*(uint *)(iVar8 + 0x6c)) * 0x10;
  *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + -1;
  *(char *)(iVar8 + 0xd0) = *(char *)(iVar8 + 0xd0) + '\x01';
  if ((param_4 & 0xf000) == 0x4000) {
    *(int *)(uVar7 + 0x18) = *(int *)(uVar7 + 0x18) + 1;
    *(int *)(iVar8 + 0xc0) = *(int *)(iVar8 + 0xc0) + 1;
    iVar5 = *(int *)(((int)param_2 >> ((byte)*(undefined4 *)(iVar8 + 0x70) & 0x1f)) * 4 + iVar8 +
                    0x2d8);
    iVar2 = (param_2 & ~*(uint *)(iVar8 + 0x6c)) * 0x10;
    *(int *)(iVar5 + iVar2) = *(int *)(iVar5 + iVar2) + 1;
  }
  _bdwrite(puVar6);
  uVar7 = param_2;
  .umul(param_2,*(undefined4 *)(iVar8 + 0xb8));
  param_3 = uVar7 + param_3;
locret_F004A170:
  return CONCAT44(param_2,param_3);
}
/* GHIDRADEC_FUNCTION index=1006 start=0xf004a178 */

/* WARNING: Removing unreachable block (ram,0xf004a61c) */
/* WARNING: Removing unreachable block (ram,0xf004a5d4) */
/* WARNING: Removing unreachable block (ram,0xf004a5b0) */
/* WARNING: Removing unreachable block (ram,0xf004a300) */
/* WARNING: Removing unreachable block (ram,0xf004a2e0) */
/* WARNING: Removing unreachable block (ram,0xf004a4e8) */
/* WARNING: Removing unreachable block (ram,0xf004a420) */
/* WARNING: Removing unreachable block (ram,0xf004a3ac) */
/* WARNING: Removing unreachable block (ram,0xf004a284) */
/* WARNING: Removing unreachable block (ram,0xf004a240) */
/* WARNING: Removing unreachable block (ram,0xf004a200) */
/* WARNING: Removing unreachable block (ram,0xf004a1d4) */
/* WARNING: Removing unreachable block (ram,0xf004a1b8) */
/* WARNING: Removing unreachable block (ram,0xf004a1c4) */
/* WARNING: Removing unreachable block (ram,0xf004a1f0) */
/* WARNING: Removing unreachable block (ram,0xf004a218) */
/* WARNING: Removing unreachable block (ram,0xf004a278) */
/* WARNING: Removing unreachable block (ram,0xf004a298) */
/* WARNING: Removing unreachable block (ram,0xf004a418) */
/* WARNING: Removing unreachable block (ram,0xf004a4d4) */
/* WARNING: Removing unreachable block (ram,0xf004a2c0) */
/* WARNING: Removing unreachable block (ram,0xf004a2ec) */
/* WARNING: Removing unreachable block (ram,0xf004a5a0) */
/* WARNING: Removing unreachable block (ram,0xf004a5c8) */
/* WARNING: Removing unreachable block (ram,0xf004a5e0) */
/* WARNING: Removing unreachable block (ram,0xf004a658) */
/* WARNING: Removing unreachable block (ram,0xf004a1ac) */

undefined8 _free_block(int param_1,uint param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 unaff_l0;
  int iVar9;
  undefined4 unaff_l1;
  int iVar10;
  int iVar11;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  byte bVar12;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar13;
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
  iVar11 = *(int *)(param_1 + 0x50);
  if ((*(uint *)(iVar11 + 0x30) < param_3) || ((param_3 & ~*(uint *)(iVar11 + 0x4c)) != 0)) {
    _printf(aDev0xXBsizeDSi_0,(int)*(sword *)(param_1 + 0x46),*(uint *)(iVar11 + 0x30),param_3,
            iVar11 + 0xd4);
    _panic(aFreeBlockBadSi);
  }
  uVar2 = param_2;
  .div(param_2,*(undefined4 *)(iVar11 + 0xbc));
  iVar3 = iVar11;
  _badblock(iVar11,param_2);
  if (iVar3 != 0) {
    _printf(aBadBlockDInoD,param_2,*(undefined4 *)(param_1 + 0x48));
    goto locret_F004A66C;
  }
  iVar3 = *(int *)(iVar11 + 0xbc);
  .umul(iVar3,uVar2);
  iVar8 = *(int *)(iVar11 + 0x18);
  .umul(iVar8,uVar2 & ~*(uint *)(iVar11 + 0x1c));
  puVar5 = *(uint **)(param_1 + 0x40);
  _bread(puVar5,iVar3 + iVar8 + *(int *)(iVar11 + 0xc) <<
                ((byte)*(undefined4 *)(iVar11 + 100) & 0x1f),*(undefined4 *)(iVar11 + 0xa0));
  *(uint **)((int)register0x00000038 + -0x14) = puVar5;
  iVar3 = *(int *)(*(int *)((int)register0x00000038 + -0x14) + 0x20);
  if (((*puVar5 & 4) != 0) || (*(int *)(iVar3 + 0x3d4) != 0x90255)) {
    _brelse(*(undefined4 *)((int)register0x00000038 + -0x14));
    goto locret_F004A66C;
  }
  _getthetime((undefined *)((int)register0x00000038 + -0x10));
  *(undefined4 *)(iVar3 + 8) = *(undefined4 *)((int)register0x00000038 + -0x10);
  .rem(param_2,*(undefined4 *)(iVar11 + 0xbc));
  if (param_3 == *(uint *)(iVar11 + 0x30)) {
    iVar8 = iVar11;
    _isblock(iVar11,iVar3 + 0x3d8,(int)param_2 >> ((byte)*(undefined4 *)(iVar11 + 0x60) & 0x1f));
    if (iVar8 != 0) {
      _printf(aDev0xXBlockDFs,(int)*(sword *)(param_1 + 0x46),param_2,iVar11 + 0xd4);
      _panic(aFreeBlockFreei);
    }
    _setblock(iVar11,iVar3 + 0x3d8,(int)param_2 >> ((byte)*(undefined4 *)(iVar11 + 0x60) & 0x1f));
    *(int *)(iVar3 + 0x1c) = *(int *)(iVar3 + 0x1c) + 1;
    *(int *)(iVar11 + 0xc4) = *(int *)(iVar11 + 0xc4) + 1;
    iVar8 = *(int *)(((int)uVar2 >> ((byte)*(undefined4 *)(iVar11 + 0x70) & 0x1f)) * 4 + iVar11 +
                    0x2d8) + (uVar2 & ~*(uint *)(iVar11 + 0x6c)) * 0x10;
    *(int *)(iVar8 + 4) = *(int *)(iVar8 + 4) + 1;
    uVar6 = *(undefined4 *)(iVar11 + 0x7c);
    uVar13 = param_2;
loc_F004A5A0:
    .umul(uVar13,uVar6);
    uVar6 = *(undefined4 *)(iVar11 + 0xac);
    uVar2 = uVar13;
    .div();
    .rem(uVar13,uVar6);
    uVar6 = *(undefined4 *)(iVar11 + 0xa8);
    .rem();
    iVar8 = uVar13 << 3;
    .div(iVar8,uVar6);
    iVar8 = iVar8 * 2 + uVar2 * 0x10 + iVar3;
    *(sword *)(iVar8 + 0xd4) = *(sword *)(iVar8 + 0xd4) + 1;
    iVar3 = uVar2 * 4 + iVar3;
    *(int *)(iVar3 + 0x54) = *(int *)(iVar3 + 0x54) + 1;
    cVar1 = *(char *)(iVar11 + 0xd0);
  }
  else {
    uVar13 = param_2 & ~(*(int *)(iVar11 + 0x38) - 1U);
    uVar7 = uVar13;
    if ((int)uVar13 < 0) {
      uVar7 = uVar13 + 7;
    }
    _fragacct(iVar11,(int)(uint)*(byte *)(iVar3 + ((int)uVar7 >> 3) + 0x3d8) >>
                     ((char)uVar13 + (char)((int)uVar7 >> 3) * -8 & 0x1fU) &
                     0xff >> (8U - (char)*(int *)(iVar11 + 0x38) & 0x1f),iVar3 + 0x34,0xffffffff);
    iVar8 = 0;
    param_3 = param_3 >> ((byte)*(undefined4 *)(iVar11 + 0x54) & 0x1f);
    if ((int)param_3 < 1) {
      iVar4 = *(int *)(iVar3 + 0x24);
    }
    else {
      do {
        iVar9 = param_2 + iVar8;
        iVar4 = iVar9;
        if (iVar9 < 0) {
          iVar4 = iVar9 + 7;
        }
        iVar10 = (iVar4 >> 3) + iVar3;
        bVar12 = (char)iVar9 + (char)(iVar4 >> 3) * -8;
        if (((int)*(char *)(iVar10 + 0x3d8) >> (bVar12 & 0x1f) & 1U) != 0) {
          _printf(aDev0xXBlockDFs_0,(int)*(sword *)(param_1 + 0x46),iVar9,iVar11 + 0xd4);
          _panic(aFreeBlockFreei_0);
        }
        iVar8 = iVar8 + 1;
        *(byte *)(iVar10 + 0x3d8) = *(byte *)(iVar10 + 0x3d8) | (byte)(1 << (bVar12 & 0x1f));
      } while (iVar8 < (int)param_3);
      iVar4 = *(int *)(iVar3 + 0x24);
    }
    *(int *)(iVar3 + 0x24) = iVar4 + iVar8;
    *(int *)(iVar11 + 0xcc) = *(int *)(iVar11 + 0xcc) + iVar8;
    iVar4 = *(int *)(((int)uVar2 >> ((byte)*(undefined4 *)(iVar11 + 0x70) & 0x1f)) * 4 + iVar11 +
                    0x2d8) + (uVar2 & ~*(uint *)(iVar11 + 0x6c)) * 0x10;
    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + iVar8;
    uVar7 = uVar13;
    if ((int)uVar13 < 0) {
      uVar7 = uVar13 + 7;
    }
    _fragacct(iVar11,(int)(uint)*(byte *)(iVar3 + ((int)uVar7 >> 3) + 0x3d8) >>
                     ((char)uVar13 + (char)((int)uVar7 >> 3) * -8 & 0x1fU) &
                     0xff >> (8U - (char)*(undefined4 *)(iVar11 + 0x38) & 0x1f),iVar3 + 0x34,1);
    iVar8 = iVar11;
    _isblock(iVar11,iVar3 + 0x3d8,(int)uVar13 >> ((byte)*(undefined4 *)(iVar11 + 0x60) & 0x1f));
    if (iVar8 != 0) {
      *(int *)(iVar3 + 0x24) = *(int *)(iVar3 + 0x24) - *(int *)(iVar11 + 0x38);
      *(int *)(iVar11 + 0xcc) = *(int *)(iVar11 + 0xcc) - *(int *)(iVar11 + 0x38);
      iVar8 = *(int *)(((int)uVar2 >> ((byte)*(undefined4 *)(iVar11 + 0x70) & 0x1f)) * 4 + iVar11 +
                      0x2d8) + (uVar2 & ~*(uint *)(iVar11 + 0x6c)) * 0x10;
      *(int *)(iVar8 + 0xc) = *(int *)(iVar8 + 0xc) - *(int *)(iVar11 + 0x38);
      *(int *)(iVar3 + 0x1c) = *(int *)(iVar3 + 0x1c) + 1;
      *(int *)(iVar11 + 0xc4) = *(int *)(iVar11 + 0xc4) + 1;
      iVar8 = *(int *)(((int)uVar2 >> ((byte)*(undefined4 *)(iVar11 + 0x70) & 0x1f)) * 4 + iVar11 +
                      0x2d8) + (uVar2 & ~*(uint *)(iVar11 + 0x6c)) * 0x10;
      *(int *)(iVar8 + 4) = *(int *)(iVar8 + 4) + 1;
      uVar6 = *(undefined4 *)(iVar11 + 0x7c);
      goto loc_F004A5A0;
    }
    cVar1 = *(char *)(iVar11 + 0xd0);
  }
  uVar6 = *(undefined4 *)((int)register0x00000038 + -0x14);
  *(char *)(iVar11 + 0xd0) = cVar1 + '\x01';
  _bdwrite(uVar6);
  if (((*(byte *)(iVar11 + 0xd3) & 1) != 0) &&
     (*(int *)(iVar11 + 0x88) <
      (*(int *)(iVar11 + 0xc4) << ((byte)*(undefined4 *)(iVar11 + 0x60) & 0x1f)) +
      *(int *)(iVar11 + 0xcc))) {
    _wakeup(iVar11 + 0xcc);
    *(byte *)(iVar11 + 0xd3) = *(byte *)(iVar11 + 0xd3) & 0xfe;
  }
locret_F004A66C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1007 start=0xf004a674 */

/* WARNING: Removing unreachable block (ram,0xf004a87c) */
/* WARNING: Removing unreachable block (ram,0xf004a798) */
/* WARNING: Removing unreachable block (ram,0xf004a748) */
/* WARNING: Removing unreachable block (ram,0xf004a708) */
/* WARNING: Removing unreachable block (ram,0xf004a6c8) */
/* WARNING: Removing unreachable block (ram,0xf004a6ac) */
/* WARNING: Removing unreachable block (ram,0xf004a6a0) */
/* WARNING: Removing unreachable block (ram,0xf004a6b8) */
/* WARNING: Removing unreachable block (ram,0xf004a6e0) */
/* WARNING: Removing unreachable block (ram,0xf004a73c) */
/* WARNING: Removing unreachable block (ram,0xf004a75c) */
/* WARNING: Removing unreachable block (ram,0xf004a7a4) */
/* WARNING: Removing unreachable block (ram,0xf004a8a8) */
/* WARNING: Removing unreachable block (ram,0xf004a680) */

undefined8 _ifree(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  uint uVar5;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  byte bVar7;
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
  iVar6 = *(int *)(param_1 + 0x50);
  uVar1 = *(uint *)(iVar6 + 0xb8);
  .umul(uVar1,*(undefined4 *)(iVar6 + 0x2c));
  if (uVar1 <= param_2) {
    _printf(aDev0xXInoDFsS,(int)*(sword *)(param_1 + 0x46),param_2,iVar6 + 0xd4);
    _panic(aIfreeRange);
  }
  uVar1 = param_2;
  .udiv(param_2,*(undefined4 *)(iVar6 + 0xb8));
  iVar2 = *(int *)(iVar6 + 0xbc);
  .umul(iVar2,uVar1);
  iVar4 = *(int *)(iVar6 + 0x18);
  .umul(iVar4,uVar1 & ~*(uint *)(iVar6 + 0x1c));
  puVar3 = *(uint **)(param_1 + 0x40);
  _bread(puVar3,iVar2 + iVar4 + *(int *)(iVar6 + 0xc) << ((byte)*(undefined4 *)(iVar6 + 100) & 0x1f)
         ,*(undefined4 *)(iVar6 + 0xa0));
  uVar5 = puVar3[8];
  if (((*puVar3 & 4) == 0) && (*(int *)(uVar5 + 0x3d4) == 0x90255)) {
    _getthetime((undefined *)((int)register0x00000038 + -0x10));
    *(undefined4 *)(uVar5 + 8) = *(undefined4 *)((int)register0x00000038 + -0x10);
    .urem(param_2,*(undefined4 *)(iVar6 + 0xb8));
    iVar2 = (param_2 >> 3) + uVar5;
    bVar7 = (byte)param_2 & 7;
    if (((int)*(char *)(iVar2 + 0x2d4) >> bVar7 & 1U) == 0) {
      _printf(aDev0xXInoDFsS_0,(int)*(sword *)(param_1 + 0x46),param_2,iVar6 + 0xd4);
      _panic(aIfreeFreeingFr);
    }
    *(byte *)(iVar2 + 0x2d4) = *(byte *)(iVar2 + 0x2d4) & ~(byte)(1 << bVar7);
    if (param_2 < *(uint *)(uVar5 + 0x30)) {
      *(uint *)(uVar5 + 0x30) = param_2;
    }
    *(int *)(uVar5 + 0x20) = *(int *)(uVar5 + 0x20) + 1;
    *(int *)(iVar6 + 200) = *(int *)(iVar6 + 200) + 1;
    iVar2 = *(int *)(((int)uVar1 >> ((byte)*(undefined4 *)(iVar6 + 0x70) & 0x1f)) * 4 + iVar6 +
                    0x2d8) + (uVar1 & ~*(uint *)(iVar6 + 0x6c)) * 0x10;
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + 1;
    if ((param_3 & 0xf000) == 0x4000) {
      *(int *)(uVar5 + 0x18) = *(int *)(uVar5 + 0x18) + -1;
      *(int *)(iVar6 + 0xc0) = *(int *)(iVar6 + 0xc0) + -1;
      iVar4 = *(int *)(((int)uVar1 >> ((byte)*(undefined4 *)(iVar6 + 0x70) & 0x1f)) * 4 + iVar6 +
                      0x2d8);
      iVar2 = (uVar1 & ~*(uint *)(iVar6 + 0x6c)) * 0x10;
      *(int *)(iVar4 + iVar2) = *(int *)(iVar4 + iVar2) + -1;
    }
    *(char *)(iVar6 + 0xd0) = *(char *)(iVar6 + 0xd0) + '\x01';
    _bdwrite(puVar3);
    if (((*(byte *)(iVar6 + 0xd3) & 2) != 0) && (*(int *)(iVar6 + 0x90) < *(int *)(iVar6 + 200))) {
      _wakeup(iVar6 + 200);
      *(byte *)(iVar6 + 0xd3) = *(byte *)(iVar6 + 0xd3) & 0xfd;
    }
  }
  else {
    _brelse(puVar3);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1008 start=0xf004a8c4 */

/* WARNING: Removing unreachable block (ram,0xf004aab0) */
/* WARNING: Removing unreachable block (ram,0xf004a9d0) */
/* WARNING: Removing unreachable block (ram,0xf004a95c) */
/* WARNING: Removing unreachable block (ram,0xf004a9ac) */
/* WARNING: Removing unreachable block (ram,0xf004a9dc) */
/* WARNING: Removing unreachable block (ram,0xf004aabc) */
/* WARNING: Removing unreachable block (ram,0xf004a8d4) */

undefined8 _mapsearch(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar8;
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
  if (param_3 == 0) {
    param_3 = *(int *)(param_2 + 0x2c);
  }
  else {
    .rem(param_3,*(undefined4 *)(param_1 + 0xbc));
  }
  if (param_3 < 0) {
    param_3 = param_3 + 7;
  }
  param_3 = param_3 >> 3;
  iVar1 = *(int *)(param_1 + 0xbc) + 7;
  if (iVar1 < 0) {
    iVar1 = *(int *)(param_1 + 0xbc) + 0xe;
  }
  iVar8 = (iVar1 >> 3) - param_3;
  iVar5 = *(int *)(param_1 + 0x38);
  iVar1 = iVar5;
  if (iVar5 < 0) {
    iVar1 = iVar5 + 7;
  }
  iVar4 = iVar8;
  _scanc(iVar8,param_2 + param_3 + 0x3d8,*(undefined4 *)(_fragtbl + iVar5 * 4),
         1 << ((char)param_4 + ((char)iVar5 - ((byte)iVar1 & 0xf8)) + -1 & 0x1f));
  iVar8 = param_3 + iVar8;
  if (iVar4 == 0) {
    iVar8 = param_3 + 1;
    iVar5 = *(int *)(param_1 + 0x38);
    iVar1 = iVar5;
    if (iVar5 < 0) {
      iVar1 = iVar5 + 7;
    }
    iVar4 = iVar8;
    _scanc(iVar8,param_2 + 0x3d8,*(undefined4 *)(_fragtbl + iVar5 * 4),
           1 << ((char)param_4 + ((char)iVar5 - ((byte)iVar1 & 0xf8)) + -1 & 0x1f));
    if (iVar4 == 0) {
      _printf(aStartDLenDFsS,0,iVar8,param_1 + 0xd4);
      _panic(aAlloccgMapCorr);
    }
  }
  iVar8 = (iVar8 - iVar4) * 8;
  iVar1 = iVar8 + 8;
  *(int *)(param_2 + 0x2c) = iVar8;
  if (iVar8 < iVar1) {
    do {
      iVar5 = iVar8;
      if (iVar8 < 0) {
        iVar5 = iVar8 + 7;
      }
      iVar4 = 0;
      uVar7 = *(uint *)(_around + param_4 * 4);
      uVar6 = *(uint *)(_inside + param_4 * 4);
      uVar3 = *(int *)(param_1 + 0x38) - param_4;
      if (uVar3 < 0x80000000) {
        do {
          uVar2 = ((int)(uint)*(byte *)(param_2 + (iVar5 >> 3) + 0x3d8) >>
                   ((char)iVar8 + (char)(iVar5 >> 3) * -8 & 0x1fU) &
                  0xff >> (8U - (char)*(int *)(param_1 + 0x38) & 0x1f)) << 1 & uVar7;
          uVar7 = uVar7 << 1;
          if (uVar2 == uVar6) {
            iVar8 = iVar8 + iVar4;
            goto locret_F004AAC8;
          }
          iVar4 = iVar4 + 1;
          uVar6 = uVar6 << 1;
        } while (iVar4 <= (int)uVar3);
      }
      iVar8 = iVar8 + *(int *)(param_1 + 0x38);
    } while (iVar8 < iVar1);
  }
  _printf(aBnoDFsS,iVar8,param_1 + 0xd4);
  _panic(aAlloccgBlockNo);
  iVar8 = -1;
locret_F004AAC8:
  return CONCAT44(param_2,iVar8);
}
/* GHIDRADEC_FUNCTION index=1009 start=0xf004aad0 */

/* WARNING: Removing unreachable block (ram,0xf004aae4) */

undefined8 _fserr(int param_1,undefined4 param_2)

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
  _log(3,&aSS_2,param_1 + 0xd4,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1010 start=0xf004aaf4 */

/* WARNING: Removing unreachable block (ram,0xf004add4) */
/* WARNING: Removing unreachable block (ram,0xf004ad68) */
/* WARNING: Removing unreachable block (ram,0xf004ad1c) */
/* WARNING: Removing unreachable block (ram,0xf004aca4) */
/* WARNING: Removing unreachable block (ram,0xf004af30) */
/* WARNING: Removing unreachable block (ram,0xf004b0a0) */
/* WARNING: Removing unreachable block (ram,0xf004b068) */
/* WARNING: Removing unreachable block (ram,0xf004b00c) */
/* WARNING: Removing unreachable block (ram,0xf004afb0) */
/* WARNING: Removing unreachable block (ram,0xf004af20) */
/* WARNING: Removing unreachable block (ram,0xf004af48) */
/* WARNING: Removing unreachable block (ram,0xf004aef0) */
/* WARNING: Removing unreachable block (ram,0xf004ac58) */
/* WARNING: Removing unreachable block (ram,0xf004ac3c) */
/* WARNING: Removing unreachable block (ram,0xf004abf4) */
/* WARNING: Removing unreachable block (ram,0xf004ac0c) */
/* WARNING: Removing unreachable block (ram,0xf004ac48) */
/* WARNING: Removing unreachable block (ram,0xf004ae74) */
/* WARNING: Removing unreachable block (ram,0xf004af04) */
/* WARNING: Removing unreachable block (ram,0xf004af7c) */
/* WARNING: Removing unreachable block (ram,0xf004afa0) */
/* WARNING: Removing unreachable block (ram,0xf004afb8) */
/* WARNING: Removing unreachable block (ram,0xf004b020) */
/* WARNING: Removing unreachable block (ram,0xf004b078) */
/* WARNING: Removing unreachable block (ram,0xf004b090) */
/* WARNING: Removing unreachable block (ram,0xf004b0b0) */
/* WARNING: Removing unreachable block (ram,0xf004ad04) */
/* WARNING: Removing unreachable block (ram,0xf004ad30) */
/* WARNING: Removing unreachable block (ram,0xf004ad78) */
/* WARNING: Removing unreachable block (ram,0xf004adc4) */
/* WARNING: Removing unreachable block (ram,0xf004abdc) */

undefined8 _bmap(int param_1,int param_2,uint param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  uint *puVar2;
  byte bVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 uVar5;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar7;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  int iVar9;
  undefined4 unaff_l6;
  int iVar10;
  undefined4 unaff_l7;
  uint uVar11;
  undefined4 unaff_i0;
  uint uVar12;
  int iVar13;
  undefined4 unaff_i1;
  int iVar14;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar15;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar16;
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
  iVar10 = 0;
  uVar11 = 0;
  iVar14 = param_2;
  if (param_2 < 0) {
loc_F004AEA8:
    iVar13 = 0;
    *(undefined *)(dword_F0133DDC + 0x38) = 0x1b;
    param_2 = iVar14;
    goto locret_F004B100;
  }
  _rablock = 0;
  _rasize = 0;
  iVar7 = *(int *)(param_1 + 0x50);
  if ((param_3 & 0x20) != 0) {
    param_3 = param_3 & 0xffffffdf;
  }
  uVar4 = *(uint *)(param_1 + 0x70);
  bVar3 = (byte)*(undefined4 *)(iVar7 + 0x50);
  uVar12 = uVar4 >> (bVar3 & 0x1f);
  if (param_3 == 0) {
    bVar16 = param_2 + -0xb < 0;
    if (((int)uVar12 < 0xc) && (bVar16 = param_2 + -0xb < 0, (int)uVar12 < param_2)) {
      if (*(int *)(uVar12 * 4 + param_1 + 0x8c) != 0) {
        if ((int)uVar12 < 0xc) {
          if (uVar4 < uVar12 + 1 << (bVar3 & 0x1f)) {
            uVar4 = ((uVar4 & ~*(uint *)(iVar7 + 0x48)) + *(int *)(iVar7 + 0x34)) - 1 &
                    *(uint *)(iVar7 + 0x4c);
          }
          else {
            uVar4 = *(uint *)(iVar7 + 0x30);
          }
        }
        else {
          uVar4 = *(uint *)(iVar7 + 0x30);
        }
        if ((uVar4 < *(uint *)(iVar7 + 0x30)) && (uVar4 != 0)) {
          iVar8 = uVar12 * 4 + param_1;
          uVar5 = *(undefined4 *)(iVar8 + 0x8c);
          iVar13 = param_1;
          _blkpref(param_1,uVar12,uVar12,param_1 + 0x8c);
          iVar9 = param_1;
          _realloccg(param_1,uVar5,iVar13,uVar4,*(undefined4 *)(iVar7 + 0x30));
          if (iVar9 == 0) {
            iVar13 = -1;
            goto locret_F004B100;
          }
          iVar13 = uVar12 + 1;
          .umul(iVar13,*(undefined4 *)(iVar7 + 0x30));
          *(int *)(param_1 + 0x70) = iVar13;
          *(int *)(iVar8 + 0x8c) =
               *(int *)(iVar9 + 0x24) >> ((byte)*(undefined4 *)(iVar7 + 100) & 0x1f);
          *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
          if (param_5 != (undefined4 *)0x0) {
            _bwrite(iVar9);
            _iupdat(param_1,1);
            bVar16 = param_2 + -0xb < 0;
            goto loc_F004AC64;
          }
          _bdwrite(iVar9);
        }
      }
      goto loc_F004AC60;
    }
  }
  else {
loc_F004AC60:
    bVar16 = param_2 + -0xb < 0;
  }
loc_F004AC64:
  iVar9 = 0;
  if (param_2 == 0xb || bVar16 != SBORROW4(param_2,0xb)) {
    iVar13 = *(int *)(param_2 * 4 + param_1 + 0x8c);
    if (param_3 == 1) {
      if (iVar13 != 0) goto loc_F004ADF8;
loc_F004AC8C:
      iVar13 = -1;
      param_2 = iVar14;
      goto locret_F004B100;
    }
    iVar10 = param_1;
    if (iVar13 == 0) {
      uVar11 = *(uint *)(iVar7 + 0x30);
loc_F004AD2C:
      uVar4 = param_2 + 1;
      .umul(uVar4,uVar11);
      if (*(uint *)(param_1 + 0x70) < uVar4) {
        uVar11 = (param_4 + *(int *)(iVar7 + 0x34)) - 1U & *(uint *)(iVar7 + 0x4c);
      }
      iVar13 = param_1;
      _blkpref(param_1,param_2,param_2,param_1 + 0x8c);
      _alloc(param_1,iVar13,uVar11);
loc_F004AD84:
      if (iVar10 == 0) goto loc_F004AC8C;
      iVar13 = *(int *)(iVar10 + 0x24) >> ((byte)*(undefined4 *)(iVar7 + 100) & 0x1f);
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = 1;
      }
      if ((*(word *)(param_1 + 100) & 0xf000) == 0x4000) {
        _bwrite(iVar10);
      }
      else {
        _bdwrite(iVar10);
      }
      *(int *)(param_2 * 4 + param_1 + 0x8c) = iVar13;
      *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
    }
    else {
      uVar11 = param_2 + 1;
      .umul(uVar11,*(undefined4 *)(iVar7 + 0x30));
      if (*(uint *)(param_1 + 0x70) < uVar11) {
        if (iVar13 == 0) {
          uVar11 = *(uint *)(iVar7 + 0x30);
          goto loc_F004AD2C;
        }
        uVar4 = ((*(uint *)(param_1 + 0x70) & ~*(uint *)(iVar7 + 0x48)) + *(int *)(iVar7 + 0x34)) -
                1 & *(uint *)(iVar7 + 0x4c);
        uVar11 = (param_4 + *(int *)(iVar7 + 0x34)) - 1U & *(uint *)(iVar7 + 0x4c);
        if (uVar11 <= uVar4) goto loc_F004ADF8;
        iVar9 = param_1;
        _blkpref(param_1,param_2,param_2,param_1 + 0x8c);
        _realloccg(param_1,iVar13,iVar9,uVar4,uVar11);
        goto loc_F004AD84;
      }
    }
loc_F004ADF8:
    if (10 < param_2) goto locret_F004B100;
    _rablock = *(int *)(param_1 + param_2 * 4 + 0x90) << ((byte)*(undefined4 *)(iVar7 + 100) & 0x1f)
    ;
    if (param_2 + 1 < 0xc) {
      if (*(uint *)(param_1 + 0x70) <
          (uint)(param_2 + 2 << ((byte)*(undefined4 *)(iVar7 + 0x50) & 0x1f))) {
        _rasize = ((*(uint *)(param_1 + 0x70) & ~*(uint *)(iVar7 + 0x48)) + *(int *)(iVar7 + 0x34))
                  - 1 & *(uint *)(iVar7 + 0x4c);
      }
      else {
        _rasize = *(uint *)(iVar7 + 0x30);
      }
      goto locret_F004B100;
    }
  }
  else {
    iVar8 = 1;
    iVar14 = param_2 + -0xc;
    iVar15 = 3;
    do {
      .umul(iVar8,*(undefined4 *)(iVar7 + 0x74));
      if (iVar14 < iVar8) break;
      iVar15 = iVar15 + -1;
      iVar14 = iVar14 - iVar8;
    } while (0 < iVar15);
    if (iVar15 == 0) goto loc_F004AEA8;
    iVar6 = (3 - iVar15) * 4 + param_1;
    iVar13 = *(int *)(iVar6 + 0xbc);
    if (iVar13 == 0) {
      if (param_3 == 1) goto loc_F004AC8C;
      iVar9 = param_1;
      _blkpref(param_1,param_2,0,0);
      iVar1 = param_1;
      _alloc(param_1,iVar9,*(undefined4 *)(iVar7 + 0x30));
      if (iVar1 == 0) {
        iVar13 = -1;
        param_2 = iVar14;
        goto locret_F004B100;
      }
      iVar13 = *(int *)(iVar1 + 0x24) >> ((byte)*(undefined4 *)(iVar7 + 100) & 0x1f);
      _bwrite(iVar1);
      *(int *)(iVar6 + 0xbc) = iVar13;
      *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = 1;
      }
    }
    while (iVar15 < 4) {
      puVar2 = *(uint **)(param_1 + 0x40);
      _bread(puVar2,iVar13 << ((byte)*(undefined4 *)(iVar7 + 100) & 0x1f),
             *(undefined4 *)(iVar7 + 0x30));
      if ((*puVar2 & 4) != 0) {
        _brelse(puVar2);
        iVar13 = 0;
        param_2 = iVar14;
        goto locret_F004B100;
      }
      uVar11 = puVar2[8];
      .div(iVar8,*(undefined4 *)(iVar7 + 0x74));
      iVar10 = iVar14;
      .div(iVar14,iVar8);
      .rem();
      iVar13 = *(int *)(uVar11 + iVar10 * 4);
      if (iVar13 == 0) {
        if (param_3 == 1) {
loc_F004AF30:
          _brelse(puVar2);
          iVar13 = -1;
          param_2 = iVar14;
          goto locret_F004B100;
        }
        if (iVar9 == 0) {
          iVar13 = iVar10;
          uVar4 = uVar11;
          if (iVar15 < 3) {
            iVar13 = 0;
            uVar4 = 0;
          }
          iVar9 = param_1;
          _blkpref(param_1,param_2,iVar13,uVar4);
        }
        iVar6 = param_1;
        _alloc(param_1,iVar9,*(undefined4 *)(iVar7 + 0x30));
        if (iVar6 == 0) goto loc_F004AF30;
        iVar13 = *(int *)(iVar6 + 0x24) >> ((byte)*(undefined4 *)(iVar7 + 100) & 0x1f);
        if (((iVar15 < 3) || ((*(word *)(param_1 + 100) & 0xf000) == 0x4000)) ||
           (param_5 != (undefined4 *)0x0)) {
          _bwrite(iVar6);
        }
        else {
          _bdwrite(iVar6);
        }
        *(int *)(uVar11 + iVar10 * 4) = iVar13;
        if (param_5 == (undefined4 *)0x0) {
          _bdwrite(puVar2);
          iVar15 = iVar15 + 1;
        }
        else {
          _bwrite(puVar2);
          iVar15 = iVar15 + 1;
        }
      }
      else {
        _brelse(puVar2);
        iVar15 = iVar15 + 1;
      }
    }
    param_2 = iVar14;
    if (*(int *)(iVar7 + 0x74) + -1 <= iVar10) goto locret_F004B100;
    _rablock = *(int *)(iVar10 * 4 + uVar11 + 4) << ((byte)*(undefined4 *)(iVar7 + 100) & 0x1f);
  }
  _rasize = *(uint *)(iVar7 + 0x30);
locret_F004B100:
  return CONCAT44(param_2,iVar13);
}
/* GHIDRADEC_FUNCTION index=1011 start=0xf004b108 */

/* WARNING: Removing unreachable block (ram,0xf004b500) */
/* WARNING: Removing unreachable block (ram,0xf004b468) */
/* WARNING: Removing unreachable block (ram,0xf004b3c8) */
/* WARNING: Removing unreachable block (ram,0xf004b41c) */
/* WARNING: Removing unreachable block (ram,0xf004b35c) */
/* WARNING: Removing unreachable block (ram,0xf004b2b8) */
/* WARNING: Removing unreachable block (ram,0xf004b248) */
/* WARNING: Removing unreachable block (ram,0xf004b160) */
/* WARNING: Removing unreachable block (ram,0xf004b144) */
/* WARNING: Removing unreachable block (ram,0xf004b1e0) */
/* WARNING: Removing unreachable block (ram,0xf004b2a8) */
/* WARNING: Removing unreachable block (ram,0xf004b300) */
/* WARNING: Removing unreachable block (ram,0xf004b378) */
/* WARNING: Removing unreachable block (ram,0xf004b444) */
/* WARNING: Removing unreachable block (ram,0xf004b3d8) */
/* WARNING: Removing unreachable block (ram,0xf004b4ec) */
/* WARNING: Removing unreachable block (ram,0xf004b1a8) */
/* WARNING: Removing unreachable block (ram,0xf004b114) */

undefined8 _dirlook(int param_1,char *param_2,int *param_3)

{
  word wVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int *piVar6;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  int iVar8;
  int iVar9;
  undefined4 unaff_l4;
  uint uVar10;
  undefined4 unaff_l5;
  int iVar11;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar12;
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
  iVar8 = 0;
  uVar7 = 0;
  pcVar2 = param_2;
  _strlen();
  if ((*(word *)(param_1 + 100) & 0xf000) != 0x4000) {
    iVar12 = 0x14;
    goto locret_F004B50C;
  }
  iVar12 = param_1;
  _iaccess(param_1,0x40);
  if (iVar12 != 0) goto locret_F004B50C;
  iVar12 = param_1 + 0xc;
  _dnlc_lookup(iVar12,param_2,0);
  if (iVar12 != 0) {
    iVar11 = *(int *)(iVar12 + 0x30);
    *(sword *)(iVar12 + 6) = *(sword *)(iVar12 + 6) + 1;
    *param_3 = iVar11;
    iVar8 = *param_3;
    wVar1 = *(word *)(iVar11 + 0x44);
    while ((wVar1 & 1) != 0) {
      *(word *)(iVar8 + 0x44) = *(word *)(iVar8 + 0x44) | 0x10;
      _sleep(*param_3,10);
      iVar8 = *param_3;
      wVar1 = *(word *)(*param_3 + 0x44);
    }
    iVar12 = 0;
    *(word *)(iVar8 + 0x44) = *(word *)(iVar8 + 0x44) | 1;
    goto locret_F004B50C;
  }
  wVar1 = *(word *)(param_1 + 0x44);
  while ((wVar1 & 1) != 0) {
    *(word *)(param_1 + 0x44) = wVar1 | 0x10;
    _sleep(param_1,10);
    wVar1 = *(word *)(param_1 + 0x44);
  }
  *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 1;
  if (*(uint *)(param_1 + 0x70) < *(uint *)(param_1 + 0x4c)) {
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  uVar5 = *(uint *)(param_1 + 0x4c);
  if (uVar5 == 0) {
    uVar5 = 0;
    iVar11 = 1;
loc_F004B260:
    uVar10 = *(int *)(param_1 + 0x70) + 0x3ffU & 0xfffffc00;
joined_r0xf004b270:
    for (; uVar5 < uVar10; uVar5 = uVar5 + uVar3) {
      if ((uVar5 & ~*(uint *)(*(int *)(param_1 + 0x50) + 0x48)) == 0) {
        if (iVar8 != 0) {
          _brelse(iVar8);
        }
        iVar8 = param_1;
        _blkatoff(param_1,uVar5,0);
        uVar7 = 0;
        if (iVar8 == 0) goto loc_F004B4A8;
        iVar12 = *(int *)(iVar8 + 0x20);
      }
      else {
        iVar12 = *(int *)(iVar8 + 0x20);
      }
      piVar6 = (int *)(iVar12 + uVar7);
      if ((*(sword *)(piVar6 + 1) == 0) ||
         ((_dirchk != 0 && (iVar12 = param_1, sub_F004CCF8(param_1,piVar6,uVar7,uVar5), iVar12 != 0)
          ))) {
        uVar3 = 0x400 - (uVar7 & 0x3ff);
      }
      else if (*piVar6 == 0) {
        uVar3 = (uint)*(word *)(piVar6 + 1);
      }
      else if ((char *)(uint)*(word *)((int)piVar6 + 6) == pcVar2) {
        if (*param_2 == *(char *)(piVar6 + 2)) {
          pcVar4 = param_2;
          _bcmp(param_2,piVar6 + 2,pcVar2);
          if (pcVar4 == (char *)0x0) {
            iVar12 = *piVar6;
            iVar9 = 0;
            _brelse(iVar8);
            *(uint *)(param_1 + 0x4c) = uVar5;
            if (pcVar2 == (char *)0x2) {
              if (*param_2 != '.') {
                iVar8 = *(int *)(param_1 + 0x48);
                goto loc_F004B3F8;
              }
              if (param_2[1] != '.') {
                iVar8 = *(int *)(param_1 + 0x48);
                goto loc_F004B3F8;
              }
              wVar1 = *(word *)(param_1 + 0x44);
              *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
              if ((wVar1 & 0x10) != 0) {
                *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
                _wakeup(param_1);
              }
              iVar8 = (int)*(sword *)(param_1 + 0x46);
              _iget(iVar8,*(undefined4 *)(param_1 + 0x50),iVar12);
              if (iVar8 == 0) goto loc_F004B4B4;
              *param_3 = iVar8;
            }
            else {
              iVar8 = *(int *)(param_1 + 0x48);
loc_F004B3F8:
              if (iVar8 == iVar12) {
                *(sword *)(param_1 + 0x12) = *(sword *)(param_1 + 0x12) + 1;
                iVar8 = param_1;
              }
              else {
                iVar8 = (int)*(sword *)(param_1 + 0x46);
                _iget(iVar8,*(undefined4 *)(param_1 + 0x50),iVar12);
                wVar1 = *(word *)(param_1 + 0x44);
                *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
                if ((wVar1 & 0x10) != 0) {
                  *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
                  _wakeup(param_1);
                }
                if (iVar8 == 0) {
loc_F004B4B4:
                  iVar12 = (int)*(char *)(dword_F0133DDC + 0x38);
                  goto loc_F004B4F4;
                }
              }
              *param_3 = iVar8;
            }
            _dnlc_enter(param_1 + 0xc,param_2,iVar8 + 0xc,0);
            iVar12 = 0;
            goto locret_F004B50C;
          }
          uVar3 = (uint)*(word *)(piVar6 + 1);
        }
        else {
          uVar3 = (uint)*(word *)(piVar6 + 1);
        }
      }
      else {
        uVar3 = (uint)*(word *)(piVar6 + 1);
      }
      uVar7 = uVar7 + uVar3;
    }
    iVar12 = 2;
    iVar9 = iVar8;
    if (iVar11 == 2) {
      iVar11 = 1;
      uVar10 = *(uint *)(param_1 + 0x4c);
      uVar5 = 0;
      goto joined_r0xf004b270;
    }
  }
  else {
    uVar7 = uVar5 & ~*(uint *)(*(int *)(param_1 + 0x50) + 0x48);
    if ((uVar7 == 0) || (iVar8 = param_1, _blkatoff(param_1,uVar5,0), iVar8 != 0)) {
      iVar11 = 2;
      goto loc_F004B260;
    }
loc_F004B4A8:
    iVar12 = (int)*(char *)(dword_F0133DDC + 0x38);
    iVar9 = iVar8;
  }
  wVar1 = *(word *)(param_1 + 0x44);
  *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
  if ((wVar1 & 0x10) != 0) {
    *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
    _wakeup(param_1);
  }
loc_F004B4F4:
  if (iVar9 != 0) {
    _brelse(iVar9);
  }
locret_F004B50C:
  return CONCAT44(param_2,iVar12);
}
/* GHIDRADEC_FUNCTION index=1012 start=0xf004b514 */

/* WARNING: Removing unreachable block (ram,0xf004b9f8) */
/* WARNING: Removing unreachable block (ram,0xf004b888) */
/* WARNING: Removing unreachable block (ram,0xf004b85c) */
/* WARNING: Removing unreachable block (ram,0xf004b96c) */
/* WARNING: Removing unreachable block (ram,0xf004b9e0) */
/* WARNING: Removing unreachable block (ram,0xf004b8ec) */
/* WARNING: Removing unreachable block (ram,0xf004b800) */
/* WARNING: Removing unreachable block (ram,0xf004b7c0) */
/* WARNING: Removing unreachable block (ram,0xf004b724) */
/* WARNING: Removing unreachable block (ram,0xf004b6d4) */
/* WARNING: Removing unreachable block (ram,0xf004b664) */
/* WARNING: Removing unreachable block (ram,0xf004b5c4) */
/* WARNING: Removing unreachable block (ram,0xf004b600) */
/* WARNING: Removing unreachable block (ram,0xf004b6b0) */
/* WARNING: Removing unreachable block (ram,0xf004b70c) */
/* WARNING: Removing unreachable block (ram,0xf004b77c) */
/* WARNING: Removing unreachable block (ram,0xf004b7d8) */
/* WARNING: Removing unreachable block (ram,0xf004b8c8) */
/* WARNING: Removing unreachable block (ram,0xf004b914) */
/* WARNING: Removing unreachable block (ram,0xf004b99c) */
/* WARNING: Removing unreachable block (ram,0xf004b8b4) */
/* WARNING: Removing unreachable block (ram,0xf004b87c) */
/* WARNING: Removing unreachable block (ram,0xf004b8a4) */
/* WARNING: Removing unreachable block (ram,0xf004ba58) */
/* WARNING: Removing unreachable block (ram,0xf004b568) */

undefined8
_direnter(int param_1,char *param_2,uint param_3,int param_4,undefined4 param_5,undefined4 param_6)

{
  sword sVar1;
  word wVar2;
  char cVar4;
  int iVar3;
  char *pcVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  int *piVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined *puVar9;
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
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  iVar7 = 0;
  piVar8 = *(int **)((int)register0x00000038 + 0x5c);
  if (*param_2 != '\0') {
    cVar4 = *param_2;
    pcVar5 = param_2;
    do {
      pcVar5 = pcVar5 + 1;
      if (cVar4 == '/') {
        iVar6 = 0xd;
        goto locret_F004BA60;
      }
      cVar4 = *pcVar5;
      iVar7 = iVar7 + 1;
    } while (cVar4 != '\0');
  }
  if (iVar7 == 0) {
    _panic(aDirenter);
    cVar4 = *param_2;
  }
  else {
    cVar4 = *param_2;
  }
  if (cVar4 == '.') {
    if (iVar7 == 1) {
loc_F004B5A4:
      if (param_3 == 2) {
        iVar6 = 0x42;
      }
      else if ((piVar8 == (int *)0x0) ||
              (_dirlook(param_1,param_2,piVar8), iVar6 = param_1, param_1 == 0)) {
        iVar6 = 0x11;
      }
      goto locret_F004BA60;
    }
    if (iVar7 == 2) {
      if (param_2[1] == '.') goto loc_F004B5A4;
      *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
    }
    else {
      *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
    }
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x20) = 0;
  }
  *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  if (param_3 == 0) goto loc_F004B72C;
  iVar6 = *(int *)((int)register0x00000038 + 0x54);
  while ((*(word *)(iVar6 + 0x44) & 1) != 0) {
    *(word *)(iVar6 + 0x44) = *(word *)(iVar6 + 0x44) | 0x10;
    _sleep(iVar6,10);
    iVar6 = *(int *)((int)register0x00000038 + 0x54);
  }
  iVar6 = *(int *)((int)register0x00000038 + 0x54);
  wVar2 = *(word *)(iVar6 + 0x44);
  sVar1 = *(sword *)(iVar6 + 0x66);
  *(word *)(iVar6 + 0x44) = wVar2 | 1;
  if (sVar1 == 0) {
    *(word *)(iVar6 + 0x44) = wVar2 & 0xfffe;
    if ((wVar2 & 0x10) != 0) {
      *(word *)(iVar6 + 0x44) = wVar2 & 0xffee;
      _wakeup(iVar6);
    }
    iVar6 = 2;
    goto locret_F004BA60;
  }
  if (sVar1 == 0x7fff) {
    *(word *)(iVar6 + 0x44) = wVar2 & 0xfffe;
    if ((wVar2 & 0x10) != 0) {
      *(word *)(iVar6 + 0x44) = wVar2 & 0xffee;
      _wakeup(iVar6);
    }
    iVar6 = 0x1f;
    goto locret_F004BA60;
  }
  *(sword *)(iVar6 + 0x66) = sVar1 + 1;
  *(word *)(iVar6 + 0x44) = *(word *)(iVar6 + 0x44) | 0x40;
  _iupdat(iVar6,1);
  iVar6 = *(int *)((int)register0x00000038 + 0x54);
  wVar2 = *(word *)(iVar6 + 0x44);
  *(word *)(iVar6 + 0x44) = wVar2 & 0xfffe;
  if ((wVar2 & 0x10) == 0) goto loc_F004B72C;
  *(word *)(iVar6 + 0x44) = wVar2 & 0xffee;
  _wakeup(iVar6);
  wVar2 = *(word *)(param_1 + 0x44);
  while ((wVar2 & 1) != 0) {
    *(word *)(param_1 + 0x44) = wVar2 | 0x10;
    _sleep(param_1,10);
loc_F004B72C:
    wVar2 = *(word *)(param_1 + 0x44);
  }
  *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 1;
  iVar6 = 0x14;
  if ((*(word *)(param_1 + 100) & 0xf000) == 0x4000) {
    if (*(sword *)(param_1 + 0x66) == 0) {
      iVar6 = 2;
      goto loc_F004B9E8;
    }
    iVar6 = param_1;
    _iaccess(param_1,0x40);
    if (iVar6 == 0) {
      if (((param_3 == 2) &&
          (iVar6 = *(int *)((int)register0x00000038 + 0x54),
          (*(word *)(iVar6 + 100) & 0xf000) == 0x4000)) && (param_4 != param_1)) {
        _iaccess(iVar6,0x80);
        iVar3 = *(int *)((int)register0x00000038 + -0x14);
        if (iVar6 == 0) {
          iVar6 = *(int *)((int)register0x00000038 + 0x54);
          sub_F004CEAC(iVar6,param_1);
          iVar3 = *(int *)((int)register0x00000038 + -0x14);
          if (iVar6 == 0) goto loc_F004B7F0;
        }
      }
      else {
loc_F004B7F0:
        puVar9 = (undefined *)((int)register0x00000038 + -0x20);
        iVar6 = param_1;
        sub_F004BA68(param_1,param_2,iVar7,puVar9,(undefined *)((int)register0x00000038 + -0x24));
        if (iVar6 == 0) {
          iVar3 = *(int *)((int)register0x00000038 + -0x24);
          if (iVar3 == 0) {
            iVar6 = param_1;
            _iaccess(param_1,0x80);
            if (iVar6 == 0) {
              if (param_3 == 0) {
                iVar6 = param_1;
                sub_F004C544(param_1,(undefined *)((int)register0x00000038 + 0x54),param_6);
                iVar3 = *(int *)((int)register0x00000038 + -0x14);
                if (iVar6 != 0) goto loc_F004B9EC;
              }
              iVar6 = param_1;
              _diraddentry(param_1,param_2,iVar7,puVar9,
                           *(undefined4 *)((int)register0x00000038 + 0x54),param_4);
              if (iVar6 == 0) {
                if (piVar8 == (int *)0x0) {
                  iVar3 = *(int *)((int)register0x00000038 + -0x14);
                  if (param_3 != 0) goto loc_F004B9EC;
                  _irele(*(undefined4 *)((int)register0x00000038 + 0x54));
                }
                else {
                  iVar7 = *(int *)((int)register0x00000038 + 0x54);
                  while ((*(word *)(iVar7 + 0x44) & 1) != 0) {
                    *(word *)(iVar7 + 0x44) = *(word *)(iVar7 + 0x44) | 0x10;
                    _sleep(iVar7,10);
                    iVar7 = *(int *)((int)register0x00000038 + 0x54);
                  }
                  iVar7 = *(int *)((int)register0x00000038 + 0x54);
                  *(word *)(iVar7 + 0x44) = *(word *)(iVar7 + 0x44) | 1;
                  *piVar8 = iVar7;
                }
              }
              else {
                iVar3 = *(int *)((int)register0x00000038 + -0x14);
                if (param_3 != 0) goto loc_F004B9EC;
                iVar7 = *(int *)((int)register0x00000038 + 0x54);
                if ((*(word *)(*(int *)((int)register0x00000038 + 0x54) + 100) & 0xf000) == 0x4000)
                {
                  *(sword *)(param_1 + 0x66) = *(sword *)(param_1 + 0x66) + -1;
                  iVar7 = *(int *)((int)register0x00000038 + 0x54);
                }
                *(undefined2 *)(iVar7 + 0x66) = 0;
                *(word *)(iVar7 + 0x44) = *(word *)(iVar7 + 0x44) | 0x40;
                _irele();
                *(undefined4 *)((int)register0x00000038 + 0x54) = 0;
              }
              goto loc_F004B9E8;
            }
            iVar3 = *(int *)((int)register0x00000038 + -0x14);
          }
          else {
            if (param_3 == 1) {
              _iput(iVar3);
              iVar6 = 0x11;
              goto loc_F004B9E8;
            }
            if (param_3 < 2) {
              if (piVar8 != (int *)0x0) {
                *piVar8 = iVar3;
                iVar6 = 0x11;
                goto loc_F004B9E8;
              }
              _iput(iVar3);
              iVar3 = *(int *)((int)register0x00000038 + -0x14);
            }
            else if (param_3 == 2) {
              sub_F004BD00(param_4,*(undefined4 *)((int)register0x00000038 + 0x54),param_1,param_2,
                           iVar7,iVar3,puVar9);
              _iput(*(undefined4 *)((int)register0x00000038 + -0x24));
              iVar3 = *(int *)((int)register0x00000038 + -0x14);
              iVar6 = param_4;
              if (*(sword *)(*(int *)((int)register0x00000038 + -0x24) + 0x66) == 0) {
                _vnode_uncache(*(int *)((int)register0x00000038 + -0x24) + 0xc);
                iVar3 = *(int *)((int)register0x00000038 + -0x14);
              }
            }
            else {
              iVar3 = *(int *)((int)register0x00000038 + -0x14);
            }
          }
        }
        else {
          iVar3 = *(int *)((int)register0x00000038 + -0x14);
        }
      }
    }
    else {
      iVar3 = *(int *)((int)register0x00000038 + -0x14);
    }
  }
  else {
loc_F004B9E8:
    iVar3 = *(int *)((int)register0x00000038 + -0x14);
  }
loc_F004B9EC:
  if (iVar3 != 0) {
    _brelse();
  }
  if ((iVar6 != 0) && (iVar7 = *(int *)((int)register0x00000038 + 0x54), param_3 != 0)) {
    *(sword *)(iVar7 + 0x66) = *(sword *)(iVar7 + 0x66) + -1;
    *(word *)(iVar7 + 0x44) = *(word *)(iVar7 + 0x44) | 0x40;
  }
  wVar2 = *(word *)(param_1 + 0x44);
  *(word *)(param_1 + 0x44) = wVar2 & 0xfffe;
  if ((wVar2 & 0x10) != 0) {
    *(word *)(param_1 + 0x44) = wVar2 & 0xffee;
    _wakeup(param_1);
  }
locret_F004BA60:
  return CONCAT44(param_2,iVar6);
}
/* GHIDRADEC_FUNCTION index=1013 start=0xf004c240 */

/* WARNING: Removing unreachable block (ram,0xf004c2e4) */
/* WARNING: Removing unreachable block (ram,0xf004c298) */
/* WARNING: Removing unreachable block (ram,0xf004c2c4) */
/* WARNING: Removing unreachable block (ram,0xf004c2ec) */
/* WARNING: Removing unreachable block (ram,0xf004c280) */

undefined8
_diraddentry(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,undefined4 param_6)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
  iVar1 = 0x12;
  if ((*(int *)(param_1 + 0x30) == *(int *)(param_5 + 0x30)) &&
     ((((*(word *)(param_5 + 100) & 0xf000) != 0x4000 ||
       (iVar1 = param_5, sub_F004BF10(param_5,param_6,param_1), iVar1 == 0)) &&
      (iVar1 = param_1, sub_F004C32C(param_1,param_4), iVar1 == 0)))) {
    *(sword *)(*(int *)(param_4 + 0x10) + 6) = (sword)param_3;
    _strncpy(*(int *)(param_4 + 0x10) + 8,param_2,param_3 + 4U & 0xfffffffc);
    **(undefined4 **)(param_4 + 0x10) = *(undefined4 *)(param_5 + 0x48);
    _dnlc_enter(param_1 + 0xc,param_2,param_5 + 0xc,0);
    _bwrite(*(undefined4 *)(param_4 + 0xc));
    *(undefined4 *)(param_4 + 0xc) = 0;
    iVar1 = (int)*(char *)(dword_F0133DDC + 0x38);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x4c) = 0;
      iVar1 = 0;
      *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1014 start=0xf004c864 */

/* WARNING: Removing unreachable block (ram,0xf004cba0) */
/* WARNING: Removing unreachable block (ram,0xf004cb6c) */
/* WARNING: Removing unreachable block (ram,0xf004cb30) */
/* WARNING: Removing unreachable block (ram,0xf004ca88) */
/* WARNING: Removing unreachable block (ram,0xf004ca30) */
/* WARNING: Removing unreachable block (ram,0xf004c92c) */
/* WARNING: Removing unreachable block (ram,0xf004c880) */
/* WARNING: Removing unreachable block (ram,0xf004c8e8) */
/* WARNING: Removing unreachable block (ram,0xf004c958) */
/* WARNING: Removing unreachable block (ram,0xf004ca50) */
/* WARNING: Removing unreachable block (ram,0xf004cb1c) */
/* WARNING: Removing unreachable block (ram,0xf004cb3c) */
/* WARNING: Removing unreachable block (ram,0xf004cb88) */
/* WARNING: Removing unreachable block (ram,0xf004cbd4) */
/* WARNING: Removing unreachable block (ram,0xf004c868) */

undefined8 _dirremove(int param_1,char *param_2,int param_3,int param_4)

{
  char cVar1;
  sword sVar2;
  word wVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar9;
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
  pcVar4 = param_2;
  _strlen();
  if (pcVar4 == (char *)0x0) {
    _panic(aDirremove);
    cVar1 = *param_2;
  }
  else {
    cVar1 = *param_2;
  }
  if (cVar1 == '.') {
    if (pcVar4 == (char *)0x1) {
      iVar9 = 0x16;
      goto locret_F004CBE0;
    }
    if (pcVar4 == (char *)0x2) {
      if (param_2[1] == '.') {
        iVar9 = 0x42;
        goto locret_F004CBE0;
      }
      *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
    }
    else {
      *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
    }
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  }
  wVar3 = *(word *)(param_1 + 0x44);
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
  while ((wVar3 & 1) != 0) {
    *(word *)(param_1 + 0x44) = wVar3 | 0x10;
    _sleep(param_1,10);
    wVar3 = *(word *)(param_1 + 0x44);
  }
  *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 1;
  iVar7 = 0x14;
  if ((*(word *)(param_1 + 100) & 0xf000) != 0x4000) goto loc_F004CB5C;
  iVar9 = param_1;
  _iaccess(param_1,0xc0);
  iVar5 = *(int *)((int)register0x00000038 + -0x24);
  if (iVar9 == 0) {
    *(undefined4 *)((int)register0x00000038 + -0x20) = 2;
    iVar9 = param_1;
    sub_F004BA68(param_1,param_2,pcVar4,(undefined *)((int)register0x00000038 + -0x20),
                 (undefined *)((int)register0x00000038 + -0x24));
    iVar5 = *(int *)((int)register0x00000038 + -0x24);
    if (iVar9 == 0) {
      if (iVar5 == 0) {
loc_F004C988:
        iVar7 = 2;
        goto loc_F004CB5C;
      }
      if (param_3 == 0) {
        wVar3 = *(word *)(param_1 + 100);
      }
      else {
        if (param_3 != iVar5) goto loc_F004C988;
        wVar3 = *(word *)(param_1 + 100);
      }
      if ((wVar3 & 0x200) == 0) {
        iVar7 = *(int *)((int)register0x00000038 + -0x24);
loc_F004C9E4:
        iVar5 = *(int *)(iVar7 + 0x18);
      }
      else {
        sVar2 = *(sword *)(*(int *)(_active_u + 0x1c) + 2);
        iVar7 = *(int *)((int)register0x00000038 + -0x24);
        if ((sVar2 == 0) || (sVar2 == *(sword *)(param_1 + 0x68))) goto loc_F004C9E4;
        if (*(sword *)(*(int *)((int)register0x00000038 + -0x24) + 0x68) != sVar2) {
          iVar7 = 1;
          goto loc_F004CB5C;
        }
        iVar5 = *(int *)(iVar7 + 0x18);
      }
      if (iVar5 == 0) {
        if ((param_4 == 0) || ((*(word *)(iVar7 + 100) & 0xf000) != 0x4000)) {
loc_F004CA50:
          _dnlc_remove(param_1 + 0xc,param_2);
          puVar8 = *(undefined4 **)((int)register0x00000038 + -0x10);
          if ((*(uint *)((int)register0x00000038 + -0x1c) & 0x3ff) == 0) {
            *puVar8 = 0;
          }
          else {
            *(sword *)((int)puVar8 + (4 - *(int *)((int)register0x00000038 + -0x18))) =
                 *(sword *)((int)puVar8 + (4 - *(int *)((int)register0x00000038 + -0x18))) +
                 *(sword *)(puVar8 + 1);
          }
          _bwrite(*(undefined4 *)((int)register0x00000038 + -0x14));
          *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
          iVar5 = *(int *)((int)register0x00000038 + -0x24);
          *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
          *(word *)(iVar5 + 0x44) = *(word *)(iVar5 + 0x44) | 0x40;
          iVar7 = (int)*(char *)(dword_F0133DDC + 0x38);
          if ((iVar7 == 0) && (iVar7 = iVar9, 0 < *(sword *)(iVar5 + 0x66))) {
            if (param_4 == 0) {
              iVar6 = *(int *)((int)register0x00000038 + -0x24);
            }
            else {
              iVar6 = *(int *)((int)register0x00000038 + -0x24);
              if ((*(word *)(iVar5 + 100) & 0xf000) == 0x4000) {
                *(sword *)(iVar5 + 0x66) = *(sword *)(iVar5 + 0x66) + -2;
                *(sword *)(param_1 + 0x66) = *(sword *)(param_1 + 0x66) + -1;
                _dnlc_remove(iVar5 + 0xc,&asc_F010EB18);
                _dnlc_remove(*(int *)((int)register0x00000038 + -0x24) + 0xc,&asc_F010EB20);
                _itrunc(*(undefined4 *)((int)register0x00000038 + -0x24),0);
                iVar5 = *(int *)((int)register0x00000038 + -0x24);
                goto loc_F004CB60;
              }
            }
            *(sword *)(iVar6 + 0x66) = *(sword *)(iVar6 + 0x66) + -1;
          }
        }
        else if (*(sword *)(iVar7 + 0x66) == 2) {
          sub_F004CDC4(iVar7,*(undefined4 *)(param_1 + 0x48));
          if (iVar7 != 0) goto loc_F004CA50;
          iVar7 = 0x42;
        }
        else {
          iVar7 = 0x42;
        }
      }
      else {
        iVar7 = 0x10;
      }
loc_F004CB5C:
      iVar5 = *(int *)((int)register0x00000038 + -0x24);
      iVar9 = iVar7;
    }
  }
loc_F004CB60:
  if (iVar5 == 0) {
    iVar7 = *(int *)((int)register0x00000038 + -0x14);
  }
  else {
    _iput();
    iVar7 = *(int *)((int)register0x00000038 + -0x14);
    if (*(sword *)(*(int *)((int)register0x00000038 + -0x24) + 0x66) == 0) {
      _vnode_uncache(*(int *)((int)register0x00000038 + -0x24) + 0xc);
      iVar7 = *(int *)((int)register0x00000038 + -0x14);
    }
  }
  if (iVar7 == 0) {
    wVar3 = *(word *)(param_1 + 0x44);
  }
  else {
    _brelse();
    wVar3 = *(word *)(param_1 + 0x44);
  }
  *(word *)(param_1 + 0x44) = wVar3 & 0xfffe;
  if ((wVar3 & 0x10) != 0) {
    *(word *)(param_1 + 0x44) = wVar3 & 0xffee;
    _wakeup(param_1);
  }
locret_F004CBE0:
  return CONCAT44(param_2,iVar9);
}
/* GHIDRADEC_FUNCTION index=1015 start=0xf004cbe8 */

/* WARNING: Removing unreachable block (ram,0xf004cca8) */
/* WARNING: Removing unreachable block (ram,0xf004cc6c) */
/* WARNING: Removing unreachable block (ram,0xf004ccc4) */
/* WARNING: Removing unreachable block (ram,0xf004cc44) */

undefined8 _blkatoff(int param_1,uint param_2,int *param_3)

{
  byte bVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint *puVar6;
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
  iVar3 = *(int *)(param_1 + 0x50);
  bVar1 = (byte)*(undefined4 *)(iVar3 + 0x50);
  uVar2 = param_2 >> (bVar1 & 0x1f);
  if ((int)uVar2 < 0xc) {
    if (*(uint *)(param_1 + 0x70) < uVar2 + 1 << (bVar1 & 0x1f)) {
      uVar5 = ((*(uint *)(param_1 + 0x70) & ~*(uint *)(iVar3 + 0x48)) + *(int *)(iVar3 + 0x34)) - 1
              & *(uint *)(iVar3 + 0x4c);
    }
    else {
      uVar5 = *(uint *)(iVar3 + 0x30);
    }
  }
  else {
    uVar5 = *(uint *)(iVar3 + 0x30);
  }
  iVar4 = param_1;
  _bmap(param_1,uVar2,1);
  iVar4 = iVar4 << ((byte)*(undefined4 *)(iVar3 + 100) & 0x1f);
  if (iVar4 < 0) {
    sub_F004CD8C(param_1,aNonexixtentDir,param_2);
    *(undefined *)(dword_F0133DDC + 0x38) = 2;
  }
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    puVar6 = *(uint **)(param_1 + 0x40);
    _bread(puVar6,iVar4,uVar5);
    if ((*puVar6 & 4) == 0) {
      if (param_3 != (int *)0x0) {
        *param_3 = puVar6[8] + (param_2 & ~*(uint *)(iVar3 + 0x48));
      }
    }
    else {
      _brelse(puVar6);
      puVar6 = (uint *)0x0;
    }
  }
  else {
    puVar6 = (uint *)0x0;
  }
  return CONCAT44(param_2,puVar6);
}
/* GHIDRADEC_FUNCTION index=1016 start=0xf004d6d4 */

/* WARNING: Removing unreachable block (ram,0xf004d724) */
/* WARNING: Removing unreachable block (ram,0xf004d6e0) */

undefined8 _disksort_enter(int param_1,int param_2)

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
  
  iVar1 = _active_threads;
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
  sub_F004D11C(param_1);
  if (*(int *)(param_1 + 0xc) < 0) {
    (*_ds_call)(param_1,param_2);
  }
  else {
    if (iVar1 != 0) {
      *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(iVar1 + 0x50);
    }
    sub_F004D454(param_1,param_2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1017 start=0xf004d734 */

/* WARNING: Removing unreachable block (ram,0xf004d770) */
/* WARNING: Removing unreachable block (ram,0xf004d738) */

undefined8 _disksort_enter_head(int param_1,int param_2)

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
  sub_F004D11C(param_1);
  if (*(int *)(param_1 + 0xc) < 0) {
    (*dword_F013AD84)(param_1,param_2);
  }
  else {
    *(undefined4 *)(param_2 + 0x3c) = 0x1f;
    sub_F004D454(param_1,param_2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1018 start=0xf004d780 */

/* WARNING: Removing unreachable block (ram,0xf004d7b8) */
/* WARNING: Removing unreachable block (ram,0xf004d784) */

undefined8 _disksort_enter_tail(int param_1,int param_2)

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
  sub_F004D11C(param_1);
  if (*(int *)(param_1 + 0xc) < 0) {
    (*_ds_call)(param_1,param_2);
  }
  else {
    *(undefined4 *)(param_2 + 0x3c) = 0;
    sub_F004D454(param_1,param_2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1019 start=0xf004d7c8 */

/* WARNING: Removing unreachable block (ram,0xf004d7fc) */
/* WARNING: Removing unreachable block (ram,0xf004d818) */
/* WARNING: Removing unreachable block (ram,0xf004d850) */
/* WARNING: Removing unreachable block (ram,0xf004d7d0) */

undefined8 _disksort_first(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  int *piVar2;
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
  uVar3 = param_2;
  sub_F004D11C(param_1);
  puVar1 = DAT_f013ac00;
  if (*(int *)(param_1 + 0xc) < 0) {
    (*dword_F013AD8C)(param_1);
  }
  else {
    _spltty();
    do {
      do {
      } while (*(int *)(param_1 + 0x24) != 0);
      piVar2 = (int *)(param_1 + 0x24);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    if (param_1 + 0x10 != *(int *)(param_1 + 0x10)) {
      *(undefined4 *)(param_1 + 0x24) = 0;
      _splx(puVar1);
      return CONCAT44(uVar3,puVar1);
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
    _splx(puVar1);
    param_1 = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1020 start=0xf004d864 */

/* WARNING: Removing unreachable block (ram,0xf004da34) */
/* WARNING: Removing unreachable block (ram,0xf004d8b4) */
/* WARNING: Removing unreachable block (ram,0xf004d898) */
/* WARNING: Removing unreachable block (ram,0xf004d9ec) */
/* WARNING: Removing unreachable block (ram,0xf004d8dc) */
/* WARNING: Removing unreachable block (ram,0xf004d868) */

undefined8 _disksort_remove(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  undefined4 unaff_l0;
  int *piVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar8;
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
  sub_F004D11C(param_1);
  iVar1 = param_1[3];
  if (iVar1 < 0) {
    (*dword_F013AD90)(param_1,param_2);
    piVar8 = param_1;
  }
  else {
    _spltty();
    do {
      do {
      } while (param_1[9] != 0);
      piVar2 = param_1 + 9;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    piVar2 = (int *)param_1[4];
    if (param_1 + 4 == piVar2) {
      param_1[9] = 0;
      _splx(iVar1);
      piVar8 = (int *)0x0;
    }
    else {
      piVar8 = (int *)*piVar2;
      while (iVar3 = piVar8[3], piVar7 = piVar8, piVar8 != param_2) {
        while ((piVar8 = (int *)piVar7[3], iVar3 != 0 && (piVar8 != param_2))) {
          iVar3 = piVar8[3];
          piVar7 = piVar8;
        }
        if (piVar8 != (int *)0x0) {
          iVar3 = param_2[3];
          piVar7[3] = iVar3;
          piVar8 = param_2;
          if (iVar3 == 0) {
            piVar2[1] = (int)piVar7;
          }
          goto loc_F004D980;
        }
        piVar2 = (int *)piVar2[4];
        piVar8 = piVar7;
        if (param_1 + 4 == piVar2) goto loc_F004D980;
        piVar8 = (int *)*piVar2;
      }
      *piVar2 = iVar3;
      uVar4 = param_1[3];
      if (piVar2 == (int *)param_1[4]) {
        param_1[3] = uVar4 & 0xefffffff;
        param_1[7] = piVar8[0xe];
loc_F004D980:
        uVar4 = param_1[3];
      }
      piVar2 = (int *)param_1[4];
      if ((((uVar4 & 0x10000000) == 0) && (piVar7 = param_1 + 4, piVar7 != piVar2)) &&
         (*piVar2 == 0)) {
        piVar6 = (int *)piVar2[4];
        while( true ) {
          piVar5 = (int *)piVar2[5];
          if (param_1 + 4 == piVar6) {
            param_1[5] = (int)piVar5;
          }
          else {
            piVar6[5] = (int)piVar5;
          }
          if (piVar7 == piVar5) {
            param_1[4] = (int)piVar6;
          }
          else {
            piVar5[4] = (int)piVar6;
          }
          _kfree(piVar2,0x18);
          piVar2 = (int *)param_1[4];
          param_1[6] = param_1[6] + 1;
          param_2 = piVar7;
          if ((((param_1[3] & 0x10000000U) != 0) || (param_1 + 4 == piVar2)) || (*piVar2 != 0))
          break;
          piVar6 = (int *)piVar2[4];
        }
      }
      param_1[9] = 0;
      _splx(iVar1);
    }
  }
  return CONCAT44(param_2,piVar8);
}
/* GHIDRADEC_FUNCTION index=1021 start=0xf004da48 */

/* WARNING: Removing unreachable block (ram,0xf004da58) */
/* WARNING: Removing unreachable block (ram,0xf004da50) */

undefined8 _disksort_init(int param_1,undefined4 param_2)

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
  _bzero(param_1,0x28);
  sub_F004D11C(param_1);
  *(int *)(param_1 + 0x14) = param_1 + 0x10;
  *(int *)(param_1 + 0x10) = param_1 + 0x10;
  *(undefined4 *)(param_1 + 0x18) = 0x14;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1022 start=0xf004da80 */

undefined8 _disksort_free(int param_1,undefined4 param_2)

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
  if (((int)*(uint *)(param_1 + 0xc) < 0) &&
     (*(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0x7fffffff, dword_F013AD9C != 0)) {
    (*DAT_f013ad98)(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1023 start=0xf004dac4 */

/* WARNING: Removing unreachable block (ram,0xf004dae0) */
/* WARNING: Removing unreachable block (ram,0xf004db0c) */
/* WARNING: Removing unreachable block (ram,0xf004dacc) */

undefined8 _new_inode(undefined4 param_1,undefined4 param_2)

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
  int iVar2;
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
  iVar2 = _inode_zone;
  _zalloc();
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    _bzero();
    *(int *)iVar2 = iVar2;
    *(int *)(iVar2 + 4) = iVar2;
    *(undefined4 *)(iVar2 + 0x5c) = 0;
    *(undefined4 *)(iVar2 + 0x60) = 0;
    *(int *)(iVar2 + 0x3c) = iVar2;
    *(undefined **)(iVar2 + 0x28) = _ufs_vnodeops;
    *(undefined4 *)(iVar2 + 0xc) = 0;
    _vm_info_init(iVar2 + 0xc);
    iVar1 = _inode_list;
    _inode_list = iVar2;
    *(uint *)(*(int *)(iVar2 + 0xc) + 0x38) = *(uint *)(*(int *)(iVar2 + 0xc) + 0x38) & 0xdfffffff;
    *(int *)(iVar2 + 8) = iVar1;
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1024 start=0xf004db40 */

/* WARNING: Removing unreachable block (ram,0xf004dc2c) */
/* WARNING: Removing unreachable block (ram,0xf004dba8) */
/* WARNING: Removing unreachable block (ram,0xf004dc38) */
/* WARNING: Removing unreachable block (ram,0xf004db80) */

undefined8 _inode_cache_clear(undefined4 param_1,undefined4 param_2)

{
  word wVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
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
  
  piVar2 = _ifreeh;
  iVar7 = _inode_list;
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
  while (_inode_list = iVar7, piVar2 != (int *)0x0) {
    _ifreeh = (int *)piVar2[0x17];
    if (_ifreeh != (int *)0x0) {
      _ifreeh[0x18] = (int)&_ifreeh;
    }
    piVar2[0x17] = 0;
    piVar2[0x18] = 0;
    _mfs_uncache(piVar2 + 3);
    *(undefined2 *)(piVar2 + 0x11) = 0x8000;
    *(word *)(piVar2 + 0x11) = *(word *)(piVar2 + 0x11) | 1;
    if (*(sword *)((int)piVar2 + 0x12) != 0) {
      _panic(aFreeInodeIsnT);
    }
    *(int *)(*piVar2 + 4) = piVar2[1];
    piVar3 = _ifreeh;
    *(int *)piVar2[1] = *piVar2;
    piVar2 = piVar3;
    iVar7 = _inode_list;
  }
  if (iVar7 != 0) {
    wVar1 = *(word *)(iVar7 + 0x44);
    iVar5 = iVar7;
    while( true ) {
      if ((wVar1 & 0x8000) == 0) {
        iVar6 = *(int *)(iVar5 + 8);
        iVar7 = iVar5;
      }
      else {
        iVar4 = *(int *)(iVar5 + 8);
        iVar6 = iVar4;
        if (iVar7 != iVar5) {
          *(int *)(iVar7 + 8) = iVar4;
          iVar4 = iVar7;
          iVar6 = _inode_list;
        }
        _inode_list = iVar6;
        iVar6 = *(int *)(iVar5 + 8);
        _zfree(_vm_info_zone,*(undefined4 *)(iVar5 + 0xc));
        _zfree(_inode_zone,iVar5);
        iVar7 = iVar4;
      }
      if (iVar6 == 0) break;
      wVar1 = *(word *)(iVar6 + 0x44);
      iVar5 = iVar6;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1025 start=0xf004dc68 */

/* WARNING: Removing unreachable block (ram,0xf004dcc0) */

undefined8 _ihinit(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
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
  puVar1 = _ihead;
  iVar3 = 0x1ff;
  do {
    *(undefined **)puVar1 = puVar1;
    *(undefined **)(puVar1 + 4) = puVar1;
    iVar3 = iVar3 + -1;
    puVar1 = puVar1 + 8;
  } while (-1 < iVar3);
  _ifreeh = 0;
  _ifreet = 0;
  _inode_list = 0;
  uVar2 = 0xe8;
  _zinit(0xe8,0x236680,0,0,aInodeStructure);
  _inode_zone = uVar2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1026 start=0xf004dcd8 */

/* WARNING: Removing unreachable block (ram,0xf004e0c8) */
/* WARNING: Removing unreachable block (ram,0xf004e058) */
/* WARNING: Removing unreachable block (ram,0xf004dfe0) */
/* WARNING: Removing unreachable block (ram,0xf004dfb0) */
/* WARNING: Removing unreachable block (ram,0xf004df7c) */
/* WARNING: Removing unreachable block (ram,0xf004df10) */
/* WARNING: Removing unreachable block (ram,0xf004de8c) */
/* WARNING: Removing unreachable block (ram,0xf004de38) */
/* WARNING: Removing unreachable block (ram,0xf004dde4) */
/* WARNING: Removing unreachable block (ram,0xf004dd00) */
/* WARNING: Removing unreachable block (ram,0xf004dd1c) */
/* WARNING: Removing unreachable block (ram,0xf004dea8) */
/* WARNING: Removing unreachable block (ram,0xf004de54) */
/* WARNING: Removing unreachable block (ram,0xf004dee4) */
/* WARNING: Removing unreachable block (ram,0xf004df6c) */
/* WARNING: Removing unreachable block (ram,0xf004df94) */
/* WARNING: Removing unreachable block (ram,0xf004dfb8) */
/* WARNING: Removing unreachable block (ram,0xf004dffc) */
/* WARNING: Removing unreachable block (ram,0xf004e0b0) */
/* WARNING: Removing unreachable block (ram,0xf004e174) */
/* WARNING: Removing unreachable block (ram,0xf004dce8) */

undefined8 _iget(sword param_1,int param_2,int *param_3)

{
  word wVar1;
  undefined2 uVar2;
  int *piVar3;
  undefined *puVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  undefined4 unaff_l0;
  int *piVar9;
  uint uVar10;
  undefined4 unaff_l1;
  int *piVar11;
  undefined4 uVar12;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar13;
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
loc_F004DCE4:
  do {
    piVar9 = (int *)(int)param_1;
    piVar3 = piVar9;
    _getmp();
    if (piVar3 == (int *)0x0) {
      _panic(aIgetBadDev);
      iVar5 = iRam0000000c;
    }
    else {
      iVar5 = piVar3[3];
    }
    if (*(int *)(iVar5 + 0x20) != param_2) {
      _panic(aIgetBadFs);
    }
    iVar5 = ((uint)((int)piVar9 + (int)param_3) & 0x1ff) * 8;
    puVar4 = _ihead;
    piVar13 = *(int **)(_ihead + iVar5);
    piVar11 = (int *)(_ihead + iVar5);
    if (piVar13 != piVar11) {
      puVar4 = (undefined *)piVar13[0x12];
      while( true ) {
        if (param_3 == (int *)puVar4) {
          puVar4 = (undefined *)(int)*(sword *)((int)piVar13 + 0x46);
          if (piVar9 == (int *)puVar4) {
            wVar1 = *(word *)(piVar13 + 0x11);
            if ((wVar1 & 1) == 0) {
              if ((wVar1 & 0x100) == 0) {
                iVar5 = piVar13[0x17];
                piVar3 = (int *)piVar13[0x18];
                if (iVar5 != 0) {
                  *(int **)(iVar5 + 0x60) = (int *)piVar13[0x18];
                  piVar3 = _ifreet;
                }
                _ifreet = piVar3;
                *(int *)piVar13[0x18] = iVar5;
                piVar13[0x17] = 0;
                piVar13[0x18] = 0;
                *(undefined4 *)piVar13[3] = 0;
                wVar1 = *(word *)(piVar13 + 0x11);
              }
              *(word *)(piVar13 + 0x11) = wVar1 | 0x100;
              while ((wVar1 & 1) != 0) {
                *(word *)(piVar13 + 0x11) = *(word *)(piVar13 + 0x11) | 0x10;
                _sleep(piVar13,10);
                wVar1 = *(word *)(piVar13 + 0x11);
              }
              *(word *)(piVar13 + 0x11) = *(word *)(piVar13 + 0x11) | 1;
              *(sword *)((int)piVar13 + 0x12) = *(sword *)((int)piVar13 + 0x12) + 1;
              goto locret_F004E190;
            }
            *(word *)(piVar13 + 0x11) = wVar1 | 0x10;
            _sleep(piVar13,10);
            goto loc_F004DCE4;
          }
          piVar13 = (int *)*piVar13;
        }
        else {
          piVar13 = (int *)*piVar13;
        }
        if (piVar13 == piVar11) break;
        puVar4 = (undefined *)piVar13[0x12];
      }
    }
    if (_ifreeh != (int *)0x0) {
      piVar9 = (int *)_ifreeh[0x17];
      piVar13 = _ifreeh;
      goto loc_F004DEC0;
    }
    _new_inode();
    if ((int *)puVar4 != (int *)0x0) {
      *(int **)((int)puVar4 + 0x5c) = _ifreeh;
      piVar9 = *(int **)((int)puVar4 + 0x5c);
      piVar13 = (int *)puVar4;
      goto loc_F004DEC0;
    }
    do {
      if (_ifreeh != (int *)0x0) break;
      piVar9 = _ifreeh;
      _dnlc_purge1();
    } while (piVar9 == (int *)0x1);
    piVar13 = _ifreeh;
  } while (_ifreeh != (int *)0x0);
  _panic(aIgetOutOfInode);
  piVar9 = piRam0000005c;
loc_F004DEC0:
  if (piVar9 != (int *)0x0) {
    piVar9[0x18] = (int)&_ifreeh;
  }
  _ifreeh = piVar9;
  piVar13[0x17] = 0;
  piVar13[0x18] = 0;
  _mfs_uncache(piVar13 + 3);
  *(undefined2 *)(piVar13 + 0x11) = 0x100;
  *(word *)(piVar13 + 0x11) = *(word *)(piVar13 + 0x11) | 1;
  if (*(sword *)((int)piVar13 + 0x12) != 0) {
    _panic(aFreeInodeIsnT_0);
  }
  *(int *)(*piVar13 + 4) = piVar13[1];
  *(int *)piVar13[1] = *piVar13;
  *piVar13 = *piVar11;
  piVar13[1] = (int)piVar11;
  *(int **)(*piVar11 + 4) = piVar13;
  *piVar11 = (int)piVar13;
  *(sword *)((int)piVar13 + 0x46) = param_1;
  piVar13[0x10] = piVar3[2];
  piVar13[0x12] = (int)param_3;
  piVar13[0x13] = 0;
  piVar13[0x14] = param_2;
  piVar13[0x16] = 0;
  uVar12 = *(undefined4 *)(param_2 + 0xb8);
  piVar9 = param_3;
  .udiv(param_3,uVar12);
  iVar5 = *(int *)(param_2 + 0xbc);
  .umul(iVar5,piVar9);
  iVar7 = *(int *)(param_2 + 0x18);
  .umul(iVar7,(uint)piVar9 & ~*(uint *)(param_2 + 0x1c));
  iVar8 = *(int *)(param_2 + 0x10);
  piVar9 = param_3;
  .urem(param_3,uVar12);
  .udiv();
  puVar6 = (uint *)piVar13[0x10];
  _bread(puVar6,iVar5 + iVar7 + iVar8 +
                ((int)piVar9 << ((byte)*(undefined4 *)(param_2 + 0x60) & 0x1f)) <<
                ((byte)*(undefined4 *)(param_2 + 100) & 0x1f),*(undefined4 *)(param_2 + 0x30));
  if ((*puVar6 & 4) == 0) {
    uVar10 = puVar6[8];
    piVar9 = param_3;
    .urem(param_3,*(undefined4 *)(param_2 + 0x78));
    _memcpy(piVar13 + 0x19,uVar10 + (int)piVar9 * 0x80,0x80);
    *(undefined2 *)(piVar13 + 4) = 0;
    *(undefined2 *)((int)piVar13 + 0x12) = 1;
    *(undefined2 *)((int)piVar13 + 0x16) = 0;
    *(undefined2 *)(piVar13 + 5) = 0;
    piVar13[0xc] = *piVar3;
    piVar13[0xd] = *(int *)(_iftovt_tab + (uint)(*(word *)(piVar13 + 0x19) >> 0xd) * 4);
    piVar13[0xb] = 0;
    piVar13[9] = 0;
    piVar13[8] = 0;
    *(sword *)(piVar13 + 0xe) = (sword)piVar13[0x23];
    if (param_3 == (int *)0x2) {
      *(word *)(piVar13 + 4) = *(word *)(piVar13 + 4) | 1;
    }
    if (*(sword *)(piVar13[0xc] + 0x124) != 0) {
      *(undefined2 *)(piVar13 + 0x39) = *(undefined2 *)(piVar13 + 0x1a);
      *(undefined2 *)((int)piVar13 + 0xe6) = *(undefined2 *)((int)piVar13 + 0x6a);
      uVar2 = _nogroup;
      *(undefined2 *)(piVar13 + 0x1a) = *(undefined2 *)(piVar13[0xc] + 0x124);
      *(undefined2 *)((int)piVar13 + 0x6a) = uVar2;
    }
    _brelse(puVar6);
    *(undefined4 *)piVar13[3] = 0;
    *(int *)(piVar13[3] + 0x14) = piVar13[0x1c];
  }
  else {
    _brelse(puVar6);
    *(int *)(*piVar13 + 4) = piVar13[1];
    *(int *)piVar13[1] = *piVar13;
    *piVar13 = (int)piVar13;
    piVar13[1] = (int)piVar13;
    piVar13[0x12] = 0;
    *(undefined2 *)((int)piVar13 + 0x12) = 0;
    wVar1 = *(word *)(piVar13 + 0x11);
    *(word *)(piVar13 + 0x11) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(piVar13 + 0x11) = wVar1 & 0xffee;
      _wakeup(piVar13);
    }
    piVar3 = _ifreeh;
    *(undefined2 *)(piVar13 + 0x11) = 0;
    piVar9 = (int *)&_ifreeh;
    piVar11 = piVar13;
    if (piVar3 != (int *)0x0) {
      *_ifreet = (int)piVar13;
      piVar9 = _ifreet;
      piVar11 = _ifreeh;
    }
    _ifreeh = piVar11;
    piVar13[0x18] = (int)piVar9;
    piVar13[0x17] = 0;
    _ifreet = piVar13 + 0x17;
    piVar13 = (int *)0x0;
  }
locret_F004E190:
  return CONCAT44(param_2,piVar13);
}
/* GHIDRADEC_FUNCTION index=1027 start=0xf004e198 */

/* WARNING: Removing unreachable block (ram,0xf004e204) */
/* WARNING: Removing unreachable block (ram,0xf004e1e4) */
/* WARNING: Removing unreachable block (ram,0xf004e264) */
/* WARNING: Removing unreachable block (ram,0xf004e1b0) */

undefined8 _iput(int param_1,undefined4 param_2)

{
  word wVar1;
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
  if ((*(word *)(param_1 + 0x44) & 1) == 0) {
    _panic(&aIput);
    wVar1 = *(word *)(param_1 + 0x44);
  }
  else {
    wVar1 = *(word *)(param_1 + 0x44);
  }
  *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
  if ((wVar1 & 0x10) != 0) {
    *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
    _wakeup(param_1);
  }
  if ((*(word *)(param_1 + 0x44) & 0x46) != 0) {
    *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 8;
    _microtime(&_iuniqtime);
    if ((*(word *)(param_1 + 0x44) & 4) != 0) {
      *(undefined4 *)(param_1 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(param_1 + 0x44) & 2) != 0) {
      *(undefined4 *)(param_1 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(param_1 + 0x44) & 0x40) == 0) {
      wVar1 = *(word *)(param_1 + 0x44);
    }
    else {
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined4 *)(param_1 + 0x84) = _iuniqtime;
      wVar1 = *(word *)(param_1 + 0x44);
    }
    *(word *)(param_1 + 0x44) = wVar1 & 0xffb9;
  }
  _vn_rele(param_1 + 0xc);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1028 start=0xf004e274 */

/* WARNING: Removing unreachable block (ram,0xf004e2a8) */
/* WARNING: Removing unreachable block (ram,0xf004e308) */
/* WARNING: Removing unreachable block (ram,0xf004e288) */

undefined8 _irele(int param_1,undefined4 param_2)

{
  word wVar1;
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
  if ((*(word *)(param_1 + 0x44) & 1) != 0) {
    _panic(&aIrele);
  }
  if ((*(word *)(param_1 + 0x44) & 0x46) != 0) {
    *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 8;
    _microtime(&_iuniqtime);
    if ((*(word *)(param_1 + 0x44) & 4) != 0) {
      *(undefined4 *)(param_1 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(param_1 + 0x44) & 2) != 0) {
      *(undefined4 *)(param_1 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(param_1 + 0x44) & 0x40) == 0) {
      wVar1 = *(word *)(param_1 + 0x44);
    }
    else {
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined4 *)(param_1 + 0x84) = _iuniqtime;
      wVar1 = *(word *)(param_1 + 0x44);
    }
    *(word *)(param_1 + 0x44) = wVar1 & 0xffb9;
  }
  _vn_rele(param_1 + 0xc);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1029 start=0xf004e318 */

/* WARNING: Removing unreachable block (ram,0xf004e364) */
/* WARNING: Removing unreachable block (ram,0xf004e330) */

undefined8 _idrop(int param_1,undefined4 param_2)

{
  word wVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
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
  if ((*(word *)(param_1 + 0x44) & 1) == 0) {
    _panic(&aIdrop);
    wVar1 = *(word *)(param_1 + 0x44);
  }
  else {
    wVar1 = *(word *)(param_1 + 0x44);
  }
  *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
  if ((wVar1 & 0x10) != 0) {
    *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
    _wakeup(param_1);
  }
  sVar2 = *(sword *)(param_1 + 0x12);
  *(sword *)(param_1 + 0x12) = sVar2 + -1;
  iVar3 = _ifreeh;
  if (sVar2 == 1) {
    *(undefined2 *)(param_1 + 0x44) = 0;
    piVar5 = &_ifreeh;
    iVar4 = param_1;
    if (iVar3 != 0) {
      *_ifreet = param_1;
      piVar5 = _ifreet;
      iVar4 = _ifreeh;
    }
    _ifreeh = iVar4;
    *(int **)(param_1 + 0x60) = piVar5;
    *(undefined4 *)(param_1 + 0x5c) = 0;
    _ifreet = (int *)(param_1 + 0x5c);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1030 start=0xf004e3d0 */

/* WARNING: Removing unreachable block (ram,0xf004e4bc) */
/* WARNING: Removing unreachable block (ram,0xf004e480) */
/* WARNING: Removing unreachable block (ram,0xf004e434) */
/* WARNING: Removing unreachable block (ram,0xf004e4a4) */
/* WARNING: Removing unreachable block (ram,0xf004e4f0) */
/* WARNING: Removing unreachable block (ram,0xf004e408) */

undefined8 _iinactive(int param_1,undefined4 param_2)

{
  word wVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
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
  if ((((*(word *)(param_1 + 0x44) & 0x101) != 0x100) || (*(int *)(param_1 + 0x60) != 0)) ||
     (*(int *)(param_1 + 0x5c) != 0)) {
    _panic(aIinactive);
  }
  if (*(char *)(*(int *)(param_1 + 0x50) + 0xd2) == '\0') {
    wVar1 = *(word *)(param_1 + 0x44);
    while ((wVar1 & 1) != 0) {
      *(word *)(param_1 + 0x44) = wVar1 | 0x10;
      _sleep(param_1,10);
      wVar1 = *(word *)(param_1 + 0x44);
    }
    *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 1;
    if (*(sword *)(param_1 + 0x66) < 1) {
      *(int *)(param_1 + 0xd0) = *(int *)(param_1 + 0xd0) + 1;
      *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x200;
      _itrunc(param_1,0);
      *(undefined4 *)(param_1 + 0x8c) = 0;
      uVar2 = *(undefined2 *)(param_1 + 100);
      *(undefined2 *)(param_1 + 100) = 0;
      *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
      _ifree(param_1,*(undefined4 *)(param_1 + 0x48),uVar2);
    }
    if ((*(word *)(param_1 + 0x44) & 0x4e) != 0) {
      _iupdat(param_1,0);
    }
    wVar1 = *(word *)(param_1 + 0x44);
    *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
      _wakeup(param_1);
    }
  }
  iVar3 = _ifreeh;
  *(undefined2 *)(param_1 + 0x44) = 0;
  piVar5 = &_ifreeh;
  iVar4 = param_1;
  if (iVar3 != 0) {
    *_ifreet = param_1;
    piVar5 = _ifreet;
    iVar4 = _ifreeh;
  }
  _ifreeh = iVar4;
  *(int **)(param_1 + 0x60) = piVar5;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  _ifreet = (int *)(param_1 + 0x5c);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1031 start=0xf004e544 */

/* WARNING: Removing unreachable block (ram,0xf004e6ec) */
/* WARNING: Removing unreachable block (ram,0xf004e680) */
/* WARNING: Removing unreachable block (ram,0xf004e604) */
/* WARNING: Removing unreachable block (ram,0xf004e5c0) */
/* WARNING: Removing unreachable block (ram,0xf004e59c) */
/* WARNING: Removing unreachable block (ram,0xf004e584) */
/* WARNING: Removing unreachable block (ram,0xf004e5b8) */
/* WARNING: Removing unreachable block (ram,0xf004e5e8) */
/* WARNING: Removing unreachable block (ram,0xf004e61c) */
/* WARNING: Removing unreachable block (ram,0xf004e6ac) */
/* WARNING: Removing unreachable block (ram,0xf004e6e0) */
/* WARNING: Removing unreachable block (ram,0xf004e574) */

undefined8 _iupdat(int param_1,int param_2)

{
  word wVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  undefined4 uVar8;
  undefined4 unaff_l4;
  int iVar9;
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
  iVar9 = *(int *)(param_1 + 0x50);
  if (((*(word *)(param_1 + 0x44) & 0x4e) != 0) && (*(char *)(iVar9 + 0xd2) == '\0')) {
    uVar7 = *(uint *)(param_1 + 0x48);
    uVar8 = *(undefined4 *)(iVar9 + 0xb8);
    uVar6 = uVar7;
    .udiv(uVar7,uVar8);
    iVar2 = *(int *)(iVar9 + 0xbc);
    .umul(iVar2,uVar6);
    iVar4 = *(int *)(iVar9 + 0x18);
    .umul(iVar4,uVar6 & ~*(uint *)(iVar9 + 0x1c));
    iVar5 = *(int *)(iVar9 + 0x10);
    .urem(uVar7,uVar8);
    .udiv();
    puVar3 = *(uint **)(param_1 + 0x40);
    _bread(puVar3,iVar2 + iVar4 + iVar5 + (uVar7 << ((byte)*(undefined4 *)(iVar9 + 0x60) & 0x1f)) <<
                  ((byte)*(undefined4 *)(iVar9 + 100) & 0x1f),*(undefined4 *)(iVar9 + 0x30));
    if ((*puVar3 & 4) == 0) {
      if ((*(word *)(param_1 + 0x44) & 0x46) != 0) {
        _microtime(&_iuniqtime);
        if ((*(word *)(param_1 + 0x44) & 4) != 0) {
          *(undefined4 *)(param_1 + 0x74) = _iuniqtime;
        }
        if ((*(word *)(param_1 + 0x44) & 2) != 0) {
          *(undefined4 *)(param_1 + 0x7c) = _iuniqtime;
        }
        if ((*(word *)(param_1 + 0x44) & 0x40) != 0) {
          *(undefined4 *)(param_1 + 0x4c) = 0;
          *(undefined4 *)(param_1 + 0x84) = _iuniqtime;
        }
      }
      wVar1 = *(word *)(param_1 + 0x44);
      iVar2 = *(int *)(param_1 + 0x48);
      *(word *)(param_1 + 0x44) = wVar1 & 0xffb1;
      .urem(iVar2,*(undefined4 *)(iVar9 + 0x78));
      uVar6 = puVar3[8];
      *(word *)(param_1 + 0x44) = wVar1 & 0xfdb1;
      iVar9 = uVar6 + iVar2 * 0x80;
      _memcpy(iVar9,param_1 + 100,0x80);
      if (*(sword *)(*(int *)(param_1 + 0x30) + 0x124) != 0) {
        *(undefined2 *)(iVar9 + 4) = *(undefined2 *)(param_1 + 0xe4);
        *(undefined2 *)(iVar9 + 6) = *(undefined2 *)(param_1 + 0xe6);
      }
      if (param_2 == 0) {
        _bdwrite(puVar3);
      }
      else {
        _bwrite(puVar3);
      }
    }
    else {
      _brelse(puVar3);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1032 start=0xf004e6fc */

/* WARNING: Removing unreachable block (ram,0xf004e908) */
/* WARNING: Removing unreachable block (ram,0xf004e848) */
/* WARNING: Removing unreachable block (ram,0xf004ed68) */
/* WARNING: Removing unreachable block (ram,0xf004ed1c) */
/* WARNING: Removing unreachable block (ram,0xf004ec24) */
/* WARNING: Removing unreachable block (ram,0xf004eb70) */
/* WARNING: Removing unreachable block (ram,0xf004eb1c) */
/* WARNING: Removing unreachable block (ram,0xf004ea8c) */
/* WARNING: Removing unreachable block (ram,0xf004ea6c) */
/* WARNING: Removing unreachable block (ram,0xf004ea24) */
/* WARNING: Removing unreachable block (ram,0xf004e968) */
/* WARNING: Removing unreachable block (ram,0xf004e764) */
/* WARNING: Removing unreachable block (ram,0xf004e740) */
/* WARNING: Removing unreachable block (ram,0xf004e944) */
/* WARNING: Removing unreachable block (ram,0xf004e998) */
/* WARNING: Removing unreachable block (ram,0xf004ea40) */
/* WARNING: Removing unreachable block (ram,0xf004ea84) */
/* WARNING: Removing unreachable block (ram,0xf004ea9c) */
/* WARNING: Removing unreachable block (ram,0xf004eb48) */
/* WARNING: Removing unreachable block (ram,0xf004ec08) */
/* WARNING: Removing unreachable block (ram,0xf004ecf8) */
/* WARNING: Removing unreachable block (ram,0xf004ed38) */
/* WARNING: Removing unreachable block (ram,0xf004eda8) */
/* WARNING: Removing unreachable block (ram,0xf004e898) */
/* WARNING: Removing unreachable block (ram,0xf004e7f4) */
/* WARNING: Removing unreachable block (ram,0xf004e734) */
/* WARNING: Type propagation algorithm not settling */

undefined8 _itrunc(uint param_1,uint param_2)

{
  int *piVar1;
  word wVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  byte bVar8;
  undefined *puVar7;
  undefined4 unaff_l0;
  int iVar9;
  uint *puVar10;
  undefined4 unaff_l1;
  uint uVar11;
  uint uVar12;
  undefined *puVar13;
  undefined4 unaff_l3;
  int iVar14;
  undefined4 unaff_l4;
  int iVar15;
  undefined4 unaff_l5;
  undefined4 uVar16;
  undefined *puVar17;
  undefined4 unaff_l6;
  undefined *puVar18;
  undefined4 unaff_l7;
  int iVar19;
  undefined4 unaff_i0;
  int iVar20;
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
  int aiStack_74 [11];
  int aiStack_48 [18];
  
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
  *(undefined4 *)((int)register0x00000038 + -0x104) = 0;
  puVar18 = (undefined *)0x0;
  wVar2 = *(word *)(param_1 + 0x44);
  *(word *)(param_1 + 0x44) = wVar2 & 0xfffe;
  if ((wVar2 & 0x10) != 0) {
    *(word *)(param_1 + 0x44) = wVar2 & 0xffee;
    _wakeup(param_1);
  }
  iVar3 = param_1 + 0xc;
  _mfs_trunc(iVar3,param_2);
  wVar2 = *(word *)(param_1 + 0x44);
  while ((wVar2 & 1) != 0) {
    *(word *)(param_1 + 0x44) = wVar2 | 0x10;
    _sleep(param_1,10);
    wVar2 = *(word *)(param_1 + 0x44);
  }
  *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 1;
  if ((*(word *)(param_1 + 100) & 0xf000) == 0xa000) {
    iVar15 = 0xe;
    if ((*(uint *)(param_1 + 200) & 1) == 0) {
      uVar6 = *(uint *)(param_1 + 0x70);
      goto loc_F004E7D8;
    }
    iVar3 = param_1 + 0x38;
    do {
      *(undefined4 *)(iVar3 + 0x8c) = 0;
      iVar15 = iVar15 + -1;
      iVar3 = iVar3 + -4;
    } while (-1 < iVar15);
    *(undefined4 *)(param_1 + 200) = 0;
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  else {
    uVar6 = *(uint *)(param_1 + 0x70);
loc_F004E7D8:
    if (param_2 != uVar6) {
      iVar15 = *(int *)(param_1 + 0x50);
      uVar12 = param_2 & ~*(uint *)(iVar15 + 0x48);
      bVar8 = (byte)*(undefined4 *)(iVar15 + 0x50);
      uVar11 = param_2 - 1 >> (bVar8 & 0x1f);
      if (uVar6 < param_2) {
        if (uVar12 == 0) {
          uVar12 = *(uint *)(iVar15 + 0x30);
        }
        uVar6 = param_1;
        _bmap(param_1,uVar11,0,uVar12,(undefined *)((int)register0x00000038 + -0x104));
        if ((*(char *)(dword_F0133DDC + 0x38) == '\0') ||
           (iVar3 = *(int *)((int)register0x00000038 + -0x104), -1 < (int)uVar6)) {
          wVar2 = *(word *)(param_1 + 0x44);
          *(uint *)(param_1 + 0x70) = param_2;
          *(word *)(param_1 + 0x44) = wVar2 | 0x40;
          if ((wVar2 & 0x46 | 0x40) != 0) {
            *(word *)(param_1 + 0x44) = wVar2 | 0x48;
            _microtime(&_iuniqtime);
            if ((*(word *)(param_1 + 0x44) & 4) != 0) {
              *(undefined4 *)(param_1 + 0x74) = _iuniqtime;
            }
            if ((*(word *)(param_1 + 0x44) & 2) != 0) {
              *(undefined4 *)(param_1 + 0x7c) = _iuniqtime;
            }
            if ((*(word *)(param_1 + 0x44) & 0x40) == 0) {
              wVar2 = *(word *)(param_1 + 0x44);
            }
            else {
              *(undefined4 *)(param_1 + 0x4c) = 0;
              *(undefined4 *)(param_1 + 0x84) = _iuniqtime;
              wVar2 = *(word *)(param_1 + 0x44);
            }
            *(word *)(param_1 + 0x44) = wVar2 & 0xffb9;
          }
          iVar3 = *(int *)((int)register0x00000038 + -0x104);
        }
        if (iVar3 != 0) {
          _iupdat(param_1,1);
        }
      }
      else {
        uVar6 = (param_2 + *(int *)(iVar15 + 0x30)) - 1 >> (bVar8 & 0x1f);
        *(uint *)((int)register0x00000038 + -0x18) = uVar6 - 0xd;
        iVar9 = (uVar6 - 0xd) - *(int *)(iVar15 + 0x74);
        *(int *)((int)register0x00000038 + -0x14) = iVar9;
        iVar20 = *(int *)(iVar15 + 0x74);
        iVar19 = uVar6 - 1;
        .umul(iVar20,iVar20);
        *(int *)((int)register0x00000038 + -0x10) = iVar9 - iVar20;
        iVar20 = param_1 + 0xc;
        (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(iVar20);
        iVar9 = *(int *)(iVar15 + 0x30);
        .div(iVar9,iVar20);
        uVar16 = *(undefined4 *)(param_1 + 0x70);
        if (uVar12 == 0) {
          *(uint *)(param_1 + 0x70) = param_2;
        }
        else {
          uVar4 = param_1;
          _bmap(param_1,uVar11,0,uVar12,0);
          iVar20 = (int)*(char *)(dword_F0133DDC + 0x38);
          iVar14 = uVar4 << ((byte)*(undefined4 *)(iVar15 + 100) & 0x1f);
          if ((iVar20 != 0) || (iVar14 < 0)) goto locret_F004EDF4;
          *(uint *)(param_1 + 0x70) = param_2;
          if (((int)uVar11 < 0xc) &&
             (param_2 < uVar11 + 1 << ((byte)*(undefined4 *)(iVar15 + 0x50) & 0x1f))) {
            uVar11 = ((param_2 & ~*(uint *)(iVar15 + 0x48)) + *(int *)(iVar15 + 0x34)) - 1 &
                     *(uint *)(iVar15 + 0x4c);
          }
          else {
            uVar11 = *(uint *)(iVar15 + 0x30);
          }
          puVar10 = *(uint **)(param_1 + 0x40);
          if (**(int **)(param_1 + 0xc) != 0) {
            _vnode_uncache(param_1 + 0xc);
          }
          if (iVar3 == 0) {
            _bread(puVar10,iVar14,uVar11);
            if ((*puVar10 & 4) != 0) {
              *(undefined *)(dword_F0133DDC + 0x38) = 5;
              *(undefined4 *)(param_1 + 0x70) = uVar16;
              _brelse(puVar10);
              iVar20 = 5;
              goto locret_F004EDF4;
            }
            _bzero(puVar10[8] + uVar12,uVar11 - uVar12);
            _bdwrite(puVar10);
          }
        }
        _memcpy((undefined *)((int)register0x00000038 + -0x100),param_1,0xe8);
        *(undefined4 *)((int)register0x00000038 + -0x90) = uVar16;
        iVar3 = 2;
        iVar20 = param_1 + 8;
        puVar7 = (undefined *)register0x00000038;
        do {
          if (*(int *)(puVar7 + -0x10) < 0) {
            *(undefined4 *)(iVar20 + 0xbc) = 0;
            *(undefined4 *)(puVar7 + -0x10) = 0xffffffff;
          }
          iVar20 = iVar20 + -4;
          iVar3 = iVar3 + -1;
          puVar7 = puVar7 + -4;
        } while (-1 < iVar3);
        iVar20 = 0xb;
        iVar3 = param_1 + 0x2c;
        if (iVar19 < 0xb) {
          do {
            *(undefined4 *)(iVar3 + 0x8c) = 0;
            iVar20 = iVar20 + -1;
            iVar3 = iVar3 + -4;
          } while (iVar19 < iVar20);
        }
        *(uint *)(param_1 + 0x70) = param_2;
        iVar3 = 2;
        *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
        _iupdat(param_1,1);
        puVar17 = (undefined *)((int)register0x00000038 + -0x100);
        puVar13 = (undefined *)((int)register0x00000038 + -0xf8);
        puVar7 = (undefined *)register0x00000038;
        do {
          iVar20 = *(int *)(puVar13 + 0xbc);
          if (iVar20 != 0) {
            puVar5 = puVar17;
            _indirtrunc(puVar17,iVar20,*(undefined4 *)(puVar7 + -0x10),iVar3);
            puVar18 = puVar18 + (int)puVar5;
            if (*(int *)(puVar7 + -0x10) < 0) {
              *(undefined4 *)(puVar13 + 0xbc) = 0;
              puVar18 = puVar18 + iVar9;
              _free_block(puVar17,iVar20,*(undefined4 *)(iVar15 + 0x30));
            }
          }
          piVar1 = (int *)(puVar7 + -0x10);
          puVar7 = puVar7 + -4;
          if (-1 < *piVar1) goto loc_F004ED44;
          iVar3 = iVar3 + -1;
          puVar13 = puVar13 + -4;
        } while (-1 < iVar3);
        iVar3 = 0xb;
        if (iVar19 < 0xb) {
          puVar7 = (undefined *)((int)register0x00000038 + -0xd4);
          do {
            iVar20 = *(int *)(puVar7 + 0x8c);
            if (iVar20 != 0) {
              *(undefined4 *)(puVar7 + 0x8c) = 0;
              if ((iVar3 < 0xc) &&
                 (*(uint *)((int)register0x00000038 + -0x90) <
                  (uint)(iVar3 + 1 << ((byte)*(undefined4 *)(iVar15 + 0x50) & 0x1f)))) {
                uVar12 = ((*(uint *)((int)register0x00000038 + -0x90) & ~*(uint *)(iVar15 + 0x48)) +
                         *(int *)(iVar15 + 0x34)) - 1 & *(uint *)(iVar15 + 0x4c);
              }
              else {
                uVar12 = *(uint *)(iVar15 + 0x30);
              }
              _free_block(puVar17,iVar20,uVar12);
              iVar20 = param_1 + 0xc;
              (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(iVar20);
              .udiv(uVar12,iVar20);
              puVar18 = puVar18 + uVar12;
            }
            iVar3 = iVar3 + -1;
            puVar7 = puVar7 + -4;
          } while (iVar19 < iVar3);
        }
        if ((-1 < iVar19) && (iVar3 = *(int *)(puVar17 + iVar19 * 4 + 0x8c), iVar3 != 0)) {
          if (iVar19 < 0xc) {
            if (*(uint *)((int)register0x00000038 + -0x90) <
                uVar6 << ((byte)*(undefined4 *)(iVar15 + 0x50) & 0x1f)) {
              uVar12 = ((*(uint *)((int)register0x00000038 + -0x90) & ~*(uint *)(iVar15 + 0x48)) +
                       *(int *)(iVar15 + 0x34)) - 1 & *(uint *)(iVar15 + 0x4c);
            }
            else {
              uVar12 = *(uint *)(iVar15 + 0x30);
            }
          }
          else {
            uVar12 = *(uint *)(iVar15 + 0x30);
          }
          *(uint *)((int)register0x00000038 + -0x90) = param_2;
          if ((iVar19 < 0xc) && (param_2 < uVar6 << ((byte)*(undefined4 *)(iVar15 + 0x50) & 0x1f)))
          {
            uVar6 = ((param_2 & ~*(uint *)(iVar15 + 0x48)) + *(int *)(iVar15 + 0x34)) - 1 &
                    *(uint *)(iVar15 + 0x4c);
          }
          else {
            uVar6 = *(uint *)(iVar15 + 0x30);
          }
          if (uVar6 == 0) {
            _panic(aItruncNewspace);
          }
          if (uVar12 != uVar6) {
            iVar20 = uVar12 - uVar6;
            _free_block(puVar17,iVar3 + (uVar6 >> ((byte)*(undefined4 *)(iVar15 + 0x54) & 0x1f)),
                        iVar20);
            iVar3 = param_1 + 0xc;
            (**(code **)(*(int *)(param_1 + 0x28) + 0x80))(iVar3);
            .udiv(iVar20,iVar3);
            puVar18 = puVar18 + iVar20;
          }
        }
loc_F004ED44:
        iVar3 = 0;
        puVar7 = puVar17;
        uVar6 = param_1;
        do {
          if (*(int *)(puVar7 + 0xbc) != *(int *)(uVar6 + 0xbc)) {
            _panic(&aItrunc1);
          }
          uVar6 = uVar6 + 4;
          iVar3 = iVar3 + 1;
          puVar7 = puVar7 + 4;
        } while (iVar3 < 3);
        iVar3 = 0;
        param_2 = param_1;
        do {
          if (*(int *)(puVar17 + 0x8c) != *(int *)(param_2 + 0x8c)) {
            _panic(&aItrunc2);
          }
          param_2 = param_2 + 4;
          iVar3 = iVar3 + 1;
          puVar17 = puVar17 + 4;
        } while (iVar3 < 0xc);
        iVar3 = *(int *)(param_1 + 0xcc) - (int)puVar18;
        *(int *)(param_1 + 0xcc) = iVar3;
        if (iVar3 < 0) {
          *(undefined4 *)(param_1 + 0xcc) = 0;
        }
        *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x40;
      }
      iVar20 = (int)*(char *)(dword_F0133DDC + 0x38);
      goto locret_F004EDF4;
    }
  }
  *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
  _iupdat(param_1,1);
  iVar20 = 0;
locret_F004EDF4:
  return CONCAT44(param_2,iVar20);
}
/* GHIDRADEC_FUNCTION index=1033 start=0xf004edfc */

/* WARNING: Removing unreachable block (ram,0xf004efa8) */
/* WARNING: Removing unreachable block (ram,0xf004ef54) */
/* WARNING: Removing unreachable block (ram,0xf004eef4) */
/* WARNING: Removing unreachable block (ram,0xf004eecc) */
/* WARNING: Removing unreachable block (ram,0xf004eeac) */
/* WARNING: Removing unreachable block (ram,0xf004ee78) */
/* WARNING: Removing unreachable block (ram,0xf004ee48) */
/* WARNING: Removing unreachable block (ram,0xf004ee6c) */
/* WARNING: Removing unreachable block (ram,0xf004ee90) */
/* WARNING: Removing unreachable block (ram,0xf004eeb4) */
/* WARNING: Removing unreachable block (ram,0xf004eeec) */
/* WARNING: Removing unreachable block (ram,0xf004ef3c) */
/* WARNING: Removing unreachable block (ram,0xf004ef80) */
/* WARNING: Removing unreachable block (ram,0xf004efb4) */
/* WARNING: Removing unreachable block (ram,0xf004ee24) */

undefined8 _indirtrunc(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  int iVar6;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  uint uVar9;
  int iVar10;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 uVar11;
  undefined4 unaff_i0;
  int iVar12;
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
  iVar12 = 0;
  uVar11 = 1;
  iVar7 = 0;
  iVar8 = *(int *)(param_1 + 0x50);
  if (0 < param_4) {
    do {
      iVar7 = iVar7 + 1;
      .umul(uVar11,*(undefined4 *)(iVar8 + 0x74));
    } while (iVar7 < param_4);
  }
  iVar7 = param_3;
  if (param_3 < 1) {
    iVar1 = *(int *)(param_1 + 0x28);
  }
  else {
    .div(param_3,uVar11);
    iVar1 = *(int *)(param_1 + 0x28);
  }
  iVar2 = param_1 + 0xc;
  (**(code **)(iVar1 + 0x80))(iVar2);
  iVar5 = *(int *)(iVar8 + 0x30);
  iVar1 = iVar5;
  .div(iVar5,iVar2);
  _geteblk();
  puVar3 = *(uint **)(param_1 + 0x40);
  _bread(puVar3,param_2 << ((byte)*(undefined4 *)(iVar8 + 100) & 0x1f),*(undefined4 *)(iVar8 + 0x30)
        );
  if ((*puVar3 & 4) == 0) {
    uVar9 = puVar3[8];
    _bcopy(uVar9,*(undefined4 *)(iVar5 + 0x20),*(undefined4 *)(iVar8 + 0x30));
    _bzero(uVar9 + iVar7 * 4 + 4,((*(int *)(iVar8 + 0x74) + -1) - iVar7) * 4);
    _bwrite(puVar3);
    iVar2 = *(int *)(iVar8 + 0x74) + -1;
    iVar10 = *(int *)(iVar5 + 0x20);
    if (iVar7 < iVar2) {
      param_2 = iVar2 * 4;
      do {
        iVar6 = *(int *)(param_2 + iVar10);
        if (iVar6 != 0) {
          if (0 < param_4) {
            iVar4 = param_1;
            _indirtrunc(param_1,iVar6,0xffffffff,param_4 + -1);
            iVar12 = iVar12 + iVar4;
          }
          iVar12 = iVar12 + iVar1;
          _free_block(param_1,iVar6,*(undefined4 *)(iVar8 + 0x30));
        }
        iVar2 = iVar2 + -1;
        param_2 = param_2 + -4;
      } while (iVar7 < iVar2);
    }
    if ((0 < param_4) && (-1 < param_3)) {
      .rem(param_3,uVar11);
      iVar7 = *(int *)(iVar10 + iVar2 * 4);
      if (iVar7 != 0) {
        _indirtrunc(param_1,iVar7,param_3,param_4 + -1);
        iVar12 = iVar12 + param_1;
      }
    }
    _brelse(iVar5);
  }
  else {
    _brelse(iVar5);
    _brelse(puVar3);
    iVar12 = 0;
  }
  return CONCAT44(param_2,iVar12);
}
/* GHIDRADEC_FUNCTION index=1034 start=0xf004efc4 */

int _iflush(sword param_1)

{
  sword sVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  int *piVar3;
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
  iVar2 = 0;
  if (_inode_list == (int *)0x0) {
    return 0;
  }
  sVar1 = *(sword *)((int)_inode_list + 0x46);
  piVar3 = _inode_list;
  do {
    if ((int)sVar1 == (int)param_1) {
      if ((*(word *)(piVar3 + 0x11) & 0x100) == 0) {
        *(int *)(*piVar3 + 4) = piVar3[1];
        *(int *)piVar3[1] = *piVar3;
        *piVar3 = (int)piVar3;
        piVar3[1] = (int)piVar3;
      }
      else {
        iVar2 = -1;
      }
loc_F004F070:
      piVar3 = (int *)piVar3[2];
    }
    else if ((*(word *)(piVar3 + 0x11) & 0x100) == 0) {
      piVar3 = (int *)piVar3[2];
    }
    else if ((*(word *)(piVar3 + 0x19) & 0xf000) == 0x6000) {
      if (piVar3[0x23] == (int)param_1) {
        if (-1 < iVar2) {
          iVar2 = iVar2 + 1;
        }
        goto loc_F004F070;
      }
      piVar3 = (int *)piVar3[2];
    }
    else {
      piVar3 = (int *)piVar3[2];
    }
    if (piVar3 == (int *)0x0) {
      return iVar2;
    }
    sVar1 = *(sword *)((int)piVar3 + 0x46);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1035 start=0xf004f088 */

/* WARNING: Removing unreachable block (ram,0xf004f09c) */

undefined8 _ilock(int param_1,undefined4 param_2)

{
  word wVar1;
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
  wVar1 = *(word *)(param_1 + 0x44);
  while ((wVar1 & 1) != 0) {
    *(word *)(param_1 + 0x44) = wVar1 | 0x10;
    _sleep(param_1,10);
    wVar1 = *(word *)(param_1 + 0x44);
  }
  *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1036 start=0xf004f0c8 */

/* WARNING: Removing unreachable block (ram,0xf004f0f8) */

undefined8 _iunlock(int param_1,undefined4 param_2)

{
  word wVar1;
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
  wVar1 = *(word *)(param_1 + 0x44);
  *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
  if ((wVar1 & 0x10) != 0) {
    *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
    _wakeup(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1037 start=0xf004f108 */

/* WARNING: Removing unreachable block (ram,0xf004f178) */

undefined8 _iaccess(int param_1,uint param_2)

{
  sword sVar1;
  uint uVar2;
  word wVar3;
  sword *psVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
  undefined4 unaff_i1;
  uint uVar7;
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
  if ((param_2 & 0x80) != 0) {
    if (((*(char *)(*(int *)(param_1 + 0x50) + 0xd2) == '\0') ||
        (wVar3 = *(word *)(param_1 + 100) & 0xf000, wVar3 == 0x2000)) || (wVar3 == 0x6000)) {
      wVar3 = *(word *)(param_1 + 0x10);
    }
    else {
      if (wVar3 != 0x1000) {
        uVar6 = 0x1e;
        goto locret_F004F238;
      }
      wVar3 = *(word *)(param_1 + 0x10);
    }
    if ((wVar3 & 2) == 0) {
      wVar3 = *(word *)(param_1 + 0x10);
    }
    else {
      _vnode_uncache(param_1 + 0xc);
      wVar3 = *(word *)(param_1 + 0x10);
    }
    if ((wVar3 & 2) != 0) {
      uVar6 = 0x1a;
      goto locret_F004F238;
    }
  }
  iVar5 = *(int *)(_active_u + 0x1c);
  if (*(sword *)(iVar5 + 2) == 0) {
    uVar6 = 0;
  }
  else {
    if (*(sword *)(iVar5 + 2) == *(sword *)(param_1 + 0x68)) {
      uVar2 = (uint)*(word *)(param_1 + 100);
      uVar7 = param_2;
    }
    else {
      uVar7 = (int)param_2 >> 3;
      uVar6 = uVar7;
      if (*(sword *)(iVar5 + 4) != *(sword *)(param_1 + 0x6a)) {
        psVar4 = (sword *)(iVar5 + 10);
        uVar6 = (int)param_2 >> 6;
        if (psVar4 < (sword *)(iVar5 + 0x2a)) {
          sVar1 = *psVar4;
          while (sVar1 != -1) {
            if (*(sword *)(param_1 + 0x6a) == sVar1) {
              uVar2 = (uint)*(word *)(param_1 + 100);
              goto loc_F004F228;
            }
            psVar4 = psVar4 + 1;
            if ((sword *)(iVar5 + 0x2a) <= psVar4) break;
            sVar1 = *psVar4;
          }
        }
      }
      uVar2 = (uint)*(word *)(param_1 + 100);
      uVar7 = uVar6;
    }
loc_F004F228:
    uVar6 = -(uint)((uVar7 & ~uVar2) != 0) & 0xd;
    param_2 = uVar7;
  }
locret_F004F238:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=1038 start=0xf004f240 */

/* WARNING: Removing unreachable block (ram,0xf004f2f4) */
/* WARNING: Removing unreachable block (ram,0xf004f2e8) */
/* WARNING: Removing unreachable block (ram,0xf004f298) */
/* WARNING: Removing unreachable block (ram,0xf004f250) */
/* WARNING: Removing unreachable block (ram,0xf004f310) */
/* WARNING: Removing unreachable block (ram,0xf004f2c8) */
/* WARNING: Removing unreachable block (ram,0xf004f320) */
/* WARNING: Removing unreachable block (ram,0xf004f244) */

undefined8 _lf_lockctl(int param_1,sword *param_2,int param_3)

{
  sword *psVar1;
  int iVar2;
  sword *psVar3;
  sword sVar4;
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
  sub_F004F334();
  psVar1 = (sword *)0x1c;
  _kalloc();
  psVar1[1] = *param_2;
  *(undefined4 *)(psVar1 + 2) = *(undefined4 *)(param_2 + 2);
  if (*(int *)(param_2 + 4) == 0) {
    iVar2 = -1;
  }
  else {
    iVar2 = *(int *)(param_2 + 2) + *(int *)(param_2 + 4) + -1;
  }
  *(int *)(psVar1 + 4) = iVar2;
  iVar2 = (int)*(sword *)(*_active_u + 0x30);
  _get_posix_proc();
  *(int *)(psVar1 + 6) = iVar2;
  *(int *)(psVar1 + 8) = param_1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  psVar1[10] = 0;
  psVar1[0xb] = 0;
  psVar1[0xc] = 0;
  psVar1[0xd] = 0;
  psVar3 = psVar1;
  if (param_3 == 7) {
    sub_F004F8C0(psVar1,param_2);
  }
  else {
    if (*param_2 != 3) {
      if (param_3 == 8) {
        sVar4 = 1;
      }
      else {
        sVar4 = 2;
      }
      *psVar1 = sVar4;
      sub_F004F460(psVar1);
      goto locret_F004F32C;
    }
    sub_F004F78C(psVar1);
  }
  sub_F004FCE0(psVar1);
  sub_F004F3DC(param_1);
  psVar1 = psVar3;
  param_2 = psVar3;
locret_F004F32C:
  return CONCAT44(param_2,psVar1);
}
/* GHIDRADEC_FUNCTION index=1039 start=0xf004fd08 */

/* WARNING: Removing unreachable block (ram,0xf004fecc) */
/* WARNING: Removing unreachable block (ram,0xf004fe78) */
/* WARNING: Removing unreachable block (ram,0xf004fe5c) */
/* WARNING: Removing unreachable block (ram,0xf004fde0) */
/* WARNING: Removing unreachable block (ram,0xf004fdcc) */
/* WARNING: Removing unreachable block (ram,0xf004fdd4) */
/* WARNING: Removing unreachable block (ram,0xf004fdf0) */
/* WARNING: Removing unreachable block (ram,0xf004fe70) */
/* WARNING: Removing unreachable block (ram,0xf004fec4) */
/* WARNING: Removing unreachable block (ram,0xf004fefc) */
/* WARNING: Removing unreachable block (ram,0xf004fd20) */

undefined8 _update(undefined4 param_1,undefined4 param_2)

{
  word wVar1;
  word wVar2;
  int iVar3;
  word wVar4;
  undefined4 unaff_l0;
  int iVar5;
  int iVar6;
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
  if (_syncprt != 0) {
    _bufstats();
  }
  if (_updlock == 0) {
    _updlock = 1;
    wVar1 = (word)param_1;
    wVar4 = (word)param_2;
    iVar5 = _mounttab;
    while (iVar3 = _inode_list, iVar5 != 0) {
      if (wVar1 == 0xffff) {
        iVar3 = *(int *)(iVar5 + 0xc);
loc_F004FD8C:
        if (iVar3 == 0) {
          iVar5 = *(int *)(iVar5 + 0x20);
        }
        else if (*(sword *)(iVar5 + 4) == -1) {
          iVar5 = *(int *)(iVar5 + 0x20);
        }
        else {
          iVar3 = *(int *)(iVar3 + 0x20);
          if (*(char *)(iVar3 + 0xd0) == '\0') {
            iVar5 = *(int *)(iVar5 + 0x20);
          }
          else {
            if (*(char *)(iVar3 + 0xd2) != '\0') {
              _printf(aFsS_0,iVar3 + 0xd4);
              _panic(aUpdateRoFsMod);
            }
            *(undefined *)(iVar3 + 0xd0) = 0;
            _getthetime((undefined *)((int)register0x00000038 + -0x10));
            *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)((int)register0x00000038 + -0x10);
            _sbupdate(iVar5);
            iVar5 = *(int *)(iVar5 + 0x20);
          }
        }
      }
      else {
        if (wVar1 == (*(word *)(iVar5 + 4) & wVar4)) {
          iVar3 = *(int *)(iVar5 + 0xc);
          goto loc_F004FD8C;
        }
        iVar5 = *(int *)(iVar5 + 0x20);
      }
    }
    while (iVar3 != 0) {
      if (wVar1 == 0xffff) {
        wVar2 = *(word *)(iVar3 + 0x44);
loc_F004FE84:
        if ((wVar2 & 1) == 0) {
          if ((wVar2 & 0x100) == 0) {
            iVar3 = *(int *)(iVar3 + 8);
          }
          else if ((wVar2 & 0x4e) == 0) {
            iVar3 = *(int *)(iVar3 + 8);
          }
          else {
            *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) | 1;
            *(sword *)(iVar3 + 0x12) = *(sword *)(iVar3 + 0x12) + 1;
            _iupdat(iVar3,0);
            _iput(iVar3);
            iVar3 = *(int *)(iVar3 + 8);
          }
        }
        else {
          iVar3 = *(int *)(iVar3 + 8);
        }
      }
      else {
        if (wVar1 == (*(word *)(iVar3 + 0x46) & wVar4)) {
          if (wVar1 == 0xffff) {
            wVar2 = *(word *)(iVar3 + 0x44);
          }
          else {
            iVar6 = *(int *)(iVar3 + 0xc) + 0x18;
            iVar5 = iVar6;
            _lock_try_write();
            if (iVar5 == 1) {
              _lock_done(iVar6);
              _mfs_fsync(iVar3 + 0xc);
              wVar2 = *(word *)(iVar3 + 0x44);
            }
            else {
              wVar2 = *(word *)(iVar3 + 0x44);
            }
          }
          goto loc_F004FE84;
        }
        iVar3 = *(int *)(iVar3 + 8);
      }
    }
    param_1 = 0;
    _updlock = 0;
    _bflush(0,(int)(sword)wVar1,(int)(sword)wVar4);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1040 start=0xf004ff0c */

/* WARNING: Removing unreachable block (ram,0xf0050054) */
/* WARNING: Removing unreachable block (ram,0xf00500a0) */
/* WARNING: Removing unreachable block (ram,0xf0050070) */
/* WARNING: Removing unreachable block (ram,0xf0050028) */
/* WARNING: Removing unreachable block (ram,0xf004ff60) */
/* WARNING: Removing unreachable block (ram,0xf004ffbc) */
/* WARNING: Removing unreachable block (ram,0xf0050068) */
/* WARNING: Removing unreachable block (ram,0xf0050098) */
/* WARNING: Removing unreachable block (ram,0xf005004c) */
/* WARNING: Removing unreachable block (ram,0xf00500c8) */
/* WARNING: Removing unreachable block (ram,0xf004ff20) */

undefined8 _syncip(int param_1,undefined4 param_2)

{
  word wVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
  uint *puVar6;
  undefined4 unaff_l1;
  int iVar7;
  uint *puVar8;
  undefined4 unaff_l3;
  uint *puVar9;
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
  iVar7 = *(int *)(param_1 + 0x50);
  iVar2 = *(int *)(param_1 + 0x70) + -1 + *(int *)(iVar7 + 0x30);
  .udiv();
  if (iVar2 < _nbuf / 2) {
    iVar5 = 0;
    if (0 < iVar2) {
      do {
        iVar3 = param_1;
        _bmap(param_1,iVar5,1);
        if ((iVar5 < 0xc) &&
           (*(uint *)(param_1 + 0x70) <
            (uint)(iVar5 + 1 << ((byte)*(undefined4 *)(iVar7 + 0x50) & 0x1f)))) {
          uVar4 = ((*(uint *)(param_1 + 0x70) & ~*(uint *)(iVar7 + 0x48)) + *(int *)(iVar7 + 0x34))
                  - 1 & *(uint *)(iVar7 + 0x4c);
        }
        else {
          uVar4 = *(uint *)(iVar7 + 0x30);
        }
        _blkflush(*(undefined4 *)(param_1 + 0x40),
                  iVar3 << ((byte)*(undefined4 *)(iVar7 + 100) & 0x1f),uVar4);
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar2);
      wVar1 = *(word *)(param_1 + 0x44);
      goto loc_F00500C0;
    }
  }
  else {
    puVar9 = _buf + _nbuf * 0x11;
    if (_buf < puVar9) {
      puVar8 = _buf + 4;
      puVar6 = _buf;
      do {
        if (puVar8[0xc] == *(uint *)(param_1 + 0x40)) {
          uVar4 = *puVar6;
          if ((uVar4 & 0x200) == 0) {
            puVar6 = puVar6 + 0x11;
          }
          else {
            _spltty();
            if ((*puVar6 & 8) == 0) {
              _splx(uVar4);
              _spltty();
              *(uint *)(*puVar8 + 0xc) = puVar8[-1];
              *(uint *)(puVar8[-1] + 0x10) = *puVar8;
              *puVar6 = *puVar6 | 8;
              _splx();
              _bwrite(puVar6);
            }
            else {
              *puVar6 = *puVar6 | 0x40;
              _sleep(puVar6,0x15);
              _splx(uVar4);
              puVar8 = puVar8 + -0x11;
              puVar6 = puVar6 + -0x11;
            }
            puVar6 = puVar6 + 0x11;
          }
        }
        else {
          puVar6 = puVar6 + 0x11;
        }
        puVar8 = puVar8 + 0x11;
      } while (puVar6 < puVar9);
    }
  }
  wVar1 = *(word *)(param_1 + 0x44);
loc_F00500C0:
  *(word *)(param_1 + 0x44) = wVar1 | 0x40;
  _iupdat(param_1,1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1041 start=0xf00500d8 */

undefined8 _fragacct(int param_1,int param_2,int param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  uint uVar8;
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
  iVar3 = *(int *)(param_1 + 0x38);
  iVar6 = 1;
  bVar1 = *(byte *)(*(int *)(_fragtbl + iVar3 * 4) + param_2);
  iVar7 = param_1;
  if (1 < iVar3) {
    iVar7 = 4;
    do {
      iVar4 = iVar3;
      if (iVar3 < 0) {
        iVar4 = iVar3 + 7;
      }
      bVar2 = (byte)iVar6;
      if (((int)((uint)bVar1 << 1) >> (bVar2 + ((char)iVar3 - ((byte)iVar4 & 0xf8)) & 0x1f) & 1U) ==
          0) {
        iVar3 = *(int *)(param_1 + 0x38);
      }
      else {
        uVar8 = *(uint *)(_around + iVar7);
        uVar5 = *(uint *)(_inside + iVar7);
        iVar4 = iVar6;
        if (iVar6 <= iVar3) {
          do {
            if ((param_2 << 1 & uVar8) == uVar5) {
              iVar4 = iVar4 + iVar6;
              uVar8 = uVar8 << (bVar2 & 0x1f);
              uVar5 = uVar5 << (bVar2 & 0x1f);
              *(int *)(param_3 + iVar7) = *(int *)(param_3 + iVar7) + param_4;
            }
            uVar8 = uVar8 << 1;
            iVar4 = iVar4 + 1;
            uVar5 = uVar5 << 1;
          } while (iVar4 <= *(int *)(param_1 + 0x38));
        }
        iVar3 = *(int *)(param_1 + 0x38);
      }
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 4;
    } while (iVar6 < iVar3);
  }
  return CONCAT44(param_2 << 1,iVar7);
}
/* GHIDRADEC_FUNCTION index=1042 start=0xf00501c0 */

/* WARNING: Removing unreachable block (ram,0xf00501f0) */
/* WARNING: Removing unreachable block (ram,0xf00501e0) */

undefined8 _badblock(int param_1,uint param_2)

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
  bool bVar1;
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
  bVar1 = *(uint *)(param_1 + 0x24) <= param_2;
  if (bVar1) {
    _printf(aBadBlockD);
    _fserr(param_1,aBadBlock);
  }
  return CONCAT44(param_2,(uint)bVar1);
}
/* GHIDRADEC_FUNCTION index=1043 start=0xf0050204 */

/* WARNING: Removing unreachable block (ram,0xf00502ac) */

undefined8 _isblock(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  sbyte sVar4;
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
  iVar3 = *(int *)(param_1 + 0x38);
  if (iVar3 == 2) {
    sVar4 = (sbyte)((param_3 & 3) << 1);
    iVar2 = 3;
    iVar3 = (int)param_3 >> 2;
loc_F0050270:
    uVar1 = (*(byte *)(param_2 + iVar3) ^ 0xff) & iVar2 << sVar4;
  }
  else {
    if (iVar3 < 3) {
      if (iVar3 == 1) {
        uVar1 = (uint)(((*(byte *)(param_2 + ((int)param_3 >> 3)) ^ 0xff) & 1 << ((byte)param_3 & 7)
                       ) == 0);
        goto locret_F00502B8;
      }
loc_F00502AC:
      _panic(&aIsblock);
      uVar1 = 0;
      goto locret_F00502B8;
    }
    if (iVar3 == 4) {
      sVar4 = (sbyte)((param_3 & 1) << 2);
      iVar2 = 0xf;
      iVar3 = (int)param_3 >> 1;
      goto loc_F0050270;
    }
    if (iVar3 != 8) goto loc_F00502AC;
    uVar1 = *(byte *)(param_2 + param_3) ^ 0xff;
  }
  uVar1 = (uint)(uVar1 == 0);
locret_F00502B8:
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1044 start=0xf00502c0 */

/* WARNING: Removing unreachable block (ram,0xf0050354) */

undefined8 _clrblock(int param_1,int param_2,uint param_3)

{
  sbyte sVar1;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x38);
  if (iVar2 == 2) {
    iVar3 = (int)param_3 >> 2;
    sVar1 = (sbyte)((param_3 & 3) << 1);
    iVar2 = 3;
loc_F0050328:
    *(byte *)(param_2 + iVar3) = *(byte *)(param_2 + iVar3) & ~(byte)(iVar2 << sVar1);
  }
  else {
    if (iVar2 < 3) {
      if (iVar2 == 1) {
        *(byte *)(param_2 + ((int)param_3 >> 3)) =
             *(byte *)(param_2 + ((int)param_3 >> 3)) & ~(byte)(1 << ((byte)param_3 & 7));
        goto locret_F005035C;
      }
    }
    else {
      if (iVar2 == 4) {
        iVar3 = (int)param_3 >> 1;
        sVar1 = (sbyte)((param_3 & 1) << 2);
        iVar2 = 0xf;
        goto loc_F0050328;
      }
      if (iVar2 == 8) {
        *(undefined *)(param_2 + param_3) = 0;
        goto locret_F005035C;
      }
    }
    _panic(aClrblock);
  }
locret_F005035C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1045 start=0xf0050364 */

/* WARNING: Removing unreachable block (ram,0xf00503fc) */

undefined8 _setblock(int param_1,int param_2,uint param_3)

{
  sbyte sVar1;
  int iVar2;
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
  iVar2 = *(int *)(param_1 + 0x38);
  if (iVar2 == 2) {
    iVar3 = (int)param_3 >> 2;
    sVar1 = (sbyte)((param_3 & 3) << 1);
    iVar2 = 3;
loc_F00503D0:
    *(byte *)(param_2 + iVar3) = *(byte *)(param_2 + iVar3) | (byte)(iVar2 << sVar1);
  }
  else {
    if (iVar2 < 3) {
      if (iVar2 == 1) {
        *(byte *)(param_2 + ((int)param_3 >> 3)) =
             *(byte *)(param_2 + ((int)param_3 >> 3)) | (byte)(1 << ((byte)param_3 & 7));
        goto locret_F0050404;
      }
    }
    else {
      if (iVar2 == 4) {
        iVar3 = (int)param_3 >> 1;
        sVar1 = (sbyte)((param_3 & 1) << 2);
        iVar2 = 0xf;
        goto loc_F00503D0;
      }
      if (iVar2 == 8) {
        *(undefined *)(param_2 + param_3) = 0xff;
        goto locret_F0050404;
      }
    }
    _panic(aSetblock);
  }
locret_F0050404:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1046 start=0xf005040c */

/* WARNING: Removing unreachable block (ram,0xf0050478) */
/* WARNING: Removing unreachable block (ram,0xf0050470) */

undefined8 _getmp(sword param_1,undefined4 param_2)

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
  int iVar2;
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
  if (_mounttab != 0) {
    iVar1 = *(int *)(_mounttab + 0xc);
    iVar2 = _mounttab;
    while( true ) {
      if (iVar1 == 0) {
        iVar2 = *(int *)(iVar2 + 0x20);
      }
      else {
        if ((int)*(sword *)(iVar2 + 4) == (int)param_1) {
          if (*(int *)(*(int *)(iVar1 + 0x20) + 0x55c) != 0x11954) {
            _printf(aDev0xXFsS,(int)*(sword *)(iVar2 + 4),*(int *)(iVar1 + 0x20) + 0xd4);
            _panic(aGetmpBadMagic);
          }
          goto locret_F0050494;
        }
        iVar2 = *(int *)(iVar2 + 0x20);
      }
      if (iVar2 == 0) break;
      iVar1 = *(int *)(iVar2 + 0xc);
    }
  }
  iVar2 = 0;
locret_F0050494:
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1047 start=0xf005049c */

/* WARNING: Removing unreachable block (ram,0xf00505b4) */
/* WARNING: Removing unreachable block (ram,0xf0050590) */
/* WARNING: Removing unreachable block (ram,0xf0050564) */
/* WARNING: Removing unreachable block (ram,0xf0050520) */
/* WARNING: Removing unreachable block (ram,0xf00504fc) */
/* WARNING: Removing unreachable block (ram,0xf005053c) */
/* WARNING: Removing unreachable block (ram,0xf0050580) */
/* WARNING: Removing unreachable block (ram,0xf00505d8) */
/* WARNING: Removing unreachable block (ram,0xf00505c4) */
/* WARNING: Removing unreachable block (ram,0xf00504a8) */

undefined8 _bufstats(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 *puVar6;
  undefined4 unaff_l1;
  uint uVar7;
  int iVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 *puVar9;
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
  int aiStack_8 [2];
  
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
  iVar2 = 0x2000;
  .udiv(0x2000,_page_size);
  uVar3 = iVar2 * 4 + 0x6eU & 0xfffffff8;
  puVar9 = &_bfreelist;
  iVar2 = 0;
  do {
    iVar8 = 0;
    uVar7 = 0;
    iVar5 = 0;
    while( true ) {
      uVar4 = 0x2000;
      .udiv(0x2000,_page_size);
      if (uVar4 < uVar7) break;
      *(undefined4 *)((int)aiStack_8 + (iVar5 - uVar3)) = 0;
      iVar5 = iVar5 + 4;
      uVar7 = uVar7 + 1;
    }
    _spltty();
    for (puVar6 = (undefined4 *)puVar9[3]; puVar6 != puVar9; puVar6 = (undefined4 *)puVar6[3]) {
      iVar5 = puVar6[6];
      .udiv(iVar5,_page_size);
      *(int *)((int)aiStack_8 + (iVar5 * 4 - uVar3)) =
           *(int *)((int)aiStack_8 + (iVar5 * 4 - uVar3)) + 1;
      iVar8 = iVar8 + 1;
    }
    _splx(uVar4);
    uVar7 = 0;
    iVar5 = 0;
    _printf(aSTotalD,*(undefined4 *)(unk_F010EDCC + iVar2),iVar8);
    while( true ) {
      uVar1 = _page_size;
      uVar4 = 0x2000;
      .udiv(0x2000,_page_size);
      if (uVar4 < uVar7) break;
      iVar8 = *(int *)((int)aiStack_8 + (iVar5 - uVar3));
      if (iVar8 != 0) {
        uVar4 = uVar7;
        .umul(uVar7,uVar1);
        _printf(&aDD,uVar4,iVar8);
      }
      iVar5 = iVar5 + 4;
      uVar7 = uVar7 + 1;
    }
    _printf(&DAT_f010ee18);
    puVar9 = puVar9 + 0x11;
    iVar2 = iVar2 + 4;
  } while (puVar9 < &_buf);
  return 0xf010edccf010ec00;
}
/* GHIDRADEC_FUNCTION index=1048 start=0xf0050600 */

undefined8 _scanc(int param_1,byte *param_2,int param_3,uint param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  byte *pbVar1;
  int iVar2;
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
  pbVar1 = param_2 + param_1;
  if (param_2 < pbVar1) {
    if ((*(byte *)(param_3 + (uint)*param_2) & param_4) != 0) {
      iVar2 = (int)pbVar1 - (int)param_2;
      goto locret_F0050650;
    }
    do {
      param_2 = param_2 + 1;
      if (pbVar1 <= param_2) {
        iVar2 = (int)pbVar1 - (int)param_2;
        goto locret_F0050650;
      }
    } while ((*(byte *)(param_3 + (uint)*param_2) & param_4) == 0);
  }
  iVar2 = (int)pbVar1 - (int)param_2;
locret_F0050650:
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1049 start=0xf0050658 */

undefined8 _skpc(uint param_1,int param_2,byte *param_3)

{
  byte bVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  byte *pbVar2;
  int iVar3;
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
  pbVar2 = param_3 + param_2;
  if (param_3 < pbVar2) {
    bVar1 = *param_3;
    while ((uint)bVar1 == (param_1 & 0xff)) {
      param_3 = param_3 + 1;
      if (pbVar2 <= param_3) {
        iVar3 = (int)pbVar2 - (int)param_3;
        goto locret_F0050698;
      }
      bVar1 = *param_3;
    }
    iVar3 = (int)pbVar2 - (int)param_3;
  }
  else {
    iVar3 = (int)pbVar2 - (int)param_3;
  }
locret_F0050698:
  return CONCAT44(param_2,iVar3);
}

