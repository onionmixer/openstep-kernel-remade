/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001966c8 */

undefined4 FUN_001966c8(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)(param_1 + 0x170);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar3 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  *(byte *)(param_1 + 0x124) = *(byte *)(param_1 + 0x124) | 1;
  if (*(int *)(param_1 + 0x168) == *(int *)(param_1 + 0x16c)) {
    piVar1 = (int *)(param_1 + 0x170);
    do {
      _thread_sleep(param_1 + 0x128,piVar1,1);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
    } while (*(int *)(param_1 + 0x168) == *(int *)(param_1 + 0x16c));
  }
  uVar2 = *(undefined4 *)(param_1 + 0x128 + *(int *)(param_1 + 0x16c) * 4);
  iVar3 = *(int *)(param_1 + 0x16c) + 1;
  if (iVar3 == 0x10) {
    iVar3 = 0;
  }
  *(int *)(param_1 + 0x16c) = iVar3;
  *(byte *)(param_1 + 0x124) = *(byte *)(param_1 + 0x124) & 0xfe;
  LOCK();
  *(undefined4 *)(param_1 + 0x170) = 0;
  UNLOCK();
  return uVar2;
}

