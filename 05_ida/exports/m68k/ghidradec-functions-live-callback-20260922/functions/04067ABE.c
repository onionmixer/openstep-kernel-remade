
undefined4 _evselect(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    if (_evg[1] != *_evg) {
      return 1;
    }
    if (dword_40B4F5E == 0) {
      dword_40B4F5E = _active_threads;
      _thread_reference(_active_threads);
    }
    else if (dword_40B4F5E != _active_threads) {
      _printf(aDoubleSelect);
      return 0xffffffff;
    }
  }
  return 0;
}

