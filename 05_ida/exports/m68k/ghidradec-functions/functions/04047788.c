
void _exception_try_task(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = _active_threads;
  iVar1 = *(int *)(_active_threads + 0xc);
  piVar2 = *(int **)(iVar1 + 100);
  if (((piVar2 == (int *)0x0) || (piVar2 == (int *)0xffffffff)) || (-1 < piVar2[1])) {
    _exception_no_server();
  }
  else {
    *piVar2 = *piVar2 + 1;
    piVar2[6] = piVar2[6] + 1;
    *(undefined4 *)(iVar3 + 0xc0) = 0;
    uVar4 = _retrieve_task_self_fast(iVar1,param_1,param_2,param_3);
    uVar4 = _retrieve_thread_self_fast(iVar3,uVar4);
    _exception_raise(piVar2,uVar4);
  }
  return;
}
