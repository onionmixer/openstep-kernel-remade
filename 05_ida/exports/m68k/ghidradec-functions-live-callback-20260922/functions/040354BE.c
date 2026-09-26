
int _dirlook(int param_1,char *param_2,int *param_3)

{
  word wVar1;
  word *pwVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  
  iVar11 = 0;
  uVar7 = 0;
  uVar3 = _strlen(param_2);
  if ((*(word *)(param_1 + 0x62) & 0xf000) != 0x4000) {
    return 0x14;
  }
  iVar4 = _iaccess(param_1,0x40);
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar4 = _dnlc_lookup(param_1 + 0xc,param_2,0);
  if (iVar4 != 0) {
    *(sword *)(iVar4 + 6) = *(sword *)(iVar4 + 6) + 1;
    *param_3 = *(int *)(iVar4 + 0x2e);
    while ((*(byte *)(*param_3 + 0x43) & 1) != 0) {
      pwVar2 = (word *)(*param_3 + 0x42);
      *pwVar2 = *pwVar2 | 0x10;
      _sleep(*param_3,10);
    }
    *(word *)(*param_3 + 0x42) = *(word *)(*param_3 + 0x42) | 1;
    return 0;
  }
  while ((*(word *)(param_1 + 0x42) & 1) != 0) {
    *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 0x10;
    _sleep(param_1,10);
  }
  *(word *)(param_1 + 0x42) = *(word *)(param_1 + 0x42) | 1;
  if (*(uint *)(param_1 + 0x6e) < *(uint *)(param_1 + 0x4a)) {
    *(undefined4 *)(param_1 + 0x4a) = 0;
  }
  uVar6 = *(uint *)(param_1 + 0x4a);
  if (uVar6 == 0) {
    uVar6 = 0;
    iVar4 = 1;
  }
  else {
    uVar7 = ~*(uint *)(*(int *)(param_1 + 0x4e) + 0x48) & uVar6;
    if ((uVar7 != 0) && (iVar11 = _blkatoff(param_1,uVar6,0), iVar11 == 0)) {
loc_4035788:
      iVar4 = (int)*(char *)(dword_40B57D4 + 100);
      goto loc_40357A6;
    }
    iVar4 = 2;
  }
  uVar8 = *(int *)(param_1 + 0x6e) + 0x3ffU & 0xfffffc00;
joined_r0x040355e2:
  for (; uVar6 < uVar8; uVar6 = uVar9 + uVar6) {
    if ((uVar6 & ~*(uint *)(*(int *)(param_1 + 0x4e) + 0x48)) == 0) {
      if (iVar11 != 0) {
        _brelse(iVar11);
      }
      iVar11 = _blkatoff(param_1,uVar6,0);
      if (iVar11 == 0) goto loc_4035788;
      uVar7 = 0;
    }
    piVar10 = (int *)(uVar7 + *(int *)(iVar11 + 0x20));
    if ((*(sword *)(piVar10 + 1) == 0) ||
       ((_dirchk != 0 && (iVar5 = sub_4036A22(param_1,piVar10,uVar7,uVar6), iVar5 != 0)))) {
      uVar9 = 0x400 - (uVar7 & 0x3ff);
    }
    else {
      if ((((*piVar10 != 0) && (uVar3 == *(word *)((int)piVar10 + 6))) &&
          (*param_2 == *(char *)(piVar10 + 2))) &&
         (iVar5 = _bcmp(param_2,piVar10 + 2,uVar3), iVar5 == 0)) {
        iVar4 = *piVar10;
        _brelse(iVar11);
        iVar11 = 0;
        *(uint *)(param_1 + 0x4a) = uVar6;
        if (((uVar3 == 2) && (*param_2 == '.')) && (param_2[1] == '.')) {
          wVar1 = *(word *)(param_1 + 0x42);
          *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
          if ((wVar1 & 0x10) != 0) {
            *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
            _wakeup(param_1);
          }
          iVar4 = _iget((int)*(sword *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x4e),iVar4);
        }
        else {
          if (iVar4 == *(int *)(param_1 + 0x46)) {
            *(sword *)(param_1 + 0x12) = *(sword *)(param_1 + 0x12) + 1;
            iVar4 = param_1;
            goto loc_403574A;
          }
          iVar4 = _iget((int)*(sword *)(param_1 + 0x44),*(undefined4 *)(param_1 + 0x4e),iVar4);
          wVar1 = *(word *)(param_1 + 0x42);
          *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
          if ((wVar1 & 0x10) != 0) {
            *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
            _wakeup(param_1);
          }
        }
        if (iVar4 != 0) {
loc_403574A:
          *param_3 = iVar4;
          _dnlc_enter(param_1 + 0xc,param_2,iVar4 + 0xc,0);
          return 0;
        }
        iVar4 = (int)*(char *)(dword_40B57D4 + 100);
        goto loc_40357CC;
      }
      uVar9 = (uint)*(word *)(piVar10 + 1);
    }
    uVar7 = uVar9 + uVar7;
  }
  if (iVar4 == 2) {
    iVar4 = 1;
    uVar6 = 0;
    uVar8 = *(uint *)(param_1 + 0x4a);
    goto joined_r0x040355e2;
  }
  iVar4 = 2;
loc_40357A6:
  wVar1 = *(word *)(param_1 + 0x42);
  *(word *)(param_1 + 0x42) = wVar1 & 0xfffe;
  if ((wVar1 & 0x10) != 0) {
    *(word *)(param_1 + 0x42) = wVar1 & 0xffee;
    _wakeup(param_1);
  }
loc_40357CC:
  if (iVar11 != 0) {
    _brelse(iVar11);
  }
  return iVar4;
}

