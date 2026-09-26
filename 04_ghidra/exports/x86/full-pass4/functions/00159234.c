/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00159234 */

void _thread_will_wait_with_timeout(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = (param_2 * _hz + 999U) / 1000;
  uVar4 = _splsched();
  piVar1 = (int *)(param_1 + 0x20);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  *(byte *)(param_1 + 0x4c) = *(byte *)(param_1 + 0x4c) | 1;
  if ((uVar3 != 0) || (param_2 == 0)) {
    _set_timeout(param_1 + 0x118,uVar3);
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x20) = 0;
  UNLOCK();
  _splx(uVar4);
  return;
}

