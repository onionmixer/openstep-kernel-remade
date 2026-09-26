/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168f90 */

void _thread_doswapin(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  _stack_alloc(param_1,_thread_continue);
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
  uVar3 = *(uint *)(param_1 + 0x4c);
  *(uint *)(param_1 + 0x4c) = uVar3 & 0xfffffcff;
  if ((uVar3 & 4) != 0) {
    _thread_setrun(param_1,1);
  }
  LOCK();
  *(undefined4 *)(param_1 + 0x20) = 0;
  UNLOCK();
  _splx(uVar4);
  return;
}

