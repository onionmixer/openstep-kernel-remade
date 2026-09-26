
/* WARNING: Removing unreachable block (ram,0xf006eb34) */
/* WARNING: Removing unreachable block (ram,0xf006eb04) */
/* WARNING: Removing unreachable block (ram,0xf006ea9c) */
/* WARNING: Removing unreachable block (ram,0xf006ea34) */
/* WARNING: Removing unreachable block (ram,0xf006ec98) */
/* WARNING: Removing unreachable block (ram,0xf006ec58) */
/* WARNING: Removing unreachable block (ram,0xf006ebf0) */
/* WARNING: Removing unreachable block (ram,0xf006eb88) */
/* WARNING: Removing unreachable block (ram,0xf006ebb0) */
/* WARNING: Removing unreachable block (ram,0xf006ec24) */
/* WARNING: Removing unreachable block (ram,0xf006ec8c) */
/* WARNING: Removing unreachable block (ram,0xf006ea18) */
/* WARNING: Removing unreachable block (ram,0xf006ea5c) */
/* WARNING: Removing unreachable block (ram,0xf006ead0) */
/* WARNING: Removing unreachable block (ram,0xf006eb28) */
/* WARNING: Removing unreachable block (ram,0xf006eca0) */
/* WARNING: Removing unreachable block (ram,0xf006eb6c) */

undefined8 _thread_quantum_update(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  int iVar7;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar4 = _min_quantum;
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
  piVar6 = (int *)(param_1 * 4);
  iVar7 = piVar6[-0x3fb2d94];
  dword_F013512C = _min_quantum;
  if (param_4 != 2) {
    param_3 = *(int *)(iVar7 + 0x120) - param_3;
    *(int *)(iVar7 + 0x120) = param_3;
    if (param_3 < 1) {
      piVar6 = (int *)(param_2 + 0x20);
      _splusclock();
      do {
        do {
        } while (*piVar6 != 0);
        piVar3 = piVar6;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      if (*(int *)(param_2 + 0x70) == _sched_tick) {
        if ((*(int *)(param_2 + 0x60) != 2) && (*(int *)(param_2 + 100) < 0)) {
          if (*(int *)(param_2 + 0x10c) == *(int *)(param_2 + 0xf8)) {
            iVar1 = *(int *)(param_2 + 0xf0) - *(int *)(param_2 + 0x108);
            *(int *)(param_2 + 0x108) = *(int *)(param_2 + 0xf0);
          }
          else {
            iVar1 = param_2 + 0xf0;
            _timer_delta(iVar1,param_2 + 0x108);
          }
          if (*(int *)(param_2 + 0x104) == *(int *)(param_2 + 0xe8)) {
            iVar2 = *(int *)(param_2 + 0xe0) - *(int *)(param_2 + 0x100);
            *(int *)(param_2 + 0x100) = *(int *)(param_2 + 0xe0);
          }
          else {
            iVar2 = param_2 + 0xe0;
            _timer_delta(iVar2,param_2 + 0x100);
          }
          piVar6 = (int *)(iVar1 + iVar2);
          *(int *)(param_2 + 0x110) = *(int *)(param_2 + 0x110) + (int)piVar6;
          piVar3 = piVar6;
          .umul(piVar6,*(undefined4 *)(*(int *)(param_2 + 400) + 0x178));
          iVar1 = *(int *)(param_2 + 0x114) + (int)piVar3;
          *(int *)(param_2 + 0x114) = iVar1;
          *(int *)(param_2 + 0x6c) = *(int *)(param_2 + 0x6c) + iVar1;
          *(undefined4 *)(param_2 + 0x114) = 0;
          _compute_my_priority(param_2);
        }
      }
      else {
        _update_priority(param_2);
      }
      *(undefined4 *)(param_2 + 0x20) = 0;
      _splx(param_3);
      *(undefined4 *)(iVar7 + 0x124) = 0;
      if (*(int *)(param_2 + 0x60) == 2) {
        *(int *)(iVar7 + 0x120) = *(int *)(iVar7 + 0x120) + *(int *)(param_2 + 0x5c);
      }
      else {
        *(int *)(iVar7 + 0x120) = *(int *)(iVar7 + 0x120) + iVar4;
      }
    }
    else {
      piVar6 = (int *)(param_2 + 0x20);
      _splusclock();
      do {
        do {
        } while (*piVar6 != 0);
        piVar3 = piVar6;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      if (*(int *)(param_2 + 0x70) == _sched_tick) {
        if ((*(int *)(param_2 + 0x60) != 2) && (*(int *)(param_2 + 100) < 0)) {
          if (*(int *)(param_2 + 0x10c) == *(int *)(param_2 + 0xf8)) {
            iVar4 = *(int *)(param_2 + 0xf0) - *(int *)(param_2 + 0x108);
            *(int *)(param_2 + 0x108) = *(int *)(param_2 + 0xf0);
          }
          else {
            iVar4 = param_2 + 0xf0;
            _timer_delta(iVar4,param_2 + 0x108);
          }
          if (*(int *)(param_2 + 0x104) == *(int *)(param_2 + 0xe8)) {
            iVar7 = *(int *)(param_2 + 0xe0) - *(int *)(param_2 + 0x100);
            *(int *)(param_2 + 0x100) = *(int *)(param_2 + 0xe0);
          }
          else {
            iVar7 = param_2 + 0xe0;
            _timer_delta(iVar7,param_2 + 0x100);
          }
          piVar6 = (int *)(iVar4 + iVar7);
          *(int *)(param_2 + 0x110) = *(int *)(param_2 + 0x110) + (int)piVar6;
          piVar3 = piVar6;
          .umul(piVar6,*(undefined4 *)(*(int *)(param_2 + 400) + 0x178));
          uVar5 = *(int *)(param_2 + 0x114) + (int)piVar3;
          *(uint *)(param_2 + 0x114) = uVar5;
          if (0x7ffffff < uVar5) {
            *(undefined4 *)(param_2 + 0x114) = 0;
            *(uint *)(param_2 + 0x6c) = *(int *)(param_2 + 0x6c) + uVar5;
            _compute_my_priority(param_2);
          }
        }
      }
      else {
        _update_priority(param_2);
      }
      *(undefined4 *)(param_2 + 0x20) = 0;
      _splx(param_3);
    }
    _ast_check();
  }
  return CONCAT44(param_2,piVar6);
}
