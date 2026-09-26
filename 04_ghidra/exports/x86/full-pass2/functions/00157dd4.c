/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00157dd4 */

undefined4 _ipc_pset_enable(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)(param_1 + 0x158);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if (*(int *)(param_1 + 0x154) != 0) {
    _ipc_kobject_set(*(undefined4 *)(param_1 + 0x15c),param_1,6);
    _ipc_kobject_set(*(undefined4 *)(param_1 + 0x160),param_1,7);
    piVar1 = (int *)(param_1 + 0x148);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    *(int *)(param_1 + 0x144) = *(int *)(param_1 + 0x144) + 2;
    LOCK();
    *(undefined4 *)(param_1 + 0x148) = 0;
    UNLOCK();
  }
  LOCK();
  uVar3 = *(undefined4 *)(param_1 + 0x158);
  *(undefined4 *)(param_1 + 0x158) = 0;
  UNLOCK();
  return uVar3;
}

