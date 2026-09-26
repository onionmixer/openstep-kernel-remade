
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
