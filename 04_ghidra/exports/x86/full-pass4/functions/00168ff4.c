/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168ff4 */

void _swapin_thread_continue(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  undefined4 uVar5;
  bool bVar6;
  
  do {
    uVar5 = _splsched();
    do {
    } while (_swapper_lock_data != 0);
    LOCK();
    UNLOCK();
    while (piVar4 = _swapin_queue, _swapper_lock_data = 1, (int **)_swapin_queue != &_swapin_queue)
    {
      *(int ***)(*_swapin_queue + 4) = &_swapin_queue;
      piVar2 = (int *)*_swapin_queue;
      bVar6 = _swapin_queue == (int *)0x0;
      _swapin_queue = piVar2;
      if (bVar6) break;
      LOCK();
      _swapper_lock_data = 0;
      UNLOCK();
      _splx(uVar5);
      _stack_alloc(piVar4,_thread_continue);
      uVar5 = _splsched();
      piVar2 = piVar4 + 8;
      do {
        do {
        } while (*piVar2 != 0);
        LOCK();
        iVar1 = *piVar2;
        *piVar2 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      uVar3 = piVar4[0x13];
      piVar4[0x13] = uVar3 & 0xfffffcff;
      if ((uVar3 & 4) != 0) {
        _thread_setrun(piVar4,1);
      }
      LOCK();
      piVar4[8] = 0;
      UNLOCK();
      _splx(uVar5);
      uVar5 = _splsched();
      do {
      } while (_swapper_lock_data != 0);
      LOCK();
      UNLOCK();
    }
    _assert_wait(&_swapin_queue,0);
    LOCK();
    _swapper_lock_data = 0;
    UNLOCK();
    _splx(uVar5);
    _thread_block_with_continuation(_swapin_thread_continue);
  } while( true );
}

