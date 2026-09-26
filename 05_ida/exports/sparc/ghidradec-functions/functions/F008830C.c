
/* WARNING: Removing unreachable block (ram,0xf008840c) */
/* WARNING: Removing unreachable block (ram,0xf00883e8) */
/* WARNING: Removing unreachable block (ram,0xf0088464) */
/* WARNING: Removing unreachable block (ram,0xf0088310) */

undefined8 sub_F008830C(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
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
  _vm_page_remove(param_1);
  uVar3 = param_1[7];
  if ((uVar3 & 0x1000) == 0) {
    if ((uVar3 & 0x4000) != 0) {
      iVar5 = *param_1;
      piVar4 = (int *)param_1[1];
      *(int **)(iVar5 + 4) = piVar4;
      if (piVar4 != &_vm_page_queue_active) {
        *piVar4 = iVar5;
        iVar5 = _vm_page_queue_active;
      }
      _vm_page_queue_active = iVar5;
      param_1[7] = param_1[7] & 0xffffbfff;
      _vm_page_active_count = _vm_page_active_count + -1;
      uVar3 = param_1[7];
    }
    if ((uVar3 & 0x8000) != 0) {
      iVar5 = *param_1;
      piVar4 = (int *)param_1[1];
      *(int **)(iVar5 + 4) = piVar4;
      if (piVar4 != &_vm_page_queue_inactive) {
        *piVar4 = iVar5;
        iVar5 = _vm_page_queue_inactive;
      }
      _vm_page_queue_inactive = iVar5;
      param_1[7] = param_1[7] & 0xffff7fff;
      _vm_page_inactive_count = _vm_page_inactive_count + -1;
    }
    uVar1 = 0x10000000;
    if ((param_1[8] & 0x10000000U) == 0) {
      _spltty();
      do {
        do {
        } while (_vm_page_queue_free_lock != 0);
        puVar2 = &_vm_page_queue_free_lock;
        _simple_lock_try();
      } while (puVar2 == (undefined4 *)0x0);
      _vm_page_queue_free[1] = (int)param_1;
      *param_1 = (int)_vm_page_queue_free;
      param_1[1] = (int)&_vm_page_queue_free;
      _vm_page_queue_free = param_1;
      param_1[7] = param_1[7] | 0x1000;
      _vm_page_queue_free_lock = 0;
      _vm_page_free_count = _vm_page_free_count + 1;
      _splx(uVar1);
    }
  }
  return CONCAT44(param_2,param_1);
}
