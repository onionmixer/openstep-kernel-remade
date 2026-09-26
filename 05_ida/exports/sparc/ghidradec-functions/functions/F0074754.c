
/* WARNING: Removing unreachable block (ram,0xf0074824) */
/* WARNING: Removing unreachable block (ram,0xf00747d8) */
/* WARNING: Removing unreachable block (ram,0xf0074780) */
/* WARNING: Removing unreachable block (ram,0xf0074814) */
/* WARNING: Removing unreachable block (ram,0xf00747ac) */
/* WARNING: Removing unreachable block (ram,0xf0074764) */

undefined8 _thread_deallocate_interrupt(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
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
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = param_1;
    _splusclock();
    do {
      do {
      } while (param_1[8] != 0);
      piVar2 = param_1 + 8;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    iVar3 = param_1[9];
    param_1[9] = iVar3 + -1;
    if (iVar3 + -1 < 1) {
      param_1[9] = 1;
      do {
        do {
        } while (_reaper_lock != 0);
        puVar4 = &_reaper_lock;
        _simple_lock_try();
      } while (puVar4 == (undefined4 *)0x0);
      *param_1 = &_reaper_queue;
      param_1[1] = DAT_f0135154;
      *DAT_f0135154 = param_1;
      _reaper_lock = 0;
      DAT_f0135154 = param_1;
      param_1[8] = 0;
      _splx(puVar1);
      _thread_wakeup_prim(&_reaper_queue,0,0);
    }
    else {
      param_1[8] = 0;
      _splx(puVar1);
    }
  }
  return CONCAT44(param_2,param_1);
}
