
undefined4
_mach_port_names(int param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  if (param_1 != 0) {
    uVar8 = 0;
    while (iVar2 = iStack_8, iVar3 = iStack_c, *(int *)(param_1 + 4) != 0) {
      uVar1 = ~_page_mask & _page_mask + (*(int *)(param_1 + 0x30) + *(int *)(param_1 + 0x10)) * 4;
      if (uVar1 <= uVar8) {
        iStack_10 = 0;
        uVar4 = _ipc_port_timestamp();
        puVar7 = *(uint **)(param_1 + 0xc);
        uVar1 = *(uint *)(param_1 + 0x10);
        uVar6 = 0;
        if (uVar1 != 0) {
          do {
            if ((*puVar7 & 0x1f0000) != 0) {
              _mach_port_names_helper
                        (uVar4,puVar7,*puVar7 >> 0x18 | uVar6 << 8,iVar2,iVar3,&iStack_10);
            }
            puVar7 = puVar7 + 4;
            uVar6 = uVar6 + 1;
          } while (uVar6 < uVar1);
        }
        iVar5 = _ipc_splay_traverse_start(param_1 + 0x18);
        while (iVar5 != 0) {
          _mach_port_names_helper(uVar4,iVar5,*(undefined4 *)(iVar5 + 0x10),iVar2,iVar3,&iStack_10);
          iVar5 = _ipc_splay_traverse_next(param_1 + 0x18,0);
        }
        _ipc_splay_traverse_finish(param_1 + 0x18);
        if (iStack_10 == 0) {
          uStack_14 = 0;
          uStack_18 = 0;
          if (uVar8 == 0) goto loc_4046238;
          _kmem_free(_ipc_kernel_map,iStack_8,uVar8);
        }
        else {
          uVar1 = ~_page_mask & _page_mask + iStack_10 * 4;
          _vm_map_pageable(_ipc_kernel_map,iStack_8,iStack_8 + uVar1,1);
          _vm_map_pageable(_ipc_kernel_map,iStack_c,iStack_c + uVar1,1);
          _vm_move(_ipc_kernel_map,iStack_8,_ipc_soft_map,uVar1,1,&uStack_14);
          _vm_move(_ipc_kernel_map,iStack_c,_ipc_soft_map,uVar1,1,&uStack_18);
          if (uVar8 == uVar1) goto loc_4046238;
          uVar8 = uVar8 - uVar1;
          _kmem_free(_ipc_kernel_map,uVar1 + iStack_8,uVar8);
          iStack_c = iStack_c + uVar1;
        }
        _kmem_free(_ipc_kernel_map,iStack_c,uVar8);
loc_4046238:
        *param_2 = uStack_14;
        *param_3 = iStack_10;
        *param_4 = uStack_18;
        *param_5 = iStack_10;
        return 0;
      }
      if (uVar8 != 0) {
        _kmem_free(_ipc_kernel_map,iStack_8,uVar8);
        _kmem_free(_ipc_kernel_map,iStack_c,uVar8);
      }
      iVar3 = _vm_allocate(_ipc_kernel_map,&iStack_8,uVar1,1);
      if (iVar3 != 0) {
        return 6;
      }
      iVar3 = _vm_allocate(_ipc_kernel_map,&iStack_c,uVar1,1);
      if (iVar3 != 0) {
        _kmem_free(_ipc_kernel_map,iStack_8,uVar1);
        return 6;
      }
      _vm_map_pageable(_ipc_kernel_map,iStack_8,uVar1 + iStack_8,0);
      _vm_map_pageable(_ipc_kernel_map,iStack_c,uVar1 + iStack_c,0);
      uVar8 = uVar1;
    }
    if (uVar8 != 0) {
      _kmem_free(_ipc_kernel_map,iStack_8,uVar8);
      _kmem_free(_ipc_kernel_map,iStack_c,uVar8);
    }
  }
  return 0x10;
}
