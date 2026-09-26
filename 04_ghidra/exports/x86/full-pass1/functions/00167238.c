/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00167238 */

void _thread_reference(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 != 0) {
    uVar3 = _splsched();
    piVar1 = (int *)(param_1 + 0x20);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
    LOCK();
    *(undefined4 *)(param_1 + 0x20) = 0;
    UNLOCK();
    _splx(uVar3);
  }
  return;
}

