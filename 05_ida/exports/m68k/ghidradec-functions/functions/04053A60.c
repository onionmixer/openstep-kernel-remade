
undefined4 _thread_wire(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_2 != _active_threads)) {
    uVar1 = 4;
  }
  else {
    if (param_3 == 0) {
      *(undefined4 *)(param_2 + 0x74) = 0;
      *(undefined4 *)(param_2 + 0x2c) = 0;
    }
    else {
      *(undefined4 *)(param_2 + 0x74) = 1;
      _stack_privilege(param_2);
    }
    uVar1 = 0;
  }
  return uVar1;
}
