/* GHIDRADEC_FUNCTION index=1550 start=0x4050e08 */

void _thread_continue(int param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(_active_threads + 0x30);
  if (param_1 != 0) {
    _thread_dispatch(param_1);
  }
  (*pcVar1)();
  return;
}
/* GHIDRADEC_FUNCTION index=1551 start=0x4050e38 */

byte _thread_block_with_continuation(undefined4 param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  char cVar6;
  
  uVar3 = _processor_ptr;
  iVar2 = _active_threads;
  cVar6 = '\0';
  _need_ast = _need_ast & 0xfffffffb;
  if (_need_ast == 0) {
    pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
    *pbVar1 = *pbVar1 & 0xef;
  }
  do {
    uVar4 = _thread_select(uVar3);
    iVar5 = _thread_invoke(iVar2,param_1,uVar4);
  } while (iVar5 == 0);
  return cVar6 << 4 | (iVar5 < 0) << 3;
}
/* GHIDRADEC_FUNCTION index=1552 start=0x4050ea6 */

byte _thread_run(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  
  uVar2 = _processor_ptr;
  uVar1 = _active_threads;
  cVar4 = '\0';
  while( true ) {
    iVar3 = _thread_invoke(uVar1,param_1,param_2);
    if (iVar3 != 0) break;
    param_2 = _thread_select(uVar2);
  }
  return cVar4 << 4 | (iVar3 < 0) << 3 | (iVar3 == 0) << 2;
}
/* GHIDRADEC_FUNCTION index=1553 start=0x4050efc */

void _thread_dispatch(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x30) != 0) {
    *(word *)(param_1 + 0x4a) = *(word *)(param_1 + 0x4a) | 0x100;
    _stack_free(param_1);
  }
  uVar1 = *(uint *)(param_1 + 0x48) & 0xfffffcff;
  if (uVar1 == 0xc) {
loc_4050F86:
    _thread_setrun(param_1,0);
  }
  else {
    if ((int)uVar1 < 0xd) {
      if (uVar1 != 5) {
        if (5 < (int)uVar1) {
          if ((int)uVar1 < 8) {
loc_4050F66:
            *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffffb;
            if (*(int *)(param_1 + 0x44) == 0) {
              return;
            }
            *(undefined4 *)(param_1 + 0x44) = 0;
            _thread_wakeup_prim(param_1 + 0x44,0,0);
            return;
          }
          goto loc_4050F9A;
        }
        uVar2 = 4;
loc_4050F50:
        if (uVar2 != uVar1) {
loc_4050F9A:
                    /* WARNING: Subroutine does not return */
          _panic(aThreadDispatch);
        }
        goto loc_4050F86;
      }
    }
    else if (uVar1 != 0xf) {
      if (0xf < (int)uVar1) {
        if (uVar1 == 0x16) goto loc_4050F66;
        if (uVar1 == 0x84) {
          return;
        }
        goto loc_4050F9A;
      }
      if (uVar1 != 0xd) {
        uVar2 = 0xe;
        goto loc_4050F50;
      }
    }
    *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffffb;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1554 start=0x4050fae */

void _compute_priority(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x5c) == 2) {
    iVar1 = *(int *)(param_1 + 0x4c);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x4c) - (*(uint *)(param_1 + 0x68) >> 0x19);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    if (-1 < *(int *)(param_1 + 0x60)) {
      *(int *)(param_1 + 0x60) = iVar1;
      return;
    }
  }
  _set_pri(param_1,iVar1,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=1555 start=0x4051000 */

void _compute_my_priority(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x4c) - (*(uint *)(param_1 + 0x68) >> 0x19);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  *(int *)(param_1 + 0x54) = iVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=1556 start=0x4051024 */

void _recompute_priorities(void)

{
  int iVar1;
  
  _sched_tick = _sched_tick + 1;
  _set_timeout(_recompute_priorities_timer,_hz);
  iVar1 = _sched_usec_elapsed();
  _sched_usec = iVar1 * 3 + _sched_usec * 5;
  if (_sched_usec < 0) {
    _sched_usec = _sched_usec + 7;
  }
  _sched_usec = _sched_usec >> 3;
  if (_sched_thread_id != 0) {
    _clear_wait(_sched_thread_id,0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1557 start=0x4051080 */

void _update_priority(int param_1)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = _sched_tick - *(int *)(param_1 + 0x6c);
  *(int *)(param_1 + 0x6c) = _sched_tick;
  if (*(int *)(param_1 + 0x104) == *(int *)(param_1 + 0xf0)) {
    iVar3 = *(int *)(param_1 + 0xe8) - *(int *)(param_1 + 0x100);
    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0xe8);
  }
  else {
    iVar3 = _timer_delta(param_1 + 0xe8,param_1 + 0x100);
  }
  if (*(int *)(param_1 + 0xfc) == *(int *)(param_1 + 0xe0)) {
    iVar4 = *(int *)(param_1 + 0xd8) - *(int *)(param_1 + 0xf8);
    *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xd8);
  }
  else {
    iVar4 = _timer_delta(param_1 + 0xd8,param_1 + 0xf8);
  }
  *(int *)(param_1 + 0x108) = iVar4 + iVar3 + *(int *)(param_1 + 0x108);
  *(int *)(param_1 + 0x10c) =
       *(int *)(*(int *)(param_1 + 0x178) + 0x168) * (iVar4 + iVar3) + *(int *)(param_1 + 0x10c);
  if (uVar2 < 0x1f) {
    *(int *)(param_1 + 100) = *(int *)(param_1 + 0x108) + *(int *)(param_1 + 100);
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x10c) + *(int *)(param_1 + 0x68);
    iVar3 = uVar2 * 8;
    puVar1 = (uint *)(_wait_shift + iVar3);
    uVar2 = *(uint *)(_wait_shift + iVar3 + 4);
    if ((int)uVar2 < 1) {
      *(uint *)(param_1 + 100) =
           (*(uint *)(param_1 + 100) >> (*puVar1 & 0x3f)) -
           (*(uint *)(param_1 + 100) >> (-uVar2 & 0x3f));
      *(uint *)(param_1 + 0x68) =
           (*(uint *)(param_1 + 0x68) >> (*puVar1 & 0x3f)) -
           (*(uint *)(param_1 + 0x68) >> (-*(int *)(_wait_shift + iVar3 + 4) & 0x3fU));
    }
    else {
      *(uint *)(param_1 + 100) =
           (*(uint *)(param_1 + 100) >> (uVar2 & 0x3f)) +
           (*(uint *)(param_1 + 100) >> (*puVar1 & 0x3f));
      *(uint *)(param_1 + 0x68) =
           (*(uint *)(param_1 + 0x68) >> (*(uint *)(_wait_shift + iVar3 + 4) & 0x3f)) +
           (*(uint *)(param_1 + 0x68) >> (*puVar1 & 0x3f));
    }
  }
  else {
    *(undefined4 *)(param_1 + 100) = 0;
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  if ((*(int *)(param_1 + 0x5c) != 2) && (*(int *)(param_1 + 0x60) < 0)) {
    iVar3 = *(int *)(param_1 + 0x4c) - (*(uint *)(param_1 + 0x68) >> 0x19);
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    *(int *)(param_1 + 0x54) = iVar3;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1558 start=0x40511ca */

void _run_queue_enqueue(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_2[0x15];
  if (0x1f < uVar2) {
    _printf(aRunQueueEnqueu,uVar2);
    uVar2 = 0x1f;
  }
  iVar1 = param_1 + uVar2 * 8;
  *param_2 = iVar1;
  param_2[1] = *(int *)(iVar1 + 4);
  *(int **)param_2[1] = param_2;
  *(int **)(iVar1 + 4) = param_2;
  if ((*(uint *)(param_1 + 0x100) < uVar2) || (*(int *)(param_1 + 0x104) == 0)) {
    *(uint *)(param_1 + 0x100) = uVar2;
  }
  *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 1;
  param_2[2] = param_1;
  return;
}
/* GHIDRADEC_FUNCTION index=1559 start=0x405122e */

void _thread_setrun(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  
  if (*(int *)(param_1 + 0x6c) != _sched_tick) {
    _update_priority(param_1);
  }
  puVar6 = _master_processor;
  puVar4 = unk_40B6750;
  if (dword_40B6758 < 1) {
    if (*(int *)(param_1 + 0x17c) == 0) {
      puVar6 = _default_pset;
    }
    else {
      _need_ast = _need_ast | 4;
      if (_need_ast != 0) {
        pbVar3 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
        *pbVar3 = *pbVar3 | 0x10;
      }
    }
    _run_queue_enqueue(puVar6,param_1);
    if ((param_2 != 0) && (*(int *)(_active_threads + 0x54) < *(int *)(param_1 + 0x54))) {
      *(undefined4 *)(_processor_ptr + 0x120) = 0;
      _need_ast = _need_ast | 4;
      if (_need_ast != 0) {
        pbVar3 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
        *pbVar3 = *pbVar3 | 0x10;
      }
    }
  }
  else {
    puVar1 = (undefined4 *)unk_40B6750[0x42];
    puVar2 = (undefined4 *)unk_40B6750[0x43];
    puVar5 = puVar2;
    if ((undefined4 **)puVar1 != &unk_40B6750) {
      puVar1[0x43] = puVar2;
      puVar5 = dword_40B6754;
    }
    dword_40B6754 = puVar5;
    if ((undefined4 **)puVar2 != &unk_40B6750) {
      puVar2[0x42] = puVar1;
      puVar1 = unk_40B6750;
    }
    unk_40B6750 = puVar1;
    dword_40B6758 = dword_40B6758 + -1;
    puVar4[0x45] = param_1;
    puVar4[0x44] = 3;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1560 start=0x4051328 */

void _set_pri(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = _rem_runq(param_1);
  *(undefined4 *)(param_1 + 0x54) = param_2;
  if (iVar1 != 0) {
    if (param_3 == 0) {
      _run_queue_enqueue(iVar1,param_1);
    }
    else {
      _thread_setrun(param_1,1);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1561 start=0x4051374 */

int _rem_runq(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[2];
  if (iVar1 != 0) {
    *(int *)(*param_1 + 4) = param_1[1];
    *(int *)param_1[1] = *param_1;
    *(int *)(iVar1 + 0x104) = *(int *)(iVar1 + 0x104) + -1;
    param_1[2] = 0;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1562 start=0x40513a6 */

int _choose_thread(int param_1)

{
  word wVar1;
  sword sVar3;
  int iVar2;
  int *piVar4;
  int *piVar5;
  
  if (*(int *)(param_1 + 0x104) < 1) {
    iVar2 = _choose_pset_thread(param_1,*(undefined4 *)(param_1 + 0x128));
    return iVar2;
  }
  iVar2 = *(int *)(param_1 + 0x100);
  piVar5 = (int *)(param_1 + iVar2 * 8);
  if (-1 < iVar2) {
    do {
      piVar4 = (int *)*piVar5;
      if (piVar4 != piVar5) {
        if (piVar5 == piVar4) {
          piVar4 = (int *)0x0;
        }
        else {
          *(int **)(*piVar4 + 4) = piVar5;
          *piVar5 = *piVar4;
        }
        *(undefined4 *)((int)piVar4 + 8) = 0;
        *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + -1;
        *(int *)(param_1 + 0x100) = iVar2;
        return (int)piVar4;
      }
      piVar5 = piVar5 + -2;
      wVar1 = (word)((uint)iVar2 >> 0x10);
      sVar3 = (sword)iVar2 + -1;
      iVar2 = CONCAT22(wVar1,sVar3);
    } while ((sVar3 != -1) || (iVar2 = (uint)wVar1 * 0x10000 + -1, wVar1 != 0));
  }
                    /* WARNING: Subroutine does not return */
  _panic(aChooseThread);
}
/* GHIDRADEC_FUNCTION index=1563 start=0x405141c */

int * _choose_pset_thread(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  if (*(int *)(param_2 + 0x104) < 1) {
    if (*(int *)(param_1 + 0x110) == 1) {
      *(undefined4 *)(param_1 + 0x110) = 2;
      if (param_1 == _master_processor) {
        piVar3 = *(int **)(param_2 + 0x10c);
        if (piVar3 == (int *)(param_2 + 0x108)) {
          *piVar3 = param_1;
        }
        else {
          piVar3[0x42] = param_1;
        }
        *(int **)(param_1 + 0x10c) = piVar3;
        *(int *)(param_1 + 0x108) = param_2 + 0x108;
        *(int *)(param_2 + 0x10c) = param_1;
      }
      else {
        iVar2 = *(int *)(param_2 + 0x108);
        if (iVar2 == param_2 + 0x108) {
          *(int *)(param_2 + 0x10c) = param_1;
        }
        else {
          *(int *)(iVar2 + 0x10c) = param_1;
        }
        *(int *)(param_1 + 0x108) = iVar2;
        *(int **)(param_1 + 0x10c) = (int *)(param_2 + 0x108);
        *(int *)(param_2 + 0x108) = param_1;
      }
      *(int *)(param_2 + 0x110) = *(int *)(param_2 + 0x110) + 1;
    }
    piVar3 = *(int **)(param_1 + 0x118);
  }
  else {
    iVar2 = *(int *)(param_2 + 0x100);
    piVar4 = (int *)(param_2 + iVar2 * 8);
    while( true ) {
      if (iVar2 < 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aChoosePsetThre);
      }
      piVar3 = (int *)*piVar4;
      if (piVar3 != piVar4) break;
      iVar2 = iVar2 + -1;
      piVar4 = piVar4 + -2;
    }
    if (piVar4 == piVar3) {
      piVar3 = (int *)0x0;
    }
    else {
      *(int **)(*piVar3 + 4) = piVar4;
      *piVar4 = *piVar3;
    }
    *(undefined4 *)((int)piVar3 + 8) = 0;
    iVar1 = *(int *)(param_2 + 0x104);
    *(int *)(param_2 + 0x104) = iVar1 + -1;
    if (((iVar1 != 1 && -1 < iVar1 + -1) && ((*(byte *)(param_2 + 0x15b) & 2) != 0)) &&
       (piVar4 == (int *)*piVar4)) {
      do {
        piVar4 = piVar4 + -2;
        iVar2 = iVar2 + -1;
      } while (piVar4 == (int *)*piVar4);
    }
    *(int *)(param_2 + 0x100) = iVar2;
  }
  return piVar3;
}
/* GHIDRADEC_FUNCTION index=1564 start=0x4051518 */

void _idle_thread_continue(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  iVar6 = _processor_ptr;
  piVar4 = (int *)(_processor_ptr + 0x114);
  piVar5 = (int *)(_processor_ptr + 0x104);
  do {
    while( true ) {
      _PMSetCpuState(0);
      while (((*piVar4 == 0 && (dword_40B674C == 0)) && (*piVar5 == 0))) {
        if ((_need_ast & 0xfffffff8) != 0) {
          _need_ast = _need_ast & 0xfffffff8;
        }
      }
      _PMSetCpuState(1);
      iVar1 = *(int *)(iVar6 + 0x110);
      if (iVar1 != 3) break;
      iVar1 = *piVar4;
      *piVar4 = 0;
      *(undefined4 *)(iVar6 + 0x110) = 1;
      if (*(int *)(iVar1 + 0x5c) == 2) {
        *(undefined4 *)(iVar6 + 0x11c) = *(undefined4 *)(iVar1 + 0x58);
      }
      else {
        *(undefined4 *)(iVar6 + 0x11c) = dword_40B67A4;
      }
      *(undefined4 *)(iVar6 + 0x120) = 1;
      _thread_run(_idle_thread_continue,iVar1);
    }
    if (iVar1 == 2) {
      iVar1 = *(int *)(iVar6 + 0x128);
      _no_dispatch_count = _no_dispatch_count + 1;
      *(int *)(iVar1 + 0x110) = *(int *)(iVar1 + 0x110) + -1;
      iVar2 = *(int *)(iVar6 + 0x108);
      piVar3 = *(int **)(iVar6 + 0x10c);
      if (iVar2 == iVar1 + 0x108) {
        *(int **)(iVar1 + 0x10c) = piVar3;
      }
      else {
        *(int **)(iVar2 + 0x10c) = piVar3;
      }
      if (piVar3 == (int *)(iVar1 + 0x108)) {
        *piVar3 = iVar2;
      }
      else {
        piVar3[0x42] = iVar2;
      }
      *(undefined4 *)(iVar6 + 0x110) = 1;
    }
    else {
      if (1 < iVar1 - 4U) {
        _printf(aBadProcessorSt,*(undefined4 *)(_processor_ptr + 0x110),0);
                    /* WARNING: Subroutine does not return */
        _panic(aIdleThread);
      }
      iVar1 = *piVar4;
      if (iVar1 != 0) {
        *piVar4 = 0;
        _thread_setrun(iVar1,0);
      }
    }
    _thread_block_with_continuation(_idle_thread_continue);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1565 start=0x4051688 */

void _idle_thread(void)

{
  int iVar1;
  
  iVar1 = _active_threads;
  _stack_privilege(_active_threads);
  *(undefined4 *)(iVar1 + 0x4c) = 0;
  *(undefined4 *)(iVar1 + 0x54) = 0;
  *(word *)(iVar1 + 0x4a) = *(word *)(iVar1 + 0x4a) | 0x80;
  *(int *)(_processor_ptr + 0x118) = iVar1;
  _thread_block_with_continuation(_idle_thread_continue);
                    /* WARNING: Subroutine does not return */
  _idle_thread_continue();
}
/* GHIDRADEC_FUNCTION index=1566 start=0x40516dc */

void _sched_thread_continue(void)

{
  do {
    _compute_mach_factor();
    if ((bRam040c2453 & 1) != 0) {
      _do_thread_scan();
    }
    _assert_wait(0,0);
    _thread_block_with_continuation(_sched_thread_continue);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1567 start=0x4051714 */

void _sched_thread(void)

{
  _sched_thread_id = _active_threads;
  _assert_wait(0,0);
  _thread_block_with_continuation(_sched_thread_continue);
                    /* WARNING: Subroutine does not return */
  _sched_thread_continue();
}
/* GHIDRADEC_FUNCTION index=1568 start=0x4051742 */

undefined4 _do_runq_scan(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar4 = *(int *)(param_1 + 0x104);
  if (0 < iVar4) {
    puVar5 = (undefined4 *)(param_1 + *(int *)(param_1 + 0x100) * 8);
    do {
      puVar2 = (undefined4 *)*puVar5;
      iVar3 = _stuck_count;
      while (_stuck_count = iVar3, puVar2 != puVar5) {
        puVar1 = (undefined4 *)*puVar2;
        if (((puVar2[0x12] & 0xf) == 4) && (1 < (uint)(_sched_tick - puVar2[0x1b]))) {
          if (iVar3 == 0x80) {
            return 1;
          }
          puVar1[1] = puVar2[1];
          *(undefined4 *)puVar2[1] = *puVar2;
          *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + -1;
          puVar2[2] = 0;
          *(undefined4 **)(_stuck_threads + iVar3 * 4) = puVar2;
          _stuck_count = _stuck_count + 1;
          if (_do_thread_scan_debug != 0) {
            _printf(aDoRunqScanAddi,puVar2);
          }
        }
        iVar4 = iVar4 + -1;
        puVar2 = puVar1;
        iVar3 = _stuck_count;
      }
      puVar5 = puVar5 + -2;
    } while (0 < iVar4);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1569 start=0x40517fe */

uint _do_thread_scan(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  byte bVar9;
  
  do {
    uVar3 = _do_runq_scan(_default_pset);
    uVar4 = uVar3;
    if (uVar3 == 0) {
      uVar3 = _do_runq_scan(_master_processor);
      uVar4 = uVar3;
    }
    while (0 < _stuck_count) {
      iVar2 = _stuck_count + -1;
      iVar1 = *(int *)(_stuck_threads + iVar2 * 4);
      _stuck_count = _stuck_count + -1;
      *(undefined4 *)(_stuck_threads + iVar2 * 4) = 0;
      uVar3 = *(uint *)(iVar1 + 0x48) & 0xf;
      cVar8 = 4 < uVar3;
      cVar7 = SBORROW4(4,uVar3);
      cVar5 = (int)(4 - uVar3) < 0;
      cVar6 = '\0';
      bVar9 = cVar8;
      if (uVar3 == 4) {
        _update_priority(iVar1);
        cVar5 = iVar1 < 0;
        cVar6 = iVar1 == 0;
        cVar7 = '\0';
        bVar9 = 0;
        _thread_setrun(iVar1,1);
      }
      uVar3 = (uint)(byte)(cVar8 << 4 | cVar5 << 3 | cVar6 << 2 | cVar7 << 1 | bVar9);
    }
  } while (uVar4 != 0);
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1570 start=0x405188e */

void _thread_wakeup(undefined4 param_1)

{
  _thread_wakeup_prim(param_1,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=1571 start=0x40518a4 */

undefined4 _thread_wait_result(void)

{
  return *(undefined4 *)(_active_threads + 0x40);
}
/* GHIDRADEC_FUNCTION index=1572 start=0x40518b6 */

void _thread_block(void)

{
  _thread_block_with_continuation(0);
  return;
}
/* GHIDRADEC_FUNCTION index=1573 start=0x40518c6 */

void _swtch_continue(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((0 < *(int *)(_processor_ptr + 0x104)) ||
     (0 < *(int *)(*(int *)(_processor_ptr + 0x128) + 0x104))) {
    uVar1 = 1;
  }
  _thread_syscall_return(uVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=1574 start=0x40518f0 */

undefined4 _swtch(void)

{
  undefined4 uVar1;
  
  _thread_block_with_continuation(_swtch_continue);
  uVar1 = 0;
  if ((0 < *(int *)(_processor_ptr + 0x104)) ||
     (0 < *(int *)(*(int *)(_processor_ptr + 0x128) + 0x104))) {
    uVar1 = 1;
  }
  return uVar1;
}

