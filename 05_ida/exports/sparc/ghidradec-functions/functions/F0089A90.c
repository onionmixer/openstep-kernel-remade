
/* WARNING: Removing unreachable block (ram,0xf0089c40) */
/* WARNING: Removing unreachable block (ram,0xf0089bf0) */
/* WARNING: Removing unreachable block (ram,0xf0089ba0) */
/* WARNING: Removing unreachable block (ram,0xf0089b50) */
/* WARNING: Removing unreachable block (ram,0xf0089b2c) */
/* WARNING: Removing unreachable block (ram,0xf0089ad8) */
/* WARNING: Removing unreachable block (ram,0xf0089b38) */
/* WARNING: Removing unreachable block (ram,0xf0089b98) */
/* WARNING: Removing unreachable block (ram,0xf0089ba8) */
/* WARNING: Removing unreachable block (ram,0xf0089c18) */
/* WARNING: Removing unreachable block (ram,0xf0089c7c) */
/* WARNING: Removing unreachable block (ram,0xf0089ab4) */

undefined8 sub_F0089A90(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
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
  int iVar5;
  uint uVar6;
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
  iVar5 = *(int *)(param_1 + 0x28);
  do {
    do {
    } while (_vm_page_queue_lock != 0);
    puVar1 = &_vm_page_queue_lock;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  if ((*(uint *)(param_2 + 0x1c) & 0x400) == 0) {
    iVar2 = *(int *)(param_2 + 0x20);
  }
  else {
    iVar2 = *(int *)(param_2 + 0x24);
    _pmap_is_modified();
    if (iVar2 == 0) {
      _vm_page_queue_lock = 0;
      uVar6 = 0;
      goto locret_F0089C98;
    }
    iVar2 = *(int *)(param_2 + 0x20);
  }
  if (iVar2 < 0) {
    _vm_page_queue_lock = 0;
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x40000000;
    _assert_wait(param_2,0);
    *(undefined4 *)(param_1 + 0x10) = 0;
    _thread_block();
    do {
      do {
      } while (*(int *)(param_1 + 0x10) != 0);
      piVar3 = (int *)(param_1 + 0x10);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    uVar6 = 2;
  }
  else {
    *(sword *)(param_1 + 0x44) = *(sword *)(param_1 + 0x44) + 1;
    *(uint *)(param_2 + 0x20) = *(uint *)(param_2 + 0x20) | 0x80000000;
    if ((*(uint *)(param_2 + 0x1c) & 0x8000) != 0) {
      _vm_page_activate(param_2);
    }
    _vm_page_deactivate(param_2);
    _pmap_remove_all(*(undefined4 *)(param_2 + 0x24));
    _vm_page_queue_lock = 0;
    DAT_f013c260._0_4_ = DAT_f013c260._0_4_ + 1;
    if (iVar5 == 0) {
      uVar6 = 1;
      *(sword *)(param_1 + 0x44) = *(sword *)(param_1 + 0x44) + -1;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = 0;
      _vm_pager_put(iVar5,param_2);
      uVar6 = (uint)(iVar5 != 0);
      do {
        do {
        } while (*(int *)(param_1 + 0x10) != 0);
        piVar3 = (int *)(param_1 + 0x10);
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar1 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar1 == (undefined4 *)0x0);
      uVar4 = *(uint *)(param_2 + 0x20);
      *(uint *)(param_2 + 0x20) = uVar4 & 0x7fffffff;
      if ((uVar4 & 0x40000000) != 0) {
        *(uint *)(param_2 + 0x20) = uVar4 & 0x3fffffff;
        _thread_wakeup_prim(param_2,0,0);
      }
      *(sword *)(param_1 + 0x44) = *(sword *)(param_1 + 0x44) + -1;
      _vm_page_queue_lock = 0;
    }
  }
locret_F0089C98:
  return CONCAT44(param_2,uVar6);
}
