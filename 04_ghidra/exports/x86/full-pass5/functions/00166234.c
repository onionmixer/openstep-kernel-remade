/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00166234 */

undefined4 _task_halt(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  piVar3 = _active_threads;
  piVar4 = (int *)0x0;
  do {
    do {
    } while (*param_1 != 0);
    LOCK();
    iVar1 = *param_1;
    *param_1 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  for (piVar2 = (int *)param_1[7]; param_1 + 7 != piVar2; piVar2 = (int *)piVar2[4]) {
    if (piVar3 != piVar2) {
      _thread_reference(piVar2);
      LOCK();
      *param_1 = 0;
      UNLOCK();
      if (piVar4 != (int *)0x0) {
        _thread_deallocate(piVar4);
      }
      _thread_halt(piVar2,1);
      do {
        do {
        } while (*param_1 != 0);
        LOCK();
        iVar1 = *param_1;
        *param_1 = 1;
        UNLOCK();
        piVar4 = piVar2;
      } while (iVar1 == 1);
    }
  }
  LOCK();
  *param_1 = 0;
  UNLOCK();
  if (piVar4 != (int *)0x0) {
    _thread_deallocate(piVar4);
  }
  return 0;
}

