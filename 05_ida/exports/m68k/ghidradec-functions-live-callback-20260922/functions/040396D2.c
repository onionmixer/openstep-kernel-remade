
/* WARNING: Removing unreachable block (ram,0x040399a2) */

int sub_40396D2(int *param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  undefined *puVar14;
  int aiStack_42 [15];
  
  piVar13 = (int *)0x0;
  iVar12 = 0;
  if (dword_40AF5C6 == 0) {
    _ihinit();
    dword_40AF5C6 = 1;
  }
  uVar3 = 3;
  if ((*(byte *)(param_3 + 0xf) & 1) != 0) {
    uVar3 = 1;
  }
  iVar4 = (*(code *)**(undefined4 **)(*param_1 + 0x1c))
                    (param_1,uVar3,*(undefined4 *)(_active_u + 0x1a));
  if (iVar4 != 0) {
    return iVar4;
  }
  bVar1 = true;
  uVar5 = (**(code **)(*(int *)(*param_1 + 0x1c) + 0x80))(*param_1);
  if (uVar5 == 0) {
    uVar3 = 3;
    if ((*(byte *)(param_3 + 0xf) & 1) != 0) {
      uVar3 = 1;
    }
    (**(code **)(*(int *)(*param_1 + 0x1c) + 4))(*param_1,uVar3,1,*(undefined4 *)(_active_u + 0x1a))
    ;
    _binval(*param_1);
    return 0xf;
  }
  iVar6 = _bread(*param_1,0x2000 / uVar5,0x2000);
  iVar11 = 0;
  iVar4 = iVar12;
  piVar2 = _mounttab;
  if ((*(byte *)(iVar6 + 3) & 4) == 0) {
    while (piVar13 = piVar2, piVar13 != (int *)0x0) {
      iVar4 = *(int *)((int)piVar13 + 10);
      if ((iVar4 != 0) && (*(sword *)(piVar13 + 1) == *(sword *)(*param_1 + 0x2c))) {
        if ((*(byte *)(param_3 + 0xf) & 0x40) != 0) goto loc_40398E2;
        piVar13 = (int *)0x0;
        iVar11 = 0x10;
        bVar1 = false;
        iVar4 = iVar12;
        goto loc_4039B50;
      }
      piVar2 = (int *)piVar13[7];
    }
    _vol_notify_cancel((int)*(sword *)(*param_1 + 0x2c));
    piVar2 = _mounttab;
    if ((*(uint *)(param_3 + 0xc) & 0x40) == 0) {
      while (piVar13 = piVar2, piVar13 != (int *)0x0) {
        if (*(int *)((int)piVar13 + 10) == 0) goto loc_4039876;
        piVar2 = (int *)piVar13[7];
      }
      piVar13 = (int *)_kalloc(0x20);
      _bzero(piVar13,0x20);
      if (piVar13 == (int *)0x0) {
        iVar11 = 0x18;
        goto loc_4039B56;
      }
      piVar13[7] = (int)_mounttab;
      _mounttab = piVar13;
loc_4039876:
      *(int **)(param_3 + 0x126) = piVar13;
      *piVar13 = param_3;
      *(int *)((int)piVar13 + 10) = iVar6;
      *(undefined2 *)(piVar13 + 1) = 0xffff;
      *(int *)((int)piVar13 + 6) = *param_1;
      iVar7 = *(int *)(iVar6 + 0x20);
      if (((*(int *)(iVar7 + 0x55c) != 0x11954) || (0x2000 < (int)*(uint *)(iVar7 + 0x30))) ||
         (*(uint *)(iVar7 + 0x30) < 0x562)) {
        iVar11 = 0x16;
        goto loc_4039B56;
      }
      iVar4 = _geteblk(*(undefined4 *)(iVar7 + 0x68));
      *(int *)((int)piVar13 + 10) = iVar4;
      _bcopy(*(undefined4 *)(iVar6 + 0x20),*(undefined4 *)(iVar4 + 0x20),
             *(undefined4 *)(iVar7 + 0x68));
loc_40398E2:
      if ((*(byte *)(param_3 + 0xf) & 1) == 0) {
        *(undefined *)(dword_40B57D4 + 100) = 0;
        _bwrite(iVar6);
        if (*(char *)(dword_40B57D4 + 100) == '\x1e') {
          *(undefined *)(dword_40B57D4 + 100) = 0;
          if (*param_1 == _rootvp) {
                    /* WARNING: Subroutine does not return */
            _panic(aRootDeviceIsPh);
          }
          *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) | 1;
        }
      }
      else {
        _brelse(iVar6);
      }
      iVar6 = 0;
      iVar12 = *(int *)(iVar4 + 0x20);
      if ((*(uint *)(param_3 + 0xc) & 1) == 0) {
        if (*(char *)(iVar12 + 0xd1) == '\x01') {
          *(undefined *)(iVar12 + 0xd1) = 2;
        }
        else {
          *(undefined *)(iVar12 + 0xd1) = 3;
        }
        *(undefined *)(iVar12 + 0xd0) = 1;
        *(undefined *)(iVar12 + 0xd2) = 0;
        if ((*(byte *)(param_3 + 0xf) & 0x40) != 0) {
          *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) & 0xffffffbf;
          _sbupdate(piVar13);
          return 0;
        }
      }
      else {
        if ((*(uint *)(param_3 + 0xc) & 0x40) != 0) {
          puVar14 = aMountfsCanTRem;
          goto loc_403995C;
        }
        *(undefined *)(iVar12 + 0xd0) = 0;
        *(undefined *)(iVar12 + 0xd2) = 1;
      }
      *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(iVar12 + 0x30);
      iVar8 = (*(int *)(iVar12 + 0x9c) + -1 + *(int *)(iVar12 + 0x34)) / *(int *)(iVar12 + 0x34);
      iVar7 = _kalloc(*(int *)(iVar12 + 0x9c));
      if (iVar7 != 0) {
        iVar9 = 0;
        if (0 < iVar8) {
          do {
            iVar10 = *(int *)(iVar12 + 0x30);
            if (iVar8 < *(int *)(iVar12 + 0x38) + iVar9) {
              iVar10 = *(int *)(iVar12 + 0x34) * (iVar8 - iVar9);
            }
            iVar6 = _bread(*(undefined4 *)((int)piVar13 + 6),
                           iVar9 + *(int *)(iVar12 + 0x98) << (*(uint *)(iVar12 + 100) & 0x3f),
                           iVar10);
            if ((*(byte *)(iVar6 + 3) & 4) != 0) {
              _kfree(iVar7,*(undefined4 *)(iVar12 + 0x9c));
              goto loc_4039B50;
            }
            _bcopy(*(undefined4 *)(iVar6 + 0x20),iVar7,iVar10);
            *(int *)(iVar12 + (iVar9 >> (*(uint *)(iVar12 + 0x60) & 0x3f)) * 4 + 0x2d8) = iVar7;
            iVar7 = iVar10 + iVar7;
            _brelse(iVar6);
            iVar9 = *(int *)(iVar12 + 0x38) + iVar9;
          } while (iVar9 < iVar8);
        }
        if (*(char *)(iVar12 + 0xd2) == '\0') {
          _sbupdate(piVar13);
        }
        *(byte *)(iVar12 + 0xd3) = *(byte *)(iVar12 + 0xd3) & 0xfc;
        iVar4 = (*(int *)(iVar12 + 0x3c) * *(int *)(iVar12 + 0x28)) / 100;
        *(int *)(iVar12 + 0x8c) = iVar4;
        *(int *)(iVar12 + 0x88) = iVar4;
        if (iVar4 < 0x65) {
          *(int *)(iVar12 + 0x88) = iVar4 * 2;
        }
        else {
          *(int *)(iVar12 + 0x88) = iVar4 + 100;
        }
        iVar4 = (*(int *)(iVar12 + 0xb8) * *(int *)(iVar12 + 0x2c)) / 100;
        *(int *)(iVar12 + 0x94) = iVar4;
        if (0x32 < iVar4) {
          *(undefined4 *)(iVar12 + 0x94) = 0x32;
        }
        *(undefined4 *)(iVar12 + 0x90) = *(undefined4 *)(iVar12 + 0x94);
        *(undefined2 *)(piVar13 + 1) = *(undefined2 *)(*(int *)((int)piVar13 + 6) + 0x2c);
        *(int *)(param_3 + 0x14) = (int)*(sword *)(piVar13 + 1);
        *(undefined4 *)(param_3 + 0x18) = 0;
        _copystr(param_2,iVar12 + 0xd4,0x1ff,aiStack_42);
        _bzero(iVar12 + aiStack_42[0] + 0xd4,0x200 - aiStack_42[0]);
        return 0;
      }
      iVar11 = 0xc;
      iVar12 = iVar4;
      goto loc_4039B56;
    }
    *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) & 0xffffffbf;
    puVar14 = aMountfsIllegal;
    iVar4 = iVar12;
loc_403995C:
    _printf(puVar14);
    iVar11 = 0x16;
  }
loc_4039B50:
  iVar12 = iVar4;
  if (iVar11 == 0) {
    iVar11 = 5;
  }
loc_4039B56:
  if (piVar13 != (int *)0x0) {
    *(undefined4 *)((int)piVar13 + 10) = 0;
  }
  if (iVar12 != 0) {
    _brelse(iVar12);
  }
  if (iVar6 != 0) {
    _brelse(iVar6);
  }
  if (bVar1) {
    uVar3 = 3;
    if ((*(byte *)(param_3 + 0xf) & 1) != 0) {
      uVar3 = 1;
    }
    (**(code **)(*(int *)(*param_1 + 0x1c) + 4))(*param_1,uVar3,1,*(undefined4 *)(_active_u + 0x1a))
    ;
    _binval(*param_1);
  }
  return iVar11;
}

