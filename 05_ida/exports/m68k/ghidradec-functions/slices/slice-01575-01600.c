/* GHIDRADEC_FUNCTION index=1575 start=0x405191e */

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
/* GHIDRADEC_FUNCTION index=1576 start=0x405195e */

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
/* GHIDRADEC_FUNCTION index=1577 start=0x40519b8 */

void _thread_switch_continue(void)

{
  if (-1 < *(int *)(_active_threads + 0x60)) {
    _thread_depress_abort(_active_threads);
  }
  _thread_syscall_return(0);
  return;
}
/* GHIDRADEC_FUNCTION index=1578 start=0x40519de */

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
/* GHIDRADEC_FUNCTION index=1579 start=0x4051aec */

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
/* GHIDRADEC_FUNCTION index=1580 start=0x4051b60 */

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
/* GHIDRADEC_FUNCTION index=1581 start=0x4051b9a */

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
/* GHIDRADEC_FUNCTION index=1582 start=0x4051bf8 */

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
/* GHIDRADEC_FUNCTION index=1583 start=0x4051db2 */

undefined4 _null_port(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=1584 start=0x4051dbc */

undefined4 _kern_invalid(void)

{
  return 4;
}
/* GHIDRADEC_FUNCTION index=1585 start=0x4051dc6 */

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
/* GHIDRADEC_FUNCTION index=1586 start=0x4051e10 */

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
/* GHIDRADEC_FUNCTION index=1587 start=0x4051e8c */

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
/* GHIDRADEC_FUNCTION index=1588 start=0x4051fe0 */

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
/* GHIDRADEC_FUNCTION index=1589 start=0x405204c */

void _task_reference(int *param_1)

{
  if (param_1 != (int *)0x0) {
    *param_1 = *param_1 + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1590 start=0x405205e */

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
/* GHIDRADEC_FUNCTION index=1591 start=0x40521ba */

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
/* GHIDRADEC_FUNCTION index=1592 start=0x4052206 */

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
/* GHIDRADEC_FUNCTION index=1593 start=0x4052284 */

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
/* GHIDRADEC_FUNCTION index=1594 start=0x40522ca */

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
/* GHIDRADEC_FUNCTION index=1595 start=0x4052334 */

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
/* GHIDRADEC_FUNCTION index=1596 start=0x4052450 */

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
/* GHIDRADEC_FUNCTION index=1597 start=0x40524f2 */

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
/* GHIDRADEC_FUNCTION index=1598 start=0x4052532 */

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
/* GHIDRADEC_FUNCTION index=1599 start=0x4052672 */

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

