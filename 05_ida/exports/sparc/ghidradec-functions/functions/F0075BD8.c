
/* WARNING: Removing unreachable block (ram,0xf0075c5c) */
/* WARNING: Removing unreachable block (ram,0xf0075c18) */
/* WARNING: Removing unreachable block (ram,0xf0075c74) */
/* WARNING: Removing unreachable block (ram,0xf0075bfc) */

undefined8 _thread_priority(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar3;
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
  uVar3 = 0;
  if ((param_1 == 0) || (0x1f < param_2)) {
    uVar3 = 4;
  }
  else {
    iVar1 = param_1;
    _splusclock();
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar2 = (int *)(param_1 + 0x20);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    if (*(int *)(param_1 + 0x54) < (int)param_2) {
      uVar3 = 5;
    }
    else {
      if (*(int *)(param_1 + 100) < 0) {
        *(uint *)(param_1 + 0x50) = param_2;
        _compute_priority(param_1,1);
      }
      else {
        *(uint *)(param_1 + 100) = param_2;
      }
      if (param_3 != 0) {
        *(uint *)(param_1 + 0x54) = param_2;
      }
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    _splx(iVar1);
  }
  return CONCAT44(param_2,uVar3);
}
