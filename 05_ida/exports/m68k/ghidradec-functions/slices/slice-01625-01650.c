/* GHIDRADEC_FUNCTION index=1625 start=0x405350a */

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
/* GHIDRADEC_FUNCTION index=1626 start=0x40536d2 */

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
/* GHIDRADEC_FUNCTION index=1627 start=0x405372c */

void _thread_start(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x30) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=1628 start=0x405373e */

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
/* GHIDRADEC_FUNCTION index=1629 start=0x40537ae */

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
/* GHIDRADEC_FUNCTION index=1630 start=0x405382c */

void _reaper_thread(void)

{
                    /* WARNING: Subroutine does not return */
  _reaper_thread_continue();
}
/* GHIDRADEC_FUNCTION index=1631 start=0x405383a */

undefined4 _thread_assign(void)

{
  return 5;
}
/* GHIDRADEC_FUNCTION index=1632 start=0x4053844 */

void _thread_assign_default(undefined4 param_1)

{
  _thread_assign(param_1,_default_pset);
  return;
}
/* GHIDRADEC_FUNCTION index=1633 start=0x405385c */

undefined4 _thread_get_assignment(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x178);
  _pset_reference(*param_2);
  return 0;
}
/* GHIDRADEC_FUNCTION index=1634 start=0x405387a */

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
/* GHIDRADEC_FUNCTION index=1635 start=0x40538e4 */

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
/* GHIDRADEC_FUNCTION index=1636 start=0x4053924 */

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
/* GHIDRADEC_FUNCTION index=1637 start=0x405398e */

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
/* GHIDRADEC_FUNCTION index=1638 start=0x4053a60 */

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
/* GHIDRADEC_FUNCTION index=1639 start=0x4053ab6 */

void _thread_collect_scan(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1640 start=0x4053abe */

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
/* GHIDRADEC_FUNCTION index=1641 start=0x4053b02 */

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
/* GHIDRADEC_FUNCTION index=1642 start=0x4053b30 */

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
/* GHIDRADEC_FUNCTION index=1643 start=0x4053b56 */

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
/* GHIDRADEC_FUNCTION index=1644 start=0x4053b7e */

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
/* GHIDRADEC_FUNCTION index=1645 start=0x4053bfe */

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
/* GHIDRADEC_FUNCTION index=1646 start=0x4053d38 */

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
/* GHIDRADEC_FUNCTION index=1647 start=0x4053d8a */

undefined4 _current_thread_EXTERNAL(void)

{
  return _active_threads;
}
/* GHIDRADEC_FUNCTION index=1648 start=0x4053d98 */

void _swapper_init(void)

{
  dword_40C2B6C = &_swapin_queue;
  _swapin_queue = &_swapin_queue;
  return;
}
/* GHIDRADEC_FUNCTION index=1649 start=0x4053dae */

void _thread_swapin(undefined4 *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[0x12] & 0x300;
  if (uVar1 == 0x100) {
    param_1[0x12] = param_1[0x12] & 0xfffffcff | 0x200;
    *param_1 = &_swapin_queue;
    param_1[1] = dword_40C2B6C;
    *(undefined4 **)param_1[1] = param_1;
    dword_40C2B6C = param_1;
    _thread_wakeup_prim(&_swapin_queue,0,0);
  }
  else if (uVar1 != 0x200) {
                    /* WARNING: Subroutine does not return */
    _panic(aThreadSwapin);
  }
  return;
}

