
/* WARNING: Removing unreachable block (ram,0xf005b81c) */
/* WARNING: Removing unreachable block (ram,0xf005b878) */
/* WARNING: Removing unreachable block (ram,0xf005b9c0) */
/* WARNING: Removing unreachable block (ram,0xf005b978) */
/* WARNING: Removing unreachable block (ram,0xf005b8ec) */
/* WARNING: Removing unreachable block (ram,0xf005b938) */
/* WARNING: Removing unreachable block (ram,0xf005b95c) */
/* WARNING: Removing unreachable block (ram,0xf005b910) */
/* WARNING: Removing unreachable block (ram,0xf005b984) */
/* WARNING: Removing unreachable block (ram,0xf005b864) */
/* WARNING: Removing unreachable block (ram,0xf005b8c4) */
/* WARNING: Removing unreachable block (ram,0xf005b838) */
/* WARNING: Removing unreachable block (ram,0xf005b7d8) */

undefined8 _ipc_pset_move(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
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
    } while (*param_2 != 0);
    piVar2 = param_2;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  piVar2 = (int *)param_2[0xc];
  if (piVar2 == param_3) {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else if (piVar2 == (int *)0x0) {
    do {
      do {
      } while (*param_3 != 0);
      piVar1 = param_3;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *(undefined4 *)(param_1 + 8) = 0;
    _ipc_pset_add(param_3,param_2);
    *param_3 = 0;
  }
  else if (param_3 == (int *)0x0) {
    *(undefined4 *)(param_1 + 8) = 0;
    do {
      do {
      } while (*piVar2 != 0);
      piVar1 = piVar2;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    _ipc_pset_remove(piVar2,param_2);
    if (piVar2[2] < 0) {
      *piVar2 = 0;
    }
    else {
      *piVar2 = 0;
      if (piVar2[1] == 0) {
        _zfree((&_ipc_object_zones)[(piVar2[2] & 0x7fffffffU) >> 0x10],piVar2);
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = (int *)0x0;
      }
    }
  }
  else {
    if (piVar2 < param_3) {
      do {
        do {
        } while (*piVar2 != 0);
        piVar1 = piVar2;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      do {
        do {
        } while (*param_3 != 0);
        piVar1 = param_3;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
    }
    else {
      do {
        do {
        } while (*param_3 != 0);
        piVar1 = param_3;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      do {
        do {
        } while (*piVar2 != 0);
        piVar1 = piVar2;
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
    }
    *(undefined4 *)(param_1 + 8) = 0;
    _ipc_pset_remove(piVar2,param_2);
    _ipc_pset_add(param_3,param_2);
    *param_3 = 0;
    *piVar2 = 0;
    if (piVar2[1] == 0) {
      _zfree((&_ipc_object_zones)[(piVar2[2] & 0x7fffffffU) >> 0x10],piVar2);
    }
  }
  *param_2 = 0;
  uVar3 = 0;
  if (param_3 == (int *)0x0) {
    uVar3 = (piVar2 != (int *)0x0) - 1 & 0xc;
  }
  return CONCAT44(param_2,uVar3);
}
