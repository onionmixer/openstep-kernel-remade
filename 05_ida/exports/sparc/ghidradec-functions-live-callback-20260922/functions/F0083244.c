
/* WARNING: Removing unreachable block (ram,0xf0083484) */
/* WARNING: Removing unreachable block (ram,0xf0083430) */
/* WARNING: Removing unreachable block (ram,0xf00833cc) */
/* WARNING: Removing unreachable block (ram,0xf00833a0) */
/* WARNING: Removing unreachable block (ram,0xf0083314) */
/* WARNING: Removing unreachable block (ram,0xf00832cc) */
/* WARNING: Removing unreachable block (ram,0xf0083328) */
/* WARNING: Removing unreachable block (ram,0xf00833b8) */
/* WARNING: Removing unreachable block (ram,0xf00833ec) */
/* WARNING: Removing unreachable block (ram,0xf0083448) */
/* WARNING: Removing unreachable block (ram,0xf008349c) */
/* WARNING: Removing unreachable block (ram,0xf00832a0) */

undefined8 _vm_fault_wire_fast(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar9;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar10;
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
  DAT_f013c264._0_4_ = DAT_f013c264._0_4_ + 1;
  if ((*(uint *)(param_3 + 0x18) & 0xa0000000) != 0) {
    uVar8 = 5;
    goto locret_F00834A8;
  }
  uVar7 = *(uint *)(param_3 + 0x1c);
  iVar1 = *(int *)(param_3 + 8);
  iVar6 = *(int *)(param_3 + 0x14);
  iVar9 = *(int *)(param_3 + 0x10);
  do {
    do {
    } while (*(int *)(iVar9 + 0x10) != 0);
    piVar2 = (int *)(iVar9 + 0x10);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  *(sword *)(iVar9 + 0x18) = *(sword *)(iVar9 + 0x18) + 1;
  *(sword *)(iVar9 + 0x44) = *(sword *)(iVar9 + 0x44) + 1;
  iVar3 = iVar9;
  _vm_page_lookup(iVar9,(param_2 - iVar1) + iVar6);
  if (((iVar3 == 0) || ((*(uint *)(iVar3 + 0x20) & 0x84000000) != 0)) ||
     ((uVar7 & *(uint *)(iVar3 + 0x28)) != 0)) {
loc_F00833DC:
    *(undefined4 *)(iVar9 + 0x10) = 0;
    *(sword *)(iVar9 + 0x44) = *(sword *)(iVar9 + 0x44) + -1;
    _vm_object_deallocate();
    uVar8 = 5;
  }
  else {
    do {
      do {
      } while (_vm_page_queue_lock != 0);
      puVar4 = &_vm_page_queue_lock;
      _simple_lock_try();
    } while (puVar4 == (undefined4 *)0x0);
    _vm_page_wire(iVar3);
    _vm_page_queue_lock = 0;
    uVar5 = *(uint *)(iVar3 + 0x20);
    *(uint *)(iVar3 + 0x20) = uVar5 & 0xfbffffff | 0x80000000;
    if (*(int *)(iVar9 + 0x1c) == 0) {
      bVar10 = (uVar7 & 2) == 0;
    }
    else {
      bVar10 = (uVar7 & 2) == 0;
      if (!bVar10) {
        *(uint *)(iVar3 + 0x20) = uVar5 & 0x7bffffff;
        if ((uVar5 & 0x40000000) != 0) {
          *(uint *)(iVar3 + 0x20) = uVar5 & 0x3bffffff;
          _thread_wakeup_prim(iVar3,0,0);
        }
        do {
          do {
          } while (_vm_page_queue_lock != 0);
          puVar4 = &_vm_page_queue_lock;
          _simple_lock_try();
        } while (puVar4 == (undefined4 *)0x0);
        _vm_page_unwire(iVar3);
        _vm_page_queue_lock = 0;
        goto loc_F00833DC;
      }
      *(uint *)(iVar3 + 0x20) = uVar5 & 0xfbffffff | 0x80200000;
    }
    if (!bVar10) {
      *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xffdfffff;
    }
    *(undefined4 *)(iVar9 + 0x10) = 0;
    _pmap_enter(*(undefined4 *)(param_1 + 0x24),param_2,*(undefined4 *)(iVar3 + 0x24),uVar7,1);
    do {
      do {
      } while (*(int *)(iVar9 + 0x10) != 0);
      piVar2 = (int *)(iVar9 + 0x10);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    uVar7 = *(uint *)(iVar3 + 0x20);
    *(uint *)(iVar3 + 0x20) = uVar7 & 0x7fffffff;
    if ((uVar7 & 0x40000000) != 0) {
      *(uint *)(iVar3 + 0x20) = uVar7 & 0x3fffffff;
      _thread_wakeup_prim(iVar3,0,0);
    }
    *(undefined4 *)(iVar9 + 0x10) = 0;
    *(sword *)(iVar9 + 0x44) = *(sword *)(iVar9 + 0x44) + -1;
    _vm_object_deallocate();
    uVar8 = 0;
  }
locret_F00834A8:
  return CONCAT44(param_2,uVar8);
}

