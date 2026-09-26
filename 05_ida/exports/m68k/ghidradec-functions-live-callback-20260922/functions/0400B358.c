
undefined4 _printf(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _prf(param_1,&stack0x00000008,5,0);
  if (iVar1 != 0) {
    _logwakeup();
  }
  return 0;
}

