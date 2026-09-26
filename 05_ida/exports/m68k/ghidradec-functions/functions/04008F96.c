
void _gsignal(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = _pgfind(param_1);
    if (iVar1 != 0) {
      _pgsignal(iVar1,param_2,0);
    }
  }
  return;
}
