/* GHIDRADEC_FUNCTION index=1600 start=0x40526cc */

undefined4 _task_assign(void)

{
  return 5;
}
/* GHIDRADEC_FUNCTION index=1601 start=0x40526d6 */

void _task_assign_default(undefined4 param_1,undefined4 param_2)

{
  _task_assign(param_1,_default_pset,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=1602 start=0x40526f2 */

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
/* GHIDRADEC_FUNCTION index=1603 start=0x405271a */

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
/* GHIDRADEC_FUNCTION index=1604 start=0x4052778 */

undefined4 _current_task_EXTERNAL(void)

{
  return *(undefined4 *)(_active_threads + 0xc);
}
/* GHIDRADEC_FUNCTION index=1605 start=0x405278a */

undefined4 _current_map_EXTERNAL(void)

{
  return *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8);
}
/* GHIDRADEC_FUNCTION index=1606 start=0x40527a0 */

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
/* GHIDRADEC_FUNCTION index=1607 start=0x40527d4 */

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
/* GHIDRADEC_FUNCTION index=1608 start=0x405290c */

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
/* GHIDRADEC_FUNCTION index=1609 start=0x4052a96 */

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
/* GHIDRADEC_FUNCTION index=1610 start=0x4052cae */

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
/* GHIDRADEC_FUNCTION index=1611 start=0x4052d20 */

void _thread_reference(int param_1)

{
  if (param_1 != 0) {
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1612 start=0x4052d40 */

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
/* GHIDRADEC_FUNCTION index=1613 start=0x4052e1a */

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
/* GHIDRADEC_FUNCTION index=1614 start=0x4052e74 */

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
/* GHIDRADEC_FUNCTION index=1615 start=0x4053072 */

void _walking_zombie(void)

{
                    /* WARNING: Subroutine does not return */
  _panic(aTheZombieWalks);
}
/* GHIDRADEC_FUNCTION index=1616 start=0x4053086 */

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
/* GHIDRADEC_FUNCTION index=1617 start=0x4053124 */

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
/* GHIDRADEC_FUNCTION index=1618 start=0x40531c4 */

byte _thread_hold(int param_1)

{
  int unaff_D2;
  char in_XF;
  
  *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 2;
  return in_XF << 4 | (unaff_D2 < 0) << 3 | (unaff_D2 == 0) << 2;
}
/* GHIDRADEC_FUNCTION index=1619 start=0x40531ec */

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
/* GHIDRADEC_FUNCTION index=1620 start=0x40532e4 */

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
/* GHIDRADEC_FUNCTION index=1621 start=0x4053340 */

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
/* GHIDRADEC_FUNCTION index=1622 start=0x40533d6 */

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
/* GHIDRADEC_FUNCTION index=1623 start=0x4053456 */

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
/* GHIDRADEC_FUNCTION index=1624 start=0x40534b0 */

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

