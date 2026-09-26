
/* WARNING: Removing unreachable block (ram,0xf0063e0c) */
/* WARNING: Removing unreachable block (ram,0xf0063de4) */
/* WARNING: Removing unreachable block (ram,0xf0063d38) */
/* WARNING: Removing unreachable block (ram,0xf0063d80) */
/* WARNING: Removing unreachable block (ram,0xf0063df0) */
/* WARNING: Removing unreachable block (ram,0xf0063db4) */
/* WARNING: Removing unreachable block (ram,0xf0063d18) */

undefined8 _exception(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar5;
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
  if (param_1 == 0) {
    _panic(aException);
  }
  *(code **)(iVar1 + 0x38) = _thread_exception_return;
  do {
    do {
    } while (*(int *)(iVar1 + 0xa8) != 0);
    piVar5 = (int *)(iVar1 + 0xa8);
    _simple_lock_try();
  } while (piVar5 == (int *)0x0);
  piVar5 = *(int **)(iVar1 + 0xb4);
  if ((piVar5 == (int *)0x0) || (piVar5 == (int *)0xffffffff)) {
    *(undefined4 *)(iVar1 + 0xa8) = 0;
  }
  else {
    do {
      do {
      } while (*piVar5 != 0);
      piVar2 = piVar5;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *(undefined4 *)(iVar1 + 0xa8) = 0;
    if (piVar5[2] < 0) {
      piVar5[1] = piVar5[1] + 1;
      piVar5[7] = piVar5[7] + 1;
      *piVar5 = 0;
      *(int *)(iVar1 + 200) = param_1;
      *(undefined4 *)(iVar1 + 0xcc) = param_2;
      *(undefined4 *)(iVar1 + 0xd0) = param_3;
      iVar3 = iVar1;
      _retrieve_thread_self_fast(iVar1);
      uVar4 = *(undefined4 *)(iVar1 + 0xc);
      _retrieve_task_self_fast(uVar4);
      _exception_raise(piVar5,iVar3,uVar4,param_1,param_2,param_3);
      goto locret_F0063E14;
    }
    *piVar5 = 0;
  }
  _exception_try_task(param_1,param_2,param_3);
locret_F0063E14:
  return CONCAT44(param_2,param_1);
}

