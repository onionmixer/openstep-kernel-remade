
undefined4 _task_halt(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = _active_threads;
  puVar3 = (undefined4 *)0x0;
  for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)(param_1 + 0x18);
      puVar1 = (undefined4 *)puVar1[4]) {
    if (puVar2 != puVar1) {
      _thread_reference(puVar1);
      if (puVar3 != (undefined4 *)0x0) {
        _thread_deallocate(puVar3);
      }
      _thread_halt(puVar1,1);
      puVar3 = puVar1;
    }
  }
  if (puVar3 != (undefined4 *)0x0) {
    _thread_deallocate(puVar3);
  }
  return 0;
}

