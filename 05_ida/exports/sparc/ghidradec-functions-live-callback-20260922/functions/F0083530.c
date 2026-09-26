
/* WARNING: Removing unreachable block (ram,0xf0083648) */
/* WARNING: Removing unreachable block (ram,0xf008367c) */
/* WARNING: Removing unreachable block (ram,0xf008362c) */
/* WARNING: Removing unreachable block (ram,0xf0083610) */
/* WARNING: Removing unreachable block (ram,0xf00835dc) */
/* WARNING: Removing unreachable block (ram,0xf00835d4) */
/* WARNING: Removing unreachable block (ram,0xf00835f8) */
/* WARNING: Removing unreachable block (ram,0xf0083618) */
/* WARNING: Removing unreachable block (ram,0xf0083660) */
/* WARNING: Removing unreachable block (ram,0xf0083684) */
/* WARNING: Removing unreachable block (ram,0xf00835b0) */
/* WARNING: Removing unreachable block (ram,0xf0083588) */

undefined8
sub_F0083530(int param_1,undefined4 *param_2,int param_3,int param_4,uint param_5,undefined4 param_6
            )

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar5;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar3 = 0;
  if (param_4 == 0) {
    uVar1 = *param_2;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
  }
  *(undefined4 *)((int)register0x00000038 + -0xc) = uVar1;
  uVar5 = param_3 + _page_mask & ~_page_mask;
  iVar2 = param_1;
  _vm_map_find(param_1,param_5 & -(uint)(param_5 != _kernel_object),0,
               (undefined *)((int)register0x00000038 + -0xc),uVar5,param_4);
  uVar4 = (uint)(iVar2 != 0);
  if (uVar4 == 0) {
    if (param_5 == _kernel_object) {
      iVar3 = *(int *)((int)register0x00000038 + -0xc) + 0x10000000;
      _vm_object_reference();
      _lock_write(param_1);
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      _vm_map_delete(param_1,*(int *)((int)register0x00000038 + -0xc),
                     *(int *)((int)register0x00000038 + -0xc) + uVar5);
      _vm_map_insert(param_1,param_5,iVar3,*(int *)((int)register0x00000038 + -0xc),
                     *(int *)((int)register0x00000038 + -0xc) + uVar5);
      _lock_done(param_1);
    }
    sub_F00838B4(param_5,iVar3,uVar5,param_6);
    if (param_5 == 0) {
      _lock_write(param_1);
      iVar3 = *(int *)((int)register0x00000038 + -0xc);
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      _vm_map_delete(param_1,iVar3,iVar3 + uVar5);
      _lock_done(param_1);
      uVar4 = 6;
    }
    else {
      _vm_map_pageable(param_1,*(int *)((int)register0x00000038 + -0xc),
                       *(int *)((int)register0x00000038 + -0xc) + uVar5,0);
      uVar4 = 0;
      *param_2 = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
  }
  else if (param_5 != _kernel_object) {
    _vm_object_deallocate(param_5);
  }
  return CONCAT44(param_2,uVar4);
}

