/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016be1c */

undefined4
_host_zone_free_space_info
          (int param_1,undefined4 *param_2,uint *param_3,undefined4 *param_4,uint *param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *local_28;
  undefined4 *local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  if (param_1 == 0) {
    return 0x16;
  }
  local_1c = 0;
  local_18 = 0;
  do {
    local_28 = (undefined4 *)0x0;
    uVar4 = 0;
    do {
    } while (_zget_space_lock != 0);
    LOCK();
    UNLOCK();
    local_20 = 0;
    uVar5 = 0;
    if (_zone_free_space_count != 0) {
      do {
        local_20 = local_20 + *(int *)((&_zone_free_space)[uVar5] + 0xc);
        uVar5 = uVar5 + 1;
      } while (uVar5 < _zone_free_space_count);
    }
    if (uVar5 < *param_3) {
      uVar4 = _page_mask + uVar5 * 0xc & ~_page_mask;
    }
    if (*param_5 < local_20) {
      local_28 = (undefined4 *)(_page_mask + local_20 * 8 & ~_page_mask);
    }
    if ((uVar4 <= local_18) && (local_28 <= local_1c)) {
      if (local_18 == 0) {
        local_28 = (undefined4 *)*param_2;
      }
      else {
        local_28 = local_8;
      }
      puVar3 = local_c;
      if (local_1c == 0) {
        puVar3 = (undefined4 *)*param_4;
      }
      uVar4 = 0;
      if (uVar5 != 0) {
        local_24 = local_28 + 2;
        do {
          puVar1 = (undefined4 *)(&_zone_free_space)[uVar4];
          *local_28 = *puVar1;
          local_24[-1] = puVar1[1];
          *local_24 = puVar1[3];
          local_24 = local_24 + 3;
          local_28 = local_28 + 3;
          for (puVar1 = (undefined4 *)puVar1[2]; puVar1 != (undefined4 *)0x0;
              puVar1 = (undefined4 *)*puVar1) {
            *puVar3 = puVar1;
            puVar3[1] = puVar1[1];
            puVar3 = puVar3 + 2;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar5);
      }
      LOCK();
      _zget_space_lock = 0;
      UNLOCK();
      if (uVar5 == 0) {
        *param_2 = 0;
        if (local_18 != 0) {
          _kmem_free(_ipc_kernel_map,local_8,local_18);
        }
      }
      else if (local_18 != 0) {
        uVar4 = _page_mask + uVar5 * 0xc & ~_page_mask;
        _vm_map_pageable(_ipc_kernel_map,local_8,uVar4 + (int)local_8,1);
        _vm_move(_ipc_kernel_map,local_8,_ipc_soft_map,uVar4,1,&local_10);
        if (local_18 != uVar4) {
          _kmem_free(_ipc_kernel_map,(int)local_8 + uVar4,local_18 - uVar4);
        }
        *param_2 = local_10;
      }
      *param_3 = uVar5;
      if (local_20 == 0) {
        *param_4 = 0;
        if (local_1c != 0) {
          _kmem_free(_ipc_kernel_map,local_c,local_1c);
        }
      }
      else if (local_1c != 0) {
        uVar4 = _page_mask + local_20 * 8 & ~_page_mask;
        _vm_map_pageable(_ipc_kernel_map,local_c,uVar4 + (int)local_c,1);
        _vm_move(_ipc_kernel_map,local_c,_ipc_soft_map,uVar4,1,&local_14);
        if (local_1c != uVar4) {
          _kmem_free(_ipc_kernel_map,(int)local_c + uVar4,local_1c - uVar4);
        }
        *param_4 = local_14;
      }
      *param_5 = local_20;
      return 0;
    }
    LOCK();
    _zget_space_lock = 0;
    UNLOCK();
    if (local_18 < uVar4) {
      if (local_18 != 0) {
        _kmem_free(_ipc_kernel_map,local_8,local_18);
      }
      iVar2 = _kmem_alloc_pageable(_ipc_kernel_map,&local_8,uVar4);
      local_18 = local_1c;
      puVar3 = local_c;
      if (iVar2 != 0) {
joined_r0x0016bf21:
        if (local_18 != 0) {
          _kmem_free(_ipc_kernel_map,puVar3,local_18);
        }
        return 6;
      }
      _vm_map_pageable(_ipc_kernel_map,local_8,uVar4 + (int)local_8,0);
      local_18 = uVar4;
    }
    if (local_1c < local_28) {
      if (local_1c != 0) {
        _kmem_free(_ipc_kernel_map,local_c,local_1c);
      }
      local_1c = (uint)local_28;
      iVar2 = _kmem_alloc_pageable(_ipc_kernel_map,&local_c,local_28);
      puVar3 = local_8;
      if (iVar2 != 0) goto joined_r0x0016bf21;
      _vm_map_pageable(_ipc_kernel_map,local_c,(int)local_28 + (int)local_c,0);
    }
  } while( true );
}

