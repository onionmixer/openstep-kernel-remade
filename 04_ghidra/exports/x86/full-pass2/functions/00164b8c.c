/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00164b8c */

void _sched_thread(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar2 = _active_threads;
  _sched_thread_id = _active_threads;
  if (*(int *)(_active_threads + 0x3c) != 0) {
    _printf(s_assert_wait__already_asserted_ev_001df520,*(int *)(_active_threads + 0x3c));
                    /* WARNING: Subroutine does not return */
    _panic(s_assert_wait_001df54a);
  }
  uVar3 = _splsched();
  piVar1 = (int *)(iVar2 + 0x20);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar6 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar6 == 1);
  *(byte *)(iVar2 + 0x4c) = *(byte *)(iVar2 + 0x4c) | 9;
  LOCK();
  *(undefined4 *)(iVar2 + 0x20) = 0;
  UNLOCK();
  _splx(uVar3);
  uVar3 = _processor_ptr;
  iVar2 = _active_threads;
  uVar4 = _splsched();
  _need_ast = _need_ast & 0xfffffffb;
  do {
    uVar5 = _thread_select(uVar3);
    iVar6 = _thread_invoke(iVar2,_sched_thread_continue,uVar5);
  } while (iVar6 == 0);
  _splx(uVar4);
  _sched_thread_continue();
  return;
}

