
void _setsid(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *_active_u;
  iVar2 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
  if (((int)*(sword *)(iVar1 + 0x30) != *(int *)(*(int *)(iVar2 + 0xe) + 0xc)) &&
     (iVar2 = _pgfind((int)*(sword *)(iVar1 + 0x30)), iVar2 == 0)) {
    _enterpgrp(iVar1,(int)*(sword *)(iVar1 + 0x30),1);
    *(int *)(dword_40B57D4 + 0x5c) = (int)*(sword *)(iVar1 + 0x30);
    return;
  }
  *(undefined *)(dword_40B57D4 + 100) = 1;
  return;
}

