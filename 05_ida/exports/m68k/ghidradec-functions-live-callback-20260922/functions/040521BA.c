
undefined4 _task_hold(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = _active_threads;
  if (*(int *)(param_1 + 4) == 0) {
    uVar3 = 5;
  }
  else {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)(param_1 + 0x18);
        puVar1 = (undefined4 *)puVar1[4]) {
      if (puVar2 != puVar1) {
        _thread_hold(puVar1);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}

