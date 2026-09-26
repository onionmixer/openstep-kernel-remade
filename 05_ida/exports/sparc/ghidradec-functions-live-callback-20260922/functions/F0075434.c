
/* WARNING: Removing unreachable block (ram,0xf007549c) */
/* WARNING: Removing unreachable block (ram,0xf0075454) */
/* WARNING: Removing unreachable block (ram,0xf00754a8) */
/* WARNING: Removing unreachable block (ram,0xf0075438) */

undefined8 _thread_release(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
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
  iVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar2 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  iVar3 = *(int *)(param_1 + 0x40) + -1;
  *(int *)(param_1 + 0x40) = iVar3;
  if (iVar3 == 0) {
    uVar4 = *(uint *)(param_1 + 0x4c);
    uVar5 = uVar4 & 0xffffffed;
    *(uint *)(param_1 + 0x4c) = uVar5;
    if ((uVar4 & 5) == 0) {
      *(uint *)(param_1 + 0x4c) = uVar5 | 4;
      _thread_setrun(param_1,1);
    }
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}

