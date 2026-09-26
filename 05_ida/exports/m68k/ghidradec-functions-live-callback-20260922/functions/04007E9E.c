
void _getpriority(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar3 = 0x15;
  iVar2 = *piVar1;
  if (iVar2 == 1) {
    if (piVar1[1] == 0) {
      piVar1[1] = (int)*(sword *)(*_active_u + 0x2e);
    }
    if (_allproc != 0) {
      iVar2 = _allproc;
      do {
        if ((piVar1[1] == (int)*(sword *)(iVar2 + 0x2e)) && (*(char *)(iVar2 + 0x15) < iVar3)) {
          iVar3 = (int)*(char *)(iVar2 + 0x15);
        }
        iVar2 = *(int *)(iVar2 + 8);
      } while (iVar2 != 0);
    }
loc_4007F8C:
    if (iVar3 == 0x15) {
      *(undefined *)(dword_40B57D4 + 100) = 3;
    }
    else {
      *(int *)(dword_40B57D4 + 0x5c) = iVar3;
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
          iVar3 = (int)*(char *)(iVar2 + 0x15);
        }
        goto loc_4007F8C;
      }
    }
    else if (iVar2 == 2) {
      if (piVar1[1] == 0) {
        piVar1[1] = (int)*(sword *)(*(int *)((int)_active_u + 0x1a) + 2);
      }
      if (_allproc != 0) {
        iVar2 = _allproc;
        do {
          if ((piVar1[1] == (int)*(sword *)(iVar2 + 0x2c)) && (*(char *)(iVar2 + 0x15) < iVar3)) {
            iVar3 = (int)*(char *)(iVar2 + 0x15);
          }
          iVar2 = *(int *)(iVar2 + 8);
        } while (iVar2 != 0);
      }
      goto loc_4007F8C;
    }
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
  }
  return;
}

