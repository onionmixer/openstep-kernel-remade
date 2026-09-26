/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00156be0 */

void _exception_try_task(exception_type_t param_1,exception_data_t param_2,
                        mach_msg_type_number_t param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  mach_port_t task;
  mach_port_t thread;
  
  iVar4 = _active_threads;
  iVar3 = *(int *)(_active_threads + 0xc);
  piVar1 = (int *)(iVar3 + 100);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  piVar1 = *(int **)(iVar3 + 0x70);
  if ((piVar1 == (int *)0x0) || (piVar1 == (int *)0xffffffff)) {
    LOCK();
    *(undefined4 *)(iVar3 + 100) = 0;
    UNLOCK();
    _exception_no_server();
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
    *(undefined4 *)(iVar3 + 100) = 0;
    UNLOCK();
    if (piVar1[2] < 0) {
      piVar1[1] = piVar1[1] + 1;
      piVar1[7] = piVar1[7] + 1;
      LOCK();
      *piVar1 = 0;
      UNLOCK();
      *(undefined4 *)(iVar4 + 200) = 0;
      task = _retrieve_task_self_fast(iVar3);
      thread = _retrieve_thread_self_fast(iVar4);
      _exception_raise((mach_port_t)piVar1,thread,task,param_1,param_2,param_3);
    }
    else {
      LOCK();
      *piVar1 = 0;
      UNLOCK();
      _exception_no_server();
    }
  }
  return;
}

