
/* WARNING: Removing unreachable block (ram,0xf00696a4) */
/* WARNING: Removing unreachable block (ram,0xf00696bc) */
/* WARNING: Removing unreachable block (ram,0xf00695f4) */

undefined8 _lock_try_read_to_write(int *param_1,undefined4 param_2)

{
  sword sVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
    } while (param_1[2] != 0);
    piVar2 = param_1 + 2;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if (*param_1 == _active_threads) {
    param_1[2] = 0;
    *(sword *)(param_1 + 1) = *(sword *)(param_1 + 1) + -1;
    uVar5 = 1;
    param_1[1] = param_1[1] & 0xfffff000U | (param_1[1] & 0xfffU) + 1 & 0xfff;
  }
  else if ((param_1[1] & 0x8000U) == 0) {
    param_1[1] = param_1[1] | 0x8000;
    sVar1 = *(sword *)(param_1 + 1);
    *(sword *)(param_1 + 1) = sVar1 + -1;
    piVar2 = param_1 + 2;
    if (sVar1 != 1) {
      uVar4 = param_1[1];
      while( true ) {
        param_1[1] = uVar4 | 0x2000;
        _thread_sleep(param_1,piVar2,0);
        do {
          do {
          } while (*piVar2 != 0);
          piVar3 = piVar2;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        if (*(sword *)(param_1 + 1) == 0) break;
        uVar4 = param_1[1];
      }
    }
    param_1[2] = 0;
    uVar5 = 1;
  }
  else {
    param_1[2] = 0;
    uVar5 = 0;
  }
  return CONCAT44(param_2,uVar5);
}
