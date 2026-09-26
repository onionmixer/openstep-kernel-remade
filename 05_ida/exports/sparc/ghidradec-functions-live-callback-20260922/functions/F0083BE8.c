
/* WARNING: Removing unreachable block (ram,0xf0083e90) */
/* WARNING: Removing unreachable block (ram,0xf0083e6c) */
/* WARNING: Removing unreachable block (ram,0xf0083df8) */
/* WARNING: Removing unreachable block (ram,0xf0083dc8) */
/* WARNING: Removing unreachable block (ram,0xf0083da4) */
/* WARNING: Removing unreachable block (ram,0xf0083d10) */
/* WARNING: Removing unreachable block (ram,0xf0083c68) */
/* WARNING: Removing unreachable block (ram,0xf0083c1c) */
/* WARNING: Removing unreachable block (ram,0xf0083c44) */
/* WARNING: Removing unreachable block (ram,0xf0083c8c) */
/* WARNING: Removing unreachable block (ram,0xf0083d68) */
/* WARNING: Removing unreachable block (ram,0xf0083e04) */
/* WARNING: Removing unreachable block (ram,0xf0083dd0) */
/* WARNING: Removing unreachable block (ram,0xf0083e58) */
/* WARNING: Removing unreachable block (ram,0xf0083e74) */
/* WARNING: Removing unreachable block (ram,0xf0083eb0) */
/* WARNING: Removing unreachable block (ram,0xf0083c04) */

undefined8 _kmem_mb_alloc(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l3;
  int iVar7;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar9;
  undefined4 unaff_i1;
  uint uVar10;
  undefined4 unaff_i2;
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
  if (param_1 != _mb_map) {
    _panic(aYouFool);
  }
  uVar10 = param_2 + _page_mask & ~_page_mask;
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  iVar7 = *(int *)(param_1 + 0x10);
  if (iVar7 == param_1 + 0xc) {
    _lock_done(param_1);
    *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x14);
    iVar7 = param_1;
    _vm_map_find(param_1,0,0,(undefined *)((int)register0x00000038 + -0xc),uVar10,1);
    if (iVar7 == 0) {
      _vm_map_pageable(param_1,*(int *)((int)register0x00000038 + -0xc),
                       *(int *)((int)register0x00000038 + -0xc) + uVar10,0);
      uVar9 = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
    else {
      uVar9 = 0;
    }
    goto locret_F0083EBC;
  }
  if ((((iVar7 == *(int *)(param_1 + 0xc)) && (-1 < *(int *)(iVar7 + 0x18))) &&
      (*(int *)(iVar7 + 8) == *(int *)(param_1 + 0x14))) &&
     (((*(int *)(iVar7 + 0x20) == 7 && (*(int *)(iVar7 + 0x1c) == 3)) &&
      ((*(int *)(iVar7 + 0x24) == 1 && (*(sword *)(iVar7 + 0x28) != 0)))))) {
    iVar1 = *(int *)(param_1 + 0x18);
  }
  else {
    _panic(aMbMapAbusedEve);
    iVar1 = *(int *)(param_1 + 0x18);
  }
  uVar3 = *(uint *)(iVar7 + 0xc);
  if (uVar3 <= iVar1 - uVar10) {
    iVar1 = *(int *)(iVar7 + 8);
    iVar4 = *(int *)(iVar7 + 0x14);
    *(uint *)((int)register0x00000038 + -0xc) = uVar3;
    iVar8 = *(int *)(iVar7 + 0x10);
    uVar3 = (uVar3 - iVar1) + iVar4;
    *(uint *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + uVar10;
    do {
      do {
      } while (*(int *)(iVar8 + 0x10) != 0);
      piVar2 = (int *)(iVar8 + 0x10);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    uVar5 = uVar3;
    for (uVar6 = uVar10 >> ((byte)_page_shift & 0x1f); uVar6 != 0; uVar6 = uVar6 - 1) {
      iVar1 = iVar8;
      _vm_page_alloc_sequential(iVar8,uVar5,0);
      if (iVar1 == 0) goto joined_r0xf0083db8;
      _vm_page_zero_fill(iVar1);
      iVar4 = _page_size;
      *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0x7fffffff;
      uVar5 = uVar5 + iVar4;
    }
    uVar10 = *(uint *)((int)register0x00000038 + -0xc);
    *(undefined4 *)(iVar8 + 0x10) = 0;
    if (uVar10 < *(uint *)(iVar7 + 0xc)) {
      do {
        do {
          do {
          } while (*(int *)(iVar8 + 0x10) != 0);
          piVar2 = (int *)(iVar8 + 0x10);
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        iVar1 = iVar8;
        _vm_page_lookup(iVar8,uVar3);
        _vm_page_wire();
        *(undefined4 *)(iVar8 + 0x10) = 0;
        _pmap_enter(*(undefined4 *)(param_1 + 0x24),uVar10,*(undefined4 *)(iVar1 + 0x24),
                    *(undefined4 *)(iVar7 + 0x1c),1);
        uVar10 = uVar10 + _page_size;
        uVar3 = uVar3 + _page_size;
      } while (uVar10 < *(uint *)(iVar7 + 0xc));
    }
    _lock_done(param_1);
    uVar9 = *(undefined4 *)((int)register0x00000038 + -0xc);
    goto locret_F0083EBC;
  }
loc_F0083DF8:
  uVar9 = 0;
  _lock_done(param_1);
locret_F0083EBC:
  return CONCAT44(uVar10,uVar9);
joined_r0xf0083db8:
  while (uVar3 < uVar5) {
    uVar5 = uVar5 - _page_size;
    _vm_page_lookup(iVar8,uVar5);
    _vm_page_free();
  }
  *(undefined4 *)(iVar8 + 0x10) = 0;
  *(uint *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) - uVar10;
  goto loc_F0083DF8;
}

