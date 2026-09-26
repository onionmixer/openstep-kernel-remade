/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00156aac */

void _exception_from_kernel(int param_1,exception_data_t param_2,mach_msg_type_number_t param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  mach_port_t task;
  mach_port_t thread;
  
  iVar7 = _active_threads;
  uVar3 = *(undefined4 *)(_active_threads + 0x38);
  uVar4 = *(undefined4 *)(_active_threads + 200);
  uVar5 = *(undefined4 *)(_active_threads + 0xcc);
  uVar6 = *(undefined4 *)(_active_threads + 0xd0);
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_exception_001deb58);
  }
  *(undefined4 *)(_active_threads + 0x38) = 0;
  piVar1 = (int *)(iVar7 + 0xa8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  piVar1 = *(int **)(iVar7 + 0xb4);
  if ((piVar1 == (int *)0x0) || (piVar1 == (int *)0xffffffff)) {
    LOCK();
    *(undefined4 *)(iVar7 + 0xa8) = 0;
    UNLOCK();
  }
  else {
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    LOCK();
    *(undefined4 *)(iVar7 + 0xa8) = 0;
    UNLOCK();
    if (piVar1[2] < 0) {
      piVar1[1] = piVar1[1] + 1;
      piVar1[7] = piVar1[7] + 1;
      LOCK();
      *piVar1 = 0;
      UNLOCK();
      *(int *)(iVar7 + 200) = param_1;
      *(exception_data_t *)(iVar7 + 0xcc) = param_2;
      *(mach_msg_type_number_t *)(iVar7 + 0xd0) = param_3;
      task = _retrieve_task_self_fast(*(undefined4 *)(iVar7 + 0xc));
      thread = _retrieve_thread_self_fast(iVar7);
      _exception_raise((mach_port_t)piVar1,thread,task,param_1,param_2,param_3);
      goto LAB_00156bb5;
    }
    LOCK();
    *piVar1 = 0;
    UNLOCK();
  }
  _exception_try_task(param_1,param_2,param_3);
LAB_00156bb5:
  *(undefined4 *)(iVar7 + 0x38) = uVar3;
  *(undefined4 *)(iVar7 + 200) = uVar4;
  *(undefined4 *)(iVar7 + 0xcc) = uVar5;
  *(undefined4 *)(iVar7 + 0xd0) = uVar6;
  return;
}

