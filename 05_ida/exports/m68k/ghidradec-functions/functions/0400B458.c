
undefined4 _log(undefined4 param_1,undefined4 param_2)

{
  sub_400B4F2(param_1);
  _prf(param_2,&stack0x0000000c,4,0);
  if (_log_open == 0) {
    _prf(param_2,&stack0x0000000c,1,0);
  }
  _logwakeup();
  return 0;
}
