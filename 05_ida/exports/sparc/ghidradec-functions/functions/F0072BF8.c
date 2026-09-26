
/* WARNING: Removing unreachable block (ram,0xf0072d9c) */
/* WARNING: Removing unreachable block (ram,0xf0072d54) */
/* WARNING: Removing unreachable block (ram,0xf0072d24) */
/* WARNING: Removing unreachable block (ram,0xf0072c98) */
/* WARNING: Removing unreachable block (ram,0xf0072c68) */
/* WARNING: Removing unreachable block (ram,0xf0072cb0) */
/* WARNING: Removing unreachable block (ram,0xf0072ce4) */
/* WARNING: Removing unreachable block (ram,0xf0072c80) */
/* WARNING: Removing unreachable block (ram,0xf0072d18) */
/* WARNING: Removing unreachable block (ram,0xf0072d34) */
/* WARNING: Removing unreachable block (ram,0xf0072d7c) */
/* WARNING: Removing unreachable block (ram,0xf0072da4) */
/* WARNING: Removing unreachable block (ram,0xf0072c0c) */

undefined8 _map_fd(int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l3;
  int *piVar5;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar7;
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
  uVar4 = *(uint *)(*(int *)(_active_threads + 0xc) + 0xc);
  _getf();
  if (param_1 == 0) {
    uVar6 = 4;
    goto locret_F0072DE4;
  }
  piVar5 = *(int **)(param_1 + 0x18);
  if (*(sword *)(param_1 + 0xc) == 1) {
    if (piVar5[10] != 1) {
      uVar6 = 4;
      goto locret_F0072DE4;
    }
    uVar3 = param_5 + _page_mask & ~_page_mask;
    if (param_4 == 0) {
      _copyin(param_3,(undefined *)((int)register0x00000038 + -0xc),4);
      uVar6 = 1;
      if (param_3 != 0) goto locret_F0072DE4;
      uVar1 = *(uint *)((int)register0x00000038 + -0xc) & ~_page_mask;
      uVar6 = 4;
      if (uVar1 != *(uint *)((int)register0x00000038 + -0xc)) goto locret_F0072DE4;
      uVar6 = uVar4;
      _vm_map_check_protection(uVar4,uVar1,uVar1 + uVar3,3);
      if (uVar6 == 0) goto loc_F0072CF8;
    }
    else {
      puVar2 = (undefined *)((int)register0x00000038 + -0xc);
      uVar6 = uVar4;
      _vm_allocate(uVar4,puVar2,param_5,1);
      if (uVar6 != 0) goto locret_F0072DE4;
      _copyout(puVar2,param_3,4);
      if (puVar2 != (undefined *)0x0) {
        _vm_deallocate(uVar4,*(undefined4 *)((int)register0x00000038 + -0xc),param_5);
        uVar6 = 1;
        goto locret_F0072DE4;
      }
    }
    if (param_5 == 0) {
      uVar6 = 0;
    }
    else {
      _vnode_pager_setup(piVar5,0,0);
      uVar1 = uVar3;
      _pmap_create();
      _vm_map_create();
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
      uVar6 = uVar1;
      _vm_allocate_with_pager();
      bVar7 = false;
      if (uVar6 == 0) {
        uVar6 = uVar4;
        _vm_map_copy(uVar4,uVar1,*(undefined4 *)((int)register0x00000038 + -0xc),uVar3,0,0,0);
        bVar7 = uVar6 == 0;
      }
      if ((!bVar7) && (param_4 != 0)) {
        _vm_deallocate(uVar4,*(undefined4 *)((int)register0x00000038 + -0xc),uVar3);
      }
      _vm_map_deallocate(uVar1);
      if (*(int *)(*piVar5 + 0x30) == 0) {
        **(sword **)(_active_u + 0x1c) = **(sword **)(_active_u + 0x1c) + 1;
        *(undefined4 *)(*piVar5 + 0x30) = *(undefined4 *)(_active_u + 0x1c);
      }
    }
  }
  else {
loc_F0072CF8:
    uVar6 = 4;
  }
locret_F0072DE4:
  return CONCAT44(param_2,uVar6);
}
