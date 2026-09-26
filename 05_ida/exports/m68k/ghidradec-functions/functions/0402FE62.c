
undefined4 _xdr_u_long(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 1) {
    uVar2 = (**(code **)param_1[1])(param_1,param_2);
  }
  else if (iVar1 == 0) {
    uVar2 = (**(code **)(param_1[1] + 4))(param_1,param_2);
  }
  else if (iVar1 == 2) {
    uVar2 = 1;
  }
  else {
    _printf(aXdrULongFailed);
    uVar2 = 0;
  }
  return uVar2;
}
