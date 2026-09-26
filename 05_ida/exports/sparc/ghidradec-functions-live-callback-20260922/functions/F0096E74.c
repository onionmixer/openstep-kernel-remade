
undefined4 _swapl(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  *param_2 = param_1;
  return uVar1;
}

