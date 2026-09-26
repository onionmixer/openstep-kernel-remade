
int _pfind(uint param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(_pidhash + (param_1 & 0x3f) * 4);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (param_1 == (int)*(sword *)(iVar1 + 0x30)) break;
    iVar1 = *(int *)(iVar1 + 0x3e);
  }
  return iVar1;
}
