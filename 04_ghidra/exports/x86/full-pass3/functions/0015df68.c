/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015df68 */

void _cpu_down(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = _splsched();
  iVar3 = (&_processor_ptr)[param_1];
  piVar1 = (int *)(iVar3 + 0x13c);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  (&DAT_001e8e0c)[param_1 * 8] = 0;
  DAT_001f634c = DAT_001f634c + -1;
  *(undefined4 *)(iVar3 + 0x130) = 0;
  *(undefined4 *)(iVar3 + 0x114) = 0;
  LOCK();
  *(undefined4 *)(iVar3 + 0x13c) = 0;
  UNLOCK();
  _splx(uVar4);
  return;
}

