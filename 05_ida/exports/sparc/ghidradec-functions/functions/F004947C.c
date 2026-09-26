
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
