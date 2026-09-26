
void _pgsignal(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_1 != 0) {
    for (iVar1 = *(int *)(param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 10)) {
      if ((param_3 == 0) || ((*(byte *)(iVar1 + 0x28) & 0x40) != 0)) {
        _psignal(iVar1,param_2);
      }
      iVar1 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
    }
  }
  return;
}
