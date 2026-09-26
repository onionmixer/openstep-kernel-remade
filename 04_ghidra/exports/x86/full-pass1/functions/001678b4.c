/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001678b4 */

void _thread_halt_self(void)

{
  code *pcVar1;
  int iVar2;
  code *pcVar3;
  code **ppcVar4;
  code *pcStack_20;
  undefined4 *puStack_1c;
  undefined4 uStack_18;
  code *pcStack_14;
  code *pcStack_10;
  
  pcVar3 = _active_threads;
  if (((byte)_active_threads[0x17c] & 2) == 0) {
    pcStack_10 = (code *)0x167961;
    pcStack_10 = (code *)_splsched();
    pcVar1 = pcVar3 + 0x20;
    do {
      do {
      } while (*(int *)pcVar1 != 0);
      LOCK();
      iVar2 = *(int *)pcVar1;
      *(int *)pcVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    pcVar3[0x4c] = (code)((byte)pcVar3[0x4c] | 0x10);
    *(uint *)(pcVar3 + 0x17c) = *(uint *)(pcVar3 + 0x17c) & 0xfffffffe;
    LOCK();
    *(undefined4 *)(pcVar3 + 0x20) = 0;
    UNLOCK();
    pcStack_14 = (code *)0x167992;
    _splx();
    ppcVar4 = &pcStack_14;
    pcStack_14 = _thread_exception_return;
  }
  else {
    pcStack_10 = _active_threads;
    pcStack_14 = (code *)0x1678d2;
    _ipc_thread_terminate();
    pcStack_14 = pcVar3;
    uStack_18 = 0x1678d8;
    _thread_hold();
    uStack_18 = 0x1678dd;
    pcStack_10 = (code *)_splsched();
    do {
    } while (_reaper_lock != 0);
    LOCK();
    UNLOCK();
    *(undefined4 **)pcVar3 = &_reaper_queue;
    *(code **)(pcVar3 + 4) = DAT_001e979c;
    **(undefined4 **)(pcVar3 + 4) = pcVar3;
    DAT_001e979c = pcVar3;
    LOCK();
    _reaper_lock = 0;
    UNLOCK();
    pcVar1 = pcVar3 + 0x20;
    do {
      do {
      } while (*(int *)pcVar1 != 0);
      LOCK();
      iVar2 = *(int *)pcVar1;
      *(int *)pcVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    pcVar3[0x4c] = (code)((byte)pcVar3[0x4c] | 0x10);
    LOCK();
    *(undefined4 *)(pcVar3 + 0x20) = 0;
    UNLOCK();
    pcStack_14 = (code *)0x167947;
    _splx();
    pcStack_14 = (code *)0x0;
    uStack_18 = 0;
    puStack_1c = &_reaper_queue;
    pcStack_20 = (code *)0x167955;
    _thread_wakeup_prim();
    ppcVar4 = &pcStack_20;
    pcStack_20 = _walking_zombie;
  }
  *(undefined4 *)((int)ppcVar4 + -4) = 0x16799c;
  _thread_block_with_continuation();
  return;
}

