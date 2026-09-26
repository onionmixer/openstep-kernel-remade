/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00167b2c */

void _thread_release(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
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
  iVar2 = *(int *)(param_1 + 0x40);
  *(int *)(param_1 + 0x40) = iVar2 + -1;
  if (iVar2 == 1) {
    uVar3 = *(uint *)(param_1 + 0x4c);
    uVar5 = uVar3 & 0xffffffed;
    *(uint *)(param_1 + 0x4c) = uVar5;
    if ((uVar3 & 5) == 0) {
      *(uint *)(param_1 + 0x4c) = uVar5 | 4;
      _thread_setrun(param_1,1);
    }
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x20) = 0;
  UNLOCK();
  _splx(uVar4);
  return;
}

