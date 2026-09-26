
/* WARNING: Removing unreachable block (ram,0xf005a9d0) */
/* WARNING: Removing unreachable block (ram,0xf005a998) */
/* WARNING: Removing unreachable block (ram,0xf005a960) */
/* WARNING: Removing unreachable block (ram,0xf005a9b8) */
/* WARNING: Removing unreachable block (ram,0xf005a9f4) */
/* WARNING: Removing unreachable block (ram,0xf005a94c) */

undefined8 _ipc_port_clear_receiver(int param_1,undefined4 param_2)

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
  piVar2 = *(int **)(param_1 + 0x30);
  if (piVar2 == (int *)0x0) {
    do {
      do {
      } while (*(int *)(param_1 + 0x40) != 0);
      piVar2 = (int *)(param_1 + 0x40);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    _ipc_mqueue_changed(param_1 + 0x40,0x10004009);
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  else {
    do {
      do {
      } while (*piVar2 != 0);
      piVar1 = piVar2;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    _ipc_pset_remove(piVar2,param_1);
    *piVar2 = 0;
    if (piVar2[1] == 0) {
      _zfree((&_ipc_object_zones)[(piVar2[2] & 0x7fffffffU) >> 0x10],piVar2);
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
  }
  do {
    do {
    } while (*(int *)(param_1 + 0x40) != 0);
    piVar2 = (int *)(param_1 + 0x40);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  return CONCAT44(param_2,param_1);
}
