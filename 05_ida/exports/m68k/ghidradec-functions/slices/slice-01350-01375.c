/* GHIDRADEC_FUNCTION index=1350 start=0x4049efc */

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
/* GHIDRADEC_FUNCTION index=1351 start=0x4049f9e */

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
/* GHIDRADEC_FUNCTION index=1352 start=0x404a010 */

bool _object_copyin(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  int iVar1;
  
  iVar1 = _ipc_object_copyin_compat(*(undefined4 *)(param_1 + 0x7c),param_2,param_3,param_4,param_5)
  ;
  return iVar1 == 0;
}
/* GHIDRADEC_FUNCTION index=1353 start=0x404a040 */

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
/* GHIDRADEC_FUNCTION index=1354 start=0x404a09a */

void _port_reference(int param_1)

{
  if (param_1 != 0) {
    _ipc_port_copy_send(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1355 start=0x404a0b0 */

void _port_release(int param_1)

{
  if (param_1 != 0) {
    _ipc_port_release_send(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1356 start=0x404a0c6 */

undefined4 _ds_notify(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=1357 start=0x404a0d0 */

void _vm_object_pager_wakeup(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1358 start=0x404a0d8 */

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
/* GHIDRADEC_FUNCTION index=1359 start=0x404a110 */

undefined4 _task_secure(void)

{
  return 1;
}
/* GHIDRADEC_FUNCTION index=1360 start=0x404a11a */

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
/* GHIDRADEC_FUNCTION index=1361 start=0x404a198 */

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
/* GHIDRADEC_FUNCTION index=1362 start=0x404a200 */

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
/* GHIDRADEC_FUNCTION index=1363 start=0x404a266 */

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
/* GHIDRADEC_FUNCTION index=1364 start=0x404a2c4 */

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
/* GHIDRADEC_FUNCTION index=1365 start=0x404a324 */

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
/* GHIDRADEC_FUNCTION index=1366 start=0x404a362 */

void _calloc(int param_1,int param_2)

{
  _malloc(param_2 * param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1367 start=0x404a37c */

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
/* GHIDRADEC_FUNCTION index=1368 start=0x404a3f2 */

void _free(int param_1)

{
  if (param_1 != 0) {
    _kfree((undefined4 *)(param_1 + -8),*(undefined4 *)(param_1 + -8));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1369 start=0x404a40e */

void _malloc_good_size(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1370 start=0x404a416 */

void _initKernelStacks(void)

{
  dword_40B3716 = &dword_40B3712;
  dword_40B3712 = &dword_40B3712;
  _lock_init(&_stack_queue_lock,1);
  dword_40B371A = 0x1000;
  dword_40B371E = _page_size + 0xfffU >> 0xc;
  return;
}
/* GHIDRADEC_FUNCTION index=1371 start=0x404a568 */

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
/* GHIDRADEC_FUNCTION index=1372 start=0x404a5de */

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
/* GHIDRADEC_FUNCTION index=1373 start=0x404a69a */

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
/* GHIDRADEC_FUNCTION index=1374 start=0x404a7da */

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

