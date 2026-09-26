
int sub_402ABC8(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  undefined uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined4 uStack_4a;
  undefined4 uStack_46;
  undefined4 uStack_42;
  undefined auStack_3e [58];
  
  iVar9 = 0;
  bVar2 = false;
  if (*(int *)(param_2 + 0x12) == 0) {
    iVar9 = 0;
  }
  else if ((*(int *)(param_2 + 8) < 0) ||
          (uVar6 = *(int *)(param_2 + 0x12) + *(int *)(param_2 + 8), (int)uVar6 < 0)) {
    iVar9 = 0x16;
  }
  else if (((param_3 == 1) && (param_1[10] == 1)) && (*(uint *)((int)_active_u + 0x25e) < uVar6)) {
    _psignal(*_active_u,0x19);
    iVar9 = 0x1b;
  }
  else {
    iVar1 = *(int *)((int)param_1 + 0x2e);
    _rlock(iVar1);
    uVar6 = *(uint *)(*(int *)(param_1[9] + 0x126) + 0x22) & 0xfffffc00;
    if ((int)uVar6 < 1) {
                    /* WARNING: Subroutine does not return */
      _panic(aRwvpZeroSize);
    }
    do {
      uVar8 = *(uint *)(param_2 + 8) % uVar6;
      uVar7 = *(uint *)(param_2 + 8) / uVar6;
      uVar5 = *(uint *)(param_2 + 0x12);
      if (uVar6 - uVar8 < *(uint *)(param_2 + 0x12)) {
        uVar5 = uVar6 - uVar8;
      }
      (**(code **)(param_1[7] + 0x50))(param_1,uVar7,&uStack_42,&uStack_46);
      if ((*(byte *)((int)param_1 + 5) & 0x40) == 0) {
        if (param_3 == 0) {
          if ((int)uVar7 < 0) {
            iVar3 = _geteblk(uVar6);
            _blkclr(*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(iVar3 + 0x14));
            *(undefined4 *)(iVar3 + 0x28) = 0;
          }
          else {
            iVar3 = _incore(uStack_42,uStack_46);
            if (iVar3 != 0) {
              _nfs_validate_caches(uStack_42,param_5,0);
            }
            if (uVar7 == *(int *)(iVar1 + 0x62) + 1U) {
              (**(code **)(param_1[7] + 0x50))(param_1,uVar7 + 1,&uStack_42,&uStack_4a);
              iVar3 = _breada(uStack_42,uStack_46,uVar6,uStack_4a,uVar6);
            }
            else {
loc_402ADC6:
              iVar3 = _bread(uStack_42,uStack_46,uVar6);
            }
          }
        }
        else {
          if (*(sword *)(iVar1 + 0x60) != 0) {
            iVar9 = (int)*(sword *)(iVar1 + 0x60);
            goto loc_402AED8;
          }
          if (uVar6 != uVar5) goto loc_402ADC6;
          iVar3 = _getblk(uStack_42,uStack_46,uVar6);
        }
      }
      else {
        iVar3 = _geteblk(uVar6);
        if ((param_3 == 0) &&
           (iVar9 = sub_402B07A(param_1,uVar8 + *(int *)(iVar3 + 0x20),*(undefined4 *)(param_2 + 8),
                                uVar5,iVar3 + 0x28,param_5,auStack_3e), iVar9 != 0)) {
          _brelse(iVar3);
          goto loc_402AED8;
        }
      }
      if ((*(byte *)(iVar3 + 3) & 4) != 0) {
        iVar9 = _geterror(iVar3);
        _brelse(iVar3);
        goto loc_402AED8;
      }
      if (param_3 == 0) {
        *(uint *)(iVar1 + 0x62) = uVar7;
        uVar7 = *(int *)(iVar1 + 0x90) - *(int *)(param_2 + 8);
        if ((int)uVar7 < 1) {
          _brelse(iVar3);
          iVar9 = 0;
          goto loc_402AED8;
        }
        if ((int)uVar7 < (int)uVar5) {
          bVar2 = true;
          uVar5 = uVar7;
        }
      }
      uVar4 = _uiomove(uVar8 + *(int *)(iVar3 + 0x20),uVar5,param_3,param_2);
      *(undefined *)(dword_40B57D4 + 100) = uVar4;
      if (param_3 == 0) {
        _brelse(iVar3);
      }
      else {
        uVar7 = *(uint *)(param_2 + 8);
        if (*(uint *)(iVar1 + 0x90) < uVar7) {
          *(uint *)(iVar1 + 0x90) = uVar7;
          if (*(uint *)(*param_1 + 0x14) < uVar7) {
            *(uint *)(*param_1 + 0x14) = uVar7;
          }
        }
        if ((*(byte *)((int)param_1 + 5) & 0x40) == 0) {
          *(word *)(iVar1 + 0x5e) = *(word *)(iVar1 + 0x5e) | 0x10;
          if (uVar6 == uVar8 + uVar5) {
            *(word *)(iVar3 + 2) = *(word *)(iVar3 + 2) | 0x80;
            _bawrite(iVar3);
          }
          else {
            _bdwrite(iVar3);
          }
        }
        else {
          iVar9 = _nfswrite(param_1,*(int *)(iVar3 + 0x20) + uVar8,*(int *)(param_2 + 8) - uVar5,
                            uVar5,param_5);
          _brelse(iVar3);
        }
      }
    } while (((*(char *)(dword_40B57D4 + 100) == '\0') && (0 < *(int *)(param_2 + 0x12))) &&
            (!bVar2));
    if (iVar9 == 0) {
      iVar9 = (int)*(char *)(dword_40B57D4 + 100);
    }
loc_402AED8:
    _runlock(iVar1);
  }
  return iVar9;
}

