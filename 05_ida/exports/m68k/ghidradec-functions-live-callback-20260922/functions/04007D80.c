
void _setpgid(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  iVar3 = *_active_u;
  if (piVar1[1] < 0) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
    return;
  }
  iVar2 = _get_posix_proc((int)*(sword *)(iVar3 + 0x30));
  iVar4 = *piVar1;
  iVar5 = iVar2;
  if ((iVar4 != 0) && (*(sword *)(iVar3 + 0x30) != iVar4)) {
    iVar3 = _pfind(iVar4);
    if ((iVar3 == 0) || (iVar4 = _inferior(iVar3), iVar4 == 0)) {
      *(undefined *)(dword_40B57D4 + 100) = 3;
      return;
    }
    iVar5 = _get_posix_proc((int)*(sword *)(iVar3 + 0x30));
    if (*(int *)(*(int *)(iVar5 + 0xe) + 8) != *(int *)(*(int *)(iVar2 + 0xe) + 8))
    goto loc_4007E78;
    if (*(int *)(iVar3 + 0x28) < 0) {
      *(undefined *)(dword_40B57D4 + 100) = 0xd;
      return;
    }
  }
  if (iVar3 == *(int *)(*(int *)(*(int *)(iVar5 + 0xe) + 8) + 4)) {
loc_4007E78:
    *(undefined *)(dword_40B57D4 + 100) = 1;
    return;
  }
  iVar4 = piVar1[1];
  if (iVar4 == 0) {
    piVar1[1] = (int)*(sword *)(iVar3 + 0x30);
  }
  else if ((*(sword *)(iVar3 + 0x30) != iVar4) &&
          ((iVar4 = _pgfind(iVar4), iVar4 == 0 ||
           (*(int *)(iVar4 + 8) != *(int *)(*(int *)(iVar2 + 0xe) + 8))))) goto loc_4007E78;
  _enterpgrp(iVar3,piVar1[1],0);
  return;
}

