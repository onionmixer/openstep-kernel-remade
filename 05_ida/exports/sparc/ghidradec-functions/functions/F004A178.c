
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
