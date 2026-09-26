/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00164a0c */

void _idle_thread(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar3 = _active_threads;
  _stack_privilege(_active_threads);
  uVar4 = _splsched();
  *(undefined4 *)(iVar3 + 0x50) = 0;
  *(undefined4 *)(iVar3 + 0x58) = 0;
  piVar1 = (int *)(iVar3 + 0x20);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  *(byte *)(iVar3 + 0x4c) = *(byte *)(iVar3 + 0x4c) | 0x80;
  LOCK();
  *(undefined4 *)(iVar3 + 0x20) = 0;
  UNLOCK();
  *(int *)(_processor_ptr + 0x11c) = iVar3;
  _splx(uVar4);
  iVar2 = _processor_ptr;
  iVar3 = _active_threads;
  uVar4 = _splsched();
  _need_ast = _need_ast & 0xfffffffb;
  do {
    uVar5 = _thread_select(iVar2);
    iVar6 = _thread_invoke(iVar3,_idle_thread_continue,uVar5);
  } while (iVar6 == 0);
  _splx(uVar4);
  _idle_thread_continue();
  return;
}

