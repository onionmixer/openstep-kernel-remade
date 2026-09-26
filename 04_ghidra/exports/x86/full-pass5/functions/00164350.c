/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00164350 */

int _rem_runq(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1[2];
  if (iVar3 != 0) {
    piVar1 = (int *)(iVar3 + 0x100);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    if (param_1[2] == iVar3) {
      *(int *)(*param_1 + 4) = param_1[1];
      *(int *)param_1[1] = *param_1;
      *(int *)(iVar3 + 0x108) = *(int *)(iVar3 + 0x108) + -1;
      param_1[2] = 0;
      LOCK();
      *(undefined4 *)(iVar3 + 0x100) = 0;
      UNLOCK();
    }
    else {
      LOCK();
      *(undefined4 *)(iVar3 + 0x100) = 0;
      UNLOCK();
      iVar3 = 0;
    }
  }
  return iVar3;
}

