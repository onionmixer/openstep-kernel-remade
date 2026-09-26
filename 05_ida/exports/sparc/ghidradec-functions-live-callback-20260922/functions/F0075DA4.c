
/* WARNING: Removing unreachable block (ram,0xf0075ec4) */
/* WARNING: Removing unreachable block (ram,0xf0075e9c) */
/* WARNING: Removing unreachable block (ram,0xf0075e34) */
/* WARNING: Removing unreachable block (ram,0xf0075de8) */
/* WARNING: Removing unreachable block (ram,0xf0075e4c) */
/* WARNING: Removing unreachable block (ram,0xf0075eb4) */
/* WARNING: Removing unreachable block (ram,0xf0075ed0) */
/* WARNING: Removing unreachable block (ram,0xf0075dcc) */

undefined8 _thread_policy(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar5;
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
  uVar5 = 0;
  if ((param_1 == 0) || (uVar2 = param_2 - 1, 3 < uVar2)) {
    uVar5 = 4;
  }
  else {
    _splusclock();
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar3 = (int *)(param_1 + 0x20);
      _simple_lock_try();
      uVar1 = _tick;
    } while (piVar3 == (int *)0x0);
    if (param_2 == *(uint *)(param_1 + 0x60)) {
      if (param_2 == 2) {
        param_3 = param_3 * 1000;
        iVar4 = param_3;
        rem(param_3,_tick);
        if (iVar4 != 0) {
          param_3 = param_3 + uVar1;
        }
        div(param_3,uVar1);
        *(int *)(param_1 + 0x5c) = param_3;
        param_2 = uVar1;
      }
    }
    else if ((*(uint *)(*(int *)(param_1 + 400) + 0x168) & param_2) == 0) {
      uVar5 = 5;
    }
    else {
      *(uint *)(param_1 + 0x60) = param_2;
      uVar1 = _tick;
      if (param_2 == 2) {
        param_3 = param_3 * 1000;
        iVar4 = param_3;
        rem(param_3,_tick);
        if (iVar4 != 0) {
          param_3 = param_3 + uVar1;
        }
        div(param_3,uVar1);
        *(int *)(param_1 + 0x5c) = param_3;
        param_2 = uVar1;
      }
      _compute_priority(param_1,1);
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    _splx(uVar2);
  }
  return CONCAT44(param_2,uVar5);
}

