
/* WARNING: Removing unreachable block (ram,0xf0075820) */
/* WARNING: Removing unreachable block (ram,0xf00757d8) */
/* WARNING: Removing unreachable block (ram,0xf00757ac) */
/* WARNING: Removing unreachable block (ram,0xf0075750) */
/* WARNING: Removing unreachable block (ram,0xf0075948) */
/* WARNING: Removing unreachable block (ram,0xf0075904) */
/* WARNING: Removing unreachable block (ram,0xf0075940) */
/* WARNING: Removing unreachable block (ram,0xf0075988) */
/* WARNING: Removing unreachable block (ram,0xf0075770) */
/* WARNING: Removing unreachable block (ram,0xf00757bc) */
/* WARNING: Removing unreachable block (ram,0xf00757f0) */
/* WARNING: Removing unreachable block (ram,0xf00758bc) */
/* WARNING: Removing unreachable block (ram,0xf00758e4) */

undefined8 _thread_info(int param_1,int param_2,undefined4 *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
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
  if (param_1 == 0) {
    uVar7 = 4;
    goto locret_F00759A4;
  }
  if (param_2 == 1) {
    uVar1 = *param_4;
    if (uVar1 < 0xb) {
      uVar7 = 4;
      goto locret_F00759A4;
    }
    _splusclock();
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar4 = (int *)(param_1 + 0x20);
      _simple_lock_try();
    } while (piVar4 == (int *)0x0);
    if (((*(uint *)(param_1 + 0x4c) & 4) == 0) && (*(int *)(param_1 + 0x70) != _sched_tick)) {
      _update_priority(param_1);
    }
    _thread_read_times(param_1,param_3,param_3 + 2);
    param_3[5] = *(undefined4 *)(param_1 + 0x50);
    param_3[6] = *(undefined4 *)(param_1 + 0x58);
    iVar2 = *(int *)(param_1 + 0x68);
    .udiv(iVar2,1000);
    param_3[4] = iVar2;
    iVar2 = iVar2 * 3;
    .div(iVar2,5);
    param_3[4] = iVar2;
    iVar2 = iVar2 * 1000000;
    .div(iVar2,_sched_usec);
    param_3[4] = iVar2;
    uVar3 = *(uint *)(param_1 + 0x4c);
    uVar6 = 1;
    if ((uVar3 & 0x100) == 0) {
      uVar6 = uVar3 >> 6 & 2;
      uVar3 = *(uint *)(param_1 + 0x4c);
    }
    uVar5 = 5;
    if (((((uVar3 & 0x10) == 0) && (uVar5 = 1, (uVar3 & 4) == 0)) && (uVar5 = 4, (uVar3 & 8) == 0))
       && (uVar5 = 2, (uVar3 & 2) == 0)) {
      uVar5 = -(uVar3 & 1) & 3;
    }
    param_3[7] = uVar5;
    param_3[8] = uVar6;
    param_3[9] = *(undefined4 *)(param_1 + 0x8c);
    if (uVar5 == 1) {
      param_3[10] = 0;
    }
    else {
      param_3[10] = _sched_tick - *(int *)(param_1 + 0x70);
    }
    *(undefined4 *)(param_1 + 0x20) = 0;
    _splx(uVar1);
    uVar1 = 0xb;
  }
  else {
    if (param_2 != 2) {
      uVar7 = 4;
      goto locret_F00759A4;
    }
    uVar1 = *param_4;
    if (uVar1 < 7) {
      uVar7 = 4;
      goto locret_F00759A4;
    }
    _splusclock();
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar4 = (int *)(param_1 + 0x20);
      _simple_lock_try();
    } while (piVar4 == (int *)0x0);
    *param_3 = *(undefined4 *)(param_1 + 0x60);
    if ((*(int *)(param_1 + 0x60) == 2) || (*(int *)(param_1 + 0x60) == 4)) {
      uVar7 = *(undefined4 *)(param_1 + 0x5c);
      .umul(uVar7,_tick);
      .div();
      param_3[1] = uVar7;
    }
    else {
      param_3[1] = 0;
    }
    param_3[2] = *(undefined4 *)(param_1 + 0x50);
    param_3[3] = *(undefined4 *)(param_1 + 0x54);
    param_3[4] = *(undefined4 *)(param_1 + 0x58);
    param_3[5] = ~*(uint *)(param_1 + 100) >> 0x1f;
    param_3[6] = *(undefined4 *)(param_1 + 100);
    *(undefined4 *)(param_1 + 0x20) = 0;
    _splx(uVar1);
    uVar1 = 7;
  }
  param_2 = param_1 + 0x20;
  *param_4 = uVar1;
  uVar7 = 0;
locret_F00759A4:
  return CONCAT44(param_2,uVar7);
}
