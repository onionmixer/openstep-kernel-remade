
int _ttread(int *param_1,int param_2)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iVar4 = _ttynty(param_1);
  iVar9 = 0;
loc_400EC24:
  bVar2 = false;
loc_400EC26:
  while( true ) {
    uVar1 = *(uint *)((int)param_1 + 0x3a);
    if ((uVar1 & 0x20000000) != 0) {
      _ttypend(param_1);
    }
    while ((uVar6 = *(uint *)((int)param_1 + 0x3e), (uVar6 & 0x10) == 0 &&
           (-1 < *(sword *)(iVar4 + 0x12)))) {
      if (-1 < (sword)uVar6) {
        return 5;
      }
      if ((uVar6 & 0x2000) != 0) goto loc_400EE90;
      _sleep(param_1,0x1c);
    }
    iVar7 = *_active_u;
    if ((*(byte *)(iVar7 + 0x16) & 0x40) != 0) break;
    if ((param_1 != *(int **)((int)_active_u + 0x15e)) ||
       (*(sword *)(iVar7 + 0x2e) == *(sword *)((int)param_1 + 0x42))) goto loc_400ED2E;
    if (((*(byte *)(iVar7 + 0x21) & 0x10) != 0) ||
       (((*(byte *)(iVar7 + 0x1d) & 0x10) != 0 || ((*(byte *)(iVar7 + 0x2a) & 0x10) != 0)))) {
      return 5;
    }
    iVar10 = (int)*(sword *)(iVar7 + 0x2e);
loc_400ED10:
    _gsignal(iVar10,0x15);
    _sleep(&_lbolt,0x1c);
  }
  iVar5 = _get_posix_proc((int)*(sword *)(iVar7 + 0x30));
  if (param_1 == *(int **)((int)_active_u + 0x15e)) {
    iVar10 = *(int *)(*(int *)(iVar5 + 0xe) + 0xc);
    if (*(sword *)((int)param_1 + 0x42) != iVar10) {
      if ((*(byte *)(iVar7 + 0x21) & 0x10) != 0) {
        return 5;
      }
      if ((*(byte *)(iVar7 + 0x1d) & 0x10) != 0) {
        return 5;
      }
      if (*(int *)(*(int *)(iVar5 + 0xe) + 0x10) == 0) {
        return 5;
      }
      if ((*(byte *)(iVar7 + 0x2a) & 0x10) != 0) {
        return 5;
      }
      goto loc_400ED10;
    }
  }
loc_400ED2E:
  if ((uVar1 & 0x22) == 0) {
    piVar11 = param_1 + 3;
    if (0 < param_1[3]) goto loc_400EEC0;
  }
  else {
    uVar6 = (uint)*(byte *)(iVar4 + 0x15);
    piVar11 = param_1;
    if (*(byte *)(iVar4 + 0x16) == 0) {
      if ((int)uVar6 <= *param_1) goto loc_400EEC0;
    }
    else {
      iVar7 = (uint)*(byte *)(iVar4 + 0x16) * 100000;
      if (uVar6 == 0) {
        if (0 < *param_1) goto loc_400EEC0;
        if (bVar2) {
          _getthetime(&iStack_1c);
          iVar7 = iVar7 - ((iStack_18 - iStack_8) + (iStack_1c - iStack_c) * 1000000);
        }
        else {
          bVar2 = true;
          _getthetime(&iStack_c);
        }
      }
      else {
        iVar5 = *param_1;
        if (iVar5 < 1) goto loc_400EE5C;
        if ((int)uVar6 <= iVar5) goto loc_400EEC0;
        if (bVar2) {
          if (iStack_20 < iVar5) {
            _getthetime(&iStack_c);
          }
          else {
            _getthetime(&iStack_14);
            iVar7 = iVar7 - ((iStack_10 - iStack_8) + (iStack_14 - iStack_c) * 1000000);
          }
        }
        else {
          bVar2 = true;
          _getthetime(&iStack_c);
        }
        iStack_20 = *param_1;
      }
      if (iVar7 < 1) goto loc_400EEC0;
      iVar7 = _hz * iVar7;
      _untimeout(_wakeup,param_1);
      _timeout(_wakeup,param_1,(iVar7 + 999999) / 1000000);
    }
  }
loc_400EE5C:
  bVar3 = false;
  if (((*(byte *)((int)param_1 + 0x41) & 0x10) != 0) || (*(sword *)(iVar4 + 0x12) < 0)) {
    bVar3 = true;
  }
  if ((!bVar3) && ((*(byte *)((int)param_1 + 0x41) & 4) != 0)) {
    return 0;
  }
  if ((*(byte *)(param_1 + 0x10) & 0x20) != 0) {
loc_400EE90:
    if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
      return 0xb;
    }
    return 0x23;
  }
  _sleep(param_1,0x1c);
  goto loc_400EC26;
loc_400EEC0:
  bVar2 = true;
  do {
    uVar6 = _getc(piVar11);
    if ((int)uVar6 < 0) goto loc_400EF76;
    cVar8 = (char)uVar6;
    if (cVar8 != -1) {
      if (((cVar8 == *(char *)((int)param_1 + 0x55)) && ((uVar1 & 0x20) == 0)) &&
         ((*(byte *)(iVar4 + 0x13) & 8) != 0)) break;
      if (((cVar8 != -1) && (cVar8 == *(char *)((int)param_1 + 0x52))) && ((uVar1 & 0x22) == 0))
      goto loc_400EF76;
    }
    iVar9 = _ureadc(uVar6,param_2);
    if (((iVar9 != 0) || (*(int *)(param_2 + 0x12) == 0)) ||
       (((uVar1 & 0x22) == 0 &&
        ((uVar6 == 10 ||
         (((*(byte *)((int)param_1 + 0x52) == uVar6 || (*(byte *)((int)param_1 + 0x53) == uVar6)) &&
          (uVar6 != 0xff)))))))) goto loc_400EF76;
    bVar2 = false;
  } while( true );
  _gsignal((int)*(sword *)((int)param_1 + 0x42),0x12);
  if (!bVar2) {
loc_400EF76:
    if (*param_1 < 0xcc) {
      *(byte *)((int)param_1 + 0x3f) = *(byte *)((int)param_1 + 0x3f) & 0x7f;
      if ((((*(uint *)((int)param_1 + 0x3e) & 0x400) != 0) &&
          ((*(uint *)((int)param_1 + 0x3e) & 0x1000000) == 0)) &&
         ((*(char *)(param_1 + 0x14) != -1 &&
          (iVar4 = _putc((int)*(char *)(param_1 + 0x14),param_1 + 6), iVar4 == 0)))) {
        *(word *)(param_1 + 0x10) = *(word *)(param_1 + 0x10) & 0xfbff;
        _ttstart(param_1);
      }
    }
    return iVar9;
  }
  _sleep(param_1,0x1c);
  goto loc_400EC24;
}

