
undefined4 _task_release(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 4) == 0) {
    uVar3 = 5;
  }
  else {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
    puVar2 = *(undefined4 **)(param_1 + 0x18);
    while (puVar2 != (undefined4 *)(param_1 + 0x18)) {
      puVar1 = (undefined4 *)puVar2[4];
      _thread_release(puVar2);
      puVar2 = puVar1;
    }
    uVar3 = 0;
  }
  return uVar3;
}
