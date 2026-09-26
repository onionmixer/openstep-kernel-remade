
int _killpg1(int param_1,int param_2,int param_3)

{
  int iVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if (((param_3 != 0) || (param_2 != 0)) ||
     (param_2 = (int)*(sword *)(*_active_u + 0x2e), param_2 != 0)) {
    iVar4 = 0;
    for (iVar1 = _allproc; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if ((((param_2 == *(sword *)(iVar1 + 0x2e)) || (param_3 != 0)) &&
          ((*(sword *)(iVar1 + 0x32) != 0 && ((*(byte *)(iVar1 + 0x2b) & 2) == 0)))) &&
         ((param_3 == 0 || (iVar1 != *_active_u)))) {
        sVar2 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 2);
        if ((sVar2 == 0) ||
           ((sVar2 == *(sword *)(iVar1 + 0x2c) ||
            ((param_1 == 0x13 && (iVar3 = _inferior(iVar1), iVar3 != 0)))))) {
          iVar4 = iVar4 + 1;
          if (param_1 != 0) {
            _psignal(iVar1,param_1);
          }
        }
        else if (param_3 == 0) {
          iVar5 = 1;
        }
      }
    }
    if (iVar5 != 0) {
      return iVar5;
    }
    if (iVar4 != 0) {
      return 0;
    }
  }
  return 3;
}
