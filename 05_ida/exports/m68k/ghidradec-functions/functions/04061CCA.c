
int _fuibyte(undefined4 param_1)

{
  int iVar1;
  char cStack_5;
  
  iVar1 = _copyinmsg(param_1,&cStack_5,1);
  if (iVar1 == 0) {
    iVar1 = (int)cStack_5;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}
