
int _ptsopen(word param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  word *pwVar3;
  
  if ((param_1 & 0xff) < 0x20) {
    pwVar3 = (word *)_pty_alloc((int)(sword)param_1);
    iVar1 = *(int *)(pwVar3 + 3);
    *pwVar3 = param_1;
    if ((*(uint *)(iVar1 + 0x3e) & 4) == 0) {
      _ttychars(iVar1);
      *(undefined *)(iVar1 + 0x48) = 0xf;
      *(undefined *)(iVar1 + 0x47) = 0xf;
      *(undefined4 *)(iVar1 + 0x3a) = 0;
    }
    else if (((char)*(uint *)(iVar1 + 0x3e) < '\0') &&
            (*(sword *)(*(int *)(_active_u + 0x1a) + 2) != 0)) {
      return 0x10;
    }
    if (*(int *)(iVar1 + 0x24) != 0) {
      *(uint *)(iVar1 + 0x3e) = *(uint *)(iVar1 + 0x3e) | 0x10;
    }
    if ((param_2 & 4) == 0) {
      while ((*(uint *)(iVar1 + 0x3e) & 0x10) == 0) {
        *(uint *)(iVar1 + 0x3e) = *(uint *)(iVar1 + 0x3e) | 2;
        _sleep(iVar1,0x1c);
      }
    }
    else {
      *(word *)(iVar1 + 0x40) = *(word *)(iVar1 + 0x40) | 0x8000;
    }
    iVar2 = (*(code *)(&_linesw)[*(char *)(iVar1 + 0x45) * 0xc])((int)(sword)param_1,iVar1);
    if (iVar2 == 0) {
      *(uint *)(pwVar3 + 1) = *(uint *)(pwVar3 + 1) | 1;
    }
    _ptcwakeup(iVar1,3);
  }
  else {
    iVar2 = 6;
  }
  return iVar2;
}
