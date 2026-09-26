
undefined4 _processor_set_default(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    *param_2 = _default_pset;
    _pset_reference(_default_pset);
    uVar1 = 0;
  }
  return uVar1;
}

