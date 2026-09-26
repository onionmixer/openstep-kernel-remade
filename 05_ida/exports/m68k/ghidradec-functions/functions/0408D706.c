
undefined4 _zsacquire(int param_1,undefined4 param_2,undefined *param_3)

{
  undefined4 uVar1;
  
  if (((undefined *)(&off_40B243E)[param_1 * 2] == _zi_null) ||
     (param_3 == (undefined *)(&off_40B243E)[param_1 * 2])) {
    (&_zs_com)[param_1 * 2] = param_2;
    (&off_40B243E)[param_1 * 2] = param_3;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x10;
  }
  return uVar1;
}
