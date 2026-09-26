
void _setpgrp(void)

{
  int *piVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  if (*piVar1 == 0) {
    *piVar1 = (int)*(sword *)(*_active_u + 0x30);
  }
  iVar3 = _pfind(*piVar1);
  if (iVar3 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 3;
  }
  else {
    sVar2 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 2);
    if (((sVar2 != *(sword *)(iVar3 + 0x2c)) && (sVar2 != 0)) &&
       (iVar4 = _inferior(iVar3), iVar4 == 0)) {
      *(undefined *)(dword_40B57D4 + 100) = 1;
      return;
    }
    _enterpgrp(iVar3,piVar1[1],0);
  }
  return;
}

