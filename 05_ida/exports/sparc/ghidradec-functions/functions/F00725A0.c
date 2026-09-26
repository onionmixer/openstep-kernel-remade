
/* WARNING: Removing unreachable block (ram,0xf0072650) */
/* WARNING: Removing unreachable block (ram,0xf007261c) */
/* WARNING: Removing unreachable block (ram,0xf00725cc) */
/* WARNING: Removing unreachable block (ram,0xf00725fc) */
/* WARNING: Removing unreachable block (ram,0xf0072644) */
/* WARNING: Removing unreachable block (ram,0xf007265c) */
/* WARNING: Removing unreachable block (ram,0xf00725b4) */

undefined8 _do_thread_scan(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
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
    puVar1 = _default_pset;
    _do_runq_scan();
    if (puVar1 == (undefined *)0x0) {
      puVar1 = _master_processor;
      _do_runq_scan();
    }
    while (0 < _stuck_count) {
      iVar2 = _stuck_count + -1;
      iVar4 = *(int *)(_stuck_threads + iVar2 * 4);
      _stuck_count = iVar2;
      *(undefined4 *)(_stuck_threads + iVar2 * 4) = 0;
      _splusclock();
      do {
        do {
        } while (*(int *)(iVar4 + 0x20) != 0);
        piVar3 = (int *)(iVar4 + 0x20);
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      if ((*(uint *)(iVar4 + 0x4c) & 0xf) == 4) {
        _update_priority(iVar4);
        _thread_setrun(iVar4,1);
      }
      *(undefined4 *)(iVar4 + 0x20) = 0;
      _splx(iVar2);
    }
  } while (puVar1 != (undefined *)0x0);
  return CONCAT44(param_2,param_1);
}
