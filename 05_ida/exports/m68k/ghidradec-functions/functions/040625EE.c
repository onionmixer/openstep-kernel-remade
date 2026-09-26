
undefined4
_vm_machine_attribute
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    uVar1 = _vm_map_machine_attribute(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}
