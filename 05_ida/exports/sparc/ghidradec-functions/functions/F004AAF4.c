
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
