
/* WARNING: Removing unreachable block (ram,0xf0068fe8) */
/* WARNING: Removing unreachable block (ram,0xf0068ef8) */
/* WARNING: Removing unreachable block (ram,0xf0068e9c) */
/* WARNING: Removing unreachable block (ram,0xf0068edc) */
/* WARNING: Removing unreachable block (ram,0xf0068fa0) */
/* WARNING: Removing unreachable block (ram,0xf0069004) */
/* WARNING: Removing unreachable block (ram,0xf0068ddc) */

undefined8 _lock_write(int *param_1,undefined4 param_2)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
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
    piVar1 = param_1 + 2;
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  uVar2 = param_1[1];
  if (*param_1 == _active_threads) {
    param_1[2] = 0;
    param_1[1] = uVar2 & 0xfffff000 | (uVar2 & 0xfff) + 1 & 0xfff;
  }
  else {
    if ((uVar2 & 0x4000) == 0) {
      uVar2 = param_1[1];
    }
    else {
      piVar1 = param_1 + 2;
      do {
        iVar4 = _lock_wait_time;
        if (_lock_wait_time < 1) {
          uVar2 = param_1[1];
        }
        else {
          param_1[2] = 0;
          iVar4 = iVar4 + -1;
          if (0 < iVar4) {
            do {
              if ((param_1[1] & 0x4000U) == 0) break;
              iVar4 = iVar4 + -1;
            } while (0 < iVar4);
          }
          do {
            do {
              piVar3 = param_1 + 2;
            } while (*piVar3 != 0);
            _simple_lock_try();
          } while (piVar3 == (int *)0x0);
          uVar2 = param_1[1];
        }
        if ((uVar2 & 0x5000) == 0x5000) {
          param_1[1] = uVar2 | 0x2000;
          _thread_sleep(param_1,piVar1,0);
          do {
            do {
            } while (*piVar1 != 0);
            piVar3 = piVar1;
            _simple_lock_try();
          } while (piVar3 == (int *)0x0);
          uVar2 = param_1[1];
        }
        else {
          uVar2 = param_1[1];
        }
      } while ((uVar2 & 0x4000) != 0);
      uVar2 = param_1[1];
    }
    param_1[1] = uVar2 | 0x4000;
    if ((uVar2 & 0xffff8000) != 0) {
      piVar1 = param_1 + 2;
      do {
        iVar4 = _lock_wait_time;
        if (_lock_wait_time < 1) {
          uVar2 = param_1[1];
        }
        else {
          param_1[2] = 0;
          iVar4 = iVar4 + -1;
          if (0 < iVar4) {
            do {
              if ((param_1[1] & 0xffff8000U) == 0) break;
              iVar4 = iVar4 + -1;
            } while (0 < iVar4);
          }
          do {
            do {
              piVar3 = param_1 + 2;
            } while (*piVar3 != 0);
            _simple_lock_try();
          } while (piVar3 == (int *)0x0);
          uVar2 = param_1[1];
        }
        if ((uVar2 & 0x1000) == 0) {
          uVar2 = param_1[1];
        }
        else if ((uVar2 & 0xffff8000) == 0) {
          uVar2 = param_1[1];
        }
        else {
          param_1[1] = uVar2 | 0x2000;
          _thread_sleep(param_1,piVar1,0);
          do {
            do {
            } while (*piVar1 != 0);
            piVar3 = piVar1;
            _simple_lock_try();
          } while (piVar3 == (int *)0x0);
          uVar2 = param_1[1];
        }
      } while ((uVar2 & 0xffff8000) != 0);
    }
    param_1[2] = 0;
  }
  return CONCAT44(param_2,param_1);
}
