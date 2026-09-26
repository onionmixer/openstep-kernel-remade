
int _mfs_io(int *param_1,int param_2,int param_3,byte param_4,sword *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uStack_18;
  
  iVar6 = *(int *)(param_2 + 0x12);
  if (iVar6 == 0) {
    iVar6 = 0;
  }
  else {
    iVar1 = *(int *)(param_2 + 8);
    if ((iVar1 < 0) || (iVar6 + iVar1 < 0)) {
      iVar6 = 0x16;
    }
    else {
      _mfs_get(param_1,iVar1,iVar6);
      iVar1 = *param_1;
      iVar2 = *(int *)(iVar1 + 0x14);
      if ((param_3 == 1) && ((param_4 & 2) != 0)) {
        *(int *)(param_2 + 8) = iVar2;
      }
      uVar3 = *(uint *)(param_2 + 8);
      iVar4 = *(int *)(param_2 + 0x12);
      uVar5 = *(uint *)(param_1[9] + 0x10);
      if ((param_3 == 1) || ((param_3 == 0 && (*(int *)(iVar1 + 0x2c) == 0)))) {
        *param_5 = *param_5 + 1;
        if (*(int *)(iVar1 + 0x2c) != 0) {
          _crfree(*(int *)(iVar1 + 0x2c));
        }
        *(sword **)(iVar1 + 0x2c) = param_5;
      }
      *(undefined4 *)(iVar1 + 0x30) = 0;
      uStack_18 = *(uint *)(param_2 + 8);
      iVar10 = 0;
      do {
        uVar9 = uVar5;
        if (*(uint *)(param_2 + 0x12) <= uVar5) {
          uVar9 = *(uint *)(param_2 + 0x12);
        }
        if (param_3 == 0) {
          uVar7 = iVar2 - *(int *)(param_2 + 8);
          if ((int)uVar7 < 1) {
            _mfs_put(param_1);
            return 0;
          }
          if ((int)uVar7 < (int)uVar9) {
            uVar9 = uVar7;
          }
        }
        if ((param_3 == 1) &&
           (uVar7 = uVar9 + *(int *)(param_2 + 8), *(uint *)(iVar1 + 0x14) < uVar7)) {
          *(uint *)(iVar1 + 0x14) = uVar7;
        }
        uVar7 = *(uint *)(param_2 + 8);
        if ((uVar7 < *(uint *)(iVar1 + 0x10)) ||
           (*(int *)(iVar1 + 0xc) + *(uint *)(iVar1 + 0x10) < uVar9 + uVar7)) {
          _remap_vnode(param_1,uVar7,uVar9);
        }
        iVar6 = _uiomove((*(int *)(param_2 + 8) + *(int *)(iVar1 + 8)) - *(int *)(iVar1 + 0x10),
                         uVar9,param_3,param_2);
        if (param_3 == 1) {
          *(byte *)(iVar1 + 0x34) = *(byte *)(iVar1 + 0x34) | 0x40;
        }
        iVar8 = *(int *)(iVar1 + 0x30);
        if (iVar8 != 0) {
          *(undefined4 *)(iVar1 + 0x30) = 0;
          _crfree(*(undefined4 *)(iVar1 + 0x2c));
          *(undefined4 *)(iVar1 + 0x2c) = 0;
          iVar6 = iVar8;
        }
        if (((param_3 == 1) && ((*(byte *)(param_1[9] + 0xe) & 1) != 0)) &&
           (iVar10 = iVar10 + 1, _nmfsbuf <= iVar10)) {
          if (iVar6 == 0) {
            _vmp_push(iVar1);
            iVar8 = 0;
            if (0 < iVar10) {
              do {
                uVar7 = (**(code **)(param_1[7] + 0x80))(param_1,uVar5);
                _blkflush(param_1,uStack_18 / uVar7);
                uStack_18 = uVar5 + uStack_18;
                iVar8 = iVar8 + 1;
              } while (iVar8 < iVar10);
            }
            iVar10 = *(int *)(iVar1 + 0x30);
            if (iVar10 != 0) {
              *(undefined4 *)(iVar1 + 0x30) = 0;
              iVar6 = iVar10;
            }
          }
          iVar10 = 0;
        }
        if (iVar6 != 0) goto loc_404DA76;
      } while ((0 < *(int *)(param_2 + 0x12)) && (uVar9 != 0));
      if ((param_3 == 1) && (((param_4 & 4) != 0 || ((*(byte *)(param_1[9] + 0xe) & 1) != 0)))) {
        _vmp_push(iVar1);
        uVar9 = uVar3 + iVar4;
        for (; uVar3 < uVar9; uVar3 = uVar5 + uVar3) {
          uVar7 = (**(code **)(param_1[7] + 0x80))(param_1,uVar5);
          _blkflush(param_1,uVar3 / uVar7);
        }
        iVar2 = *(int *)(iVar1 + 0x30);
        if (iVar2 != 0) {
          *(undefined4 *)(iVar1 + 0x30) = 0;
          iVar6 = iVar2;
        }
      }
loc_404DA76:
      _mfs_put(param_1);
    }
  }
  return iVar6;
}

