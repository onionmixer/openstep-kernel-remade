/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016610c */

undefined4 _task_dowait(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 local_10;
  
  piVar3 = _active_threads;
  local_10 = 0;
  piVar4 = (int *)0x0;
  do {
    do {
    } while (*param_1 != 0);
    LOCK();
    iVar1 = *param_1;
    *param_1 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  piVar2 = (int *)param_1[7];
  do {
    if (param_1 + 7 == piVar2) {
LAB_001661b0:
      LOCK();
      *param_1 = 0;
      UNLOCK();
      if (piVar4 != (int *)0x0) {
        _thread_deallocate(piVar4);
      }
      return local_10;
    }
    if ((param_1[2] == 0) && (param_2 == 0)) {
      local_10 = 5;
      goto LAB_001661b0;
    }
    if (piVar3 != piVar2) {
      _thread_reference(piVar2);
      LOCK();
      *param_1 = 0;
      UNLOCK();
      if (piVar4 != (int *)0x0) {
        _thread_deallocate(piVar4);
      }
      _thread_dowait(piVar2,1);
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
    piVar2 = (int *)piVar2[4];
  } while( true );
}

