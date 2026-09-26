
void _reaper_thread_continue(void)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  
  do {
    while (piVar2 = _reaper_queue, (int **)_reaper_queue == &_reaper_queue) {
loc_4053806:
      _assert_wait(&_reaper_queue,0);
      _thread_block_with_continuation(_reaper_thread_continue);
    }
    *(int ***)(*_reaper_queue + 4) = &_reaper_queue;
    piVar1 = (int *)*_reaper_queue;
    bVar3 = _reaper_queue == (int *)0x0;
    _reaper_queue = piVar1;
    if (bVar3) goto loc_4053806;
    _thread_dowait(piVar2,1);
    _thread_deallocate(piVar2);
  } while( true );
}
