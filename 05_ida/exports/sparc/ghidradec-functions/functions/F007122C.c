
/* WARNING: Removing unreachable block (ram,0xf0071314) */
/* WARNING: Removing unreachable block (ram,0xf00712ec) */
/* WARNING: Removing unreachable block (ram,0xf007134c) */
/* WARNING: Removing unreachable block (ram,0xf0071280) */
/* WARNING: Removing unreachable block (ram,0xf0071248) */

undefined8 _thread_select(int *param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
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
  param_1[0x49] = 1;
  if (0 < param_1[0x42]) {
    piVar6 = param_1;
    _choose_thread(param_1);
    param_1[0x48] = _min_quantum;
    goto locret_F00713E0;
  }
  do {
    do {
    } while (DAT_f01350c0._0_4_ != 0);
    puVar1 = &DAT_f01350c0;
    _simple_lock_try();
    piVar6 = _active_threads;
  } while (puVar1 == (undefined8 *)0x0);
  if (unk_F01350C8 == 0) {
    if ((_active_threads[0x13] != 4) ||
       (((int *)_active_threads[0x65] != (int *)0x0 && ((int *)_active_threads[0x65] != param_1))))
    goto loc_F007134C;
    DAT_f01350c0._0_4_ = 0;
    piVar4 = _active_threads + 8;
    do {
      do {
      } while (*piVar4 != 0);
      piVar2 = piVar4;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    if (piVar6[0x1c] != _sched_tick) {
      _update_priority(piVar6);
    }
    piVar6[8] = 0;
    iVar5 = piVar6[0x18];
  }
  else {
    iVar5 = DAT_f01350c0._4_4_ * 8;
    piVar6 = *(int **)(_default_pset + iVar5);
    piVar4 = (int *)(_default_pset + iVar5);
    if (piVar4 == piVar6) {
      DAT_f01350c0._4_4_ = DAT_f01350c0._4_4_ + -1;
loc_F007134C:
      piVar6 = param_1;
      _choose_pset_thread(param_1,_default_pset);
    }
    else {
      if (piVar6 == piVar4) {
        piVar6 = (int *)0x0;
      }
      else {
        *(int **)(*piVar6 + 4) = piVar4;
        *(int *)(_default_pset + iVar5) = *piVar6;
      }
      piVar6[2] = 0;
      unk_F01350C8 = unk_F01350C8 + -1;
      if ((0 < unk_F01350C8) && ((DAT_f0135128 & 2) != 0)) {
        piVar2 = (int *)*piVar4;
        while (piVar4 == piVar2) {
          piVar4 = piVar4 + -2;
          DAT_f01350c0._4_4_ = DAT_f01350c0._4_4_ + -1;
          piVar2 = (int *)*piVar4;
        }
      }
      DAT_f01350c0._0_4_ = 0;
    }
    iVar5 = piVar6[0x18];
  }
  iVar3 = dword_F013512C;
  if (iVar5 == 2) {
    iVar3 = piVar6[0x17];
  }
  param_1[0x48] = iVar3;
locret_F00713E0:
  return CONCAT44(param_2,piVar6);
}
