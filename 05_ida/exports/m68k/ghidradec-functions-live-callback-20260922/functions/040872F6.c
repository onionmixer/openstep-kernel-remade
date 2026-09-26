
void _snd_stream_queue_reset(int param_1)

{
  _snd_stream_abort(param_1,0);
  while ((*(int *)(param_1 + 0x1c) != 0 && (*(int *)(_active_threads + 0x40) != 2))) {
    _assert_wait(param_1,1);
    _thread_block();
  }
  return;
}

