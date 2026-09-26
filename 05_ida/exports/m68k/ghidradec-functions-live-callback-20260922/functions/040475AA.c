
void _exception_with_continuation
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = _active_threads;
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aException);
  }
  *(undefined4 *)(_active_threads + 0x34) = param_4;
  piVar1 = *(int **)(iVar2 + 0xac);
  if (((piVar1 == (int *)0x0) || (piVar1 == (int *)0xffffffff)) || (-1 < piVar1[1])) {
    _exception_try_task(param_1,param_2,param_3);
  }
  else {
    *piVar1 = *piVar1 + 1;
    piVar1[6] = piVar1[6] + 1;
    *(int *)(iVar2 + 0xc0) = param_1;
    *(undefined4 *)(iVar2 + 0xc4) = param_2;
    *(undefined4 *)(iVar2 + 200) = param_3;
    uVar3 = _retrieve_task_self_fast(*(undefined4 *)(iVar2 + 0xc),param_1,param_2,param_3);
    uVar3 = _retrieve_thread_self_fast(iVar2,uVar3);
    _exception_raise(piVar1,uVar3);
  }
  return;
}

