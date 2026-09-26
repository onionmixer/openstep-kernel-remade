
/* WARNING: Removing unreachable block (ram,0xf00837d4) */
/* WARNING: Removing unreachable block (ram,0xf00837a4) */
/* WARNING: Removing unreachable block (ram,0xf0083764) */
/* WARNING: Removing unreachable block (ram,0xf008373c) */
/* WARNING: Removing unreachable block (ram,0xf008372c) */
/* WARNING: Removing unreachable block (ram,0xf0083754) */
/* WARNING: Removing unreachable block (ram,0xf0083780) */
/* WARNING: Removing unreachable block (ram,0xf00837c0) */
/* WARNING: Removing unreachable block (ram,0xf00837e8) */
/* WARNING: Removing unreachable block (ram,0xf008370c) */

undefined8 _kmem_realloc(int param_1,uint param_2,int param_3,undefined4 *param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  undefined4 unaff_i1;
  int iVar6;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  uint uVar7;
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
  uVar1 = ~_page_mask;
  iVar6 = (param_2 + param_3 + _page_mask & uVar1) - (param_2 & uVar1);
  uVar7 = param_5 + _page_mask & uVar1;
  iVar2 = param_1;
  _vm_map_find(param_1,0,0,(undefined *)((int)register0x00000038 + -0xc),uVar7,1);
  uVar5 = (uint)(iVar2 != 0);
  if (uVar5 == 0) {
    _vm_map_lookup_entry
              (param_1,*(undefined4 *)((int)register0x00000038 + -0xc),
               (undefined *)((int)register0x00000038 + -0x10));
    iVar2 = param_1;
    _vm_map_lookup_entry(param_1,param_2 & uVar1,(undefined *)((int)register0x00000038 + -0x14));
    if (iVar2 == 0) {
      _panic(aKmemRealloc);
      iVar2 = *(int *)((int)register0x00000038 + -0x14);
    }
    else {
      iVar2 = *(int *)((int)register0x00000038 + -0x14);
    }
    iVar2 = *(int *)(iVar2 + 0x10);
    _vm_object_reference(iVar2);
    do {
      do {
      } while (*(int *)(iVar2 + 0x10) != 0);
      piVar3 = (int *)(iVar2 + 0x10);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    if (*(int *)(iVar2 + 0x14) != iVar6) {
      _panic(aKmemRealloc_0);
    }
    *(uint *)(iVar2 + 0x14) = uVar7;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    iVar4 = *(int *)((int)register0x00000038 + -0x10);
    *(int *)(iVar4 + 0x10) = iVar2;
    *(undefined4 *)(iVar4 + 0x14) = 0;
    _lock_done(param_1);
    sub_F00838B4(iVar2,iVar6,uVar7,1);
    _vm_map_pageable(param_1,*(int *)((int)register0x00000038 + -0xc),
                     *(int *)((int)register0x00000038 + -0xc) + uVar7,0);
    uVar5 = 0;
    *param_4 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(iVar6,uVar5);
}

