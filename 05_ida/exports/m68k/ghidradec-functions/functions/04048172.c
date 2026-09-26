
undefined4 _host_processor_sets(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    puVar2 = (undefined4 *)_kalloc(4);
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 6;
    }
    else {
      _pset_reference(_default_pset);
      uVar1 = _convert_pset_name_to_port(_default_pset);
      *puVar2 = uVar1;
      *param_2 = (int)puVar2;
      *param_3 = 1;
      uVar1 = 0;
    }
  }
  return uVar1;
}
