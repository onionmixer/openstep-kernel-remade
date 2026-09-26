
void _thread_deallocate_interrupt(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    iVar1 = param_1[8];
    param_1[8] = iVar1 + -1;
    if (iVar1 == 1 || iVar1 + -1 < 0) {
      param_1[8] = 1;
      *param_1 = &_reaper_queue;
      param_1[1] = dword_40B67C4;
      *(undefined4 **)param_1[1] = param_1;
      dword_40B67C4 = param_1;
      _thread_wakeup_prim(&_reaper_queue,0,0);
    }
  }
  return;
}

