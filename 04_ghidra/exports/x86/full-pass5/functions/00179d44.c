/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00179d44 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _vm_pageout_scan(void)

{
  int *piVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 local_c;
  
  local_c = 0;
  uVar5 = _splimp();
  do {
  } while (_vm_page_queue_free_lock != 0);
  LOCK();
  UNLOCK();
  bVar3 = _vm_page_free_min < _vm_page_free_count;
  if (bVar3) {
    LOCK();
    _vm_page_queue_free_lock = 0;
    UNLOCK();
    _splx(uVar5);
  }
  else {
    LOCK();
    _vm_page_queue_free_lock = 0;
    UNLOCK();
    _splx(uVar5);
    _pmap_update();
  }
  do {
  } while (_vm_page_queue_lock != 0);
  LOCK();
  _vm_page_queue_lock = 1;
  UNLOCK();
  puVar8 = _vm_page_queue_inactive;
  while( true ) {
    puVar7 = puVar8;
    if ((bVar3) || ((undefined4 **)puVar7 == &_vm_page_queue_inactive)) goto LAB_0017a054;
    uVar5 = _splimp();
    do {
    } while (_vm_page_queue_free_lock != 0);
    LOCK();
    UNLOCK();
    if (_vm_page_free_target <= _vm_page_free_count) break;
    LOCK();
    _vm_page_queue_free_lock = 0;
    UNLOCK();
    _splx(uVar5);
    iVar6 = _pmap_is_referenced(puVar7[9]);
    if (iVar6 == 0) {
      if ((*(byte *)((int)puVar7 + 0x1e) & 0x20) == 0) {
        if ((*(byte *)((int)puVar7 + 0x1e) & 4) != 0) {
          iVar9 = puVar7[5];
          LOCK();
          iVar6 = *(int *)(iVar9 + 0x10);
          *(int *)(iVar9 + 0x10) = 1;
          UNLOCK();
          if (iVar6 != 1) {
            *(byte *)(puVar7 + 8) = *(byte *)(puVar7 + 8) | 1;
            _DAT_001f6510 = _DAT_001f6510 + 1;
            LOCK();
            _vm_page_queue_lock = 0;
            UNLOCK();
            _pmap_remove_all(puVar7[9]);
            _vm_object_collapse(iVar9);
            *(short *)(iVar9 + 0x44) = *(short *)(iVar9 + 0x44) + 1;
            LOCK();
            *(undefined4 *)(iVar9 + 0x10) = 0;
            UNLOCK();
            _thread_wakeup_prim(&_vm_page_free_count,0,0);
            iVar6 = *(int *)(iVar9 + 0x28);
            if ((iVar6 == 0) &&
               (iVar6 = _vm_pager_allocate(*(undefined4 *)(iVar9 + 0x14)), iVar6 != 0)) {
              _vm_object_setpager(iVar9,iVar6,0,0);
            }
            bVar4 = false;
            if ((iVar6 != 0) && (iVar6 = _vm_pager_put(iVar6,puVar7), iVar6 == 0)) {
              bVar4 = true;
            }
            piVar1 = (int *)(iVar9 + 0x10);
            do {
              do {
              } while (*piVar1 != 0);
              LOCK();
              iVar6 = *piVar1;
              *piVar1 = 1;
              UNLOCK();
            } while (iVar6 == 1);
            do {
            } while (_vm_page_queue_lock != 0);
            LOCK();
            _vm_page_queue_lock = 1;
            UNLOCK();
            puVar8 = (undefined4 *)*puVar7;
            if (bVar4) {
              *(byte *)((int)puVar7 + 0x1e) = *(byte *)((int)puVar7 + 0x1e) & 0xfb;
            }
            else {
              _vm_page_activate(puVar7);
            }
            _pmap_clear_reference(puVar7[9]);
            bVar2 = *(byte *)(puVar7 + 8);
            *(byte *)(puVar7 + 8) = bVar2 & 0xfe;
            if ((bVar2 & 2) != 0) {
              *(byte *)(puVar7 + 8) = bVar2 & 0xfc;
              _thread_wakeup_prim(puVar7,0,0);
            }
            *(short *)(iVar9 + 0x44) = *(short *)(iVar9 + 0x44) + -1;
            _thread_wakeup_prim(iVar9,0,0);
            goto LAB_0017a03f;
          }
        }
        puVar8 = (undefined4 *)*puVar7;
      }
      else {
        puVar8 = (undefined4 *)*puVar7;
        iVar9 = puVar7[5];
        LOCK();
        iVar6 = *(int *)(iVar9 + 0x10);
        *(int *)(iVar9 + 0x10) = 1;
        UNLOCK();
        if (iVar6 != 1) {
          *(byte *)(puVar7 + 8) = *(byte *)(puVar7 + 8) | 1;
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
          _pmap_remove_all(puVar7[9]);
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          _vm_page_queue_lock = 1;
          UNLOCK();
          bVar2 = *(byte *)(puVar7 + 8);
          *(byte *)(puVar7 + 8) = bVar2 & 0xfe;
          if ((bVar2 & 2) != 0) {
            *(byte *)(puVar7 + 8) = bVar2 & 0xfc;
            _thread_wakeup_prim(puVar7,0,0);
          }
          puVar8 = (undefined4 *)*puVar7;
          _vm_page_addfree(puVar7);
LAB_0017a03f:
          local_c = 1;
          LOCK();
          *(undefined4 *)(iVar9 + 0x10) = 0;
          UNLOCK();
        }
      }
    }
    else {
      puVar8 = (undefined4 *)*puVar7;
      _vm_page_activate(puVar7);
      _DAT_001f6508 = _DAT_001f6508 + 1;
    }
  }
  LOCK();
  _vm_page_queue_free_lock = 0;
  UNLOCK();
  _splx(uVar5);
LAB_0017a054:
  iVar6 = (_vm_page_inactive_target - _vm_page_inactive_count) - _vm_page_free_count;
  while ((0 < iVar6 && ((undefined4 **)_vm_page_queue_active != &_vm_page_queue_active))) {
    local_c = 1;
    _vm_page_deactivate(_vm_page_queue_active);
    iVar6 = iVar6 + -1;
  }
  LOCK();
  _vm_page_queue_lock = 0;
  UNLOCK();
  return local_c;
}

