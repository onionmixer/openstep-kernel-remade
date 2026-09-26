
int _argstrcpy(char *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    iVar1 = _isargsep((int)*param_1);
    if (iVar1 != 0) break;
    iVar2 = iVar2 + 1;
    *param_2 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return iVar2;
}
