
void _getpgrp(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  if (*piVar1 == 0) {
    *piVar1 = (int)*(sword *)(*_active_u + 0x30);
  }
  iVar2 = _pfind(*piVar1);
  if (iVar2 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 3;
  }
  else {
    *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(iVar2 + 0x2e);
  }
  return;
}

