
/* WARNING: Removing unreachable block (ram,0xf00690e0) */
/* WARNING: Removing unreachable block (ram,0xf006904c) */

undefined8 _lock_done(int param_1,undefined4 param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
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
    } while (*(int *)(param_1 + 8) != 0);
    piVar1 = (int *)(param_1 + 8);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (*(sword *)(param_1 + 4) == 0) {
    uVar3 = *(uint *)(param_1 + 4);
    if ((uVar3 & 0xfff) == 0) {
      uVar2 = 0x8000;
      if ((uVar3 & 0x8000) == 0) {
        uVar2 = 0x4000;
      }
      *(uint *)(param_1 + 4) = uVar3 & ~uVar2;
    }
    else {
      *(uint *)(param_1 + 4) = uVar3 & 0xfffff000 | (uVar3 & 0xfff) - 1 & 0xfff;
    }
  }
  else {
    *(sword *)(param_1 + 4) = *(sword *)(param_1 + 4) + -1;
  }
  if ((*(uint *)(param_1 + 4) & 0xffff2000) == 0x2000) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffdfff;
    _thread_wakeup_prim(param_1,0,0);
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return CONCAT44(param_2,param_1);
}
