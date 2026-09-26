
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
