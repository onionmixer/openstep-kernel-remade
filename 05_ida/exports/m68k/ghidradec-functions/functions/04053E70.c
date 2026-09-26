
void _swapin_thread_continue(void)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  
  do {
    while (piVar2 = _swapin_queue, (int **)_swapin_queue == &_swapin_queue) {
loc_4053EB8:
      _assert_wait(&_swapin_queue,0);
      _thread_block_with_continuation(_swapin_thread_continue);
    }
    *(int ***)(*_swapin_queue + 4) = &_swapin_queue;
    piVar1 = (int *)*_swapin_queue;
    bVar3 = _swapin_queue == (int *)0x0;
    _swapin_queue = piVar1;
    if (bVar3) goto loc_4053EB8;
    _thread_doswapin(piVar2);
  } while( true );
}
