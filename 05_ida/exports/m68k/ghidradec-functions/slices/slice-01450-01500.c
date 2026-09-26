/* GHIDRADEC_FUNCTION index=1450 start=0x404d582 */

void _vmp_get(int param_1)

{
  if (*(char *)(param_1 + 0x34) < '\0') {
    _vm_info_dequeue(param_1);
  }
  *(sword *)(param_1 + 6) = *(sword *)(param_1 + 6) + 1;
  _lock_write(param_1 + 0x18);
  return;
}
/* GHIDRADEC_FUNCTION index=1451 start=0x404d5b2 */

void _vmp_put(int param_1)

{
  sword sVar1;
  
  sVar1 = *(sword *)(param_1 + 6);
  *(sword *)(param_1 + 6) = sVar1 + -1;
  if (sVar1 == 1) {
    _vm_info_enqueue(param_1);
  }
  _lock_done(param_1 + 0x18);
  if (_mfs_files_max < _mfs_files_mapped) {
    _mfs_cache_trim();
  }
  if ((*(byte *)(param_1 + 0x34) & 0x10) != 0) {
    *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) & 0xef;
    _vmp_invalidate(param_1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1452 start=0x404d61a */

void _mfs_uncache(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (((*(byte *)(iVar1 + 0x34) & 8) != 0) && (*(sword *)(iVar1 + 4) == 0)) {
    _mfs_memfree(iVar1,0);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1453 start=0x404d640 */

void _mfs_memfree(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x34) < '\0') {
    _vm_info_dequeue(param_1);
  }
  _lock_write(param_1 + 0x18);
  if (*(sword *)(param_1 + 4) == 0) {
    *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) & 0xf7;
  }
  _mfs_map_remove(param_1,*(int *)(param_1 + 8),*(int *)(param_1 + 0xc) + *(int *)(param_1 + 8),
                  param_2);
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  iVar1 = 0;
  if (*(sword *)(param_1 + 4) == 0) {
    iVar1 = *(int *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x20) = 0;
    if (*(int *)(param_1 + 0x2c) != 0) {
      _crfree(*(int *)(param_1 + 0x2c));
      *(undefined4 *)(param_1 + 0x2c) = 0;
    }
  }
  _lock_done(param_1 + 0x18);
  if (iVar1 != 0) {
    _vm_object_deallocate(iVar1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1454 start=0x404d6e2 */

void _mfs_cache_trim(void)

{
  undefined4 uVar1;
  
  while (uVar1 = _vm_info_queue, _mfs_files_max < _mfs_files_mapped) {
    _vm_info_dequeue(_vm_info_queue);
    _mfs_memfree(uVar1,1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1455 start=0x404d71e */

void _mfs_cache_clear(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar1 = _vm_info_version;
  puVar2 = _vm_info_queue;
  while (puVar4 = puVar2, iVar3 = iVar1, (undefined4 **)puVar4 != &_vm_info_queue) {
    if (*(sword *)(puVar4 + 1) == 0) {
      _mfs_memfree(puVar4,1);
    }
    iVar1 = _vm_info_version;
    puVar2 = _vm_info_queue;
    if (_vm_info_version == iVar3) {
      iVar1 = iVar3;
      puVar2 = (undefined4 *)puVar4[9];
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1456 start=0x404d774 */

void _mfs_map_remove(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  if (param_4 != 0) {
    _vmp_push(param_1);
  }
  _lock_write(&_mfs_alloc_lock_data);
  _vm_map_remove(_mfs_map,param_2,param_3);
  if (_mfs_alloc_wanted != 0) {
    _mfs_alloc_wanted = 0;
    _thread_wakeup_prim(&_mfs_map,0,0);
  }
  _lock_done(&_mfs_alloc_lock_data);
  if (*(int *)(param_1 + 0x20) != 0) {
    _vm_object_deactivate_pages(*(int *)(param_1 + 0x20));
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1457 start=0x404d7f8 */

undefined4 _vnode_size(int param_1)

{
  undefined auStack_3e [20];
  undefined4 uStack_2a;
  
  (**(code **)(*(int *)(param_1 + 0x1c) + 0x14))
            (param_1,auStack_3e,*(undefined4 *)(_active_u + 0x1a));
  return uStack_2a;
}
/* GHIDRADEC_FUNCTION index=1458 start=0x404d828 */

int _mfs_io(int *param_1,int param_2,int param_3,byte param_4,sword *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uStack_18;
  
  iVar6 = *(int *)(param_2 + 0x12);
  if (iVar6 == 0) {
    iVar6 = 0;
  }
  else {
    iVar1 = *(int *)(param_2 + 8);
    if ((iVar1 < 0) || (iVar6 + iVar1 < 0)) {
      iVar6 = 0x16;
    }
    else {
      _mfs_get(param_1,iVar1,iVar6);
      iVar1 = *param_1;
      iVar2 = *(int *)(iVar1 + 0x14);
      if ((param_3 == 1) && ((param_4 & 2) != 0)) {
        *(int *)(param_2 + 8) = iVar2;
      }
      uVar3 = *(uint *)(param_2 + 8);
      iVar4 = *(int *)(param_2 + 0x12);
      uVar5 = *(uint *)(param_1[9] + 0x10);
      if ((param_3 == 1) || ((param_3 == 0 && (*(int *)(iVar1 + 0x2c) == 0)))) {
        *param_5 = *param_5 + 1;
        if (*(int *)(iVar1 + 0x2c) != 0) {
          _crfree(*(int *)(iVar1 + 0x2c));
        }
        *(sword **)(iVar1 + 0x2c) = param_5;
      }
      *(undefined4 *)(iVar1 + 0x30) = 0;
      uStack_18 = *(uint *)(param_2 + 8);
      iVar10 = 0;
      do {
        uVar9 = uVar5;
        if (*(uint *)(param_2 + 0x12) <= uVar5) {
          uVar9 = *(uint *)(param_2 + 0x12);
        }
        if (param_3 == 0) {
          uVar7 = iVar2 - *(int *)(param_2 + 8);
          if ((int)uVar7 < 1) {
            _mfs_put(param_1);
            return 0;
          }
          if ((int)uVar7 < (int)uVar9) {
            uVar9 = uVar7;
          }
        }
        if ((param_3 == 1) &&
           (uVar7 = uVar9 + *(int *)(param_2 + 8), *(uint *)(iVar1 + 0x14) < uVar7)) {
          *(uint *)(iVar1 + 0x14) = uVar7;
        }
        uVar7 = *(uint *)(param_2 + 8);
        if ((uVar7 < *(uint *)(iVar1 + 0x10)) ||
           (*(int *)(iVar1 + 0xc) + *(uint *)(iVar1 + 0x10) < uVar9 + uVar7)) {
          _remap_vnode(param_1,uVar7,uVar9);
        }
        iVar6 = _uiomove((*(int *)(param_2 + 8) + *(int *)(iVar1 + 8)) - *(int *)(iVar1 + 0x10),
                         uVar9,param_3,param_2);
        if (param_3 == 1) {
          *(byte *)(iVar1 + 0x34) = *(byte *)(iVar1 + 0x34) | 0x40;
        }
        iVar8 = *(int *)(iVar1 + 0x30);
        if (iVar8 != 0) {
          *(undefined4 *)(iVar1 + 0x30) = 0;
          _crfree(*(undefined4 *)(iVar1 + 0x2c));
          *(undefined4 *)(iVar1 + 0x2c) = 0;
          iVar6 = iVar8;
        }
        if (((param_3 == 1) && ((*(byte *)(param_1[9] + 0xe) & 1) != 0)) &&
           (iVar10 = iVar10 + 1, _nmfsbuf <= iVar10)) {
          if (iVar6 == 0) {
            _vmp_push(iVar1);
            iVar8 = 0;
            if (0 < iVar10) {
              do {
                uVar7 = (**(code **)(param_1[7] + 0x80))(param_1,uVar5);
                _blkflush(param_1,uStack_18 / uVar7);
                uStack_18 = uVar5 + uStack_18;
                iVar8 = iVar8 + 1;
              } while (iVar8 < iVar10);
            }
            iVar10 = *(int *)(iVar1 + 0x30);
            if (iVar10 != 0) {
              *(undefined4 *)(iVar1 + 0x30) = 0;
              iVar6 = iVar10;
            }
          }
          iVar10 = 0;
        }
        if (iVar6 != 0) goto loc_404DA76;
      } while ((0 < *(int *)(param_2 + 0x12)) && (uVar9 != 0));
      if ((param_3 == 1) && (((param_4 & 4) != 0 || ((*(byte *)(param_1[9] + 0xe) & 1) != 0)))) {
        _vmp_push(iVar1);
        uVar9 = uVar3 + iVar4;
        for (; uVar3 < uVar9; uVar3 = uVar5 + uVar3) {
          uVar7 = (**(code **)(param_1[7] + 0x80))(param_1,uVar5);
          _blkflush(param_1,uVar3 / uVar7);
        }
        iVar2 = *(int *)(iVar1 + 0x30);
        if (iVar2 != 0) {
          *(undefined4 *)(iVar1 + 0x30) = 0;
          iVar6 = iVar2;
        }
      }
loc_404DA76:
      _mfs_put(param_1);
    }
  }
  return iVar6;
}
/* GHIDRADEC_FUNCTION index=1459 start=0x404da8a */

void _mfs_sync(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = _vm_info_version;
  puVar4 = _vm_info_queue;
  while ((undefined4 **)puVar4 != &_vm_info_queue) {
    puVar1 = (undefined4 *)puVar4[9];
    iVar3 = iVar2;
    if ((*(byte *)(puVar4 + 0xd) & 0x40) != 0) {
      _vmp_get(puVar4);
      _vmp_push(puVar4);
      _vmp_put(puVar4);
      iVar3 = iVar2 + 2;
    }
    iVar2 = _vm_info_version;
    puVar4 = _vm_info_queue;
    if (_vm_info_version == iVar3) {
      iVar2 = iVar3;
      puVar4 = puVar1;
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1460 start=0x404daf2 */

undefined4 _mfs_fsync(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_1;
  if ((iVar1 == 0) || ((*(byte *)(iVar1 + 0x34) & 8) == 0)) {
    uVar2 = 0;
  }
  else {
    _vmp_get(iVar1);
    _vmp_push(iVar1);
    _vmp_put(iVar1);
    uVar2 = *(undefined4 *)(iVar1 + 0x30);
  }
  return uVar2;
}
/* GHIDRADEC_FUNCTION index=1461 start=0x404db32 */

undefined4 _mfs_fsync_invalidate(int *param_1,uint param_2)

{
  int iVar1;
  sword sVar2;
  undefined4 uVar3;
  
  iVar1 = *param_1;
  if ((iVar1 == 0) || ((*(byte *)(iVar1 + 0x34) & 8) == 0)) {
    uVar3 = 0;
  }
  else {
    if ((char)*(byte *)(iVar1 + 0x34) < '\0') {
      _vm_info_dequeue(iVar1);
    }
    *(sword *)(iVar1 + 6) = *(sword *)(iVar1 + 6) + 1;
    if ((param_2 & 1) == 0) {
      _vmp_push_all(iVar1);
    }
    if ((param_2 & 2) == 0) {
      *(byte *)(iVar1 + 0x34) = *(byte *)(iVar1 + 0x34) & 0xef;
      _vmp_invalidate(iVar1);
    }
    sVar2 = *(sword *)(iVar1 + 6);
    *(sword *)(iVar1 + 6) = sVar2 + -1;
    if (sVar2 == 1) {
      _vm_info_enqueue(iVar1);
    }
    uVar3 = *(undefined4 *)(iVar1 + 0x30);
  }
  return uVar3;
}
/* GHIDRADEC_FUNCTION index=1462 start=0x404dbb8 */

undefined4 _mfs_invalidate(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x34) & 8) != 0)) {
    if (*(sword *)(iVar1 + 6) < 1) {
      _vmp_get(iVar1);
      _vmp_invalidate(iVar1);
      _vmp_put(iVar1);
    }
    else {
      *(byte *)(iVar1 + 0x34) = *(byte *)(iVar1 + 0x34) | 0x10;
    }
  }
  return *(undefined4 *)(iVar1 + 0x30);
}
/* GHIDRADEC_FUNCTION index=1463 start=0x404dc06 */

void _vno_flush(int *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = *(int *)(*param_1 + 0x20);
  if (iVar1 == 0) {
    return;
  }
  uVar2 = _page_mask + param_2 + param_3;
  uVar3 = ~_page_mask;
  param_2 = uVar3 & param_2;
  do {
    while( true ) {
      if ((uVar3 & uVar2) <= param_2) {
        return;
      }
      iVar4 = _vm_page_lookup(iVar1,param_2);
      if (iVar4 != 0) break;
loc_404DC76:
      param_2 = _page_size + param_2;
    }
    if (-1 < (char)*(byte *)(iVar4 + 0x20)) {
      _vm_page_free(iVar4);
      goto loc_404DC76;
    }
    *(byte *)(iVar4 + 0x20) = *(byte *)(iVar4 + 0x20) | 0x40;
    _assert_wait(iVar4,0);
    _thread_block();
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1464 start=0x404dc88 */

void _vmp_invalidate(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar1;
    while (puVar4 = puVar2, puVar4 != puVar1) {
      puVar2 = (undefined4 *)puVar4[2];
      if ((*(byte *)((int)puVar4 + 0x21) & 0x10) == 0) {
        if ((char)*(byte *)(puVar4 + 8) < '\0') {
          *(byte *)(puVar4 + 8) = *(byte *)(puVar4 + 8) | 0x40;
          _assert_wait(puVar4,0);
          _thread_block();
          puVar2 = puVar4;
        }
        else if (*(sword *)(puVar4 + 7) == 0) {
          _pmap_remove_all(*(undefined4 *)((int)puVar4 + 0x22));
          if (((*(byte *)((int)puVar4 + 0x1e) & 4) == 0) ||
             (iVar3 = _pmap_is_modified(*(undefined4 *)((int)puVar4 + 0x22)), iVar3 != 0)) {
            _mfs_mdirty = _mfs_mdirty + 1;
          }
          else {
            _mfs_mclean = _mfs_mclean + 1;
            _vm_page_free(puVar4);
          }
        }
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1465 start=0x404dd20 */

void _vmp_push(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  
  if ((*(byte *)(param_1 + 0x34) & 0x40) != 0) {
    *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) & 0xbf;
    iVar2 = *(int *)(param_1 + 0x20);
    if (iVar2 != 0) {
      uVar5 = _page_mask + *(uint *)(param_1 + 0x10) + *(int *)(param_1 + 0xc);
      uVar6 = ~_page_mask;
      uVar10 = uVar6 & *(uint *)(param_1 + 0x10);
      while (uVar10 < (uVar6 & uVar5)) {
        puVar8 = (undefined4 *)_vm_page_lookup(iVar2,uVar10);
        if ((puVar8 == (undefined4 *)0x0) || ((*(byte *)((int)puVar8 + 0x21) & 0x10) != 0)) {
loc_404DE5C:
          uVar10 = _page_size + uVar10;
        }
        else {
          if (-1 < (char)*(byte *)(puVar8 + 8)) {
            if ((*(byte *)((int)puVar8 + 0x1e) & 0x40) == 0) {
              _vm_page_activate(puVar8);
            }
            _vm_page_deactivate(puVar8);
            puVar1 = (undefined4 *)*puVar8;
            puVar3 = (undefined4 *)puVar8[1];
            puVar7 = puVar3;
            if (puVar1 != &_vm_page_queue_inactive) {
              puVar1[1] = puVar3;
              puVar7 = dword_40C23DC;
            }
            dword_40C23DC = puVar7;
            *puVar3 = puVar1;
            *(byte *)((int)puVar8 + 0x1e) = *(byte *)((int)puVar8 + 0x1e) & 0x7f;
            _vm_page_inactive_count = _vm_page_inactive_count + -1;
            *(byte *)(puVar8 + 8) = *(byte *)(puVar8 + 8) | 0x80;
            if ((*(byte *)((int)puVar8 + 0x1e) & 0x20) != 0) {
              _pmap_remove_all(*(undefined4 *)((int)puVar8 + 0x22));
              *(sword *)(iVar2 + 0x40) = *(sword *)(iVar2 + 0x40) + 1;
              iVar9 = _vnode_pageout(puVar8);
              *(sword *)(iVar2 + 0x40) = *(sword *)(iVar2 + 0x40) + -1;
              if (iVar9 == 0) {
                *(byte *)((int)puVar8 + 0x1e) = *(byte *)((int)puVar8 + 0x1e) & 0xdf;
              }
            }
            _vm_page_activate(puVar8);
            bVar4 = *(byte *)(puVar8 + 8);
            *(byte *)(puVar8 + 8) = bVar4 & 0x7f;
            *(byte *)(puVar8 + 8) = bVar4 & 0x7f;
            if ((bVar4 & 0x40) != 0) {
              *(byte *)(puVar8 + 8) = bVar4 & 0x3f;
              _thread_wakeup_prim(puVar8,0,0);
            }
            goto loc_404DE5C;
          }
          *(byte *)(puVar8 + 8) = *(byte *)(puVar8 + 8) | 0x40;
          _assert_wait(puVar8,0);
          _thread_block();
        }
      }
    }
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1466 start=0x404de70 */

void _vmp_push_all(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  byte bVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  *(byte *)(param_1 + 0x34) = *(byte *)(param_1 + 0x34) & 0xbf;
  puVar2 = *(undefined4 **)(param_1 + 0x20);
  if (puVar2 == (undefined4 *)0x0) {
    return;
  }
loc_404DE8C:
  puVar7 = (undefined4 *)*puVar2;
  if (puVar7 == puVar2) {
    return;
  }
  do {
    if ((*(byte *)((int)puVar7 + 0x21) & 0x10) == 0) {
      if ((char)*(byte *)(puVar7 + 8) < '\0') break;
      if ((*(byte *)((int)puVar7 + 0x1e) & 0x40) == 0) {
        _vm_page_activate(puVar7);
      }
      _vm_page_deactivate(puVar7);
      puVar1 = (undefined4 *)*puVar7;
      puVar3 = (undefined4 *)puVar7[1];
      puVar5 = puVar3;
      if (puVar1 != &_vm_page_queue_inactive) {
        puVar1[1] = puVar3;
        puVar5 = dword_40C23DC;
      }
      dword_40C23DC = puVar5;
      *puVar3 = puVar1;
      *(byte *)((int)puVar7 + 0x1e) = *(byte *)((int)puVar7 + 0x1e) & 0x7f;
      _vm_page_inactive_count = _vm_page_inactive_count + -1;
      *(byte *)(puVar7 + 8) = *(byte *)(puVar7 + 8) | 0x80;
      if ((*(byte *)((int)puVar7 + 0x1e) & 0x20) != 0) {
        _pmap_remove_all(*(undefined4 *)((int)puVar7 + 0x22));
        *(sword *)(puVar2 + 0x10) = *(sword *)(puVar2 + 0x10) + 1;
        iVar6 = _vnode_pageout(puVar7);
        *(sword *)(puVar2 + 0x10) = *(sword *)(puVar2 + 0x10) + -1;
        if (iVar6 == 0) {
          *(byte *)((int)puVar7 + 0x1e) = *(byte *)((int)puVar7 + 0x1e) & 0xdf;
        }
      }
      _vm_page_activate(puVar7);
      bVar4 = *(byte *)(puVar7 + 8);
      *(byte *)(puVar7 + 8) = bVar4 & 0x7f;
      *(byte *)(puVar7 + 8) = bVar4 & 0x7f;
      if ((bVar4 & 0x40) != 0) {
        *(byte *)(puVar7 + 8) = bVar4 & 0x3f;
        _thread_wakeup_prim(puVar7,0,0);
      }
    }
    puVar7 = (undefined4 *)puVar7[2];
    if (puVar7 == puVar2) {
      return;
    }
  } while( true );
  *(byte *)(puVar7 + 8) = *(byte *)(puVar7 + 8) | 0x40;
  _assert_wait(puVar7,0);
  _thread_block();
  goto loc_404DE8C;
}
/* GHIDRADEC_FUNCTION index=1467 start=0x404df88 */

void _vm_info_free(undefined4 *param_1)

{
  _mfs_uncache(param_1);
  _zfree(_vm_info_zone,*param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1468 start=0x404dfb0 */

undefined4 _vm_get_vnode_size(int *param_1)

{
  return *(undefined4 *)(*param_1 + 0x14);
}
/* GHIDRADEC_FUNCTION index=1469 start=0x404dfc2 */

void _vm_set_vnode_size(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*param_1 + 0x14) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=1470 start=0x404dfd6 */

void _vm_set_close_flush(int *param_1,int param_2)

{
  *(byte *)(*param_1 + 0x34) = *(byte *)(*param_1 + 0x34) & 0xdf | (param_2 != 0) << 5;
  return;
}
/* GHIDRADEC_FUNCTION index=1471 start=0x404dffa */

void _vm_set_error(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*param_1 + 0x30) = param_2;
  return;
}
/* GHIDRADEC_FUNCTION index=1472 start=0x404e174 */

void _miniMonInit(void)

{
  __kernDebuggerLock = _simple_lock_alloc();
  _simple_unlock(__kernDebuggerLock);
  return;
}
/* GHIDRADEC_FUNCTION index=1473 start=0x404e190 */

void _miniMonLoop(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  _miniMonState = param_3;
  if (param_2 != 0) {
    _safe_prf(aSystemPanic_0);
    _safe_prf(&aS,_panicstr);
    _safe_prf(aTypeRToRebootO);
    do {
      while( true ) {
        iVar1 = _miniMonTryGetchar();
        if (iVar1 != 0x72) break;
        _safe_prf(aRebooting);
        _miniMonReboot(&unk_40A62E7);
      }
    } while (iVar1 != 0x6d);
    _safe_prf(&asc_40A6049);
  }
  _safe_prf(aNextstepMiniMo);
  do {
    _safe_prf(&aS_0,param_1);
    sub_404E0D2(unk_40B393A,0x80);
    iVar1 = sub_404E046(unk_40B393A);
  } while (iVar1 != 0);
  return;
}
/* GHIDRADEC_FUNCTION index=1474 start=0x404e2e4 */

void _safe_prf(undefined4 param_1)

{
  char cVar1;
  char *pcStack_8;
  
  pcStack_8 = unk_40B373A;
  _prf(param_1,&stack0x00000008,8,&pcStack_8);
  *pcStack_8 = '\0';
  pcStack_8 = unk_40B373A;
  cVar1 = unk_40B373A[0];
  while (cVar1 != '\0') {
    cVar1 = *pcStack_8;
    pcStack_8 = pcStack_8 + 1;
    _miniMonPutchar((int)cVar1);
    cVar1 = *pcStack_8;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1475 start=0x404e3a8 */

void _ns_callout_init(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = _ncallout;
  _ns_callfree = _ns_callout;
  uVar3 = 1;
  piVar1 = _ns_callout;
  if (1 < _ncallout) {
    do {
      *piVar1 = (int)(piVar1 + 6);
      uVar3 = uVar3 + 1;
      piVar1 = piVar1 + 6;
    } while (uVar3 < uVar2);
  }
  _ns_callout[_ncallout * 6 + -6] = 0;
  return;
}
/* GHIDRADEC_FUNCTION index=1476 start=0x404e3f8 */

byte _ns_timer_init(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  cVar2 = '\0';
  cVar3 = '\x01';
  cVar4 = '\0';
  bVar5 = 0;
  __set_timer_expire_func(0,sub_404E458);
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=1477 start=0x404e420 */

void _ns_hardclock_init(void)

{
  dword_40C2448 = 1000000000 / _hz;
  _ns_per_tick = (int)-(dword_40C2448 < 0);
  _hardclock_init(_ns_per_tick,dword_40C2448);
  return;
}
/* GHIDRADEC_FUNCTION index=1478 start=0x404e53a */

void _ns_timeout(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  sqword sVar1;
  
  sVar1 = _clock_value(1);
  _ns_abstimeout(param_1,param_2,sVar1 + CONCAT44(param_3,param_4),param_5);
  return;
}
/* GHIDRADEC_FUNCTION index=1479 start=0x404e57e */

undefined4
_ns_abstimeout(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined2 extraout_D0u;
  undefined2 uVar4;
  undefined4 in_D0;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  byte bVar14;
  undefined8 uVar15;
  
  puVar3 = _ns_callfree;
  uVar4 = (undefined2)((uint)in_D0 >> 0x10);
  if (_ns_callfree == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    _panic(aNsAbstimeoutTa);
  }
  puVar1 = _ns_callfree + 5;
  _ns_callfree = (undefined4 *)*_ns_callfree;
  *puVar1 = param_5;
  puVar3[3] = param_2;
  puVar3[4] = param_1;
  puVar1 = &_ns_calltodo;
  for (puVar2 = _ns_calltodo; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    uVar8 = puVar2[1];
    uVar4 = (undefined2)(uVar8 - (((uint)puVar2[2] < param_4) + param_3) >> 0x10);
    if (param_3 <= uVar8 && ((uint)puVar2[2] >= param_4 || uVar8 != param_3)) break;
    puVar1 = puVar2;
  }
  *puVar1 = puVar3;
  *puVar3 = puVar2;
  puVar3[1] = param_3;
  puVar3[2] = param_4;
  cVar13 = puVar3 < _ns_calltodo;
  cVar12 = SBORROW4((int)puVar3,(int)_ns_calltodo);
  cVar10 = (int)puVar3 - (int)_ns_calltodo < 0;
  cVar11 = '\0';
  bVar14 = cVar13;
  if (puVar3 == _ns_calltodo) {
    uVar15 = _clock_value(1);
    uVar5 = (uint)((qword)uVar15 >> 0x20);
    uVar7 = (uint)uVar15;
    uVar8 = 0;
    uVar9 = 0;
    if (uVar5 < param_3 || uVar7 < param_4 && uVar5 == param_3) {
      uVar9 = param_4 - uVar7;
      uVar8 = param_3 - ((param_4 < uVar7) + uVar5);
    }
    puVar6 = (uint *)_timer_attributes(0);
    uVar5 = *puVar6;
    cVar13 = uVar5 < uVar8 || puVar6[1] < uVar9 && uVar5 == uVar8;
    if (uVar5 < uVar8 || puVar6[1] < uVar9 && uVar5 == uVar8) {
      puVar6 = (uint *)_timer_attributes(0);
      uVar8 = *puVar6;
      uVar9 = puVar6[1];
    }
    cVar10 = '\0';
    cVar11 = '\x01';
    cVar12 = '\0';
    bVar14 = 0;
    __set_timer(0,uVar8,uVar9);
    uVar4 = extraout_D0u;
  }
  return CONCAT22(uVar4,(word)(byte)(cVar13 << 4 | cVar10 << 3 | cVar11 << 2 | cVar12 << 1 | bVar14)
                 );
}
/* GHIDRADEC_FUNCTION index=1480 start=0x404e664 */

undefined4 _ns_untimeout(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar1 = &_ns_calltodo;
  puVar2 = _ns_calltodo;
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      uVar3 = _callout_remove(param_1,param_2);
      return uVar3;
    }
    if ((param_1 == puVar2[4]) && (param_2 == puVar2[3])) break;
    puVar1 = puVar2;
    puVar2 = (undefined4 *)*puVar2;
  }
  *puVar1 = *puVar2;
  *puVar2 = _ns_callfree;
  _ns_callfree = puVar2;
  return 1;
}
/* GHIDRADEC_FUNCTION index=1481 start=0x404e6ce */

byte _ns_sleep(int param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  byte bVar5;
  
  cVar1 = '\0';
  cVar2 = param_1 < 0;
  cVar3 = param_1 == 0;
  cVar4 = '\0';
  bVar5 = 0;
  _ns_timeout(_wakeup,&param_1,param_1,param_2,1);
  _sleep(&param_1,0x18);
  return cVar1 << 4 | cVar2 << 3 | cVar3 << 2 | cVar4 << 1 | bVar5;
}
/* GHIDRADEC_FUNCTION index=1482 start=0x404e712 */

void _ns_time_to_timeval(uint param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  qword qVar2;
  
  piVar1 = param_3 + 1;
  qVar2 = CONCAT44(param_1 % 1000000000,param_2);
  *piVar1 = (int)(qVar2 % 1000000000);
  *param_3 = (int)(qVar2 / 1000000000);
  *piVar1 = *piVar1 / 1000;
  return;
}
/* GHIDRADEC_FUNCTION index=1483 start=0x404e76e */

undefined8 _timeval_to_ns_time(int *param_1)

{
  uint uVar1;
  sqword sVar2;
  int iVar3;
  
  sVar2 = (sqword)*param_1 * 1000000 + CONCAT44((int)-(param_1[1] < 0),param_1[1]);
  uVar1 = (uint)sVar2;
  iVar3 = (int)((qword)sVar2 >> 0x20);
  sVar2 = sVar2 + CONCAT44((((iVar3 << 5 | uVar1 >> 0x1b) - ((uint)(uVar1 * 0x20 < uVar1) + iVar3))
                            * 2 + (uint)CARRY4(uVar1 * 0x1f,uVar1 * 0x1f)) * 2 +
                           (uint)CARRY4(uVar1 * 0x3e,uVar1 * 0x3e),uVar1 * 0x7c);
  uVar1 = (uint)sVar2;
  return CONCAT44((((int)((qword)sVar2 >> 0x20) * 2 + (uint)CARRY4(uVar1,uVar1)) * 2 +
                  (uint)CARRY4(uVar1 * 2,uVar1 * 2)) * 2 + (uint)CARRY4(uVar1 * 4,uVar1 * 4),
                  uVar1 * 8);
}
/* GHIDRADEC_FUNCTION index=1484 start=0x404e7d0 */

void _ns_time_to_tsval(uint param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_3 = (int)(CONCAT44(param_1 % 1000,param_2) / 1000);
  param_3[1] = param_1 / 1000;
  return;
}
/* GHIDRADEC_FUNCTION index=1485 start=0x404e81e */

undefined8 _ticks_to_ns_time(uint param_1)

{
  return CONCAT44(_ns_per_tick * param_1 + (int)((qword)dword_40C2448 * (qword)param_1 >> 0x20),
                  (int)((qword)dword_40C2448 * (qword)param_1));
}
/* GHIDRADEC_FUNCTION index=1486 start=0x404e85c */

undefined4 _sched_usec_elapsed(void)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  
  uVar6 = _clock_value(1);
  iVar4 = (int)((qword)uVar6 >> 0x20);
  uVar5 = (uint)uVar6;
  uVar3 = CONCAT44(dword_40B39BA,dword_40B39BE);
  if (dword_40B39BE == 0 && dword_40B39BA == 0) {
    uVar3 = uVar6;
  }
  dword_40B39BA = (int)((qword)uVar3 >> 0x20);
  dword_40B39BE = (uint)uVar3;
  iVar1 = uVar5 - dword_40B39BE;
  iVar2 = (uint)(uVar5 < dword_40B39BE) + dword_40B39BA;
  dword_40B39BA = iVar4;
  dword_40B39BE = uVar5;
  return (int)(CONCAT44((uint)(iVar4 - iVar2) % 1000,iVar1) / 1000);
}
/* GHIDRADEC_FUNCTION index=1487 start=0x404e8de */

void _get_calendar_time_value(undefined4 *param_1)

{
  int *piVar1;
  qword qVar2;
  undefined8 uVar3;
  
  uVar3 = _clock_value(0);
  piVar1 = param_1 + 1;
  qVar2 = CONCAT44((uint)((qword)uVar3 >> 0x20) % 1000000000,(int)uVar3);
  *piVar1 = (int)(qVar2 % 1000000000);
  *param_1 = (int)(qVar2 / 1000000000);
  *piVar1 = *piVar1 / 1000;
  return;
}
/* GHIDRADEC_FUNCTION index=1488 start=0x404e948 */

void _set_calendar_time_value(int *param_1)

{
  _set_clock(0,(sqword)param_1[1] * 1000 + (sqword)*param_1 * 1000000000);
  return;
}
/* GHIDRADEC_FUNCTION index=1489 start=0x404e98c */

void _microtime(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  uVar4 = _clock_value(0);
  uVar2 = (uint)((qword)uVar4 >> 0x20);
  uVar3 = (uint)uVar4;
  if ((uVar2 < dword_40AF93C || uVar3 < dword_40AF940 && uVar2 == dword_40AF93C) &&
     (uVar1 = dword_40AF940 - uVar3, uVar2 = (dword_40AF940 < uVar3) + uVar2,
     uVar1 < 999999999 && dword_40AF93C == uVar2 ||
     dword_40AF93C - uVar2 == (uint)(uVar1 < 999999999) && uVar1 == 999999999)) {
    uVar4 = CONCAT44(dword_40AF93C,dword_40AF940);
  }
  dword_40AF93C = (uint)((qword)uVar4 >> 0x20);
  dword_40AF940 = (uint)uVar4;
  _ns_time_to_timeval(uVar4,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1490 start=0x404ea00 */

void _microboot(undefined4 param_1)

{
  undefined8 uVar1;
  
  uVar1 = _clock_value(1);
  _ns_time_to_timeval(uVar1,param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=1491 start=0x404ea28 */

void _us_timeout(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  uVar1 = _timeval_to_ns_time(param_3);
  _ns_timeout(param_1,param_2,uVar1,param_4);
  return;
}
/* GHIDRADEC_FUNCTION index=1492 start=0x404ea60 */

void _us_abstimeout(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  uVar1 = _timeval_to_ns_time(param_3);
  _ns_abstimeout(param_1,param_2,uVar1,param_4);
  return;
}
/* GHIDRADEC_FUNCTION index=1493 start=0x404ea98 */

void _us_untimeout(undefined4 param_1,undefined4 param_2)

{
  _ns_untimeout(param_1,param_2);
  return;
}
/* GHIDRADEC_FUNCTION index=1494 start=0x404eb90 */

void _power_callout(undefined4 param_1,int param_2)

{
  undefined8 uVar1;
  
  sub_404EAAE(0);
  if (param_2 == 0) {
    param_2 = _calloutEntryAllocate(_power_callout,0);
  }
  uVar1 = _calloutDeadlineFromInterval(0,1010000000);
  _calloutEntryDispatchDelayed(param_2,uVar1);
  return;
}
/* GHIDRADEC_FUNCTION index=1495 start=0x404ebe0 */

void _power_init(void)

{
  int iVar1;
  
  if (dword_40AF944 == 0) {
    iVar1 = _PMConnect();
    if (iVar1 == 0) {
      _power_callout(0,0);
    }
    dword_40B39C2 = 0;
    dword_40AF944 = 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=1496 start=0x404ec12 */

undefined4 _kern_PMSetPowerState(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == &_realhost) {
    uVar1 = _PMSetPowerState(param_2,param_3);
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1497 start=0x404ec36 */

undefined4 _kern_PMGetPowerEvent(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == &_realhost) {
    uVar1 = sub_404EAAE(param_2);
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1498 start=0x404ec56 */

undefined4 _kern_PMGetPowerStatus(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == &_realhost) {
    uVar1 = _PMGetPowerStatus(param_2);
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}
/* GHIDRADEC_FUNCTION index=1499 start=0x404ec76 */

undefined4 _kern_PMSetPowerManagement(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == &_realhost) {
    uVar1 = _PMSetPowerManagement(param_2,param_3);
  }
  else {
    uVar1 = 0x16;
  }
  return uVar1;
}

