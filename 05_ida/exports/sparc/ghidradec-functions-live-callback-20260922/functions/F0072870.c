
/* WARNING: Removing unreachable block (ram,0xf00729c8) */
/* WARNING: Removing unreachable block (ram,0xf0072a14) */
/* WARNING: Removing unreachable block (ram,0xf0072970) */
/* WARNING: Removing unreachable block (ram,0xf0072928) */
/* WARNING: Removing unreachable block (ram,0xf00728c8) */
/* WARNING: Removing unreachable block (ram,0xf00728e8) */
/* WARNING: Removing unreachable block (ram,0xf0072948) */
/* WARNING: Removing unreachable block (ram,0xf00729dc) */
/* WARNING: Removing unreachable block (ram,0xf0072988) */
/* WARNING: Removing unreachable block (ram,0xf0072a2c) */
/* WARNING: Removing unreachable block (ram,0xf00728b8) */

undefined8 _thread_switch(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  iVar1 = _active_threads;
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
  iVar5 = 0;
  if (param_2 == 1) {
    _thread_depress_priority(_active_threads,param_3);
  }
  else if (param_2 < 2) {
    if (param_2 != 0) {
      uVar6 = 4;
      goto locret_F0072A38;
    }
  }
  else {
    if (param_2 != 2) {
      uVar6 = 4;
      goto locret_F0072A38;
    }
    _thread_will_wait_with_timeout(_active_threads);
  }
  if (param_1 == 0) {
loc_F00729F8:
    if ((param_1 != 0) && (iVar5 == 0xf)) {
      uVar6 = 4;
      goto locret_F0072A38;
    }
loc_F0072A14:
    _thread_block_with_continuation(_thread_switch_continue);
    iVar5 = *(int *)(iVar1 + 100);
  }
  else {
    iVar5 = *(int *)(*(int *)(iVar1 + 0xc) + 0x88);
    _ipc_object_translate(iVar5,param_1,0,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar5 != 0) goto loc_F00729F8;
    uVar4 = *(uint *)(*(int *)((int)register0x00000038 + -0xc) + 8);
    puVar2 = *(undefined4 **)((int)register0x00000038 + -0xc);
    if ((-1 < (int)uVar4) ||
       (puVar2 = *(undefined4 **)((int)register0x00000038 + -0xc), (uVar4 & 0xffff) != 1)) {
loc_F00729E8:
      *puVar2 = 0;
      goto loc_F0072A14;
    }
    param_2 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x14);
    _splusclock();
    do {
      do {
      } while (*(int *)(param_2 + 0x20) != 0);
      piVar3 = (int *)(param_2 + 0x20);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    if ((*(int *)(param_2 + 400) != *(int *)(iVar1 + 400)) ||
       (iVar5 = param_2, _rem_runq(), iVar5 == 0)) {
      *(undefined4 *)(param_2 + 0x20) = 0;
      _splx(puVar2);
      puVar2 = *(undefined4 **)((int)register0x00000038 + -0xc);
      goto loc_F00729E8;
    }
    *(undefined4 *)(param_2 + 0x20) = 0;
    _splx(puVar2);
    **(undefined4 **)((int)register0x00000038 + -0xc) = 0;
    iVar5 = _processor_ptr;
    if (*(int *)(param_2 + 0x60) == 2) {
      *(undefined4 *)(_processor_ptr + 0x120) = *(undefined4 *)(param_2 + 0x5c);
      *(undefined4 *)(iVar5 + 0x124) = 1;
    }
    _thread_run(_thread_switch_continue,param_2);
    iVar5 = *(int *)(iVar1 + 100);
  }
  uVar6 = 0;
  if (-1 < iVar5) {
    _thread_depress_abort(iVar1);
    uVar6 = 0;
  }
locret_F0072A38:
  return CONCAT44(param_2,uVar6);
}

