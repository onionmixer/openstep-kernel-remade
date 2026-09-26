/* GHIDRADEC_FUNCTION index=1800 start=0x405fde8 */

void _vm_object_pmap_copy(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (puVar1 = (undefined4 *)*param_1; puVar1 != param_1; puVar1 = (undefined4 *)puVar1[2]) {
      if (((param_2 <= (uint)puVar1[6]) && ((uint)puVar1[6] < param_3)) &&
         ((*(byte *)((int)puVar1 + 0x21) & 0x20) == 0)) {
        _pmap_copy_on_write(*(undefined4 *)((int)puVar1 + 0x22));
        *(byte *)((int)puVar1 + 0x21) = *(byte *)((int)puVar1 + 0x21) | 0x20;
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1801 start=0x405fe3e */

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
/* GHIDRADEC_FUNCTION index=1802 start=0x405fe86 */

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
/* GHIDRADEC_FUNCTION index=1803 start=0x405ffa4 */

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
/* GHIDRADEC_FUNCTION index=1804 start=0x405ffea */

void _vm_object_setpager(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  *(undefined4 *)(param_1 + 0x28) = param_3;
  return;
}
/* GHIDRADEC_FUNCTION index=1805 start=0x4060002 */

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
/* GHIDRADEC_FUNCTION index=1806 start=0x4060080 */

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
/* GHIDRADEC_FUNCTION index=1807 start=0x40600e2 */

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
/* GHIDRADEC_FUNCTION index=1808 start=0x406014c */

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
/* GHIDRADEC_FUNCTION index=1809 start=0x406019c */

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
/* GHIDRADEC_FUNCTION index=1810 start=0x4060340 */

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
/* GHIDRADEC_FUNCTION index=1811 start=0x4060392 */

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
/* GHIDRADEC_FUNCTION index=1812 start=0x4060402 */

undefined4 _vm_object_request_object(void)

{
  _printf(aVmObjectReques);
  return 0;
}
/* GHIDRADEC_FUNCTION index=1813 start=0x4060418 */

undefined4 _vm_object_name(void)

{
  return 0;
}
/* GHIDRADEC_FUNCTION index=1814 start=0x4060422 */

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
/* GHIDRADEC_FUNCTION index=1815 start=0x406070e */

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
/* GHIDRADEC_FUNCTION index=1816 start=0x406087c */

void _vm_pager_init(void)

{
  return;
}
/* GHIDRADEC_FUNCTION index=1817 start=0x4060884 */

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
/* GHIDRADEC_FUNCTION index=1818 start=0x40608be */

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
/* GHIDRADEC_FUNCTION index=1819 start=0x4060902 */

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
/* GHIDRADEC_FUNCTION index=1820 start=0x406093c */

void _vm_pager_allocate(undefined4 param_1)

{
  _vnode_alloc(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1821 start=0x406094e */

void _vm_pager_has_page(int *param_1,undefined4 param_2)

{
  if ((param_1 != (int *)0x0) && (*param_1 == 0)) {
    _vnode_has_page(param_1,param_2);
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aVmPagerHasPage);
}
/* GHIDRADEC_FUNCTION index=1822 start=0x4060a50 */

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
/* GHIDRADEC_FUNCTION index=1823 start=0x4060cbc */

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
/* GHIDRADEC_FUNCTION index=1824 start=0x4060d06 */

undefined4 _vm_fault_range(void)

{
  return 4;
}
/* GHIDRADEC_FUNCTION index=1825 start=0x4060d10 */

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
/* GHIDRADEC_FUNCTION index=1826 start=0x4060d52 */

void _vm_set_page_size(void)

{
  int iVar1;
  uint uVar2;
  
  _page_mask = _page_size - 1;
  if ((_page_size & _page_mask) == 0) {
    _page_shift = 0;
    if (_page_size != 1) {
      do {
        iVar1 = _page_shift + 1;
        uVar2 = _page_shift + 1;
        _page_shift = iVar1;
      } while (_page_size != 1 << (uVar2 & 0x3f));
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(aVmSetPageSizeP);
}
/* GHIDRADEC_FUNCTION index=1827 start=0x4060dba */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _vm_page_startup(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint *puVar8;
  byte *pbVar9;
  int *piVar10;
  uint *puStack_8;
  
  dword_40C32A4 = 0;
  dword_40C32A8 = 0;
  dword_40C32AC._0_2_ = 0;
  dword_40C32B0._0_1_ = 0x80;
  dword_40C32B0._1_1_ = dword_40C32B0._1_1_ & 0x47;
  dword_40C32AC._2_1_ = dword_40C32AC._2_1_ & 7 | 4;
  ram0x040c32b2 = 0;
  uRam040c32b6 = 0;
  uRam040c32ba = 0;
  dword_40C2C1C = &_vm_page_queue_free;
  _vm_page_queue_free = &_vm_page_queue_free;
  dword_40C2C14 = &_vm_page_queue_active;
  _vm_page_queue_active = &_vm_page_queue_active;
  dword_40C23DC = &_vm_page_queue_inactive;
  _vm_page_queue_inactive = &_vm_page_queue_inactive;
  uVar5 = 0;
  if (param_1 < param_1 + param_2 * 7) {
    puVar6 = param_1;
    do {
      uVar5 = ((~_page_mask & puVar6[6]) - (~_page_mask & _page_mask + puVar6[5])) + uVar5;
      puVar6 = puVar6 + 7;
    } while (puVar6 < param_1 + param_2 * 7);
  }
  if (_vm_page_bucket_count == 0) {
    _vm_page_bucket_count = 1;
    uVar5 = uVar5 >> (_page_shift & 0x3f);
    if (1 < uVar5) {
      do {
        _vm_page_bucket_count = _vm_page_bucket_count * 2;
      } while (_vm_page_bucket_count < uVar5);
    }
  }
  _vm_page_hash_mask = _vm_page_bucket_count - 1;
  if ((_vm_page_bucket_count & _vm_page_hash_mask) != 0) {
    _printf(aVmPageBootstra);
  }
  _vm_page_buckets = (undefined4 *)_vm_alloc_from_regions(_vm_page_bucket_count << 2,2);
  _bzero(_vm_page_buckets,_vm_page_bucket_count << 2);
  uVar2 = _vm_page_bucket_count;
  uVar5 = 0;
  puVar6 = _vm_page_buckets;
  if (_vm_page_bucket_count != 0) {
    do {
      *puVar6 = 0;
      uVar5 = uVar5 + 1;
      puVar6 = puVar6 + 1;
    } while (uVar5 < uVar2);
  }
  _zdata_size = _page_size << 3;
  _zdata = _vm_alloc_from_regions(_zdata_size,_page_size);
  _bzero(_zdata,_zdata_size);
  _map_data_size = 0x2a8;
  _map_data = _vm_alloc_from_regions(0x2a8,2);
  _bzero(_map_data,_map_data_size);
  _kentry_data_size = 0x15000;
  _kentry_data = _vm_alloc_from_regions(0x15000,2);
  _bzero(_kentry_data,_kentry_data_size);
  if (param_1 < param_1 + param_2 * 7) {
    piVar10 = param_1 + 5;
    puVar8 = param_1 + 6;
    puVar6 = param_1;
    do {
      uVar1 = _vm_alloc_from_regions
                        (((~_page_mask & *puVar8) - (~_page_mask & *piVar10 + _page_mask) >>
                         (_page_shift & 0x3f)) * 0x2e,2);
      *puVar6 = uVar1;
      _bzero(uVar1,((~_page_mask & *puVar8) - (~_page_mask & *piVar10 + _page_mask) >>
                   (_page_shift & 0x3f)) * 0x2e);
      piVar10 = piVar10 + 7;
      puVar8 = puVar8 + 7;
      puVar6 = puVar6 + 7;
    } while (puVar6 < param_1 + param_2 * 7);
  }
  _vm_page_free_count = 0;
  if (param_1 < param_1 + param_2 * 7) {
    puStack_8 = param_1 + 3;
    puVar8 = param_1 + 5;
    puVar4 = param_1 + 1;
    puVar3 = param_1 + 6;
    puVar6 = param_1;
    do {
      uVar5 = ~_page_mask;
      *puVar8 = uVar5 & _page_mask + *puVar8;
      *puVar3 = uVar5 & *puVar3;
      uVar5 = _page_shift;
      *puVar4 = *puVar8 >> (_page_shift & 0x3f);
      uVar5 = *puVar3 >> (uVar5 & 0x3f);
      puVar6[2] = uVar5;
      uVar5 = uVar5 - *puVar4;
      *puStack_8 = uVar5;
      _vm_page_free_count = uVar5 + _vm_page_free_count;
      puVar7 = (undefined4 *)*puVar6;
      uVar5 = *puVar8;
      uVar2 = 0;
      if (*puStack_8 != 0) {
        pbVar9 = (byte *)((int)puVar7 + 0x1e);
        do {
          *(uint *)((int)puVar7 + 0x22) = uVar5;
          *dword_40C2C1C = puVar7;
          puVar7[1] = dword_40C2C1C;
          *puVar7 = &_vm_page_queue_free;
          dword_40C2C1C = puVar7;
          *pbVar9 = *pbVar9 | 0x10;
          pbVar9 = pbVar9 + 0x2e;
          puVar7 = (undefined4 *)((int)puVar7 + 0x2e);
          uVar5 = _page_size + uVar5;
          uVar2 = uVar2 + 1;
        } while (uVar2 < *puStack_8);
      }
      puStack_8 = puStack_8 + 7;
      puVar8 = puVar8 + 7;
      puVar4 = puVar4 + 7;
      puVar3 = puVar3 + 7;
      puVar6 = puVar6 + 7;
    } while (puVar6 < param_1 + param_2 * 7);
  }
  return param_3;
}
/* GHIDRADEC_FUNCTION index=1828 start=0x406114c */

byte _vm_page_insert(int param_1,int *param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  
  if ((*(byte *)(param_1 + 0x20) & 0x20) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aVmPageInsert);
  }
  *(int **)(param_1 + 0x14) = param_2;
  *(uint *)(param_1 + 0x18) = param_3;
  param_3 = param_3 >> (_page_shift & 0x3f);
  uVar2 = _vm_page_hash_mask & (int)param_2 + param_3;
  piVar1 = (int *)(_vm_page_buckets + uVar2 * 4);
  *(int *)(param_1 + 0x10) = *piVar1;
  *piVar1 = param_1;
  piVar1 = (int *)param_2[1];
  if (piVar1 == param_2) {
    *param_2 = param_1;
  }
  else {
    piVar1[2] = param_1;
  }
  *(int **)(param_1 + 0xc) = piVar1;
  *(int **)(param_1 + 8) = param_2;
  param_2[1] = param_1;
  *(byte *)(param_1 + 0x20) = *(byte *)(param_1 + 0x20) | 0x20;
  *(sword *)((int)param_2 + 0x16) = *(sword *)((int)param_2 + 0x16) + 1;
  return CARRY4((uint)param_2,param_3) << 4 | ((int)uVar2 < 0) << 3 | (uVar2 == 0) << 2;
}
/* GHIDRADEC_FUNCTION index=1829 start=0x40611da */

void _vm_page_remove(int param_1)

{
  int *piVar1;
  sword *psVar2;
  int iVar3;
  
  if ((*(byte *)(param_1 + 0x20) & 0x20) != 0) {
    piVar1 = (int *)(_vm_page_buckets +
                    (_vm_page_hash_mask &
                    *(int *)(param_1 + 0x14) + (*(uint *)(param_1 + 0x18) >> (_page_shift & 0x3f)))
                    * 4);
    iVar3 = *piVar1;
    if (param_1 == iVar3) {
      *piVar1 = *(int *)(param_1 + 0x10);
    }
    else {
      do {
        piVar1 = (int *)(iVar3 + 0x10);
        iVar3 = *piVar1;
      } while (param_1 != iVar3);
      *piVar1 = *(int *)(iVar3 + 0x10);
    }
    iVar3 = *(int *)(param_1 + 8);
    piVar1 = *(int **)(param_1 + 0xc);
    if (iVar3 == *(int *)(param_1 + 0x14)) {
      *(int **)(iVar3 + 4) = piVar1;
    }
    else {
      *(int **)(iVar3 + 0xc) = piVar1;
    }
    if (piVar1 == *(int **)(param_1 + 0x14)) {
      *piVar1 = iVar3;
    }
    else {
      piVar1[2] = iVar3;
    }
    psVar2 = (sword *)(*(int *)(param_1 + 0x14) + 0x16);
    *psVar2 = *psVar2 + -1;
    *(byte *)(param_1 + 0x20) = *(byte *)(param_1 + 0x20) & 0xdf;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1830 start=0x4061276 */

int _vm_page_lookup(int param_1,uint param_2)

{
  int iVar1;
  
  for (iVar1 = *(int *)(_vm_page_buckets +
                       (_vm_page_hash_mask & param_1 + (param_2 >> (_page_shift & 0x3f))) * 4);
      (iVar1 != 0 && ((param_1 != *(int *)(iVar1 + 0x14) || (param_2 != *(uint *)(iVar1 + 0x18)))));
      iVar1 = *(int *)(iVar1 + 0x10)) {
  }
  return iVar1;
}
/* GHIDRADEC_FUNCTION index=1831 start=0x40612d8 */

void _vm_page_rename(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _vm_page_remove(param_1);
  _vm_page_insert(param_1,param_2,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=1832 start=0x406130a */

void _vm_page_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = _vm_page_template;
  param_1[1] = dword_40C3294;
  param_1[2] = dword_40C3298;
  param_1[3] = dword_40C329C;
  param_1[4] = dword_40C32A0;
  param_1[5] = dword_40C32A4;
  param_1[6] = dword_40C32A8;
  param_1[7] = dword_40C32AC;
  param_1[8] = dword_40C32B0;
  param_1[9] = dword_40C32B4;
  param_1[10] = dword_40C32B8;
  *(undefined2 *)(param_1 + 0xb) = word_40C32BC;
  *(undefined4 *)((int)param_1 + 0x22) = param_4;
  _vm_page_insert(param_1,param_2,param_3);
  return;
}
/* GHIDRADEC_FUNCTION index=1833 start=0x4061376 */

undefined4 * _vm_page_alloc_sequential(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  byte *pbVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  
  puVar4 = _vm_page_queue_free;
  if ((undefined4 **)_vm_page_queue_free == &_vm_page_queue_free) {
    puVar4 = (undefined4 *)0x0;
  }
  else if ((_vm_page_free_count < _vm_page_free_reserved) && (*(int *)(_active_threads + 0x74) == 0)
          ) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)*_vm_page_queue_free;
    if ((undefined4 **)puVar1 == &_vm_page_queue_free) {
      dword_40C2C1C = &_vm_page_queue_free;
    }
    else {
      puVar1[1] = &_vm_page_queue_free;
    }
    pbVar2 = (byte *)((int)_vm_page_queue_free + 0x1e);
    _vm_page_queue_free = puVar1;
    *pbVar2 = *pbVar2 & 0xef;
    _vm_page_free_count = _vm_page_free_count + -1;
    _vm_page_remove(puVar4);
    *puVar4 = _vm_page_template;
    puVar4[1] = dword_40C3294;
    puVar4[2] = dword_40C3298;
    puVar4[3] = dword_40C329C;
    puVar4[4] = dword_40C32A0;
    puVar4[5] = dword_40C32A4;
    puVar4[6] = dword_40C32A8;
    puVar4[7] = dword_40C32AC;
    puVar4[8] = dword_40C32B0;
    puVar4[9] = dword_40C32B4;
    puVar4[10] = dword_40C32B8;
    *(undefined2 *)(puVar4 + 0xb) = word_40C32BC;
    *(undefined4 *)((int)puVar4 + 0x22) = *(undefined4 *)((int)puVar4 + 0x22);
    _vm_page_insert(puVar4,param_1,param_2);
    if ((_vm_page_free_count < _vm_page_free_min) ||
       ((_vm_page_free_count < _vm_page_free_target &&
        (_vm_page_inactive_count < _vm_page_inactive_target)))) {
      _thread_wakeup_prim(&_vm_pages_needed,0,0);
    }
    if (((*(uint *)(param_1 + 0x45) & 0x3fffffff) >> 0x1c != 0) && (param_3 != 0)) {
      iVar5 = param_2 - *(int *)(param_1 + 0x4e);
      if (iVar5 < 0) {
        iVar5 = -iVar5;
      }
      if (iVar5 == _page_size) {
        iVar5 = _vm_page_lookup(param_1,*(int *)(param_1 + 0x4e));
        if (iVar5 != 0) {
          uVar3 = *(uint *)(param_1 + 0x44) >> 0x14 | (*(byte *)(param_1 + 0x43) & 0xf) << 0xc;
          uVar6 = 0;
          if ((uVar3 != 1) && (uVar3 == 2)) {
            uVar6 = 1;
          }
          _vm_policy_apply(param_1,iVar5,uVar6);
        }
      }
    }
    *(int *)(param_1 + 0x4e) = param_2;
  }
  return puVar4;
}
/* GHIDRADEC_FUNCTION index=1834 start=0x4061510 */

void _vm_page_free(int param_1)

{
  _vm_page_remove(param_1);
  if ((*(byte *)(param_1 + 0x1e) & 0x10) == 0) {
    _vm_page_addfree(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1835 start=0x406153c */

void _vm_page_addfree(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if ((*(byte *)((int)param_1 + 0x1e) & 0x40) != 0) {
    puVar1 = (undefined4 *)*param_1;
    puVar2 = (undefined4 *)param_1[1];
    puVar3 = puVar2;
    if (puVar1 != &_vm_page_queue_active) {
      puVar1[1] = puVar2;
      puVar3 = dword_40C2C14;
    }
    dword_40C2C14 = puVar3;
    *puVar2 = puVar1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0xbf;
    _vm_page_active_count = _vm_page_active_count + -1;
  }
  if (*(char *)((int)param_1 + 0x1e) < '\0') {
    puVar1 = (undefined4 *)*param_1;
    puVar2 = (undefined4 *)param_1[1];
    puVar3 = puVar2;
    if (puVar1 != &_vm_page_queue_inactive) {
      puVar1[1] = puVar2;
      puVar3 = dword_40C23DC;
    }
    dword_40C23DC = puVar3;
    *puVar2 = puVar1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0x7f;
    _vm_page_inactive_count = _vm_page_inactive_count + -1;
  }
  if ((*(byte *)(param_1 + 8) & 0x10) == 0) {
    *dword_40C2C1C = param_1;
    param_1[1] = dword_40C2C1C;
    *param_1 = &_vm_page_queue_free;
    dword_40C2C1C = param_1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) | 0x10;
    _vm_page_free_count = _vm_page_free_count + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1836 start=0x40615e8 */

void _vm_page_wire(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(sword *)(param_1 + 7) == 0) {
    if ((*(byte *)((int)param_1 + 0x1e) & 0x40) != 0) {
      puVar1 = (undefined4 *)*param_1;
      puVar2 = (undefined4 *)param_1[1];
      puVar3 = puVar2;
      if (puVar1 != &_vm_page_queue_active) {
        puVar1[1] = puVar2;
        puVar3 = dword_40C2C14;
      }
      dword_40C2C14 = puVar3;
      *puVar2 = puVar1;
      _vm_page_active_count = _vm_page_active_count + -1;
      *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0xbf;
    }
    if (*(char *)((int)param_1 + 0x1e) < '\0') {
      puVar1 = (undefined4 *)*param_1;
      puVar2 = (undefined4 *)param_1[1];
      puVar3 = puVar2;
      if (puVar1 != &_vm_page_queue_inactive) {
        puVar1[1] = puVar2;
        puVar3 = dword_40C23DC;
      }
      dword_40C23DC = puVar3;
      *puVar2 = puVar1;
      _vm_page_inactive_count = _vm_page_inactive_count + -1;
      *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0x7f;
    }
    if ((*(byte *)((int)param_1 + 0x1e) & 0x10) != 0) {
      puVar1 = (undefined4 *)*param_1;
      puVar2 = (undefined4 *)param_1[1];
      puVar3 = puVar2;
      if (puVar1 != &_vm_page_queue_free) {
        puVar1[1] = puVar2;
        puVar3 = dword_40C2C1C;
      }
      dword_40C2C1C = puVar3;
      *puVar2 = puVar1;
      _vm_page_free_count = _vm_page_free_count + -1;
      *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0xef;
    }
    _vm_page_wire_count = _vm_page_wire_count + 1;
  }
  *(sword *)(param_1 + 7) = *(sword *)(param_1 + 7) + 1;
  return;
}
/* GHIDRADEC_FUNCTION index=1837 start=0x406169a */

void _vm_page_unwire(undefined4 *param_1)

{
  sword sVar1;
  
  sVar1 = *(sword *)(param_1 + 7);
  *(sword *)(param_1 + 7) = sVar1 + -1;
  if (sVar1 == 1) {
    *dword_40C2C14 = param_1;
    param_1[1] = dword_40C2C14;
    *param_1 = &_vm_page_queue_active;
    dword_40C2C14 = param_1;
    _vm_page_active_count = _vm_page_active_count + 1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) | 0x40;
    _vm_page_wire_count = _vm_page_wire_count + -1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1838 start=0x40616ea */

void _vm_page_deactivate(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  
  if ((*(byte *)((int)param_1 + 0x1e) & 0x40) != 0) {
    _pmap_clear_reference(*(undefined4 *)((int)param_1 + 0x22));
    puVar1 = (undefined4 *)*param_1;
    puVar2 = (undefined4 *)param_1[1];
    puVar3 = puVar2;
    if (puVar1 != &_vm_page_queue_active) {
      puVar1[1] = puVar2;
      puVar3 = dword_40C2C14;
    }
    dword_40C2C14 = puVar3;
    *puVar2 = puVar1;
    *dword_40C23DC = param_1;
    param_1[1] = dword_40C23DC;
    *param_1 = &_vm_page_queue_inactive;
    dword_40C23DC = param_1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0xbf | 0x80;
    _vm_page_active_count = _vm_page_active_count + -1;
    _vm_page_inactive_count = _vm_page_inactive_count + 1;
    if (((*(byte *)((int)param_1 + 0x1e) & 4) != 0) &&
       (iVar4 = _pmap_is_modified(*(undefined4 *)((int)param_1 + 0x22)), iVar4 != 0)) {
      *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0xfb;
    }
    *(byte *)((int)param_1 + 0x1e) =
         *(byte *)((int)param_1 + 0x1e) & 0xdf |
         (byte)((((word)(*(byte *)((int)param_1 + 0x1e) ^ 4) & 7) >> 2) << 5);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1839 start=0x4061796 */

void _vm_page_activate(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(char *)((int)param_1 + 0x1e) < '\0') {
    puVar1 = (undefined4 *)*param_1;
    puVar2 = (undefined4 *)param_1[1];
    puVar3 = puVar2;
    if (puVar1 != &_vm_page_queue_inactive) {
      puVar1[1] = puVar2;
      puVar3 = dword_40C23DC;
    }
    dword_40C23DC = puVar3;
    *puVar2 = puVar1;
    _vm_page_inactive_count = _vm_page_inactive_count + -1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0x7f;
  }
  if ((*(byte *)((int)param_1 + 0x1e) & 0x10) != 0) {
    puVar1 = (undefined4 *)*param_1;
    puVar2 = (undefined4 *)param_1[1];
    puVar3 = puVar2;
    if (puVar1 != &_vm_page_queue_free) {
      puVar1[1] = puVar2;
      puVar3 = dword_40C2C1C;
    }
    dword_40C2C1C = puVar3;
    *puVar2 = puVar1;
    _vm_page_free_count = _vm_page_free_count + -1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) & 0xef;
  }
  if (*(sword *)(param_1 + 7) == 0) {
    if ((*(byte *)((int)param_1 + 0x1e) & 0x40) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(aVmPageActivate);
    }
    *dword_40C2C14 = param_1;
    param_1[1] = dword_40C2C14;
    *param_1 = &_vm_page_queue_active;
    dword_40C2C14 = param_1;
    *(byte *)((int)param_1 + 0x1e) = *(byte *)((int)param_1 + 0x1e) | 0x40;
    _vm_page_active_count = _vm_page_active_count + 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1840 start=0x4061846 */

undefined4 _vm_page_zero_fill(int param_1)

{
  _pmap_zero_page(*(undefined4 *)(param_1 + 0x22));
  return 1;
}
/* GHIDRADEC_FUNCTION index=1841 start=0x406185e */

void _vm_page_copy(int param_1,int param_2)

{
  _pmap_copy_page(*(undefined4 *)(param_1 + 0x22),*(undefined4 *)(param_2 + 0x22));
  return;
}
/* GHIDRADEC_FUNCTION index=1842 start=0x406187c */

undefined4 _vm_page_to_phys(int param_1)

{
  return *(undefined4 *)(param_1 + 0x22);
}
/* GHIDRADEC_FUNCTION index=1843 start=0x406188c */

undefined4 _vm_synchronize(int param_1,int param_2,int param_3)

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
    uVar1 = sub_40618D0(param_1,param_2,param_3 + param_2);
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1844 start=0x4061b0e */

void _useracc(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (param_3 == 1) {
    uVar1 = 1;
  }
  _vm_map_check_protection
            (*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),~_page_mask & param_1,
             ~_page_mask & _page_mask + param_2 + param_1,uVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=1845 start=0x4061b5c */

void _vslock(uint param_1,int param_2)

{
  _vm_map_pageable(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),~_page_mask & param_1,
                   ~_page_mask & _page_mask + param_2 + param_1,0);
  return;
}
/* GHIDRADEC_FUNCTION index=1846 start=0x4061b9c */

void _vsunlock(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_3 != 0) {
    uVar1 = *(undefined4 *)(*(int *)(*(int *)(_active_threads + 0xc) + 8) + 0x20);
    uVar4 = ~_page_mask & param_1;
    if (uVar4 < (~_page_mask & param_2 + param_1 + _page_mask)) {
      do {
        uVar2 = _pmap_extract(uVar1,uVar4);
        iVar3 = _vm_phys_to_vm_page(uVar2);
        *(byte *)(iVar3 + 0x1e) = *(byte *)(iVar3 + 0x1e) & 0xfb;
        uVar4 = _page_size + uVar4;
      } while (uVar4 < (~_page_mask & _page_mask + param_2 + param_1));
    }
  }
  _vm_map_pageable(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),~_page_mask & param_1,
                   ~_page_mask & _page_mask + param_2 + param_1,1);
  return;
}
/* GHIDRADEC_FUNCTION index=1847 start=0x4061c4e */

undefined4 _subyte(undefined4 param_1,undefined param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined uStack_5;
  
  uStack_5 = param_2;
  iVar1 = _copyoutmsg(&uStack_5,param_1,1);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1848 start=0x4061c78 */

undefined4 _suibyte(undefined4 param_1,undefined param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined uStack_5;
  
  uStack_5 = param_2;
  iVar1 = _copyoutmsg(&uStack_5,param_1,1);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1849 start=0x4061ca2 */

int _fubyte(undefined4 param_1)

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

