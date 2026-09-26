/* GHIDRADEC_FUNCTION index=1750 start=0x405d996 */

undefined4 _copyoutmap(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x20) == _kernel_pmap) {
    _bcopy(param_2,param_3,param_4);
    uVar1 = 0;
  }
  else if (param_1 == *(int *)(*(int *)(_active_threads + 0xc) + 8)) {
    uVar1 = _copyoutmsg(param_2,param_3,param_4);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1751 start=0x405d9f6 */

void _kmem_alloc_zone(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  sub_405D448(param_1,param_2,param_3,1,_kernel_object,param_4);
  return;
}
/* GHIDRADEC_FUNCTION index=1752 start=0x405da1e */

uint _kmem_mb_alloc(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uStack_8;
  
  if (((param_1 != _mb_map) && (param_1 != _swapfs_bit_map)) && (param_1 != _swapfs_rem_map)) {
                    /* WARNING: Subroutine does not return */
    _panic(aYouFool);
  }
  uVar2 = ~_page_mask & _page_mask + param_2;
  _lock_write(param_1);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  piVar1 = *(int **)(param_1 + 0xc);
  if ((int *)(param_1 + 8) == piVar1) {
    _lock_done(param_1);
    uStack_8 = *(uint *)(param_1 + 0x10);
    iVar4 = _vm_map_find(param_1,0,0,&uStack_8,uVar2,1);
    if (iVar4 == 0) {
      _vm_map_pageable(param_1,uStack_8,uStack_8 + uVar2,0);
      return uStack_8;
    }
    return 0;
  }
  if (((((piVar1 == *(int **)(param_1 + 8)) && (-1 < *(char *)(piVar1 + 6))) &&
       ((piVar1[2] == *(int *)(param_1 + 0x10) &&
        ((*(int *)((int)piVar1 + 0x1e) == 7 && (*(int *)((int)piVar1 + 0x1a) == 3)))))) &&
      (*(int *)((int)piVar1 + 0x22) == 1)) && (*(sword *)((int)piVar1 + 0x26) != 0)) {
    uVar9 = piVar1[3];
    if (uVar9 <= *(int *)(param_1 + 0x14) - uVar2) {
      iVar4 = piVar1[4];
      uVar7 = piVar1[5] + (uVar9 - piVar1[2]);
      piVar1[3] = uVar2 + piVar1[3];
      uVar8 = uVar2 >> (_page_shift & 0x3f);
      uVar3 = uVar7;
      while( true ) {
        uStack_8 = uVar9;
        if (uVar8 == 0) {
          if (uVar9 < (uint)piVar1[3]) {
            do {
              iVar5 = _vm_page_lookup(iVar4,uVar7);
              _vm_page_wire(iVar5);
              _pmap_enter(*(undefined4 *)(param_1 + 0x20),uVar9,*(undefined4 *)(iVar5 + 0x22),
                          *(undefined4 *)((int)piVar1 + 0x1a),1);
              uVar9 = _page_size + uVar9;
              uVar7 = _page_size + uVar7;
            } while (uVar9 < (uint)piVar1[3]);
          }
          _lock_done(param_1);
          return uStack_8;
        }
        iVar5 = _vm_page_alloc_sequential(iVar4,uVar3,0);
        if (iVar5 == 0) break;
        _vm_page_zero_fill(iVar5);
        *(byte *)(iVar5 + 0x20) = *(byte *)(iVar5 + 0x20) & 0x7f;
        uVar8 = uVar8 - 1;
        uVar3 = _page_size + uVar3;
        uVar9 = uStack_8;
      }
      while (uVar7 < uVar3) {
        uVar3 = uVar3 - _page_size;
        uVar6 = _vm_page_lookup(iVar4,uVar3);
        _vm_page_free(uVar6);
      }
      piVar1[3] = piVar1[3] - uVar2;
    }
    _lock_done(param_1);
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aMbMapAbusedEve);
}
/* GHIDRADEC_FUNCTION index=1753 start=0x405dc04 */

undefined4 _kmem_alloc_wait(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uStack_8;
  
  uVar1 = ~_page_mask & _page_mask + param_2;
  do {
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
    _lock_set_recursive(param_1);
    uStack_8 = *(undefined4 *)(param_1 + 0x10);
    iVar2 = _vm_map_find(param_1,0,0,&uStack_8,uVar1,1);
    _lock_clear_recursive(param_1);
    if (iVar2 == 0) {
      _lock_done(param_1);
    }
    else {
      if ((uint)(*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10)) < uVar1) {
        _lock_done(param_1);
        return 0;
      }
      _assert_wait(param_1,1);
      _lock_done(param_1);
      _thread_block();
    }
  } while (iVar2 != 0);
  return uStack_8;
}
/* GHIDRADEC_FUNCTION index=1754 start=0x405dcba */

void _kmem_free_wakeup(int param_1,uint param_2,int param_3)

{
  _lock_write(param_1);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  _vm_map_delete(param_1,~_page_mask & param_2,~_page_mask & _page_mask + param_2 + param_3);
  _thread_wakeup_prim(param_1,0,0);
  _lock_done(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1755 start=0x405dd16 */

void _vm_map_init(void)

{
  _vm_map_zone = _zinit(0x44,0x19000,0,0,&aMaps);
  _vm_map_entry_zone = _zinit(0x2a,0x100000,0,0,aNonKernelMapEn);
  _vm_map_kentry_zone = _zinit(0x2a,_kentry_data_size,0,0,aKernelMapEntri);
  _zchange(_vm_map_kentry_zone,0,0,0,0);
  _zcram(_vm_map_zone,_map_data,_map_data_size);
  _zcram(_vm_map_kentry_zone,_kentry_data,_kentry_data_size);
  return;
}
/* GHIDRADEC_FUNCTION index=1756 start=0x405ddc4 */

int _vm_map_create(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = _zalloc(_vm_map_zone);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVmMapCreate);
  }
  iVar1 = iVar2 + 8;
  *(int *)(iVar2 + 0xc) = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(iVar2 + 0x18) = 0;
  *(undefined4 *)(iVar2 + 0x1c) = param_4;
  *(undefined4 *)(iVar2 + 0x24) = 0;
  *(undefined4 *)(iVar2 + 0x2c) = 1;
  *(undefined4 *)(iVar2 + 0x20) = param_1;
  *(undefined4 *)(iVar2 + 0x28) = 1;
  *(undefined4 *)(iVar2 + 0x10) = param_2;
  *(undefined4 *)(iVar2 + 0x14) = param_3;
  *(undefined4 *)(iVar2 + 0x3c) = 0;
  *(undefined4 *)(iVar2 + 0x38) = 0;
  *(int *)(iVar2 + 0x34) = iVar1;
  *(int *)(iVar2 + 0x30) = iVar1;
  *(undefined4 *)(iVar2 + 0x40) = 0;
  _lock_init(iVar2,1);
  *(undefined4 *)(iVar2 + 0x40) = 0;
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=1757 start=0x405de4e */

int __vm_map_entry_create(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = _vm_map_kentry_zone;
  if (*(int *)(param_1 + 0x14) != 0) {
    uVar1 = _vm_map_entry_zone;
  }
  iVar2 = _zalloc(uVar1);
  if (iVar2 != 0) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aVmMapEntryCrea);
}
/* GHIDRADEC_FUNCTION index=1758 start=0x405de90 */

void __vm_map_entry_dispose(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = _vm_map_kentry_zone;
  if (*(int *)(param_1 + 0x14) != 0) {
    uVar1 = _vm_map_entry_zone;
  }
  _zfree(uVar1,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=1759 start=0x405debc */

void _vm_map_reference(int param_1)

{
  if (param_1 != 0) {
    *(int *)(param_1 + 0x2c) = *(int *)(param_1 + 0x2c) + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1760 start=0x405ded0 */

void _vm_map_deallocate(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x2c);
    *(int *)(param_1 + 0x2c) = iVar1 + -1;
    if (iVar1 == 1 || iVar1 + -1 < 0) {
      _lock_write(param_1);
      *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
      _vm_map_delete(param_1,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
      _pmap_destroy(*(undefined4 *)(param_1 + 0x20));
      _zfree(_vm_map_zone,param_1);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1761 start=0x405df2c */

undefined4 _vm_map_insert(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  int *piVar2;
  int iStack_8;
  
  if (((param_4 < *(uint *)(param_1 + 0x10)) || (*(uint *)(param_1 + 0x14) < param_5)) ||
     (param_5 <= param_4)) {
    return 1;
  }
  iVar1 = _vm_map_lookup_entry(param_1,param_4,&iStack_8);
  if ((iVar1 == 0) &&
     ((param_1 + 8 == *(int *)(iStack_8 + 4) || (param_5 <= *(uint *)(*(int *)(iStack_8 + 4) + 8))))
     ) {
    if ((param_2 == 0) &&
       (((param_1 + 8 != iStack_8 && (param_4 == *(uint *)(iStack_8 + 0xc))) &&
        (((*(byte *)(iStack_8 + 0x18) & 0xa0) == 0 &&
         ((((*(int *)(iStack_8 + 0x22) == 1 && (*(int *)(iStack_8 + 0x1a) == 3)) &&
           (*(int *)(iStack_8 + 0x1e) == 7)) &&
          ((*(sword *)(iStack_8 + 0x26) == 0 &&
           (iVar1 = _vm_object_coalesce(*(undefined4 *)(iStack_8 + 0x10),0,
                                        *(undefined4 *)(iStack_8 + 0x14),0,
                                        param_4 - *(int *)(iStack_8 + 8),param_5 - param_4),
           iVar1 != 0)))))))))) {
      *(int *)(param_1 + 0x24) = (param_5 - *(int *)(iStack_8 + 0xc)) + *(int *)(param_1 + 0x24);
      *(uint *)(iStack_8 + 0xc) = param_5;
    }
    else {
      piVar2 = (int *)__vm_map_entry_create(param_1 + 8);
      piVar2[2] = param_4;
      piVar2[3] = param_5;
      *(byte *)(piVar2 + 6) = *(byte *)(piVar2 + 6) & 0x5f;
      piVar2[4] = param_2;
      piVar2[5] = param_3;
      *(byte *)(piVar2 + 6) = *(byte *)(piVar2 + 6) & 0xed;
      if (*(int *)(param_1 + 0x28) != 0) {
        *(undefined4 *)((int)piVar2 + 0x22) = 1;
        *(undefined4 *)((int)piVar2 + 0x1a) = 3;
        *(undefined4 *)((int)piVar2 + 0x1e) = 7;
        *(undefined2 *)((int)piVar2 + 0x26) = 0;
      }
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
      *piVar2 = iStack_8;
      piVar2[1] = *(int *)(iStack_8 + 4);
      iVar1 = *piVar2;
      *(int **)piVar2[1] = piVar2;
      *(int **)(iVar1 + 4) = piVar2;
      *(int *)(param_1 + 0x24) = (piVar2[3] - piVar2[2]) + *(int *)(param_1 + 0x24);
      if ((iStack_8 == *(int *)(param_1 + 0x34)) && ((uint)piVar2[2] <= *(uint *)(iStack_8 + 0xc)))
      {
        *(int **)(param_1 + 0x34) = piVar2;
      }
    }
    return 0;
  }
  return 3;
}
/* GHIDRADEC_FUNCTION index=1762 start=0x405e088 */

undefined4 _vm_map_lookup_entry(int param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x30);
  puVar1 = (undefined4 *)(param_1 + 8);
  if (puVar1 == puVar2) {
    puVar2 = *(undefined4 **)(param_1 + 0xc);
  }
  if (param_2 < (uint)puVar2[2]) {
    puVar1 = (undefined4 *)puVar2[1];
    puVar2 = *(undefined4 **)(param_1 + 0xc);
  }
  else {
    if (puVar1 == puVar2) goto loc_405E0EC;
    if (param_2 < (uint)puVar2[3]) {
      *param_3 = puVar2;
      return 1;
    }
  }
  for (; puVar1 != puVar2; puVar2 = (undefined4 *)puVar2[1]) {
    if (param_2 < (uint)puVar2[3]) {
      if ((uint)puVar2[2] <= param_2) {
        *param_3 = puVar2;
        *(undefined4 **)(param_1 + 0x30) = puVar2;
        return 1;
      }
      break;
    }
  }
loc_405E0EC:
  *param_3 = *puVar2;
  *(undefined4 *)(param_1 + 0x30) = *param_3;
  return 0;
}
/* GHIDRADEC_FUNCTION index=1763 start=0x405e100 */

undefined4
_vm_map_find(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4,int param_5,int param_6
            )

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iStack_8;
  
  uVar4 = *param_4;
  _lock_write(param_1);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  if (param_6 == 0) {
loc_405E1B4:
    uVar3 = _vm_map_insert(param_1,param_2,param_3,uVar4,uVar4 + param_5);
    _lock_done(param_1);
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x10);
    if (uVar4 < uVar1) {
      uVar4 = uVar1;
    }
    if (uVar4 <= *(uint *)(param_1 + 0x14)) {
      if (uVar1 == uVar4) {
        iStack_8 = *(int *)(param_1 + 0x34);
        if (param_1 + 8 != iStack_8) {
          uVar4 = *(uint *)(iStack_8 + 0xc);
        }
      }
      else {
        iVar2 = _vm_map_lookup_entry(param_1,uVar4,&iStack_8);
        if (iVar2 != 0) {
          uVar4 = *(uint *)(iStack_8 + 0xc);
        }
      }
      while ((uVar1 = uVar4 + param_5, uVar1 <= *(uint *)(param_1 + 0x14) && (uVar4 <= uVar1))) {
        iVar2 = *(int *)(iStack_8 + 4);
        if ((param_1 + 8 == iVar2) || (uVar1 <= *(uint *)(iVar2 + 8))) {
          *param_4 = uVar4;
          *(int *)(param_1 + 0x30) = iStack_8;
          goto loc_405E1B4;
        }
        iStack_8 = iVar2;
        uVar4 = *(uint *)(iVar2 + 0xc);
      }
    }
    _lock_done(param_1);
    uVar3 = 3;
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1764 start=0x405e1e0 */

void __vm_map_clip_start(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)__vm_map_entry_create(param_1);
  *piVar2 = *param_2;
  piVar2[1] = param_2[1];
  piVar2[2] = param_2[2];
  piVar2[3] = param_2[3];
  piVar2[4] = param_2[4];
  piVar2[5] = param_2[5];
  piVar2[6] = param_2[6];
  piVar2[7] = param_2[7];
  piVar2[8] = param_2[8];
  piVar2[9] = param_2[9];
  *(undefined2 *)(piVar2 + 10) = *(undefined2 *)(param_2 + 10);
  piVar2[3] = param_3;
  param_2[5] = (param_3 - param_2[2]) + param_2[5];
  param_2[2] = param_3;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  *piVar2 = *param_2;
  piVar2[1] = *(int *)(*param_2 + 4);
  iVar1 = *piVar2;
  *(int **)piVar2[1] = piVar2;
  *(int **)(iVar1 + 4) = piVar2;
  if ((*(byte *)(param_2 + 6) & 0xa0) == 0) {
    _vm_object_reference(piVar2[4]);
  }
  else {
    _vm_map_reference(piVar2[4]);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1765 start=0x405e270 */

void __vm_map_clip_end(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)__vm_map_entry_create(param_1);
  *piVar2 = *param_2;
  piVar2[1] = param_2[1];
  piVar2[2] = param_2[2];
  piVar2[3] = param_2[3];
  piVar2[4] = param_2[4];
  piVar2[5] = param_2[5];
  piVar2[6] = param_2[6];
  piVar2[7] = param_2[7];
  piVar2[8] = param_2[8];
  piVar2[9] = param_2[9];
  *(undefined2 *)(piVar2 + 10) = *(undefined2 *)(param_2 + 10);
  param_2[3] = param_3;
  piVar2[2] = param_3;
  piVar2[5] = (param_3 - param_2[2]) + piVar2[5];
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  *piVar2 = (int)param_2;
  piVar2[1] = param_2[1];
  iVar1 = *piVar2;
  *(int **)piVar2[1] = piVar2;
  *(int **)(iVar1 + 4) = piVar2;
  if ((*(byte *)(param_2 + 6) & 0xa0) == 0) {
    _vm_object_reference(piVar2[4]);
  }
  else {
    _vm_map_reference(piVar2[4]);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1766 start=0x405e2fc */

undefined4 _vm_map_submap(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_8;
  
  uVar2 = 4;
  _lock_write(param_1);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  if (param_2 < *(uint *)(param_1 + 0x10)) {
    param_2 = *(uint *)(param_1 + 0x10);
  }
  if (*(uint *)(param_1 + 0x14) < param_3) {
    param_3 = *(uint *)(param_1 + 0x14);
  }
  if (param_3 < param_2) {
    param_2 = param_3;
  }
  iVar1 = _vm_map_lookup_entry(param_1,param_2,&iStack_8);
  if (iVar1 == 0) {
    iStack_8 = *(int *)(iStack_8 + 4);
  }
  else if (*(uint *)(iStack_8 + 8) < param_2) {
    __vm_map_clip_start(param_1 + 8,iStack_8,param_2);
  }
  if (param_3 < *(uint *)(iStack_8 + 0xc)) {
    __vm_map_clip_end(param_1 + 8,iStack_8,param_3);
  }
  if ((((param_2 == *(uint *)(iStack_8 + 8)) && (param_3 == *(uint *)(iStack_8 + 0xc))) &&
      (-1 < (char)*(byte *)(iStack_8 + 0x18))) &&
     ((iVar1 = *(int *)(iStack_8 + 0x10), iVar1 == _vm_submap_object &&
      ((*(byte *)(iStack_8 + 0x18) & 0x10) == 0)))) {
    *(undefined4 *)(iStack_8 + 0x10) = 0;
    _vm_object_deallocate(iVar1);
    *(byte *)(iStack_8 + 0x18) = *(byte *)(iStack_8 + 0x18) | 0x20;
    *(undefined4 *)(iStack_8 + 0x10) = param_4;
    _vm_map_reference(param_4);
    uVar2 = 0;
  }
  _lock_done(param_1);
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1767 start=0x405e3fe */

undefined4 _vm_map_protect(int param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iStack_c;
  int iStack_8;
  
  _lock_write(param_1);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  if (param_2 < *(uint *)(param_1 + 0x10)) {
    param_2 = *(uint *)(param_1 + 0x10);
  }
  if (*(uint *)(param_1 + 0x14) < param_3) {
    param_3 = *(uint *)(param_1 + 0x14);
  }
  if (param_3 < param_2) {
    param_2 = param_3;
  }
  iVar3 = _vm_map_lookup_entry(param_1,param_2,&iStack_8);
  if (iVar3 == 0) {
    iStack_8 = *(int *)(iStack_8 + 4);
  }
  else if (*(uint *)(iStack_8 + 8) < param_2) {
    __vm_map_clip_start(param_1 + 8,iStack_8,param_2);
  }
  iVar3 = iStack_8;
  while( true ) {
    iVar8 = iStack_8;
    if ((param_1 + 8 == iVar3) || (param_3 <= *(uint *)(iVar3 + 8))) {
      for (; (param_1 + 8 != iVar8 && (*(uint *)(iVar8 + 8) < param_3)); iVar8 = *(int *)(iVar8 + 4)
          ) {
        if (param_3 < *(uint *)(iVar8 + 0xc)) {
          __vm_map_clip_end(param_1 + 8,iVar8,param_3);
        }
        uVar7 = *(uint *)(iVar8 + 0x1a);
        if (param_5 == 0) {
          *(uint *)(iVar8 + 0x1a) = param_4;
        }
        else {
          *(uint *)(iVar8 + 0x1e) = param_4;
          *(uint *)(iVar8 + 0x1a) = uVar7 & param_4;
        }
        if (uVar7 != *(uint *)(iVar8 + 0x1a)) {
          if (*(char *)(iVar8 + 0x18) < '\0') {
            _lock_write(*(undefined4 *)(iVar8 + 0x10));
            piVar1 = (int *)(*(int *)(iVar8 + 0x10) + 0x40);
            *piVar1 = *piVar1 + 1;
            _vm_map_lookup_entry
                      (*(undefined4 *)(iVar8 + 0x10),*(undefined4 *)(iVar8 + 0x14),&iStack_c);
            uVar7 = (*(int *)(iVar8 + 0xc) - *(int *)(iVar8 + 8)) + *(int *)(iVar8 + 0x14);
            for (; (*(int *)(iVar8 + 0x10) + 8 != iStack_c && (*(uint *)(iStack_c + 8) < uVar7));
                iStack_c = *(int *)(iStack_c + 4)) {
              uVar6 = 7;
              if ((*(byte *)(iStack_c + 0x18) & 0x10) != 0) {
                uVar6 = 0xfffffffd;
              }
              uVar4 = *(uint *)(iStack_c + 0xc);
              if (*(uint *)(iStack_c + 0xc) < uVar7) {
                uVar4 = uVar7;
              }
              uVar2 = *(uint *)(iVar8 + 0x14);
              uVar5 = *(uint *)(iStack_c + 8);
              if (*(uint *)(iStack_c + 8) < uVar2) {
                uVar5 = uVar2;
              }
              _pmap_protect(*(undefined4 *)(param_1 + 0x20),*(int *)(iVar8 + 8) + (uVar5 - uVar2),
                            *(int *)(iVar8 + 8) + (uVar4 - uVar2),uVar6 & *(uint *)(iVar8 + 0x1a));
            }
            _lock_done(*(undefined4 *)(iVar8 + 0x10));
          }
          else {
            uVar7 = 7;
            if ((*(byte *)(iStack_8 + 0x18) & 0x10) != 0) {
              uVar7 = 0xfffffffd;
            }
            _pmap_protect(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(iVar8 + 8),
                          *(undefined4 *)(iVar8 + 0xc),uVar7 & *(uint *)(iVar8 + 0x1a));
          }
        }
      }
      _lock_done(param_1);
      return 0;
    }
    if ((*(byte *)(iVar3 + 0x18) & 0x20) != 0) {
      _lock_done(param_1);
      return 4;
    }
    if (param_4 != (*(uint *)(iVar3 + 0x1e) & param_4)) break;
    iVar3 = *(int *)(iVar3 + 4);
  }
  _lock_done(param_1);
  return 2;
}
/* GHIDRADEC_FUNCTION index=1768 start=0x405e624 */

undefined4 _vm_map_inherit(int param_1,uint param_2,uint param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iStack_8;
  
  if ((param_4 < 3) && (-1 < param_4)) {
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
    if (param_2 < *(uint *)(param_1 + 0x10)) {
      param_2 = *(uint *)(param_1 + 0x10);
    }
    if (*(uint *)(param_1 + 0x14) < param_3) {
      param_3 = *(uint *)(param_1 + 0x14);
    }
    if (param_3 < param_2) {
      param_2 = param_3;
    }
    iVar2 = _vm_map_lookup_entry(param_1,param_2,&iStack_8);
    if (iVar2 == 0) {
      iStack_8 = *(int *)(iStack_8 + 4);
    }
    else if (*(uint *)(iStack_8 + 8) < param_2) {
      __vm_map_clip_start(param_1 + 8,iStack_8,param_2);
    }
    for (iVar2 = iStack_8; (param_1 + 8 != iVar2 && (*(uint *)(iVar2 + 8) < param_3));
        iVar2 = *(int *)(iVar2 + 4)) {
      if (param_3 < *(uint *)(iVar2 + 0xc)) {
        __vm_map_clip_end(param_1 + 8,iVar2,param_3);
      }
      *(int *)(iVar2 + 0x22) = param_4;
    }
    _lock_done(param_1);
    uVar1 = 0;
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1769 start=0x405e6f8 */

undefined4 _vm_map_pageable(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  sword sVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  int iStack_8;
  
  bVar5 = true;
  _lock_write(param_1);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  if (param_2 < *(uint *)(param_1 + 0x10)) {
    param_2 = *(uint *)(param_1 + 0x10);
  }
  if (*(uint *)(param_1 + 0x14) < param_3) {
    param_3 = *(uint *)(param_1 + 0x14);
  }
  if (param_3 < param_2) {
    param_2 = param_3;
  }
  iVar3 = _vm_map_lookup_entry(param_1,param_2,&iStack_8);
  if (iVar3 == 0) {
    iVar3 = *(int *)(iStack_8 + 4);
  }
  else {
    iVar3 = iStack_8;
    if (*(uint *)(iStack_8 + 8) < param_2) {
      __vm_map_clip_start(param_1 + 8,iStack_8,param_2);
    }
  }
  iStack_8 = iVar3;
  if (param_4 == 0) {
    for (; (param_1 + 8 != iVar3 && (*(uint *)(iVar3 + 8) < param_3)); iVar3 = *(int *)(iVar3 + 4))
    {
      if (param_3 < *(uint *)(iVar3 + 0xc)) {
        __vm_map_clip_end(param_1 + 8,iVar3,param_3);
      }
      sVar2 = *(sword *)(iVar3 + 0x26);
      *(sword *)(iVar3 + 0x26) = sVar2 + 1;
      if ((sVar2 == 0) && (-1 < (char)*(byte *)(iVar3 + 0x18))) {
        if (((*(byte *)(iVar3 + 0x18) & 2) == 0) || ((*(byte *)(iVar3 + 0x1d) & 2) == 0)) {
          if (*(int *)(iVar3 + 0x10) == 0) {
            uVar4 = _vm_object_allocate(*(int *)(iVar3 + 0xc) - *(int *)(iVar3 + 8));
            *(undefined4 *)(iVar3 + 0x10) = uVar4;
            *(undefined4 *)(iVar3 + 0x14) = 0;
          }
        }
        else {
          _vm_object_shadow(iVar3 + 0x10,iVar3 + 0x14,*(int *)(iVar3 + 0xc) - *(int *)(iVar3 + 8));
          *(byte *)(iVar3 + 0x18) = *(byte *)(iVar3 + 0x18) & 0xfd;
        }
      }
    }
    bVar5 = param_1 != _kernel_map;
    if (bVar5) {
      _lock_set_recursive(param_1);
      _lock_write_to_read(param_1);
    }
    else {
      _lock_done(param_1);
    }
    for (iVar3 = iStack_8; (param_1 + 8 != iVar3 && (*(uint *)(iVar3 + 8) < param_3));
        iVar3 = *(int *)(iVar3 + 4)) {
      if (*(sword *)(iVar3 + 0x26) == 1) {
        _vm_fault_wire(param_1,iVar3);
      }
    }
    if (!bVar5) {
      return 0;
    }
    _lock_clear_recursive(param_1);
  }
  else {
    for (iVar1 = iVar3; (param_1 + 8 != iVar1 && (*(uint *)(iVar1 + 8) < param_3));
        iVar1 = *(int *)(iVar1 + 4)) {
      if (*(sword *)(iVar1 + 0x26) == 0) {
        _lock_done(param_1);
        return 4;
      }
    }
    for (; (param_1 + 8 != iVar3 && (*(uint *)(iVar3 + 8) < param_3)); iVar3 = *(int *)(iVar3 + 4))
    {
      if (param_3 < *(uint *)(iVar3 + 0xc)) {
        __vm_map_clip_end(param_1 + 8,iVar3,param_3);
      }
      sVar2 = *(sword *)(iVar3 + 0x26);
      *(sword *)(iVar3 + 0x26) = sVar2 + -1;
      if (sVar2 == 1) {
        _vm_fault_unwire(param_1,iVar3);
      }
    }
  }
  if (bVar5) {
    _lock_done(param_1);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1770 start=0x405e916 */

void _vm_map_entry_unwire(undefined4 param_1,int param_2)

{
  _vm_fault_unwire(param_1,param_2);
  *(undefined2 *)(param_2 + 0x26) = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1771 start=0x405e938 */

void _vm_map_entry_delete(int param_1,int *param_2)

{
  if (*(sword *)((int)param_2 + 0x26) != 0) {
    _vm_map_entry_unwire(param_1,param_2);
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) - (param_2[3] - param_2[2]);
  if ((*(byte *)(param_2 + 6) & 0xa0) == 0) {
    _vm_object_deallocate(param_2[4]);
  }
  else {
    _vm_map_deallocate(param_2[4]);
  }
  __vm_map_entry_dispose(param_1 + 8,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=1772 start=0x405e9b0 */

undefined4 _vm_map_delete(int param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puStack_8;
  
  iVar4 = _vm_map_lookup_entry(param_1,param_2,&puStack_8);
  if (iVar4 == 0) {
    puStack_8 = (undefined4 *)puStack_8[1];
  }
  else {
    if ((uint)puStack_8[2] < param_2) {
      __vm_map_clip_start(param_1 + 8,puStack_8,param_2);
    }
    *(undefined4 *)(param_1 + 0x30) = *puStack_8;
  }
  puVar5 = puStack_8;
  if (param_2 <= *(uint *)(*(int *)(param_1 + 0x34) + 8)) {
    *(undefined4 *)(param_1 + 0x34) = *puStack_8;
  }
  while (((undefined4 *)(param_1 + 8) != puVar5 && ((uint)puVar5[2] < param_3))) {
    if (param_3 < (uint)puVar5[3]) {
      __vm_map_clip_end(param_1 + 8,puVar5,param_3);
    }
    puVar1 = (undefined4 *)puVar5[1];
    iVar4 = puVar5[2];
    iVar2 = puVar5[3];
    iVar3 = puVar5[4];
    if (*(sword *)((int)puVar5 + 0x26) != 0) {
      _vm_map_entry_unwire(param_1,puVar5);
    }
    if (iVar3 == _kernel_object) {
      _vm_object_page_remove(iVar3,puVar5[5],(iVar2 - iVar4) + puVar5[5]);
    }
    if (*(int *)(param_1 + 0x28) == 0) {
      _vm_object_pmap_remove(iVar3,puVar5[5],(iVar2 - iVar4) + puVar5[5]);
    }
    _pmap_remove(*(undefined4 *)(param_1 + 0x20),iVar4,iVar2);
    _vm_map_entry_delete(param_1,puVar5);
    puVar5 = puVar1;
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1773 start=0x405ead0 */

undefined4 _vm_map_remove(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  
  _lock_write(param_1);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  if (param_2 < *(uint *)(param_1 + 0x10)) {
    param_2 = *(uint *)(param_1 + 0x10);
  }
  if (*(uint *)(param_1 + 0x14) < param_3) {
    param_3 = *(uint *)(param_1 + 0x14);
  }
  if (param_3 < param_2) {
    param_2 = param_3;
  }
  uVar1 = _vm_map_delete(param_1,param_2,param_3);
  _lock_done(param_1);
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1774 start=0x405eb2e */

undefined4 _vm_map_check_protection(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_8;
  
  iVar1 = _vm_map_lookup_entry(param_1,param_2,&iStack_8);
  if (iVar1 == 0) {
loc_405EB58:
    uVar2 = 0;
  }
  else {
    if (param_2 < param_3) {
      do {
        if (((param_1 + 8 == iStack_8) || (param_2 < *(uint *)(iStack_8 + 8))) ||
           (param_4 != (param_4 & *(uint *)(iStack_8 + 0x1a)))) goto loc_405EB58;
        param_2 = *(uint *)(iStack_8 + 0xc);
        iStack_8 = *(int *)(iStack_8 + 4);
      } while (param_2 < param_3);
    }
    uVar2 = 1;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1775 start=0x405eb94 */

void _vm_map_copy_entry(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iStack_8;
  
  if (((*(byte *)(param_3 + 0x18) & 0x20) == 0) && ((*(byte *)(param_4 + 0x18) & 0x20) == 0)) {
    if (*(sword *)(param_4 + 0x26) != 0) {
      _vm_map_entry_unwire(param_2,param_4);
    }
    if (*(int *)(param_2 + 0x28) == 0) {
      _vm_object_pmap_remove
                (*(undefined4 *)(param_4 + 0x10),*(int *)(param_4 + 0x14),
                 (*(int *)(param_4 + 0xc) - *(int *)(param_4 + 8)) + *(int *)(param_4 + 0x14));
    }
    _pmap_remove(*(undefined4 *)(param_2 + 0x20),*(undefined4 *)(param_4 + 8),
                 *(undefined4 *)(param_4 + 0xc));
    if (*(sword *)(param_3 + 0x26) == 0) {
      if ((*(byte *)(param_3 + 0x18) & 2) == 0) {
        if ((*(int *)(param_1 + 0x28) == 0) && (*(int *)(param_1 + 0x2c) != 1)) {
          _vm_object_pmap_copy
                    (*(undefined4 *)(param_3 + 0x10),*(int *)(param_3 + 0x14),
                     (*(int *)(param_3 + 0xc) - *(int *)(param_3 + 8)) + *(int *)(param_3 + 0x14));
        }
        else {
          _pmap_protect(*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_3 + 8),
                        *(undefined4 *)(param_3 + 0xc),*(uint *)(param_3 + 0x1a) & 0xfffffffd);
        }
      }
      uVar1 = *(undefined4 *)(param_4 + 0x10);
      _vm_object_copy(*(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 0x14),
                      *(int *)(param_3 + 0xc) - *(int *)(param_3 + 8),param_4 + 0x10,param_4 + 0x14,
                      &iStack_8);
      if (iStack_8 != 0) {
        *(byte *)(param_3 + 0x18) = *(byte *)(param_3 + 0x18) | 2;
      }
      *(byte *)(param_4 + 0x18) = *(byte *)(param_4 + 0x18) | 2;
      *(byte *)(param_3 + 0x18) = *(byte *)(param_3 + 0x18) | 0x10;
      *(byte *)(param_4 + 0x18) = *(byte *)(param_4 + 0x18) | 0x10;
      if ((*(byte *)(param_3 + 0x1d) & 4) != 0) {
        *(uint *)(param_4 + 0x1a) = *(uint *)(param_4 + 0x1e) & 4 | *(uint *)(param_4 + 0x1a);
      }
      _vm_object_deallocate(uVar1);
      _pmap_copy(*(undefined4 *)(param_2 + 0x20),*(undefined4 *)(param_1 + 0x20),
                 *(int *)(param_4 + 8),*(int *)(param_4 + 0xc) - *(int *)(param_4 + 8),
                 *(undefined4 *)(param_3 + 8));
    }
    else {
      _vm_fault_copy_entry(param_2,param_1,param_4,param_3);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1776 start=0x405ed0a */

/* WARNING: Removing unreachable block (ram,0x0405f00c) */
/* WARNING: Removing unreachable block (ram,0x0405f014) */
/* WARNING: Removing unreachable block (ram,0x0405f01a) */
/* WARNING: Removing unreachable block (ram,0x0405f040) */

int _vm_map_copy(int param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6,
                int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iStack_8;
  
  uVar8 = param_4 + param_5;
  uVar9 = param_3 + param_4;
  if ((uVar9 < param_3) || (uVar8 < param_5)) {
    return 3;
  }
  if (param_1 == param_2) {
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  }
  else if (param_2 < param_1) {
    _lock_write(param_2);
    *(int *)(param_2 + 0x40) = *(int *)(param_2 + 0x40) + 1;
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  }
  else {
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
    _lock_write(param_2);
    *(int *)(param_2 + 0x40) = *(int *)(param_2 + 0x40) + 1;
  }
  iVar12 = 0;
  if ((*(int *)(param_2 + 0x28) != 0) && (*(int *)(param_1 + 0x28) != 0)) {
    iVar3 = _vm_map_check_protection(param_2,param_5,uVar8,1);
    if (iVar3 == 0) {
      iVar12 = 2;
      goto loc_405F05E;
    }
    if (param_6 == 0) {
      iVar3 = _vm_map_check_protection(param_1,param_3,uVar9,2);
      if (iVar3 == 0) {
        iVar12 = 2;
        goto loc_405F05E;
      }
    }
    else {
      iVar12 = _vm_map_insert(param_1,0,0,param_3,uVar9);
      if (iVar12 != 0) goto loc_405F05E;
    }
  }
  _vm_map_lookup_entry(param_2,param_5,&iStack_8);
  iVar3 = iStack_8;
  if (*(uint *)(iStack_8 + 8) < param_5) {
    __vm_map_clip_start(param_2 + 8,iStack_8,param_5);
  }
  _vm_map_lookup_entry(param_1,param_3,&iStack_8);
  iVar11 = iStack_8;
  if (*(uint *)(iStack_8 + 8) < param_3) {
    __vm_map_clip_start(param_1 + 8,iStack_8,param_3);
  }
  uVar5 = param_5;
  if ((iVar11 != iVar3) ||
     (_vm_map_lookup_entry(param_2,param_5,&iStack_8), iVar3 = iStack_8, iVar11 != iStack_8)) {
    while (uVar5 < uVar8) {
      if (uVar8 < *(uint *)(iVar3 + 0xc)) {
        __vm_map_clip_end(param_2 + 8,iVar3,uVar8);
      }
      if (uVar9 < *(uint *)(iVar11 + 0xc)) {
        __vm_map_clip_end(param_1 + 8,iVar11,uVar9);
      }
      uVar5 = *(int *)(iVar3 + 8) + (*(int *)(iVar11 + 0xc) - *(int *)(iVar11 + 8));
      if (uVar5 < *(uint *)(iVar3 + 0xc)) {
        __vm_map_clip_end(param_2 + 8,iVar3,uVar5);
      }
      uVar5 = *(int *)(iVar11 + 8) + (*(int *)(iVar3 + 0xc) - *(int *)(iVar3 + 8));
      if (uVar5 < *(uint *)(iVar11 + 0xc)) {
        __vm_map_clip_end(param_1 + 8,iVar11,uVar5);
      }
      if ((*(char *)(iVar3 + 0x18) < '\0') || (*(char *)(iVar11 + 0x18) < '\0')) {
        iVar2 = *(int *)(iVar11 + 0xc) - *(int *)(iVar11 + 8);
        if (*(char *)(iVar3 + 0x18) < '\0') {
          uVar7 = *(undefined4 *)(iVar3 + 0x14);
          iVar6 = *(int *)(iVar3 + 0x10);
        }
        else {
          uVar7 = *(undefined4 *)(iVar3 + 8);
          _lock_set_recursive(param_2);
          iVar6 = param_2;
        }
        if (*(char *)(iVar11 + 0x18) < '\0') {
          iVar10 = *(int *)(iVar11 + 0x10);
          iVar4 = *(int *)(iVar11 + 0x14);
          iVar1 = iVar2 + iVar4;
          if (iVar6 != iVar10) {
            _lock_write(iVar10);
            *(int *)(iVar10 + 0x40) = *(int *)(iVar10 + 0x40) + 1;
            _vm_map_delete(iVar10,iVar4,iVar1);
            _vm_map_insert(iVar10,0,0,iVar4,iVar1);
            _lock_done(iVar10);
          }
        }
        else {
          iVar4 = *(int *)(iVar11 + 8);
          _lock_set_recursive(param_1);
          iVar10 = param_1;
        }
        _vm_map_copy(iVar10,iVar6,iVar4,iVar2,uVar7,0,0);
        if (iVar10 == param_1) {
          _lock_clear_recursive(param_1);
        }
        if (iVar6 == param_2) {
          _lock_clear_recursive(param_2);
        }
      }
      else {
        _vm_map_copy_entry(param_2,param_1,iVar3,iVar11);
      }
      iVar11 = *(int *)(iVar11 + 4);
      uVar5 = *(uint *)(iVar3 + 0xc);
      iVar3 = *(int *)(iVar3 + 4);
    }
  }
loc_405F05E:
  if (param_7 != 0) {
    _vm_map_delete(param_2,param_5,param_4 + param_5);
  }
  _lock_done(param_2);
  if (param_1 != param_2) {
    _lock_done(param_1);
  }
  return iVar12;
}
/* GHIDRADEC_FUNCTION index=1777 start=0x405f0a0 */

int _vm_map_fork(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  
  _lock_write(param_1);
  *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
  uVar2 = _pmap_create(0);
  iVar3 = _vm_map_create(uVar2,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                         *(undefined4 *)(param_1 + 0x1c));
  piVar8 = *(int **)(param_1 + 0xc);
  if ((int *)(param_1 + 8) != piVar8) {
    piVar1 = (int *)(iVar3 + 8);
    do {
      if ((*(byte *)(piVar8 + 6) & 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(aVmMapForkEncou);
      }
      iVar7 = *(int *)((int)piVar8 + 0x22);
      if (iVar7 == 1) {
        piVar6 = (int *)__vm_map_entry_create(piVar1);
        *piVar6 = *piVar8;
        piVar6[1] = piVar8[1];
        piVar6[2] = piVar8[2];
        piVar6[3] = piVar8[3];
        piVar6[4] = piVar8[4];
        piVar6[5] = piVar8[5];
        piVar6[6] = piVar8[6];
        piVar6[7] = piVar8[7];
        piVar6[8] = piVar8[8];
        piVar6[9] = piVar8[9];
        *(undefined2 *)(piVar6 + 10) = *(undefined2 *)(piVar8 + 10);
        *(undefined2 *)((int)piVar6 + 0x26) = 0;
        piVar6[4] = 0;
        *(byte *)(piVar6 + 6) = *(byte *)(piVar6 + 6) & 0x7f;
        *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
        *piVar6 = *piVar1;
        piVar6[1] = *(int *)(*piVar1 + 4);
        iVar7 = *piVar6;
        *(int **)piVar6[1] = piVar6;
        *(int **)(iVar7 + 4) = piVar6;
        if (*(char *)(piVar8 + 6) < '\0') {
          iVar7 = _vm_map_copy(iVar3,piVar8[4],piVar6[2],piVar6[3] - piVar6[2],piVar8[5],0,0);
          if (iVar7 != 0) {
            _printf(aVmMapForkCopyI);
          }
        }
        else {
          _vm_map_copy_entry(param_1,iVar3,piVar8,piVar6);
        }
      }
      else if ((iVar7 < 2) && (iVar7 == 0)) {
        if (-1 < *(char *)(piVar8 + 6)) {
          iVar4 = _vm_map_create(0,piVar8[2],piVar8[3],1);
          *(undefined4 *)(iVar4 + 0x28) = 0;
          piVar6 = (int *)(iVar4 + 8);
          piVar5 = (int *)__vm_map_entry_create(piVar6);
          *piVar5 = *piVar8;
          piVar5[1] = piVar8[1];
          piVar5[2] = piVar8[2];
          piVar5[3] = piVar8[3];
          piVar5[4] = piVar8[4];
          piVar5[5] = piVar8[5];
          piVar5[6] = piVar8[6];
          piVar5[7] = piVar8[7];
          piVar5[8] = piVar8[8];
          piVar5[9] = piVar8[9];
          *(undefined2 *)(piVar5 + 10) = *(undefined2 *)(piVar8 + 10);
          *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + 1;
          *piVar5 = *piVar6;
          piVar5[1] = *(int *)(*piVar6 + 4);
          iVar7 = *piVar5;
          *(int **)piVar5[1] = piVar5;
          *(int **)(iVar7 + 4) = piVar5;
          *(byte *)(piVar8 + 6) = *(byte *)(piVar8 + 6) | 0x80;
          piVar8[4] = iVar4;
          piVar8[5] = piVar8[2];
        }
        piVar6 = (int *)__vm_map_entry_create(piVar1);
        *piVar6 = *piVar8;
        piVar6[1] = piVar8[1];
        piVar6[2] = piVar8[2];
        piVar6[3] = piVar8[3];
        piVar6[4] = piVar8[4];
        piVar6[5] = piVar8[5];
        piVar6[6] = piVar8[6];
        piVar6[7] = piVar8[7];
        piVar6[8] = piVar8[8];
        piVar6[9] = piVar8[9];
        *(undefined2 *)(piVar6 + 10) = *(undefined2 *)(piVar8 + 10);
        _vm_map_reference(piVar6[4]);
        *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
        *piVar6 = *piVar1;
        piVar6[1] = *(int *)(*piVar1 + 4);
        iVar7 = *piVar6;
        *(int **)piVar6[1] = piVar6;
        *(int **)(iVar7 + 4) = piVar6;
        _pmap_copy(*(undefined4 *)(iVar3 + 0x20),*(undefined4 *)(param_1 + 0x20),piVar6[2],
                   piVar8[3] - piVar8[2],piVar8[2]);
      }
      piVar8 = (int *)piVar8[1];
    } while ((int *)(param_1 + 8) != piVar8);
  }
  *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(param_1 + 0x24);
  _lock_done(param_1);
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=1778 start=0x405f2da */

undefined4
_vm_map_lookup(int *param_1,uint param_2,uint param_3,int *param_4,undefined4 *param_5,int *param_6,
              uint *param_7,int *param_8,uint *param_9)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iStack_c;
  int iStack_8;
  
  iVar7 = *param_1;
  do {
    _lock_read(iVar7);
    iVar1 = *(int *)(iVar7 + 0x30);
    *param_4 = iVar1;
    if (((iVar7 + 8 == iVar1) || (param_2 < *(uint *)(iVar1 + 8))) ||
       (*(uint *)(iVar1 + 0xc) <= param_2)) {
      iVar1 = _vm_map_lookup_entry(iVar7,param_2,&iStack_8);
      if (iVar1 == 0) {
        _lock_done(iVar7);
        return 1;
      }
      *param_4 = iStack_8;
      iVar1 = iStack_8;
    }
    if ((*(byte *)(iVar1 + 0x18) & 0x20) != 0) {
      iVar1 = *(int *)(iVar1 + 0x10);
      *param_1 = iVar1;
      goto loc_405F452;
    }
    uVar5 = *(uint *)(iVar1 + 0x1a);
    if (param_3 != (uVar5 & param_3)) {
      _lock_done(iVar7);
      return 2;
    }
    iVar8 = -(int)-(*(sword *)(iVar1 + 0x26) != 0);
    *param_8 = iVar8;
    if (iVar8 != 0) {
      uVar5 = *(uint *)(iVar1 + 0x1a);
      param_3 = uVar5;
    }
    uVar4 = *(uint *)(iVar1 + 0x18) >> 0x1f ^ 1;
    uVar6 = param_2;
    iVar8 = iVar7;
    if (uVar4 == 0) {
      iVar8 = *(int *)(iVar1 + 0x10);
      uVar6 = *(int *)(iVar1 + 0x14) + (param_2 - *(int *)(iVar1 + 8));
      _lock_read(iVar8);
      iVar2 = _vm_map_lookup_entry(iVar8,uVar6,&iStack_c);
      iVar1 = iStack_c;
      if (iVar2 == 0) {
        _lock_done(iVar8);
        _lock_done(iVar7);
        return 1;
      }
    }
    if ((*(byte *)(iVar1 + 0x18) & 2) != 0) {
      if ((param_3 & 2) == 0) {
        uVar5 = uVar5 & 0xfffffffd;
        goto loc_405F436;
      }
      iVar2 = _lock_read_to_write(iVar8);
      if (iVar2 == 0) {
        _vm_object_shadow(iVar1 + 0x10,iVar1 + 0x14,*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 8));
        *(byte *)(iVar1 + 0x18) = *(byte *)(iVar1 + 0x18) & 0xfd;
        _lock_write_to_read(iVar8);
        goto loc_405F436;
      }
      goto loc_405F44A;
    }
loc_405F436:
    if (*(int *)(iVar1 + 0x10) != 0) goto loc_405F47E;
    iVar2 = _lock_read_to_write(iVar8);
    if (iVar2 == 0) {
      uVar3 = _vm_object_allocate(*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 8));
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      *(undefined4 *)(iVar1 + 0x14) = 0;
      _lock_write_to_read(iVar8);
loc_405F47E:
      *param_6 = *(int *)(iVar1 + 0x14) + (uVar6 - *(int *)(iVar1 + 8));
      *param_5 = *(undefined4 *)(iVar1 + 0x10);
      if (uVar4 == 0) {
        uVar4 = -(int)-(*(int *)(iVar8 + 0x2c) == 1);
      }
      *param_7 = uVar5;
      *param_9 = uVar4;
      return 0;
    }
loc_405F44A:
    iVar1 = iVar7;
    if (iVar7 != iVar8) {
loc_405F452:
      _lock_done(iVar7);
      iVar7 = iVar1;
    }
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1779 start=0x405f4c0 */

void _vm_map_lookup_done(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 0x18) < '\0') {
    _lock_done(*(undefined4 *)(param_2 + 0x10));
  }
  _lock_done(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1780 start=0x405f4e8 */

undefined4
_vm_map_machine_attribute
          (int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if ((param_2 < *(uint *)(param_1 + 0x10)) || (*(uint *)(param_1 + 0x14) < param_3 + param_2)) {
    uVar1 = 4;
  }
  else {
    _lock_write(param_1);
    *(int *)(param_1 + 0x40) = *(int *)(param_1 + 0x40) + 1;
    uVar1 = _pmap_attribute(*(undefined4 *)(param_1 + 0x20),param_2,param_3,param_4,param_5);
    _lock_done(param_1);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1781 start=0x405f548 */

undefined4
_vm_region(int param_1,int *param_2,uint *param_3,undefined4 *param_4,undefined4 *param_5,
          undefined4 *param_6,int *param_7,undefined4 *param_8,int *param_9)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iStack_8;
  
  if (param_1 == 0) {
    uVar2 = 4;
  }
  else {
    iVar4 = *param_2;
    _lock_read(param_1);
    iVar3 = _vm_map_lookup_entry(param_1,iVar4,&iStack_8);
    iVar4 = iStack_8;
    if ((iVar3 == 0) && (iVar4 = *(int *)(iStack_8 + 4), param_1 + 8 == *(int *)(iStack_8 + 4))) {
      _lock_done(param_1);
      uVar2 = 3;
    }
    else {
      iVar3 = *(int *)(iVar4 + 8);
      *param_4 = *(undefined4 *)(iVar4 + 0x1a);
      *param_5 = *(undefined4 *)(iVar4 + 0x1e);
      *param_6 = *(undefined4 *)(iVar4 + 0x22);
      *param_2 = iVar3;
      *param_3 = *(int *)(iVar4 + 0xc) - iVar3;
      iVar3 = *(int *)(iVar4 + 0x14);
      if ((char)*(byte *)(iVar4 + 0x18) < '\0') {
        iVar4 = *(int *)(iVar4 + 0x10);
        _lock_read(iVar4);
        _vm_map_lookup_entry(iVar4,iVar3,&iStack_8);
        uVar1 = *(int *)(iStack_8 + 0xc) - iVar3;
        if (uVar1 < *param_3) {
          *param_3 = uVar1;
        }
        uVar2 = _vm_object_name(*(undefined4 *)(iStack_8 + 0x10));
        *param_8 = uVar2;
        *param_9 = *(int *)(iStack_8 + 0x14) + (iVar3 - *(int *)(iStack_8 + 8));
        *param_7 = -(int)-(*(int *)(iVar4 + 0x2c) != 1);
        _lock_done(iVar4);
      }
      else if ((*(byte *)(iVar4 + 0x18) & 0x20) == 0) {
        *param_7 = 0;
        uVar2 = _vm_object_name(*(undefined4 *)(iVar4 + 0x10));
        *param_8 = uVar2;
        *param_9 = iVar3;
      }
      else {
        *param_7 = 0;
        *param_8 = 0;
        *param_9 = iVar3;
      }
      _lock_done(param_1);
      uVar2 = 0;
    }
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1782 start=0x405f68e */

int _vm_move(undefined4 param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5,
            int *param_6)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_8;
  
  if (param_4 == 0) {
    *param_6 = 0;
    iVar3 = 0;
  }
  else {
    uVar1 = ~_page_mask & param_2;
    iVar2 = (~_page_mask & _page_mask + param_2 + param_4) - uVar1;
    iStack_8 = 0;
    iVar3 = _vm_allocate(param_3,&iStack_8,iVar2,1);
    if (iVar3 == 0) {
      iVar3 = _vm_map_copy(param_3,param_1,iStack_8,iVar2,uVar1,0,param_5);
      if (iVar3 == 0) {
        *param_6 = iStack_8 + (param_2 - uVar1);
      }
      else {
        _vm_deallocate(param_3,iStack_8,iVar2);
      }
    }
  }
  return iVar3;
}
/* GHIDRADEC_FUNCTION index=1783 start=0x405f72c */

undefined4 _vm_map_pmap_EXTERNAL(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}
/* GHIDRADEC_FUNCTION index=1784 start=0x405f73c */

int _vm_mem_ppi(uint param_1)

{
  undefined *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = _mem_region;
  while( true ) {
    if (_mem_region + _num_regions * 0x1c <= puVar1) {
                    /* WARNING: Subroutine does not return */
      _panic(&aMemPpi);
    }
    if ((*(uint *)(puVar1 + 0x14) <= param_1) && (param_1 < *(uint *)(puVar1 + 0x18))) break;
    iVar2 = *(int *)(puVar1 + 0xc) + iVar2;
    puVar1 = puVar1 + 0x1c;
  }
  return iVar2 + (param_1 - *(uint *)(puVar1 + 0x14) >> (_page_shift & 0x3f));
}
/* GHIDRADEC_FUNCTION index=1785 start=0x405f7a8 */

undefined4 _vm_valid_page(uint param_1)

{
  undefined *puVar1;
  
  puVar1 = _mem_region;
  while( true ) {
    if (_mem_region + _num_regions * 0x1c <= puVar1) {
      return 0;
    }
    if ((*(uint *)(puVar1 + 0x14) <= param_1) && (param_1 < *(uint *)(puVar1 + 0x18))) break;
    puVar1 = puVar1 + 0x1c;
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=1786 start=0x405f7f0 */

int _vm_phys_to_vm_page(uint param_1)

{
  undefined *puVar1;
  
  puVar1 = _mem_region;
  if (_mem_region < _mem_region + _num_regions * 0x1c) {
    do {
      if ((*(uint *)((int)puVar1 + 0x14) <= param_1) && (param_1 < *(uint *)((int)puVar1 + 0x18))) {
        return *(int *)puVar1 +
               ((param_1 >> (_page_shift & 0x3f)) - *(int *)((int)puVar1 + 4)) * 0x2e;
      }
      puVar1 = (undefined *)((int)puVar1 + 0x1c);
    } while (puVar1 < _mem_region + _num_regions * 0x1c);
  }
  return 0;
}
/* GHIDRADEC_FUNCTION index=1787 start=0x405f85c */

void _vm_region_to_vm_page(undefined4 param_1)

{
  _vm_phys_to_vm_page(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1788 start=0x405f86e */

void _vm_alloc_from_regions(int param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  undefined *puVar3;
  
  puVar3 = _mem_region;
  if (_mem_region < _mem_region + _num_regions * 0x1c) {
    puVar2 = &dword_40C2C40;
    do {
      uVar1 = param_1 + (-param_2 & param_2 + (*puVar2 - 1));
      if (uVar1 <= *(uint *)(puVar3 + 0x18)) {
        *puVar2 = uVar1;
        return;
      }
      puVar2 = puVar2 + 7;
      puVar3 = puVar3 + 0x1c;
    } while (puVar3 < _mem_region + _num_regions * 0x1c);
  }
                    /* WARNING: Subroutine does not return */
  _panic(aVmMemAllocFrom);
}
/* GHIDRADEC_FUNCTION index=1789 start=0x405f8de */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _vm_object_init(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  _vm_object_zone = _zinit(0x52,~_page_mask & _page_mask + 0x80000,0,0,&aObjects);
  _object_hash_zone = _zinit(0xc,0x19000,0,0,aObjectHashZone);
  dword_40C2DA4 = &_vm_object_cached_list;
  _vm_object_cached_list = &_vm_object_cached_list;
  dword_40C31B0 = &_vm_object_list;
  _vm_object_list = &_vm_object_list;
  _vm_object_count = 0;
  iVar1 = 0;
  puVar2 = &_vm_object_hashtable;
  do {
    puVar2[1] = puVar2;
    *puVar2 = puVar2;
    puVar2 = puVar2 + 2;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x80);
  _vm_cache_max = (_mem_size >> 0x14) * 0x32;
  if (0x9c4 < _vm_cache_max) {
    _vm_cache_max = 0x9c4;
  }
  word_40C31CC = 1;
  word_40C31CE = 0;
  dword_40C31C8 = 0;
  word_40C31F8 = 0;
  dword_40C31D0 = 0;
  dword_40C31DC = 0;
  dword_40C31E4 = 0;
  dword_40C31E8 = 0;
  _unk_40C31FC = (word)(byte_40C31FD & 0xf7);
  unk_40C31FA = unk_40C31FA & 0xcf | 8;
  dword_40C31E0 = 0;
  dword_40C31D4 = 0;
  dword_40C31D8 = 0;
  dword_40C3206 = 0;
  byte_40C31FB = byte_40C31FB & 0xf0;
  _unk_40C31FC = _unk_40C31FC & 0x2f | 0x20;
  _kernel_object = _kernel_object_store;
  __vm_object_allocate(0x4000000,_kernel_object_store);
  _vm_submap_object = _vm_submap_object_store;
  __vm_object_allocate(0x4000000,_vm_submap_object_store);
  return;
}
/* GHIDRADEC_FUNCTION index=1790 start=0x405fa6c */

undefined4 _vm_object_allocate(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = _zalloc(_vm_object_zone);
  __vm_object_allocate(param_1,uVar1);
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1791 start=0x405fa9e */

void __vm_object_allocate(undefined4 param_1,int param_2)

{
  _bcopy(_vm_object_template,param_2,0x52);
  *(int *)(param_2 + 4) = param_2;
  *(int *)param_2 = param_2;
  *(undefined4 *)(param_2 + 0x10) = param_1;
  if (dword_40C31B0 == &_vm_object_list) {
    _vm_object_list = param_2;
  }
  else {
    dword_40C31B0[2] = param_2;
  }
  *(undefined4 **)(param_2 + 0xc) = dword_40C31B0;
  *(int **)(param_2 + 8) = &_vm_object_list;
  dword_40C31B0 = (undefined4 *)param_2;
  _vm_object_count = _vm_object_count + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1792 start=0x405fb04 */

void _vm_object_reference(int param_1)

{
  if (param_1 != 0) {
    *(sword *)(param_1 + 0x14) = *(sword *)(param_1 + 0x14) + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1793 start=0x405fb18 */

void _vm_object_deallocate(int param_1)

{
  int iVar1;
  sword sVar2;
  
  while( true ) {
    if (param_1 == 0) {
      return;
    }
    sVar2 = *(sword *)(param_1 + 0x14);
    *(sword *)(param_1 + 0x14) = sVar2 + -1;
    if (sVar2 != 1) break;
    if ((*(byte *)(param_1 + 0x42) & 0x10) != 0) {
      if (0 < *(sword *)(param_1 + 0x16)) {
        iVar1 = param_1;
        if (dword_40C2DA4 != &_vm_object_cached_list) {
          *(int *)((int)dword_40C2DA4 + 0x46) = param_1;
          iVar1 = _vm_object_cached_list;
        }
        _vm_object_cached_list = iVar1;
        *(undefined4 **)(param_1 + 0x4a) = dword_40C2DA4;
        *(int **)(param_1 + 0x46) = &_vm_object_cached_list;
        _vm_object_cached = _vm_object_cached + 1;
        dword_40C2DA4 = (undefined4 *)param_1;
        _vm_object_deactivate_pages(param_1);
        _vm_object_cache_trim();
        return;
      }
      *(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) & 0xef;
    }
    _vm_object_remove(*(undefined4 *)(param_1 + 0x24));
    iVar1 = *(int *)(param_1 + 0x1c);
    _vm_object_terminate(param_1);
    param_1 = iVar1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1794 start=0x405fbbc */

void _vm_object_terminate(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar2 = param_1[7];
  if (iVar2 != 0) {
    if (param_1 == *(undefined4 **)(iVar2 + 0x18)) {
      *(undefined4 *)(iVar2 + 0x18) = 0;
    }
    else if (*(undefined4 **)(iVar2 + 0x18) != (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(aVmObjectTermin);
    }
  }
  while (*(sword *)(param_1 + 0x10) != 0) {
    _thread_sleep(param_1,0,0);
  }
  puVar1 = (undefined4 *)*param_1;
  while (puVar4 = puVar1, puVar4 != param_1) {
    if ((*(byte *)((int)puVar4 + 0x1e) & 0x40) != 0) {
      puVar1 = (undefined4 *)*puVar4;
      puVar3 = (undefined4 *)puVar4[1];
      puVar5 = puVar3;
      if (puVar1 != &_vm_page_queue_active) {
        puVar1[1] = puVar3;
        puVar5 = dword_40C2C14;
      }
      dword_40C2C14 = puVar5;
      *puVar3 = puVar1;
      *(byte *)((int)puVar4 + 0x1e) = *(byte *)((int)puVar4 + 0x1e) & 0xbf;
      _vm_page_active_count = _vm_page_active_count + -1;
    }
    if (*(char *)((int)puVar4 + 0x1e) < '\0') {
      puVar1 = (undefined4 *)*puVar4;
      puVar3 = (undefined4 *)puVar4[1];
      puVar5 = puVar3;
      if (puVar1 != &_vm_page_queue_inactive) {
        puVar1[1] = puVar3;
        puVar5 = dword_40C23DC;
      }
      dword_40C23DC = puVar5;
      *puVar3 = puVar1;
      *(byte *)((int)puVar4 + 0x1e) = *(byte *)((int)puVar4 + 0x1e) & 0x7f;
      _vm_page_inactive_count = _vm_page_inactive_count + -1;
    }
    puVar1 = (undefined4 *)puVar4[2];
    if ((*(byte *)((int)puVar4 + 0x1e) & 0x10) != 0) {
      _vm_page_free(puVar4);
    }
  }
  if (param_1[9] != 0) {
    _vm_pager_deallocate(param_1[9]);
  }
  if (*(sword *)(param_1 + 0x10) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVmObjectDeallo);
  }
  while (param_1 != (undefined4 *)*param_1) {
    _vm_page_free(*param_1);
  }
  puVar1 = (undefined4 *)param_1[2];
  puVar4 = (undefined4 *)param_1[3];
  puVar3 = puVar4;
  if ((undefined4 **)puVar1 != &_vm_object_list) {
    puVar1[3] = puVar4;
    puVar3 = dword_40C31B0;
  }
  dword_40C31B0 = puVar3;
  if ((undefined4 **)puVar4 != &_vm_object_list) {
    puVar4[2] = puVar1;
    puVar1 = _vm_object_list;
  }
  _vm_object_list = puVar1;
  _vm_object_count = _vm_object_count + -1;
  _zfree(_vm_object_zone,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1795 start=0x405fd08 */

void _vm_object_destroy(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _vm_object_lookup(param_1);
  if (iVar1 != 0) {
    _vm_object_deallocate(iVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1796 start=0x405fd28 */

void _vm_object_deactivate_pages(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)*param_1;
  while (puVar2 = puVar1, puVar2 != param_1) {
    puVar1 = (undefined4 *)puVar2[2];
    if (-1 < *(char *)((int)puVar2 + 0x1e)) {
      _vm_page_deactivate(puVar2);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1797 start=0x405fd60 */

void _vm_object_cache_trim(void)

{
  int iVar1;
  int iVar2;
  
  while( true ) {
    iVar1 = _vm_object_cached_list;
    if (_vm_object_cached <= _vm_cache_max) {
      return;
    }
    iVar2 = _vm_object_lookup(*(undefined4 *)(_vm_object_cached_list + 0x24));
    if (iVar2 != iVar1) break;
    _vm_object_cache_object(iVar1,0);
  }
                    /* WARNING: Subroutine does not return */
  _panic(aVmObjectDeacti);
}
/* GHIDRADEC_FUNCTION index=1798 start=0x405fdae */

undefined4 _vm_object_cache_object(int param_1,byte param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    *(uint *)(param_1 + 0x42) = *(uint *)(param_1 + 0x42) & 0xefffffff | (param_2 & 1) << 0x1c;
    _vm_object_deallocate(param_1);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1799 start=0x405fdda */

void _vm_object_shutdown(void)

{
  _vm_object_cache_clear();
  return;
}

