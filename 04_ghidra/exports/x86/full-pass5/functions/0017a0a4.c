/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017a0a4 */

void _vm_pageout(void)

{
  int iVar1;
  
  iVar1 = 1;
  *(undefined4 *)(_active_threads + 0x78) = 1;
  _spl0();
  if (_vm_page_free_min == 0) {
    _vm_page_free_min = _vm_page_free_count / 0x32;
    if ((int)_vm_page_free_min < 3) {
      _vm_page_free_min = 3;
    }
    if (_vm_page_free_min_sanity <= _vm_page_free_min * _page_size &&
        _vm_page_free_min * _page_size - _vm_page_free_min_sanity != 0) {
      _vm_page_free_min = _vm_page_free_min_sanity / _page_size;
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
  } while (_vm_pages_needed_lock != 0);
  LOCK();
  _vm_pages_needed_lock = 1;
  UNLOCK();
  do {
    if ((iVar1 == 0) ||
       (((int)_vm_page_free_min < _vm_page_free_count &&
        ((_vm_page_free_target <= _vm_page_free_count ||
         (_vm_page_inactive_target < _vm_page_inactive_count)))))) {
      _thread_sleep(&_vm_pages_needed,&_vm_pages_needed_lock,0);
    }
    else {
      LOCK();
      _vm_pages_needed_lock = 0;
      UNLOCK();
    }
    iVar1 = _vm_pageout_scan();
    do {
    } while (_vm_pages_needed_lock != 0);
    LOCK();
    _vm_pages_needed_lock = 1;
    UNLOCK();
    _thread_wakeup_prim(&_vm_page_free_count,0,0);
  } while( true );
}

