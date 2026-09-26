/* GHIDRADEC_FUNCTION index=1800 start=0x405fe3e */

void _vm_object_pmap_remove(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (puVar1 = (undefined4 *)*param_1; puVar1 != param_1; puVar1 = (undefined4 *)puVar1[2]) {
      if ((param_2 <= (uint)puVar1[6]) && ((uint)puVar1[6] < param_3)) {
        _pmap_remove_all(*(undefined4 *)((int)puVar1 + 0x22));
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1801 start=0x405fe86 */

void _vm_object_copy(int *param_1,uint param_2,int param_3,int *param_4,uint *param_5,
                    undefined4 *param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  if (param_1 == (int *)0x0) {
    *param_4 = 0;
    *param_5 = 0;
  }
  else {
    if ((param_1[9] == 0) || ((*(byte *)((int)param_1 + 0x42) & 8) != 0)) {
      *(sword *)(param_1 + 5) = *(sword *)(param_1 + 5) + 1;
      piVar4 = (int *)*param_1;
      if (piVar4 != param_1) {
        do {
          if ((param_2 <= (uint)piVar4[6]) && ((uint)piVar4[6] < param_3 + param_2)) {
            *(byte *)((int)piVar4 + 0x21) = *(byte *)((int)piVar4 + 0x21) | 0x20;
          }
          piVar4 = (int *)piVar4[2];
        } while (piVar4 != param_1);
      }
      *param_4 = (int)param_1;
      *param_5 = param_2;
      *param_6 = 1;
      return;
    }
    _vm_object_collapse(param_1);
    iVar1 = param_1[6];
    if (((iVar1 == 0) || (*(sword *)(iVar1 + 0x16) != 0)) || (*(int *)(iVar1 + 0x24) != 0)) {
      iVar3 = _vm_object_allocate(param_1[4]);
      iVar1 = param_1[6];
      if (iVar1 != 0) {
        if ((param_1 != *(int **)(iVar1 + 0x1c)) || (*(int *)(iVar1 + 0x20) != 0)) {
                    /* WARNING: Subroutine does not return */
          _panic(aVmObjectCopyCo);
        }
        *(sword *)(param_1 + 5) = *(sword *)(param_1 + 5) + -1;
        *(int *)(iVar1 + 0x1c) = iVar3;
        *(sword *)(iVar3 + 0x14) = *(sword *)(iVar3 + 0x14) + 1;
      }
      uVar2 = *(uint *)(iVar3 + 0x10);
      *(int **)(iVar3 + 0x1c) = param_1;
      *(undefined4 *)(iVar3 + 0x20) = 0;
      *(sword *)(param_1 + 5) = *(sword *)(param_1 + 5) + 1;
      param_1[6] = iVar3;
      for (piVar4 = (int *)*param_1; piVar4 != param_1; piVar4 = (int *)piVar4[2]) {
        if ((uint)piVar4[6] < uVar2) {
          *(byte *)((int)piVar4 + 0x21) = *(byte *)((int)piVar4 + 0x21) | 0x20;
        }
      }
      *param_4 = iVar3;
    }
    else {
      *(sword *)(iVar1 + 0x14) = *(sword *)(iVar1 + 0x14) + 1;
      *param_4 = iVar1;
    }
    *param_5 = param_2;
  }
  *param_6 = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1802 start=0x405ffa4 */

void _vm_object_shadow(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = _vm_object_allocate(param_3);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVmObjectShadow);
  }
  *(int *)(iVar2 + 0x1c) = iVar1;
  *(undefined4 *)(iVar2 + 0x20) = *param_2;
  *param_2 = 0;
  *param_1 = iVar2;
  return;
}
/* GHIDRADEC_FUNCTION index=1803 start=0x405ffea */

void _vm_object_setpager(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  *(undefined4 *)(param_1 + 0x28) = param_3;
  return;
}
/* GHIDRADEC_FUNCTION index=1804 start=0x4060002 */

int _vm_object_lookup(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)(&_vm_object_hashtable)[(param_1 & 0x7f) * 2];
  while( true ) {
    if (puVar1 == &_vm_object_hashtable + (param_1 & 0x7f) * 2) {
      return 0;
    }
    iVar2 = puVar1[2];
    if (param_1 == *(uint *)(iVar2 + 0x24)) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  if (*(sword *)(iVar2 + 0x14) == 0) {
    puVar1 = *(undefined4 **)(iVar2 + 0x46);
    puVar3 = *(undefined4 **)(iVar2 + 0x4a);
    puVar4 = puVar3;
    if ((undefined4 **)puVar1 != &_vm_object_cached_list) {
      *(undefined4 **)((int)puVar1 + 0x4a) = puVar3;
      puVar4 = dword_40C2DA4;
    }
    dword_40C2DA4 = puVar4;
    if ((undefined4 **)puVar3 != &_vm_object_cached_list) {
      *(undefined4 **)((int)puVar3 + 0x46) = puVar1;
      puVar1 = _vm_object_cached_list;
    }
    _vm_object_cached_list = puVar1;
    _vm_object_cached = _vm_object_cached + -1;
  }
  *(sword *)(iVar2 + 0x14) = *(sword *)(iVar2 + 0x14) + 1;
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=1805 start=0x4060080 */

void _vm_object_enter(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    param_2 = param_2 & 0x7f;
    puVar1 = &_vm_object_hashtable + param_2 * 2;
    puVar3 = (undefined4 *)_zalloc(_object_hash_zone);
    puVar3[2] = param_1;
    *(byte *)(param_1 + 0x42) = *(byte *)(param_1 + 0x42) | 0x10;
    puVar2 = (undefined4 *)(&dword_40C2DB0)[param_2 * 2];
    if (puVar2 == puVar1) {
      *puVar1 = puVar3;
    }
    else {
      *puVar2 = puVar3;
    }
    puVar3[1] = puVar2;
    *puVar3 = puVar1;
    (&dword_40C2DB0)[param_2 * 2] = puVar3;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1806 start=0x40600e2 */

void _vm_object_remove(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = &_vm_object_hashtable + (param_1 & 0x7f) * 2;
  puVar2 = (undefined4 *)*puVar1;
  while( true ) {
    if (puVar2 == puVar1) {
      return;
    }
    if (param_1 == *(uint *)(puVar2[2] + 0x24)) break;
    puVar2 = (undefined4 *)*puVar2;
  }
  puVar3 = (undefined4 *)*puVar2;
  puVar4 = (undefined4 *)puVar2[1];
  if (puVar3 == puVar1) {
    (&dword_40C2DB0)[(param_1 & 0x7f) * 2] = puVar4;
  }
  else {
    puVar3[1] = puVar4;
  }
  if (puVar4 == puVar1) {
    *puVar1 = puVar3;
  }
  else {
    *puVar4 = puVar3;
  }
  _zfree(_object_hash_zone,puVar2);
  return;
}
/* GHIDRADEC_FUNCTION index=1807 start=0x406014c */

void _vm_object_cache_clear(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if ((undefined4 **)_vm_object_cached_list != &_vm_object_cached_list) {
    do {
      puVar1 = _vm_object_cached_list;
      puVar2 = (undefined4 *)_vm_object_lookup(_vm_object_cached_list[9]);
      if (puVar2 != puVar1) {
                    /* WARNING: Subroutine does not return */
        _panic(aVmObjectCacheC);
      }
      _vm_object_cache_object(puVar1,0);
    } while ((undefined4 **)_vm_object_cached_list != &_vm_object_cached_list);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1808 start=0x406019c */

void _vm_object_collapse(int param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  
  if (_vm_object_collapse_allowed != 0) {
    while ((((param_1 != 0 && (*(sword *)(param_1 + 0x40) == 0)) && (*(int *)(param_1 + 0x24) == 0))
           && (((piVar2 = *(int **)(param_1 + 0x1c), piVar2 != (int *)0x0 &&
                ((piVar2[0x10] & 0xffff0800U) == 0x800)) &&
               ((piVar2[7] == 0 || (*(int *)(piVar2[7] + 0x18) == 0))))))) {
      uVar3 = *(uint *)(param_1 + 0x20);
      uVar4 = *(uint *)(param_1 + 0x10);
      if (*(sword *)(piVar2 + 5) == 1) {
        while (piVar2 != (int *)*piVar2) {
          iVar10 = *piVar2;
          uVar7 = *(uint *)(iVar10 + 0x18) - uVar3;
          if (((*(uint *)(iVar10 + 0x18) < uVar3) || (uVar4 <= uVar7)) ||
             (iVar9 = _vm_page_lookup(param_1,uVar7), iVar9 != 0)) {
            _vm_page_free(iVar10);
          }
          else {
            _vm_page_rename(iVar10,param_1,uVar7);
          }
        }
        *(int *)(param_1 + 0x24) = piVar2[9];
        *(uint *)(param_1 + 0x28) = piVar2[10] + uVar3;
        piVar2[9] = 0;
        piVar2[0xb] = 0;
        piVar2[0xc] = 0;
        *(int *)(param_1 + 0x1c) = piVar2[7];
        *(int *)(param_1 + 0x20) = piVar2[8] + *(int *)(param_1 + 0x20);
        if ((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(*(int *)(param_1 + 0x1c) + 0x18) != 0)) {
                    /* WARNING: Subroutine does not return */
          _panic(aVmObjectCollap);
        }
        puVar5 = (undefined4 *)piVar2[2];
        puVar6 = (undefined4 *)piVar2[3];
        puVar8 = puVar6;
        if ((undefined4 **)puVar5 != &_vm_object_list) {
          puVar5[3] = puVar6;
          puVar8 = dword_40C31B0;
        }
        dword_40C31B0 = puVar8;
        if ((undefined4 **)puVar6 != &_vm_object_list) {
          puVar6[2] = puVar5;
          puVar5 = _vm_object_list;
        }
        _vm_object_list = puVar5;
        _vm_object_count = _vm_object_count + -1;
        _zfree(_vm_object_zone,piVar2);
        _object_collapses = _object_collapses + 1;
      }
      else {
        if (piVar2[9] != 0) {
          return;
        }
        for (piVar1 = (int *)*piVar2; piVar1 != piVar2; piVar1 = (int *)piVar1[2]) {
          uVar7 = piVar1[6] - uVar3;
          if (((uVar3 <= (uint)piVar1[6]) && (uVar7 <= uVar4)) &&
             (iVar10 = _vm_page_lookup(param_1,uVar7), iVar10 == 0)) {
            return;
          }
        }
        iVar10 = piVar2[7];
        *(int *)(param_1 + 0x1c) = iVar10;
        _vm_object_reference(iVar10);
        *(int *)(param_1 + 0x20) = piVar2[8] + *(int *)(param_1 + 0x20);
        *(sword *)(piVar2 + 5) = *(sword *)(piVar2 + 5) + -1;
        _object_bypasses = _object_bypasses + 1;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1809 start=0x4060340 */

void _vm_object_page_remove(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_1;
    while (puVar2 = puVar1, puVar2 != param_1) {
      puVar1 = (undefined4 *)puVar2[2];
      if ((param_2 <= (uint)puVar2[6]) && ((uint)puVar2[6] < param_3)) {
        _pmap_remove_all(*(undefined4 *)((int)puVar2 + 0x22));
        _vm_page_free(puVar2);
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1810 start=0x4060392 */

undefined4
_vm_object_coalesce(int param_1,int param_2,int param_3,undefined4 param_4,int param_5,int param_6)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (param_2 == 0) {
    if (param_1 != 0) {
      _vm_object_collapse(param_1);
      if ((((1 < *(sword *)(param_1 + 0x14)) || (*(int *)(param_1 + 0x24) != 0)) ||
          (*(int *)(param_1 + 0x1c) != 0)) || (*(int *)(param_1 + 0x18) != 0)) goto loc_40603CC;
      uVar1 = param_6 + param_5 + param_3;
      _vm_object_page_remove(param_1,param_5 + param_3,uVar1);
      if (*(uint *)(param_1 + 0x10) < uVar1) {
        *(uint *)(param_1 + 0x10) = uVar1;
      }
    }
    uVar2 = 1;
  }
  else {
loc_40603CC:
    uVar2 = 0;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1811 start=0x4060402 */

undefined4 _vm_object_request_object(void)

{
  _printf(aVmObjectReques);
  return 0;
}
/* GHIDRADEC_FUNCTION index=1812 start=0x4060418 */

undefined4 _vm_object_name(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=1813 start=0x4060422 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _vm_pageout_scan(void)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  
  iVar3 = _vm_page_free_count;
  iVar9 = _vm_page_free_min;
  uVar6 = 0;
  if (_vm_page_free_count <= _vm_page_free_min) {
    _pmap_update();
    puVar7 = _vm_page_queue_inactive;
    do {
      if (((undefined4 **)puVar7 == &_vm_page_queue_inactive) ||
         (_vm_page_free_target <= _vm_page_free_count)) break;
      iVar4 = _pmap_is_referenced(*(undefined4 *)((int)puVar7 + 0x22));
      if (iVar4 == 0) {
        if ((*(byte *)((int)puVar7 + 0x1e) & 4) == 0) {
          if ((*(byte *)((int)puVar7 + 0x1e) & 0x20) == 0) {
            puVar8 = (undefined4 *)*puVar7;
          }
          else {
            iVar4 = puVar7[5];
            *(byte *)(puVar7 + 8) = *(byte *)(puVar7 + 8) | 0x80;
            dword_40C2400 = dword_40C2400 + 1;
            uVar6 = 1;
            _pmap_remove_all(*(undefined4 *)((int)puVar7 + 0x22));
            _vm_object_collapse(iVar4);
            *(sword *)(iVar4 + 0x40) = *(sword *)(iVar4 + 0x40) + 1;
            _thread_wakeup_prim(&_vm_page_free_count,0,0);
            iVar5 = *(int *)(iVar4 + 0x24);
            if ((iVar5 == 0) &&
               (iVar5 = _vm_pager_allocate(*(undefined4 *)(iVar4 + 0x10)), iVar5 != 0)) {
              _vm_object_setpager(iVar4,iVar5,0,0);
            }
            if ((_byte_40B60C0 & 0x1000000) != 0) {
              _pmonlogcontextflush(0x11,0x1000000);
            }
            if ((_byte_40B60C0 & 0x4000002) != 0) {
              _pmonlogevent(0x11,0x4000002,*(uint *)((int)puVar7 + 0x22) >> (_page_shift & 0x3f),
                            CONCAT22((sword)_vm_page_inactive_count,_vm_page_free_count._2_2_),
                            _active_threads);
            }
            bVar2 = false;
            if ((iVar5 != 0) && (iVar5 = _vm_pager_put(iVar5,puVar7), iVar5 == 0)) {
              bVar2 = true;
            }
            puVar8 = (undefined4 *)*puVar7;
            if (bVar2) {
              *(byte *)((int)puVar7 + 0x1e) = *(byte *)((int)puVar7 + 0x1e) & 0xdf;
            }
            else {
              _vm_page_activate(puVar7);
            }
            _pmap_clear_reference(*(undefined4 *)((int)puVar7 + 0x22));
            bVar1 = *(byte *)(puVar7 + 8);
            *(byte *)(puVar7 + 8) = bVar1 & 0x7f;
            *(byte *)(puVar7 + 8) = bVar1 & 0x7f;
            if ((bVar1 & 0x40) != 0) {
              *(byte *)(puVar7 + 8) = bVar1 & 0x3f;
              _thread_wakeup_prim(puVar7,0,0);
            }
            *(sword *)(iVar4 + 0x40) = *(sword *)(iVar4 + 0x40) + -1;
            _thread_wakeup_prim(iVar4,0,0);
          }
        }
        else {
          uVar6 = 1;
          *(byte *)(puVar7 + 8) = *(byte *)(puVar7 + 8) | 0x80;
          if ((_byte_40B60C0 & 0x1000000) != 0) {
            _pmonlogcontextflush(0x11,0x1000000);
          }
          if ((_byte_40B60C0 & 0x4000001) != 0) {
            _pmonlogevent(0x11,0x4000001,*(uint *)((int)puVar7 + 0x22) >> (_page_shift & 0x3f),
                          CONCAT22((sword)_vm_page_inactive_count,_vm_page_free_count._2_2_),
                          _active_threads);
          }
          _pmap_remove_all(*(undefined4 *)((int)puVar7 + 0x22));
          bVar1 = *(byte *)(puVar7 + 8);
          *(byte *)(puVar7 + 8) = bVar1 & 0x7f;
          *(byte *)(puVar7 + 8) = bVar1 & 0x7f;
          if ((bVar1 & 0x40) != 0) {
            *(byte *)(puVar7 + 8) = bVar1 & 0x3f;
            _thread_wakeup_prim(puVar7,0,0);
          }
          puVar8 = (undefined4 *)*puVar7;
          _vm_page_addfree(puVar7);
        }
      }
      else {
        puVar8 = (undefined4 *)*puVar7;
        _vm_page_activate(puVar7);
        dword_40C23F8 = dword_40C23F8 + 1;
      }
      puVar7 = puVar8;
    } while (iVar3 <= iVar9);
  }
  iVar9 = (_vm_page_inactive_target - _vm_page_inactive_count) - _vm_page_free_count;
  while ((0 < iVar9 && ((undefined4 **)_vm_page_queue_active != &_vm_page_queue_active))) {
    uVar6 = 1;
    _vm_page_deactivate(_vm_page_queue_active);
    iVar9 = iVar9 + -1;
  }
  return uVar6;
}
/* GHIDRADEC_FUNCTION index=1814 start=0x406070e */

void _vm_pageout(void)

{
  int iVar1;
  
  iVar1 = 1;
  *(undefined4 *)(_active_threads + 0x74) = 1;
  if (_vm_page_free_min == 0) {
    _vm_page_free_min = _vm_page_free_count / 0x32;
    if ((int)_vm_page_free_min < 3) {
      _vm_page_free_min = 3;
    }
    if (_vm_page_free_min_sanity < _page_size * _vm_page_free_min) {
      _vm_page_free_min = _vm_page_free_min_sanity / _page_size;
    }
  }
  if (_vm_page_free_reserved == 0) {
    _vm_page_free_reserved = 3;
  }
  if (_vm_pageout_free_min == 0) {
    _vm_pageout_free_min = _vm_page_free_reserved;
    if (_vm_page_free_reserved < 0) {
      _vm_pageout_free_min = _vm_page_free_reserved + 1;
    }
    _vm_pageout_free_min = _vm_pageout_free_min >> 1;
    if (10 < _vm_pageout_free_min) {
      _vm_pageout_free_min = 10;
    }
  }
  if (_vm_page_free_target == 0) {
    _vm_page_free_target = _vm_page_free_min << 2;
  }
  if (_vm_page_inactive_target == 0) {
    _vm_page_inactive_target = _vm_page_free_count / 3;
  }
  if (_vm_page_free_target <= (int)_vm_page_free_min) {
    _vm_page_free_target = _vm_page_free_min + 1;
  }
  if (_vm_page_inactive_target <= _vm_page_free_target) {
    _vm_page_inactive_target = _vm_page_free_target + 1;
  }
  do {
    if ((iVar1 == 0) ||
       (((int)_vm_page_free_min < _vm_page_free_count &&
        ((_vm_page_free_target <= _vm_page_free_count ||
         (_vm_page_inactive_target < _vm_page_inactive_count)))))) {
      _thread_sleep(&_vm_pages_needed,&_vm_pages_needed_lock,0);
    }
    iVar1 = _vm_pageout_scan();
    _thread_wakeup_prim(&_vm_page_free_count,0,0);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1815 start=0x406087c */

void _vm_pager_init(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1816 start=0x4060884 */

undefined4 _vm_pager_get(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    _vm_page_zero_fill(param_2);
    uVar1 = 0;
  }
  else {
    if (*param_1 != 0) {
                    /* WARNING: Subroutine does not return */
      _device_pagein(param_2);
    }
    uVar1 = _vnode_pagein(param_2,param_3);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1817 start=0x40608be */

void _vm_pager_put(int *param_1,undefined4 param_2)

{
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVmPagerPutNull);
  }
  if (*param_1 == 0) {
    _vnode_pageout(param_2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  _device_pageout(param_2);
}
/* GHIDRADEC_FUNCTION index=1818 start=0x4060902 */

void _vm_pager_deallocate(int *param_1)

{
  if (param_1 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVmPagerDealloc);
  }
  if (*param_1 == 0) {
    _vnode_dealloc(param_1);
  }
  else {
    _device_dealloc(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1819 start=0x406093c */

void _vm_pager_allocate(undefined4 param_1)

{
  _vnode_alloc(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1820 start=0x406094e */

void _vm_pager_has_page(int *param_1,undefined4 param_2)

{
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    _vnode_has_page(param_1,param_2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aVmPagerHasPage);
}
/* GHIDRADEC_FUNCTION index=1821 start=0x4060a50 */

void _vm_policy_apply(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  if (((2 < *(sword *)(param_1 + 0x14)) &&
      (piVar1 = *(int **)(param_1 + 0x24), piVar1 != (int *)0x0)) && (*piVar1 == 0)) {
    uVar2 = (uint)piVar1[3] >> 0x1f ^ 1;
  }
  if (((param_3 & 2) != 0) || (uVar2 == 0)) {
    if (param_3 == 0) {
      if (((*(byte *)(param_2 + 0x1e) & 4) == 0) ||
         (iVar3 = _pmap_is_modified(*(undefined4 *)(param_2 + 0x22)), iVar3 != 0)) {
        if ((*(byte *)(param_2 + 0x1e) & 0x40) != 0) {
          _vm_page_deactivate(param_2);
        }
      }
      else {
        sub_4060982(param_2);
      }
      _pmap_remove_all(*(undefined4 *)(param_2 + 0x22));
    }
    else if ((param_3 == 1) && ((*(byte *)(param_2 + 0x1e) & 0x40) != 0)) {
      _vm_page_deactivate(param_2);
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1822 start=0x4060cbc */

undefined4 _vm_set_policy(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 5;
  }
  else {
    if (param_3 == 0) {
      param_3 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10);
    }
    if (param_2 == 0) {
      param_2 = *(int *)(param_1 + 0x10);
    }
    sub_4060C18(param_1,param_2,param_3 + param_2,param_4);
    uVar1 = 0;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1823 start=0x4060d06 */

undefined4 _vm_fault_range(void)

{
  return 4;
}
/* GHIDRADEC_FUNCTION index=1824 start=0x4060d10 */

undefined4 _vm_deactivate(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 5;
  }
  else {
    if (param_3 == 0) {
      param_3 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10);
    }
    if (param_2 == 0) {
      param_2 = *(int *)(param_1 + 0x10);
    }
    sub_4060B78(param_1,param_2,param_3,param_4);
    uVar1 = 0;
  }
  return uVar1;
}

