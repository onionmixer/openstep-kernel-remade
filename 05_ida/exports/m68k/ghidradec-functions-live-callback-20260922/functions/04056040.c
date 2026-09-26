
undefined4
_host_zone_free_space_info
          (int param_1,undefined4 *param_2,uint *param_3,undefined4 *param_4,uint *param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 *puStack_c;
  undefined4 *puStack_8;
  
  if (param_1 == 0) {
    return 0x16;
  }
  uVar11 = 0;
  uVar5 = 0;
  do {
    uVar7 = 0;
    uVar4 = 0;
    uVar6 = 0;
    uVar10 = 0;
    if (_zone_free_space_count != 0) {
      piVar3 = &_zone_free_space;
      do {
        uVar6 = *(int *)(*piVar3 + 0xc) + uVar6;
        uVar10 = uVar10 + 1;
        piVar3 = piVar3 + 1;
      } while (uVar10 < _zone_free_space_count);
    }
    if (uVar10 < *param_3) {
      uVar4 = ~_page_mask & _page_mask + uVar10 * 0xc;
    }
    if (*param_5 < uVar6) {
      uVar7 = ~_page_mask & _page_mask + uVar6 * 8;
    }
    if ((uVar4 <= uVar11) && (uVar7 <= uVar5)) {
      puVar9 = puStack_8;
      if (uVar11 == 0) {
        puVar9 = (undefined4 *)*param_2;
      }
      puVar8 = puStack_c;
      if (uVar5 == 0) {
        puVar8 = (undefined4 *)*param_4;
      }
      uVar4 = 0;
      if (uVar10 != 0) {
        piVar3 = &_zone_free_space;
        do {
          puVar1 = (undefined4 *)*piVar3;
          *puVar9 = *puVar1;
          puVar9[1] = puVar1[1];
          puVar9[2] = puVar1[3];
          puVar9 = puVar9 + 3;
          for (puVar1 = (undefined4 *)puVar1[2]; puVar1 != (undefined4 *)0x0;
              puVar1 = (undefined4 *)*puVar1) {
            *puVar8 = puVar1;
            puVar8[1] = puVar1[1];
            puVar8 = puVar8 + 2;
          }
          piVar3 = piVar3 + 1;
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar10);
      }
      if (uVar10 == 0) {
        *param_2 = 0;
        if (uVar11 != 0) {
          _kmem_free(_ipc_kernel_map,puStack_8,uVar11);
        }
      }
      else if (uVar11 != 0) {
        uVar4 = ~_page_mask & _page_mask + uVar10 * 0xc;
        _vm_map_pageable(_ipc_kernel_map,puStack_8,(int)puStack_8 + uVar4,1);
        _vm_move(_ipc_kernel_map,puStack_8,_ipc_soft_map,uVar4,1,&uStack_10);
        if (uVar11 != uVar4) {
          _kmem_free(_ipc_kernel_map,(int)puStack_8 + uVar4,uVar11 - uVar4);
        }
        *param_2 = uStack_10;
      }
      *param_3 = uVar10;
      if (uVar6 == 0) {
        *param_4 = 0;
        if (uVar5 != 0) {
          _kmem_free(_ipc_kernel_map,puStack_c,uVar5);
        }
      }
      else if (uVar5 != 0) {
        uVar11 = ~_page_mask & _page_mask + uVar6 * 8;
        _vm_map_pageable(_ipc_kernel_map,puStack_c,(int)puStack_c + uVar11,1);
        _vm_move(_ipc_kernel_map,puStack_c,_ipc_soft_map,uVar11,1,&uStack_14);
        if (uVar5 != uVar11) {
          _kmem_free(_ipc_kernel_map,(int)puStack_c + uVar11,uVar5 - uVar11);
        }
        *param_4 = uStack_14;
      }
      *param_5 = uVar6;
      return 0;
    }
    if (uVar11 < uVar4) {
      if (uVar11 != 0) {
        _kmem_free(_ipc_kernel_map,puStack_8,uVar11);
      }
      iVar2 = _kmem_alloc_pageable(_ipc_kernel_map,&puStack_8,uVar4);
      uVar11 = uVar5;
      puVar9 = puStack_c;
      if (iVar2 != 0) {
joined_r0x04056108:
        if (uVar11 != 0) {
          _kmem_free(_ipc_kernel_map,puVar9,uVar11);
        }
        return 6;
      }
      _vm_map_pageable(_ipc_kernel_map,puStack_8,uVar4 + (int)puStack_8,0);
      uVar11 = uVar4;
    }
    if (uVar5 < uVar7) {
      if (uVar5 != 0) {
        _kmem_free(_ipc_kernel_map,puStack_c,uVar5);
      }
      iVar2 = _kmem_alloc_pageable(_ipc_kernel_map,&puStack_c,uVar7);
      puVar9 = puStack_8;
      if (iVar2 != 0) goto joined_r0x04056108;
      _vm_map_pageable(_ipc_kernel_map,puStack_c,(int)puStack_c + uVar7,0);
      uVar5 = uVar7;
    }
  } while( true );
}

