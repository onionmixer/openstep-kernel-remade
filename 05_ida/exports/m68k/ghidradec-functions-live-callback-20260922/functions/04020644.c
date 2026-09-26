
int _ifptoia(int param_1)

{
  int iVar1;
  
  iVar1 = _in_ifaddr;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (param_1 == *(int *)(iVar1 + 0x20)) break;
    iVar1 = *(int *)(iVar1 + 0x40);
  }
  return iVar1;
}

