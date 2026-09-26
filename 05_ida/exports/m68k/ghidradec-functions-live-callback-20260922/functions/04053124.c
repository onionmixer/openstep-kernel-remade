
void _thread_halt_self(void)

{
  code *pcVar1;
  code **ppcVar2;
  code *pcStack_1c;
  undefined4 *puStack_18;
  code *pcStack_14;
  code *pcStack_10;
  
  pcVar1 = _active_threads;
  if (((byte)_active_threads[0x177] & 2) == 0) {
    *(uint *)(_active_threads + 0x48) = *(uint *)(_active_threads + 0x48) | 0x10;
    *(uint *)(pcVar1 + 0x174) = *(uint *)(pcVar1 + 0x174) & 0xfffffffe;
    ppcVar2 = &pcStack_10;
    pcStack_10 = _thread_exception_return;
  }
  else {
    pcStack_10 = _active_threads;
    pcStack_14 = (code *)0x4053142;
    _ipc_thread_terminate();
    pcStack_14 = pcVar1;
    puStack_18 = (undefined4 *)0x405314a;
    _thread_hold();
    *(undefined4 **)pcVar1 = &_reaper_queue;
    *(code **)(pcVar1 + 4) = dword_40B67C4;
    **(undefined4 **)(pcVar1 + 4) = pcVar1;
    dword_40B67C4 = pcVar1;
    *(uint *)(pcVar1 + 0x48) = *(uint *)(pcVar1 + 0x48) | 0x10;
    pcStack_10 = (code *)0x0;
    pcStack_14 = (code *)0x0;
    puStack_18 = &_reaper_queue;
    pcStack_1c = (code *)0x405318a;
    _thread_wakeup_prim();
    ppcVar2 = &pcStack_1c;
    pcStack_1c = _walking_zombie;
  }
  *(undefined4 *)((int)ppcVar2 + -4) = 0x40531b8;
  _thread_block_with_continuation();
  return;
}

