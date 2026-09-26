/* GHIDRADEC_FUNCTION index=1850 start=0x4061cf2 */

undefined4 _suword(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _copyoutmsg(&stack0x00000008,param_1,4);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1851 start=0x4061d16 */

undefined4 _fuword(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_8;
  
  iVar1 = _copyinmsg(param_1,&uStack_8,4);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    uVar2 = uStack_8;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1852 start=0x4061d3c */

undefined4 _suiword(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _copyoutmsg(&stack0x00000008,param_1,4);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1853 start=0x4061d60 */

undefined4 _fuiword(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_8;
  
  iVar1 = _copyinmsg(param_1,&uStack_8,4);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    uVar2 = uStack_8;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1854 start=0x4061d86 */

void _swapon(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1855 start=0x4061d8e */

int _procdup(int param_1,int param_2)

{
  int iVar1;
  int iStack_c;
  int iStack_8;
  
  iVar1 = _task_create(*(int *)(param_2 + 0x66),*(int *)(param_2 + 0x66) != _kernel_task,&iStack_8);
  if (iVar1 != 0) {
    _printf(aForkProcdupTas,iVar1);
  }
  *(int *)(param_1 + 0x66) = iStack_8;
  _task_deallocate(iStack_8);
  *(int *)(iStack_8 + 0x34) = param_1;
  iVar1 = _thread_create(iStack_8,&iStack_c);
  if (iVar1 != 0) {
    _printf(aForkProcdupThr,iVar1);
  }
  _thread_deallocate(iStack_c);
  _compute_priority(iStack_c,0);
  _bcopy(*(undefined4 *)(*(int *)(param_2 + 0x66) + 0x30),*(undefined4 *)(iStack_8 + 0x30),0x28a);
  _bzero(*(int *)(iStack_8 + 0x30) + 0x23c,0x18);
  *(undefined4 *)(*(int *)(iStack_8 + 0x30) + 0x152) = 0;
  _expand_fdlist(*(int *)(iStack_8 + 0x30),*(undefined4 *)(*(int *)(iStack_8 + 0x30) + 0x14e));
  _bcopy(*(undefined4 *)(*(int *)(*(int *)(param_2 + 0x66) + 0x30) + 0x146),
         *(undefined4 *)(*(int *)(iStack_8 + 0x30) + 0x146),
         (*(int *)(*(int *)(iStack_8 + 0x30) + 0x14e) + 1) * 4);
  _bcopy(*(undefined4 *)(*(int *)(*(int *)(param_2 + 0x66) + 0x30) + 0x14a),
         *(undefined4 *)(*(int *)(iStack_8 + 0x30) + 0x14a),
         *(int *)(*(int *)(iStack_8 + 0x30) + 0x14e) + 1);
  **(int **)(*(int *)(iStack_c + 0xc) + 0x30) = param_1;
  _bzero(*(int *)(*(int *)(iStack_c + 0xc) + 0x30) + 0x166,0x48);
  _bzero(*(int *)(*(int *)(iStack_c + 0xc) + 0x30) + 0x1ae,0x48);
  *(undefined4 *)(*(int *)(*(int *)(iStack_c + 0xc) + 0x30) + 0x26) = 0;
  return iStack_c;
}
/* GHIDRADEC_FUNCTION index=1856 start=0x4061f1e */

int _chgprot(uint param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _vm_map_protect(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),~_page_mask & param_1
                          ,~_page_mask & param_1 + 1 + _page_mask,param_2,0);
  return -(int)-(iVar1 == 0);
}
/* GHIDRADEC_FUNCTION index=1857 start=0x4061f6a */

undefined4 _unix_pid(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x34) == 0)) {
    *param_2 = -1;
    uVar1 = 5;
  }
  else {
    *param_2 = (int)*(sword *)(*(int *)(param_1 + 0x34) + 0x30);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1858 start=0x4061f96 */

undefined4 _task_by_unix_pid(int param_1,undefined4 param_2,undefined4 *param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _pfind(param_2);
  if ((((iVar2 != 0) && (*(int *)(param_1 + 0x34) != 0)) &&
      ((*(sword *)(*(int *)(param_1 + 0x34) + 0x2c) == *(sword *)(iVar2 + 0x2c) ||
       (iVar3 = _suser(), iVar3 != 0)))) && (*(char *)(iVar2 + 0x13) != '\x05')) {
    if (*(int *)(iVar2 + 0x66) != 0) {
      _task_reference(*(int *)(iVar2 + 0x66));
    }
    *param_3 = *(undefined4 *)(iVar2 + 0x66);
    iVar2 = _suser();
    if ((iVar2 != 0) && (iVar2 = *(int *)(*(int *)(_active_threads + 0xc) + 0x34), iVar2 != 0)) {
      pbVar1 = (byte *)(iVar2 + 0x16);
      *pbVar1 = *pbVar1 | 0x80;
    }
    return 0;
  }
  *param_3 = 0;
  return 5;
}
/* GHIDRADEC_FUNCTION index=1859 start=0x4062024 */

int _task_by_pid(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iStack_c;
  undefined4 uStack_8;
  
  uVar1 = *(undefined4 *)(_active_threads + 0xc);
  iStack_c = 0;
  iVar2 = _task_by_unix_pid(uVar1,param_1,&uStack_8);
  if (iVar2 == 0) {
    iStack_c = _convert_task_to_port(uStack_8);
    if (iStack_c != 0) {
      _object_copyout(uVar1,iStack_c,6,&iStack_c);
    }
  }
  return iStack_c;
}
/* GHIDRADEC_FUNCTION index=1860 start=0x4062080 */

undefined4
_vm_object_special(sword param_1,code *param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  
  uVar1 = ~_page_mask & _page_mask + param_5;
  uVar6 = uVar1 >> (_page_shift & 0x3f);
  uVar2 = _vm_object_allocate(uVar1);
  iVar5 = uVar6 * 0x2e + 0x10;
  puVar3 = (undefined4 *)_kalloc(iVar5);
  _bzero(puVar3,iVar5);
  *puVar3 = 1;
  puVar3[1] = uVar2;
  puVar3[2] = puVar3;
  puVar3[3] = iVar5;
  puVar7 = puVar3 + 4;
  iVar5 = 0;
  if (0 < (int)uVar6) {
    do {
      *(undefined2 *)(puVar7 + 7) = 1;
      iVar4 = (*param_2)((int)param_1,param_4 + (iVar5 << (_page_shift & 0x3f)),param_3);
      uVar1 = _page_shift;
      *(int *)((int)puVar7 + 0x22) = iVar4 << (_page_shift & 0x3f);
      _vm_page_insert(puVar7,uVar2,iVar5 << (uVar1 & 0x3f));
      iVar5 = iVar5 + 1;
      puVar7 = (undefined4 *)((int)puVar7 + 0x2e);
    } while (iVar5 < (int)uVar6);
  }
  _vm_object_setpager(uVar2,puVar3,0,0);
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1861 start=0x4062168 */

void _device_pagein(void)

{
                    /* WARNING: Subroutine does not return */
  _panic(aDevicePageinCa);
}
/* GHIDRADEC_FUNCTION index=1862 start=0x406217c */

void _device_pageout(void)

{
                    /* WARNING: Subroutine does not return */
  _panic(aDevicePageoutC);
}
/* GHIDRADEC_FUNCTION index=1863 start=0x4062190 */

void _device_dealloc(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 4);
  puVar1 = (undefined4 *)*puVar2;
  while (puVar2 != puVar1) {
    _vm_page_remove(*puVar2);
    puVar1 = (undefined4 *)*puVar2;
  }
  _kfree(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc));
  return;
}
/* GHIDRADEC_FUNCTION index=1864 start=0x40621cc */

void _fake_u(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(*(int *)(param_2 + 0xc) + 0x30);
  iVar2 = *(int *)(param_2 + 0x80);
  _bcopy(iVar1 + 8,param_1 + 8,0x11);
  _bcopy(iVar2 + 4,param_1 + 0x1a,0x20);
  *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(iVar1 + 0x1a);
  _bcopy(iVar1 + 0x2a,param_1 + 0x98,0x84);
  *(undefined4 *)(param_1 + 0x1ac) = *(undefined4 *)(iVar2 + 0x6c);
  *(undefined4 *)(param_1 + 0x6c4) = *(undefined4 *)(iVar1 + 0x15e);
  *(undefined2 *)(param_1 + 0x6c8) = *(undefined2 *)(iVar1 + 0x162);
  _bcopy(iVar1 + 0x166,(undefined4 *)(param_1 + 0x6cc),0x48);
  _thread_read_times(param_2,&uStack_c,&uStack_14);
  *(undefined4 *)(param_1 + 0x6d4) = uStack_14;
  *(undefined4 *)(param_1 + 0x6d8) = uStack_10;
  *(undefined4 *)(param_1 + 0x6cc) = uStack_c;
  *(undefined4 *)(param_1 + 0x6d0) = uStack_8;
  _bcopy(iVar1 + 0x1ae,param_1 + 0x714,0x48);
  return;
}
/* GHIDRADEC_FUNCTION index=1865 start=0x40622a4 */

void _gc_init(void)

{
  _gc_active = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1866 start=0x40622b2 */

void _gc_control(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(dword_40B57D4 + 0x24);
  iVar2 = _suser();
  if ((iVar2 != 0) && (_gc_active == 0)) {
    _gc_active = 1;
    if ((*(byte *)(iVar1 + 3) & 1) != 0) {
      _mfs_cache_clear();
      _vm_object_cache_clear();
      _inode_cache_clear();
      _rnode_cache_clear();
      _proc_cache_clear();
    }
    if ((*(byte *)(iVar1 + 3) & 2) != 0) {
      _zone_gc();
    }
    if ((*(byte *)(iVar1 + 3) & 4) != 0) {
      _zone_reclaim();
    }
    _gc_active = 0;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1867 start=0x406232c */

void _vm_user_init(void)

{
  _lock_init(&_vm_alloc_lock,1);
  return;
}
/* GHIDRADEC_FUNCTION index=1868 start=0x4062344 */

int _vm_allocate_with_pager
              (int param_1,uint *param_2,int param_3,undefined4 param_4,int param_5,
              undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar2 = 4;
  }
  else {
    *param_2 = ~_page_mask & *param_2;
    uVar1 = ~_page_mask & _page_mask + param_3;
    _lock_write(&_vm_alloc_lock);
    iVar3 = _vm_object_lookup(param_5);
    dword_40C240C = dword_40C240C + 1;
    if (iVar3 == 0) {
      iVar3 = _vm_object_allocate(uVar1);
      if (param_5 != 0) {
        _vm_object_setpager(iVar3,param_5,0,1);
        _vm_object_enter(iVar3,param_5);
      }
    }
    else {
      dword_40C2410 = dword_40C2410 + 1;
    }
    _lock_done(&_vm_alloc_lock);
    *(byte *)(iVar3 + 0x42) = *(byte *)(iVar3 + 0x42) & 0xf7;
    iVar2 = _vm_map_find(param_1,iVar3,param_6,param_2,uVar1,param_4);
    if (iVar2 != 0) {
      _vm_object_deallocate(iVar3);
    }
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=1869 start=0x406241c */

undefined4 _vm_allocate(int param_1,uint *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else if (param_3 == 0) {
    *param_2 = 0;
    uVar1 = 0;
  }
  else {
    if (param_4 == 0) {
      *param_2 = ~_page_mask & *param_2;
    }
    else {
      *param_2 = *(uint *)(param_1 + 0x10);
    }
    uVar1 = _vm_map_find(param_1,0,0,param_2,~_page_mask & _page_mask + param_3,param_4);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1870 start=0x406247e */

undefined4 _vm_deallocate(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else if (param_3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = _vm_map_remove(param_1,~_page_mask & param_2,
                           ~_page_mask & _page_mask + param_3 + param_2);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1871 start=0x40624c8 */

undefined4 _vm_inherit(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    uVar1 = _vm_map_inherit(param_1,~_page_mask & param_2,
                            ~_page_mask & _page_mask + param_3 + param_2,param_4);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1872 start=0x406250c */

undefined4 _vm_protect(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    uVar1 = _vm_map_protect(param_1,~_page_mask & param_2,
                            ~_page_mask & _page_mask + param_3 + param_2,param_5,param_4);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1873 start=0x4062554 */

undefined4 _vm_statistics(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    _vm_stat = _page_size;
    unk_40C23E4 = _vm_page_free_count;
    unk_40C23E8 = _vm_page_active_count;
    unk_40C23EC = _vm_page_inactive_count;
    unk_40C23F0 = _vm_page_wire_count;
    *param_2 = _page_size;
    param_2[1] = unk_40C23E4;
    param_2[2] = unk_40C23E8;
    param_2[3] = unk_40C23EC;
    param_2[4] = unk_40C23F0;
    param_2[5] = dword_40C23F4;
    param_2[6] = dword_40C23F8;
    param_2[7] = dword_40C23FC;
    param_2[8] = dword_40C2400;
    param_2[9] = dword_40C2404;
    param_2[10] = dword_40C2408;
    param_2[0xb] = dword_40C240C;
    param_2[0xc] = dword_40C2410;
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1874 start=0x40625ee */

undefined4
_vm_machine_attribute
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    uVar1 = _vm_map_machine_attribute(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}

