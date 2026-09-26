
void _exception_from_kernel(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar6 = _active_threads;
  uVar1 = *(undefined4 *)(_active_threads + 0x34);
  uVar2 = *(undefined4 *)(_active_threads + 0xc0);
  uVar3 = *(undefined4 *)(_active_threads + 0xc4);
  uVar4 = *(undefined4 *)(_active_threads + 200);
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aException);
  }
  *(undefined4 *)(_active_threads + 0x34) = 0;
  piVar5 = *(int **)(iVar6 + 0xac);
  if (((piVar5 == (int *)0x0) || (piVar5 == (int *)0xffffffff)) || (-1 < piVar5[1])) {
    _exception_try_task(param_1,param_2,param_3);
  }
  else {
    *piVar5 = *piVar5 + 1;
    piVar5[6] = piVar5[6] + 1;
    *(int *)(iVar6 + 0xc0) = param_1;
    *(undefined4 *)(iVar6 + 0xc4) = param_2;
    *(undefined4 *)(iVar6 + 200) = param_3;
    uVar7 = _retrieve_task_self_fast(*(undefined4 *)(iVar6 + 0xc),param_1,param_2,param_3);
    uVar7 = _retrieve_thread_self_fast(iVar6,uVar7);
    _exception_raise(piVar5,uVar7);
  }
  *(undefined4 *)(iVar6 + 0x34) = uVar1;
  *(undefined4 *)(iVar6 + 0xc0) = uVar2;
  *(undefined4 *)(iVar6 + 0xc4) = uVar3;
  *(undefined4 *)(iVar6 + 200) = uVar4;
  return;
}

