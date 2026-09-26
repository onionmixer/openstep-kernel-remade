
/* WARNING: Removing unreachable block (ram,0xf0072ac8) */
/* WARNING: Removing unreachable block (ram,0xf0072a80) */
/* WARNING: Removing unreachable block (ram,0xf0072a5c) */
/* WARNING: Removing unreachable block (ram,0xf0072a64) */
/* WARNING: Removing unreachable block (ram,0xf0072aa4) */
/* WARNING: Removing unreachable block (ram,0xf0072ad4) */
/* WARNING: Removing unreachable block (ram,0xf0072a50) */

undefined8 _thread_depress_priority(int param_1,int param_2)

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
  undefined4 unaff_i1;
  int *piVar3;
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
  piVar3 = (int *)(param_1 + 0x20);
  umul(param_2,_hz);
  param_2 = param_2 + 999;
  udiv(param_2,1000);
  iVar1 = param_2;
  _splusclock();
  do {
    do {
    } while (*piVar3 != 0);
    piVar2 = piVar3;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if (*(int *)(param_1 + 0x184) == 0) {
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  else {
    _reset_timeout(param_1 + 0x150);
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(param_1 + 0x50) = 0;
  if (param_2 != 0) {
    _set_timeout(param_1 + 0x150,param_2);
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  _splx(iVar1);
  return CONCAT44(piVar3,param_1);
}

