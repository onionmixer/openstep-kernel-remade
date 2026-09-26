
/* WARNING: Removing unreachable block (ram,0xf006987c) */
/* WARNING: Removing unreachable block (ram,0xf00697b8) */
/* WARNING: Removing unreachable block (ram,0xf0069804) */

undefined8 _clock_interrupt(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = _active_threads;
  if (param_2 == 0) {
    iVar3 = *(int *)(_active_threads + 0xf0) + param_1;
    *(int *)(_active_threads + 0xf0) = iVar3;
    if (-1 < iVar3) goto LAB_f006980c;
    iVar3 = iVar1 + 0xf0;
  }
  else {
    iVar3 = *(int *)(_active_threads + 0xe0) + param_1;
    *(int *)(_active_threads + 0xe0) = iVar3;
    if (-1 < iVar3) goto LAB_f006980c;
    iVar3 = iVar1 + 0xe0;
  }
  _timer_normalize(iVar3);
LAB_f006980c:
  if (param_2 == 0) {
    iVar3 = 2;
    if (*(int *)(_processor_ptr + 0x114) != 2) {
      iVar3 = 1;
    }
  }
  else {
    iVar3 = 0;
  }
  (&DAT_f0134770)[iVar3] = (&DAT_f0134770)[iVar3] + 1;
  if ((*(uint *)(iVar1 + 0x4c) & 0x80) == 0) {
    _thread_quantum_update(0,iVar1,1);
  }
  piVar2 = _mtime;
  if (_master_cpu == 0) {
    if (_timedelta != 0) {
      if (_timedelta < 0) {
        iVar1 = _tickdelta;
        iVar3 = -_tickdelta;
      }
      else {
        iVar1 = -_tickdelta;
        iVar3 = _tickdelta;
      }
      param_1 = param_1 + iVar3;
      _timedelta = _timedelta + iVar1;
    }
    param_1 = DAT_f010fbec + param_1;
    DAT_f010fbec = param_1;
    if (999999 < param_1) {
      DAT_f010fbec = param_1 + -1000000;
      _time = _time + 1;
    }
    if (_mtime != (int *)0x0) {
      _mtime[2] = _time;
      piVar2[1] = DAT_f010fbec;
      *piVar2 = _time;
    }
  }
  return CONCAT44(param_2,param_1);
}

