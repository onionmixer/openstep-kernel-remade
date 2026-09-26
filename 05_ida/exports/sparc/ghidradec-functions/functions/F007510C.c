
/* WARNING: Removing unreachable block (ram,0xf00751e0) */
/* WARNING: Removing unreachable block (ram,0xf00751a8) */
/* WARNING: Removing unreachable block (ram,0xf007513c) */
/* WARNING: Removing unreachable block (ram,0xf007512c) */
/* WARNING: Removing unreachable block (ram,0xf0075210) */
/* WARNING: Removing unreachable block (ram,0xf0075240) */
/* WARNING: Removing unreachable block (ram,0xf0075134) */
/* WARNING: Removing unreachable block (ram,0xf0075160) */
/* WARNING: Removing unreachable block (ram,0xf00751cc) */
/* WARNING: Removing unreachable block (ram,0xf007524c) */
/* WARNING: Removing unreachable block (ram,0xf00751f4) */

undefined8 _thread_halt_self(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  code *pcVar7;
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
  
  puVar1 = _active_threads;
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
  uVar2 = 0xf009bc00;
  pcVar7 = _thread_exception_return;
  if ((_active_threads[99] & 2) == 0) {
    piVar5 = _active_threads + 8;
    _splusclock();
    do {
      do {
      } while (*piVar5 != 0);
      piVar6 = piVar5;
      _simple_lock_try();
    } while (piVar6 == (int *)0x0);
    puVar1[8] = 0;
    puVar1[0x13] = puVar1[0x13] | 0x10;
    puVar1[99] = puVar1[99] & 0xfffffffe;
    _splx(uVar2);
  }
  else {
    _ipc_thread_terminate(_active_threads);
    puVar3 = puVar1;
    _thread_hold(puVar1);
    _splusclock();
    do {
      do {
      } while (_reaper_lock != 0);
      puVar4 = &_reaper_lock;
      _simple_lock_try();
    } while (puVar4 == (undefined4 *)0x0);
    *puVar1 = &_reaper_queue;
    puVar1[1] = DAT_f0135154;
    *DAT_f0135154 = puVar1;
    DAT_f0135154 = puVar1;
    _reaper_lock = 0;
    do {
      do {
      } while (puVar1[8] != 0);
      piVar5 = puVar1 + 8;
      _simple_lock_try();
    } while (piVar5 == (int *)0x0);
    puVar1[8] = 0;
    puVar1[0x13] = puVar1[0x13] | 0x10;
    _splx(puVar3);
    _thread_wakeup_prim(&_reaper_queue,0,0);
    pcVar7 = _walking_zombie;
  }
  _thread_block_with_continuation(pcVar7);
  return CONCAT44(param_2,param_1);
}
