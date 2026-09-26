/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001669b0 */

undefined4 _task_priority(int *param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 0;
  if ((param_1 == (int *)0x0) || (0x1f < param_2)) {
    local_8 = 4;
  }
  else {
    do {
      do {
      } while (*param_1 != 0);
      LOCK();
      iVar2 = *param_1;
      *param_1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    param_1[0x12] = param_2;
    if (param_3 != 0) {
      for (piVar1 = (int *)param_1[7]; param_1 + 7 != piVar1; piVar1 = (int *)piVar1[4]) {
        iVar2 = _thread_priority(piVar1,param_2,0);
        if (iVar2 != 0) {
          local_8 = 5;
        }
      }
    }
    LOCK();
    *param_1 = 0;
    UNLOCK();
  }
  return local_8;
}

