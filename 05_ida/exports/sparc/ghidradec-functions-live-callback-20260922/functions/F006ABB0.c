
/* WARNING: Removing unreachable block (ram,0xf006ae04) */
/* WARNING: Removing unreachable block (ram,0xf006adc8) */
/* WARNING: Removing unreachable block (ram,0xf006ada0) */
/* WARNING: Removing unreachable block (ram,0xf006ad8c) */
/* WARNING: Removing unreachable block (ram,0xf006ad54) */
/* WARNING: Removing unreachable block (ram,0xf006ace8) */
/* WARNING: Removing unreachable block (ram,0xf006ac68) */
/* WARNING: Removing unreachable block (ram,0xf006ac58) */
/* WARNING: Removing unreachable block (ram,0xf006ac88) */
/* WARNING: Removing unreachable block (ram,0xf006ad20) */
/* WARNING: Removing unreachable block (ram,0xf006ad78) */
/* WARNING: Removing unreachable block (ram,0xf006ad38) */
/* WARNING: Removing unreachable block (ram,0xf006acfc) */
/* WARNING: Removing unreachable block (ram,0xf006add4) */
/* WARNING: Removing unreachable block (ram,0xf006ae24) */
/* WARNING: Removing unreachable block (ram,0xf006ac10) */

undefined8 sub_F006ABB0(int param_1,int param_2,int param_3,uint param_4,int param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 *puVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar8;
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
  puVar6 = *(undefined4 **)((int)register0x00000038 + 0x5c);
  if ((uint)(*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x24)) <= param_4) {
    uVar1 = *(int *)(param_1 + 0x1c) + _page_mask & ~_page_mask;
    if (-1 < (int)uVar1) {
      if (uVar1 != 0) {
        *(uint *)((int)register0x00000038 + -0xc) = *(uint *)(param_1 + 0x18) & ~_page_mask;
        iVar5 = param_6;
        _vm_map_find(param_6,0,0,(undefined *)((int)register0x00000038 + -0xc),uVar1,0);
        if (iVar5 != 0) {
          uVar7 = 5;
          goto locret_F006AE48;
        }
        iVar5 = *(int *)(param_1 + 0x20);
        uVar2 = *(int *)(param_1 + 0x24) + _page_mask & ~_page_mask;
        if ((int)uVar2 < 0) goto loc_F006AC44;
        if (0 < (int)uVar2) {
          uVar4 = uVar2;
          _pmap_create();
          _vm_map_create();
          *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
          uVar8 = uVar4;
          _vm_allocate_with_pager();
          if (uVar8 == 0) {
            uVar3 = *(uint *)(param_1 + 0x24);
            uVar8 = uVar2;
            if ((uVar2 == uVar3) || ((param_5 != 0 && (iVar5 + param_3 + uVar3 == param_5)))) {
loc_F006ADB4:
              param_2 = param_6;
              _vm_map_copy(param_6,uVar4,*(undefined4 *)((int)register0x00000038 + -0xc),uVar8,
                           *(undefined4 *)((int)register0x00000038 + -0x10),0,0);
              _vm_map_deallocate(uVar4);
              if (param_2 != 0) {
                uVar7 = 4;
                goto locret_F006AE48;
              }
              iVar5 = *(int *)(param_1 + 0x28);
              goto loc_F006ADF0;
            }
            *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
            uVar8 = uVar3 & ~_page_mask;
            iVar5 = _kernel_map;
            _vm_map_find(_kernel_map,0,0,(undefined *)((int)register0x00000038 + -0x14),_page_size,1
                        );
            if (iVar5 == 0) {
              iVar5 = _kernel_map;
              _vm_map_copy(_kernel_map,uVar4,*(undefined4 *)((int)register0x00000038 + -0x14),
                           _page_size,uVar8,0,0);
              if (iVar5 == 0) {
                _bzero(*(int *)((int)register0x00000038 + -0x14) +
                       (*(int *)(param_1 + 0x24) - uVar8),uVar2 - *(int *)(param_1 + 0x24));
                param_2 = param_6;
                _vm_map_copy(param_6,_kernel_map,*(int *)((int)register0x00000038 + -0xc) + uVar8,
                             _page_size,*(undefined4 *)((int)register0x00000038 + -0x14),0,0);
                _vm_deallocate(_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x14),
                               _page_size);
                if (param_2 == 0) goto loc_F006ADB4;
              }
              else {
                _vm_deallocate(_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x14),
                               _page_size);
              }
              _vm_map_deallocate(uVar4);
              uVar7 = 4;
              goto locret_F006AE48;
            }
          }
          _vm_map_deallocate(uVar4);
          uVar7 = 5;
          goto locret_F006AE48;
        }
        iVar5 = *(int *)(param_1 + 0x28);
loc_F006ADF0:
        if (iVar5 != 3) {
          _vm_map_protect(param_6,*(int *)((int)register0x00000038 + -0xc),
                          *(int *)((int)register0x00000038 + -0xc) + uVar1,iVar5,1);
        }
        if (*(int *)(param_1 + 0x2c) != 3) {
          _vm_map_protect(param_6,*(int *)((int)register0x00000038 + -0xc),
                          *(int *)((int)register0x00000038 + -0xc) + uVar1,*(int *)(param_1 + 0x2c),
                          0);
        }
        uVar7 = 0;
        if (*(int *)(param_1 + 0x20) != 0) goto locret_F006AE48;
        *puVar6 = *(undefined4 *)((int)register0x00000038 + -0xc);
      }
      uVar7 = 0;
      goto locret_F006AE48;
    }
  }
loc_F006AC44:
  uVar7 = 2;
locret_F006AE48:
  return CONCAT44(param_2,uVar7);
}

