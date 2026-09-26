
int sub_403A216(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  word wVar5;
  int iVar6;
  undefined uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  int iStack_8;
  
  iStack_8 = 0;
  iVar1 = *(int *)(param_2 + 0x12);
  if (1 < param_3) {
                    /* WARNING: Subroutine does not return */
    _panic(&aRwip);
  }
  wVar5 = *(word *)(param_1 + 0x62) & 0xf000;
  if (((wVar5 != 0x8000) && (wVar5 != 0x4000)) && (wVar5 != 0xa000)) {
                    /* WARNING: Subroutine does not return */
    _panic(aRwipType);
  }
  if (-1 < *(int *)(param_2 + 8)) {
    uVar4 = *(int *)(param_2 + 0x12) + *(int *)(param_2 + 8);
    if (-1 < (int)uVar4) {
      if (*(int *)(param_2 + 0x12) == 0) {
        return 0;
      }
      if (param_3 == 1) {
        if ((wVar5 == 0x8000) && (*(uint *)((int)_active_u + 0x25e) < uVar4)) {
          _psignal(*_active_u,0x19);
          return 0x1b;
        }
      }
      else {
        *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 4;
      }
      uVar2 = *(undefined4 *)(param_1 + 0x3e);
      iVar3 = *(int *)(param_1 + 0x4e);
      uVar4 = *(uint *)(iVar3 + 0x30);
      *(undefined *)(dword_40B57D4 + 100) = 0;
      param_4 = param_4 & 4;
      while( true ) {
        uVar8 = *(uint *)(param_2 + 8);
        uVar10 = uVar8 % uVar4;
        uVar9 = uVar8 / uVar4;
        uVar12 = *(uint *)(param_2 + 0x12);
        if (uVar4 - uVar10 < *(uint *)(param_2 + 0x12)) {
          uVar12 = uVar4 - uVar10;
        }
        if (param_3 == 0) {
          uVar8 = *(int *)(param_1 + 0x6e) - uVar8;
          if ((int)uVar8 < 1) {
            return 0;
          }
          if ((int)uVar8 < (int)uVar12) {
            uVar12 = uVar8;
          }
        }
        piVar11 = (int *)0x0;
        if (param_4 != 0) {
          piVar11 = &iStack_8;
        }
        iVar6 = _bmap(param_1,uVar9,-(int)-(param_3 != 1),uVar12 + uVar10,piVar11);
        iVar6 = iVar6 << (*(uint *)(iVar3 + 100) & 0x3f);
        if (((*(char *)(dword_40B57D4 + 100) == '\x1c') && (param_3 == 1)) &&
           ((iVar1 != *(int *)(param_2 + 0x12) && -1 < iVar1 - *(int *)(param_2 + 0x12) &&
            ((*(byte *)(*_active_u + 0x16) & 0x40) != 0)))) break;
        if (*(char *)(dword_40B57D4 + 100) != '\0') {
loc_403A3CE:
          return (int)*(char *)(dword_40B57D4 + 100);
        }
        if (param_3 == 1) {
          if (iVar6 < 0) goto loc_403A3CE;
          if ((*(uint *)(param_1 + 0x6e) < uVar12 + *(int *)(param_2 + 8)) &&
             (((wVar5 == 0x4000 || (wVar5 == 0x8000)) || (wVar5 == 0xa000)))) {
            uVar8 = uVar12 + *(int *)(param_2 + 8);
            *(uint *)(param_1 + 0x6e) = uVar8;
            if (*(uint *)(*(int *)(param_1 + 0xc) + 0x14) < uVar8) {
              *(uint *)(*(int *)(param_1 + 0xc) + 0x14) = uVar8;
            }
            if (param_4 != 0) {
              iStack_8 = 1;
            }
          }
        }
        if (((int)uVar9 < 0xc) &&
           (*(uint *)(param_1 + 0x6e) < uVar9 + 1 << (*(uint *)(iVar3 + 0x50) & 0x3f))) {
          uVar8 = *(uint *)(iVar3 + 0x4c) &
                  (*(int *)(iVar3 + 0x34) + (*(uint *)(param_1 + 0x6e) & ~*(uint *)(iVar3 + 0x48)))
                  - 1;
        }
        else {
          uVar8 = *(uint *)(iVar3 + 0x30);
        }
        if (param_3 == 0) {
          if (iVar6 < 0) {
            iVar6 = _geteblk(uVar8);
            _blkclr(*(undefined4 *)(iVar6 + 0x20),*(undefined4 *)(iVar6 + 0x14));
            *(undefined4 *)(iVar6 + 0x28) = 0;
          }
          else if (*(int *)(param_1 + 0x56) + 1U == uVar9) {
            iVar6 = _breada(uVar2,iVar6,uVar8,_rablock,_rasize);
          }
          else {
            iVar6 = _bread(uVar2,iVar6,uVar8);
          }
          *(uint *)(param_1 + 0x56) = uVar9;
        }
        else if (uVar4 == uVar12) {
          iVar6 = _getblk(uVar2,iVar6,uVar8);
        }
        else {
          iVar6 = _bread(uVar2,iVar6,uVar8);
        }
        uVar8 = *(int *)(iVar6 + 0x14) - *(int *)(iVar6 + 0x28);
        if ((int)uVar8 < (int)uVar12) {
          uVar12 = uVar8;
        }
        if ((*(byte *)(iVar6 + 3) & 4) != 0) {
          _brelse(iVar6);
          return 5;
        }
        uVar7 = _uiomove(uVar10 + *(int *)(iVar6 + 0x20),uVar12,param_3,param_2);
        *(undefined *)(dword_40B57D4 + 100) = uVar7;
        if (((param_4 != 0) && ((*(word *)(param_1 + 0x62) & 0x200) != 0)) &&
           ((_stickyhack != 0 && ((*(word *)(param_1 + 0x62) & 0x49) == 0)))) {
          *(byte *)(iVar6 + 1) = *(byte *)(iVar6 + 1) | 0x40;
        }
        if (param_3 == 0) {
          if ((uVar4 == uVar10 + uVar12) || (*(int *)(param_2 + 8) == *(int *)(param_1 + 0x6e))) {
            *(word *)(iVar6 + 2) = *(word *)(iVar6 + 2) | 0x80;
          }
          _brelse(iVar6);
        }
        else {
          if ((param_4 == 0) && ((*(word *)(param_1 + 0x62) & 0xf000) != 0x4000)) {
            if (uVar4 == uVar10 + uVar12) {
              *(word *)(iVar6 + 2) = *(word *)(iVar6 + 2) | 0x80;
              _bawrite(iVar6);
            }
            else {
              _bdwrite(iVar6);
            }
          }
          else {
            _bwrite(iVar6);
          }
          *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x42;
          if (*(sword *)(*(int *)((int)_active_u + 0x1a) + 6) != 0) {
            *(word *)(param_1 + 0x62) = *(word *)(param_1 + 0x62) & 0xf3ff;
          }
        }
        if (((*(char *)(dword_40B57D4 + 100) != '\0') || (*(int *)(param_2 + 0x12) < 1)) ||
           (uVar12 == 0)) goto loc_403A5F6;
      }
      *(undefined *)(dword_40B57D4 + 100) = 0;
loc_403A5F6:
      if (iStack_8 != 0) {
        _iupdat(param_1,1);
      }
      return (int)*(char *)(dword_40B57D4 + 100);
    }
  }
  return 0x16;
}
