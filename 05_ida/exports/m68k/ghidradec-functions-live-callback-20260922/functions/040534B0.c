
undefined4 _thread_set_state(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_1 == _active_threads)) {
    uVar1 = 4;
  }
  else {
    _thread_hold(param_1);
    _thread_dowait(param_1,1);
    uVar1 = _thread_setstatus(param_1,param_2,param_3,param_4);
    _thread_release(param_1);
  }
  return uVar1;
}

