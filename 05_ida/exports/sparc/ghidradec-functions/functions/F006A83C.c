
/* WARNING: Removing unreachable block (ram,0xf006ab60) */
/* WARNING: Removing unreachable block (ram,0xf006aa5c) */
/* WARNING: Removing unreachable block (ram,0xf006aaa0) */
/* WARNING: Removing unreachable block (ram,0xf006a978) */
/* WARNING: Removing unreachable block (ram,0xf006a904) */
/* WARNING: Removing unreachable block (ram,0xf006a954) */
/* WARNING: Removing unreachable block (ram,0xf006aacc) */
/* WARNING: Removing unreachable block (ram,0xf006aa7c) */
/* WARNING: Removing unreachable block (ram,0xf006aa3c) */
/* WARNING: Removing unreachable block (ram,0xf006ab78) */
/* WARNING: Removing unreachable block (ram,0xf006a86c) */

undefined8
sub_F006A83C(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5,int param_6
            )

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 unaff_l4;
  int iVar10;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar11;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar12;
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
  puVar8 = (undefined4 *)0x0;
  iVar10 = *(int *)((int)register0x00000038 + 0x60);
  if (param_6 < 7) {
    param_6 = param_6 + 1;
    if (*(int *)(param_3 + 4) == dword_F0134764) {
      iVar2 = *(int *)(param_3 + 8);
      _check_cpu_subtype();
      if (iVar2 != 0) {
        switch(*(undefined4 *)(param_3 + 0xc)) {
        case :
        case :
        case :
          if (param_6 != 1) {
            puVar11 = (undefined4 *)0x4;
            goto locret_F006ABA8;
          }
          break;
        case :
        case :
          if (param_6 == 1) {
            puVar11 = (undefined4 *)0x4;
            goto locret_F006ABA8;
          }
          break;
        :
          goto def_F006A8A4;
        case :
          puVar11 = (undefined4 *)0x4;
          if (param_6 != 2) goto locret_F006ABA8;
        }
        piVar3 = param_1;
        _vnode_pager_setup(param_1,0,1);
        if ((param_5 < *(int *)(param_3 + 0x14) + 0x1cU) ||
           (uVar1 = *(int *)(param_3 + 0x14) + _page_mask + 0x1c & ~_page_mask, uVar1 == 0)) {
loc_F006A980:
          puVar11 = (undefined4 *)0x2;
        }
        else {
          *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
          iVar2 = _kernel_map;
          _vm_allocate_with_pager
                    (_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar1,1,piVar3,
                     param_4);
          iVar6 = 1;
          if (iVar2 == 0) {
            iVar2 = *(int *)(param_3 + 0x10);
            puVar11 = (undefined4 *)0x0;
            do {
              uVar7 = 0x1c;
              do {
                iVar2 = iVar2 + -1;
                iVar5 = *(int *)((int)register0x00000038 + -0xc);
                if (iVar2 == -1) break;
                puVar4 = (undefined4 *)(iVar5 + uVar7);
                uVar7 = uVar7 + puVar4[1];
                if (*(int *)(param_3 + 0x14) + 0x1cU < uVar7) {
                  _vm_map_remove(_kernel_map,iVar5,iVar5 + uVar1);
                  goto loc_F006A980;
                }
                puVar9 = puVar8;
                switch(*puVar4) {
                case :
                  bVar12 = puVar11 == (undefined4 *)0x0;
                  if (iVar6 == 1) {
                    sub_F006ABB0(puVar4,piVar3,param_4,param_5,*(undefined4 *)(*param_1 + 0x14),
                                 param_2,iVar10);
                    puVar11 = puVar4;
                    break;
                  }
                  goto loc_F006AB0C;
                :
                  puVar11 = (undefined4 *)0x0;
                  break;
                case :
                  bVar12 = puVar11 == (undefined4 *)0x0;
                  if (iVar6 != 2) goto loc_F006AB0C;
                  sub_F006AF04(puVar4,iVar10);
                  puVar11 = puVar4;
                  break;
                case :
                  bVar12 = puVar11 == (undefined4 *)0x0;
                  if (iVar6 != 2) goto loc_F006AB0C;
                  sub_F006AE50(puVar4,iVar10);
                  puVar11 = puVar4;
                  break;
                case :
                  bVar12 = puVar11 == (undefined4 *)0x0;
                  if (iVar6 != 1) goto loc_F006AB0C;
                  sub_F006B130(puVar4,param_2,param_6);
                  puVar11 = puVar4;
                  break;
                case :
                  bVar12 = puVar11 == (undefined4 *)0x0;
                  if (iVar6 != 1) goto loc_F006AB0C;
                  if (*(int *)((int)register0x00000038 + 0x5c) != 0) {
                    sub_F006B1F8(puVar4,*(undefined4 *)((int)register0x00000038 + 0x5c));
                    puVar11 = puVar4;
                  }
                  break;
                case :
                  bVar12 = puVar11 == (undefined4 *)0x0;
                  if (iVar6 != 2) goto loc_F006AB0C;
                  puVar9 = puVar4;
                  if ((param_6 != 1) && (puVar8 != (undefined4 *)0x0)) {
                    puVar9 = puVar8;
                    puVar11 = (undefined4 *)0x4;
                  }
                }
                bVar12 = puVar11 == (undefined4 *)0x0;
                puVar8 = puVar9;
loc_F006AB0C:
              } while (bVar12);
              if ((puVar11 != (undefined4 *)0x0) || (iVar6 = iVar6 + 1, 2 < iVar6))
              goto loc_F006AB44;
              iVar2 = *(int *)(param_3 + 0x10);
            } while( true );
          }
          puVar11 = (undefined4 *)0x5;
        }
        goto locret_F006ABA8;
      }
    }
    puVar11 = (undefined4 *)0x1;
    goto locret_F006ABA8;
  }
def_F006A8A4:
  puVar11 = (undefined4 *)0x4;
locret_F006ABA8:
  return CONCAT44(param_2,puVar11);
loc_F006AB44:
  iVar2 = *(int *)((int)register0x00000038 + -0xc);
  if ((puVar11 == (undefined4 *)0x0) && (puVar8 != (undefined4 *)0x0)) {
    sub_F006B20C(puVar8,param_2,param_6,iVar10);
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    puVar11 = puVar8;
  }
  _vm_map_remove(_kernel_map,iVar2,iVar2 + uVar1);
  if (((puVar11 != (undefined4 *)0x0) || (param_6 != 1)) || (*(int *)(iVar10 + 0xc) != 0))
  goto locret_F006ABA8;
  goto def_F006A8A4;
}
