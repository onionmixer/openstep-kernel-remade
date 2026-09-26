
undefined4 _task_dowait(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  puVar2 = _active_threads;
  uVar4 = 0;
  puVar3 = (undefined4 *)0x0;
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  do {
    if (puVar1 == (undefined4 *)(param_1 + 0x18)) {
loc_405226C:
      if (puVar3 != (undefined4 *)0x0) {
        _thread_deallocate(puVar3);
      }
      return uVar4;
    }
    if ((*(int *)(param_1 + 4) == 0) && (param_2 == 0)) {
      uVar4 = 5;
      goto loc_405226C;
    }
    if (puVar2 != puVar1) {
      _thread_reference(puVar1);
      if (puVar3 != (undefined4 *)0x0) {
        _thread_deallocate(puVar3);
      }
      _thread_dowait(puVar1,1);
      puVar3 = puVar1;
    }
    puVar1 = (undefined4 *)puVar1[4];
  } while( true );
}
