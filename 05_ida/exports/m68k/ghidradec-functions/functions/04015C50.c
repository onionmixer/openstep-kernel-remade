
int _getsock(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _getf(param_1);
  if (iVar1 != 0) {
    if (*(sword *)(iVar1 + 0xc) == 2) {
      return iVar1;
    }
    *(undefined *)(dword_40B57D4 + 100) = 0x26;
  }
  return 0;
}

