
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
