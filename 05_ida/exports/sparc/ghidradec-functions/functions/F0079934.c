
/* WARNING: Removing unreachable block (ram,0xf0079ae8) */
/* WARNING: Removing unreachable block (ram,0xf0079ab0) */
/* WARNING: Removing unreachable block (ram,0xf0079a58) */
/* WARNING: Removing unreachable block (ram,0xf0079cdc) */
/* WARNING: Removing unreachable block (ram,0xf0079ca0) */
/* WARNING: Removing unreachable block (ram,0xf0079c28) */
/* WARNING: Removing unreachable block (ram,0xf0079bec) */
/* WARNING: Removing unreachable block (ram,0xf0079c60) */
/* WARNING: Removing unreachable block (ram,0xf0079c0c) */
/* WARNING: Removing unreachable block (ram,0xf0079d14) */
/* WARNING: Removing unreachable block (ram,0xf0079cc0) */
/* WARNING: Removing unreachable block (ram,0xf0079a44) */
/* WARNING: Removing unreachable block (ram,0xf0079a8c) */
/* WARNING: Removing unreachable block (ram,0xf0079ac4) */
/* WARNING: Removing unreachable block (ram,0xf0079b04) */
/* WARNING: Removing unreachable block (ram,0xf0079980) */

undefined8
_host_zone_free_space_info
          (int param_1,undefined4 *param_2,uint *param_3,undefined4 *param_4,uint *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined4 unaff_l1;
  uint uVar8;
  uint uVar9;
  undefined4 unaff_l3;
  uint uVar10;
  undefined4 unaff_l4;
  uint uVar11;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar12;
  uint uVar13;
  undefined4 unaff_i1;
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
    uVar12 = 0x16;
  }
  else {
    uVar8 = 0;
    uVar10 = 0;
loc_F007996C:
    do {
      uVar11 = 0;
      uVar7 = 0;
      do {
        do {
        } while (_zget_space_lock != 0);
        puVar6 = &_zget_space_lock;
        _simple_lock_try();
        uVar9 = 0;
      } while (puVar6 == (undefined4 *)0x0);
      uVar13 = 0;
      if (_zone_free_space_count != 0) {
        iVar1 = 0;
        do {
          uVar13 = uVar13 + 1;
          piVar4 = (int *)((int)&_zone_free_space + iVar1);
          iVar1 = iVar1 + 4;
          uVar9 = uVar9 + *(int *)(*piVar4 + 0xc);
        } while (uVar13 < _zone_free_space_count);
      }
      if (uVar13 < *param_3) {
        uVar7 = uVar13 * 0xc + _page_mask & ~_page_mask;
      }
      if (*param_5 < uVar9) {
        uVar11 = uVar9 * 8 + _page_mask & ~_page_mask;
      }
      if ((uVar7 <= uVar8) && (uVar11 <= uVar10)) {
        puVar6 = *(undefined4 **)((int)register0x00000038 + -0xc);
        if (uVar8 == 0) {
          puVar6 = (undefined4 *)*param_2;
        }
        piVar4 = *(int **)((int)register0x00000038 + -0x10);
        if (uVar10 == 0) {
          piVar4 = (int *)*param_4;
        }
        uVar7 = 0;
        if (uVar13 != 0) {
          iVar1 = 0;
          puVar5 = puVar6 + 2;
          do {
            puVar2 = *(undefined4 **)((int)&_zone_free_space + iVar1);
            *puVar6 = *puVar2;
            puVar5[-1] = puVar2[1];
            puVar6 = puVar6 + 3;
            *puVar5 = puVar2[3];
            puVar5 = puVar5 + 3;
            for (piVar3 = (int *)puVar2[2]; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
              *piVar4 = (int)piVar3;
              piVar4[1] = piVar3[1];
              piVar4 = piVar4 + 2;
            }
            uVar7 = uVar7 + 1;
            iVar1 = iVar1 + 4;
          } while (uVar7 < uVar13);
        }
        _zget_space_lock = 0;
        if ((uVar13 == 0) || (uVar8 == 0)) {
          if ((uVar13 == 0) && (*param_2 = 0, uVar8 != 0)) {
            _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar8);
          }
        }
        else {
          uVar7 = uVar13 * 0xc + _page_mask & ~_page_mask;
          _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc),
                           *(int *)((int)register0x00000038 + -0xc) + uVar7,1);
          _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),_ipc_soft_map,
                   uVar7,1,(undefined *)((int)register0x00000038 + -0x14));
          if (uVar7 != uVar8) {
            _kmem_free(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc) + uVar7,
                       uVar8 - uVar7);
          }
          *param_2 = *(undefined4 *)((int)register0x00000038 + -0x14);
        }
        *param_3 = uVar13;
        if ((uVar9 == 0) || (uVar10 == 0)) {
          if (uVar9 == 0) {
            *param_4 = 0;
            if (uVar10 != 0) {
              _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar10);
            }
            goto loc_F0079D1C;
          }
          *param_5 = uVar9;
        }
        else {
          uVar8 = uVar9 * 8 + _page_mask & ~_page_mask;
          _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0x10),
                           *(int *)((int)register0x00000038 + -0x10) + uVar8,1);
          _vm_move(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),_ipc_soft_map,
                   uVar8,1,(undefined *)((int)register0x00000038 + -0x18));
          if (uVar8 != uVar10) {
            _kmem_free(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0x10) + uVar8,
                       uVar10 - uVar8);
          }
          *param_4 = *(undefined4 *)((int)register0x00000038 + -0x18);
loc_F0079D1C:
          *param_5 = uVar9;
        }
        uVar12 = 0;
        goto locret_F0079D24;
      }
      _zget_space_lock = 0;
      if (uVar8 < uVar7) {
        if (uVar8 != 0) {
          _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc),uVar8);
        }
        iVar1 = _ipc_kernel_map;
        _kmem_alloc_pageable(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar7);
        if (iVar1 != 0) {
          if (uVar10 == 0) goto loc_F0079AF0;
          uVar12 = *(undefined4 *)((int)register0x00000038 + -0x10);
          uVar8 = uVar10;
          goto loc_F0079AE8;
        }
        _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0xc),
                         *(int *)((int)register0x00000038 + -0xc) + uVar7,0);
        uVar8 = uVar7;
      }
    } while (uVar11 <= uVar10);
    if (uVar10 != 0) {
      _kmem_free(_ipc_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x10),uVar10);
    }
    iVar1 = _ipc_kernel_map;
    _kmem_alloc_pageable(_ipc_kernel_map,(undefined *)((int)register0x00000038 + -0x10),uVar11);
    if (iVar1 == 0) {
      _vm_map_pageable(_ipc_kernel_map,*(int *)((int)register0x00000038 + -0x10),
                       *(int *)((int)register0x00000038 + -0x10) + uVar11,0);
      uVar10 = uVar11;
      goto loc_F007996C;
    }
    if (uVar8 != 0) {
      uVar12 = *(undefined4 *)((int)register0x00000038 + -0xc);
loc_F0079AE8:
      _kmem_free(_ipc_kernel_map,uVar12,uVar8);
    }
loc_F0079AF0:
    uVar12 = 6;
  }
locret_F0079D24:
  return CONCAT44(param_2,uVar12);
}
