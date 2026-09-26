
void _leavepgrp(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = _get_posix_proc((int)*(sword *)(param_1 + 0x30));
  piVar3 = (int *)(*(int *)(iVar1 + 0xe) + 4);
  while( true ) {
    if (*piVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aLeavepgrpCanTF);
    }
    if (param_1 == *piVar3) break;
    iVar2 = _get_posix_proc((int)*(sword *)(*piVar3 + 0x30));
    piVar3 = (int *)(iVar2 + 10);
  }
  *piVar3 = *(int *)(iVar1 + 10);
  if (*(int *)(*(int *)(iVar1 + 0xe) + 4) == 0) {
    _pgdelete(*(int *)(iVar1 + 0xe));
  }
  *(undefined4 *)(iVar1 + 0xe) = 0;
  *(undefined2 *)(param_1 + 0x2e) = 0;
  return;
}

