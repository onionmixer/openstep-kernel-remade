/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001661cc */

undefined4 _task_release(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  
  do {
    do {
    } while (*param_1 != 0);
    LOCK();
    iVar1 = *param_1;
    *param_1 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  if (param_1[2] == 0) {
    LOCK();
    *param_1 = 0;
    UNLOCK();
    uVar4 = 5;
  }
  else {
    param_1[6] = param_1[6] + -1;
    piVar3 = (int *)param_1[7];
    while (param_1 + 7 != piVar3) {
      piVar2 = (int *)piVar3[4];
      _thread_release(piVar3);
      piVar3 = piVar2;
    }
    LOCK();
    *param_1 = 0;
    UNLOCK();
    uVar4 = 0;
  }
  return uVar4;
}

