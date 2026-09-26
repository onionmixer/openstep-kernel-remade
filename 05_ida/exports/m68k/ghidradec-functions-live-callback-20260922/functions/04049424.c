
undefined4 _thread_handoff(int param_1,undefined4 param_2,int param_3)

{
  byte *pbVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x2c) == _active_stacks) || (*(int *)(param_3 + 0x48) != 0x101)) {
    _c_thread_handoff_misses = _c_thread_handoff_misses + 1;
    uVar2 = 0;
  }
  else {
    if (*(int *)(param_3 + 0x13c) != 0) {
      _reset_timeout(param_3 + 0x110);
    }
    *(undefined4 *)(param_3 + 0x48) = 4;
    _need_ast = *(uint *)(param_3 + 0x174) | _need_ast & 0xfffffffc;
    if (_need_ast == 0) {
      pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
      *pbVar1 = *pbVar1 & 0xef;
    }
    else {
      pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
      *pbVar1 = *pbVar1 | 0x10;
    }
    _switch_unix_context(param_3);
    _stack_handoff(param_1,param_3);
    *(undefined4 *)(param_1 + 0x30) = param_2;
    if (*(int *)(param_1 + 0x48) == 4) {
      *(undefined4 *)(param_1 + 0x48) = 0x101;
    }
    else {
      if (*(int *)(param_1 + 0x48) != 6) {
                    /* WARNING: Subroutine does not return */
        _panic(aThreadHandoff);
      }
      *(undefined4 *)(param_1 + 0x48) = 0x103;
      if (*(int *)(param_1 + 0x44) != 0) {
        *(undefined4 *)(param_1 + 0x44) = 0;
        _thread_wakeup_prim(param_1 + 0x44,0,0);
      }
    }
    _c_thread_handoff_hits = _c_thread_handoff_hits + 1;
    uVar2 = 1;
  }
  return uVar2;
}

