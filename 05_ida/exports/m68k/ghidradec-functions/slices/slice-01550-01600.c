/* GHIDRADEC_FUNCTION index=1550 start=0x4050bd2 */

undefined4 _thread_invoke(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (param_3 == param_1) {
    *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffff7;
    if (param_2 == 0) {
      return 1;
    }
    _call_continuation(param_2);
    return 1;
  }
  if ((*(int *)(param_1 + 0x2c) == _active_stacks) || (param_2 == 0)) {
    if (((*(uint *)(param_3 + 0x48) & 0x100) != 0) &&
       (((*(uint *)(param_3 + 0x48) & 0x200) != 0 ||
        (iVar3 = _stack_alloc_try(param_3,_thread_continue), iVar3 == 0)))) {
loc_4050D8A:
      _thread_swapin(param_3);
      _c_thread_invoke_misses = _c_thread_invoke_misses + 1;
      return 0;
    }
loc_4050DAE:
    *(word *)(param_3 + 0x4a) = *(word *)(param_3 + 0x4a) & 0xfef7;
    _need_ast = *(uint *)(param_3 + 0x174) | _need_ast & 0xfffffffc;
    if (_need_ast == 0) {
      pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
      *pbVar1 = *pbVar1 & 0xef;
    }
    else {
      pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
      *pbVar1 = *pbVar1 | 0x10;
    }
    _switch_unix_context(param_3);
    _c_thread_invoke_csw = _c_thread_invoke_csw + 1;
    uVar4 = _switch_context(param_1,param_2,param_3);
    _thread_dispatch(uVar4);
    return 1;
  }
  uVar2 = *(uint *)(param_3 + 0x48) & 0x300;
  if (uVar2 != 0x100) {
    if ((0x100 < uVar2) && (uVar2 == 0x200)) goto loc_4050D8A;
    goto loc_4050DAE;
  }
  *(uint *)(param_3 + 0x48) = *(uint *)(param_3 + 0x48) & 0xfffffef7;
  _need_ast = *(uint *)(param_3 + 0x174) | _need_ast & 0xfffffffc;
  if (_need_ast == 0) {
    pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
    *pbVar1 = *pbVar1 & 0xef;
  }
  else {
    pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
    *pbVar1 = *pbVar1 | 0x10;
  }
  _switch_unix_context(param_3);
  _stack_handoff(param_1,param_3);
  *(int *)(param_1 + 0x30) = param_2;
  iVar3 = *(int *)(param_1 + 0x48);
  if (iVar3 == 0xc) {
loc_4050D10:
    *(word *)(param_1 + 0x4a) = *(word *)(param_1 + 0x4a) | 0x100;
    _thread_setrun(param_1,0);
  }
  else {
    if (iVar3 < 0xd) {
      if (iVar3 != 5) {
        if (5 < iVar3) {
          if (7 < iVar3) goto loc_4050D3E;
loc_4050CE4:
          *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffffb | 0x100;
          if (*(int *)(param_1 + 0x44) != 0) {
            *(undefined4 *)(param_1 + 0x44) = 0;
            _thread_wakeup_prim(param_1 + 0x44,0,0);
          }
          goto loc_4050D4C;
        }
        iVar5 = 4;
loc_4050CCE:
        if (iVar5 != iVar3) {
loc_4050D3E:
                    /* WARNING: Subroutine does not return */
          _panic(aThreadInvoke);
        }
        goto loc_4050D10;
      }
    }
    else if (iVar3 != 0xf) {
      if (0xf < iVar3) {
        if (iVar3 != 0x16) {
          if (iVar3 != 0x84) goto loc_4050D3E;
          *(undefined4 *)(param_1 + 0x48) = 0x184;
          goto loc_4050D4C;
        }
        goto loc_4050CE4;
      }
      if (iVar3 != 0xd) {
        iVar5 = 0xe;
        goto loc_4050CCE;
      }
    }
    *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffffb | 0x100;
  }
loc_4050D4C:
  _c_thread_invoke_hits = _c_thread_invoke_hits + 1;
  _call_continuation(*(undefined4 *)(param_3 + 0x30));
  return 1;
}
/* GHIDRADEC_FUNCTION index=1551 start=0x4050e08 */

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
/* GHIDRADEC_FUNCTION index=1552 start=0x4050e38 */

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
/* GHIDRADEC_FUNCTION index=1553 start=0x4050ea6 */

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
/* GHIDRADEC_FUNCTION index=1554 start=0x4050efc */

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
/* GHIDRADEC_FUNCTION index=1555 start=0x4050fae */

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
/* GHIDRADEC_FUNCTION index=1556 start=0x4051000 */

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
/* GHIDRADEC_FUNCTION index=1557 start=0x4051024 */

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
/* GHIDRADEC_FUNCTION index=1558 start=0x4051080 */

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
/* GHIDRADEC_FUNCTION index=1559 start=0x40511ca */

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
/* GHIDRADEC_FUNCTION index=1560 start=0x405122e */

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
/* GHIDRADEC_FUNCTION index=1561 start=0x4051328 */

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
/* GHIDRADEC_FUNCTION index=1562 start=0x4051374 */

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
/* GHIDRADEC_FUNCTION index=1563 start=0x40513a6 */

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
/* GHIDRADEC_FUNCTION index=1564 start=0x405141c */

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
/* GHIDRADEC_FUNCTION index=1565 start=0x4051518 */

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
/* GHIDRADEC_FUNCTION index=1566 start=0x4051688 */

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
/* GHIDRADEC_FUNCTION index=1567 start=0x40516dc */

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
/* GHIDRADEC_FUNCTION index=1568 start=0x4051714 */

void _sched_thread(void)

{
  _sched_thread_id = _active_threads;
  _assert_wait(0,0);
  _thread_block_with_continuation(_sched_thread_continue);
                    /* WARNING: Subroutine does not return */
  _sched_thread_continue();
}
/* GHIDRADEC_FUNCTION index=1569 start=0x4051742 */

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
/* GHIDRADEC_FUNCTION index=1570 start=0x40517fe */

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
/* GHIDRADEC_FUNCTION index=1571 start=0x405188e */

void _thread_wakeup(undefined4 param_1)

{
  _thread_wakeup_prim(param_1,0,0);
  return;
}
/* GHIDRADEC_FUNCTION index=1572 start=0x40518a4 */

undefined4 _thread_wait_result(void)

{
  return *(undefined4 *)(_active_threads + 0x40);
}
/* GHIDRADEC_FUNCTION index=1573 start=0x40518b6 */

void _thread_block(void)

{
  _thread_block_with_continuation(0);
  return;
}
/* GHIDRADEC_FUNCTION index=1574 start=0x40518c6 */

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
/* GHIDRADEC_FUNCTION index=1575 start=0x40518f0 */

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
/* GHIDRADEC_FUNCTION index=1576 start=0x405191e */

void _swtch_pri_continue(void)

{
  undefined4 uVar1;
  
  if (-1 < *(int *)(_active_threads + 0x60)) {
    _thread_depress_abort(_active_threads);
  }
  uVar1 = 0;
  if ((0 < *(int *)(_processor_ptr + 0x104)) ||
     (0 < *(int *)(*(int *)(_processor_ptr + 0x128) + 0x104))) {
    uVar1 = 1;
  }
  _thread_syscall_return(uVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=1577 start=0x405195e */

undefined4 _swtch_pri(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _active_threads;
  _thread_depress_priority(_active_threads,_min_quantum);
  _thread_block_with_continuation(_swtch_pri_continue);
  if (-1 < *(int *)(iVar1 + 0x60)) {
    _thread_depress_abort(iVar1);
  }
  uVar2 = 0;
  if ((0 < *(int *)(_processor_ptr + 0x104)) ||
     (0 < *(int *)(*(int *)(_processor_ptr + 0x128) + 0x104))) {
    uVar2 = 1;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1578 start=0x40519b8 */

void _thread_switch_continue(void)

{
  if (-1 < *(int *)(_active_threads + 0x60)) {
    _thread_depress_abort(_active_threads);
  }
  _thread_syscall_return(0);
  return;
}
/* GHIDRADEC_FUNCTION index=1579 start=0x40519de */

undefined4 _thread_switch(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iStack_8;
  
  iVar1 = _active_threads;
  if (param_2 == 1) {
    _thread_depress_priority(_active_threads,param_3);
  }
  else if (param_2 < 2) {
    if (param_2 != 0) {
      return 4;
    }
  }
  else {
    if (param_2 != 2) {
      return 4;
    }
    _thread_will_wait_with_timeout(_active_threads,param_3);
  }
  if (param_1 != 0) {
    iVar3 = _ipc_object_translate(*(undefined4 *)(*(int *)(iVar1 + 0xc) + 0x7c),param_1,0,&iStack_8)
    ;
    if (iVar3 == 0) {
      if ((((*(int *)(iStack_8 + 4) < 0) && ((sword)*(int *)(iStack_8 + 4) == 1)) &&
          (iVar3 = *(int *)(iStack_8 + 0x10), *(int *)(iVar3 + 0x178) == *(int *)(iVar1 + 0x178)))
         && (iVar4 = _rem_runq(iVar3), iVar2 = _processor_ptr, iVar4 != 0)) {
        if (*(int *)(iVar3 + 0x5c) == 2) {
          *(undefined4 *)(_processor_ptr + 0x11c) = *(undefined4 *)(iVar3 + 0x58);
          *(undefined4 *)(iVar2 + 0x120) = 1;
        }
        _thread_run(_thread_switch_continue,iVar3);
        goto loc_4051AD2;
      }
    }
    else if (iVar3 == 0xf) {
      return 4;
    }
  }
  _thread_block_with_continuation(_thread_switch_continue);
loc_4051AD2:
  if (-1 < *(int *)(iVar1 + 0x60)) {
    _thread_depress_abort(iVar1);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1580 start=0x4051aec */

undefined4 _thread_depress_priority(int param_1,int param_2)

{
  uint uVar1;
  undefined2 extraout_D0u;
  undefined2 extraout_D0u_00;
  undefined2 uVar2;
  uint uVar3;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  
  uVar1 = _hz * param_2 + 999;
  uVar3 = uVar1 / 1000;
  uVar2 = (undefined2)(uVar1 / 0xfa000);
  cVar4 = '\0';
  if (*(int *)(param_1 + 0x16c) != 0) {
    _reset_timeout(param_1 + 0x140);
    uVar2 = extraout_D0u;
  }
  *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  cVar7 = '\0';
  bVar8 = 0;
  cVar5 = '\0';
  cVar6 = uVar3 == 0;
  if (!(bool)cVar6) {
    cVar5 = '\0';
    cVar6 = uVar3 == 0;
    cVar7 = '\0';
    bVar8 = 0;
    _set_timeout(param_1 + 0x140,uVar3);
    uVar2 = extraout_D0u_00;
  }
  return CONCAT22(uVar2,(word)(byte)(cVar4 << 4 | cVar5 << 3 | cVar6 << 2 | cVar7 << 1 | bVar8));
}
/* GHIDRADEC_FUNCTION index=1581 start=0x4051b60 */

byte _thread_depress_timeout(int param_1)

{
  int iVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  cVar2 = '\0';
  iVar1 = *(int *)(param_1 + 0x60);
  cVar3 = iVar1 < 0;
  cVar4 = iVar1 == 0;
  cVar5 = '\0';
  bVar6 = 0;
  if (!(bool)cVar3) {
    *(int *)(param_1 + 0x4c) = iVar1;
    *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
    cVar3 = param_1 < 0;
    cVar4 = param_1 == 0;
    cVar5 = '\0';
    bVar6 = 0;
    _compute_priority(param_1,0);
  }
  return cVar2 << 4 | cVar3 << 3 | cVar4 << 2 | cVar5 << 1 | bVar6;
}
/* GHIDRADEC_FUNCTION index=1582 start=0x4051b9a */

undefined4 _thread_depress_abort(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    if (-1 < *(int *)(param_1 + 0x60)) {
      if (*(int *)(param_1 + 0x16c) != 0) {
        _reset_timeout(param_1 + 0x140);
      }
      *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x60);
      *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
      _compute_priority(param_1,0);
    }
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1583 start=0x4051bf8 */

int _map_fd(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uStack_c;
  uint uStack_8;
  
  uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
  iVar5 = _getf(param_1);
  if (((iVar5 == 0) || (piVar2 = *(int **)(iVar5 + 0x16), *(sword *)(iVar5 + 0xc) != 1)) ||
     (piVar2[10] != 1)) {
loc_4051CEE:
    iVar5 = 4;
  }
  else {
    uVar3 = ~_page_mask & _page_mask + param_5;
    if (param_4 == 0) {
      iVar5 = _copyinmsg(param_3,&uStack_8,4);
      if (iVar5 != 0) {
        return 1;
      }
      uVar4 = uStack_8 & ~_page_mask;
      if ((uStack_8 != uVar4) ||
         (iVar5 = _vm_map_check_protection(uVar1,uVar4,uVar4 + uVar3,3), iVar5 == 0))
      goto loc_4051CEE;
    }
    else {
      iVar5 = _vm_allocate(uVar1,&uStack_8,param_5,1);
      if (iVar5 != 0) {
        return iVar5;
      }
      iVar5 = _copyoutmsg(&uStack_8,param_3,4);
      if (iVar5 != 0) {
        _vm_deallocate(uVar1,uStack_8,param_5);
        return 1;
      }
    }
    if (param_5 == 0) {
      iVar5 = 0;
    }
    else {
      uVar6 = _vnode_pager_setup(piVar2,0,0);
      uVar7 = _pmap_create(uVar3,0,uVar3,1);
      uVar7 = _vm_map_create(uVar7);
      uStack_c = 0;
      iVar5 = _vm_allocate_with_pager(uVar7,&uStack_c,uVar3,0,uVar6,param_2);
      if (((iVar5 != 0) || (iVar5 = _vm_map_copy(uVar1,uVar7,uStack_8,uVar3,0,0,0), iVar5 != 0)) &&
         (param_4 != 0)) {
        _vm_deallocate(uVar1,uStack_8,uVar3);
      }
      _vm_map_deallocate(uVar7);
      if (*(int *)(*piVar2 + 0x2c) == 0) {
        **(sword **)(_active_u + 0x1a) = **(sword **)(_active_u + 0x1a) + 1;
        *(undefined4 *)(*piVar2 + 0x2c) = *(undefined4 *)(_active_u + 0x1a);
      }
    }
  }
  return iVar5;
}
/* GHIDRADEC_FUNCTION index=1584 start=0x4051db2 */

undefined4 _null_port(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=1585 start=0x4051dbc */

undefined4 _kern_invalid(void)

{
  return 4;
}
/* GHIDRADEC_FUNCTION index=1586 start=0x4051dc6 */

void _task_init(void)

{
  int iVar1;
  
  _task_zone = _zinit(0x80,0x10000,0x2000,0,&aTasks);
  _task_create(0,0,&_kernel_task);
  iVar1 = _kernel_task;
  *(undefined4 *)(_kernel_task + 0x44) = 1;
  *(undefined4 *)(iVar1 + 0x48) = 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1587 start=0x4051e10 */

int _kernel_task_create(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined auStack_10 [4];
  undefined auStack_c [4];
  int iStack_8;
  
  _task_create(param_1,0,&iStack_8);
  _task_deallocate(iStack_8);
  _vm_map_deallocate(*(undefined4 *)(iStack_8 + 8));
  if (param_2 == 0) {
    *(undefined4 *)(iStack_8 + 8) = _kernel_map;
  }
  else {
    uVar1 = _kmem_suballoc(_kernel_map,auStack_c,auStack_10,param_2,0);
    *(undefined4 *)(iStack_8 + 8) = uVar1;
  }
  *(undefined4 *)(iStack_8 + 0x48) = 1;
  return iStack_8;
}
/* GHIDRADEC_FUNCTION index=1588 start=0x4051e8c */

undefined4 _task_create(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  puVar2 = (undefined4 *)_zalloc(_task_zone);
  if (puVar2 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aTaskCreateNoMe);
  }
  uVar3 = _zalloc(_u_task_zone);
  puVar2[0xc] = uVar3;
  _utask_zero(puVar2);
  *puVar2 = 2;
  if (param_3 == &_kernel_task) {
    puVar2[2] = _kernel_map;
  }
  else if (param_2 == 0) {
    uVar3 = _pmap_create(0,0,~_page_mask & 0xfffffffc,1);
    uVar3 = _vm_map_create(uVar3);
    puVar2[2] = uVar3;
  }
  else {
    uVar3 = _vm_map_fork(*(undefined4 *)(param_1 + 8));
    puVar2[2] = uVar3;
  }
  puVar1 = puVar2 + 6;
  puVar2[7] = puVar1;
  *puVar1 = puVar1;
  puVar2[5] = 0;
  puVar2[1] = 1;
  puVar2[0xf] = 0;
  puVar2[8] = 0;
  puVar2[0xe] = 0;
  puVar2[0x12] = 0;
  _ipc_task_init(puVar2,param_1);
  puVar2[0x13] = 0;
  puVar2[0x14] = 0;
  puVar2[0x15] = 0;
  puVar2[0x16] = 0;
  if (param_1 == 0) {
    puVar2[0x11] = 0;
    puVar4 = _default_pset;
    _pset_reference(_default_pset);
    puVar2[0x10] = 10;
  }
  else {
    puVar2[0x11] = *(undefined4 *)(param_1 + 0x44);
    puVar4 = *(undefined **)(param_1 + 0x24);
    if (*(int *)(puVar4 + 0x148) == 0) {
      puVar4 = _default_pset;
    }
    _pset_reference(puVar4);
    puVar2[0x10] = *(undefined4 *)(param_1 + 0x40);
  }
  _pset_add_task(puVar4,puVar2);
  puVar2[10] = 1;
  puVar2[0xb] = 0;
  _ipc_task_enable(puVar2);
  *param_3 = puVar2;
  return 0;
}
/* GHIDRADEC_FUNCTION index=1589 start=0x4051fe0 */

void _task_deallocate(int *param_1)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && (iVar1 = *param_1, *param_1 = iVar1 + -1, iVar1 == 1)) {
    iVar1 = param_1[9];
    _pset_remove_task(iVar1,param_1);
    _pset_deallocate(iVar1);
    _vm_map_deallocate(param_1[2]);
    _ipc_space_release(param_1[0x1f]);
    _utask_free(param_1[0xc]);
    _zfree(_task_zone,param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1590 start=0x405204c */

void _task_reference(int *param_1)

{
  if (param_1 != (int *)0x0) {
    *param_1 = *param_1 + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1591 start=0x405205e */

undefined4 _task_terminate(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = _active_threads;
  if (param_1 == 0) {
    return 4;
  }
  piVar4 = (int *)(param_1 + 0x18);
  if (*(int *)(_active_threads + 0xc) == param_1) {
    if (*(int *)(param_1 + 4) == 0) {
      return 5;
    }
    if (*(int *)(_active_threads + 0x170) != 0) {
      *(undefined4 *)(param_1 + 4) = 0;
      piVar2 = *(int **)(iVar5 + 0x10);
      piVar3 = *(int **)(iVar5 + 0x14);
      if (piVar2 == piVar4) {
        *(int **)(param_1 + 0x1c) = piVar3;
      }
      else {
        piVar2[5] = (int)piVar3;
      }
      if (piVar3 == piVar4) {
        *piVar4 = (int)piVar2;
      }
      else {
        piVar3[4] = (int)piVar2;
      }
      _ipc_thread_disable(iVar5);
      _ipc_thread_terminate(iVar5);
loc_405211C:
      _ipc_task_disable(param_1);
      _task_hold(param_1);
      _task_dowait(param_1,1);
      while (piVar4 != (int *)*piVar4) {
        iVar1 = *piVar4;
        _thread_reference(iVar1);
        _thread_force_terminate(iVar1);
        _thread_deallocate(iVar1);
        _thread_block_with_continuation(0);
      }
      _ipc_task_terminate(param_1);
      _task_deallocate(param_1);
      if (param_1 == *(int *)(iVar5 + 0xc)) {
        piVar2 = *(int **)(param_1 + 0x1c);
        if (piVar2 == piVar4) {
          *piVar4 = iVar5;
        }
        else {
          piVar2[4] = iVar5;
        }
        *(int **)(iVar5 + 0x14) = piVar2;
        *(int **)(iVar5 + 0x10) = piVar4;
        *(int *)(param_1 + 0x1c) = iVar5;
        _thread_terminate(iVar5);
      }
      return 0;
    }
  }
  else if ((*(int *)(*(int *)(_active_threads + 0xc) + 4) != 0) &&
          (*(int *)(_active_threads + 0x170) != 0)) {
    if (*(int *)(param_1 + 4) == 0) {
      return 5;
    }
    *(undefined4 *)(param_1 + 4) = 0;
    goto loc_405211C;
  }
  _thread_terminate(_active_threads);
  return 5;
}
/* GHIDRADEC_FUNCTION index=1592 start=0x40521ba */

undefined4 _task_hold(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = _active_threads;
  if (*(int *)(param_1 + 4) == 0) {
    uVar3 = 5;
  }
  else {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)(param_1 + 0x18);
        puVar1 = (undefined4 *)puVar1[4]) {
      if (puVar2 != puVar1) {
        _thread_hold(puVar1);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1593 start=0x4052206 */

undefined4 _task_dowait(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  puVar2 = _active_threads;
  uVar4 = 0;
  puVar3 = (undefined4 *)0x0;
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  do {
    if (puVar1 == (undefined4 *)(param_1 + 0x18)) {
loc_405226C:
      if (puVar3 != (undefined4 *)0x0) {
        _thread_deallocate(puVar3);
      }
      return uVar4;
    }
    if ((*(int *)(param_1 + 4) == 0) && (param_2 == 0)) {
      uVar4 = 5;
      goto loc_405226C;
    }
    if (puVar2 != puVar1) {
      _thread_reference(puVar1);
      if (puVar3 != (undefined4 *)0x0) {
        _thread_deallocate(puVar3);
      }
      _thread_dowait(puVar1,1);
      puVar3 = puVar1;
    }
    puVar1 = (undefined4 *)puVar1[4];
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1594 start=0x4052284 */

undefined4 _task_release(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 4) == 0) {
    uVar3 = 5;
  }
  else {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
    puVar2 = *(undefined4 **)(param_1 + 0x18);
    while (puVar2 != (undefined4 *)(param_1 + 0x18)) {
      puVar1 = (undefined4 *)puVar2[4];
      _thread_release(puVar2);
      puVar2 = puVar1;
    }
    uVar3 = 0;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1595 start=0x40522ca */

undefined4 _task_halt(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = _active_threads;
  puVar3 = (undefined4 *)0x0;
  for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)(param_1 + 0x18);
      puVar1 = (undefined4 *)puVar1[4]) {
    if (puVar2 != puVar1) {
      _thread_reference(puVar1);
      if (puVar3 != (undefined4 *)0x0) {
        _thread_deallocate(puVar3);
      }
      _thread_halt(puVar1,1);
      puVar3 = puVar1;
    }
  }
  if (puVar3 != (undefined4 *)0x0) {
    _thread_deallocate(puVar3);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1596 start=0x4052334 */

undefined4 _task_threads(int param_1,undefined4 *param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  
  if (param_1 == 0) {
    uVar2 = 4;
  }
  else {
    piVar8 = (int *)0x0;
    uVar7 = 0;
    do {
      if (*(int *)(param_1 + 4) == 0) {
        return 5;
      }
      uVar1 = *(uint *)(param_1 + 0x20);
      uVar6 = uVar1 << 2;
      if (uVar6 <= uVar7) {
        uVar5 = 0;
        iVar4 = *(int *)(param_1 + 0x18);
        piVar3 = piVar8;
        if (uVar1 != 0) {
          do {
            _thread_reference(iVar4);
            *piVar3 = iVar4;
            uVar5 = uVar5 + 1;
            iVar4 = *(int *)(iVar4 + 0x10);
            piVar3 = piVar3 + 1;
          } while (uVar5 < uVar1);
        }
        if (uVar1 == 0) {
          *param_2 = 0;
          *param_3 = 0;
          if (uVar7 != 0) {
            _kfree(piVar8,uVar7);
          }
        }
        else {
          piVar3 = piVar8;
          if (uVar6 < uVar7) {
            piVar3 = (int *)_kalloc(uVar6);
            if (piVar3 == (int *)0x0) {
              uVar6 = 0;
              piVar3 = piVar8;
              if (uVar1 != 0) {
                do {
                  _thread_deallocate(*piVar3);
                  uVar6 = uVar6 + 1;
                  piVar3 = piVar3 + 1;
                } while (uVar6 < uVar1);
              }
              _kfree(piVar8,uVar7);
              return 6;
            }
            _bcopy(piVar8,piVar3,uVar6);
            _kfree(piVar8,uVar7);
          }
          *param_2 = piVar3;
          *param_3 = uVar1;
          uVar7 = 0;
          if (uVar1 != 0) {
            do {
              iVar4 = _convert_thread_to_port(*piVar3);
              *piVar3 = iVar4;
              uVar7 = uVar7 + 1;
              piVar3 = piVar3 + 1;
            } while (uVar7 < uVar1);
          }
        }
        return 0;
      }
      if (uVar7 != 0) {
        _kfree(piVar8,uVar7);
      }
      piVar8 = (int *)_kalloc(uVar6);
      uVar7 = uVar6;
    } while (piVar8 != (int *)0x0);
    uVar2 = 6;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1597 start=0x4052450 */

undefined4 _task_suspend(int param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == 0) {
    uVar2 = 4;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x3c);
    *(int *)(param_1 + 0x3c) = iVar3 + 1;
    if (iVar3 == 0) {
      iVar3 = _task_hold(param_1);
      if ((iVar3 != 0) || (iVar3 = _task_dowait(param_1,0), iVar3 != 0)) {
        return 5;
      }
      if (param_1 == *(int *)(_active_threads + 0xc)) {
        _thread_hold(_active_threads);
        _need_ast = _need_ast | 4;
        if (_need_ast != 0) {
          pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
          *pbVar1 = *pbVar1 | 0x10;
        }
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1598 start=0x40524f2 */

undefined4 _task_resume(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 4;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x3c);
    if (iVar1 < 1) {
      uVar2 = 5;
    }
    else {
      *(int *)(param_1 + 0x3c) = iVar1 + -1;
      if (iVar1 == 1) {
        uVar2 = _task_release(param_1);
      }
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1599 start=0x4052532 */

undefined4 _task_info(int param_1,int param_2,int *param_3,uint *param_4)

{
  int iVar1;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if (param_1 != 0) {
    if (param_2 == 1) {
      if (7 < *param_4) {
        iVar1 = _kernel_map;
        if (param_1 != _kernel_task) {
          iVar1 = *(int *)(param_1 + 8);
        }
        param_3[2] = *(int *)(iVar1 + 0x24);
        param_3[3] = _page_size * *(int *)(*(int *)(iVar1 + 0x20) + 0x10);
        param_3[1] = *(int *)(param_1 + 0x40);
        *param_3 = *(int *)(param_1 + 0x3c);
        param_3[4] = *(int *)(param_1 + 0x4c);
        param_3[5] = *(int *)(param_1 + 0x50);
        param_3[6] = *(int *)(param_1 + 0x54);
        param_3[7] = *(int *)(param_1 + 0x58);
        *param_4 = 8;
        return 0;
      }
    }
    else if ((param_2 == 3) && (3 < *param_4)) {
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      for (iVar1 = *(int *)(param_1 + 0x18); iVar1 != param_1 + 0x18; iVar1 = *(int *)(iVar1 + 0x10)
          ) {
        _thread_read_times(iVar1,&iStack_c,&iStack_14);
        param_3[1] = iStack_8 + param_3[1];
        *param_3 = iStack_c + *param_3;
        if (999999 < param_3[1]) {
          param_3[1] = param_3[1] + -1000000;
          *param_3 = *param_3 + 1;
        }
        param_3[3] = iStack_10 + param_3[3];
        param_3[2] = iStack_14 + param_3[2];
        if (999999 < param_3[3]) {
          param_3[3] = param_3[3] + -1000000;
          param_3[2] = param_3[2] + 1;
        }
      }
      *param_4 = 4;
      return 0;
    }
  }
  return 4;
}

