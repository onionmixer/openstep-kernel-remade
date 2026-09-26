/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00154064 */

bool _mach_msg_interrupt(int param_1)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  
  piVar2 = *(int **)(param_1 + 0xdc);
  do {
    do {
    } while (*piVar2 != 0);
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  bVar3 = *(int *)(param_1 + 0x98) != 0x10004001;
  if (bVar3) {
    LOCK();
    *piVar2 = 0;
    UNLOCK();
  }
  else {
    _ipc_thread_rmqueue(piVar2 + 2,param_1);
    LOCK();
    *piVar2 = 0;
    UNLOCK();
    _ipc_object_release(*(undefined4 *)(param_1 + 0xd8));
    _thread_set_syscall_return(param_1,0x10004005);
    *(code **)(param_1 + 0x34) = _thread_exception_return;
  }
  return !bVar3;
}

