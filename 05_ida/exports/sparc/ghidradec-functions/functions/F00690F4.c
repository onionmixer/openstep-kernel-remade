
/* WARNING: Removing unreachable block (ram,0xf00691f4) */
/* WARNING: Removing unreachable block (ram,0xf00691ac) */
/* WARNING: Removing unreachable block (ram,0xf0069210) */
/* WARNING: Removing unreachable block (ram,0xf006910c) */

undefined8 _lock_read(int *param_1,undefined4 param_2)

{
  sword sVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
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
    } while (param_1[2] != 0);
    piVar2 = param_1 + 2;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if (*param_1 != _active_threads) {
    if ((param_1[1] & 0xc000U) == 0) {
      sVar1 = *(sword *)(param_1 + 1);
      goto loc_F0069238;
    }
    piVar2 = param_1 + 2;
    do {
      iVar5 = _lock_wait_time;
      if (_lock_wait_time < 1) {
        uVar4 = param_1[1];
      }
      else {
        param_1[2] = 0;
        iVar5 = iVar5 + -1;
        if (0 < iVar5) {
          do {
            if ((param_1[1] & 0xc000U) == 0) break;
            iVar5 = iVar5 + -1;
          } while (0 < iVar5);
        }
        do {
          do {
            piVar3 = param_1 + 2;
          } while (*piVar3 != 0);
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        uVar4 = param_1[1];
      }
      if ((uVar4 & 0x1000) == 0) {
        uVar4 = param_1[1];
      }
      else if ((uVar4 & 0xc000) == 0) {
        uVar4 = param_1[1];
      }
      else {
        param_1[1] = uVar4 | 0x2000;
        _thread_sleep(param_1,piVar2,0);
        do {
          do {
          } while (*piVar2 != 0);
          piVar3 = piVar2;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        uVar4 = param_1[1];
      }
    } while ((uVar4 & 0xc000) != 0);
  }
  sVar1 = *(sword *)(param_1 + 1);
loc_F0069238:
  param_1[2] = 0;
  *(sword *)(param_1 + 1) = sVar1 + 1;
  return CONCAT44(param_2,param_1);
}
