
/* WARNING: Removing unreachable block (ram,0xf0073830) */
/* WARNING: Removing unreachable block (ram,0xf0073808) */
/* WARNING: Removing unreachable block (ram,0xf00737f0) */
/* WARNING: Removing unreachable block (ram,0xf0073814) */
/* WARNING: Removing unreachable block (ram,0xf0073864) */
/* WARNING: Removing unreachable block (ram,0xf00737c4) */

sqword _task_halt(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int *piVar4;
  int *piVar5;
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
  
  iVar2 = _active_threads;
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
    do {
    } while (*param_1 != 0);
    piVar3 = param_1;
    _simple_lock_try();
  } while (piVar3 == (int *)0x0);
  piVar4 = (int *)param_1[7];
  iVar1 = (int)piVar4 - iVar2;
  piVar3 = (int *)0x0;
  while (param_1 + 7 != piVar4) {
    if (iVar1 == 0) {
      piVar5 = (int *)piVar4[4];
      piVar4 = piVar3;
    }
    else {
      _thread_reference(piVar4);
      *param_1 = 0;
      if (piVar3 != (int *)0x0) {
        _thread_deallocate(piVar3);
      }
      _thread_halt(piVar4,1);
      do {
        do {
        } while (*param_1 != 0);
        piVar3 = param_1;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      piVar5 = (int *)piVar4[4];
    }
    iVar1 = (int)piVar5 - iVar2;
    piVar3 = piVar4;
    piVar4 = piVar5;
  }
  *param_1 = 0;
  if (piVar3 != (int *)0x0) {
    _thread_deallocate(piVar3);
  }
  return (qword)param_2 << 0x20;
}
