
undefined4 _host_processor_set_priv(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    *param_3 = 0;
    uVar1 = 4;
  }
  else {
    *param_3 = param_2;
    _pset_reference(param_2);
    uVar1 = 0;
  }
  return uVar1;
}

