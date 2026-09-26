
undefined _fatfile_getarch(int *param_1,int param_2,int *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int iStack_8;
  
  uVar2 = _vnode_pager_setup(param_1,0,1);
  iVar8 = *(int *)(param_2 + 4);
  uVar1 = iVar8 * 0x14 + 8;
  if ((*(uint *)(*param_1 + 0x14) < uVar1) || (uVar1 = ~_page_mask & _page_mask + uVar1, uVar1 == 0)
     ) {
    uVar5 = 2;
  }
  else {
    iStack_8 = 0;
    iVar3 = _vm_allocate_with_pager(_kernel_map,&iStack_8,uVar1,1,uVar2,0);
    if (iVar3 == 0) {
      piVar7 = (int *)0x0;
      iVar3 = 0;
      piVar6 = (int *)(iStack_8 + 8);
      while (0 < iVar8) {
        iVar8 = iVar8 + -1;
        if ((*piVar6 == dword_40B5DCC) && (iVar4 = _grade_cpu_subtype(piVar6[1]), iVar3 < iVar4)) {
          iVar3 = iVar4;
          piVar7 = piVar6;
        }
        piVar6 = piVar6 + 5;
      }
      if (piVar7 != (int *)0x0) {
        *param_3 = *piVar7;
        param_3[1] = piVar7[1];
        param_3[2] = piVar7[2];
        param_3[3] = piVar7[3];
        param_3[4] = piVar7[4];
      }
      uVar5 = piVar7 == (int *)0x0;
      _vm_map_remove(_kernel_map,iStack_8,iStack_8 + uVar1);
    }
    else {
      uVar5 = 5;
    }
  }
  return uVar5;
}
