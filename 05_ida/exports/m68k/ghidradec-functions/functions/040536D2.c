
undefined4 _thread_abort(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == 0) || (param_1 == _active_threads)) {
    uVar1 = 4;
  }
  else {
    iVar2 = _thread_halt(param_1,0);
    if (iVar2 == 0) {
      _mach_msg_abort_rpc(param_1);
      _thread_release(param_1);
      if (*(int *)(param_1 + 0x60) != -1) {
        _thread_depress_abort(param_1);
      }
      uVar1 = 0;
    }
    else {
      uVar1 = 0xe;
    }
  }
  return uVar1;
}
