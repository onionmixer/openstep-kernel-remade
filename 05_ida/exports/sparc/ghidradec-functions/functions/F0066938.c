
/* WARNING: Removing unreachable block (ram,0xf0066a78) */
/* WARNING: Removing unreachable block (ram,0xf0066a18) */
/* WARNING: Removing unreachable block (ram,0xf00669f0) */
/* WARNING: Removing unreachable block (ram,0xf0066994) */
/* WARNING: Removing unreachable block (ram,0xf0066958) */
/* WARNING: Removing unreachable block (ram,0xf00669c0) */
/* WARNING: Removing unreachable block (ram,0xf00669fc) */
/* WARNING: Removing unreachable block (ram,0xf0066a84) */
/* WARNING: Removing unreachable block (ram,0xf0066a90) */
/* WARNING: Removing unreachable block (ram,0xf006693c) */

undefined8 _thread_handoff(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  iVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_3 + 0x20) != 0);
    piVar2 = (int *)(param_3 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if ((*(int *)(param_1 + 0x30) == _active_stacks) || (*(int *)(param_3 + 0x4c) != 0x101)) {
    *(undefined4 *)(param_3 + 0x20) = 0;
    _splx(iVar1);
    uVar3 = 0;
    _c_thread_handoff_misses = _c_thread_handoff_misses + 1;
    goto locret_F0066AAC;
  }
  if (*(int *)(param_3 + 0x14c) != 0) {
    _reset_timeout(param_3 + 0x118);
  }
  *(undefined4 *)(param_3 + 0x4c) = 4;
  *(undefined4 *)(param_3 + 0x20) = 0;
  _need_ast = _need_ast & 0xfffffffc | *(uint *)(param_3 + 0x18c);
  _switch_unix_context(param_3);
  _stack_handoff(param_1,param_3);
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar2 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  *(undefined4 *)(param_1 + 0x34) = param_2;
  if (*(int *)(param_1 + 0x4c) == 4) {
    *(undefined4 *)(param_1 + 0x4c) = 0x101;
loc_F0066A8C:
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    if (*(int *)(param_1 + 0x4c) != 6) {
      _panic(aThreadHandoff);
      goto loc_F0066A8C;
    }
    *(undefined4 *)(param_1 + 0x4c) = 0x103;
    if (*(int *)(param_1 + 0x48) == 0) goto loc_F0066A8C;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    _thread_wakeup_prim(param_1 + 0x48,0,0);
  }
  _splx(iVar1);
  uVar3 = 1;
  _c_thread_handoff_hits = _c_thread_handoff_hits + 1;
locret_F0066AAC:
  return CONCAT44(param_2,uVar3);
}
