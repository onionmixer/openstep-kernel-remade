/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015bc30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _clock_interrupt(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = _active_threads;
  if (param_2 == 0) {
    iVar3 = *(int *)(_active_threads + 0xf0) + param_1;
    *(int *)(_active_threads + 0xf0) = iVar3;
    if (-1 < iVar3) goto LAB_0015bc7f;
    iVar3 = iVar1 + 0xf0;
  }
  else {
    iVar3 = *(int *)(_active_threads + 0xe0) + param_1;
    *(int *)(_active_threads + 0xe0) = iVar3;
    if (-1 < iVar3) goto LAB_0015bc7f;
    iVar3 = iVar1 + 0xe0;
  }
  _timer_normalize(iVar3);
LAB_0015bc7f:
  if (param_2 == 0) {
    iVar3 = 2;
    if (*(int *)(_processor_ptr + 0x114) != 2) {
      iVar3 = 1;
    }
  }
  else {
    iVar3 = 0;
  }
  (&DAT_001e8e10)[iVar3] = (&DAT_001e8e10)[iVar3] + 1;
  if (-1 < *(char *)(iVar1 + 0x4c)) {
    _thread_quantum_update(0,iVar1,1,iVar3);
  }
  piVar2 = _mtime;
  if (_master_cpu == 0) {
    if (_timedelta != 0) {
      if (_timedelta < 0) {
        uVar4 = _tickdelta * -1000;
        _DAT_001f63e4 =
             (_DAT_001f63e4 - (_tickdelta * 1000 >> 0x1f)) -
             (uint)(__time_of_boot < (uint)(_tickdelta * 1000));
        iVar3 = -_tickdelta;
        iVar1 = _tickdelta;
      }
      else {
        iVar1 = -_tickdelta;
        uVar4 = _tickdelta * 1000;
        _DAT_001f63e4 = _DAT_001f63e4 + ((int)uVar4 >> 0x1f) + (uint)CARRY4(__time_of_boot,uVar4);
        iVar3 = _tickdelta;
      }
      _timedelta = _timedelta + iVar1;
      __time_of_boot = __time_of_boot + uVar4;
      param_1 = param_1 + iVar3;
    }
    DAT_001dee3c = DAT_001dee3c + param_1;
    if (999999 < DAT_001dee3c) {
      DAT_001dee3c = DAT_001dee3c + -1000000;
      _time = _time + 1;
    }
    if (_mtime != (int *)0x0) {
      _mtime[2] = _time;
      piVar2[1] = DAT_001dee3c;
      *piVar2 = _time;
    }
  }
  return;
}

