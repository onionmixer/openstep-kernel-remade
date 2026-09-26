/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001677c4 */

void _thread_halt_self_with_continuation(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  code **ppcVar4;
  code *pcStack_20;
  undefined4 *puStack_1c;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  undefined4 *puStack_10;
  
  puVar3 = _active_threads;
  if ((*(byte *)(_active_threads + 0x5f) & 2) == 0) {
    puStack_10 = (undefined4 *)0x167871;
    puStack_10 = (undefined4 *)_splsched();
    piVar1 = puVar3 + 8;
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    *(byte *)(puVar3 + 0x13) = *(byte *)(puVar3 + 0x13) | 0x10;
    puVar3[0x5f] = puVar3[0x5f] & 0xfffffffe;
    LOCK();
    puVar3[8] = 0;
    UNLOCK();
    puStack_14 = (undefined4 *)0x1678a2;
    _splx();
    ppcVar4 = (code **)&puStack_14;
    puStack_14 = param_1;
  }
  else {
    puStack_10 = _active_threads;
    puStack_14 = (undefined4 *)0x1677e2;
    _ipc_thread_terminate();
    puStack_14 = puVar3;
    uStack_18 = 0x1677e8;
    _thread_hold();
    uStack_18 = 0x1677ed;
    puStack_10 = (undefined4 *)_splsched();
    do {
    } while (_reaper_lock != 0);
    LOCK();
    UNLOCK();
    *puVar3 = &_reaper_queue;
    puVar3[1] = DAT_001e979c;
    *(undefined4 **)puVar3[1] = puVar3;
    DAT_001e979c = puVar3;
    LOCK();
    _reaper_lock = 0;
    UNLOCK();
    piVar1 = puVar3 + 8;
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    *(byte *)(puVar3 + 0x13) = *(byte *)(puVar3 + 0x13) | 0x10;
    LOCK();
    puVar3[8] = 0;
    UNLOCK();
    puStack_14 = (undefined4 *)0x167857;
    _splx();
    puStack_14 = (undefined4 *)0x0;
    uStack_18 = 0;
    puStack_1c = &_reaper_queue;
    pcStack_20 = (code *)0x167865;
    _thread_wakeup_prim();
    ppcVar4 = &pcStack_20;
    pcStack_20 = _walking_zombie;
  }
  *(undefined4 *)((int)ppcVar4 + -4) = 0x1678ab;
  _thread_block_with_continuation();
  return;
}

