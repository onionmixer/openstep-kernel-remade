
undefined4 _thread_switch(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iStack_8;
  
  iVar1 = _active_threads;
  if (param_2 == 1) {
    _thread_depress_priority(_active_threads,param_3);
  }
  else if (param_2 < 2) {
    if (param_2 != 0) {
      return 4;
    }
  }
  else {
    if (param_2 != 2) {
      return 4;
    }
    _thread_will_wait_with_timeout(_active_threads,param_3);
  }
  if (param_1 != 0) {
    iVar3 = _ipc_object_translate(*(undefined4 *)(*(int *)(iVar1 + 0xc) + 0x7c),param_1,0,&iStack_8)
    ;
    if (iVar3 == 0) {
      if ((((*(int *)(iStack_8 + 4) < 0) && ((sword)*(int *)(iStack_8 + 4) == 1)) &&
          (iVar3 = *(int *)(iStack_8 + 0x10), *(int *)(iVar3 + 0x178) == *(int *)(iVar1 + 0x178)))
         && (iVar4 = _rem_runq(iVar3), iVar2 = _processor_ptr, iVar4 != 0)) {
        if (*(int *)(iVar3 + 0x5c) == 2) {
          *(undefined4 *)(_processor_ptr + 0x11c) = *(undefined4 *)(iVar3 + 0x58);
          *(undefined4 *)(iVar2 + 0x120) = 1;
        }
        _thread_run(_thread_switch_continue,iVar3);
        goto loc_4051AD2;
      }
    }
    else if (iVar3 == 0xf) {
      return 4;
    }
  }
  _thread_block_with_continuation(_thread_switch_continue);
loc_4051AD2:
  if (-1 < *(int *)(iVar1 + 0x60)) {
    _thread_depress_abort(iVar1);
  }
  return 0;
}

