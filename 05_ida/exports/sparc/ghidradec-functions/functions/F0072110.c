
/* WARNING: Removing unreachable block (ram,0xf007221c) */
/* WARNING: Removing unreachable block (ram,0xf0072248) */
/* WARNING: Removing unreachable block (ram,0xf0072328) */
/* WARNING: Removing unreachable block (ram,0xf00721c4) */
/* WARNING: Removing unreachable block (ram,0xf0072184) */
/* WARNING: Removing unreachable block (ram,0xf0072170) */
/* WARNING: Removing unreachable block (ram,0xf00721bc) */
/* WARNING: Removing unreachable block (ram,0xf00722fc) */
/* WARNING: Removing unreachable block (ram,0xf0072334) */
/* WARNING: Removing unreachable block (ram,0xf0072308) */
/* WARNING: Removing unreachable block (ram,0xf007233c) */
/* WARNING: Removing unreachable block (ram,0xf007213c) */

void _idle_thread_continue(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int *piVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  int *piVar9;
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
  
  iVar1 = _processor_ptr;
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
  piVar8 = (int *)(_processor_ptr + 0x118);
  piVar9 = (int *)(_processor_ptr + 0x108);
  do {
    _PMSetCpuState(0);
    iVar2 = *piVar8;
    while (((iVar2 == 0 && (unk_F01350C8 == 0)) && (*piVar9 == 0))) {
      if ((_need_ast & 0xfffffff8) != 0) {
        _splusclock();
        _need_ast = _need_ast & 0xfffffff8;
        _spl0();
      }
      iVar2 = *piVar8;
    }
    uVar3 = 1;
    _PMSetCpuState(1);
    _splusclock();
    iVar2 = *(int *)(iVar1 + 0x114);
    while (iVar2 != 3) {
      if (iVar2 != 2) {
        if (iVar2 == 4 || iVar2 == 5) {
          iVar2 = *piVar8;
          if (iVar2 != 0) {
            *piVar8 = 0;
            _thread_setrun(iVar2,0);
          }
loc_F0072308:
          _thread_block_with_continuation(_idle_thread_continue);
        }
        else {
          _printf(0xf0110588,*(undefined4 *)(_processor_ptr + 0x114),0);
          _panic(aIdleThread);
        }
        goto loc_F007233C;
      }
      iVar2 = *(int *)(iVar1 + 300);
      do {
        do {
        } while (*(int *)(iVar2 + 0x118) != 0);
        piVar5 = (int *)(iVar2 + 0x118);
        _simple_lock_try();
      } while (piVar5 == (int *)0x0);
      if (*(int *)(iVar1 + 0x114) == 2) {
        _no_dispatch_count._0_4_ = _no_dispatch_count._0_4_ + 1;
        *(int *)(iVar2 + 0x114) = *(int *)(iVar2 + 0x114) + -1;
        iVar7 = *(int *)(iVar1 + 0x10c);
        iVar6 = *(int *)(iVar1 + 0x110);
        if (iVar2 + 0x10c == iVar7) {
          *(int *)(iVar2 + 0x110) = iVar6;
        }
        else {
          *(int *)(iVar7 + 0x110) = iVar6;
        }
        if (iVar2 + 0x10c == iVar6) {
          *(int *)(iVar2 + 0x10c) = iVar7;
        }
        else {
          *(int *)(iVar6 + 0x10c) = iVar7;
        }
        *(undefined4 *)(iVar1 + 0x114) = 1;
        *(undefined4 *)(iVar2 + 0x118) = 0;
        goto loc_F0072308;
      }
      *(undefined4 *)(iVar2 + 0x118) = 0;
      iVar2 = *(int *)(iVar1 + 0x114);
    }
    iVar2 = *piVar8;
    *piVar8 = 0;
    *(undefined4 *)(iVar1 + 0x114) = 1;
    uVar4 = dword_F013512C;
    if (*(int *)(iVar2 + 0x60) == 2) {
      uVar4 = *(undefined4 *)(iVar2 + 0x5c);
    }
    *(undefined4 *)(iVar1 + 0x120) = uVar4;
    *(undefined4 *)(iVar1 + 0x124) = 1;
    _thread_run(_idle_thread_continue);
loc_F007233C:
    _splx(uVar3);
  } while( true );
}
