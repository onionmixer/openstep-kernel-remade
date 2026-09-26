
undefined4 _convert_port_to_pset(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((((param_1 != 0) && (param_1 != -1)) && (*(int *)(param_1 + 4) < 0)) &&
     ((sword)*(int *)(param_1 + 4) == 6)) {
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    _pset_reference(uVar1);
  }
  return uVar1;
}

