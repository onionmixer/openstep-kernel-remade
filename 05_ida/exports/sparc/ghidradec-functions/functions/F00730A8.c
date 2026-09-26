
/* WARNING: Removing unreachable block (ram,0xf0073144) */
/* WARNING: Removing unreachable block (ram,0xf0073134) */
/* WARNING: Removing unreachable block (ram,0xf0073120) */
/* WARNING: Removing unreachable block (ram,0xf007310c) */
/* WARNING: Removing unreachable block (ram,0xf007312c) */
/* WARNING: Removing unreachable block (ram,0xf007313c) */
/* WARNING: Removing unreachable block (ram,0xf0073154) */
/* WARNING: Removing unreachable block (ram,0xf00730c8) */

undefined8 _task_deallocate(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
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
  if (param_1 != (int *)0x0) {
    do {
      do {
      } while (*param_1 != 0);
      piVar1 = param_1;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    iVar2 = param_1[1];
    *param_1 = 0;
    param_1[1] = iVar2 + -1;
    if (iVar2 + -1 == 0) {
      iVar2 = param_1[0xb];
      do {
        do {
        } while (*(int *)(iVar2 + 0x158) != 0);
        piVar1 = (int *)(iVar2 + 0x158);
        _simple_lock_try();
      } while (piVar1 == (int *)0x0);
      _pset_remove_task(iVar2,param_1);
      *(undefined4 *)(iVar2 + 0x158) = 0;
      _pset_deallocate(iVar2);
      _vm_map_deallocate(param_1[3]);
      _ipc_space_release(param_1[0x22]);
      _utask_free(param_1[0xe]);
      _zfree(_task_zone,param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}
