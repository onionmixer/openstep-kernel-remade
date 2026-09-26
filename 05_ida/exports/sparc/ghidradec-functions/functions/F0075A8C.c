
/* WARNING: Removing unreachable block (ram,0xf0075b24) */
/* WARNING: Removing unreachable block (ram,0xf0075b14) */
/* WARNING: Removing unreachable block (ram,0xf0075b70) */
/* WARNING: Removing unreachable block (ram,0xf0075b58) */
/* WARNING: Removing unreachable block (ram,0xf0075ab8) */
/* WARNING: Removing unreachable block (ram,0xf0075b64) */
/* WARNING: Removing unreachable block (ram,0xf0075b08) */
/* WARNING: Removing unreachable block (ram,0xf0075b1c) */
/* WARNING: Removing unreachable block (ram,0xf0075b40) */
/* WARNING: Removing unreachable block (ram,0xf0075a9c) */

void _reaper_thread_continue(code *param_1)

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
      } while (_reaper_lock != 0);
      puVar1 = &_reaper_lock;
      _simple_lock_try();
    } while (puVar1 == (undefined4 *)0x0);
    while( true ) {
      if (_reaper_queue._0_4_ == (code *)&_reaper_queue) {
        pcVar2 = (code *)0x0;
      }
      else {
        *(undefined8 **)(*(int *)_reaper_queue._0_4_ + 4) = &_reaper_queue;
        pcVar2 = _reaper_queue._0_4_;
        _reaper_queue._0_4_ = *(code **)_reaper_queue._0_4_;
      }
      if (pcVar2 == (code *)0x0) break;
      _reaper_lock = 0;
      _splx(param_1);
      _thread_dowait(pcVar2,1);
      _thread_deallocate();
      _splusclock();
      do {
        do {
        } while (_reaper_lock != 0);
        puVar1 = &_reaper_lock;
        _simple_lock_try();
        param_1 = pcVar2;
      } while (puVar1 == (undefined4 *)0x0);
    }
    _assert_wait(&_reaper_queue,0);
    _reaper_lock = 0;
    _splx(param_1);
    param_1 = _reaper_thread_continue;
    _thread_block_with_continuation();
  } while( true );
}
