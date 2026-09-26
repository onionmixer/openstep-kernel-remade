
/* WARNING: Removing unreachable block (ram,0xf0072564) */
/* WARNING: Removing unreachable block (ram,0xf0072484) */
/* WARNING: Removing unreachable block (ram,0xf007250c) */
/* WARNING: Removing unreachable block (ram,0xf007258c) */
/* WARNING: Removing unreachable block (ram,0xf0072468) */

undefined8 _do_runq_scan(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int *piVar6;
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
  iVar4 = param_1;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_1 + 0x100) != 0);
    piVar5 = (int *)(param_1 + 0x100);
    _simple_lock_try();
  } while (piVar5 == (int *)0x0);
  iVar7 = *(int *)(param_1 + 0x108);
  if (0 < iVar7) {
    piVar5 = (int *)(param_1 + *(int *)(param_1 + 0x104) * 8);
    do {
      piVar1 = (int *)*piVar5;
      iVar2 = _stuck_count;
      while (_stuck_count = iVar2, piVar5 != piVar1) {
        piVar6 = (int *)*piVar1;
        if (((piVar1[0x13] & 0xfU) == 4) && (1 < (uint)(_sched_tick - piVar1[0x1c]))) {
          if (iVar2 == 0x80) {
            *(undefined4 *)(param_1 + 0x100) = 0;
            _splx(iVar4);
            uVar8 = 1;
            goto locret_F0072598;
          }
          piVar6[1] = piVar1[1];
          iVar3 = _do_thread_scan_debug;
          _stuck_count = iVar2 + 1;
          *(int *)piVar1[1] = *piVar1;
          *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + -1;
          piVar1[2] = 0;
          *(int **)(_stuck_threads + iVar2 * 4) = piVar1;
          if (iVar3 != 0) {
            _printf(aDoRunqScanAddi,piVar1);
          }
        }
        iVar7 = iVar7 + -1;
        piVar1 = piVar6;
        iVar2 = _stuck_count;
      }
      piVar5 = piVar5 + -2;
    } while (0 < iVar7);
  }
  *(undefined4 *)(param_1 + 0x100) = 0;
  _splx(iVar4);
  uVar8 = 0;
locret_F0072598:
  return CONCAT44(param_2,uVar8);
}
