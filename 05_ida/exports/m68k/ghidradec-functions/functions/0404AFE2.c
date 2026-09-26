
void _clock_interrupt(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  
  iVar1 = _active_threads;
  if (param_2 == 0) {
    iVar3 = param_1 + *(int *)(_active_threads + 0xe8);
    *(int *)(_active_threads + 0xe8) = iVar3;
    if (-1 < iVar3) goto loc_404B028;
    iVar3 = iVar1 + 0xe8;
  }
  else {
    iVar3 = param_1 + *(int *)(_active_threads + 0xd8);
    *(int *)(_active_threads + 0xd8) = iVar3;
    if (-1 < iVar3) goto loc_404B028;
    iVar3 = iVar1 + 0xd8;
  }
  _timer_normalize(iVar3);
loc_404B028:
  if (param_2 == 0) {
    iVar3 = 2;
    if (*(int *)(_processor_ptr + 0x110) != 2) {
      iVar3 = 1;
    }
  }
  else {
    iVar3 = 0;
  }
  *(int *)(DAT_40b5dd8 + iVar3 * 4) = *(int *)(DAT_40b5dd8 + iVar3 * 4) + 1;
  if (-1 < *(char *)(iVar1 + 0x4b)) {
    _thread_quantum_update(0,iVar1,1,iVar3);
  }
  pcVar2 = _mtime;
  if (_master_cpu == 0) {
    if (_timedelta != 0) {
      if (_timedelta < 0) {
        iVar3 = -_tickdelta;
        iVar1 = _tickdelta;
      }
      else {
        iVar1 = -_tickdelta;
        iVar3 = _tickdelta;
      }
      _timedelta = iVar1 + _timedelta;
      param_1 = param_1 + iVar3;
    }
    dword_40AF7F0 = param_1 + dword_40AF7F0;
    if (999999 < dword_40AF7F0) {
      dword_40AF7F0 = dword_40AF7F0 + -1000000;
      _time = (code)((int)_time + 1);
    }
    if (_mtime != (code *)0x0) {
      *(code *)((int)_mtime + 8) = _time;
      *(int *)((int)pcVar2 + 4) = dword_40AF7F0;
      *pcVar2 = _time;
    }
  }
  return;
}
