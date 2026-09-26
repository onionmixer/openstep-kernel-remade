/* GHIDRADEC_FUNCTION index=1425 start=0x404bb96 */

int _load_machfile(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 auStack_16 [4];
  
  iVar1 = *(int *)(*(int *)(_active_threads + 0xc) + 8);
  uVar2 = *(undefined4 *)(iVar1 + 0x20);
  _pmap_reference(uVar2);
  uVar2 = _vm_map_create(uVar2,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),
                         *(undefined4 *)(iVar1 + 0x1c));
  if (param_5 == (undefined4 *)0x0) {
    param_5 = auStack_16;
  }
  _bzero(param_5,0x12);
  *param_5 = 0;
  iVar3 = sub_404BC42(param_1,uVar2,param_2,param_3,param_4,0,0,param_5);
  if (iVar3 == 0) {
    *(undefined4 *)(*(int *)(_active_threads + 0xc) + 8) = uVar2;
    _vm_map_deallocate(iVar1);
    iVar3 = 0;
  }
  else {
    _vm_map_deallocate(uVar2);
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=1426 start=0x404c95e */

bool _netipc_msg_send(int param_1)

{
  bool bVar1;
  
  bVar1 = *(int *)(param_1 + 0x28) == 0x7a7;
  if (bVar1) {
    sub_404C758(param_1);
  }
  return bVar1;
}
/* GHIDRADEC_FUNCTION index=1427 start=0x404c982 */

undefined4
_netipc_listen(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
              undefined2 param_5,byte param_6,int param_7)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (*(sword *)(*(int *)(_active_u + 0x1a) + 2) == 0) {
    if (param_7 == 0) {
      uVar1 = 4;
    }
    else {
      puVar2 = (undefined4 *)_zalloc(_listener_zone);
      puVar2[1] = param_2;
      *(undefined2 *)(puVar2 + 3) = param_4;
      puVar2[2] = param_3;
      *(undefined2 *)((int)puVar2 + 0xe) = param_5;
      puVar2[4] = param_7;
      _ipc_object_reference(param_7);
      *puVar2 = *(undefined4 *)(_listeners + (uint)(param_6 & 0xf) * 4);
      *(undefined4 **)(_listeners + (uint)(param_6 & 0xf) * 4) = puVar2;
      _ipc_kobject_set(param_7,0,0x11);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 8;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1428 start=0x404ca60 */

undefined4 _netipc_ignore(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int *piVar4;
  int *piVar5;
  
  uVar2 = 5;
  if (param_2 == 0) {
    uVar2 = 4;
  }
  else {
    puVar3 = _listeners;
    do {
      piVar1 = *(int **)puVar3;
      piVar4 = *(int **)puVar3;
      while (piVar5 = piVar1, piVar5 != (int *)0x0) {
        if (param_2 == piVar5[4]) {
          uVar2 = 0;
          if (piVar5 == *(int **)puVar3) {
            *(int *)puVar3 = *piVar5;
            _zfree(_listener_zone,piVar5);
            piVar4 = *(int **)puVar3;
            if (piVar4 == (int *)0x0) break;
          }
          else {
            *piVar4 = *piVar5;
            _zfree(_listener_zone,piVar5);
          }
          _ipc_object_release(param_2);
          piVar5 = piVar4;
        }
        piVar4 = piVar5;
        piVar1 = (int *)*piVar5;
      }
      puVar3 = (undefined *)((int)puVar3 + 4);
    } while (puVar3 < &_mach_net_kmsg_zone);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1429 start=0x404cb02 */

int _find_listener(int param_1,sword param_2,int param_3,sword param_4,byte param_5)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  piVar1 = (int *)(_listeners + (param_5 & 0xf) * 4);
  piVar4 = (int *)*piVar1;
  piVar3 = (int *)*piVar1;
  while( true ) {
    piVar2 = piVar4;
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    if (((((*(sword *)((int)piVar2 + 0xe) == 0) || (param_4 == *(sword *)((int)piVar2 + 0xe))) &&
         ((*(sword *)(piVar2 + 3) == 0 || (param_2 == *(sword *)(piVar2 + 3))))) &&
        ((piVar2[1] == 0 || (param_1 == piVar2[1])))) &&
       ((piVar2[2] == 0 || (param_3 == piVar2[2])))) break;
    piVar4 = (int *)*piVar2;
    piVar3 = piVar2;
  }
  if (piVar2 != (int *)*piVar1) {
    *piVar3 = *piVar2;
    *piVar2 = *piVar1;
    *piVar1 = (int)piVar2;
  }
  return piVar2[4];
}
/* GHIDRADEC_FUNCTION index=1430 start=0x404cb80 */

void _mach_net_init(void)

{
  undefined *puVar1;
  undefined4 uStack_8;
  
  _listener_zone = _zinit(0x14,2000,0x14,0,aNetListenerZon);
  dword_40B3722 = 0x11;
  dword_40B3726 = 0x7ec;
  dword_40B372A = 0;
  dword_40B372E = 0;
  dword_40B3736 = 0x7a7;
  puVar1 = _listeners;
  do {
    puVar1 = (undefined *)((int)puVar1 + 4);
  } while (puVar1 < &_mach_net_kmsg_zone);
  _mach_net_kmsg_zone = _zinit(0x800,0x2000,0x800,0,aMachNetMessage);
  _zchange(_mach_net_kmsg_zone,0,0,0,0);
  _kmem_alloc_wired(_kernel_map,&uStack_8,0x2000);
  _zcram(_mach_net_kmsg_zone,uStack_8,0x2000);
  return;
}
/* GHIDRADEC_FUNCTION index=1431 start=0x404cc4e */

void _netipc_msg_release(undefined4 param_1)

{
  _zfree(_mach_net_kmsg_zone,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1432 start=0x404cc66 */

undefined4 _receive_ip_datagram(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  
  iVar1 = *param_1;
  pbVar5 = (byte *)(*(int *)(iVar1 + 4) + iVar1);
  if (5 < (*pbVar5 & 0xf)) {
    _ip_stripoptions(pbVar5,0);
  }
  if ((0x7c < *(uint *)(iVar1 + 4)) || (*(word *)(iVar1 + 8) < 0x18)) {
    iVar1 = _m_pullup(iVar1,0x18);
    *param_1 = iVar1;
    if (iVar1 == 0) {
      return 1;
    }
    pbVar5 = (byte *)(*(int *)(iVar1 + 4) + iVar1);
  }
  iVar2 = _find_listener(*(undefined4 *)(pbVar5 + 0xc),*(undefined2 *)(pbVar5 + 0x14),
                         *(undefined4 *)(pbVar5 + 0x10),*(undefined2 *)(pbVar5 + 0x16),pbVar5[9]);
  if (iVar2 != 0) {
    iVar3 = _zget(_mach_net_kmsg_zone);
    if (iVar3 == 0) {
      _m_freem(iVar1);
    }
    else {
      *(undefined4 *)(iVar3 + 8) = 0xfffffffd;
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *(undefined4 *)(iVar3 + 0x10) = 0;
      *(word *)(pbVar5 + 2) = (*pbVar5 & 0xf) * 4 + *(sword *)(pbVar5 + 2);
      *(sword *)(pbVar5 + 6) = *(sword *)(pbVar5 + 6) >> 3;
      iVar7 = iVar3 + 0x2c;
      for (uVar4 = 0x7d4; (iVar1 != 0 && (0 < (int)uVar4)); uVar4 = uVar4 - uVar6) {
        uVar6 = (int)*(sword *)(iVar1 + 8);
        if ((int)uVar4 < (int)*(sword *)(iVar1 + 8)) {
          uVar6 = uVar4;
        }
        _bcopy(*(int *)(iVar1 + 4) + iVar1,iVar7,uVar6);
        iVar7 = uVar6 + iVar7;
        iVar1 = _m_free(iVar1);
      }
      *(uint *)(iVar3 + 0x10) = uVar4;
      *(uint *)(iVar3 + 0x10) = (uVar4 & 0xfffffffc) - *(int *)(iVar3 + 0x10);
      *(undefined4 *)(iVar3 + 0x14) = dword_40B3722;
      *(undefined4 *)(iVar3 + 0x18) = dword_40B3726;
      *(undefined4 *)(iVar3 + 0x1c) = dword_40B372A;
      *(undefined4 *)(iVar3 + 0x20) = dword_40B372E;
      *(undefined4 *)(iVar3 + 0x24) = dword_40B3732;
      *(undefined4 *)(iVar3 + 0x28) = dword_40B3736;
      *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) - (uVar4 & 0xfffffffc);
      *(int *)(iVar3 + 0x1c) = iVar2;
      _ipc_object_reference(iVar2);
      _ipc_mqueue_send(iVar3,0x10000,0,0);
    }
    return 1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1433 start=0x404cdfc */

undefined4 _xxx_host_info(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = _machine_info;
  param_2[1] = dword_40C22CC;
  param_2[2] = dword_40C22D0;
  param_2[3] = dword_40C22D4;
  param_2[4] = dword_40C22D8;
  return 0;
}
/* GHIDRADEC_FUNCTION index=1434 start=0x404ce28 */

undefined4 _xxx_slot_info(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_2 < 0) || (0 < param_2)) {
    uVar2 = 4;
  }
  else {
    iVar1 = param_2 * 0x20;
    *param_3 = (&_machine_slot)[param_2 * 8];
    param_3[1] = (&dword_40B5DCC)[param_2 * 8];
    param_3[2] = (&dword_40B5DD0)[param_2 * 8];
    param_3[3] = (&dword_40B5DD4)[param_2 * 8];
    param_3[4] = *(undefined4 *)(DAT_40b5dd8 + iVar1);
    param_3[5] = *(undefined4 *)(DAT_40b5dd8 + iVar1 + 4);
    param_3[6] = *(undefined4 *)(DAT_40b5dd8 + iVar1 + 8);
    param_3[7] = *(undefined4 *)(DAT_40b5dd8 + iVar1 + 0xc);
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1435 start=0x404ce5c */

undefined4 _xxx_cpu_control(void)

{
  return 5;
}
/* GHIDRADEC_FUNCTION index=1436 start=0x404ce66 */

char _cpu_up(int param_1)

{
  int iVar1;
  char cVar2;
  
  iVar1 = (&_processor_ptr)[param_1];
  (&dword_40B5DD4)[param_1 * 8] = 1;
  cVar2 = 0xfffffffe < dword_40C22D4;
  dword_40C22D4 = dword_40C22D4 + 1;
  _pset_add_processor(_default_pset,iVar1);
  *(undefined4 *)(iVar1 + 0x110) = 1;
  return cVar2 << 4;
}
/* GHIDRADEC_FUNCTION index=1437 start=0x404cebe */

undefined8 _cpu_down(int param_1)

{
  int iVar1;
  char in_XF;
  bool bVar2;
  
  iVar1 = (&_processor_ptr)[param_1];
  (&dword_40B5DD4)[param_1 * 8] = 0;
  bVar2 = dword_40C22D4 == 0;
  dword_40C22D4 = dword_40C22D4 + -1;
  *(undefined4 *)(iVar1 + 300) = 0;
  *(undefined4 *)(iVar1 + 0x110) = 0;
  return CONCAT44(CONCAT22((sword)((uint)(param_1 * 0x20) >> 0x10),(word)(byte)(bVar2 << 4 | 4)),
                  (int)(sword)(word)(byte)(in_XF << 4 | (param_1 < 0) << 3 | (param_1 == 0) << 2));
}
/* GHIDRADEC_FUNCTION index=1438 start=0x404cefc */

undefined4 _processor_assign(void)

{
  return 5;
}
/* GHIDRADEC_FUNCTION index=1439 start=0x404cf06 */

void _mfs_init(void)

{
  double dVar1;
  undefined auStack_c [4];
  undefined auStack_8 [4];
  
  dword_40C23D0 = &_vm_info_queue;
  _vm_info_queue = &_vm_info_queue;
  _lock_init(&_mfs_alloc_lock_data,1);
  _mfs_alloc_wanted = 0;
  _mfs_map = _kmem_suballoc(_kernel_map,auStack_8,auStack_c,_mfs_map_size,1);
  dVar1 = (double)dword_40C22D8;
  if (dword_40C22D8 < 0) {
    dVar1 = dVar1 + 4294967296.0;
  }
  _mfs_map_size = (uint)dVar1;
  if (0x1000000 < _mfs_map_size) {
    _mfs_map_size = 0x1000000;
  }
  if (_mfs_max_window == 0) {
    _mfs_max_window = _mfs_map_size / 0x14;
  }
  if (_mfs_max_window < 0x10000) {
    _mfs_max_window = 0x10000;
  }
  _vm_info_zone = _zinit(0x36,540000,0x2000,0,aVmInfoZone);
  return;
}
/* GHIDRADEC_FUNCTION index=1440 start=0x404d002 */

void _vm_info_init(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)_zalloc(_vm_info_zone);
  }
  *puVar1 = 0;
  *(undefined2 *)(puVar1 + 1) = 0;
  *(undefined2 *)((int)puVar1 + 6) = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  *(byte *)(puVar1 + 0xd) = *(byte *)(puVar1 + 0xd) & 0x37 | 0x20;
  puVar1[5] = 0;
  _lock_init(puVar1 + 6,1);
  puVar1[8] = 0;
  *param_1 = puVar1;
  return;
}
/* GHIDRADEC_FUNCTION index=1441 start=0x404d076 */

void _vm_info_enqueue(int param_1)

{
  if (dword_40C23D0 == &_vm_info_queue) {
    _vm_info_queue = param_1;
  }
  else {
    dword_40C23D0[9] = param_1;
  }
  *(undefined4 **)(param_1 + 0x28) = dword_40C23D0;
  *(int **)(param_1 + 0x24) = &_vm_info_queue;
  dword_40C23D0 = (undefined4 *)param_1;
  *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) | 0x80;
  _mfs_files_mapped = _mfs_files_mapped + 1;
  _vm_info_version = _vm_info_version + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1442 start=0x404d0c2 */

void _vm_info_dequeue(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0x24);
  puVar2 = *(undefined4 **)(param_1 + 0x28);
  puVar3 = puVar2;
  if ((undefined4 **)puVar1 != &_vm_info_queue) {
    puVar1[10] = puVar2;
    puVar3 = dword_40C23D0;
  }
  dword_40C23D0 = puVar3;
  if ((undefined4 **)puVar2 != &_vm_info_queue) {
    puVar2[9] = puVar1;
    puVar1 = _vm_info_queue;
  }
  _vm_info_queue = puVar1;
  *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) & 0x7f;
  _mfs_files_mapped = _mfs_files_mapped + -1;
  _vm_info_version = _vm_info_version + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1443 start=0x404d112 */

void _map_vnode(int *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  sword sVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  puVar1 = (undefined4 *)*param_1;
  sVar3 = *(sword *)(puVar1 + 1);
  *(sword *)(puVar1 + 1) = *(sword *)(puVar1 + 1) + 1;
  if ((sVar3 < 1) && ((*(byte *)(puVar1 + 0xd) & 8) == 0)) {
    _vmp_get(puVar1);
    uVar4 = _vnode_pager_setup(param_1,0,1);
    *puVar1 = uVar4;
    _lock_write(&_vm_alloc_lock);
    uVar5 = _vm_object_lookup(uVar4);
    puVar1[8] = uVar5;
    dword_40C240C = dword_40C240C + 1;
    if (puVar1[8] == 0) {
      uVar5 = _vm_object_allocate(0);
      puVar1[8] = uVar5;
      _vm_object_enter(uVar5,uVar4);
      _vm_object_setpager(puVar1[8],uVar4,0,0);
    }
    else {
      dword_40C2410 = dword_40C2410 + 1;
    }
    _lock_done(&_vm_alloc_lock);
    puVar1[0xc] = 0;
    uVar4 = _vnode_size(param_1);
    puVar1[5] = uVar4;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    *(byte *)(puVar1 + 0xd) = *(byte *)(puVar1 + 0xd) | 8;
    uVar2 = puVar1[5];
    if ((uVar2 != 0) && (uVar2 < _mfs_max_window)) {
      _remap_vnode(param_1,0,uVar2);
    }
    _vmp_put(puVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1444 start=0x404d20c */

void _unmap_vnode(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  sword sVar3;
  int iStack_8;
  
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x34) & 8) != 0) {
    sVar3 = *(sword *)(iVar1 + 4);
    *(sword *)(iVar1 + 4) = sVar3 + -1;
    if ((sword)(sVar3 + -1) < 1) {
      *(sword *)(iVar1 + 4) = sVar3;
      (**(code **)(param_1[7] + 0x7c))(param_1,&iStack_8);
      sVar3 = *(sword *)(iVar1 + 4);
      *(sword *)(iVar1 + 4) = sVar3 + -1;
      if (iStack_8 == 0) {
        _mfs_memfree(iVar1,0);
      }
      else {
        uVar2 = *(undefined4 *)(iVar1 + 0x20);
        if ((_close_flush != 0) || ((*(byte *)(iVar1 + 0x34) & 0x20) != 0)) {
          *(sword *)(iVar1 + 4) = sVar3;
          _vmp_get(iVar1);
          _vmp_push(iVar1);
        }
        _vm_object_deactivate_pages(uVar2);
        if ((_close_flush != 0) || ((*(byte *)(iVar1 + 0x34) & 0x20) != 0)) {
          _vmp_put(iVar1);
          *(sword *)(iVar1 + 4) = *(sword *)(iVar1 + 4) + -1;
        }
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1445 start=0x404d2c8 */

undefined4 _remap_vnode(int *param_1,uint param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uStack_8;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1[3] != 0) {
    _mfs_map_remove(puVar1,puVar1[2],puVar1[3] + puVar1[2],1);
  }
  uVar2 = ~_page_mask & param_2;
  uVar6 = (~_page_mask & _page_mask + param_3 + param_2) - uVar2;
  if (uVar6 < 0x10000) {
    uVar6 = 0x10000;
  }
  do {
    uStack_8 = *(undefined4 *)(_mfs_map + 0x10);
    _lock_write(&_mfs_alloc_lock_data);
    iVar4 = _vm_allocate_with_pager(_mfs_map,&uStack_8,uVar6,1,*puVar1,uVar2);
    puVar3 = _vm_info_queue;
    if (iVar4 == 3) {
      puVar5 = (undefined4 *)0x0;
      if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
        _vm_info_dequeue(_vm_info_queue);
        puVar5 = puVar3;
      }
      if (puVar5 == (undefined4 *)0x0) {
        _mfs_alloc_wanted = 1;
        _assert_wait(&_mfs_map,0);
        _mfs_alloc_blocks = _mfs_alloc_blocks + 1;
        _lock_done(&_mfs_alloc_lock_data);
        _thread_block();
      }
      else {
        _lock_done(&_mfs_alloc_lock_data);
        _mfs_memfree(puVar5,1);
      }
      _lock_write(&_mfs_alloc_lock_data);
    }
    else if (iVar4 != 0) {
      _printf(aUnexpectedErro,iVar4);
                    /* WARNING: Subroutine does not return */
      _panic(aRemapVnode);
    }
    _lock_done(&_mfs_alloc_lock_data);
  } while (iVar4 != 0);
  puVar1[2] = uStack_8;
  puVar1[3] = uVar6;
  puVar1[4] = uVar2;
  return 1;
}
/* GHIDRADEC_FUNCTION index=1446 start=0x404d42c */

undefined4 _mfs_trunc(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x34) & 8) == 0) {
    *(uint *)(iVar1 + 0x14) = param_2;
    uVar4 = 0;
  }
  else {
    _vmp_get(iVar1);
    uVar2 = ~_page_mask & _page_mask + param_2;
    uVar5 = 0;
    if (*(uint *)(iVar1 + 0x10) <= uVar2) {
      uVar5 = uVar2 - *(uint *)(iVar1 + 0x10);
    }
    if (uVar5 < *(uint *)(iVar1 + 0xc)) {
      _mfs_map_remove(iVar1,uVar5 + *(int *)(iVar1 + 8),*(uint *)(iVar1 + 0xc) + *(int *)(iVar1 + 8)
                      ,0);
      *(uint *)(iVar1 + 0xc) = uVar5;
    }
    if (uVar2 < *(uint *)(iVar1 + 0x14)) {
      _vno_flush(param_1,uVar2,*(uint *)(iVar1 + 0x14) - uVar2);
    }
    *(uint *)(iVar1 + 0x14) = param_2;
    if (uVar2 != param_2) {
      iVar3 = uVar2 - param_2;
      if ((param_2 < *(uint *)(iVar1 + 0x10)) ||
         (*(int *)(iVar1 + 0xc) + *(uint *)(iVar1 + 0x10) < iVar3 + param_2)) {
        _remap_vnode(param_1,param_2,iVar3);
      }
      _bzero((param_2 + *(int *)(iVar1 + 8)) - *(int *)(iVar1 + 0x10),iVar3);
      *(sword *)(iVar1 + 4) = *(sword *)(iVar1 + 4) + 1;
      *(byte *)(iVar1 + 0x34) = *(byte *)(iVar1 + 0x34) | 0x40;
      _vmp_push(iVar1);
      *(sword *)(iVar1 + 4) = *(sword *)(iVar1 + 4) + -1;
    }
    _vmp_put(iVar1);
    uVar4 = 1;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=1447 start=0x404d528 */

void _mfs_get(int *param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = *param_1;
  _vmp_get(iVar1);
  if (_mfs_max_window < param_3) {
    param_3 = _mfs_max_window;
  }
  if (*(uint *)(iVar1 + 0xc) < param_3) {
    _remap_vnode(param_1,param_2,param_3);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1448 start=0x404d56e */

void _mfs_put(undefined4 *param_1)

{
  _vmp_put(*param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1449 start=0x404d582 */

void _vmp_get(int param_1)

{
  if (*(char *)(param_1 + 0x34) < '\0') {
    _vm_info_dequeue(param_1);
  }
  *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
  _lock_write(param_1 + 0x18);
  return;
}

