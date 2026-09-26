
/* WARNING: Removing unreachable block (ram,0xf00765f8) */
/* WARNING: Removing unreachable block (ram,0xf00765e8) */
/* WARNING: Removing unreachable block (ram,0xf0076638) */
/* WARNING: Removing unreachable block (ram,0xf0076598) */
/* WARNING: Removing unreachable block (ram,0xf007662c) */
/* WARNING: Removing unreachable block (ram,0xf0076644) */
/* WARNING: Removing unreachable block (ram,0xf00765f0) */
/* WARNING: Removing unreachable block (ram,0xf0076614) */
/* WARNING: Removing unreachable block (ram,0xf007657c) */

void _swapin_thread_continue(code *param_1)

{
  undefined4 *puVar1;
  undefined4 unaff_l0;
  code *pcVar2;
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
  do {
    _splusclock();
    do {
      do {
      } while (_swapper_lock_data != 0);
      puVar1 = &_swapper_lock_data;
      _simple_lock_try();
    } while (puVar1 == (undefined4 *)0x0);
    while( true ) {
      if (_swapin_queue._0_4_ == (code *)&_swapin_queue) {
        pcVar2 = (code *)0x0;
      }
      else {
        *(undefined8 **)(*(int *)_swapin_queue._0_4_ + 4) = &_swapin_queue;
        pcVar2 = _swapin_queue._0_4_;
        _swapin_queue._0_4_ = *(code **)_swapin_queue._0_4_;
      }
      if (pcVar2 == (code *)0x0) break;
      _swapper_lock_data = 0;
      _splx(param_1);
      _thread_doswapin();
      _splusclock();
      do {
        do {
        } while (_swapper_lock_data != 0);
        puVar1 = &_swapper_lock_data;
        _simple_lock_try();
        param_1 = pcVar2;
      } while (puVar1 == (undefined4 *)0x0);
    }
    _assert_wait(&_swapin_queue,0);
    _swapper_lock_data = 0;
    _splx(param_1);
    param_1 = _swapin_thread_continue;
    _thread_block_with_continuation();
  } while( true );
}

