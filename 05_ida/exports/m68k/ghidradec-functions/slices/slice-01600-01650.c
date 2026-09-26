/* GHIDRADEC_FUNCTION index=1600 start=0x4052672 */

undefined4 _task_suspend_nowait(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x3c);
    *(int *)(param_1 + 0x3c) = iVar2 + 1;
    if (iVar2 == 0) {
      iVar2 = _task_hold(param_1);
      if (iVar2 != 0) {
        return 5;
      }
      if (param_1 == *(int *)(_active_threads + 0xc)) {
        _thread_hold(_active_threads);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1601 start=0x40526cc */

undefined4 _task_assign(void)

{
  return 5;
}
/* GHIDRADEC_FUNCTION index=1602 start=0x40526d6 */

void _task_assign_default(undefined4 param_1,undefined4 param_2)

{
  _task_assign(param_1,_default_pset,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=1603 start=0x40526f2 */

undefined4 _task_get_assignment(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 5;
  }
  else {
    *param_2 = *(undefined4 *)(param_1 + 0x24);
    _pset_reference(*param_2);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1604 start=0x405271a */

undefined4 _task_priority(int param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((param_1 == 0) || (0x1f < param_2)) {
    uVar3 = 4;
  }
  else {
    *(uint *)(param_1 + 0x40) = param_2;
    if (param_3 != 0) {
      for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)(param_1 + 0x18);
          puVar1 = (undefined4 *)puVar1[4]) {
        iVar2 = _thread_priority(puVar1,param_2,0);
        if (iVar2 != 0) {
          uVar3 = 5;
        }
      }
    }
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1605 start=0x4052778 */

undefined4 _current_task_EXTERNAL(void)

{
  return *(undefined4 *)(_active_threads + 0xc);
}
/* GHIDRADEC_FUNCTION index=1606 start=0x405278a */

undefined4 _current_map_EXTERNAL(void)

{
  return *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
}
/* GHIDRADEC_FUNCTION index=1607 start=0x40527a0 */

void _stack_privilege(int param_1)

{
  if (param_1 != _active_threads) {
                    /* WARNING: Subroutine does not return */
    _panic(aStackPrivilege);
  }
  if (*(int *)(param_1 + 0x2c) == 0) {
    *(undefined4 *)(param_1 + 0x2c) = _active_stacks;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1608 start=0x40527d4 */

void _thread_init(void)

{
  _thread_zone = _zinit(0x184,0x30800,0x6100,0,&aThreads);
  dword_40C29E8 = 0;
  dword_40C2A00 = 2;
  dword_40C2A04 = 0;
  dword_40C2A08 = 0;
  dword_40C2A0C = 0;
  dword_40C2A18 = 0;
  dword_40C2A20 = 0;
  dword_40C2A24 = 0;
  dword_40C2A28 = 0x102;
  dword_40C2A10 = _thread_bootstrap_return;
  dword_40C2A14 = 0;
  dword_40C2A30 = 0x12;
  dword_40C2A38 = 0;
  dword_40C2A3C = 1;
  dword_40C2A40 = 0xffffffff;
  dword_40C2A44 = 0;
  dword_40C2A48 = 0;
  dword_40C2A50 = 0;
  dword_40C2A54 = 0;
  dword_40C2A58 = 0;
  dword_40C2A5C = 0;
  dword_40C2A64 = 0xffffffff;
  dword_40C2A68 = 1;
  _timer_init(unk_40C2AB8);
  _timer_init(unk_40C2AC8);
  dword_40C2AD8 = 0;
  dword_40C2ADC = 0;
  dword_40C2AE0 = 0;
  dword_40C2AE4 = 0;
  dword_40C2AE8 = 0;
  dword_40C2AEC = 0;
  dword_40C2B50 = 0;
  dword_40C2B54 = 0;
  dword_40C2B5C = 0;
  dword_40C2B60 = 0;
  _initKernelStacks();
  dword_40B67C4 = &_reaper_queue;
  _reaper_queue = &_reaper_queue;
  _pcb_module_init();
  return;
}
/* GHIDRADEC_FUNCTION index=1609 start=0x405290c */

undefined4 _thread_create(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  
  if (param_1 == (int *)0x0) {
    uVar2 = 4;
  }
  else {
    iVar3 = _zalloc(_thread_zone);
    if (iVar3 == 0) {
      uVar2 = 6;
    }
    else {
      _bcopy(&_thread_template,iVar3,0x184);
      *(int **)(iVar3 + 0xc) = param_1;
      *(undefined4 *)(iVar3 + 0x6c) = _sched_tick;
      _thread_timeout_setup(iVar3);
      _pcb_init(iVar3);
      _ipc_thread_init(iVar3);
      uVar2 = _zalloc(_u_thread_zone);
      *(undefined4 *)(iVar3 + 0x80) = uVar2;
      _uarea_zero(iVar3);
      _uarea_init(iVar3);
      puVar5 = (undefined *)param_1[9];
      _pset_reference(puVar5);
      while( true ) {
        puVar4 = (undefined *)param_1[9];
        if (*(int *)(puVar4 + 0x148) == 0) {
          puVar4 = _default_pset;
        }
        if (puVar5 == puVar4) break;
        _pset_reference(puVar4);
        _pset_deallocate(puVar5);
        puVar5 = puVar4;
      }
      *(int *)(iVar3 + 0x4c) = param_1[0x10];
      if (*(int *)(puVar5 + 0x154) < *(int *)(iVar3 + 0x50)) {
        *(int *)(iVar3 + 0x50) = *(int *)(puVar5 + 0x154);
      }
      if (*(int *)(iVar3 + 0x50) < *(int *)(iVar3 + 0x4c)) {
        *(int *)(iVar3 + 0x4c) = *(int *)(iVar3 + 0x50);
      }
      _compute_priority(iVar3,1);
      *(int *)(iVar3 + 0x3c) = param_1[5] + 1;
      _pset_add_thread(puVar5,iVar3);
      if (*(int *)(puVar5 + 0x120) != 0) {
        *(int *)(iVar3 + 0x3c) = *(int *)(iVar3 + 0x3c) + 1;
      }
      *param_1 = *param_1 + 1;
      param_1[8] = param_1[8] + 1;
      piVar1 = (int *)param_1[7];
      if (piVar1 == param_1 + 6) {
        *piVar1 = iVar3;
      }
      else {
        piVar1[4] = iVar3;
      }
      *(int **)(iVar3 + 0x14) = piVar1;
      *(int **)(iVar3 + 0x10) = param_1 + 6;
      param_1[7] = iVar3;
      *(undefined4 *)(iVar3 + 0x170) = 1;
      if (param_1[1] == 0) {
        _thread_terminate(iVar3);
        _thread_deallocate(iVar3);
        uVar2 = 5;
      }
      else {
        _ipc_thread_enable(iVar3);
        _nthreads = _nthreads + 1;
        *param_2 = iVar3;
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1610 start=0x4052a96 */

void _thread_deallocate(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x20);
    *(int *)(param_1 + 0x20) = iVar1 + -1;
    if (iVar1 == 1 || iVar1 + -1 < 0) {
      *(undefined4 *)(param_1 + 0x20) = 1;
      uVar2 = *(undefined4 *)(param_1 + 0x178);
      iVar1 = *(int *)(param_1 + 0xc);
      iVar3 = *(int *)(param_1 + 0x20);
      *(int *)(param_1 + 0x20) = iVar3 + -1;
      if (iVar3 == 1 || iVar3 + -1 < 0) {
        if (*(int *)(param_1 + 0x13c) != 0) {
          _reset_timeout(param_1 + 0x110);
        }
        if (*(int *)(param_1 + 0x16c) != 0) {
          _reset_timeout(param_1 + 0x140);
        }
        *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
        _thread_read_times(param_1,&iStack_c,&iStack_14);
        *(int *)(iVar1 + 0x50) = iStack_8 + *(int *)(iVar1 + 0x50);
        *(int *)(iVar1 + 0x4c) = iStack_c + *(int *)(iVar1 + 0x4c);
        if (999999 < *(int *)(iVar1 + 0x50)) {
          *(int *)(iVar1 + 0x50) = *(int *)(iVar1 + 0x50) + -1000000;
          *(int *)(iVar1 + 0x4c) = *(int *)(iVar1 + 0x4c) + 1;
        }
        *(int *)(iVar1 + 0x58) = iStack_10 + *(int *)(iVar1 + 0x58);
        *(int *)(iVar1 + 0x54) = iStack_14 + *(int *)(iVar1 + 0x54);
        if (999999 < *(int *)(iVar1 + 0x58)) {
          *(int *)(iVar1 + 0x58) = *(int *)(iVar1 + 0x58) + -1000000;
          *(int *)(iVar1 + 0x54) = *(int *)(iVar1 + 0x54) + 1;
        }
        *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + -1;
        iVar3 = *(int *)(param_1 + 0x10);
        piVar4 = *(int **)(param_1 + 0x14);
        if (iVar3 == iVar1 + 0x18) {
          *(int **)(iVar1 + 0x1c) = piVar4;
        }
        else {
          *(int **)(iVar3 + 0x14) = piVar4;
        }
        if (piVar4 == (int *)(iVar1 + 0x18)) {
          *piVar4 = iVar3;
        }
        else {
          piVar4[4] = iVar3;
        }
        _pset_remove_thread(uVar2,param_1);
        _pset_deallocate(uVar2);
        if (*(int *)(param_1 + 0x78) != 0) {
          _kmem_free(_kernel_map,*(int *)(param_1 + 0x78),_page_size);
        }
        if (*(int *)(param_1 + 0x7c) != 0) {
          _vm_object_deallocate(*(int *)(param_1 + 0x7c));
        }
        if (param_1 == _active_threads) {
                    /* WARNING: Subroutine does not return */
          _panic(aThreadDealloca);
        }
        if ((*(uint *)(param_1 + 0x48) & 0xfffffeeb) != 2) {
                    /* WARNING: Subroutine does not return */
          _panic(aUnstoppedThrea);
        }
        _task_deallocate(*(undefined4 *)(param_1 + 0xc));
        if ((*(byte *)(param_1 + 0x4a) & 1) == 0) {
          _stack_free(param_1);
          _thread_deallocate_stack = _thread_deallocate_stack + 1;
        }
        if (*(int *)(param_1 + 0x2c) != 0) {
          _freeStack(*(int *)(param_1 + 0x2c));
        }
        _pcb_terminate(param_1);
        _nthreads = _nthreads + -1;
        _uthread_free(*(undefined4 *)(param_1 + 0x80));
        _zfree(_thread_zone,param_1);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1611 start=0x4052cae */

void _thread_deallocate_interrupt(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    iVar1 = param_1[8];
    param_1[8] = iVar1 + -1;
    if (iVar1 == 1 || iVar1 + -1 < 0) {
      param_1[8] = 1;
      *param_1 = &_reaper_queue;
      param_1[1] = dword_40B67C4;
      *(undefined4 **)param_1[1] = param_1;
      dword_40B67C4 = param_1;
      _thread_wakeup_prim(&_reaper_queue,0,0);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1612 start=0x4052d20 */

void _thread_reference(int param_1)

{
  if (param_1 != 0) {
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1613 start=0x4052d40 */

undefined4 _thread_terminate(int param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = _active_threads;
  if (param_1 == 0) {
    uVar3 = 4;
  }
  else {
    _ipc_thread_disable(param_1);
    if (iVar2 == param_1) {
      if (*(int *)(param_1 + 0x170) != 0) {
        *(undefined4 *)(param_1 + 0x170) = 0;
        *(uint *)(param_1 + 0x174) = *(uint *)(param_1 + 0x174) | 2;
      }
      _need_ast = _need_ast | 2;
      if (_need_ast != 0) {
        pbVar1 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
        *pbVar1 = *pbVar1 | 0x10;
      }
      uVar3 = 0;
    }
    else {
      if ((*(int *)(*(int *)(_active_threads + 0xc) + 4) == 0) || (*(int *)(iVar2 + 0x170) == 0)) {
        _thread_terminate(iVar2);
      }
      else if (*(int *)(param_1 + 0x170) != 0) {
        *(undefined4 *)(param_1 + 0x170) = 0;
        _thread_halt(param_1,1);
        _ipc_thread_terminate(param_1);
        _thread_deallocate(param_1);
        return 0;
      }
      uVar3 = 5;
    }
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1614 start=0x4052e1a */

void _thread_force_terminate(int param_1)

{
  int iVar1;
  
  _ipc_thread_disable(param_1);
  iVar1 = *(int *)(param_1 + 0x170);
  *(undefined4 *)(param_1 + 0x170) = 0;
  _thread_halt(param_1,1);
  _ipc_thread_terminate(param_1);
  if (iVar1 != 0) {
    _thread_deallocate(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1615 start=0x4052e74 */

int _thread_halt(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if (_active_threads == param_1) {
                    /* WARNING: Subroutine does not return */
    _panic(aThreadHaltTryi);
  }
  if (param_2 == 0) {
    if ((*(byte *)(param_1 + 0x4b) & 0x10) != 0) {
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
      return 0;
    }
    if ((*(byte *)(_active_threads + 0x177) & 1) != 0) {
      _thread_wakeup_prim(_active_threads + 0x44,0,2);
      return 5;
    }
  }
  else if ((*(byte *)(param_1 + 0x4b) & 0x10) != 0) {
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
    return 0;
  }
  *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
  uVar1 = *(uint *)(param_1 + 0x48);
  *(uint *)(param_1 + 0x48) = uVar1 | 2;
  if (((*(byte *)(param_1 + 0x177) & 1) != 0) && ((uVar1 & 0x10) == 0)) {
    do {
      *(undefined4 *)(param_1 + 0x44) = 1;
      _thread_sleep(param_1 + 0x44,0,1);
      if ((*(byte *)(param_1 + 0x4b) & 0x10) != 0) {
        return 0;
      }
      if ((*(int *)(_active_threads + 0x40) != 0) && (param_2 == 0)) {
        _thread_release(param_1);
        return 5;
      }
    } while ((*(byte *)(param_1 + 0x177) & 1) != 0);
  }
  *(uint *)(param_1 + 0x174) = *(uint *)(param_1 + 0x174) | 1;
  while( true ) {
    iVar2 = _thread_dowait(param_1,param_2);
    if (iVar2 != 0) {
      *(uint *)(param_1 + 0x174) = *(uint *)(param_1 + 0x174) & 0xfffffffe;
      _thread_wakeup_prim(param_1 + 0x44,0,2);
      _thread_release(param_1);
      return iVar2;
    }
    _clear_wait(param_1,2,1);
    if ((*(byte *)(param_1 + 0x4b) & 0x10) != 0) break;
    if ((((*(code **)(param_1 + 0x30) == _mach_msg_continue) ||
         (*(code **)(param_1 + 0x30) == _mach_msg_receive_continue)) &&
        (iVar2 = _mach_msg_interrupt(param_1), iVar2 != 0)) ||
       ((*(code **)(param_1 + 0x30) == _thread_exception_return ||
        (*(code **)(param_1 + 0x30) == _thread_bootstrap_return)))) {
      *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 0x10;
      *(uint *)(param_1 + 0x174) = *(uint *)(param_1 + 0x174) & 0xfffffffe;
      return 0;
    }
    if ((*(uint *)(param_1 + 0x48) & 0xf) != 2) {
                    /* WARNING: Subroutine does not return */
      _panic(aThreadHalt);
    }
    *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 0xc;
    _thread_setrun(param_1,0);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1616 start=0x4053072 */

void _walking_zombie(void)

{
                    /* WARNING: Subroutine does not return */
  _panic(aTheZombieWalks);
}
/* GHIDRADEC_FUNCTION index=1617 start=0x4053086 */

void _thread_halt_self_with_continuation(undefined4 *param_1)

{
  undefined4 *puVar1;
  code **ppcVar2;
  code *pcStack_1c;
  undefined4 *puStack_18;
  undefined4 *puStack_14;
  undefined4 *puStack_10;
  
  puVar1 = _active_threads;
  if ((*(byte *)((int)_active_threads + 0x177) & 2) == 0) {
    _active_threads[0x12] = _active_threads[0x12] | 0x10;
    puVar1[0x5d] = puVar1[0x5d] & 0xfffffffe;
    ppcVar2 = (code **)&puStack_10;
    puStack_10 = param_1;
  }
  else {
    puStack_10 = _active_threads;
    puStack_14 = (undefined4 *)0x40530a4;
    _ipc_thread_terminate();
    puStack_14 = puVar1;
    puStack_18 = (undefined4 *)0x40530ac;
    _thread_hold();
    *puVar1 = &_reaper_queue;
    puVar1[1] = dword_40B67C4;
    *(undefined4 **)puVar1[1] = puVar1;
    dword_40B67C4 = puVar1;
    puVar1[0x12] = puVar1[0x12] | 0x10;
    puStack_10 = (undefined4 *)0x0;
    puStack_14 = (undefined4 *)0x0;
    puStack_18 = &_reaper_queue;
    pcStack_1c = (code *)0x40530ec;
    _thread_wakeup_prim();
    ppcVar2 = &pcStack_1c;
    pcStack_1c = _walking_zombie;
  }
  *(undefined4 *)((int)ppcVar2 + -4) = 0x4053118;
  _thread_block_with_continuation();
  return;
}
/* GHIDRADEC_FUNCTION index=1618 start=0x4053124 */

void _thread_halt_self(void)

{
  code *pcVar1;
  code **ppcVar2;
  code *pcStack_1c;
  undefined4 *puStack_18;
  code *pcStack_14;
  code *pcStack_10;
  
  pcVar1 = _active_threads;
  if (((byte)_active_threads[0x177] & 2) == 0) {
    *(uint *)(_active_threads + 0x48) = *(uint *)(_active_threads + 0x48) | 0x10;
    *(uint *)(pcVar1 + 0x174) = *(uint *)(pcVar1 + 0x174) & 0xfffffffe;
    ppcVar2 = &pcStack_10;
    pcStack_10 = _thread_exception_return;
  }
  else {
    pcStack_10 = _active_threads;
    pcStack_14 = (code *)0x4053142;
    _ipc_thread_terminate();
    pcStack_14 = pcVar1;
    puStack_18 = (undefined4 *)0x405314a;
    _thread_hold();
    *(undefined4 **)pcVar1 = &_reaper_queue;
    *(code **)(pcVar1 + 4) = dword_40B67C4;
    **(undefined4 **)(pcVar1 + 4) = pcVar1;
    dword_40B67C4 = pcVar1;
    *(uint *)(pcVar1 + 0x48) = *(uint *)(pcVar1 + 0x48) | 0x10;
    pcStack_10 = (code *)0x0;
    pcStack_14 = (code *)0x0;
    puStack_18 = &_reaper_queue;
    pcStack_1c = (code *)0x405318a;
    _thread_wakeup_prim();
    ppcVar2 = &pcStack_1c;
    pcStack_1c = _walking_zombie;
  }
  *(undefined4 *)((int)ppcVar2 + -4) = 0x40531b8;
  _thread_block_with_continuation();
  return;
}
/* GHIDRADEC_FUNCTION index=1619 start=0x40531c4 */

byte _thread_hold(int param_1)

{
  int unaff_D2;
  char in_XF;
  
  *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 2;
  return in_XF << 4 | (unaff_D2 < 0) << 3 | (unaff_D2 == 0) << 2;
}
/* GHIDRADEC_FUNCTION index=1620 start=0x40531ec */

undefined4 _thread_dowait(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_1 == _active_threads) {
                    /* WARNING: Subroutine does not return */
    _panic(aThreadDowait);
  }
  iVar2 = 0;
  do {
    switch(*(uint *)(param_1 + 0x48) & 0xf) {
    :
      goto loc_40532C2;
    case :
      iVar1 = _rem_runq(param_1);
      if (iVar1 != 0) {
        *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffffb;
        iVar2 = *(int *)(param_1 + 0x44);
        *(undefined4 *)(param_1 + 0x44) = 0;
        goto loc_40532C2;
      }
      break;
    case :
    case :
    case :
    case :
      break;
    }
    *(undefined4 *)(param_1 + 0x44) = 1;
    _thread_sleep(param_1 + 0x44,0,1);
  } while ((*(int *)(_active_threads + 0x40) == 0) || (param_2 != 0));
  uVar3 = 5;
loc_40532C2:
  if (iVar2 != 0) {
    _thread_wakeup_prim(param_1 + 0x44,0,0);
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1621 start=0x40532e4 */

undefined4 _thread_release(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 extraout_D0u;
  undefined4 in_D0;
  char cVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  byte bVar8;
  
  uVar3 = (undefined2)((uint)in_D0 >> 0x10);
  uVar1 = *(uint *)(param_1 + 0x3c);
  *(uint *)(param_1 + 0x3c) = uVar1 - 1;
  cVar7 = 1 < uVar1;
  cVar6 = SBORROW4(1,uVar1);
  cVar4 = (int)(1 - uVar1) < 0;
  cVar5 = '\0';
  bVar8 = cVar7;
  if (uVar1 == 1) {
    uVar1 = *(uint *)(param_1 + 0x48);
    uVar2 = uVar1 & 0xffffffed;
    *(uint *)(param_1 + 0x48) = uVar2;
    cVar6 = '\0';
    bVar8 = 0;
    uVar3 = 0;
    cVar4 = '\0';
    cVar5 = '\0';
    if ((uVar1 & 5) == 0) {
      *(uint *)(param_1 + 0x48) = uVar2 | 4;
      cVar4 = param_1 < 0;
      cVar5 = param_1 == 0;
      cVar6 = '\0';
      bVar8 = 0;
      _thread_setrun(param_1,1);
      uVar3 = extraout_D0u;
    }
  }
  return CONCAT22(uVar3,(word)(byte)(cVar7 << 4 | cVar4 << 3 | cVar5 << 2 | cVar6 << 1 | bVar8));
}
/* GHIDRADEC_FUNCTION index=1622 start=0x4053340 */

undefined4 _thread_suspend(int param_1)

{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  
  if (param_1 == 0) {
    uVar3 = 4;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x88);
    *(int *)(param_1 + 0x88) = iVar1 + 1;
    if (iVar1 == 0) {
      *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
      *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 2;
      if (param_1 == _active_threads) {
        _need_ast = _need_ast | 4;
        if (_need_ast != 0) {
          pbVar2 = (byte *)(*(int *)(_active_threads + 0x24) + 0x54);
          *pbVar2 = *pbVar2 | 0x10;
        }
      }
      else {
        _thread_dowait(param_1,1);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1623 start=0x40533d6 */

undefined4 _thread_resume(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (param_1 == 0) {
    uVar4 = 4;
  }
  else {
    uVar4 = 0;
    iVar1 = *(int *)(param_1 + 0x88);
    if (iVar1 < 1) {
      uVar4 = 5;
    }
    else {
      *(int *)(param_1 + 0x88) = iVar1 + -1;
      if ((iVar1 == 1) &&
         (iVar1 = *(int *)(param_1 + 0x3c), *(int *)(param_1 + 0x3c) = iVar1 + -1, iVar1 == 1)) {
        uVar2 = *(uint *)(param_1 + 0x48);
        uVar3 = uVar2 & 0xffffffed;
        *(uint *)(param_1 + 0x48) = uVar3;
        if ((uVar2 & 5) == 0) {
          *(uint *)(param_1 + 0x48) = uVar3 | 4;
          _thread_setrun(param_1,1);
        }
      }
    }
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=1624 start=0x4053456 */

undefined4 _thread_get_state(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_1 == _active_threads)) {
    uVar1 = 4;
  }
  else {
    _thread_hold(param_1);
    _thread_dowait(param_1,1);
    uVar1 = _thread_getstatus(param_1,param_2,param_3,param_4);
    _thread_release(param_1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1625 start=0x40534b0 */

undefined4 _thread_set_state(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (param_1 == _active_threads)) {
    uVar1 = 4;
  }
  else {
    _thread_hold(param_1);
    _thread_dowait(param_1,1);
    uVar1 = _thread_setstatus(param_1,param_2,param_3,param_4);
    _thread_release(param_1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1626 start=0x405350a */

undefined4 _thread_info(int param_1,int param_2,undefined4 *param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
loc_40536C6:
    uVar2 = 4;
  }
  else {
    if (param_2 == 1) {
      if (*param_4 < 0xb) goto loc_40536C6;
      if (((*(byte *)(param_1 + 0x4b) & 4) == 0) && (*(int *)(param_1 + 0x6c) != _sched_tick)) {
        _update_priority(param_1);
      }
      _thread_read_times(param_1,param_3,param_3 + 2);
      param_3[5] = *(undefined4 *)(param_1 + 0x4c);
      param_3[6] = *(undefined4 *)(param_1 + 0x54);
      uVar3 = ((*(uint *)(param_1 + 100) / 1000) * 3) / 5;
      param_3[4] = uVar3;
      param_3[4] = (int)(uVar3 * 1000000) / _sched_usec;
      if ((*(uint *)(param_1 + 0x48) & 0x100) == 0) {
        uVar2 = 0;
        if ((char)*(uint *)(param_1 + 0x48) < '\0') {
          uVar2 = 2;
        }
      }
      else {
        uVar2 = 1;
      }
      uVar3 = *(uint *)(param_1 + 0x48);
      if ((uVar3 & 0x10) == 0) {
        if ((uVar3 & 4) == 0) {
          if ((uVar3 & 8) == 0) {
            if ((uVar3 & 2) == 0) {
              iVar1 = 0;
              if ((uVar3 & 1) != 0) {
                iVar1 = 3;
              }
            }
            else {
              iVar1 = 2;
            }
          }
          else {
            iVar1 = 4;
          }
        }
        else {
          iVar1 = 1;
        }
      }
      else {
        iVar1 = 5;
      }
      param_3[7] = iVar1;
      param_3[8] = uVar2;
      param_3[9] = *(undefined4 *)(param_1 + 0x88);
      if (iVar1 == 1) {
        param_3[10] = 0;
      }
      else {
        param_3[10] = _sched_tick - *(int *)(param_1 + 0x6c);
      }
      uVar3 = 0xb;
    }
    else {
      if ((param_2 != 2) || (*param_4 < 7)) goto loc_40536C6;
      *param_3 = *(undefined4 *)(param_1 + 0x5c);
      if ((*(int *)(param_1 + 0x5c) == 2) || (*(int *)(param_1 + 0x5c) == 4)) {
        param_3[1] = (_tick * *(int *)(param_1 + 0x58)) / 1000;
      }
      else {
        param_3[1] = 0;
      }
      param_3[2] = *(undefined4 *)(param_1 + 0x4c);
      param_3[3] = *(undefined4 *)(param_1 + 0x50);
      param_3[4] = *(undefined4 *)(param_1 + 0x54);
      param_3[5] = (uint)CARRY4(~*(uint *)(param_1 + 0x60),~*(uint *)(param_1 + 0x60));
      param_3[6] = *(undefined4 *)(param_1 + 0x60);
      uVar3 = 7;
    }
    *param_4 = uVar3;
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1627 start=0x40536d2 */

undefined4 _thread_abort(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 == 0) || (param_1 == _active_threads)) {
    uVar1 = 4;
  }
  else {
    iVar2 = _thread_halt(param_1,0);
    if (iVar2 == 0) {
      _mach_msg_abort_rpc(param_1);
      _thread_release(param_1);
      if (*(int *)(param_1 + 0x60) != -1) {
        _thread_depress_abort(param_1);
      }
      uVar1 = 0;
    }
    else {
      uVar1 = 0xe;
    }
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1628 start=0x405372c */

void _thread_start(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x30) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=1629 start=0x405373e */

int _kernel_thread(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iStack_8;
  
  _thread_create(param_1,&iStack_8);
  _thread_deallocate(iStack_8);
  _thread_start(iStack_8,param_2);
  *(undefined4 *)(iStack_8 + 0xbc) = param_3;
  _thread_doswapin(iStack_8);
  *(undefined4 *)(iStack_8 + 0x50) = 0x1f;
  *(undefined4 *)(iStack_8 + 0x4c) = 0x18;
  *(undefined4 *)(iStack_8 + 0x54) = 0x18;
  _thread_resume(iStack_8);
  return iStack_8;
}
/* GHIDRADEC_FUNCTION index=1630 start=0x40537ae */

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
/* GHIDRADEC_FUNCTION index=1631 start=0x405382c */

void _reaper_thread(void)

{
                    /* WARNING: Subroutine does not return */
  _reaper_thread_continue();
}
/* GHIDRADEC_FUNCTION index=1632 start=0x405383a */

undefined4 _thread_assign(void)

{
  return 5;
}
/* GHIDRADEC_FUNCTION index=1633 start=0x4053844 */

void _thread_assign_default(undefined4 param_1)

{
  _thread_assign(param_1,_default_pset);
  return;
}
/* GHIDRADEC_FUNCTION index=1634 start=0x405385c */

undefined4 _thread_get_assignment(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x178);
  _pset_reference(*param_2);
  return 0;
}
/* GHIDRADEC_FUNCTION index=1635 start=0x405387a */

undefined4 _thread_priority(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 == 0) || (0x1f < param_2)) {
    uVar1 = 4;
  }
  else if (*(int *)(param_1 + 0x50) < (int)param_2) {
    uVar1 = 5;
  }
  else {
    if (*(int *)(param_1 + 0x60) < 0) {
      *(uint *)(param_1 + 0x4c) = param_2;
      _compute_priority(param_1,1);
    }
    else {
      *(uint *)(param_1 + 0x60) = param_2;
    }
    if (param_3 != 0) {
      *(uint *)(param_1 + 0x50) = param_2;
    }
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1636 start=0x40538e4 */

byte _thread_set_own_priority(uint param_1)

{
  int iVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  char cVar5;
  byte bVar6;
  
  iVar1 = _active_threads;
  cVar5 = param_1 < *(uint *)(_active_threads + 0x50);
  if ((int)param_1 < (int)*(uint *)(_active_threads + 0x50)) {
    *(uint *)(_active_threads + 0x50) = param_1;
  }
  *(uint *)(iVar1 + 0x4c) = param_1;
  cVar2 = iVar1 < 0;
  cVar3 = iVar1 == 0;
  cVar4 = '\0';
  bVar6 = 0;
  _compute_priority(iVar1,1);
  return cVar5 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar6;
}
/* GHIDRADEC_FUNCTION index=1637 start=0x4053924 */

undefined4 _thread_max_priority(int param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (((param_1 == 0) || (param_2 == 0)) || (0x1f < param_3)) {
    uVar1 = 4;
  }
  else {
    *(uint *)(param_1 + 0x50) = param_3;
    if ((int)param_3 < *(int *)(param_1 + 0x4c)) {
      *(uint *)(param_1 + 0x4c) = param_3;
      _compute_priority(param_1,1);
    }
    else if ((-1 < *(int *)(param_1 + 0x60)) && ((int)param_3 < *(int *)(param_1 + 0x60))) {
      *(uint *)(param_1 + 0x60) = param_3;
    }
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1638 start=0x405398e */

undefined4 _thread_policy(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 == 0) || (3 < param_2 - 1)) {
    uVar1 = 4;
  }
  else if (param_2 == *(uint *)(param_1 + 0x5c)) {
    if (param_2 == 2) {
      param_3 = param_3 * 1000;
      if (param_3 % _tick != 0) {
        param_3 = _tick + param_3;
      }
      *(int *)(param_1 + 0x58) = param_3 / _tick;
    }
  }
  else if ((param_2 & *(uint *)(*(int *)(param_1 + 0x178) + 0x158)) == 0) {
    uVar1 = 5;
  }
  else {
    *(uint *)(param_1 + 0x5c) = param_2;
    if (param_2 == 2) {
      param_3 = param_3 * 1000;
      if (param_3 % _tick != 0) {
        param_3 = _tick + param_3;
      }
      *(int *)(param_1 + 0x58) = param_3 / _tick;
    }
    _compute_priority(param_1,1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1639 start=0x4053a60 */

undefined4 _thread_wire(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_2 != _active_threads)) {
    uVar1 = 4;
  }
  else {
    if (param_3 == 0) {
      *(undefined4 *)(param_2 + 0x74) = 0;
      *(undefined4 *)(param_2 + 0x2c) = 0;
    }
    else {
      *(undefined4 *)(param_2 + 0x74) = 1;
      _stack_privilege(param_2);
    }
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1640 start=0x4053ab6 */

void _thread_collect_scan(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1641 start=0x4053abe */

void _consider_thread_collect(void)

{
  if (_thread_collect_max_rate == 0) {
    _thread_collect_max_rate = _hz;
  }
  if ((_thread_collect_allowed != 0) &&
     (_thread_collect_max_rate + _thread_collect_last_tick < _sched_tick)) {
    _thread_collect_last_tick = _sched_tick;
    _thread_collect_scan();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1642 start=0x4053b02 */

int _stack_usage(int *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if (*param_1 != -0x21524111) break;
    param_1 = param_1 + 1;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x3fd);
  return uVar1 * -4 + 0xff4;
}
/* GHIDRADEC_FUNCTION index=1643 start=0x4053b30 */

void _stack_init(undefined4 *param_1)

{
  uint uVar1;
  
  if (_stack_check_usage != 0) {
    uVar1 = 0;
    do {
      *param_1 = 0xdeadbeef;
      uVar1 = uVar1 + 1;
      param_1 = param_1 + 1;
    } while (uVar1 < 0x3fd);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1644 start=0x4053b56 */

void _stack_finalize(undefined4 param_1)

{
  uint uVar1;
  
  if (_stack_check_usage != 0) {
    uVar1 = _stack_usage(param_1);
    if (_stack_max_usage < uVar1) {
      _stack_max_usage = uVar1;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1645 start=0x4053b7e */

undefined4
_host_stack_usage(int param_1,undefined4 *param_2,int *param_3,uint *param_4,uint *param_5,
                 undefined4 *param_6,undefined4 *param_7)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uStack_c;
  int iStack_8;
  
  if (param_1 == 0) {
    uVar2 = 0x16;
  }
  else {
    uStack_c = _stack_max_usage;
    _stack_statistics(&iStack_8,&uStack_c);
    *param_2 = 0;
    *param_3 = iStack_8;
    uVar1 = ~_page_mask & _page_mask + iStack_8 * 0xff4;
    *param_4 = uVar1;
    *param_5 = uVar1;
    *param_6 = uStack_c;
    *param_7 = 0;
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1646 start=0x4053bfe */

undefined4
_processor_set_stack_usage
          (int param_1,int *param_2,uint *param_3,uint *param_4,uint *param_5,int *param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  
  if (param_1 == 0) {
loc_4053C0E:
    uVar3 = 4;
  }
  else {
    piVar8 = (int *)0x0;
    uVar7 = 0;
    do {
      if (*(int *)(param_1 + 0x148) == 0) goto loc_4053C0E;
      uVar2 = *(uint *)(param_1 + 0x138);
      uVar6 = uVar2 << 2;
      if (uVar6 <= uVar7) {
        uVar6 = 0;
        iVar10 = *(int *)(param_1 + 0x130);
        piVar13 = piVar8;
        if (uVar2 != 0) {
          do {
            _thread_reference(iVar10);
            *piVar13 = iVar10;
            uVar6 = uVar6 + 1;
            iVar10 = *(int *)(iVar10 + 0x18);
            piVar13 = piVar13 + 1;
          } while (uVar6 < uVar2);
        }
        iVar14 = 0;
        uVar9 = 0;
        iVar10 = 0;
        uVar6 = 0;
        piVar13 = piVar8;
        if (uVar2 != 0) {
          do {
            iVar1 = *piVar13;
            iVar4 = 0;
            if ((*(byte *)(iVar1 + 0x4a) & 1) == 0) {
              iVar4 = *(int *)(iVar1 + 0x28);
              piVar11 = &_active_stacks;
              piVar12 = &_active_threads;
              do {
                if (iVar1 == *piVar12) {
                  iVar4 = *piVar11;
                  break;
                }
                piVar11 = piVar11 + 1;
                piVar12 = piVar12 + 1;
              } while ((int)piVar11 < 0x40c22dd);
            }
            if (((iVar4 != 0) && (iVar14 = iVar14 + 1, _stack_check_usage != 0)) &&
               (uVar5 = _stack_usage(iVar4), uVar9 < uVar5)) {
              uVar9 = uVar5;
              iVar10 = iVar1;
            }
            _thread_deallocate(iVar1);
            piVar13 = piVar13 + 1;
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar2);
        }
        if (uVar7 != 0) {
          _kfree(piVar8,uVar7);
        }
        *param_2 = iVar14;
        uVar7 = ~_page_mask & _page_mask + iVar14 * 0xff4;
        *param_3 = uVar7;
        *param_4 = uVar7;
        *param_5 = uVar9;
        *param_6 = iVar10;
        return 0;
      }
      if (uVar7 != 0) {
        _kfree(piVar8,uVar7);
      }
      piVar8 = (int *)_kalloc(uVar6);
      uVar7 = uVar6;
    } while (piVar8 != (int *)0x0);
    uVar3 = 6;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1647 start=0x4053d38 */

void _thread_stats(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  
  iVar2 = 0;
  iVar3 = 0;
  puVar4 = (undefined *)unk_40B6778._0_4_;
  if ((undefined *)unk_40B6778._0_4_ != unk_40B6778) {
    do {
      iVar2 = iVar2 + 1;
      if (*(int *)(puVar4 + 0xb8) != 0) {
        iVar3 = iVar3 + 1;
      }
      piVar1 = (int *)(puVar4 + 0x18);
      puVar4 = (undefined *)*piVar1;
    } while ((undefined *)*piVar1 != unk_40B6778);
  }
  _printf(aDTotalThreads,iVar2);
  _printf(aDUsingRpcReply,iVar3);
  return;
}
/* GHIDRADEC_FUNCTION index=1648 start=0x4053d8a */

undefined4 _current_thread_EXTERNAL(void)

{
  return _active_threads;
}
/* GHIDRADEC_FUNCTION index=1649 start=0x4053d98 */

void _swapper_init(void)

{
  dword_40C2B6C = &_swapin_queue;
  _swapin_queue = &_swapin_queue;
  return;
}

