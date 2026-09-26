
void _setpriority(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar3 = 0;
  iVar2 = *piVar1;
  if (iVar2 == 1) {
    iVar2 = _allproc;
    if (piVar1[1] == 0) {
      piVar1[1] = (int)*(sword *)(*_active_u + 0x2e);
      iVar2 = _allproc;
    }
    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
      if ((int)*(sword *)(iVar2 + 0x2e) == piVar1[1]) {
        _donice(iVar2,piVar1[2]);
        iVar3 = iVar3 + 1;
      }
    }
loc_40080B0:
    if (iVar3 == 0) {
      *(undefined *)(dword_40B57D4 + 100) = 3;
    }
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 == 0) {
        if (piVar1[1] == 0) {
          iVar2 = *_active_u;
        }
        else {
          iVar2 = _pfind(piVar1[1]);
        }
        if (iVar2 != 0) {
          _donice(iVar2,piVar1[2]);
          iVar3 = 1;
        }
        goto loc_40080B0;
      }
    }
    else if (iVar2 == 2) {
      iVar2 = _allproc;
      if (piVar1[1] == 0) {
        piVar1[1] = (int)*(sword *)(*(int *)((int)_active_u + 0x1a) + 2);
        iVar2 = _allproc;
      }
      for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
        if ((int)*(sword *)(iVar2 + 0x2c) == piVar1[1]) {
          _donice(iVar2,piVar1[2]);
          iVar3 = iVar3 + 1;
        }
      }
      goto loc_40080B0;
    }
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}
