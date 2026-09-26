
void _thread_halt_self_with_continuation(undefined4 *param_1)

{
  undefined4 *puVar1;
  code **ppcVar2;
  code *pcStack_1c;
  undefined4 *puStack_18;
  undefined4 *puStack_14;
  undefined4 *puStack_10;
  
  puVar1 = _active_threads;
  if ((*(byte *)((int)_active_threads + 0x177) & 2) == 0) {
    _active_threads[0x12] = _active_threads[0x12] | 0x10;
    puVar1[0x5d] = puVar1[0x5d] & 0xfffffffe;
    ppcVar2 = (code **)&puStack_10;
    puStack_10 = param_1;
  }
  else {
    puStack_10 = _active_threads;
    puStack_14 = (undefined4 *)0x40530a4;
    _ipc_thread_terminate();
    puStack_14 = puVar1;
    puStack_18 = (undefined4 *)0x40530ac;
    _thread_hold();
    *puVar1 = &_reaper_queue;
    puVar1[1] = dword_40B67C4;
    *(undefined4 **)puVar1[1] = puVar1;
    dword_40B67C4 = puVar1;
    puVar1[0x12] = puVar1[0x12] | 0x10;
    puStack_10 = (undefined4 *)0x0;
    puStack_14 = (undefined4 *)0x0;
    puStack_18 = &_reaper_queue;
    pcStack_1c = (code *)0x40530ec;
    _thread_wakeup_prim();
    ppcVar2 = &pcStack_1c;
    pcStack_1c = _walking_zombie;
  }
  *(undefined4 *)((int)ppcVar2 + -4) = 0x4053118;
  _thread_block_with_continuation();
  return;
}
