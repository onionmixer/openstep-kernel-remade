
undefined4 _vlog(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = _prf(param_2,param_3,5,0);
  if (iVar1 != 0) {
    _logwakeup();
  }
  return 0;
}
