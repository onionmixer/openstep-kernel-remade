
undefined * _sprintf(undefined *param_1,undefined4 param_2)

{
  undefined *puStack_8;
  
  puStack_8 = param_1;
  _prf(param_2,&stack0x0000000c,8,&puStack_8);
  *puStack_8 = 0;
  return puStack_8 + (1 - (int)param_1);
}
