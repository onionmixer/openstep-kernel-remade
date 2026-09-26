
/* WARNING: Removing unreachable block (ram,0xf008819c) */
/* WARNING: Removing unreachable block (ram,0xf0088170) */
/* WARNING: Removing unreachable block (ram,0xf00880a0) */
/* WARNING: Removing unreachable block (ram,0xf0087fec) */
/* WARNING: Removing unreachable block (ram,0xf0087fc4) */
/* WARNING: Removing unreachable block (ram,0xf0088008) */
/* WARNING: Removing unreachable block (ram,0xf0088100) */
/* WARNING: Removing unreachable block (ram,0xf0088180) */
/* WARNING: Removing unreachable block (ram,0xf00881b4) */
/* WARNING: Removing unreachable block (ram,0xf0087fa0) */

void _vm_pageout(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  *(undefined4 *)(_active_threads + 0x78) = 1;
  _spl0();
  if (_vm_page_free_min == (undefined8 *)0x0) {
    puVar3 = _vm_page_free_count;
    div(_vm_page_free_count,0x32);
    uVar1 = _page_size;
    _vm_page_free_min = puVar3;
    if ((int)puVar3 < 3) {
      _vm_page_free_min = (undefined8 *)0x3;
    }
    puVar3 = _vm_page_free_min;
    umul(_vm_page_free_min,_page_size);
    if (_vm_page_free_min_sanity < puVar3) {
      puVar3 = _vm_page_free_min_sanity;
      udiv(_vm_page_free_min_sanity,uVar1);
      _vm_page_free_min = puVar3;
    }
  }
  if (_vm_page_free_reserved == 0) {
    _vm_page_free_reserved = 3;
  }
  if ((_vm_pageout_free_min == 0) &&
     (_vm_pageout_free_min = _vm_page_free_reserved / 2, 10 < _vm_pageout_free_min)) {
    _vm_pageout_free_min = 10;
  }
  if (_vm_page_free_target == 0) {
    _vm_page_free_target = (int)_vm_page_free_min << 2;
  }
  if (_vm_page_inactive_target == (undefined8 *)0x0) {
    puVar3 = _vm_page_free_count;
    div(_vm_page_free_count,3);
    _vm_page_inactive_target = puVar3;
  }
  if (_vm_page_free_target <= (int)_vm_page_free_min) {
    _vm_page_free_target = (int)_vm_page_free_min + 1;
  }
  if ((int)_vm_page_inactive_target <= _vm_page_free_target) {
    _vm_page_inactive_target = (undefined8 *)(_vm_page_free_target + 1);
  }
  do {
    do {
    } while (_vm_pages_needed_lock != 0);
    puVar2 = &_vm_pages_needed_lock;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  puVar3 = (undefined8 *)0x1;
  do {
    if ((puVar3 == (undefined8 *)0x0) ||
       ((puVar3 = (undefined8 *)0xf0111c00, (int)_vm_page_free_min < (int)_vm_page_free_count &&
        ((_vm_page_free_target <= (int)_vm_page_free_count ||
         (puVar3 = _vm_page_inactive_target, (int)_vm_page_inactive_target < _vm_page_inactive_count
         )))))) {
      puVar3 = &_vm_pages_needed;
      _thread_sleep(&_vm_pages_needed,&_vm_pages_needed_lock,0);
    }
    else {
      _vm_pages_needed_lock = 0;
    }
    _vm_pageout_scan();
    do {
      do {
      } while (_vm_pages_needed_lock != 0);
      puVar2 = &_vm_pages_needed_lock;
      _simple_lock_try();
    } while (puVar2 == (undefined4 *)0x0);
    _thread_wakeup_prim(&_vm_page_free_count,0,0);
  } while( true );
}

