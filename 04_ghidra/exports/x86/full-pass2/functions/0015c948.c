/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015c948 */

undefined1 _fatfile_getarch(int *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  int local_8;
  
  uVar3 = _vnode_pager_setup(param_1,0,1);
  uVar6 = *(uint *)(param_2 + 4);
  uVar9 = uVar6 >> 0x18 | (uVar6 & 0xff0000) >> 8 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18;
  uVar6 = uVar9 * 0x14 + 8;
  if ((*(uint *)(*param_1 + 0x14) < uVar6) || (uVar6 = uVar6 + _page_mask & ~_page_mask, uVar6 == 0)
     ) {
    uVar2 = 2;
  }
  else {
    local_8 = 0;
    iVar4 = _vm_allocate_with_pager(_kernel_map,&local_8,uVar6,1,uVar3,0);
    if (iVar4 == 0) {
      puVar8 = (uint *)0x0;
      iVar4 = 0;
      puVar7 = (uint *)(local_8 + 8);
      while (0 < (int)uVar9) {
        uVar9 = uVar9 - 1;
        uVar1 = *puVar7;
        if (DAT_001e8e04 ==
            (uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 | uVar1 << 0x18)) {
          uVar1 = puVar7[1];
          iVar5 = _grade_cpu_subtype(uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8
                                     | uVar1 << 0x18);
          if (iVar4 < iVar5) {
            iVar4 = iVar5;
            puVar8 = puVar7;
          }
        }
        puVar7 = puVar7 + 5;
      }
      if (puVar8 != (uint *)0x0) {
        uVar9 = *puVar8;
        *param_3 = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18;
        uVar9 = puVar8[1];
        param_3[1] = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18
        ;
        uVar9 = puVar8[2];
        param_3[2] = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18
        ;
        uVar9 = puVar8[3];
        param_3[3] = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18
        ;
        uVar9 = puVar8[4];
        param_3[4] = uVar9 >> 0x18 | (uVar9 & 0xff0000) >> 8 | (uVar9 & 0xff00) << 8 | uVar9 << 0x18
        ;
      }
      uVar2 = puVar8 == (uint *)0x0;
      _vm_map_remove(_kernel_map,local_8,uVar6 + local_8);
    }
    else {
      uVar2 = 5;
    }
  }
  return uVar2;
}

