
int _bmap(int param_1,int param_2,uint param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iStack_14;
  int iStack_10;
  int iStack_8;
  
  iStack_8 = 0;
  iStack_10 = 0;
  if (param_2 < 0) {
loc_40352C4:
    *(undefined *)(dword_40B57D4 + 100) = 0x1b;
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x4e);
  _rablock = 0;
  _rasize = 0;
  if ((param_3 & 0x20) != 0) {
    param_3 = param_3 & 0xffffffdf;
  }
  uVar4 = *(uint *)(param_1 + 0x6e);
  uVar7 = uVar4 >> (*(uint *)(iVar1 + 0x50) & 0x3f);
  if ((((param_3 == 0) && ((int)uVar7 < 0xc)) && ((int)uVar7 < param_2)) &&
     (*(int *)(param_1 + uVar7 * 4 + 0x8a) != 0)) {
    if (((int)uVar7 < 0xc) && (uVar4 < uVar7 + 1 << (*(uint *)(iVar1 + 0x50) & 0x3f))) {
      uVar4 = *(uint *)(iVar1 + 0x4c) &
              (*(int *)(iVar1 + 0x34) + (uVar4 & ~*(uint *)(iVar1 + 0x48))) - 1;
    }
    else {
      uVar4 = *(uint *)(iVar1 + 0x30);
    }
    if ((uVar4 < *(uint *)(iVar1 + 0x30)) && (uVar4 != 0)) {
      uVar2 = _blkpref(param_1,uVar7,uVar7,param_1 + 0x8a,uVar4,*(uint *)(iVar1 + 0x30));
      iVar8 = param_1 + uVar7 * 4;
      iVar3 = _realloccg(param_1,*(undefined4 *)(iVar8 + 0x8a),uVar2);
      if (iVar3 == 0) {
        return -1;
      }
      *(uint *)(param_1 + 0x6e) = *(int *)(iVar1 + 0x30) * (uVar7 + 1);
      *(int *)(iVar8 + 0x8a) = *(int *)(iVar3 + 0x24) >> (*(uint *)(iVar1 + 100) & 0x3f);
      *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
      if (param_5 == (undefined4 *)0x0) {
        _bdwrite(iVar3);
      }
      else {
        _bwrite(iVar3);
        _iupdat(param_1,1);
      }
    }
  }
  if (param_2 < 0xc) {
    iVar8 = *(int *)(param_1 + param_2 * 4 + 0x8a);
    if (param_3 == 1) {
      if (iVar8 == 0) {
        return -1;
      }
      goto loc_4035240;
    }
    if (iVar8 == 0) {
      uVar4 = *(uint *)(iVar1 + 0x30);
      uVar7 = uVar4 * (param_2 + 1);
      if (*(uint *)(param_1 + 0x6e) <= uVar7 && uVar7 - *(uint *)(param_1 + 0x6e) != 0) {
        uVar4 = *(uint *)(iVar1 + 0x4c) & (*(int *)(iVar1 + 0x34) + param_4) - 1U;
      }
      uVar2 = _blkpref(param_1,param_2,param_2,param_1 + 0x8a,uVar4);
      iVar3 = _alloc(param_1,uVar2);
    }
    else {
      uVar7 = *(int *)(iVar1 + 0x30) * (param_2 + 1);
      uVar4 = *(uint *)(param_1 + 0x6e);
      if (uVar7 < uVar4 || uVar7 - uVar4 == 0) goto loc_4035240;
      uVar4 = *(uint *)(iVar1 + 0x4c) &
              *(int *)(iVar1 + 0x34) + -1 + (uVar4 & ~*(uint *)(iVar1 + 0x48));
      uVar7 = *(uint *)(iVar1 + 0x4c) & *(int *)(iVar1 + 0x34) + -1 + param_4;
      if (uVar7 <= uVar4) goto loc_4035240;
      uVar2 = _blkpref(param_1,param_2,param_2,param_1 + 0x8a,uVar4,uVar7);
      iVar3 = _realloccg(param_1,iVar8,uVar2);
    }
    if (iVar3 != 0) {
      iVar8 = *(int *)(iVar3 + 0x24) >> (*(uint *)(iVar1 + 100) & 0x3f);
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = 1;
      }
      if ((*(word *)(param_1 + 0x62) & 0xf000) == 0x4000) {
        _bwrite(iVar3);
      }
      else {
        _bdwrite(iVar3);
      }
      *(int *)(param_1 + param_2 * 4 + 0x8a) = iVar8;
      *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
loc_4035240:
      if (10 < param_2) {
        return iVar8;
      }
      _rablock = *(int *)(param_1 + param_2 * 4 + 0x8e) << (*(uint *)(iVar1 + 100) & 0x3f);
      if ((param_2 + 1 < 0xc) &&
         (*(uint *)(param_1 + 0x6e) < (uint)(param_2 + 2 << (*(uint *)(iVar1 + 0x50) & 0x3f)))) {
        _rasize = *(uint *)(iVar1 + 0x4c) &
                  (*(int *)(iVar1 + 0x34) + (*(uint *)(param_1 + 0x6e) & ~*(uint *)(iVar1 + 0x48)))
                  - 1;
        return iVar8;
      }
      _rasize = *(undefined4 *)(iVar1 + 0x30);
      return iVar8;
    }
  }
  else {
    iStack_14 = 0;
    iVar10 = 1;
    iVar8 = param_2 + -0xc;
    iVar3 = 3;
    do {
      iVar10 = *(int *)(iVar1 + 0x74) * iVar10;
      if (iVar10 - iVar8 != 0 && iVar8 <= iVar10) break;
      iVar8 = iVar8 - iVar10;
      iVar3 = iVar3 + -1;
    } while (0 < iVar3);
    if (iVar3 == 0) goto loc_40352C4;
    iVar6 = param_1 + (3 - iVar3) * 4;
    iVar9 = *(int *)(iVar6 + 0xba);
    if (iVar9 == 0) {
      if (param_3 == 1) {
        return -1;
      }
      iStack_14 = _blkpref(param_1,param_2,0,0);
      iVar5 = _alloc(param_1,iStack_14,*(undefined4 *)(iVar1 + 0x30));
      if (iVar5 == 0) {
        return -1;
      }
      iVar9 = *(int *)(iVar5 + 0x24) >> (*(uint *)(iVar1 + 100) & 0x3f);
      _bwrite(iVar5);
      *(int *)(iVar6 + 0xba) = iVar9;
      *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = 1;
      }
    }
    while( true ) {
      if (3 < iVar3) {
        if (iStack_8 < *(int *)(iVar1 + 0x74) + -1) {
          _rablock = *(int *)(iStack_10 + 4 + iStack_8 * 4) << (*(uint *)(iVar1 + 100) & 0x3f);
          _rasize = *(undefined4 *)(iVar1 + 0x30);
          return iVar9;
        }
        return iVar9;
      }
      iVar6 = _bread(*(undefined4 *)(param_1 + 0x3e),iVar9 << (*(uint *)(iVar1 + 100) & 0x3f),
                     *(undefined4 *)(iVar1 + 0x30));
      if ((*(byte *)(iVar6 + 3) & 4) != 0) {
        _brelse(iVar6);
        return 0;
      }
      iStack_10 = *(int *)(iVar6 + 0x20);
      iVar10 = iVar10 / *(int *)(iVar1 + 0x74);
      iStack_8 = (iVar8 / iVar10) % *(int *)(iVar1 + 0x74);
      iVar9 = *(int *)(iStack_10 + iStack_8 * 4);
      if (iVar9 == 0) break;
      _brelse(iVar6);
loc_403547A:
      iVar3 = iVar3 + 1;
    }
    if (param_3 != 1) {
      if (iStack_14 == 0) {
        iVar9 = iStack_8;
        iVar5 = iStack_10;
        if (iVar3 < 3) {
          iVar9 = 0;
          iVar5 = 0;
        }
        iStack_14 = _blkpref(param_1,param_2,iVar9,iVar5);
      }
      iVar5 = _alloc(param_1,iStack_14,*(undefined4 *)(iVar1 + 0x30));
      if (iVar5 != 0) {
        iVar9 = *(int *)(iVar5 + 0x24) >> (*(uint *)(iVar1 + 100) & 0x3f);
        if (((iVar3 < 3) || ((*(word *)(param_1 + 0x62) & 0xf000) == 0x4000)) ||
           (param_5 != (undefined4 *)0x0)) {
          _bwrite(iVar5);
        }
        else {
          _bdwrite(iVar5);
        }
        *(int *)(iStack_10 + iStack_8 * 4) = iVar9;
        if (param_5 == (undefined4 *)0x0) {
          _bdwrite(iVar6);
        }
        else {
          _bwrite(iVar6);
        }
        goto loc_403547A;
      }
    }
    _brelse(iVar6);
  }
  return -1;
}

