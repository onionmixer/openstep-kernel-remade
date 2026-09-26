
/* WARNING: Removing unreachable block (ram,0xf005a8d0) */
/* WARNING: Removing unreachable block (ram,0xf005a878) */
/* WARNING: Removing unreachable block (ram,0xf005a898) */
/* WARNING: Removing unreachable block (ram,0xf005a8ec) */
/* WARNING: Removing unreachable block (ram,0xf005a840) */

undefined8 _ipc_port_lock_mqueue(int param_1,undefined4 param_2)

{
  int *piVar1;
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
  piVar1 = *(int **)(param_1 + 0x30);
  if (piVar1 != (int *)0x0) {
    do {
      do {
      } while (*piVar1 != 0);
      piVar2 = piVar1;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    if (piVar1[2] < 0) {
      do {
        do {
        } while (piVar1[4] != 0);
        piVar2 = piVar1 + 4;
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      *piVar1 = 0;
      piVar1 = piVar1 + 4;
      goto locret_F005A904;
    }
    _ipc_pset_remove(piVar1,param_1);
    *piVar1 = 0;
    if (piVar1[1] == 0) {
      _zfree((&_ipc_object_zones)[(piVar1[2] & 0x7fffffffU) >> 0x10],piVar1);
    }
  }
  do {
    do {
      piVar1 = (int *)(param_1 + 0x40);
    } while (*piVar1 != 0);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  piVar1 = (int *)(param_1 + 0x40);
locret_F005A904:
  return CONCAT44(param_2,piVar1);
}
