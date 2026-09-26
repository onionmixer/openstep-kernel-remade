/* GHIDRADEC_FUNCTION index=2550 start=0x4096924 */

void _pcb_init(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = _zalloc(_pcb_zone);
  *(undefined4 *)(param_1 + 0x24) = uVar1;
  _bzero(uVar1,0x1a0);
  return;
}
/* GHIDRADEC_FUNCTION index=2551 start=0x4096952 */

int _thread_user_state(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if (*(int *)(iVar1 + 0x4c) == 0) {
    iVar3 = 0x138;
    if (_cpu_type != '\0') {
      iVar3 = 0x244;
    }
    iVar2 = _kalloc(iVar3);
    *(int *)(iVar1 + 0x4c) = iVar2;
    iVar3 = iVar2 + -0x48 + iVar3;
    *(int *)(iVar1 + 0x48) = iVar3;
    _bzero(iVar3,0x48);
  }
  else {
    iVar3 = *(int *)(iVar1 + 0x48);
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=2552 start=0x40969b4 */

void _thread_bootstrap_return(void)

{
  _thread_exception_return();
  return;
}
/* GHIDRADEC_FUNCTION index=2553 start=0x40969c2 */

void _thread_exception_return(void)

{
  undefined4 uVar1;
  
  if (*(int *)(*(int *)(_active_threads + 0x24) + 0x4c) == 0) {
    uVar1 = _thread_user_state(_active_threads);
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(_active_threads + 0x24) + 0x48);
  }
  _check_for_ast(uVar1);
  __return_with_state(uVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=2554 start=0x4096a02 */

void _thread_syscall_return(undefined4 param_1)

{
  undefined4 *puVar1;
  
  if (*(int *)(*(int *)(_active_threads + 0x24) + 0x4c) == 0) {
    puVar1 = (undefined4 *)_thread_user_state(_active_threads);
  }
  else {
    puVar1 = *(undefined4 **)(*(int *)(_active_threads + 0x24) + 0x48);
  }
  *puVar1 = param_1;
  _check_for_ast(puVar1);
  __return_with_state(puVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=2555 start=0x4096a46 */

void _thread_set_syscall_return(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x24) + 0x4c) == 0) {
    puVar1 = (undefined4 *)_thread_user_state(param_1);
  }
  else {
    puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x24) + 0x48);
  }
  *puVar1 = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=2556 start=0x4096a70 */

void _start_initial_context(int param_1)

{
  _active_threads = param_1;
  _active_stacks = *(undefined4 *)(param_1 + 0x28);
  _stack_pointers = *(int *)(param_1 + 0x28) + 0xff4;
  __switch_context0(0,*(undefined4 *)(param_1 + 0x24),0);
  return;
}
/* GHIDRADEC_FUNCTION index=2557 start=0x4096aa8 */

undefined4 _thread_setstatus(int param_1,int param_2,undefined4 *param_3,uint param_4)

{
  word wVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (param_2 == 2) {
    if (0x1b < param_4) {
      iVar2 = *(int *)(param_1 + 0x24);
      _bcopy(param_3,iVar2 + 0x134,0x60);
      *(undefined4 *)(iVar2 + 0x194) = param_3[0x18];
      *(undefined4 *)(iVar2 + 0x198) = param_3[0x19];
      *(undefined4 *)(iVar2 + 0x19c) = param_3[0x1a];
      return 0;
    }
  }
  else if (param_2 < 3) {
    if ((param_2 == 1) && (0x11 < param_4)) {
      if (*(int *)(*(int *)(param_1 + 0xc) + 0x44) == 0) {
        if (*(int *)(*(int *)(param_1 + 0x24) + 0x4c) == 0) {
          puVar3 = (undefined4 *)_thread_user_state(param_1);
        }
        else {
          puVar3 = *(undefined4 **)(*(int *)(param_1 + 0x24) + 0x48);
        }
        iVar2 = 0;
        puVar4 = param_3;
        puVar5 = puVar3;
        do {
          *puVar5 = *puVar4;
          puVar3[iVar2 + 8] = param_3[iVar2 + 8];
          iVar2 = iVar2 + 1;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        } while (iVar2 < 8);
        *(undefined2 *)(puVar3 + 0x10) = *(undefined2 *)((int)param_3 + 0x42);
        *(undefined4 *)((int)puVar3 + 0x42) = param_3[0x11];
        wVar1 = *(word *)(puVar3 + 0x10);
        *(word *)(puVar3 + 0x10) = wVar1 & 0xc0ff;
        *(word *)(puVar3 + 0x10) = wVar1 & 0xc0ff;
        if ((wVar1 & 0xc000) == 0xc000) {
          *(word *)(puVar3 + 0x10) = wVar1 & 0x80ff;
        }
      }
      else {
        puVar3 = *(undefined4 **)(param_1 + 0x24);
        iVar2 = 0;
        puVar4 = param_3;
        puVar5 = puVar3;
        do {
          *puVar5 = *puVar4;
          puVar3[iVar2 + 8] = param_3[iVar2 + 8];
          iVar2 = iVar2 + 1;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        } while (iVar2 < 8);
        _thread_start(param_1,param_3[0x11]);
      }
      return 0;
    }
  }
  else if ((param_2 == 3) && (param_4 != 0)) {
    *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x50) = *param_3;
    return 0;
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=2558 start=0x4096bd0 */

undefined4 _thread_getstatus(int param_1,int param_2,undefined4 *param_3,uint *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (param_2 == 1) {
    if (0x11 < *param_4) {
      if (*(int *)(*(int *)(param_1 + 0x24) + 0x4c) == 0) {
        puVar1 = (undefined4 *)_thread_user_state(param_1);
      }
      else {
        puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x24) + 0x48);
      }
      iVar2 = 0;
      puVar3 = puVar1;
      puVar4 = param_3;
      do {
        *puVar4 = *puVar3;
        param_3[iVar2 + 8] = puVar1[iVar2 + 8];
        iVar2 = iVar2 + 1;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar2 < 8);
      *(undefined2 *)((int)param_3 + 0x42) = *(undefined2 *)(puVar1 + 0x10);
      param_3[0x11] = *(undefined4 *)((int)puVar1 + 0x42);
      *param_4 = 0x12;
      return 0;
    }
  }
  else if (param_2 < 2) {
    if ((param_2 == 0) && (5 < *param_4)) {
      *param_3 = 1;
      param_3[1] = 0x12;
      param_3[2] = 2;
      param_3[3] = 0x1c;
      param_3[4] = 3;
      param_3[5] = 1;
      *param_4 = 6;
      return 0;
    }
  }
  else if (param_2 == 2) {
    if (0x1b < *param_4) {
      iVar2 = *(int *)(param_1 + 0x24);
      _bcopy(iVar2 + 0x134,param_3,0x60);
      param_3[0x18] = *(undefined4 *)(iVar2 + 0x194);
      param_3[0x19] = *(undefined4 *)(iVar2 + 0x198);
      param_3[0x1a] = *(undefined4 *)(iVar2 + 0x19c);
      param_3[0x1b] = 0;
      *param_4 = 0x1c;
      return 0;
    }
  }
  else if ((param_2 == 3) && (*param_4 != 0)) {
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x50);
    *param_4 = 1;
    return 0;
  }
  return 4;
}
/* GHIDRADEC_FUNCTION index=2559 start=0x4096ce2 */

void _thread_dup(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (*(int *)(*(int *)(param_1 + 0x24) + 0x4c) == 0) {
    uVar1 = _thread_user_state(param_1);
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x24) + 0x48);
  }
  piVar2 = (int *)_thread_user_state(param_2);
  _bcopy(uVar1,piVar2,0x48);
  *piVar2 = (int)*(sword *)(*(int *)(*(int *)(param_2 + 0xc) + 0x34) + 0x30);
  piVar2[1] = 1;
  *(word *)(piVar2 + 0x10) = *(word *)(piVar2 + 0x10) & 0x3ffe;
  if (piVar2[0xf] != piVar2[8]) {
    piVar2[0xf] = piVar2[0xf] + 4;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2560 start=0x4096d5a */

undefined4 _thread_userstack(undefined4 param_1,int param_2,int param_3,uint param_4,int *param_5)

{
  int iVar1;
  
  if (*param_5 == 0) {
    *param_5 = 0x4000000;
  }
  if (param_2 == 1) {
    if (param_4 < 0x12) {
      return 4;
    }
    iVar1 = 0x4000000;
    if (*(int *)(param_3 + 0x3c) != 0) {
      iVar1 = *(int *)(param_3 + 0x3c);
    }
    *param_5 = iVar1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2561 start=0x4096da2 */

undefined4
_thread_entrypoint(undefined4 param_1,int param_2,int param_3,uint param_4,undefined4 *param_5)

{
  if (param_2 == 1) {
    if (param_4 < 0x12) {
      return 4;
    }
    *param_5 = *(undefined4 *)(param_3 + 0x44);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=2562 start=0x4096dcc */

void _pcb_terminate(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x24);
  iVar2 = *(int *)(iVar1 + 0x4c);
  if (iVar2 != 0) {
    uVar3 = 0x138;
    if (_cpu_type != '\0') {
      uVar3 = 0x244;
    }
    _kfree(iVar2,uVar3);
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  _zfree(_pcb_zone,iVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=2563 start=0x4096e20 */

int _pmap_pte(int param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  
  puVar1 = (uint *)(*(int *)(param_1 + 8) +
                   ((_m68k_pt1_mask & param_2) >> (_m68k_pt1_shift & 0x3f)) * 4);
  if (((byte)*puVar1 & 3) == _m68k_pt1_desctype) {
    puVar1 = (uint *)(((*puVar1 >> 9) << (_m68k_pt1_l2ptr & 0x3f)) +
                     ((_m68k_pt2_mask & param_2) >> (_m68k_pt2_shift & 0x3f)) * 4);
    if (((byte)*puVar1 & 3) == _m68k_pt2_desctype) {
      iVar2 = ((*puVar1 >> 7) << (_m68k_pt2_l3ptr & 0x3f)) +
              ((_m68k_pte_mask & param_2) >> (_m68k_pte_shift & 0x3f)) * 4;
    }
    else {
      iVar2 = -3;
    }
  }
  else {
    iVar2 = -4;
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2564 start=0x4096ec2 */

int _pmap_pte_valid(int param_1,uint param_2)

{
  return ((*(uint *)(((*(uint *)(*(int *)(param_1 + 8) +
                                ((_m68k_pt1_mask & param_2) >> (_m68k_pt1_shift & 0x3f)) * 4) >> 9)
                     << (_m68k_pt1_l2ptr & 0x3f)) +
                    ((_m68k_pt2_mask & param_2) >> (_m68k_pt2_shift & 0x3f)) * 4) >> 7) <<
         (_m68k_pt2_l3ptr & 0x3f)) + ((_m68k_pte_mask & param_2) >> (_m68k_pte_shift & 0x3f)) * 4;
}
/* GHIDRADEC_FUNCTION index=2565 start=0x4096f38 */

void _m68k_protection_init(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)0x4096f5c;
  do {
    if (puVar1 < (undefined4 *)0x4096f79) {
                    /* WARNING: Jumptable at 0x04096f5a did not pass sanity check. */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)*puVar1)();
      return;
    }
    puVar1 = puVar1 + 1;
  } while ((int)puVar1 < 0x4096f79);
  return;
}
/* GHIDRADEC_FUNCTION index=2566 start=0x4097224 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _pmap_set_page_size(void)

{
  byte bVar1;
  int iVar2;
  
  _m68k_page_mask = _m68k_page_size + -1;
  _m68k_page_shift = 0;
  iVar2 = 1;
  if (_m68k_page_size != 1) {
    do {
      _m68k_page_shift = _m68k_page_shift + 1;
      iVar2 = iVar2 * 2;
    } while (_m68k_page_size != iVar2);
  }
  _m68k_tic = 5;
  if (_m68k_page_size == 0x1000) {
    _m68k_tic = 6;
  }
  _m68k_pte_elemsize = 4;
  _m68k_pte_entries = 1 << _m68k_tic;
  _m68k_pte_size = _m68k_pte_entries << 2;
  _m68k_pte_shift = _m68k_page_shift;
  _m68k_pte_mask = _m68k_pte_entries + -1 << (_m68k_page_shift & 0x3f);
  _m68k_pte_maps = _m68k_pte_entries << (_m68k_page_shift & 0x3f);
  _m68k_pte_pfn = 0xc;
  if (_cpu_type == '\0') {
    _m68k_pte_pfn = 8;
  }
  _m68k_tib = 7;
  _m68k_pt2_entries = 0x80;
  _m68k_pt2_size = 0x200;
  _m68k_pt2_shift = _m68k_tic + _m68k_page_shift;
  _m68k_pt2_mask = 0x7f << (_m68k_pt2_shift & 0x3f);
  _m68k_pt2_maps = 0x80 << (_m68k_pt2_shift & 0x3f);
  _m68k_pt2_desctype = 2;
  _m68k_pt2_l3ptr = 7;
  _m68k_tia = 7;
  _m68k_pt1_elemsize = 4;
  _m68k_pt1_entries = 0x80;
  _m68k_pt1_size = 0x200;
  _m68k_pt1_shift = _m68k_pt2_shift + 7;
  _m68k_pt1_mask = 0x7f << (_m68k_pt2_shift + 7 & 0x3f);
  _m68k_pt1_desctype = 2;
  _m68k_pt1_l2ptr = 9;
  _m68k_cache = 3;
  if (_cache != 0) {
    _m68k_cache = 1;
  }
  _m68k_cache_inhibit_serial = 2;
  _m68k_cache_inhibit_nonserial = 3;
  bVar1 = bRam040b57ba | 0x80;
  if (_m68k_page_size == 0x2000) {
    bVar1 = bRam040b57ba | 0xc0;
  }
  bRam040b57ba = bVar1;
  if (_cpu_type == '\0') {
    _m68k_cache = -(int)-(_cache == 0);
    _m68k_cache_inhibit_serial = 1;
    _m68k_cache_inhibit_nonserial = 1;
    _m68k_kernel_mmu_030_tc._0_1_ = _m68k_kernel_mmu_030_tc._0_1_ | 0x82;
    _m68k_kernel_mmu_030_tc._1_1_ = (char)_m68k_page_shift << 4;
    _m68k_kernel_mmu_030_tc._2_1_ = 0x77;
    ram0x040b57b3 = ram0x040b57b3 & 0xfffffff | _m68k_tic << 0x1c;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2567 start=0x40973f4 */

int _pmap_size(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = _max_virtual_size;
  if (param_1 != (undefined4 *)0x0) {
    puVar2 = param_1;
  }
  iVar1 = ((int)puVar2 + _m68k_pt2_maps + -1) / _m68k_pt2_maps;
  return _m68k_pt1_size + _m68k_pt2_size * iVar1 + _m68k_pte_size * _m68k_pt2_entries * iVar1;
}
/* GHIDRADEC_FUNCTION index=2568 start=0x4097446 */

int _pmap_map(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,
             undefined4 param_6)

{
  int iVar1;
  
  iVar1 = _page_size;
  for (; param_2 < param_3; param_2 = iVar1 + param_2) {
    _pmap_enter_mapping(_kernel_pmap,param_1,param_2,param_4,0,param_5,param_6);
    param_1 = iVar1 + param_1;
  }
  return param_1;
}
/* GHIDRADEC_FUNCTION index=2569 start=0x40974a0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _pmap_bootstrap(int param_1,int param_2,uint *param_3,undefined4 *param_4,int param_5)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined uStack_11;
  undefined uStack_d;
  int iStack_c;
  int iStack_8;
  
  sub_4096F96(_pt_zone,_m68k_pt1_size);
  sub_4096F96(_pte_zone,_m68k_pte_size);
  _m68k_protection_init();
  _m68k_ptes_per_page = _page_size >> (_m68k_page_shift & 0x3f);
  _kernel_pmap = _kernel_pmap_store;
  _lock_init(&_pmap_lock,0);
  if (_cpu_type == '\0') {
    uVar5 = 0x10;
  }
  else {
    uVar5 = _m68k_pt1_elemsize * _m68k_pt1_entries;
  }
  uVar5 = uVar5 * ((uVar5 + *(int *)(param_1 + 0x14) + -1) / uVar5);
  *(uint *)((int)_kernel_pmap + 8) = uVar5;
  iVar2 = _pmap_size(0);
  _avail_kernel_map = _m68k_pt1_size + uVar5;
  iVar4 = iVar2 + uVar5;
  _max_kernel_map = iVar4;
  *(int *)(param_1 + 0x14) = iVar4;
  puVar1 = (uint *)_kernel_pmap;
  *(uint *)((int)_kernel_pmap + 0xc) = 1;
  *(byte *)((int)puVar1 + 3) = (byte)*puVar1 & 0xfe | 2;
  puVar1 = (uint *)_kernel_pmap;
  *(uint *)_kernel_pmap =
       *(uint *)_kernel_pmap & 0x8000ffff | (_m68k_pt1_entries - 1U & 0x7fff) << 0x10;
  puVar1[1] = uVar5 & 0xfffffff0 | puVar1[1] & 0xf;
  _m68k_kernel_mmu_rp._4_4_ = puVar1[1];
  _m68k_kernel_mmu_rp._0_3_ = (undefined3)(*puVar1 >> 8);
  _m68k_kernel_mmu_rp._3_1_ = (undefined)*puVar1;
  _bzero(uVar5,iVar2);
  uVar5 = ~_page_mask & 0xf0fffff0;
  _pmap_map(uVar5,uVar5,~_page_mask & _page_mask + 0xf0fffff4,3,0,1);
  if (_cpu_type == '\0') {
    _m68k_kernel_mmu_030_tt._0_1_ = _slot_id._0_1_;
    _m68k_kernel_mmu_030_tt._1_1_ = 0xf;
    _m68k_kernel_mmu_030_tt._3_1_ = (byte)_m68k_kernel_mmu_030_tt & 0xcb | 0x43;
    _m68k_kernel_mmu_030_tt._2_1_ =
         -(_cache == 0) & 4U | _m68k_kernel_mmu_030_tt._2_1_ & 0xfb | 0x81;
  }
  else {
    _pmap_map(_slot_id,_slot_id,_slot_id + 0x20000,1,1,0);
    _pmap_map(_slot_id + 0x1000000,_slot_id + 0x1000000,_slot_id + 0x1020000,1,1,0);
    _pmap_map(_slot_id + 0x2000000,_slot_id + 0x2000000,_slot_id + 0x20c0040,3,0,1);
    _pmap_map(_slot_id + 0x2100000,_slot_id + 0x2100000,_slot_id + 0x211e000,3,0,1);
    switch(_machine_type) {
    case :
    case :
      uStack_11 = (undefined)((uint)(_slot_id + 0x4000000) >> 0x18);
      uStack_d = 3;
      _vidGetFBAddrAndSize(&iStack_8,&iStack_c);
      _pmap_map(iStack_8,iStack_8,iStack_c + iStack_8,3,0,1);
      break;
    case :
      uStack_11 = (undefined)((uint)(_slot_id + 0x4000000) >> 0x18);
      uStack_d = 0x2b;
      break;
    :
      uStack_11 = (undefined)((uint)(_slot_id + 0x4000000) >> 0x18);
      uStack_d = 3;
      _vidGetFBAddrAndSize(&iStack_8,&iStack_c);
      _pmap_map(_slot_id + 0x2200000,_slot_id + 0x2200000,_slot_id + 0x2209000,3,0,1);
      _pmap_map(_slot_id + 0x2210000,_slot_id + 0x2210000,_slot_id + 0x2210004,3,0,1);
      _pmap_map(_slot_id + 0x3e00000,_slot_id + 0x3e00000,_slot_id + 0x3e80000,3,0,0);
      _pmap_map(iStack_8,iStack_8,iStack_c + iStack_8,3,0,1);
      iVar2 = 0;
      if (0 < param_2) {
        iVar7 = 0;
        do {
          uVar5 = *(uint *)(param_1 + 0x14 + iVar7);
          if (_slot_id + 0x8000000U <= uVar5) {
            iVar3 = _pmap_size(*(int *)(param_1 + 0x18 + iVar7) - uVar5);
            _max_kernel_map = iVar3 + _max_kernel_map;
            iVar4 = iVar3 + iVar4;
            *(int *)(param_1 + 0x14) = iVar4;
            _pmap_map(uVar5,uVar5,*(undefined4 *)(param_1 + 0x18 + iVar7),3,1,0);
          }
          iVar7 = iVar7 + 0x1c;
          iVar2 = iVar2 + 1;
        } while (iVar2 < param_2);
      }
      _pmap_map(param_5,param_5,param_5 + 0xff4,3,0,1);
    }
    _m68k_kernel_mmu_040_tt._0_1_ = uStack_11;
    _m68k_kernel_mmu_040_tt._1_1_ = uStack_d;
    _m68k_kernel_mmu_040_tt._2_1_ = _m68k_kernel_mmu_040_tt._2_1_ & 0xbf | 0xa0;
    iVar4 = 3;
    if (_cache != 0) {
      iVar4 = 1;
    }
    ram0x040b57bf = ram0x040b57bf & 0x9fffffff | iVar4 << 0x1d;
  }
  *param_3 = 0x10000000;
  *param_4 = 0x14000000;
  _phys_map_vaddr1 = *param_3;
  _phys_map_vaddr2 = _page_size + *param_3;
  *param_3 = _phys_map_vaddr2;
  uVar5 = _page_size + *param_3;
  *param_3 = uVar5;
  uVar6 = _phys_map_vaddr1;
  if (_phys_map_vaddr1 < uVar5) {
    do {
      iVar4 = _pmap_pte(_kernel_pmap,uVar6);
      if (iVar4 < 0) {
        _pmap_expand_kernel(uVar6,iVar4);
      }
      uVar6 = _m68k_page_size + uVar6;
    } while (uVar6 < *param_3);
  }
  _phys_map_pte1 = _pmap_pte_valid(_kernel_pmap,_phys_map_vaddr1);
  _phys_map_pte2 = _pmap_pte_valid(_kernel_pmap,_phys_map_vaddr2);
  *param_3 = ~_page_mask & _page_mask + *param_3;
  return;
}
/* GHIDRADEC_FUNCTION index=2570 start=0x40979c0 */

void _pmap_init(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uStack_8;
  
  iVar3 = 0;
  iVar2 = 0;
  if (0 < param_2) {
    do {
      iVar3 = *(int *)(param_1 + 0xc) + iVar3;
      param_1 = param_1 + 0x1c;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  uVar1 = ~_page_mask & _page_mask + iVar3 * 0xc;
  _kmem_alloc_wired(_kernel_map,&uStack_8,uVar1);
  _bzero(uStack_8,uVar1);
  _pmap_zone = _zinit(0x18,0x2580,0,0,&aPmap);
  _pv_list_zone = _zinit(0xc,1200000,0,0,&aPvList);
  _pv_head_table = uStack_8;
  _managed_page_count = iVar3;
  return;
}
/* GHIDRADEC_FUNCTION index=2571 start=0x4097a74 */

uint * _pmap_create(int param_1)

{
  uint *puVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    puVar1 = (uint *)_zalloc(_pmap_zone);
    _bzero(puVar1,0x18);
    puVar1[3] = 1;
    *(byte *)((int)puVar1 + 3) = (byte)*puVar1 & 0xfe | 2;
    *puVar1 = *puVar1 & 0x8000ffff | (_m68k_pt1_entries - 1U & 0x7fff) << 0x10;
    uVar2 = sub_4096FD0(_pt_zone);
    puVar1[2] = uVar2;
    puVar1[1] = uVar2 & 0xfffffff0 | puVar1[1] & 0xf;
  }
  else {
    puVar1 = (uint *)0x0;
  }
  return puVar1;
}
/* GHIDRADEC_FUNCTION index=2572 start=0x4097af4 */

void _pmap_destroy(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) &&
     (iVar1 = *(int *)(param_1 + 0xc), *(int *)(param_1 + 0xc) = iVar1 + -1, iVar1 == 1)) {
    _pmap_free_maps(param_1,*(undefined4 *)(param_1 + 8));
    _zfree(_pmap_zone,param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2573 start=0x4097b58 */

void _pmap_free_maps(undefined4 param_1,uint *param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  
  iVar2 = 0;
  puVar4 = param_2;
  if (0 < _m68k_pt1_entries) {
    do {
      if (((byte)*puVar4 & 3) == _m68k_pt1_desctype) {
        puVar1 = (uint *)((*puVar4 >> 9) << (_m68k_pt1_l2ptr & 0x3f));
        puVar3 = puVar1;
        if (puVar1 < puVar1 + _m68k_pt2_entries) {
          do {
            if (((byte)*puVar3 & 3) == _m68k_pt2_desctype) {
              sub_40970C6(_pte_zone,(*puVar3 >> 7) << (_m68k_pt2_l3ptr & 0x3f));
            }
            puVar3 = puVar3 + 1;
          } while (puVar3 < puVar1 + _m68k_pt2_entries);
        }
        sub_40970C6(_pt_zone,puVar1);
      }
      iVar2 = iVar2 + 1;
      puVar4 = puVar4 + 1;
    } while (iVar2 < _m68k_pt1_entries);
  }
  sub_40970C6(_pt_zone,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=2574 start=0x4097c1a */

void _pmap_reference(int param_1)

{
  if (param_1 != 0) {
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2575 start=0x4097c50 */

void _pmap_remove_range(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  byte bVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  int *piVar8;
  uint *puVar9;
  
  if (param_1 == _kernel_pmap) {
    _pflush_super();
  }
  else if (_active_threads != 0) {
    _pflush_user();
  }
  do {
    while( true ) {
      if (param_3 <= param_2) {
        return;
      }
      puVar4 = (uint *)_pmap_pte(param_1,param_2);
      if (-1 < (int)puVar4) break;
      uVar6 = _m68k_pt2_maps;
      if (puVar4 == (uint *)0xfffffffd) {
        uVar6 = _m68k_pte_maps;
      }
      param_2 = uVar6 + (-uVar6 & param_2);
      if (param_2 == 0) {
        return;
      }
    }
    uVar6 = _m68k_page_shift & 0x3f;
    iVar5 = _pmap_pte(param_1,_m68k_pte_maps * ((_m68k_pte_maps + param_2) / _m68k_pte_maps) + -1);
    puVar7 = puVar4 + (param_3 - param_2 >> uVar6);
    if ((uint *)(iVar5 + 4) < puVar4 + (param_3 - param_2 >> uVar6)) {
      puVar7 = (uint *)(iVar5 + 4);
    }
    puVar9 = puVar4;
    if (puVar4 < puVar7) {
      do {
        if ((*puVar9 & 0x13) == 0x11) {
          if (_cpu_type == '\0') {
            uVar6 = *puVar9 >> 8;
          }
          else {
            uVar6 = *puVar9 >> 0xc;
          }
          iVar5 = _vm_phys_to_vm_page(uVar6 << (_m68k_pte_pfn & 0x3f));
          if (iVar5 != 0) {
            *(byte *)(iVar5 + 0x1e) = *(byte *)(iVar5 + 0x1e) & 0xfb;
          }
        }
        puVar9 = puVar9 + 1;
        puVar3 = puVar4;
      } while (puVar9 < puVar7);
      for (; puVar3 < puVar7; puVar3 = puVar3 + _m68k_ptes_per_page) {
        if (_cpu_type == '\0') {
          uVar6 = *puVar3 >> 8;
        }
        else {
          uVar6 = *puVar3 >> 0xc;
        }
        if (((*puVar3 & 3) == 1) &&
           (iVar5 = _pmap_phys_to_index(uVar6 << (_m68k_pte_pfn & 0x3f)), iVar5 != -1)) {
          *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
          if (_cpu_type == '\0') {
            bVar2 = (byte)*puVar3 & 0x20;
          }
          else {
            bVar2 = *(byte *)((int)puVar3 + 2) & 8;
          }
          if (bVar2 != 0) {
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
          }
          piVar1 = (int *)(_pv_head_table + iVar5 * 0xc);
          if ((param_2 == piVar1[2]) && (param_1 == piVar1[1])) {
            piVar8 = (int *)*piVar1;
            if (piVar8 == (int *)0x0) {
              piVar1[1] = 0;
              goto loc_4097E1C;
            }
            *piVar1 = *piVar8;
            piVar1[1] = piVar8[1];
            piVar1[2] = piVar8[2];
          }
          else {
            for (piVar8 = (int *)*piVar1;
                (piVar8 != (int *)0x0 && ((param_2 != piVar8[2] || (param_1 != piVar8[1]))));
                piVar8 = (int *)*piVar8) {
              piVar1 = piVar8;
            }
            *piVar1 = *piVar8;
          }
          _zfree(_pv_list_zone,piVar8);
        }
loc_4097E1C:
        *puVar3 = 0;
        param_2 = _page_size + param_2;
      }
    }
    if (1 < _m68k_ptes_per_page) {
      _bzero(puVar4,_m68k_pte_elemsize * ((int)puVar7 - (int)puVar4 >> 2));
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2576 start=0x4097e6c */

byte _pmap_remove(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  bVar5 = 0;
  if (param_1 != 0) {
    cVar1 = '\0';
    cVar2 = param_1 < 0;
    cVar3 = param_1 == 0;
    cVar4 = '\0';
    bVar5 = 0;
    _pmap_remove_range(param_1,param_2,param_3);
    bVar5 = cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
  }
  return bVar5;
}
/* GHIDRADEC_FUNCTION index=2577 start=0x4097e9c */

byte _pmap_remove_all(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  
  iVar5 = _vm_phys_to_vm_page(param_1);
  iVar6 = _pmap_phys_to_index(param_1);
  bVar11 = false;
  bVar10 = SBORROW4(-1,iVar6);
  iVar8 = -1 - iVar6;
  bVar9 = iVar6 == -1;
  if (!bVar9) {
    piVar1 = (int *)(_pv_head_table + iVar6 * 0xc);
    while( true ) {
      iVar6 = piVar1[1];
      bVar10 = false;
      bVar9 = true;
      iVar8 = 0;
      if (iVar6 == 0) break;
      if (iVar6 == _kernel_pmap) {
        _pflush_super();
      }
      else if (_active_threads != 0) {
        _pflush_user();
      }
      iVar8 = piVar1[2];
      puVar7 = (undefined4 *)_pmap_pte_valid(iVar6,iVar8);
      *(int *)(iVar6 + 0x10) = *(int *)(iVar6 + 0x10) + -1;
      if (_cpu_type == '\0') {
        bVar4 = *(byte *)((int)puVar7 + 3) & 0x20;
      }
      else {
        bVar4 = *(byte *)((int)puVar7 + 2) & 8;
      }
      if (bVar4 != 0) {
        *(int *)(iVar6 + 0x14) = *(int *)(iVar6 + 0x14) + -1;
      }
      piVar3 = (int *)*piVar1;
      if (piVar3 == (int *)0x0) {
        piVar1[1] = 0;
      }
      else {
        *piVar1 = *piVar3;
        piVar1[1] = piVar3[1];
        piVar1[2] = piVar3[2];
        _zfree(_pv_list_zone,piVar3);
      }
      puVar2 = puVar7 + _m68k_ptes_per_page;
      bVar11 = puVar2 < puVar7;
      if (puVar7 < puVar2) {
        do {
          if (((*(byte *)((int)puVar7 + 3) & 0x13) == 0x11) && (iVar5 != 0)) {
            *(byte *)(iVar5 + 0x1e) = *(byte *)(iVar5 + 0x1e) & 0xfb;
          }
          *puVar7 = 0;
          _pmap_collapse(iVar6,iVar8,puVar7);
          puVar7 = puVar7 + 1;
          iVar8 = _m68k_page_size + iVar8;
          bVar11 = puVar2 < puVar7;
        } while (!bVar11 && puVar2 != puVar7);
      }
    }
  }
  return bVar11 << 4 | (iVar8 < 0) << 3 | bVar9 << 2 | bVar10 << 1;
}
/* GHIDRADEC_FUNCTION index=2578 start=0x4097fba */

void _pmap_collapse(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  byte *pbVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  if ((param_1 != _kernel_pmap) && (_pmap_coll != 0)) {
    uVar4 = param_3 + ((_m68k_pte_mask & param_2) >> (_m68k_pte_shift & 0x3f)) * -4;
    uVar1 = uVar4 + _m68k_pte_entries * 4;
    for (; uVar4 < uVar1; uVar4 = uVar4 + 4) {
      if ((*(byte *)(uVar4 + 3) & 3) == 1) {
        return;
      }
    }
    puVar2 = (uint *)(*(int *)(param_1 + 8) +
                     ((_m68k_pt1_mask & param_2) >> (_m68k_pt1_shift & 0x3f)) * 4);
    puVar6 = (uint *)(((*puVar2 >> 9) << (_m68k_pt1_l2ptr & 0x3f)) +
                     ((_m68k_pt2_mask & param_2) >> (_m68k_pt2_shift & 0x3f)) * 4);
    sub_40970C6(_pte_zone,(*puVar6 >> 7) << (_m68k_pt2_l3ptr & 0x3f));
    *(byte *)((int)puVar6 + 3) = *(byte *)((int)puVar6 + 3) & 0xfc;
    puVar6 = puVar6 + -((_m68k_pt2_mask & param_2) >> (_m68k_pt2_shift & 0x3f));
    for (puVar5 = puVar6; puVar5 < puVar6 + _m68k_pt2_entries; puVar5 = puVar5 + 1) {
      if (_m68k_pt2_desctype == ((byte)*puVar5 & 3)) {
        return;
      }
    }
    sub_40970C6(_pt_zone,puVar6);
    pbVar3 = (byte *)((int)puVar2 + 3);
    *pbVar3 = *pbVar3 & 0xfc;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2579 start=0x40980d6 */

byte _pmap_copy_on_write(undefined4 param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  iVar5 = _pmap_phys_to_index(param_1);
  bVar10 = false;
  bVar9 = SBORROW4(-1,iVar5);
  iVar3 = -1 - iVar5;
  bVar8 = iVar5 == -1;
  if (!bVar8) {
    puVar1 = (undefined4 *)(_pv_head_table + iVar5 * 0xc);
    bVar10 = false;
    puVar4 = (undefined4 *)puVar1[1];
    while( true ) {
      bVar9 = false;
      iVar3 = 0;
      bVar8 = true;
      if (puVar4 == (undefined4 *)0x0) break;
      iVar3 = puVar1[1];
      if (iVar3 == _kernel_pmap) {
        _pflush_super();
      }
      else if (_active_threads != 0) {
        _pflush_user();
      }
      uVar6 = _pmap_pte_valid(iVar3,puVar1[2]);
      uVar2 = uVar6 + _m68k_ptes_per_page * 4;
      bVar10 = uVar2 < uVar6;
      if (uVar6 < uVar2) {
        pbVar7 = (byte *)(uVar6 + 3);
        do {
          if ((*pbVar7 & 3) == 1) {
            *pbVar7 = *pbVar7 | 4;
          }
          pbVar7 = pbVar7 + 4;
          uVar6 = uVar6 + 4;
          bVar10 = uVar2 < uVar6;
        } while (!bVar10 && uVar2 != uVar6);
      }
      puVar1 = (undefined4 *)*puVar1;
      puVar4 = puVar1;
    }
  }
  return bVar10 << 4 | (iVar3 < 0) << 3 | bVar8 << 2 | bVar9 << 1;
}
/* GHIDRADEC_FUNCTION index=2580 start=0x409818a */

uint _pmap_protect(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  
  if (param_1 != 0) {
    if (param_4 == 0) {
      param_4 = _pmap_remove(param_1,param_2,param_3);
    }
    else {
      uVar1 = *(undefined4 *)(_protection_codes + param_4 * 4);
      if (param_1 == _kernel_pmap) {
        param_4 = _pflush_super();
      }
      else if (_active_threads != 0) {
        param_4 = _pflush_user();
      }
      if (param_2 < param_3) {
        do {
          uVar2 = _m68k_pte_maps + (-_m68k_pte_maps & param_2);
          uVar4 = _pmap_pte(param_1,param_2);
          param_4 = uVar4;
          if (0 < (int)uVar4) {
            if (param_3 < uVar2) {
              param_4 = param_3 - param_2 >> (_m68k_page_shift & 0x3f);
              uVar5 = uVar4 + param_4 * 4;
            }
            else {
              param_4 = _pmap_pte(param_1,uVar2 - 1);
              uVar5 = param_4 + 4;
            }
            if (uVar4 < uVar5) {
              pbVar6 = (byte *)(uVar4 + 3);
              do {
                bVar3 = ((byte)uVar1 & 1) << 2 | *pbVar6 & 0xfb;
                param_4 = (uint)bVar3;
                *pbVar6 = bVar3;
                pbVar6 = pbVar6 + 4;
                uVar4 = uVar4 + 4;
              } while (uVar4 < uVar5);
            }
          }
          param_2 = uVar2;
        } while (uVar2 < param_3);
      }
      if (param_1 == _kernel_pmap) {
        param_4 = (uint)(byte)((param_1 < _kernel_pmap) << 4 |
                               ((int)(param_1 - _kernel_pmap) < 0) << 3 | 4U |
                               SBORROW4(param_1,_kernel_pmap) << 1 | param_1 < _kernel_pmap);
      }
    }
  }
  return param_4;
}
/* GHIDRADEC_FUNCTION index=2581 start=0x409827e */

void _pmap_enter(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  _pmap_enter_mapping(param_1,param_2,param_3,param_4,param_5,1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=2582 start=0x40982a6 */

void _pmap_enter_mapping(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                        int param_7)

{
  undefined4 *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  byte bVar4;
  int iVar5;
  byte bVar6;
  bool bVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  uint *puVar11;
  undefined4 *puVar12;
  byte *pbStack_10;
  undefined2 uStack_8;
  byte bStack_6;
  byte bStack_5;
  
  bVar7 = false;
  if (param_1 != 0) {
    if (param_4 == 0) {
      _pmap_remove(param_1,param_2,_page_size + param_2);
    }
    else {
      if ((param_6 == 0) ||
         ((_managed_page_count != 0 && (iVar8 = _pmap_phys_to_index(param_3), iVar8 == -1)))) {
        bVar7 = true;
      }
      uVar3 = *(undefined4 *)(_protection_codes + param_4 * 4);
      puVar12 = (undefined4 *)0x0;
      while( true ) {
        while (puVar9 = (uint *)_pmap_pte(param_1,param_2), (int)puVar9 < 0) {
          if (param_1 == _kernel_pmap) {
            _pmap_expand_kernel(param_2,puVar9);
          }
          else {
            _pmap_expand(param_1,param_2,puVar9);
          }
        }
        if (_pv_head_table == 0) goto loc_4098444;
        if (_cpu_type == '\0') {
          uVar10 = *puVar9 >> 8;
        }
        else {
          uVar10 = *puVar9 >> 0xc;
        }
        if (((*puVar9 & 3) == 1) && (param_3 == uVar10 << (_m68k_pte_pfn & 0x3f))) goto loc_4098444;
        _pmap_remove_range(param_1,param_2,_page_size + param_2);
        iVar8 = _pmap_phys_to_index(param_3);
        if (iVar8 == -1) goto loc_4098444;
        puVar1 = (undefined4 *)(_pv_head_table + iVar8 * 0xc);
        if (puVar1[1] == 0) {
          puVar1[2] = param_2;
          puVar1[1] = param_1;
          *puVar1 = 0;
          goto loc_4098436;
        }
        if (puVar12 != (undefined4 *)0x0) break;
        puVar12 = (undefined4 *)_zalloc(_pv_list_zone);
      }
      puVar12[2] = param_2;
      puVar12[1] = param_1;
      *puVar12 = *puVar1;
      *puVar1 = puVar12;
      puVar12 = (undefined4 *)0x0;
loc_4098436:
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
      if (param_5 != 0) {
        *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      }
loc_4098444:
      iVar8 = _m68k_page_size;
      if ((*puVar9 & 3) == 1) {
        if (param_1 == _kernel_pmap) {
          _pflush_super();
        }
        else if (_active_threads != 0) {
          _pflush_user();
        }
        puVar2 = puVar9 + _m68k_ptes_per_page;
        if (puVar9 < puVar2) {
          bVar6 = ((byte)uVar3 & 1) << 2;
          puVar11 = (uint *)((int)puVar9 + 3);
          pbStack_10 = (byte *)((int)puVar9 + 2);
          do {
            bVar4 = *(byte *)puVar11;
            *(byte *)puVar11 = bVar6 | bVar4 & 0xfb;
            if (_cpu_type == '\0') {
              *(byte *)puVar11 = ((byte)param_5 & 1) << 5 | bVar6 | bVar4 & 0xdb;
            }
            else {
              *pbStack_10 = ((byte)param_5 & 1) << 3 | *pbStack_10 & 0xf7;
            }
            uVar10 = _m68k_cache;
            if ((bVar7) && (uVar10 = _m68k_cache_inhibit_nonserial, param_7 != 0)) {
              uVar10 = _m68k_cache_inhibit_serial;
            }
            if (_cpu_type == '\0') {
              *(byte *)puVar11 = ((byte)uVar10 & 1) << 6 | *(byte *)puVar11 & 0xbf;
            }
            else {
              *puVar11 = *puVar11 & 0x9fffffff | (uVar10 & 3) << 0x1d;
            }
            puVar11 = puVar11 + 1;
            pbStack_10 = pbStack_10 + 4;
            puVar9 = puVar9 + 1;
          } while (puVar9 < puVar2);
        }
      }
      else {
        bStack_6 = 0;
        bStack_5 = ((byte)uVar3 & 1) << 2 | 1;
        if ((_cpu_type != '\0') && (param_1 == _kernel_pmap)) {
          bStack_6 = 4;
        }
        if (_cpu_type == '\0') {
          bStack_5 = ((byte)param_5 & 1) << 5 | bStack_5;
        }
        else {
          bStack_6 = ((byte)param_5 & 1) << 3 | bStack_6;
        }
        uVar10 = _m68k_cache;
        if ((bVar7) && (uVar10 = _m68k_cache_inhibit_nonserial, param_7 != 0)) {
          uVar10 = _m68k_cache_inhibit_serial;
        }
        if (_cpu_type == '\0') {
          bStack_5 = ((byte)uVar10 & 1) << 6 | bStack_5;
        }
        else {
          bStack_5 = bStack_5 & 0x9f | (byte)(((uVar10 & 3) << 0x1d) >> 0x18);
        }
        param_3 = param_3 >> (_m68k_pte_pfn & 0x3f);
        if (_cpu_type == '\0') {
          uVar10 = CONCAT31((int3)param_3,bStack_5);
        }
        else {
          uVar10 = param_3 << 0xc | (uint)CONCAT11(bStack_6,bStack_5);
        }
        uStack_8 = (undefined2)(uVar10 >> 0x10);
        bStack_6 = (byte)(uVar10 >> 8);
        bStack_5 = (byte)uVar10;
        puVar2 = puVar9 + _m68k_ptes_per_page;
        for (; puVar9 < puVar2; puVar9 = puVar9 + 1) {
          *puVar9 = CONCAT31(CONCAT21(uStack_8,bStack_6),bStack_5);
          iVar5 = iVar8 + CONCAT31(CONCAT21(uStack_8,bStack_6),bStack_5);
          uStack_8 = (undefined2)((uint)iVar5 >> 0x10);
          bStack_6 = (byte)((uint)iVar5 >> 8);
          bStack_5 = (byte)iVar5;
        }
      }
      if (puVar12 != (undefined4 *)0x0) {
        _zfree(_pv_list_zone,puVar12);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2583 start=0x409865e */

uint _pmap_change_wiring(uint param_1,undefined4 param_2,byte param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  
  uVar2 = _pmap_pte_valid(param_1,param_2);
  if (param_1 == _kernel_pmap) {
    uVar3 = _pflush_super();
  }
  else {
    uVar3 = uVar2;
    if (_active_threads != 0) {
      uVar3 = _pflush_user();
    }
  }
  uVar3 = CONCAT31((int3)(uVar3 >> 8),*(byte *)(uVar2 + 3)) & 0xffffff03;
  if (((*(byte *)(uVar2 + 3) & 3) == 1) &&
     (uVar1 = uVar2 + _m68k_ptes_per_page * 4, uVar3 = _m68k_ptes_per_page, uVar2 < uVar1)) {
    uVar3 = CONCAT31((int3)(_m68k_ptes_per_page >> 8),param_3) & 0xffffff01;
    pbVar6 = (byte *)(uVar2 + 3);
    pbVar5 = (byte *)(uVar2 + 2);
    do {
      if (_cpu_type == '\0') {
        bVar4 = (param_3 & 1) << 5 | *pbVar6 & 0xdf;
        *pbVar6 = bVar4;
      }
      else {
        bVar4 = (param_3 & 1) << 3 | *pbVar5 & 0xf7;
        *pbVar5 = bVar4;
      }
      uVar3 = CONCAT31((int3)(uVar3 >> 8),bVar4);
      pbVar6 = pbVar6 + 4;
      pbVar5 = pbVar5 + 4;
      uVar2 = uVar2 + 4;
    } while (uVar2 < uVar1);
  }
  if (param_1 == _kernel_pmap) {
    uVar3 = (uint)(byte)((param_1 < _kernel_pmap) << 4 | ((int)(param_1 - _kernel_pmap) < 0) << 3 |
                         4U | SBORROW4(param_1,_kernel_pmap) << 1 | param_1 < _kernel_pmap);
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=2584 start=0x409871e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _pmap_extract(int param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint *puVar4;
  uint uVar5;
  
  puVar4 = (uint *)_pmap_pte(param_1,param_2);
  if (((int)puVar4 < 0) || ((*puVar4 & 3) != 1)) {
    bVar3 = _m68k_kernel_mmu_030_tt._1_1_;
    bVar1 = _m68k_kernel_mmu_030_tt._0_1_;
    iVar2 = ram0x040b57b6;
    if (_cpu_type != '\0') {
      bVar3 = _m68k_kernel_mmu_040_tt._1_1_;
      bVar1 = _m68k_kernel_mmu_040_tt._0_1_;
      iVar2 = ram0x040b57be;
    }
    uVar5 = 0;
    if (((param_1 == _kernel_pmap) && (iVar2 < 0)) &&
       ((uint)bVar1 == (~(uint)bVar3 & param_2 >> 0x18))) {
      uVar5 = param_2;
    }
  }
  else {
    if (_cpu_type == '\0') {
      uVar5 = *puVar4 >> 8;
    }
    else {
      uVar5 = *puVar4 >> 0xc;
    }
    uVar5 = (_m68k_page_mask & param_2) + (uVar5 << (_m68k_pte_pfn & 0x3f));
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=2585 start=0x40987f8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _pmap_resident_extract(int param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint *puVar4;
  uint uVar5;
  
  puVar4 = (uint *)_pmap_pte(param_1,param_2);
  if (((int)puVar4 < 0) || ((*puVar4 & 3) != 1)) {
    bVar3 = _m68k_kernel_mmu_030_tt._1_1_;
    bVar1 = _m68k_kernel_mmu_030_tt._0_1_;
    iVar2 = ram0x040b57b6;
    if (_cpu_type != '\0') {
      bVar3 = _m68k_kernel_mmu_040_tt._1_1_;
      bVar1 = _m68k_kernel_mmu_040_tt._0_1_;
      iVar2 = ram0x040b57be;
    }
    uVar5 = 0;
    if (((param_1 == _kernel_pmap) && (iVar2 < 0)) &&
       ((uint)bVar1 == (~(uint)bVar3 & param_2 >> 0x18))) {
      uVar5 = param_2;
    }
  }
  else {
    if (_cpu_type == '\0') {
      uVar5 = *puVar4 >> 8;
    }
    else {
      uVar5 = *puVar4 >> 0xc;
    }
    uVar5 = (_m68k_page_mask & param_2) + (uVar5 << (_m68k_pte_pfn & 0x3f));
  }
  return uVar5;
}
/* GHIDRADEC_FUNCTION index=2586 start=0x40988b0 */

void _pmap_expand_kernel(uint param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = (uint *)(*(int *)(_kernel_pmap + 8) +
                   ((_m68k_pt1_mask & param_1) >> (_m68k_pt1_shift & 0x3f)) * 4);
  if (param_2 == -4) {
    uVar2 = 1 << (_m68k_pt1_l2ptr & 0x3f);
    iVar4 = (uVar2 + _avail_kernel_map + -1) / uVar2 << (_m68k_pt1_l2ptr & 0x3f);
    _avail_kernel_map = iVar4;
    _bzero(iVar4,_m68k_pt2_size);
    _avail_kernel_map = _m68k_pt2_size + _avail_kernel_map;
    *puVar1 = (iVar4 >> (_m68k_pt1_l2ptr & 0x3f)) << 9 | *puVar1 & 0x1ff;
    *(byte *)((int)puVar1 + 3) = (byte)*puVar1 & 0xfb | 8;
    *(byte *)((int)puVar1 + 3) = (byte)*puVar1 & 0xf8 | 8 | (byte)_m68k_pt1_desctype & 3;
  }
  else {
    iVar4 = (*puVar1 >> 9) << (_m68k_pt1_l2ptr & 0x3f);
  }
  uVar2 = 1 << (_m68k_pt2_l3ptr & 0x3f);
  iVar3 = (uVar2 + _avail_kernel_map + -1) / uVar2 << (_m68k_pt2_l3ptr & 0x3f);
  _avail_kernel_map = _m68k_pte_size + iVar3;
  if (_max_kernel_map < _avail_kernel_map) {
                    /* WARNING: Subroutine does not return */
    _panic(aNoMoreRoomInKe);
  }
  _bzero(iVar3,_m68k_pte_size);
  puVar1 = (uint *)(iVar4 + ((_m68k_pt2_mask & param_1) >> (_m68k_pt2_shift & 0x3f)) * 4);
  *puVar1 = (iVar3 >> (_m68k_pt2_l3ptr & 0x3f)) << 7 | *puVar1 & 0x7f;
  *(byte *)((int)puVar1 + 3) = (byte)*puVar1 & 0xfb | 8;
  *(byte *)((int)puVar1 + 3) = bRam040c97cf & 3 | (byte)*puVar1 & 0xf8 | 8;
  return;
}
/* GHIDRADEC_FUNCTION index=2587 start=0x4098a14 */

void _pmap_expand(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int unaff_A2;
  
  uVar4 = _m68k_pt1_mask & param_2;
  uVar1 = _m68k_pt1_shift & 0x3f;
  uVar5 = _m68k_pt2_mask & param_2;
  uVar2 = _m68k_pt2_shift & 0x3f;
  if (param_3 == -4) {
    unaff_A2 = sub_4096FD0(_pt_zone);
  }
  iVar6 = sub_4096FD0(_pte_zone);
  iVar7 = _pmap_pte(param_1,param_2);
  if (iVar7 < 1) {
    puVar3 = (uint *)(*(int *)(param_1 + 8) + (uVar4 >> uVar1) * 4);
    if (param_3 == -4) {
      *puVar3 = (unaff_A2 >> (_m68k_pt1_l2ptr & 0x3f)) << 9 | *puVar3 & 0x1ff;
      *(byte *)((int)puVar3 + 3) = (byte)*puVar3 & 0xfb | 8;
      *(byte *)((int)puVar3 + 3) = (byte)*puVar3 & 0xf8 | 8 | (byte)_m68k_pt1_desctype & 3;
    }
    else {
      unaff_A2 = (*puVar3 >> 9) << (_m68k_pt1_l2ptr & 0x3f);
    }
    puVar3 = (uint *)(unaff_A2 + (uVar5 >> uVar2) * 4);
    *puVar3 = (iVar6 >> (_m68k_pt2_l3ptr & 0x3f)) << 7 | *puVar3 & 0x7f;
    *(byte *)((int)puVar3 + 3) = (byte)*puVar3 & 0xfb | 8;
    *(byte *)((int)puVar3 + 3) = bRam040c97cf & 3 | (byte)*puVar3 & 0xf8 | 8;
  }
  else {
    if (param_3 == -4) {
      sub_40970C6(_pt_zone,unaff_A2);
    }
    sub_40970C6(_pte_zone,iVar6);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2588 start=0x4098b48 */

void _pmap_copy(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2589 start=0x4098b50 */

void _pmap_update(void)

{
  _pflush_super();
  if (_active_threads != 0) {
    _pflush_user();
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2590 start=0x4098b6c */

void _pmap_collect(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (((param_1 != 0) && (param_1 != _kernel_pmap)) && (*(int *)(param_1 + 0x10) == 0)) {
    iVar2 = _m68k_pt1_elemsize * _m68k_pt1_entries;
    iVar1 = sub_4096FD0(_pt_zone);
    if (iVar1 != 0) {
      if (_active_threads != 0) {
        _pflush_user();
      }
      _pmap_remove_range(param_1,0,0xfffffffc);
      _bcopy(*(undefined4 *)(param_1 + 8),iVar1,iVar2);
      _bzero(*(undefined4 *)(param_1 + 8),iVar2);
      _pmap_free_maps(param_1,iVar1);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=2591 start=0x4098c08 */

undefined4 _pmap_kernel(void)

{
  return _kernel_pmap;
}
/* GHIDRADEC_FUNCTION index=2592 start=0x4098c16 */

void _pmap_pageable(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=2593 start=0x4098c1e */

undefined4 _pmap_attribute(void)

{
  return 4;
}
/* GHIDRADEC_FUNCTION index=2594 start=0x4098c28 */

byte _pmap_clear_modify(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int *piVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  
  iVar2 = _pmap_phys_to_index(param_1);
  bVar9 = false;
  bVar8 = SBORROW4(-1,iVar2);
  bVar6 = -1 - iVar2 < 0;
  bVar7 = iVar2 == -1;
  if (!bVar7) {
    piVar5 = (int *)(_pv_head_table + iVar2 * 0xc);
    do {
      iVar2 = piVar5[1];
      bVar6 = iVar2 < 0;
      bVar8 = false;
      bVar7 = true;
      if (iVar2 == 0) break;
      uVar3 = _pmap_pte_valid(iVar2,piVar5[2]);
      uVar1 = uVar3 + _m68k_ptes_per_page * 4;
      bVar9 = uVar1 < uVar3;
      if (uVar3 < uVar1) {
        pbVar4 = (byte *)(uVar3 + 3);
        do {
          *pbVar4 = *pbVar4 & 0xef;
          pbVar4 = pbVar4 + 4;
          uVar3 = uVar3 + 4;
          bVar9 = uVar1 < uVar3;
        } while (!bVar9 && uVar1 != uVar3);
      }
      piVar5 = (int *)*piVar5;
      bVar8 = false;
      bVar6 = (int)piVar5 < 0;
      bVar7 = piVar5 == (int *)0x0;
    } while (!bVar7);
  }
  return bVar9 << 4 | bVar6 << 3 | bVar7 << 2 | bVar8 << 1;
}
/* GHIDRADEC_FUNCTION index=2595 start=0x4098cac */

byte _pmap_clear_reference(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int *piVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  
  iVar2 = _pmap_phys_to_index(param_1);
  bVar9 = false;
  bVar8 = SBORROW4(-1,iVar2);
  bVar6 = -1 - iVar2 < 0;
  bVar7 = iVar2 == -1;
  if (!bVar7) {
    piVar5 = (int *)(_pv_head_table + iVar2 * 0xc);
    do {
      iVar2 = piVar5[1];
      bVar6 = iVar2 < 0;
      bVar8 = false;
      bVar7 = true;
      if (iVar2 == 0) break;
      uVar3 = _pmap_pte_valid(iVar2,piVar5[2]);
      uVar1 = uVar3 + _m68k_ptes_per_page * 4;
      bVar9 = uVar1 < uVar3;
      if (uVar3 < uVar1) {
        pbVar4 = (byte *)(uVar3 + 3);
        do {
          *pbVar4 = *pbVar4 & 0xf7;
          pbVar4 = pbVar4 + 4;
          uVar3 = uVar3 + 4;
          bVar9 = uVar1 < uVar3;
        } while (!bVar9 && uVar1 != uVar3);
      }
      piVar5 = (int *)*piVar5;
      bVar8 = false;
      bVar6 = (int)piVar5 < 0;
      bVar7 = piVar5 == (int *)0x0;
    } while (!bVar7);
  }
  return bVar9 << 4 | bVar6 << 3 | bVar7 << 2 | bVar8 << 1;
}
/* GHIDRADEC_FUNCTION index=2596 start=0x4098d30 */

int _pmap_is_referenced(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 0;
  iVar2 = _pmap_phys_to_index(param_1);
  if (iVar2 != -1) {
    piVar5 = (int *)(_pv_head_table + iVar2 * 0xc);
    while (piVar5[1] != 0) {
      uVar3 = _pmap_pte_valid(piVar5[1],piVar5[2]);
      uVar1 = uVar3 + _m68k_ptes_per_page * 4;
      for (; (iVar4 == 0 && (uVar3 < uVar1)); uVar3 = uVar3 + 4) {
        if ((*(byte *)(uVar3 + 3) & 8) != 0) {
          iVar4 = 1;
        }
      }
      piVar5 = (int *)*piVar5;
      if (piVar5 == (int *)0x0) {
        return iVar4;
      }
      if (iVar4 != 0) {
        return iVar4;
      }
    }
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=2597 start=0x4098dbe */

int _pmap_is_modified(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 0;
  iVar2 = _pmap_phys_to_index(param_1);
  if (iVar2 != -1) {
    piVar5 = (int *)(_pv_head_table + iVar2 * 0xc);
    while (piVar5[1] != 0) {
      uVar3 = _pmap_pte_valid(piVar5[1],piVar5[2]);
      uVar1 = uVar3 + _m68k_ptes_per_page * 4;
      for (; (iVar4 == 0 && (uVar3 < uVar1)); uVar3 = uVar3 + 4) {
        if ((*(byte *)(uVar3 + 3) & 0x10) != 0) {
          iVar4 = 1;
        }
      }
      piVar5 = (int *)*piVar5;
      if (piVar5 == (int *)0x0) {
        return iVar4;
      }
      if (iVar4 != 0) {
        return iVar4;
      }
    }
  }
  return iVar4;
}
/* GHIDRADEC_FUNCTION index=2598 start=0x4098e4c */

int _pmap_phys_to_index(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined *in_A1;
  
  iVar3 = 0;
  iVar2 = 0;
  if (0 < _num_regions) {
    puVar1 = _mem_region;
    do {
      in_A1 = puVar1;
      if ((*(uint *)(in_A1 + 0x14) <= param_1) && (param_1 < *(uint *)(in_A1 + 0x18))) break;
      iVar3 = *(int *)(in_A1 + 0xc) + iVar3;
      iVar2 = iVar2 + 1;
      puVar1 = in_A1 + 0x1c;
    } while (iVar2 < _num_regions);
  }
  if (iVar2 == _num_regions) {
    iVar2 = -1;
  }
  else {
    iVar3 = iVar3 + ((param_1 >> (_page_shift & 0x3f)) - *(int *)(in_A1 + 4));
    iVar2 = -1;
    if (iVar3 < _managed_page_count) {
      iVar2 = iVar3;
    }
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=2599 start=0x4098ebc */

void _pmap_page_protect(undefined4 param_1,int param_2)

{
  if (param_2 == 5) {
loc_4098EE2:
    _pmap_copy_on_write(param_1);
  }
  else {
    if (param_2 < 6) {
      if (param_2 == 1) goto loc_4098EE2;
    }
    else if (param_2 == 7) {
      return;
    }
    _pmap_remove_all(param_1);
  }
  return;
}

