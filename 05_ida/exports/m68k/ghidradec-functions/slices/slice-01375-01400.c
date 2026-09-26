/* GHIDRADEC_FUNCTION index=1375 start=0x404a81e */

void _doSwapout(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  
  iVar5 = dword_40B371E;
  iVar4 = dword_40B371A;
  puVar3 = (undefined4 *)(~_page_mask & param_1);
  iVar7 = 0;
  puVar8 = puVar3;
  if (0 < dword_40B371E) {
    do {
      if (puVar8[2] == 0) {
        puVar1 = (undefined4 *)*puVar8;
        puVar2 = (undefined4 *)puVar8[1];
        puVar6 = puVar2;
        if (puVar1 != &dword_40B3712) {
          puVar1[1] = puVar2;
          puVar6 = dword_40B3716;
        }
        dword_40B3716 = puVar6;
        *puVar2 = puVar1;
        dword_40AF7D4 = dword_40AF7D4 + -1;
        dword_40C2330 = dword_40C2330 + -1;
      }
      iVar7 = iVar7 + 1;
      puVar8 = (undefined4 *)(iVar4 + (int)puVar8);
    } while (iVar7 < iVar5);
  }
  *puVar3 = 0xfeedface;
  _vm_map_pageable(_kernel_map,puVar3,~_page_mask & (int)puVar3 + _page_mask + dword_40B371A,1);
  dword_40C2338 = dword_40C2338 + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1376 start=0x404a8c4 */

void _swapoutStack(int param_1)

{
  int iVar1;
  undefined8 **ppuVar2;
  undefined8 *puStack_c;
  
  dword_40C2334 = dword_40C2334 + 1;
  puStack_c = &_stack_queue_lock;
  _lock_write();
  *(undefined4 *)(param_1 + -4) = 1;
  iVar1 = _canSwap((undefined8 *)(param_1 + -0xc));
  ppuVar2 = (undefined8 **)&stack0xfffffff8;
  if (iVar1 != 0) {
    puStack_c = (undefined8 *)(param_1 + -0xc);
    _doSwapout();
    ppuVar2 = &puStack_c;
  }
  *(undefined8 **)((int)ppuVar2 + -4) = &_stack_queue_lock;
  *(undefined4 *)((int)ppuVar2 + -8) = 0x404a90c;
  _lock_done();
  return;
}
/* GHIDRADEC_FUNCTION index=1377 start=0x404a914 */

void _swapinStack(uint param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(~_page_mask & param_1);
  dword_40C2334 = dword_40C2334 + -1;
  _vm_map_pageable(_kernel_map,piVar2,~_page_mask & (int)piVar2 + _page_mask + dword_40B371A,0);
  _lock_write(&_stack_queue_lock);
  *(undefined4 *)(param_1 - 4) = 2;
  if (*piVar2 == -0x1120532) {
    *piVar2 = 0;
    dword_40C2338 = dword_40C2338 + -1;
    iVar1 = 0;
    if (0 < dword_40B371E) {
      do {
        if (piVar2[2] == 0) {
          sub_404A45C(piVar2);
        }
        piVar2 = (int *)(dword_40B371A + (int)piVar2);
        iVar1 = iVar1 + 1;
      } while (iVar1 < dword_40B371E);
    }
  }
  _lock_done(&_stack_queue_lock);
  return;
}
/* GHIDRADEC_FUNCTION index=1378 start=0x404a9c0 */

undefined4 _stack_alloc_try(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  _lock_write(&_stack_queue_lock);
  if (dword_40AF7D4 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    if ((int **)dword_40B3712 == &dword_40B3712) {
      piVar2 = (int *)0x0;
    }
    else {
      *(int ***)(*dword_40B3712 + 4) = &dword_40B3712;
      piVar2 = dword_40B3712;
      dword_40B3712 = (int *)*dword_40B3712;
    }
    piVar2[2] = 2;
    piVar2 = piVar2 + 3;
    dword_40AF7D4 = dword_40AF7D4 + -1;
    dword_40C2330 = dword_40C2330 + -1;
    dword_40C232C = dword_40C232C + 1;
  }
  _lock_done(&_stack_queue_lock);
  if ((piVar2 == (int *)0x0) && (piVar2 = *(int **)(param_1 + 0x2c), piVar2 == (int *)0x0)) {
    uVar1 = 0;
  }
  else {
    _stack_attach(param_1,piVar2,param_2);
    uVar1 = 1;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1379 start=0x404aa5e */

void _stack_alloc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _allocStack();
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aStackAlloc);
  }
  _stack_attach(param_1,iVar1,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=1380 start=0x404aa94 */

void _stack_free(int param_1)

{
  int iVar1;
  
  iVar1 = _stack_detach(param_1);
  if (iVar1 != *(int *)(param_1 + 0x2c)) {
    _freeStack(iVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1381 start=0x404aabe */

void _stack_collect(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1382 start=0x404aac6 */

void _stack_statistics(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  
  _lock_read(&_stack_queue_lock);
  puVar1 = dword_40B3712;
  if (_stack_check_usage != 0) {
    for (; (undefined4 **)puVar1 != &dword_40B3712; puVar1 = (undefined4 *)*puVar1) {
      uVar2 = _stack_usage(puVar1 + 3);
      if (*param_2 < uVar2) {
        *param_2 = uVar2;
      }
    }
  }
  *param_1 = dword_40AF7D4;
  _lock_done(&_stack_queue_lock);
  return;
}
/* GHIDRADEC_FUNCTION index=1383 start=0x404ab32 */

undefined4 _simple_lock_alloc(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=1384 start=0x404ab3c */

void _simple_lock_free(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1385 start=0x404ab44 */

void _lock_alloc(void)

{
  _kalloc(8);
  return;
}
/* GHIDRADEC_FUNCTION index=1386 start=0x404ab56 */

void _lock_free(undefined4 param_1)

{
  _kfree(param_1,8);
  return;
}
/* GHIDRADEC_FUNCTION index=1387 start=0x404ab6c */

void _lock_init(undefined4 *param_1,uint param_2)

{
  _bzero(param_1,8);
  *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) & 0x3f;
  *(undefined2 *)(param_1 + 1) = 0;
  *(uint *)((int)param_1 + 6) = *(uint *)((int)param_1 + 6) & 0xefffffff | (param_2 & 1) << 0x1c;
  *param_1 = 0xffffffff;
  *(word *)((int)param_1 + 6) = *(word *)((int)param_1 + 6) & 0xf000;
  return;
}
/* GHIDRADEC_FUNCTION index=1388 start=0x404abb2 */

void _lock_sleepable(int param_1,byte param_2)

{
  *(uint *)(param_1 + 6) = *(uint *)(param_1 + 6) & 0xefffffff | (param_2 & 1) << 0x1c;
  return;
}
/* GHIDRADEC_FUNCTION index=1389 start=0x404abcc */

void _lock_write(int *param_1)

{
  int iVar1;
  
  if (*param_1 == _active_threads) {
    *(uint *)((int)param_1 + 6) =
         *(uint *)((int)param_1 + 6) & 0xf000ffff |
         ((word)(*(sword *)((int)param_1 + 6) + 1) & 0xfff) << 0x10;
  }
  else {
    while ((*(byte *)((int)param_1 + 6) & 0x40) != 0) {
      if ((0 < _lock_wait_time) && (iVar1 = _lock_wait_time + -1, 0 < iVar1)) {
        do {
          if ((*(byte *)((int)param_1 + 6) & 0x40) == 0) break;
          iVar1 = iVar1 + -1;
        } while (0 < iVar1);
      }
      if ((*(byte *)((int)param_1 + 6) & 0x50) == 0x50) {
        *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 0x20;
        _thread_sleep(param_1,0,0);
      }
    }
    *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 0x40;
    while ((param_1[1] & 0xffff8000U) != 0) {
      if ((0 < _lock_wait_time) && (iVar1 = _lock_wait_time + -1, 0 < iVar1)) {
        do {
          if ((param_1[1] & 0xffff8000U) == 0) break;
          iVar1 = iVar1 + -1;
        } while (0 < iVar1);
      }
      if ((*(byte *)((int)param_1 + 6) & 0x10) != 0) {
        if ((param_1[1] & 0xffff8000U) == 0) {
          return;
        }
        *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 0x20;
        _thread_sleep(param_1,0,0);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1390 start=0x404acae */

void _lock_done(int param_1)

{
  byte bVar1;
  
  if (*(sword *)(param_1 + 4) == 0) {
    if ((*(word *)(param_1 + 6) & 0xfff) == 0) {
      bVar1 = *(byte *)(param_1 + 6);
      if ((char)bVar1 < '\0') {
        bVar1 = bVar1 & 0x7f;
      }
      else {
        bVar1 = bVar1 & 0xbf;
      }
      *(byte *)(param_1 + 6) = bVar1;
    }
    else {
      *(uint *)(param_1 + 6) =
           *(uint *)(param_1 + 6) & 0xf000ffff |
           ((word)(*(word *)(param_1 + 6) + 0xfff) & 0xfff) << 0x10;
    }
  }
  else {
    *(sword *)(param_1 + 4) = *(sword *)(param_1 + 4) + -1;
  }
  if ((*(uint *)(param_1 + 4) & 0xffff2000) == 0x2000) {
    *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) & 0xdf;
    _thread_wakeup_prim(param_1,0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1391 start=0x404ad18 */

void _lock_read(int *param_1)

{
  byte bVar1;
  int iVar2;
  
  if (*param_1 != _active_threads) {
    while ((*(byte *)((int)param_1 + 6) & 0xc0) != 0) {
      if ((0 < _lock_wait_time) && (iVar2 = _lock_wait_time + -1, 0 < iVar2)) {
        do {
          if ((*(byte *)((int)param_1 + 6) & 0xc0) == 0) break;
          iVar2 = iVar2 + -1;
        } while (0 < iVar2);
      }
      bVar1 = *(byte *)((int)param_1 + 6);
      if ((bVar1 & 0x10) != 0) {
        if ((bVar1 & 0xc0) == 0) break;
        *(byte *)((int)param_1 + 6) = bVar1 | 0x20;
        _thread_sleep(param_1,0,0);
      }
    }
  }
  *(sword *)(param_1 + 1) = *(sword *)(param_1 + 1) + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1392 start=0x404ad8e */

undefined4 _lock_read_to_write(int *param_1)

{
  byte bVar1;
  int iVar2;
  
  *(sword *)(param_1 + 1) = *(sword *)(param_1 + 1) + -1;
  if (*param_1 == _active_threads) {
    *(uint *)((int)param_1 + 6) =
         *(uint *)((int)param_1 + 6) & 0xf000ffff |
         ((word)(*(sword *)((int)param_1 + 6) + 1) & 0xfff) << 0x10;
  }
  else {
    bVar1 = *(byte *)((int)param_1 + 6);
    if ((char)bVar1 < '\0') {
      if ((param_1[1] & 0xffff2000U) == 0x2000) {
        *(byte *)((int)param_1 + 6) = bVar1 & 0xdf;
        _thread_wakeup_prim(param_1,0,0);
      }
      return 1;
    }
    *(byte *)((int)param_1 + 6) = bVar1 | 0x80;
    while (*(sword *)(param_1 + 1) != 0) {
      if ((0 < _lock_wait_time) && (iVar2 = _lock_wait_time + -1, 0 < iVar2)) {
        do {
          if (*(sword *)(param_1 + 1) == 0) break;
          iVar2 = iVar2 + -1;
        } while (0 < iVar2);
      }
      if ((*(byte *)((int)param_1 + 6) & 0x10) != 0) {
        if (*(sword *)(param_1 + 1) == 0) {
          return 0;
        }
        *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 0x20;
        _thread_sleep(param_1,0,0);
      }
    }
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1393 start=0x404ae46 */

void _lock_write_to_read(int param_1)

{
  byte bVar1;
  
  *(sword *)(param_1 + 4) = *(sword *)(param_1 + 4) + 1;
  if ((*(word *)(param_1 + 6) & 0xfff) == 0) {
    bVar1 = *(byte *)(param_1 + 6);
    if ((char)bVar1 < '\0') {
      bVar1 = bVar1 & 0x7f;
    }
    else {
      bVar1 = bVar1 & 0xbf;
    }
    *(byte *)(param_1 + 6) = bVar1;
  }
  else {
    *(uint *)(param_1 + 6) =
         *(uint *)(param_1 + 6) & 0xf000ffff |
         ((word)(*(word *)(param_1 + 6) + 0xfff) & 0xfff) << 0x10;
  }
  if ((*(byte *)(param_1 + 6) & 0x20) != 0) {
    *(byte *)(param_1 + 6) = *(byte *)(param_1 + 6) & 0xdf;
    _thread_wakeup_prim(param_1,0,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1394 start=0x404aea2 */

undefined4 _lock_try_write(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == _active_threads) {
    *(uint *)((int)param_1 + 6) =
         *(uint *)((int)param_1 + 6) & 0xf000ffff |
         ((word)(*(sword *)((int)param_1 + 6) + 1) & 0xfff) << 0x10;
    uVar1 = 1;
  }
  else if ((param_1[1] & 0xffffc000U) == 0) {
    *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 0x40;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1395 start=0x404aee4 */

undefined4 _lock_try_read(int *param_1)

{
  undefined4 uVar1;
  
  if ((*param_1 == _active_threads) || ((*(byte *)((int)param_1 + 6) & 0xc0) == 0)) {
    *(sword *)(param_1 + 1) = *(sword *)(param_1 + 1) + 1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1396 start=0x404af0e */

undefined4 _lock_try_read_to_write(int *param_1)

{
  sword sVar1;
  
  if (*param_1 == _active_threads) {
    *(sword *)(param_1 + 1) = *(sword *)(param_1 + 1) + -1;
    *(uint *)((int)param_1 + 6) =
         *(uint *)((int)param_1 + 6) & 0xf000ffff |
         ((word)(*(sword *)((int)param_1 + 6) + 1) & 0xfff) << 0x10;
  }
  else {
    if ((char)*(byte *)((int)param_1 + 6) < '\0') {
      return 0;
    }
    *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 0x80;
    sVar1 = *(sword *)(param_1 + 1);
    *(sword *)(param_1 + 1) = sVar1 + -1;
    if (sVar1 != 1) {
      do {
        *(byte *)((int)param_1 + 6) = *(byte *)((int)param_1 + 6) | 0x20;
        _thread_sleep(param_1,0,0);
      } while (*(sword *)(param_1 + 1) != 0);
    }
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=1397 start=0x404af82 */

void _lock_set_recursive(undefined4 *param_1)

{
  if ((*(byte *)((int)param_1 + 6) & 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aLockSetRecursi);
  }
  *param_1 = _active_threads;
  return;
}
/* GHIDRADEC_FUNCTION index=1398 start=0x404afae */

void _lock_clear_recursive(int *param_1)

{
  if (*param_1 != _active_threads) {
                    /* WARNING: Subroutine does not return */
    _panic(aLockClearRecur);
  }
  if ((*(uint *)((int)param_1 + 6) & 0xfffffff) >> 0x10 == 0) {
    *param_1 = -1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1399 start=0x404afe2 */

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

