
void sub_40070AE(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    if (*(char *)(iVar1 + 0x13) == '\x06') break;
    iVar1 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
    iVar1 = *(int *)(iVar1 + 10);
  }
  for (iVar1 = *(int *)(param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 10)) {
    _psignal(iVar1,1);
    _psignal(iVar1,0x13);
    iVar1 = _get_posix_proc((int)*(sword *)(iVar1 + 0x30));
  }
  return;
}

