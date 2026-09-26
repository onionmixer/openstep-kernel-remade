
/* WARNING: Removing unreachable block (ram,0xf0064028) */
/* WARNING: Removing unreachable block (ram,0xf0063fcc) */
/* WARNING: Removing unreachable block (ram,0xf006401c) */
/* WARNING: Removing unreachable block (ram,0xf0064044) */
/* WARNING: Removing unreachable block (ram,0xf0063f84) */

undefined8 _exception_try_task(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar5;
  int iVar6;
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
  
  iVar3 = _active_threads;
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
  iVar6 = *(int *)(_active_threads + 0xc);
  uVar4 = param_2;
  do {
    do {
    } while (*(int *)(iVar6 + 100) != 0);
    piVar1 = (int *)(iVar6 + 100);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  piVar5 = *(int **)(iVar6 + 0x70);
  if ((piVar5 == (int *)0x0) || (piVar5 == (int *)0xffffffff)) {
    *(undefined4 *)(iVar6 + 100) = 0;
    _exception_no_server();
    return CONCAT44(uVar4,piVar1);
  }
  do {
    do {
    } while (*piVar5 != 0);
    piVar1 = piVar5;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  *(undefined4 *)(iVar6 + 100) = 0;
  iVar2 = piVar5[2];
  if (iVar2 < 0) {
    piVar5[1] = piVar5[1] + 1;
    piVar5[7] = piVar5[7] + 1;
    *piVar5 = 0;
    *(undefined4 *)(iVar3 + 200) = 0;
    _retrieve_thread_self_fast(iVar3);
    _retrieve_task_self_fast(iVar6);
    _exception_raise(piVar5,iVar3,iVar6,param_1,param_2,param_3);
    return CONCAT44(param_2,param_1);
  }
  *piVar5 = 0;
  _exception_no_server();
  return CONCAT44(uVar4,iVar2);
}
