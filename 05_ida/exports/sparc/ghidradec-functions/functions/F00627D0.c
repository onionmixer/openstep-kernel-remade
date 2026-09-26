
/* WARNING: Removing unreachable block (ram,0xf0062a18) */
/* WARNING: Removing unreachable block (ram,0xf00629d8) */
/* WARNING: Removing unreachable block (ram,0xf00628f0) */
/* WARNING: Removing unreachable block (ram,0xf00628bc) */
/* WARNING: Removing unreachable block (ram,0xf00629a8) */
/* WARNING: Removing unreachable block (ram,0xf0062830) */
/* WARNING: Removing unreachable block (ram,0xf0062820) */
/* WARNING: Removing unreachable block (ram,0xf0062990) */
/* WARNING: Removing unreachable block (ram,0xf00628a4) */
/* WARNING: Removing unreachable block (ram,0xf00628e4) */
/* WARNING: Removing unreachable block (ram,0xf0062908) */
/* WARNING: Removing unreachable block (ram,0xf00629f8) */
/* WARNING: Removing unreachable block (ram,0xf0062928) */
/* WARNING: Removing unreachable block (ram,0xf0062804) */

undefined8
_mach_port_get_set_status(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  uint *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar3;
  undefined4 unaff_l3;
  uint uVar4;
  undefined4 unaff_l4;
  undefined4 uVar5;
  undefined4 unaff_l5;
  uint uVar6;
  undefined4 unaff_l6;
  uint uVar7;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar8;
  uint uVar9;
  undefined4 unaff_i1;
  undefined4 uVar10;
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
  if (param_1 == 0) {
    iVar8 = 0x10;
    uVar10 = param_2;
  }
  else {
    uVar10 = 0x20000;
    uVar7 = _page_size;
    while( true ) {
      iVar8 = _ipc_kernel_map;
      _vm_allocate(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar7,1);
      if (iVar8 != 0) break;
      _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc),
                       *(int *)((int)register0x00000038 + -0xc) + uVar7,0);
      iVar8 = param_1;
      _ipc_right_lookup_write(param_1,param_2,(undefined *)((int)register0x00000038 + -0x10));
      iVar1 = _ipc_kernel_map;
      if (iVar8 != 0) {
        _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar7);
        goto locret_F0062A34;
      }
      uVar3 = 0;
      if ((**(uint **)((int)register0x00000038 + -0x10) & 0x1f0000) != 0x80000) {
        *(undefined4 *)(param_1 + 8) = 0;
        _kmem_free(iVar1,*(undefined4 *)((int)register0x00000038 + -0xc),uVar7);
        iVar8 = 0x11;
        goto locret_F0062A34;
      }
      uVar6 = (*(uint **)((int)register0x00000038 + -0x10))[1];
      uVar4 = *(uint *)(param_1 + 0x18);
      *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
      uVar5 = *(undefined4 *)((int)register0x00000038 + -0xc);
      puVar2 = *(uint **)(param_1 + 0x14);
      uVar9 = uVar7 >> 2;
      if (uVar4 != 0) {
        do {
          if ((*puVar2 & 0x20000) != 0) {
            _mach_port_gst_helper
                      (uVar6,puVar2[1],uVar9,uVar5,(undefined *)((int)register0x00000038 + -0x14));
          }
          uVar3 = uVar3 + 1;
          puVar2 = puVar2 + 4;
        } while (uVar3 < uVar4);
      }
      puVar2 = (uint *)(param_1 + 0x20);
      _ipc_splay_traverse_start();
      while (puVar2 != (uint *)0x0) {
        if ((*puVar2 & 0x20000) != 0) {
          _mach_port_gst_helper
                    (uVar6,puVar2[1],uVar9,uVar5,(undefined *)((int)register0x00000038 + -0x14));
        }
        puVar2 = (uint *)(param_1 + 0x20);
        _ipc_splay_traverse_next(puVar2,0);
      }
      _ipc_splay_traverse_finish(param_1 + 0x20);
      uVar3 = *(uint *)((int)register0x00000038 + -0x14);
      *(undefined4 *)(param_1 + 8) = 0;
      if (uVar3 <= uVar9) {
        if (*(int *)((int)register0x00000038 + -0x14) == 0) {
          *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
          iVar8 = *(int *)((int)register0x00000038 + -0xc);
loc_F0062A18:
          _kmem_free(_ipc_kernel_map,iVar8,uVar7);
        }
        else {
          uVar3 = *(int *)((int)register0x00000038 + -0x14) * 4 + _page_mask & ~_page_mask;
          _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc),
                           *(int *)((int)register0x00000038 + -0xc) + uVar3,1);
          _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,
                   uVar3,1,(undefined *)((int)register0x00000038 + -0x18));
          if (uVar3 != uVar7) {
            uVar7 = uVar7 - uVar3;
            iVar8 = *(int *)((int)register0x00000038 + -0xc) + uVar3;
            goto loc_F0062A18;
          }
        }
        *param_3 = *(undefined4 *)((int)register0x00000038 + -0x18);
        iVar8 = 0;
        *param_4 = *(undefined4 *)((int)register0x00000038 + -0x14);
        goto locret_F0062A34;
      }
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar7);
      uVar7 = (*(int *)((int)register0x00000038 + -0x14) * 4 + _page_mask & ~_page_mask) +
              _page_size;
    }
    iVar8 = 6;
  }
locret_F0062A34:
  return CONCAT44(uVar10,iVar8);
}
