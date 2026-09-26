
void _sysacct(void)

{
  int *piVar1;
  int iVar2;
  undefined uVar3;
  int iStack_8;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar2 = _suser();
  if (iVar2 != 0) {
    if (_savacctp != 0) {
      _acctp = _savacctp;
      _savacctp = 0;
    }
    iVar2 = _acctp;
    if (*piVar1 == 0) {
      iStack_8 = _acctp;
      if (_acctp != 0) {
        _acctp = 0;
        _vn_rele(iVar2);
      }
    }
    else {
      uVar3 = _lookupname(*piVar1,0,1,0,&iStack_8);
      *(undefined *)(dword_40B57D4 + 100) = uVar3;
      iVar2 = _acctp;
      if (*(char *)(dword_40B57D4 + 100) == '\0') {
        if (*(int *)(iStack_8 + 0x28) == 1) {
          if ((*(byte *)(*(int *)(iStack_8 + 0x24) + 0xf) & 1) == 0) {
            if (_acctp == 0) {
              _acctp = iStack_8;
            }
            else {
              _acctp = iStack_8;
              _vn_rele(iVar2);
            }
            if (_acctcred != 0) {
              _crfree(_acctcred);
            }
            _acctcred = _crdup(*(undefined4 *)(_active_u + 0x1a));
            return;
          }
          *(undefined *)(dword_40B57D4 + 100) = 0x1e;
        }
        else {
          *(undefined *)(dword_40B57D4 + 100) = 0xd;
        }
        _vn_rele(iStack_8);
      }
    }
  }
  return;
}

