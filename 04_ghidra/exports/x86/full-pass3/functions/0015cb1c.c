/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015cb1c */

int FUN_0015cb1c(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5,
                int param_6,int param_7,int param_8)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  uint local_18;
  undefined4 *local_c;
  int local_8;
  
  local_c = (undefined4 *)0x0;
  if (param_6 < 7) {
    param_6 = param_6 + 1;
    if ((*(int *)(param_3 + 4) != DAT_001e8e04) ||
       (iVar3 = _check_cpu_subtype(*(undefined4 *)(param_3 + 8)), iVar3 == 0)) {
      return 1;
    }
    switch(*(undefined4 *)(param_3 + 0xc)) {
    case 1:
    case 2:
    case 5:
      if (param_6 == 1) {
LAB_0015cbaa:
        uVar4 = _vnode_pager_setup(param_1,0,1);
        if ((param_5 < *(int *)(param_3 + 0x14) + 0x1cU) ||
           (uVar6 = *(int *)(param_3 + 0x14) + 0x1c + _page_mask & ~_page_mask, uVar6 == 0)) {
          return 2;
        }
        local_8 = 0;
        iVar3 = _vm_allocate_with_pager(_kernel_map,&local_8,uVar6,1,uVar4,param_4);
        if (iVar3 != 0) {
          return 5;
        }
        iVar7 = 1;
        iVar3 = 0;
        do {
          local_18 = 0x1c;
          iVar1 = *(int *)(param_3 + 0x10);
          puVar2 = local_c;
          while (iVar1 = iVar1 + -1, local_c = puVar2, iVar1 != -1) {
            puVar5 = (undefined4 *)(local_18 + local_8);
            local_18 = local_18 + puVar5[1];
            if (*(int *)(param_3 + 0x14) + 0x1cU < local_18) {
              _vm_map_remove(_kernel_map,local_8,uVar6 + local_8);
              return 2;
            }
            switch(*puVar5) {
            case 1:
              if (iVar7 == 1) {
                iVar3 = FUN_0015ce08(puVar5,uVar4,param_4,param_5,*(undefined4 *)(*param_1 + 0x14),
                                     param_2,param_8);
              }
              break;
            default:
              iVar3 = 0;
              break;
            case 4:
              if (iVar7 == 2) {
                iVar3 = FUN_0015d158(puVar5,param_8);
              }
              break;
            case 5:
              if (iVar7 == 2) {
                iVar3 = FUN_0015d0d4(puVar5,param_8);
              }
              break;
            case 6:
              if (iVar7 == 1) {
                iVar3 = FUN_0015d338(puVar5,param_2,param_6);
              }
              break;
            case 7:
              if ((iVar7 == 1) && (param_7 != 0)) {
                iVar3 = FUN_0015d3e8(puVar5,param_7);
              }
              break;
            case 0xe:
              if (((iVar7 == 2) && (local_c = puVar5, param_6 != 1)) &&
                 (puVar2 != (undefined4 *)0x0)) {
                iVar3 = 4;
                goto LAB_0015cdcd;
              }
            }
            puVar2 = local_c;
            if (iVar3 != 0) goto LAB_0015cdcd;
          }
          if (iVar3 != 0) goto LAB_0015cdcd;
          iVar7 = iVar7 + 1;
        } while (iVar7 < 3);
        if (puVar2 != (undefined4 *)0x0) {
          iVar3 = FUN_0015d3fc(puVar2,param_2,param_6,param_8);
        }
LAB_0015cdcd:
        _vm_map_remove(_kernel_map,local_8,uVar6 + local_8);
        if (iVar3 != 0) {
          return iVar3;
        }
        if (param_6 != 1) {
          return 0;
        }
        if (*(int *)(param_8 + 0xc) != 0) {
          return 0;
        }
        return 4;
      }
      break;
    case 3:
    case 6:
      if (param_6 != 1) goto LAB_0015cbaa;
      break;
    case 7:
      if (param_6 == 2) goto LAB_0015cbaa;
    }
  }
  return 4;
}

