/* GHIDRADEC_FUNCTION index=1350 start=0x4049ea4 */

undefined4 _host_priv_self(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  iVar2 = _suser();
  if (iVar2 == 0) {
    uStack_8 = 0;
  }
  else if (dword_40B67DC == 0) {
    uStack_8 = 0;
  }
  else {
    uVar3 = _ipc_port_copy_send(dword_40B67DC,0x11,1,&uStack_8);
    _ipc_object_copyout(*(undefined4 *)(iVar1 + 0x7c),uVar3);
  }
  return uStack_8;
}
/* GHIDRADEC_FUNCTION index=1351 start=0x4049efc */

int __lookupd_port(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iStack_c;
  int iStack_8;
  
  iVar2 = *(int *)(_active_threads + 0xc);
  if (param_1 == 0) {
    iStack_8 = _lookupd_port;
    if (_lookupd_port == 0) {
      iStack_c = 0;
      param_1 = iStack_c;
    }
    else {
      uVar3 = _ipc_port_copy_send(_lookupd_port,0x11,1,&iStack_c);
      _ipc_object_copyout(*(undefined4 *)(iVar2 + 0x7c),uVar3);
      param_1 = iStack_c;
    }
  }
  else {
    iVar1 = _suser();
    if ((iVar1 == 0) ||
       (iVar2 = _ipc_object_copyin(*(undefined4 *)(iVar2 + 0x7c),param_1,0x14,&iStack_8), iVar2 != 0
       )) {
      param_1 = 0;
    }
    else {
      if (_lookupd_port != 0) {
        _ipc_port_release_send(_lookupd_port);
      }
      _lookupd_port = iStack_8;
    }
  }
  return param_1;
}
/* GHIDRADEC_FUNCTION index=1352 start=0x4049f9e */

undefined4 __event_port_by_tag(uint param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(_active_threads + 0xc);
  if ((((param_1 == 0) && (iVar2 = _suser(), iVar2 == 0)) || ((int)param_1 < 0)) || (2 < param_1)) {
    uStack_8 = 0;
  }
  else {
    iVar2 = *(int *)((int)&_ev_port_list + param_1 * 4);
    if (iVar2 == 0) {
      uStack_8 = 0;
    }
    else {
      uVar3 = _ipc_port_copy_send(iVar2,0x11,1,&uStack_8);
      _ipc_object_copyout(*(undefined4 *)(iVar1 + 0x7c),uVar3);
    }
  }
  return uStack_8;
}
/* GHIDRADEC_FUNCTION index=1353 start=0x404a010 */

bool _object_copyin(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  int iVar1;
  
  iVar1 = _ipc_object_copyin_compat(*(undefined4 *)(param_1 + 0x7c),param_2,param_3,param_4,param_5)
  ;
  return iVar1 == 0;
}
/* GHIDRADEC_FUNCTION index=1354 start=0x404a040 */

void _object_copyout(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aObjectCopyout);
  }
  if (param_3 == 5) {
    uVar2 = 0x10;
  }
  else {
    uVar2 = 0x11;
  }
  if ((param_2 != 0) &&
     (iVar1 = _ipc_object_copyout_compat(*(undefined4 *)(param_1 + 0x7c),param_2,uVar2,param_4),
     iVar1 == 0)) {
    return;
  }
  *param_4 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1355 start=0x404a09a */

void _port_reference(int param_1)

{
  if (param_1 != 0) {
    _ipc_port_copy_send(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1356 start=0x404a0b0 */

void _port_release(int param_1)

{
  if (param_1 != 0) {
    _ipc_port_release_send(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1357 start=0x404a0c6 */

undefined4 _ds_notify(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=1358 start=0x404a0d0 */

void _vm_object_pager_wakeup(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1359 start=0x404a0d8 */

void _send_notification(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uStack_8;
  
  if (param_2 == 0x42) {
    iVar1 = _task_get_special_port(param_1,2,&uStack_8);
    if (iVar1 == 0) {
      _ipc_notify_msg_accepted_compat(uStack_8,param_3);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1360 start=0x404a110 */

undefined4 _task_secure(void)

{
  return 1;
}
/* GHIDRADEC_FUNCTION index=1361 start=0x404a11a */

void _kalloc_init(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  _kalloc_map = _kernel_map;
  iVar3 = 0;
  puVar4 = unk_40B3612;
  do {
    uVar1 = *(uint *)(_k_zone_elemsize + iVar3 * 4);
    if (_page_size <= uVar1) {
      return;
    }
    _sprintf(puVar4,aKallocD,uVar1);
    uVar2 = _zinit(uVar1,0x100000,_page_size,0,puVar4);
    *(undefined4 *)(_k_zone + iVar3 * 4) = uVar2;
    puVar4 = puVar4 + 0x10;
    iVar3 = iVar3 + 1;
    _k_zone_maxsize = uVar1;
  } while (iVar3 < 0x10);
  return;
}
/* GHIDRADEC_FUNCTION index=1362 start=0x404a198 */

undefined4 _kalloc_noblock(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 uStack_8;
  
  iVar3 = 0;
  uVar2 = param_1;
  if (param_1 <= _k_zone_maxsize) {
    for (puVar4 = _k_zone_elemsize; uVar2 = *(uint *)puVar4, uVar2 < param_1;
        puVar4 = (undefined *)((int)puVar4 + 4)) {
      iVar3 = iVar3 + 1;
    }
    if (uVar2 <= _k_zone_maxsize) {
      uVar1 = _zalloc_noblock(*(undefined4 *)(_k_zone + iVar3 * 4));
      return uVar1;
    }
  }
  iVar3 = _kmem_alloc_zone(_kalloc_map,&uStack_8,uVar2,0);
  if (iVar3 != 0) {
    uStack_8 = 0;
  }
  return uStack_8;
}
/* GHIDRADEC_FUNCTION index=1363 start=0x404a200 */

undefined4 _kalloc(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 uStack_8;
  
  iVar3 = 0;
  uVar2 = param_1;
  if (param_1 <= _k_zone_maxsize) {
    for (puVar4 = _k_zone_elemsize; uVar2 = *(uint *)puVar4, uVar2 < param_1;
        puVar4 = (undefined *)((int)puVar4 + 4)) {
      iVar3 = iVar3 + 1;
    }
    if (uVar2 <= _k_zone_maxsize) {
      uVar1 = _zalloc(*(undefined4 *)(_k_zone + iVar3 * 4));
      return uVar1;
    }
  }
  iVar3 = _kmem_alloc_wired(_kalloc_map,&uStack_8,uVar2);
  if (iVar3 != 0) {
    uStack_8 = 0;
  }
  return uStack_8;
}
/* GHIDRADEC_FUNCTION index=1364 start=0x404a266 */

undefined4 _kget(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  
  if (param_1 <= _k_zone_maxsize) {
    puVar4 = _k_zone_elemsize;
    iVar3 = 0;
    uVar1 = _k_zone_elemsize._0_4_;
    while (uVar1 < param_1) {
      puVar4 = (undefined *)((int)puVar4 + 4);
      iVar3 = iVar3 + 1;
      uVar1 = *(uint *)puVar4;
    }
    if (uVar1 <= _k_zone_maxsize) {
      uVar2 = _zget(*(undefined4 *)(_k_zone + iVar3 * 4));
      return uVar2;
    }
  }
                    /* WARNING: Subroutine does not return */
  _panic(&aKget);
}
/* GHIDRADEC_FUNCTION index=1365 start=0x404a2c4 */

void _kfree(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = 0;
  uVar1 = param_2;
  if (param_2 <= _k_zone_maxsize) {
    for (puVar3 = _k_zone_elemsize; uVar1 = *(uint *)puVar3, uVar1 < param_2;
        puVar3 = (undefined *)((int)puVar3 + 4)) {
      iVar2 = iVar2 + 1;
    }
    if (uVar1 <= _k_zone_maxsize) {
      _zfree(*(undefined4 *)(_k_zone + iVar2 * 4),param_1);
      return;
    }
  }
  _kmem_free(_kalloc_map,param_1,uVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=1366 start=0x404a324 */

int * _malloc(int param_1)

{
  int *piVar1;
  
  param_1 = param_1 + 8;
  piVar1 = (int *)_kalloc(param_1);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    _bzero(piVar1,param_1);
    *piVar1 = param_1;
    piVar1 = piVar1 + 2;
  }
  return piVar1;
}
/* GHIDRADEC_FUNCTION index=1367 start=0x404a362 */

void _calloc(int param_1,int param_2)

{
  _malloc(param_2 * param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1368 start=0x404a37c */

int * _realloc(int param_1,uint param_2)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  
  puVar1 = (uint *)(param_1 + -8);
  if (param_1 == 0) {
    piVar2 = (int *)_malloc(param_2);
  }
  else {
    piVar2 = (int *)_kalloc(param_2 + 8);
    if (piVar2 == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      *piVar2 = param_2 + 8;
      uVar3 = *puVar1;
      if (param_2 < uVar3) {
        uVar3 = param_2;
      }
      _bcopy(param_1,piVar2 + 2,uVar3);
      _kfree(puVar1,*puVar1);
      piVar2 = piVar2 + 2;
    }
  }
  return piVar2;
}
/* GHIDRADEC_FUNCTION index=1369 start=0x404a3f2 */

void _free(int param_1)

{
  if (param_1 != 0) {
    _kfree((undefined4 *)(param_1 + -8),*(undefined4 *)(param_1 + -8));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1370 start=0x404a40e */

void _malloc_good_size(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1371 start=0x404a416 */

void _initKernelStacks(void)

{
  dword_40B3716 = &dword_40B3712;
  dword_40B3712 = &dword_40B3712;
  _lock_init(&_stack_queue_lock,1);
  dword_40B371A = 0x1000;
  dword_40B371E = _page_size + 0xfffU >> 0xc;
  return;
}
/* GHIDRADEC_FUNCTION index=1372 start=0x404a568 */

void _freeStack(int param_1)

{
  dword_40C232C = dword_40C232C + -1;
  _lock_write(&_stack_queue_lock);
  sub_404A45C(param_1 + -0xc);
  _lock_done(&_stack_queue_lock);
  if (dword_40AF7DC != 0) {
    dword_40AF7DC = 0;
    _thread_wakeup_prim(&dword_40B3712,0,0);
  }
  if (dword_40AF7D8 < dword_40AF7D4) {
    sub_404A498(param_1 + -0xc);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1373 start=0x404a5de */

int _newStack(void)

{
  int iVar1;
  int iVar2;
  int iStack_8;
  
  iVar1 = _kmem_alloc_wired(_kernel_map,&iStack_8,dword_40B371A);
  if (iVar1 == 0) {
    _stackStats = _stackStats + 1;
    *(undefined4 *)(iStack_8 + 8) = 2;
    dword_40C232C = dword_40C232C + 1;
    _stack_init(iStack_8 + 0xc);
    if (1 < dword_40B371E) {
      _lock_write(&_stack_queue_lock);
      iVar2 = dword_40B371A + iStack_8;
      iVar1 = 1;
      if (1 < dword_40B371E) {
        do {
          _stack_init(iVar2 + 0xc);
          sub_404A45C(iVar2);
          iVar2 = dword_40B371A + iVar2;
          iVar1 = iVar1 + 1;
        } while (iVar1 < dword_40B371E);
      }
      _lock_done(&_stack_queue_lock);
    }
    iStack_8 = iStack_8 + 0xc;
  }
  else {
    iStack_8 = 0;
  }
  return iStack_8;
}
/* GHIDRADEC_FUNCTION index=1374 start=0x404a69a */

int * _allocStack(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  
  bVar1 = false;
  iVar3 = 0;
  do {
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
    if ((piVar2 == (int *)0x0) && (piVar2 = (int *)_newStack(), piVar2 == (int *)0x0)) {
      if (bVar1) {
        if (iVar3 != 0) {
          return (int *)0x0;
        }
      }
      else {
        bVar1 = true;
        _uprintf(aMachOutOfKerne);
        if (dword_40AF7DC == 0) {
          _printf(aStackAllocKern);
        }
      }
      _lock_write(&_stack_queue_lock);
      if (dword_40AF7D4 == 0) {
        _assert_wait(&dword_40B3712,0);
        dword_40AF7DC = 1;
        _lock_done(&_stack_queue_lock);
        _thread_block();
        iVar3 = *(int *)(_active_threads + 0x40);
      }
      else {
        _lock_done(&_stack_queue_lock);
        iVar3 = 0;
      }
    }
    else if (bVar1) {
      _uprintf(aContinuing);
    }
  } while (piVar2 == (int *)0x0);
  return piVar2;
}
/* GHIDRADEC_FUNCTION index=1375 start=0x404a7da */

undefined4 _canSwap(uint param_1)

{
  int iVar1;
  
  param_1 = param_1 & ~_page_mask;
  iVar1 = 0;
  if (0 < dword_40B371E) {
    do {
      if (*(int *)(param_1 + 8) == 2) {
        return 0;
      }
      param_1 = dword_40B371A + param_1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < dword_40B371E);
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=1376 start=0x404a81e */

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
/* GHIDRADEC_FUNCTION index=1377 start=0x404a8c4 */

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
/* GHIDRADEC_FUNCTION index=1378 start=0x404a914 */

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
/* GHIDRADEC_FUNCTION index=1379 start=0x404a9c0 */

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
/* GHIDRADEC_FUNCTION index=1380 start=0x404aa5e */

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
/* GHIDRADEC_FUNCTION index=1381 start=0x404aa94 */

void _stack_free(int param_1)

{
  int iVar1;
  
  iVar1 = _stack_detach(param_1);
  if (iVar1 != *(int *)(param_1 + 0x2c)) {
    _freeStack(iVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1382 start=0x404aabe */

void _stack_collect(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1383 start=0x404aac6 */

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
/* GHIDRADEC_FUNCTION index=1384 start=0x404ab32 */

undefined4 _simple_lock_alloc(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=1385 start=0x404ab3c */

void _simple_lock_free(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1386 start=0x404ab44 */

void _lock_alloc(void)

{
  _kalloc(8);
  return;
}
/* GHIDRADEC_FUNCTION index=1387 start=0x404ab56 */

void _lock_free(undefined4 param_1)

{
  _kfree(param_1,8);
  return;
}
/* GHIDRADEC_FUNCTION index=1388 start=0x404ab6c */

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
/* GHIDRADEC_FUNCTION index=1389 start=0x404abb2 */

void _lock_sleepable(int param_1,byte param_2)

{
  *(uint *)(param_1 + 6) = *(uint *)(param_1 + 6) & 0xefffffff | (param_2 & 1) << 0x1c;
  return;
}
/* GHIDRADEC_FUNCTION index=1390 start=0x404abcc */

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
/* GHIDRADEC_FUNCTION index=1391 start=0x404acae */

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
/* GHIDRADEC_FUNCTION index=1392 start=0x404ad18 */

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
/* GHIDRADEC_FUNCTION index=1393 start=0x404ad8e */

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
/* GHIDRADEC_FUNCTION index=1394 start=0x404ae46 */

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
/* GHIDRADEC_FUNCTION index=1395 start=0x404aea2 */

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
/* GHIDRADEC_FUNCTION index=1396 start=0x404aee4 */

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
/* GHIDRADEC_FUNCTION index=1397 start=0x404af0e */

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
/* GHIDRADEC_FUNCTION index=1398 start=0x404af82 */

void _lock_set_recursive(undefined4 *param_1)

{
  if ((*(byte *)((int)param_1 + 6) & 0x40) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aLockSetRecursi);
  }
  *param_1 = _active_threads;
  return;
}
/* GHIDRADEC_FUNCTION index=1399 start=0x404afae */

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

