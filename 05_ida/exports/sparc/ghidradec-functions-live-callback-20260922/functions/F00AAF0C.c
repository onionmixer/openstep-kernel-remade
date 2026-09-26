
/* WARNING: Removing unreachable block (ram,0xf00ab018) */
/* WARNING: Removing unreachable block (ram,0xf00aafe4) */
/* WARNING: Removing unreachable block (ram,0xf00aafac) */
/* WARNING: Removing unreachable block (ram,0xf00aaf7c) */
/* WARNING: Removing unreachable block (ram,0xf00aafd8) */
/* WARNING: Removing unreachable block (ram,0xf00ab000) */
/* WARNING: Removing unreachable block (ram,0xf00ab020) */
/* WARNING: Removing unreachable block (ram,0xf00aaf4c) */

undefined8 _map_alloc(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 unaff_l0;
  uint uVar3;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  undefined4 uVar6;
  undefined4 unaff_i1;
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
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  uVar3 = param_2 - 1;
  uVar5 = param_1 + _page_mask & ~_page_mask;
  if ((param_2 & uVar3) == 0) {
    iVar1 = _kernel_map;
    _vm_map_find(_kernel_map,0,0,(undefined *)((int)register0x00000038 + -0xc),uVar5,1);
    if (iVar1 != 0) {
      uVar6 = 0;
      goto locret_F00AB02C;
    }
    uVar2 = *(uint *)((int)register0x00000038 + -0xc);
    if ((param_2 != 0) && ((uVar2 & uVar3) != 0)) {
      _vm_map_remove(_kernel_map,uVar2,uVar2 + uVar5);
      *(uint *)((int)register0x00000038 + -0xc) =
           *(int *)((int)register0x00000038 + -0xc) + -1 + param_2 & ~uVar3;
      iVar1 = _kernel_map;
      _vm_map_find(_kernel_map,0,0,(undefined *)((int)register0x00000038 + -0xc),uVar5,0);
      if (iVar1 != 0) goto loc_F00AAFC0;
    }
    iVar4 = *(int *)((int)register0x00000038 + -0xc);
    _vm_object_reference(_kernel_object);
    _lock_write(_kernel_map);
    iVar1 = _kernel_map;
    *(int *)(_kernel_map + 0x4c) = *(int *)(_kernel_map + 0x4c) + 1;
    _vm_map_delete(iVar1,*(int *)((int)register0x00000038 + -0xc),
                   *(int *)((int)register0x00000038 + -0xc) + uVar5);
    _vm_map_insert(_kernel_map,_kernel_object,iVar4 + 0x10000000,
                   *(int *)((int)register0x00000038 + -0xc),
                   *(int *)((int)register0x00000038 + -0xc) + uVar5);
    _lock_done(_kernel_map);
    uVar6 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  else {
loc_F00AAFC0:
    uVar6 = 0;
  }
locret_F00AB02C:
  return CONCAT44(param_2,uVar6);
}

