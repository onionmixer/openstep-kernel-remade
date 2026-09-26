
/* WARNING: Removing unreachable block (ram,0xf0062030) */
/* WARNING: Removing unreachable block (ram,0xf0062014) */
/* WARNING: Removing unreachable block (ram,0xf0061fe0) */
/* WARNING: Removing unreachable block (ram,0xf0062214) */
/* WARNING: Removing unreachable block (ram,0xf00621fc) */
/* WARNING: Removing unreachable block (ram,0xf00621c0) */
/* WARNING: Removing unreachable block (ram,0xf006218c) */
/* WARNING: Removing unreachable block (ram,0xf00620f0) */
/* WARNING: Removing unreachable block (ram,0xf00620c8) */
/* WARNING: Removing unreachable block (ram,0xf0062054) */
/* WARNING: Removing unreachable block (ram,0xf0061f70) */
/* WARNING: Removing unreachable block (ram,0xf0061f80) */
/* WARNING: Removing unreachable block (ram,0xf00620b0) */
/* WARNING: Removing unreachable block (ram,0xf00620e4) */
/* WARNING: Removing unreachable block (ram,0xf0062108) */
/* WARNING: Removing unreachable block (ram,0xf00621a0) */
/* WARNING: Removing unreachable block (ram,0xf00621dc) */
/* WARNING: Removing unreachable block (ram,0xf0062140) */
/* WARNING: Removing unreachable block (ram,0xf0061fd0) */
/* WARNING: Removing unreachable block (ram,0xf0061ff8) */
/* WARNING: Removing unreachable block (ram,0xf006215c) */
/* WARNING: Removing unreachable block (ram,0xf0062044) */
/* WARNING: Removing unreachable block (ram,0xf0061f38) */

undefined8
_mach_port_names(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  undefined4 unaff_l0;
  uint uVar6;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  uint uVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 uVar9;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar10;
  undefined4 unaff_i1;
  undefined4 *puVar11;
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
  if (param_1 == 0) {
loc_F0061F14:
    uVar10 = 0x10;
  }
  else {
    uVar6 = 0;
loc_F0061F28:
    do {
      do {
      } while (*(int *)(param_1 + 8) != 0);
      piVar1 = (int *)(param_1 + 8);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if (*(int *)(param_1 + 0xc) == 0) {
      *(undefined4 *)(param_1 + 8) = 0;
      if (uVar6 == 0) goto loc_F0061F14;
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar6);
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar6);
      uVar10 = 0x10;
      goto locret_F0062240;
    }
    uVar2 = (*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x38)) * 4 + _page_mask;
    uVar7 = uVar2 & ~_page_mask;
    uVar10 = *(undefined4 *)((int)register0x00000038 + -0xc);
    if (uVar7 <= uVar6) {
      uVar9 = *(undefined4 *)((int)register0x00000038 + -0x10);
      *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
      _ipc_port_timestamp();
      uVar7 = 0;
      uVar8 = *(uint *)(param_1 + 0x18);
      puVar5 = *(uint **)(param_1 + 0x14);
      puVar11 = param_2;
      if (uVar8 != 0) {
        puVar11 = (undefined4 *)0x1f0000;
        do {
          if ((*puVar5 & 0x1f0000) != 0) {
            _mach_port_names_helper
                      (uVar2,puVar5,uVar7 << 8 | *puVar5 >> 0x18,uVar10,uVar9,
                       (undefined *)((int)register0x00000038 + -0x14));
          }
          uVar7 = uVar7 + 1;
          puVar5 = puVar5 + 4;
        } while (uVar7 < uVar8);
      }
      iVar3 = param_1 + 0x20;
      _ipc_splay_traverse_start();
      while (iVar3 != 0) {
        _mach_port_names_helper
                  (uVar2,iVar3,*(undefined4 *)(iVar3 + 0x10),uVar10,uVar9,
                   (undefined *)((int)register0x00000038 + -0x14));
        iVar3 = param_1 + 0x20;
        _ipc_splay_traverse_next(iVar3,0);
      }
      _ipc_splay_traverse_finish(param_1 + 0x20);
      iVar3 = *(int *)((int)register0x00000038 + -0x14);
      *(undefined4 *)(param_1 + 8) = 0;
      if (iVar3 == 0) {
        *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
        *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
        if (uVar6 != 0) {
          _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar6);
          iVar3 = *(int *)((int)register0x00000038 + -0x10);
loc_F0062214:
          _kmem_free(_ipc_kernel_map,iVar3,uVar6);
        }
      }
      else {
        uVar2 = iVar3 * 4 + _page_mask & ~_page_mask;
        _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc),
                         *(int *)((int)register0x00000038 + -0xc) + uVar2,1);
        _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0x10),
                         *(int *)((int)register0x00000038 + -0x10) + uVar2,1);
        _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,uVar2
                 ,1,(undefined *)((int)register0x00000038 + -0x18));
        _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),_ipc_soft_map,
                 uVar2,1,(undefined *)((int)register0x00000038 + -0x1c));
        bVar12 = uVar2 != uVar6;
        uVar6 = uVar6 - uVar2;
        if (bVar12) {
          _kmem_free(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc) + uVar2,uVar6);
          iVar3 = *(int *)((int)register0x00000038 + -0x10) + uVar2;
          goto loc_F0062214;
        }
      }
      *param_2 = *(undefined4 *)((int)register0x00000038 + -0x18);
      *param_3 = *(undefined4 *)((int)register0x00000038 + -0x14);
      *param_4 = *(undefined4 *)((int)register0x00000038 + -0x1c);
      uVar10 = 0;
      *param_5 = *(undefined4 *)((int)register0x00000038 + -0x14);
      param_2 = puVar11;
      goto locret_F0062240;
    }
    *(undefined4 *)(param_1 + 8) = 0;
    if (uVar6 != 0) {
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar6);
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar6);
    }
    iVar3 = _ipc_kernel_map;
    _vm_allocate(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar7,1);
    if (iVar3 != 0) goto loc_F0062164;
    iVar3 = _ipc_kernel_map;
    _vm_allocate(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0x10),uVar7,1);
    iVar4 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar3 == 0) {
      _vm_map_pageable(_ipc_kernel_map,iVar4,iVar4 + uVar7,0);
      _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0x10),
                       *(int *)((int)register0x00000038 + -0x10) + uVar7,0);
      uVar6 = uVar7;
      goto loc_F0061F28;
    }
    _kmem_free(_ipc_kernel_map,iVar4,uVar7);
loc_F0062164:
    uVar10 = 6;
  }
locret_F0062240:
  return CONCAT44(param_2,uVar10);
}

