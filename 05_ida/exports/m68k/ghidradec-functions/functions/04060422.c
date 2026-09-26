
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
