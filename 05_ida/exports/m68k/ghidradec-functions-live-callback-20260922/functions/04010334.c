
undefined4 _ptsread(byte param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar2 = *(int *)((int)&dword_40B318A + (sword)(word)param_1 * 0xe);
  iVar5 = *(int *)((int)&dword_40B318E + (sword)(word)param_1 * 0xe);
  uVar6 = 0;
  while ((*(byte *)(iVar5 + 3) & 0x20) != 0) {
    while ((iVar2 == *(int *)((int)_active_u + 0x15e) &&
           (iVar1 = *_active_u, *(sword *)(iVar2 + 0x42) != *(sword *)(iVar1 + 0x2e)))) {
      if ((*(byte *)(iVar1 + 0x16) & 0x40) == 0) {
        if ((((*(byte *)(iVar1 + 0x21) & 0x10) != 0) || ((*(byte *)(iVar1 + 0x1d) & 0x10) != 0)) ||
           ((*(byte *)(iVar1 + 0x2a) & 0x10) != 0)) {
          return 5;
        }
      }
      else {
        iVar3 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
        if ((*(byte *)(iVar1 + 0x21) & 0x10) != 0) {
          return 5;
        }
        if ((*(byte *)(iVar1 + 0x1d) & 0x10) != 0) {
          return 5;
        }
        if (*(int *)(*(int *)(iVar3 + 0xe) + 0x10) == 0) {
          return 5;
        }
      }
      _gsignal((int)*(sword *)(*_active_u + 0x2e),0x15);
      _sleep(&_lbolt,0x1c);
    }
    if (*(int *)(iVar2 + 0xc) != 0) {
      if (*(int *)(iVar2 + 0xc) < 2) goto loc_4010470;
      goto loc_401044C;
    }
    if ((*(byte *)(iVar2 + 0x40) & 0x20) != 0) {
      if ((*(byte *)(*_active_u + 0x16) & 0x40) != 0) {
        return 0xb;
      }
      return 0x23;
    }
    _sleep(iVar2 + 0xc,0x1c);
  }
  if (*(int *)(iVar2 + 0x24) != 0) {
    uVar6 = (**(code **)(DAT_40ae4b4 + *(char *)(iVar2 + 0x45) * 0x30))(iVar2,param_2);
  }
  goto loc_40104B6;
  while( true ) {
    uVar4 = _getc((int *)(iVar2 + 0xc),param_2);
    iVar5 = _ureadc(uVar4);
    if (iVar5 < 0) {
      uVar6 = 0xe;
      break;
    }
    if (*(int *)(iVar2 + 0xc) < 2) break;
loc_401044C:
    if (*(int *)(param_2 + 0x12) < 1) break;
  }
loc_4010470:
  if (*(int *)(iVar2 + 0xc) == 1) {
    _getc(iVar2 + 0xc);
  }
  if (*(int *)(iVar2 + 0xc) != 0) {
    return uVar6;
  }
loc_40104B6:
  _ptcwakeup(iVar2,2);
  return uVar6;
}

