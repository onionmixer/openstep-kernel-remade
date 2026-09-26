
undefined4 _tprintf(undefined *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 6;
  sub_400B4F2(6);
  if (param_1 == (undefined *)0x0) {
    param_1 = _cons;
  }
  iVar1 = _ttycheckoutq(param_1,0);
  if (iVar1 == 0) {
    uVar2 = 4;
  }
  _prf(param_2,&stack0x0000000c,uVar2,param_1);
  _logwakeup();
  return 0;
}
