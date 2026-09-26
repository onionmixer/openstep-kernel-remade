
int sub_404BC42(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5,
               int param_6,int param_7,int param_8)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  word wVar6;
  sword sVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iStack_8;
  int iVar7;
  
  puVar10 = (undefined4 *)0x0;
  if (param_6 < 7) {
    param_6 = param_6 + 1;
    if ((*(int *)(param_3 + 4) != dword_40B5DCC) ||
       (iVar3 = _check_cpu_subtype(*(undefined4 *)(param_3 + 8)), iVar3 == 0)) {
      return 1;
    }
    switch(*(undefined4 *)(param_3 + 0xc)) {
    case :
    case :
    case :
      iVar3 = 1;
      break;
    case :
    case :
      if (param_6 == 1) {
        return 4;
      }
      goto loc_404BCCC;
    :
      goto loc_404BCC0;
    case :
      iVar3 = 2;
    }
    if (iVar3 == param_6) {
loc_404BCCC:
      uVar4 = _vnode_pager_setup(param_1,0,1);
      if ((param_5 < *(int *)(param_3 + 0x14) + 0x1cU) ||
         (uVar2 = ~_page_mask & *(int *)(param_3 + 0x14) + 0x1c + _page_mask, uVar2 == 0)) {
        return 2;
      }
      iStack_8 = 0;
      iVar3 = _vm_allocate_with_pager(_kernel_map,&iStack_8,uVar2,1,uVar4,param_4);
      if (iVar3 != 0) {
        return 5;
      }
      iVar3 = 1;
      iVar5 = 0;
      do {
        uVar9 = 0x1c;
        iVar7 = *(int *)(param_3 + 0x10) + -1;
        puVar11 = puVar10;
        if (iVar7 != -1) {
          do {
            puVar1 = (undefined4 *)(iStack_8 + uVar9);
            uVar9 = puVar1[1] + uVar9;
            if (*(int *)(param_3 + 0x14) + 0x1cU < uVar9) {
              _vm_map_remove(_kernel_map,iStack_8,uVar2 + iStack_8);
              return 2;
            }
            puVar10 = puVar11;
            switch(*puVar1) {
            case :
              if (iVar3 == 1) {
                iVar5 = sub_404BEE0(puVar1,uVar4,param_4,param_5,*(undefined4 *)(*param_1 + 0x14),
                                    param_2,param_8);
              }
              break;
            :
              iVar5 = 0;
              break;
            case :
              if (iVar3 == 2) {
                iVar5 = sub_404C1C8(puVar1,param_8);
              }
              break;
            case :
              if (iVar3 == 2) {
                iVar5 = sub_404C13C(puVar1,param_8);
              }
              break;
            case :
              if (iVar3 == 1) {
                iVar5 = sub_404C398(puVar1,param_2,param_6);
              }
              break;
            case :
              if ((iVar3 == 1) && (param_7 != 0)) {
                iVar5 = sub_404C44A(puVar1,param_7);
              }
              break;
            case :
              if (((iVar3 == 2) && (puVar10 = puVar1, param_6 != 1)) &&
                 (puVar11 != (undefined4 *)0x0)) {
                iVar5 = 4;
                goto loc_404BEAC;
              }
            }
            if (iVar5 != 0) goto loc_404BEAC;
            wVar6 = (word)((uint)iVar7 >> 0x10);
            sVar8 = (sword)iVar7 + -1;
            iVar7 = CONCAT22(wVar6,sVar8);
            puVar11 = puVar10;
          } while ((sVar8 != -1) || (iVar7 = (uint)wVar6 * 0x10000 + -1, wVar6 != 0));
        }
        if (iVar5 != 0) goto loc_404BEAC;
        iVar3 = iVar3 + 1;
      } while (iVar3 < 3);
      if (puVar10 != (undefined4 *)0x0) {
        iVar5 = sub_404C460(puVar10,param_2,param_6,param_8);
      }
loc_404BEAC:
      _vm_map_remove(_kernel_map,iStack_8,uVar2 + iStack_8);
      if (iVar5 != 0) {
        return iVar5;
      }
      if (param_6 == 1) {
        if (*(int *)(param_8 + 0xc) == 0) {
          return 4;
        }
        return 0;
      }
      return 0;
    }
  }
loc_404BCC0:
  return 4;
}
