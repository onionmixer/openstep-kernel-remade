/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001568d8 */

void _exception_with_continuation
               (int param_1,exception_data_t param_2,mach_msg_type_number_t param_3,
               undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  mach_port_t task;
  mach_port_t thread;
  
  iVar3 = _active_threads;
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_exception_001deb58);
  }
  *(undefined4 *)(_active_threads + 0x38) = param_4;
  piVar1 = (int *)(iVar3 + 0xa8);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  piVar1 = *(int **)(iVar3 + 0xb4);
  if ((piVar1 == (int *)0x0) || (piVar1 == (int *)0xffffffff)) {
    LOCK();
    *(undefined4 *)(iVar3 + 0xa8) = 0;
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
    *(undefined4 *)(iVar3 + 0xa8) = 0;
    UNLOCK();
    if (piVar1[2] < 0) {
      piVar1[1] = piVar1[1] + 1;
      piVar1[7] = piVar1[7] + 1;
      LOCK();
      *piVar1 = 0;
      UNLOCK();
      *(int *)(iVar3 + 200) = param_1;
      *(exception_data_t *)(iVar3 + 0xcc) = param_2;
      *(mach_msg_type_number_t *)(iVar3 + 0xd0) = param_3;
      task = _retrieve_task_self_fast(*(undefined4 *)(iVar3 + 0xc));
      thread = _retrieve_thread_self_fast(iVar3);
      _exception_raise((mach_port_t)piVar1,thread,task,param_1,param_2,param_3);
      return;
    }
    LOCK();
    *piVar1 = 0;
    UNLOCK();
  }
  _exception_try_task(param_1,param_2,param_3);
  return;
}

