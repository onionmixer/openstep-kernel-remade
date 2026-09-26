
/* WARNING: Removing unreachable block (ram,0xf0082fcc) */
/* WARNING: Removing unreachable block (ram,0xf0082fbc) */
/* WARNING: Removing unreachable block (ram,0xf0082f98) */
/* WARNING: Removing unreachable block (ram,0xf0082fac) */
/* WARNING: Removing unreachable block (ram,0xf0082fc4) */
/* WARNING: Removing unreachable block (ram,0xf0082ffc) */
/* WARNING: Removing unreachable block (ram,0xf0082f68) */

undefined8 _vm_fault_unwire(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
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
  uVar4 = *(uint *)(param_2 + 0xc);
  iVar3 = *(int *)(param_1 + 0x24);
  do {
    do {
    } while (_vm_page_queue_lock != 0);
    puVar1 = &_vm_page_queue_lock;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  for (uVar5 = *(uint *)(param_2 + 8); uVar5 < uVar4; uVar5 = uVar5 + _page_size) {
    iVar2 = iVar3;
    _pmap_extract(iVar3,uVar5);
    if (iVar2 == 0) {
      _panic(aUnwirePageNotI);
    }
    _pmap_change_wiring(iVar3,uVar5,0);
    _vm_phys_to_vm_page(iVar2);
    _vm_page_unwire();
  }
  _vm_page_queue_lock = 0;
  _pmap_pageable(iVar3,*(undefined4 *)(param_2 + 8),uVar4,1);
  return CONCAT44(param_2,uVar5);
}

