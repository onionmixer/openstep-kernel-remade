
/* WARNING: Removing unreachable block (ram,0xf006d008) */
/* WARNING: Removing unreachable block (ram,0xf006cfc4) */
/* WARNING: Removing unreachable block (ram,0xf006cf34) */
/* WARNING: Removing unreachable block (ram,0xf006cec0) */
/* WARNING: Removing unreachable block (ram,0xf006ce60) */
/* WARNING: Removing unreachable block (ram,0xf006cdb8) */
/* WARNING: Removing unreachable block (ram,0xf006cd34) */
/* WARNING: Removing unreachable block (ram,0xf006ce84) */
/* WARNING: Removing unreachable block (ram,0xf006cf08) */
/* WARNING: Removing unreachable block (ram,0xf006cf44) */
/* WARNING: Removing unreachable block (ram,0xf006cff8) */
/* WARNING: Removing unreachable block (ram,0xf006d038) */
/* WARNING: Removing unreachable block (ram,0xf006cd44) */

undefined8 _mfs_io(int *param_1,uint param_2,int param_3,uint param_4,sword *param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar7;
  undefined4 unaff_l4;
  uint uVar8;
  undefined4 unaff_l5;
  int iVar9;
  undefined4 unaff_l6;
  int iVar10;
  undefined4 unaff_l7;
  int iVar11;
  undefined4 unaff_i0;
  int iVar12;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  uint uVar13;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar14;
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
  if (*(int *)(param_2 + 0x14) == 0) {
    iVar12 = 0;
    goto locret_F006D044;
  }
  if ((*(int *)(param_2 + 8) < 0) || (*(int *)(param_2 + 8) + *(int *)(param_2 + 0x14) < 0)) {
    iVar12 = 0x16;
    goto locret_F006D044;
  }
  _mfs_get(param_1);
  iVar6 = *param_1;
  iVar10 = *(int *)(iVar6 + 0x14);
  if ((param_3 == 1) && ((param_4 & 2) != 0)) {
    *(int *)(param_2 + 8) = iVar10;
  }
  uVar13 = *(uint *)(param_2 + 8);
  iVar11 = *(int *)(param_2 + 0x14);
  uVar8 = *(uint *)(param_1[9] + 0x10);
  if (param_3 != 1) {
    if (param_3 != 0) {
      *(undefined4 *)(iVar6 + 0x34) = 0;
      goto loc_F006CDC8;
    }
    if (*(int *)(iVar6 + 0x30) != 0) {
      *(undefined4 *)(iVar6 + 0x34) = 0;
      goto loc_F006CDC8;
    }
  }
  *param_5 = *param_5 + 1;
  if (*(int *)(iVar6 + 0x30) == 0) {
    *(sword **)(iVar6 + 0x30) = param_5;
  }
  else {
    _crfree();
    *(sword **)(iVar6 + 0x30) = param_5;
  }
  *(undefined4 *)(iVar6 + 0x34) = 0;
loc_F006CDC8:
  iVar9 = *(int *)(param_2 + 8);
  iVar7 = 0;
  uVar1 = *(uint *)(param_2 + 0x14);
  do {
    uVar5 = uVar8;
    if (uVar1 <= uVar8) {
      uVar5 = uVar1;
    }
    if (param_3 == 0) {
      uVar1 = iVar10 - *(int *)(param_2 + 8);
      if ((int)uVar1 < 1) {
        _mfs_put(param_1);
        iVar12 = 0;
        goto locret_F006D044;
      }
      if ((int)uVar1 < (int)uVar5) {
        uVar5 = uVar1;
      }
    }
    if (param_3 == 1) {
      uVar1 = *(int *)(param_2 + 8) + uVar5;
      if (*(uint *)(iVar6 + 0x14) < uVar1) {
        *(uint *)(iVar6 + 0x14) = uVar1;
      }
      uVar1 = *(uint *)(param_2 + 8);
    }
    else {
      uVar1 = *(uint *)(param_2 + 8);
    }
    if ((uVar1 < *(uint *)(iVar6 + 0x10)) ||
       (*(uint *)(iVar6 + 0x10) + *(int *)(iVar6 + 0xc) < uVar1 + uVar5)) {
      _remap_vnode(param_1,uVar1,uVar5);
      iVar12 = *(int *)(iVar6 + 8);
    }
    else {
      iVar12 = *(int *)(iVar6 + 8);
    }
    iVar12 = (iVar12 + *(int *)(param_2 + 8)) - *(int *)(iVar6 + 0x10);
    _uiomove(iVar12,uVar5,param_3,param_2);
    if (param_3 == 1) {
      *(uint *)(iVar6 + 0x38) = *(uint *)(iVar6 + 0x38) | 0x40000000;
    }
    iVar2 = *(int *)(iVar6 + 0x34);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar6 + 0x34) = 0;
      _crfree(*(undefined4 *)(iVar6 + 0x30));
      *(undefined4 *)(iVar6 + 0x30) = 0;
      iVar12 = iVar2;
    }
    bVar14 = iVar12 == 0;
    if (param_3 == 1) {
      if ((*(uint *)(param_1[9] + 0xc) & 0x100) != 0) {
        iVar7 = iVar7 + 1;
        bVar14 = iVar12 == 0;
        if (_nmfsbuf <= iVar7) {
          if (!bVar14) {
            iVar7 = 0;
            goto loc_F006CF74;
          }
          _vmp_push(iVar6);
          iVar2 = 0;
          if (0 < iVar7) {
            do {
              iVar2 = iVar2 + 1;
              piVar3 = param_1;
              (**(code **)(param_1[7] + 0x80))(param_1);
              iVar4 = iVar9;
              udiv(iVar9,piVar3);
              _blkflush(param_1,iVar4,uVar8);
              iVar9 = iVar9 + uVar8;
            } while (iVar2 < iVar7);
          }
          iVar2 = *(int *)(iVar6 + 0x34);
          iVar7 = 0;
          if (iVar2 != 0) {
            *(undefined4 *)(iVar6 + 0x34) = 0;
            iVar12 = iVar2;
          }
        }
      }
      bVar14 = iVar12 == 0;
    }
loc_F006CF74:
    if (!bVar14) break;
    uVar1 = *(uint *)(param_2 + 0x14);
    if (((int)uVar1 < 1) || (uVar5 == 0)) break;
  } while( true );
  if (((iVar12 == 0) && (param_3 == 1)) &&
     (((param_4 & 4) != 0 || ((*(uint *)(param_1[9] + 0xc) & 0x100) != 0)))) {
    _vmp_push(iVar6);
    uVar1 = uVar13 + iVar11;
    if (uVar13 < uVar1) {
      iVar10 = param_1[7];
      while( true ) {
        piVar3 = param_1;
        (**(code **)(iVar10 + 0x80))(param_1);
        uVar5 = uVar13;
        udiv(uVar13,piVar3);
        _blkflush(param_1,uVar5,uVar8);
        uVar13 = uVar13 + uVar8;
        if (uVar1 <= uVar13) break;
        iVar10 = param_1[7];
      }
      iVar10 = *(int *)(iVar6 + 0x34);
    }
    else {
      iVar10 = *(int *)(iVar6 + 0x34);
    }
    param_2 = uVar13;
    if (iVar10 != 0) {
      *(undefined4 *)(iVar6 + 0x34) = 0;
      iVar12 = iVar10;
    }
  }
  _mfs_put(param_1);
locret_F006D044:
  return CONCAT44(param_2,iVar12);
}

