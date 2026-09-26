
/* WARNING: Removing unreachable block (ram,0xf00736d4) */
/* WARNING: Removing unreachable block (ram,0xf00736ac) */
/* WARNING: Removing unreachable block (ram,0xf0073694) */
/* WARNING: Removing unreachable block (ram,0xf00736b8) */
/* WARNING: Removing unreachable block (ram,0xf0073708) */
/* WARNING: Removing unreachable block (ram,0xf0073644) */

undefined8 _task_dowait(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  int *piVar5;
  int *piVar6;
  undefined4 unaff_l3;
  undefined4 uVar7;
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
  
  piVar1 = _active_threads;
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
  uVar7 = 0;
  piVar6 = param_1 + 7;
  piVar5 = (int *)0x0;
  do {
    do {
    } while (*param_1 != 0);
    piVar2 = param_1;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if (piVar6 != (int *)*piVar6) {
    iVar3 = param_1[2];
    piVar2 = (int *)*piVar6;
    while ((iVar3 != 0 || (param_2 != 0))) {
      if (piVar2 == piVar1) {
        piVar4 = (int *)piVar2[4];
      }
      else {
        _thread_reference(piVar2);
        *param_1 = 0;
        if (piVar5 != (int *)0x0) {
          _thread_deallocate(piVar5);
        }
        _thread_dowait(piVar2,1);
        do {
          do {
          } while (*param_1 != 0);
          piVar5 = param_1;
          _simple_lock_try();
        } while (piVar5 == (int *)0x0);
        piVar4 = (int *)piVar2[4];
        piVar5 = piVar2;
      }
      if (piVar6 == piVar4) goto loc_F00736F8;
      iVar3 = param_1[2];
      piVar2 = piVar4;
    }
    uVar7 = 5;
  }
loc_F00736F8:
  *param_1 = 0;
  if (piVar5 != (int *)0x0) {
    _thread_deallocate(piVar5);
  }
  return CONCAT44(param_2,uVar7);
}
