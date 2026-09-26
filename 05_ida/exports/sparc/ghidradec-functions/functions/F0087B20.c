
/* WARNING: Removing unreachable block (ram,0xf0087f00) */
/* WARNING: Removing unreachable block (ram,0xf0087eb0) */
/* WARNING: Removing unreachable block (ram,0xf0087e78) */
/* WARNING: Removing unreachable block (ram,0xf0087e2c) */
/* WARNING: Removing unreachable block (ram,0xf0087df8) */
/* WARNING: Removing unreachable block (ram,0xf0087dc0) */
/* WARNING: Removing unreachable block (ram,0xf0087d88) */
/* WARNING: Removing unreachable block (ram,0xf0087d58) */
/* WARNING: Removing unreachable block (ram,0xf0087d04) */
/* WARNING: Removing unreachable block (ram,0xf0087ca0) */
/* WARNING: Removing unreachable block (ram,0xf0087c80) */
/* WARNING: Removing unreachable block (ram,0xf0087c50) */
/* WARNING: Removing unreachable block (ram,0xf0087bd4) */
/* WARNING: Removing unreachable block (ram,0xf0087b80) */
/* WARNING: Removing unreachable block (ram,0xf0087b48) */
/* WARNING: Removing unreachable block (ram,0xf0087bb4) */
/* WARNING: Removing unreachable block (ram,0xf0087b88) */
/* WARNING: Removing unreachable block (ram,0xf0087c2c) */
/* WARNING: Removing unreachable block (ram,0xf0087b9c) */
/* WARNING: Removing unreachable block (ram,0xf0087c88) */
/* WARNING: Removing unreachable block (ram,0xf0087cd0) */
/* WARNING: Removing unreachable block (ram,0xf0087d1c) */
/* WARNING: Removing unreachable block (ram,0xf0087d64) */
/* WARNING: Removing unreachable block (ram,0xf0087db8) */
/* WARNING: Removing unreachable block (ram,0xf0087de0) */
/* WARNING: Removing unreachable block (ram,0xf0087e14) */
/* WARNING: Removing unreachable block (ram,0xf0087e50) */
/* WARNING: Removing unreachable block (ram,0xf0087ea8) */
/* WARNING: Removing unreachable block (ram,0xf0087ee0) */
/* WARNING: Removing unreachable block (ram,0xf0087f68) */
/* WARNING: Removing unreachable block (ram,0xf0087b24) */

undefined8 _vm_pageout_scan(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
  bool bVar10;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar8 = 0;
  _spltty();
  do {
    do {
    } while (_vm_page_queue_free_lock != 0);
    puVar5 = &_vm_page_queue_free_lock;
    _simple_lock_try();
  } while (puVar5 == (undefined4 *)0x0);
  bVar9 = _vm_page_free_min < _vm_page_free_count;
  if (bVar9) {
    _vm_page_queue_free_lock = 0;
    _splx(param_1);
  }
  else {
    _vm_page_queue_free_lock = 0;
    _splx(param_1);
    _pmap_update();
  }
  do {
    do {
    } while (_vm_page_queue_lock != 0);
    puVar5 = &_vm_page_queue_lock;
    _simple_lock_try();
  } while (puVar5 == (undefined4 *)0x0);
  if (bVar9) {
    uVar8 = 0;
  }
  else {
    param_2 = 0xbfffffff;
    puVar5 = _vm_page_queue_inactive;
    while (puVar6 = puVar5, uVar1 = 0xf0111c00, (undefined4 **)puVar6 != &_vm_page_queue_inactive) {
      _spltty();
      do {
        do {
        } while (_vm_page_queue_free_lock != 0);
        puVar5 = &_vm_page_queue_free_lock;
        _simple_lock_try();
      } while (puVar5 == (undefined4 *)0x0);
      if (_vm_page_free_target <= _vm_page_free_count) {
        _vm_page_queue_free_lock = 0;
        _splx(uVar1);
        break;
      }
      _vm_page_queue_free_lock = 0;
      _splx(uVar1);
      iVar2 = puVar6[9];
      _pmap_is_referenced();
      if (iVar2 == 0) {
        if ((puVar6[7] & 0x400) == 0) {
          if ((puVar6[7] & 0x2000) == 0) {
            puVar5 = (undefined4 *)*puVar6;
          }
          else {
            iVar7 = puVar6[5];
            iVar2 = iVar7 + 0x10;
            _simple_lock_try();
            if (iVar2 == 0) {
              puVar5 = (undefined4 *)*puVar6;
            }
            else {
              puVar6[8] = puVar6[8] | 0x80000000;
              _vm_page_queue_lock = 0;
              DAT_f013c258._8_4_ = DAT_f013c258._8_4_ + 1;
              _pmap_remove_all(puVar6[9]);
              _vm_object_collapse(iVar7);
              *(undefined4 *)(iVar7 + 0x10) = 0;
              *(sword *)(iVar7 + 0x44) = *(sword *)(iVar7 + 0x44) + 1;
              _thread_wakeup_prim(&_vm_page_free_count,0,0);
              iVar2 = *(int *)(iVar7 + 0x28);
              uVar8 = 1;
              bVar9 = false;
              if (iVar2 == 0) {
                iVar2 = *(int *)(iVar7 + 0x14);
                _vm_pager_allocate();
                bVar9 = iVar2 == 0;
                if (!bVar9) {
                  _vm_object_setpager(iVar7,iVar2,0,0);
                  bVar9 = iVar2 == 0;
                }
              }
              bVar10 = false;
              if (!bVar9) {
                _vm_pager_put(iVar2,puVar6);
                bVar10 = iVar2 == 0;
              }
              do {
                do {
                } while (*(int *)(iVar7 + 0x10) != 0);
                piVar4 = (int *)(iVar7 + 0x10);
                _simple_lock_try();
              } while (piVar4 == (int *)0x0);
              do {
                do {
                } while (_vm_page_queue_lock != 0);
                puVar5 = &_vm_page_queue_lock;
                _simple_lock_try();
              } while (puVar5 == (undefined4 *)0x0);
              puVar5 = (undefined4 *)*puVar6;
              if (bVar10) {
                puVar6[7] = puVar6[7] & 0xffffdfff;
              }
              else {
                _vm_page_activate(puVar6);
              }
              _pmap_clear_reference(puVar6[9]);
              uVar3 = puVar6[8];
              puVar6[8] = uVar3 & 0x7fffffff;
              if ((uVar3 & 0x40000000) != 0) {
                puVar6[8] = uVar3 & 0x3fffffff;
                _thread_wakeup_prim(puVar6,0,0);
              }
              *(sword *)(iVar7 + 0x44) = *(sword *)(iVar7 + 0x44) + -1;
              _thread_wakeup_prim(iVar7,0,0);
              *(undefined4 *)(iVar7 + 0x10) = 0;
            }
          }
        }
        else {
          iVar7 = puVar6[5];
          puVar5 = (undefined4 *)*puVar6;
          iVar2 = iVar7 + 0x10;
          _simple_lock_try();
          if (iVar2 != 0) {
            uVar8 = 1;
            puVar6[8] = puVar6[8] | 0x80000000;
            _vm_page_queue_lock = 0;
            _pmap_remove_all(puVar6[9]);
            do {
              do {
              } while (_vm_page_queue_lock != 0);
              puVar5 = &_vm_page_queue_lock;
              _simple_lock_try();
            } while (puVar5 == (undefined4 *)0x0);
            uVar3 = puVar6[8];
            puVar6[8] = uVar3 & 0x7fffffff;
            if ((uVar3 & 0x40000000) != 0) {
              puVar6[8] = uVar3 & 0x3fffffff;
              _thread_wakeup_prim(puVar6,0,0);
            }
            puVar5 = (undefined4 *)*puVar6;
            _vm_page_addfree(puVar6);
            *(undefined4 *)(iVar7 + 0x10) = 0;
          }
        }
      }
      else {
        puVar5 = (undefined4 *)*puVar6;
        _vm_page_activate(puVar6);
        DAT_f013c258._0_4_ = DAT_f013c258._0_4_ + 1;
      }
    }
  }
  iVar2 = (_vm_page_inactive_target - _vm_page_inactive_count) - _vm_page_free_count;
  while ((0 < iVar2 && ((undefined4 **)_vm_page_queue_active != &_vm_page_queue_active))) {
    uVar8 = 1;
    _vm_page_deactivate();
    iVar2 = iVar2 + -1;
  }
  _vm_page_queue_lock = 0;
  return CONCAT44(param_2,uVar8);
}
