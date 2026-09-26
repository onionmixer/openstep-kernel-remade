
int _thread_select(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  bool bVar5;
  
  *(undefined4 *)(param_1 + 0x120) = 1;
  piVar2 = (int *)_active_threads;
  if (0 < *(int *)(param_1 + 0x104)) {
    iVar1 = _choose_thread(param_1);
    *(undefined4 *)(param_1 + 0x11c) = _min_quantum;
    return iVar1;
  }
  if (dword_40B674C == 0) {
    if ((*(int *)(_active_threads + 0x48) == 4) &&
       ((*(int *)(_active_threads + 0x17c) == 0 || (param_1 == *(int *)(_active_threads + 0x17c)))))
    {
      if (*(int *)(_active_threads + 0x6c) != _sched_tick) {
        _update_priority(_active_threads);
      }
      goto loc_4050BB0;
    }
  }
  else {
    piVar4 = (int *)(_default_pset + dword_40B6748 * 8);
    piVar2 = (int *)*piVar4;
    if (piVar2 != piVar4) {
      if (piVar4 == piVar2) {
        piVar2 = (int *)0x0;
      }
      else {
        *(int **)(*piVar2 + 4) = piVar4;
        *piVar4 = *piVar2;
      }
      *(undefined4 *)((int)piVar2 + 8) = 0;
      iVar1 = dword_40B674C + -1;
      iVar3 = dword_40B674C + -1;
      bVar5 = dword_40B674C != 1;
      dword_40B674C = iVar1;
      if (((bVar5 && -1 < iVar3) && ((DAT_40b67a3 & 2) != 0)) && (piVar4 == (int *)*piVar4)) {
        do {
          dword_40B6748 = dword_40B6748 + -1;
          piVar4 = piVar4 + -2;
        } while (piVar4 == (int *)*piVar4);
      }
      goto loc_4050BB0;
    }
    dword_40B6748 = dword_40B6748 + -1;
  }
  piVar2 = (int *)_choose_pset_thread(param_1,_default_pset);
loc_4050BB0:
  if (*(int *)((int)piVar2 + 0x5c) == 2) {
    *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)((int)piVar2 + 0x58);
  }
  else {
    *(undefined4 *)(param_1 + 0x11c) = dword_40B67A4;
  }
  return (int)piVar2;
}

