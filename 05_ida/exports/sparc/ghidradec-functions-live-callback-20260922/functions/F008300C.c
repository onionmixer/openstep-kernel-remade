
/* WARNING: Removing unreachable block (ram,0xf00831d8) */
/* WARNING: Removing unreachable block (ram,0xf008319c) */
/* WARNING: Removing unreachable block (ram,0xf0083160) */
/* WARNING: Removing unreachable block (ram,0xf008313c) */
/* WARNING: Removing unreachable block (ram,0xf00830f8) */
/* WARNING: Removing unreachable block (ram,0xf00830cc) */
/* WARNING: Removing unreachable block (ram,0xf0083088) */
/* WARNING: Removing unreachable block (ram,0xf0083070) */
/* WARNING: Removing unreachable block (ram,0xf00830b4) */
/* WARNING: Removing unreachable block (ram,0xf00830dc) */
/* WARNING: Removing unreachable block (ram,0xf0083128) */
/* WARNING: Removing unreachable block (ram,0xf0083154) */
/* WARNING: Removing unreachable block (ram,0xf0083184) */
/* WARNING: Removing unreachable block (ram,0xf00831c4) */
/* WARNING: Removing unreachable block (ram,0xf0083214) */
/* WARNING: Removing unreachable block (ram,0xf0083028) */

undefined8 _vm_fault_copy_entry(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar7;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  int iVar9;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar10;
  undefined4 unaff_i1;
  undefined4 uVar11;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  int iVar12;
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
  iVar9 = *(int *)(param_4 + 0x10);
  iVar8 = 0;
  iVar12 = *(int *)(param_4 + 0x14);
  iVar1 = *(int *)(param_3 + 0xc) - *(int *)(param_3 + 8);
  _vm_object_allocate();
  uVar7 = *(uint *)(param_3 + 8);
  *(int *)(param_3 + 0x10) = iVar1;
  *(undefined4 *)(param_3 + 0x14) = 0;
  uVar11 = *(undefined4 *)(param_3 + 0x20);
  puVar10 = param_1;
  if (uVar7 < *(uint *)(param_3 + 0xc)) {
    puVar10 = &_vm_page_free_count;
    do {
      do {
        do {
        } while (*(int *)(iVar1 + 0x10) != 0);
        piVar2 = (int *)(iVar1 + 0x10);
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      do {
        iVar3 = iVar1;
        _vm_page_alloc_sequential(iVar1,iVar8,1);
        if (iVar3 == 0) {
          *(undefined4 *)(iVar1 + 0x10) = 0;
          do {
            do {
            } while (_vm_pages_needed_lock != 0);
            puVar4 = &_vm_pages_needed_lock;
            _simple_lock_try();
          } while (puVar4 == (undefined4 *)0x0);
          _thread_wakeup_prim(&_vm_pages_needed,0,0);
          _thread_sleep(&_vm_page_free_count,&_vm_pages_needed_lock,0);
          do {
            do {
            } while (*(int *)(iVar1 + 0x10) != 0);
            piVar2 = (int *)(iVar1 + 0x10);
            _simple_lock_try();
          } while (piVar2 == (int *)0x0);
        }
      } while (iVar3 == 0);
      do {
        do {
        } while (*(int *)(iVar9 + 0x10) != 0);
        piVar2 = (int *)(iVar9 + 0x10);
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      iVar5 = iVar9;
      _vm_page_lookup(iVar9,iVar8 + iVar12);
      if (iVar5 == 0) {
        _panic(aVmFaultCopyWir);
      }
      _vm_page_copy(iVar5,iVar3);
      *(undefined4 *)(iVar9 + 0x10) = 0;
      *(undefined4 *)(iVar1 + 0x10) = 0;
      _pmap_enter(param_1[9],uVar7,*(undefined4 *)(iVar3 + 0x24),uVar11,0);
      do {
        do {
        } while (*(int *)(iVar1 + 0x10) != 0);
        piVar2 = (int *)(iVar1 + 0x10);
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar4 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar4 == (undefined4 *)0x0);
      _vm_page_activate(iVar3);
      _vm_page_queue_lock = 0;
      uVar6 = *(uint *)(iVar3 + 0x20);
      *(uint *)(iVar3 + 0x20) = uVar6 & 0x7fffffff;
      if ((uVar6 & 0x40000000) != 0) {
        *(uint *)(iVar3 + 0x20) = uVar6 & 0x3fffffff;
        _thread_wakeup_prim(iVar3,0,0);
      }
      iVar3 = _page_size;
      *(undefined4 *)(iVar1 + 0x10) = 0;
      uVar7 = uVar7 + iVar3;
      iVar8 = iVar8 + iVar3;
    } while (uVar7 < *(uint *)(param_3 + 0xc));
  }
  return CONCAT44(uVar11,puVar10);
}

