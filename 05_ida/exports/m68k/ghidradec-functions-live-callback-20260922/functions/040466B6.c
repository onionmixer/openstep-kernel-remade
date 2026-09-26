
int _mach_port_get_set_status(int param_1,undefined4 param_2,undefined4 *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uStack_14;
  uint uStack_10;
  uint *puStack_c;
  int iStack_8;
  
  uVar7 = _page_size;
  if (param_1 == 0) {
    iVar3 = 0x10;
  }
  else {
    while (iVar3 = _vm_allocate(_ipc_kernel_map,&iStack_8,uVar7,1), iVar3 == 0) {
      _vm_map_pageable(_ipc_kernel_map,iStack_8,iStack_8 + uVar7,0);
      iVar4 = _ipc_right_lookup_write(param_1,param_2,&puStack_c);
      iVar3 = iStack_8;
      if (iVar4 != 0) {
        _kmem_free(_ipc_kernel_map,iStack_8,uVar7);
        return iVar4;
      }
      if ((*puStack_c & 0x1f0000) != 0x80000) {
        _kmem_free(_ipc_kernel_map,iStack_8,uVar7);
        return 0x11;
      }
      uVar1 = puStack_c[1];
      uVar6 = uVar7 >> 2;
      uStack_10 = 0;
      iVar4 = *(int *)(param_1 + 0xc);
      uVar2 = *(uint *)(param_1 + 0x10);
      uVar5 = 0;
      if (uVar2 != 0) {
        do {
          if ((*(byte *)(iVar4 + 1) & 2) != 0) {
            _mach_port_gst_helper(uVar1,*(undefined4 *)(iVar4 + 4),uVar6,iVar3,&uStack_10);
          }
          iVar4 = iVar4 + 0x10;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar2);
      }
      iVar4 = _ipc_splay_traverse_start(param_1 + 0x18);
      while (iVar4 != 0) {
        if ((*(byte *)(iVar4 + 1) & 2) != 0) {
          _mach_port_gst_helper(uVar1,*(undefined4 *)(iVar4 + 4),uVar6,iVar3,&uStack_10);
        }
        iVar4 = _ipc_splay_traverse_next(param_1 + 0x18,0);
      }
      _ipc_splay_traverse_finish(param_1 + 0x18);
      if (uStack_10 <= uVar6) {
        if (uStack_10 == 0) {
          uStack_14 = 0;
        }
        else {
          uVar1 = ~_page_mask & _page_mask + uStack_10 * 4;
          _vm_map_pageable(_ipc_kernel_map,iStack_8,iStack_8 + uVar1,1);
          _vm_move(_ipc_kernel_map,iStack_8,_ipc_soft_map,uVar1,1,&uStack_14);
          if (uVar7 == uVar1) goto loc_40468D0;
          uVar7 = uVar7 - uVar1;
          iStack_8 = iStack_8 + uVar1;
        }
        _kmem_free(_ipc_kernel_map,iStack_8,uVar7);
loc_40468D0:
        *param_3 = uStack_14;
        *param_4 = uStack_10;
        return 0;
      }
      _kmem_free(_ipc_kernel_map,iStack_8,uVar7);
      uVar7 = _page_size + (~_page_mask & _page_mask + uStack_10 * 4);
    }
    iVar3 = 6;
  }
  return iVar3;
}

