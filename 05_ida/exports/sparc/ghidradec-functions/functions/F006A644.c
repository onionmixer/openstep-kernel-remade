
/* WARNING: Removing unreachable block (ram,0xf006a708) */
/* WARNING: Removing unreachable block (ram,0xf006a6b8) */
/* WARNING: Removing unreachable block (ram,0xf006a77c) */
/* WARNING: Removing unreachable block (ram,0xf006a650) */

undefined8 _fatfile_getarch(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  int *piVar6;
  undefined4 unaff_i1;
  int *piVar7;
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
  piVar6 = param_1;
  _vnode_pager_setup(param_1,0,1);
  iVar4 = param_2[1];
  uVar3 = iVar4 * 0x14 + 8;
  if ((*(uint *)(*param_1 + 0x14) < uVar3) || (uVar3 = uVar3 + _page_mask & ~_page_mask, uVar3 == 0)
     ) {
    uVar5 = 2;
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
    iVar1 = _kernel_map;
    _vm_allocate_with_pager
              (_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar3,1,piVar6,0);
    param_2 = (int *)0x0;
    if (iVar1 == 0) {
      piVar6 = (int *)(*(int *)((int)register0x00000038 + -0xc) + 8);
      iVar1 = 0;
      while (0 < iVar4) {
        iVar4 = iVar4 + -1;
        iVar2 = iVar1;
        piVar7 = param_2;
        if (*piVar6 == dword_F0134764) {
          iVar2 = piVar6[1];
          _grade_cpu_subtype();
          piVar7 = piVar6;
          if (iVar2 <= iVar1) {
            iVar2 = iVar1;
            piVar7 = param_2;
          }
        }
        piVar6 = piVar6 + 5;
        param_2 = piVar7;
        iVar1 = iVar2;
      }
      if (param_2 != (int *)0x0) {
        *param_3 = *param_2;
        param_3[1] = param_2[1];
        param_3[2] = param_2[2];
        param_3[3] = param_2[3];
        param_3[4] = param_2[4];
      }
      uVar5 = (uint)(param_2 == (int *)0x0);
      _vm_map_remove(_kernel_map,*(int *)((int)register0x00000038 + -0xc),
                     *(int *)((int)register0x00000038 + -0xc) + uVar3);
    }
    else {
      uVar5 = 5;
    }
  }
  return CONCAT44(param_2,uVar5);
}
