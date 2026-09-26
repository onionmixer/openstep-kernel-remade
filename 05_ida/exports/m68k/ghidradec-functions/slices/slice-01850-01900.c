/* GHIDRADEC_FUNCTION index=1850 start=0x4061cca */

int _fuibyte(undefined4 param_1)

{
  int iVar1;
  char cStack_5;
  
  iVar1 = _copyinmsg(param_1,&cStack_5,1);
  if (iVar1 == 0) {
    iVar1 = (int)cStack_5;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1851 start=0x4061cf2 */

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
/* GHIDRADEC_FUNCTION index=1852 start=0x4061d16 */

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
/* GHIDRADEC_FUNCTION index=1853 start=0x4061d3c */

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
/* GHIDRADEC_FUNCTION index=1854 start=0x4061d60 */

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
/* GHIDRADEC_FUNCTION index=1855 start=0x4061d86 */

void _swapon(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1856 start=0x4061d8e */

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
/* GHIDRADEC_FUNCTION index=1857 start=0x4061f1e */

int _chgprot(uint param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _vm_map_protect(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),~_page_mask & param_1
                          ,~_page_mask & param_1 + 1 + _page_mask,param_2,0);
  return -(int)-(iVar1 == 0);
}
/* GHIDRADEC_FUNCTION index=1858 start=0x4061f6a */

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
/* GHIDRADEC_FUNCTION index=1859 start=0x4061f96 */

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
/* GHIDRADEC_FUNCTION index=1860 start=0x4062024 */

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
/* GHIDRADEC_FUNCTION index=1861 start=0x4062080 */

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
/* GHIDRADEC_FUNCTION index=1862 start=0x4062168 */

void _device_pagein(void)

{
                    /* WARNING: Subroutine does not return */
  _panic(aDevicePageinCa);
}
/* GHIDRADEC_FUNCTION index=1863 start=0x406217c */

void _device_pageout(void)

{
                    /* WARNING: Subroutine does not return */
  _panic(aDevicePageoutC);
}
/* GHIDRADEC_FUNCTION index=1864 start=0x4062190 */

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
/* GHIDRADEC_FUNCTION index=1865 start=0x40621cc */

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
/* GHIDRADEC_FUNCTION index=1866 start=0x40622a4 */

void _gc_init(void)

{
  _gc_active = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1867 start=0x40622b2 */

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
/* GHIDRADEC_FUNCTION index=1868 start=0x406232c */

void _vm_user_init(void)

{
  _lock_init(&_vm_alloc_lock,1);
  return;
}
/* GHIDRADEC_FUNCTION index=1869 start=0x4062344 */

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
/* GHIDRADEC_FUNCTION index=1870 start=0x406241c */

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
/* GHIDRADEC_FUNCTION index=1871 start=0x406247e */

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
/* GHIDRADEC_FUNCTION index=1872 start=0x40624c8 */

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
/* GHIDRADEC_FUNCTION index=1873 start=0x406250c */

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
/* GHIDRADEC_FUNCTION index=1874 start=0x4062554 */

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
/* GHIDRADEC_FUNCTION index=1875 start=0x40625ee */

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
/* GHIDRADEC_FUNCTION index=1876 start=0x4062618 */

int _vm_read(undefined4 param_1,uint param_2,uint param_3,undefined4 *param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uStack_8;
  
  uVar1 = ~_page_mask & _page_mask + param_2;
  if ((param_2 == uVar1) && (uVar2 = _page_mask + param_3 & ~_page_mask, param_3 == uVar2)) {
    iVar3 = _vm_allocate(_ipc_soft_map,&uStack_8,uVar2,1);
    if (iVar3 == 0) {
      iVar3 = _vm_map_copy(_ipc_soft_map,param_1,uStack_8,uVar2,uVar1,0,0);
      if (iVar3 == 0) {
        *param_4 = uStack_8;
        *param_5 = uVar2;
      }
      else {
        _vm_deallocate(_ipc_soft_map,uStack_8,uVar2);
      }
    }
    else {
      _printf(aVmReadKernelEr,iVar3);
      iVar3 = 6;
    }
  }
  else {
    iVar3 = 4;
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=1877 start=0x40626ce */

undefined4 _vm_write(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar1 = ~_page_mask & _page_mask + param_2;
  if ((param_2 == uVar1) && (uVar2 = ~_page_mask & _page_mask + param_4, param_4 == uVar2)) {
    uVar3 = _vm_map_copy(param_1,_ipc_soft_map,uVar1,uVar2,param_3,0,1);
  }
  else {
    uVar3 = 4;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1878 start=0x406272a */

undefined4 _vm_copy(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = ~_page_mask;
  uVar1 = uVar3 & _page_mask + param_2;
  if (((param_2 == uVar1) && (uVar2 = uVar3 & _page_mask + param_4, param_4 == uVar2)) &&
     (uVar3 = uVar3 & _page_mask + param_3, param_3 == uVar3)) {
    uVar4 = _vm_map_copy(param_1,param_1,uVar2,uVar3,uVar1,0,0);
  }
  else {
    uVar4 = 4;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=1879 start=0x4062790 */

void _vnode_pager_vput(int param_1)

{
  *(sword *)(param_1 + 0xe) = *(sword *)(param_1 + 0xe) + -1;
  return;
}
/* GHIDRADEC_FUNCTION index=1880 start=0x40627a0 */

undefined4 _vnode_pager_vget(int param_1)

{
  *(sword *)(param_1 + 0xe) = *(sword *)(param_1 + 0xe) + 1;
  return *(undefined4 *)(param_1 + 0x14);
}
/* GHIDRADEC_FUNCTION index=1881 start=0x40627b4 */

uint _vnode_pager_allocpage(int param_1)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  _lock_write(param_1 + 0x34);
  if (*(int *)(param_1 + 0x18) == 0) {
    _lock_done(param_1 + 0x34);
    uVar2 = 0xffffffff;
  }
  else {
    iVar5 = 0;
    iVar6 = *(int *)(param_1 + 0x24);
    if (iVar6 < 0) {
      iVar6 = iVar6 + 7;
    }
    iVar6 = iVar6 >> 3;
    while( true ) {
      iVar3 = *(int *)(param_1 + 0x14) + 7;
      if (iVar3 < 0) {
        iVar3 = *(int *)(param_1 + 0x14) + 0xe;
      }
      if (iVar3 >> 3 <= iVar6) goto loc_4062844;
      if (*(char *)(iVar6 + *(int *)(param_1 + 0x10)) != -1) break;
      iVar6 = iVar6 + 1;
    }
    iVar5 = 0;
    do {
      iVar3 = iVar5;
      if (iVar5 < 0) {
        iVar3 = iVar5 + 7;
      }
    } while ((((int)*(char *)(iVar6 + *(int *)(param_1 + 0x10) + (iVar3 >> 3)) &
              1 << (iVar5 + (iVar3 >> 3) * -8 & 0x1fU)) != 0) && (iVar5 = iVar5 + 1, iVar5 < 8));
loc_4062844:
    uVar2 = iVar5 + iVar6 * 8;
    if (*(int *)(param_1 + 0x14) <= (int)uVar2) {
                    /* WARNING: Subroutine does not return */
      _panic(aVnodePagerAllo);
    }
    if (*(int *)(param_1 + 0x20) < (int)uVar2) {
      *(uint *)(param_1 + 0x20) = uVar2;
    }
    uVar4 = uVar2;
    if ((int)uVar2 < 0) {
      uVar4 = uVar2 + 7;
    }
    pbVar1 = (byte *)(*(int *)(param_1 + 0x10) + ((int)uVar4 >> 3));
    *pbVar1 = *pbVar1 | '\x01' << (uVar2 & 7);
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
    *(uint *)(param_1 + 0x24) = uVar2;
    _lock_done(param_1 + 0x34);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1882 start=0x406289e */

undefined4 _vnode_pager_findpage(undefined4 *param_1,undefined *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  if ((param_1 != (undefined4 *)0x0) ||
     (param_1 = dword_40B4DF4, puVar2 = dword_40B4DF4,
     (undefined4 **)dword_40B4DF4 != &dword_40B4DF4)) {
    do {
      iVar1 = _vnode_pager_allocpage(param_1);
      if (iVar1 != -1) {
        *param_2 = *(undefined *)((int)param_1 + 0x33);
        *(uint *)(param_2 + 1) = *(uint *)(param_2 + 1) & 0xff | iVar1 << 8;
        return 0;
      }
      param_1 = (undefined4 *)*param_1;
    } while (param_1 != puVar2);
  }
  return 5;
}
/* GHIDRADEC_FUNCTION index=1883 start=0x4062976 */

undefined4 * _pagerfile_pager_create(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  
  puVar2 = (undefined4 *)_zalloc_noblock(_vstruct_zone);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    uVar3 = (~_page_mask & _page_mask + param_2) >> (_page_shift & 0x3f);
    puVar2[4] = uVar3;
    if (uVar3 == 0) {
      puVar2[2] = 0;
    }
    else {
      uVar6 = uVar3 << 2;
      if (0x40 < uVar6) {
        uVar6 = (uVar3 - 1 >> 4) * 4 + 4;
      }
      uVar4 = _kalloc_noblock(uVar6);
      puVar2[2] = uVar4;
      if (puVar2[2] == 0) {
        _zfree(_vstruct_zone,puVar2);
        return (undefined4 *)0x0;
      }
      iVar1 = puVar2[4];
      if ((uint)(iVar1 << 2) < 0x41) {
        iVar5 = 0;
        if (0 < iVar1) {
          do {
            *(undefined *)(puVar2[2] + iVar5 * 4) = 0;
            iVar5 = iVar5 + 1;
          } while (iVar5 < (int)puVar2[4]);
        }
      }
      else {
        _bzero(puVar2[2],(iVar1 - 1U >> 4) * 4 + 4);
      }
    }
    *puVar2 = 0;
    *(undefined2 *)((int)puVar2 + 0xe) = 1;
    puVar2[5] = *(undefined4 *)(param_1 + 8);
    *(byte *)(puVar2 + 3) = *(byte *)(puVar2 + 3) | 0x80;
    puVar2[1] = param_1;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    _vnode_pager_vput(puVar2);
  }
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=1884 start=0x4062d88 */

undefined4 * _vnode_pager_create(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_zalloc(_vstruct_zone);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    _bzero(puVar1,0x18);
    *puVar1 = 0;
    *(undefined2 *)((int)puVar1 + 0xe) = 1;
    *(undefined4 **)*param_1 = puVar1;
    puVar1[5] = param_1;
    *(byte *)(puVar1 + 3) = *(byte *)(puVar1 + 3) & 0x7f;
    *(sword *)((int)param_1 + 6) = *(sword *)((int)param_1 + 6) + 1;
    _vnode_pager_vput(puVar1);
  }
  return puVar1;
}
/* GHIDRADEC_FUNCTION index=1885 start=0x4062de8 */

undefined4 _vnode_pager_setup(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_2 != 0) {
    *(word *)(param_1 + 1) = *(word *)(param_1 + 1) | 2;
  }
  if (*(int *)*param_1 == 0) {
    puVar2 = dword_40B4DF4;
    if ((undefined4 **)dword_40B4DF4 != &dword_40B4DF4) {
      do {
        if (param_1 == (undefined4 *)puVar2[2]) {
          return 0;
        }
        puVar2 = (undefined4 *)*puVar2;
      } while ((undefined4 **)puVar2 != &dword_40B4DF4);
    }
    _vnode_pager_create(param_1);
    if (param_3 != 0) {
      uVar1 = _vm_object_lookup(*(undefined4 *)*param_1,1);
      _vm_object_cache_object(uVar1);
    }
  }
  uVar1 = _zalloc(_vstruct_zone);
  _zfree(_vstruct_zone,uVar1);
  return *(undefined4 *)*param_1;
}
/* GHIDRADEC_FUNCTION index=1886 start=0x4062e70 */

undefined4 _vnode_pagein(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  bool bVar6;
  uint uStack_8;
  
  bVar6 = false;
  iVar1 = *(int *)(*(int *)(param_1 + 0x14) + 0x24);
  piVar2 = (int *)_vnode_pager_vget(iVar1);
  iVar5 = *(int *)(*(int *)(param_1 + 0x14) + 0x28) + *(int *)(param_1 + 0x18);
  if (*(char *)(iVar1 + 0xc) < '\0') {
    iVar3 = sub_4062AD4(iVar1,iVar5,1,&uStack_8);
    if (iVar3 == 5) {
      bVar6 = true;
    }
    else {
      iVar5 = (uStack_8 & 0xffffff) << (_page_shift & 0x3f);
      piVar2 = *(int **)((&unk_40B4E00)[uStack_8 >> 0x18] + 8);
    }
  }
  uVar4 = 1;
  if (!bVar6) {
    uVar4 = (**(code **)(piVar2[7] + 0x74))(piVar2,param_1,iVar5);
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(*piVar2 + 0x30);
    }
  }
  _vnode_pager_vput(iVar1);
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=1887 start=0x4062f2a */

int _vnode_pageout(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uStack_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x14) + 0x24);
  piVar3 = (int *)_vnode_pager_vget(iVar1);
  uVar5 = *(int *)(*(int *)(param_1 + 0x14) + 0x28) + *(int *)(param_1 + 0x18);
  iVar6 = _page_size;
  if ((-1 < *(char *)(iVar1 + 0xc)) &&
     (uVar2 = *(uint *)(*piVar3 + 0x14), uVar2 < _page_size + uVar5)) {
    if (uVar2 < uVar5) {
      iVar6 = 0;
    }
    else {
      iVar6 = uVar2 - uVar5;
    }
  }
  if (*(char *)(iVar1 + 0xc) < '\0') {
    iVar4 = sub_4062AD4(iVar1,uVar5,0,&uStack_8);
    if (iVar4 == 5) {
      _vnode_pager_vput(iVar1);
      return 2;
    }
    uVar5 = (uStack_8 & 0xffffff) << (_page_shift & 0x3f);
    piVar3 = *(int **)((&unk_40B4E00)[uStack_8 >> 0x18] + 8);
    if (*(uint *)(*piVar3 + 0x14) < iVar6 + uVar5) {
      *(uint *)(*piVar3 + 0x14) = iVar6 + uVar5;
    }
  }
  if (iVar6 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = (**(code **)(piVar3[7] + 0x78))(piVar3,*(undefined4 *)(param_1 + 0x22),iVar6,uVar5);
  }
  if (iVar6 == 0) {
    *(byte *)(param_1 + 0x1e) = *(byte *)(param_1 + 0x1e) | 4;
    _pmap_clear_modify(*(undefined4 *)(param_1 + 0x22));
  }
  else {
    _printf(aVnodePageoutFa);
  }
  _vnode_pager_vput(iVar1);
  return iVar6;
}
/* GHIDRADEC_FUNCTION index=1888 start=0x406303a */

bool _vnode_has_page(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined auStack_8 [4];
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVnodeHasPageFa);
  }
  if (*(char *)(param_1 + 0xc) < '\0') {
    iVar1 = sub_4062AD4(param_1,param_2,1,auStack_8);
    return iVar1 != 5;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aVnodeHasPageCa);
}
/* GHIDRADEC_FUNCTION index=1889 start=0x4063092 */

int _vnode_pager_file_init(undefined4 *param_1,int *param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  sword *psVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  undefined auStack_7e [4];
  int iStack_7a;
  int iStack_76;
  undefined auStack_3e [20];
  uint uStack_2a;
  
  *param_1 = 0;
  _mfs_uncache(param_2);
  if ((*(byte *)(*param_2 + 0x34) & 8) == 0) {
    psVar2 = *(sword **)(_active_u + 0x1a);
    (**(code **)(param_2[7] + 0x14))(param_2,auStack_3e,psVar2);
    uVar7 = uStack_2a;
    if (param_3 < uStack_2a) {
      _vattr_null(auStack_3e);
      uStack_2a = param_3;
      iVar3 = (**(code **)(param_2[7] + 0x18))(param_2,auStack_3e,psVar2);
      uVar7 = param_3;
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    *(uint *)(*param_2 + 0x14) = uVar7;
    puVar4 = (undefined4 *)_kalloc(0x3c);
    *(sword *)((int)param_2 + 6) = *(sword *)((int)param_2 + 6) + 1;
    puVar4[2] = param_2;
    *psVar2 = *psVar2 + 1;
    *(sword **)(*param_2 + 0x2c) = psVar2;
    puVar4[3] = 0;
    puVar4[9] = 0;
    puVar4[7] = (~_page_mask & _page_mask + param_3) >> (_page_shift & 0x3f);
    if (param_4 == 0) {
      iVar3 = (**(code **)(*(int *)(param_2[9] + 4) + 0xc))(param_2[9],auStack_7e);
      if (iVar3 != 0) {
        _kfree(puVar4,0x3c);
        return iVar3;
      }
      param_4 = iStack_7a * iStack_76;
    }
    param_4 = param_4 >> (_page_shift & 0x3f);
    puVar4[5] = param_4;
    puVar4[6] = param_4;
    iVar3 = puVar4[5] + 7;
    if (iVar3 < 0) {
      iVar3 = puVar4[5] + 0xe;
    }
    uVar5 = _kalloc(iVar3 >> 3);
    puVar4[4] = uVar5;
    iVar3 = 0;
    if (0 < (int)puVar4[5]) {
      do {
        iVar6 = iVar3;
        if (iVar3 < 0) {
          iVar6 = iVar3 + 7;
        }
        pbVar1 = (byte *)(puVar4[4] + (iVar6 >> 3));
        *pbVar1 = ~(byte)(1 << (iVar3 + (iVar6 >> 3) * -8 & 0x3fU)) & *pbVar1;
        iVar3 = iVar3 + 1;
      } while (iVar3 < (int)puVar4[5]);
    }
    puVar4[8] = 0xffffffff;
    puVar4[0xb] = 0;
    _lock_init(puVar4 + 0xd,1);
    *dword_40B4DF8 = puVar4;
    puVar4[1] = dword_40B4DF8;
    *puVar4 = &dword_40B4DF4;
    iVar6 = dword_40B4DFC;
    iVar3 = dword_40B4DFC + 1;
    dword_40B4DF8 = puVar4;
    dword_40B4DFC = dword_40B4DFC + 1;
    puVar4[0xc] = iVar3;
    (&dword_40B4E04)[iVar6] = puVar4;
    *param_1 = puVar4;
    iVar3 = 0;
  }
  else {
    iVar3 = 0x10;
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=1890 start=0x4063266 */

void _vnode_pager_shutdown(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((undefined4 **)dword_40B4DF4 != &dword_40B4DF4) {
    do {
      puVar2 = dword_40B4DF4;
      _vn_rele(dword_40B4DF4[2]);
      puVar1 = (undefined4 *)*puVar2;
      puVar2 = (undefined4 *)puVar2[1];
      puVar3 = puVar2;
      if ((undefined4 **)puVar1 != &dword_40B4DF4) {
        puVar1[1] = puVar2;
        puVar3 = dword_40B4DF8;
      }
      dword_40B4DF8 = puVar3;
      *puVar2 = puVar1;
      dword_40B4DFC = dword_40B4DFC + -1;
    } while ((undefined4 **)dword_40B4DF4 != &dword_40B4DF4);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1891 start=0x40632b6 */

int _mach_swapon(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piStack_18;
  int iStack_14;
  undefined auStack_10 [4];
  undefined4 uStack_c;
  int iStack_8;
  
  iVar1 = _suser();
  if (iVar1 == 0) {
    return 0xd;
  }
  *(undefined *)(dword_40B57D4 + 100) = 0;
  iStack_14 = 0;
  iVar1 = _pn_get(param_1,0,auStack_10);
  if (iVar1 != 0) {
    return 0x16;
  }
  iVar1 = iStack_8 + 1;
  iVar2 = _kalloc(iVar1);
  _strncpy(iVar2,uStack_c,iStack_8);
  *(undefined *)(iVar2 + -1 + iVar1) = 0;
  iVar3 = _lookuppn(auStack_10,1,0,&iStack_14);
  _pn_free(auStack_10);
  if (iVar3 == 0) {
    if (*(int *)(iStack_14 + 0x28) == 1) {
      piStack_18 = dword_40B4DF4;
      if ((int **)dword_40B4DF4 != &dword_40B4DF4) {
        do {
          if (iStack_14 == piStack_18[2]) break;
          piStack_18 = (int *)*piStack_18;
        } while ((int **)piStack_18 != &dword_40B4DF4);
        if ((int **)piStack_18 != &dword_40B4DF4) {
          iVar3 = 0x10;
          goto loc_40633C4;
        }
      }
      iVar3 = _vnode_pager_file_init(&piStack_18,iStack_14,param_3,param_4);
      if (iVar3 == 0) {
        piStack_18[0xb] = param_2 & 1;
        piStack_18[10] = iVar2;
        iVar2 = 0;
      }
    }
    else {
      iVar3 = 0x16;
    }
  }
loc_40633C4:
  if (iStack_14 != 0) {
    _vn_rele(iStack_14);
  }
  if (iVar2 != 0) {
    _kfree(iVar2,iVar1);
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=1892 start=0x40633ee */

undefined4 * _vswap_allocate(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar2 = (undefined4 *)0x0;
  iVar3 = 0;
  if (dword_40B4DFC < 2) {
    if (dword_40B4DFC == 1) {
      puVar2 = dword_40B4DF4;
    }
  }
  else {
    uVar1 = 0;
    do {
      if ((undefined4 **)dword_40B4DF4 != &dword_40B4DF4) {
        puVar4 = dword_40B4DF4;
        do {
          if ((((1 < (int)uVar1) || (puVar4[0xb] != 0)) &&
              (((uVar1 & 1) != 0 || (*(undefined **)(puVar4[2] + 0x1c) == _ufs_vnodeops)))) &&
             (iVar3 < (int)puVar4[6])) {
            puVar2 = puVar4;
            iVar3 = puVar4[6];
          }
          puVar4 = (undefined4 *)*puVar4;
        } while ((undefined4 **)puVar4 != &dword_40B4DF4);
      }
    } while ((puVar2 == (undefined4 *)0x0) && (uVar1 = uVar1 + 1, (int)uVar1 < 4));
  }
  return puVar2;
}
/* GHIDRADEC_FUNCTION index=1893 start=0x4063476 */

undefined4 _vnode_alloc(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = _vswap_allocate();
  if (iVar1 != 0) {
    uVar2 = _pagerfile_pager_create(iVar1,param_1);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1894 start=0x40634a0 */

void _vnode_pager_truncate(uint param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  sword sVar6;
  bool bVar7;
  undefined auStack_3e [20];
  int iStack_2a;
  
  iVar3 = (&unk_40B4E00)[param_1 >> 0x18];
  piVar1 = *(int **)(iVar3 + 8);
  param_1 = param_1 & 0xffffff;
  if ((*(int *)(iVar3 + 0x20) <= (int)param_1) && (_swapfs_enabled == 0)) {
    _lock_write(iVar3 + 0x34);
    for (; param_1 = param_1 - 1, -1 < (int)param_1; param_1 = param_1 & 0xffff0000) {
      do {
        uVar4 = param_1;
        if ((int)param_1 < 0) {
          uVar4 = param_1 + 7;
        }
        bVar7 = ((int)*(char *)(*(int *)(iVar3 + 0x10) + ((int)uVar4 >> 3)) &
                1 << (param_1 + ((int)uVar4 >> 3) * -8 & 0x1f)) != 0;
      } while ((!bVar7) &&
              (sVar6 = (sword)param_1 + -1, param_1 = CONCAT22((sword)(param_1 >> 0x10),sVar6),
              sVar6 != -1));
      if (bVar7) {
        *(uint *)(iVar3 + 0x20) = param_1;
        break;
      }
    }
    iVar5 = *(int *)(iVar3 + 0x20) + 1;
    if (((*(int *)(iVar3 + 0x1c) != 0) && (*(int *)(iVar3 + 0x1c) < iVar5)) &&
       ((uint)(iVar5 << (_page_shift & 0x3f)) <= *(uint *)(*piVar1 + 0x14))) {
      _vattr_null(auStack_3e);
      iStack_2a = iVar5 << (_page_shift & 0x3f);
      uVar2 = *(undefined4 *)(_active_u + 0x1a);
      *(undefined4 *)(_active_u + 0x1a) = *(undefined4 *)(*piVar1 + 0x2c);
      iVar5 = (**(code **)(piVar1[7] + 0x18))(piVar1,auStack_3e,*(undefined4 *)(*piVar1 + 0x2c));
      if (iVar5 != 0) {
        _printf(aVnodeDeallocpa,*(undefined4 *)(iVar3 + 0x28),iVar5);
      }
      *(undefined4 *)(_active_u + 0x1a) = uVar2;
    }
    _lock_done(iVar3 + 0x34);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1895 start=0x406362e */

void _vnode_dealloc(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  puVar2 = (undefined4 *)_vnode_pager_vget(param_1);
  dword_40B06E8 = 0;
  if (-1 < *(char *)(param_1 + 0xc)) {
    *(word *)(puVar2 + 1) = *(word *)(puVar2 + 1) & 0xfffd;
    *(undefined4 *)*puVar2 = 0;
    _vn_rele(puVar2);
    goto loc_4063740;
  }
  iVar4 = *(int *)(param_1 + 4);
  iVar7 = *(int *)(param_1 + 0x10);
  if ((uint)(iVar7 << 2) < 0x41) {
    iVar6 = 0;
    if (0 < iVar7) {
      do {
        sub_40628FA(*(undefined4 *)(*(int *)(param_1 + 8) + iVar6 * 4));
        sub_40635B6(*(undefined4 *)(*(int *)(param_1 + 8) + iVar6 * 4));
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)(param_1 + 0x10));
    }
    if (0 < *(int *)(param_1 + 0x10)) {
      iVar7 = *(int *)(param_1 + 0x10) << 2;
      goto loc_406371A;
    }
  }
  else {
    uVar5 = 0;
    if (iVar7 - 1U >> 4 != 0xffffffff) {
      do {
        if (*(int *)(*(int *)(param_1 + 8) + uVar5 * 4) != 0) {
          uVar3 = 0;
          do {
            sub_40628FA(*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + uVar5 * 4) + uVar3 * 4));
            sub_40635B6(*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + uVar5 * 4) + uVar3 * 4));
            uVar3 = uVar3 + 1;
          } while (uVar3 < 0x10);
          _kfree(*(undefined4 *)(*(int *)(param_1 + 8) + uVar5 * 4),0x40);
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < (*(int *)(param_1 + 0x10) - 1U >> 4) + 1);
    }
    iVar7 = (*(int *)(param_1 + 0x10) - 1U >> 4) * 4 + 4;
loc_406371A:
    _kfree(*(undefined4 *)(param_1 + 8),iVar7);
  }
  piVar1 = (int *)(iVar4 + 0xc);
  *piVar1 = *piVar1 + -1;
loc_4063740:
  iVar4 = 0;
  if (0 < dword_40B06E8) {
    puVar2 = (undefined4 *)unk_40B4E40;
    do {
      _vnode_pager_truncate(*puVar2);
      iVar4 = iVar4 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar4 < dword_40B06E8);
  }
  _zfree(_vstruct_zone,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1896 start=0x406377c */

void _vnode_uncache(int *param_1)

{
  word wVar1;
  word *pwVar2;
  bool bVar3;
  undefined4 uVar4;
  
  if (((int *)*param_1 != (int *)0x0) && (*(int *)*param_1 != 0)) {
    bVar3 = false;
    if ((undefined *)param_1[7] == _ufs_vnodeops) {
      wVar1 = *(word *)(*(int *)((int)param_1 + 0x2e) + 0x42);
      if ((wVar1 & 1) != 0) {
        bVar3 = true;
        *(word *)(*(int *)((int)param_1 + 0x2e) + 0x42) = wVar1 & 0xfffe;
      }
    }
    else if ((undefined *)param_1[7] == _nfs_vnodeops) {
      wVar1 = *(word *)(*(int *)((int)param_1 + 0x2e) + 0x5e);
      if ((wVar1 & 1) != 0) {
        bVar3 = true;
        *(word *)(*(int *)((int)param_1 + 0x2e) + 0x5e) = wVar1 & 0xfffe;
      }
    }
    _mfs_uncache(param_1);
    uVar4 = _vm_object_lookup(*(undefined4 *)*param_1,0);
    _vm_object_cache_object(uVar4);
    if (bVar3) {
      if ((undefined *)param_1[7] == _ufs_vnodeops) {
        pwVar2 = (word *)(*(int *)((int)param_1 + 0x2e) + 0x42);
        *pwVar2 = *pwVar2 | 1;
      }
      else if ((undefined *)param_1[7] == _nfs_vnodeops) {
        pwVar2 = (word *)(*(int *)((int)param_1 + 0x2e) + 0x5e);
        *pwVar2 = *pwVar2 | 1;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1897 start=0x4063834 */

void _vnode_pager_init(void)

{
  _vstruct_zone = _zinit(0x18,240000,_page_size,0,aVnodePagerStru);
  dword_40B4DF8 = &dword_40B4DF4;
  dword_40B4DF4 = &dword_40B4DF4;
  return;
}
/* GHIDRADEC_FUNCTION index=1898 start=0x406386e */

undefined4 _volopen(void)

{
  undefined4 uVar1;
  
  if (byte_40B4E80 == '\0') {
    byte_40B4E80 = '\x01';
    uVar1 = 0;
  }
  else {
    uVar1 = 0x10;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1899 start=0x406388c */

undefined4 _volclose(void)

{
  byte_40B4E80 = 0;
  return 0;
}

