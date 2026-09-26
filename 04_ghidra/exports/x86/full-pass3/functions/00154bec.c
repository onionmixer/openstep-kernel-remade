/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00154bec */

kern_return_t
_mach_port_names(ipc_space_t task,mach_port_name_array_t *names,mach_msg_type_number_t *namesCnt,
                mach_port_type_array_t *types,mach_msg_type_number_t *typesCnt)

{
  int iVar1;
  bool bVar2;
  vm_address_t vVar3;
  vm_address_t vVar4;
  kern_return_t kVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  uint uVar13;
  uint *local_3c;
  uint local_38;
  uint local_30;
  uint local_20;
  mach_port_type_array_t local_18;
  mach_port_name_array_t local_14;
  mach_msg_type_number_t local_10;
  vm_address_t local_c;
  vm_address_t local_8;
  
  if (task == 0) {
    return 0x10;
  }
  local_30 = 0;
  piVar12 = (int *)(task + 8);
  while( true ) {
    do {
      vVar4 = local_8;
      vVar3 = local_c;
      do {
      } while (*piVar12 != 0);
      LOCK();
      iVar6 = *piVar12;
      *piVar12 = 1;
      UNLOCK();
    } while (iVar6 == 1);
    if (*(int *)(task + 0xc) == 0) {
      LOCK();
      *(undefined4 *)(task + 8) = 0;
      UNLOCK();
      if (local_30 == 0) {
        return 0x10;
      }
      _kmem_free(_ipc_kernel_map,local_8,local_30);
      _kmem_free(_ipc_kernel_map,local_c,local_30);
      return 0x10;
    }
    uVar10 = _page_mask + (*(int *)(task + 0x18) + *(int *)(task + 0x38)) * 4 & ~_page_mask;
    if (uVar10 <= local_30) break;
    LOCK();
    *(undefined4 *)(task + 8) = 0;
    UNLOCK();
    if (local_30 != 0) {
      _kmem_free(_ipc_kernel_map,local_8,local_30);
      _kmem_free(_ipc_kernel_map,local_c,local_30);
    }
    kVar5 = _vm_allocate(_ipc_kernel_map,&local_8,uVar10,1);
    if (kVar5 != 0) {
      return 6;
    }
    kVar5 = _vm_allocate(_ipc_kernel_map,&local_c,uVar10,1);
    if (kVar5 != 0) {
      _kmem_free(_ipc_kernel_map,local_8,uVar10);
      return 6;
    }
    _vm_map_pageable(_ipc_kernel_map,local_8,uVar10 + local_8,0);
    _vm_map_pageable(_ipc_kernel_map,local_c,uVar10 + local_c,0);
    local_30 = uVar10;
  }
  local_10 = 0;
  iVar6 = _ipc_port_timestamp();
  local_3c = *(uint **)(task + 0x14);
  uVar10 = *(uint *)(task + 0x18);
  local_20 = 0;
  if (uVar10 != 0) {
    local_38 = 0;
    do {
      uVar9 = *local_3c;
      if ((uVar9 & 0x1f0000) != 0) {
        uVar7 = uVar9 >> 0x18;
        uVar13 = local_3c[2];
        if ((uVar9 & 0x50000) != 0) {
          piVar12 = (int *)local_3c[1];
          do {
            do {
            } while (*piVar12 != 0);
            LOCK();
            iVar1 = *piVar12;
            *piVar12 = 1;
            UNLOCK();
          } while (iVar1 == 1);
          bVar2 = false;
          if ((-1 < piVar12[2]) && (piVar12[3] - iVar6 < 0)) {
            bVar2 = true;
          }
          LOCK();
          *piVar12 = 0;
          UNLOCK();
          if (bVar2) {
            if ((uVar9 & 0x400000) != 0) goto LAB_00154e4a;
            uVar9 = uVar9 & 0xffc0ffff | 0x100000;
            if (uVar13 != 0) {
              uVar9 = uVar9 + 1;
            }
            uVar13 = 0;
          }
        }
        uVar11 = uVar9 & 0x1f0000;
        if ((uVar9 & 0x400000) == 0) {
          if (uVar13 != 0) {
            uVar11 = uVar11 | 0x80000000;
          }
        }
        else {
          uVar11 = uVar11 | 0x20000000;
        }
        if ((uVar9 & 0x200000) != 0) {
          uVar11 = uVar11 | 0x40000000;
        }
        *(uint *)(vVar4 + local_10 * 4) = uVar7 | local_38;
        *(uint *)(vVar3 + local_10 * 4) = uVar11;
        local_10 = local_10 + 1;
      }
LAB_00154e4a:
      local_38 = local_38 + 0x100;
      local_3c = local_3c + 4;
      local_20 = local_20 + 1;
    } while (local_20 < uVar10);
  }
  puVar8 = (uint *)_ipc_splay_traverse_start(task + 0x20);
  while (puVar8 != (uint *)0x0) {
    uVar10 = puVar8[4];
    uVar9 = *puVar8;
    uVar13 = puVar8[2];
    if ((uVar9 & 0x50000) == 0) {
LAB_00154ee5:
      uVar7 = uVar9 & 0x1f0000;
      if ((uVar9 & 0x400000) == 0) {
        if (uVar13 != 0) {
          uVar7 = uVar7 | 0x80000000;
        }
      }
      else {
        uVar7 = uVar7 | 0x20000000;
      }
      if ((uVar9 & 0x200000) != 0) {
        uVar7 = uVar7 | 0x40000000;
      }
      *(uint *)(vVar4 + local_10 * 4) = uVar10;
      *(uint *)(vVar3 + local_10 * 4) = uVar7;
      local_10 = local_10 + 1;
    }
    else {
      piVar12 = (int *)puVar8[1];
      do {
        do {
        } while (*piVar12 != 0);
        LOCK();
        iVar1 = *piVar12;
        *piVar12 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      bVar2 = false;
      if ((-1 < piVar12[2]) && (piVar12[3] - iVar6 < 0)) {
        bVar2 = true;
      }
      LOCK();
      *piVar12 = 0;
      UNLOCK();
      if (!bVar2) goto LAB_00154ee5;
      if ((uVar9 & 0x400000) == 0) {
        uVar9 = uVar9 & 0xffc0ffff | 0x100000;
        if (uVar13 != 0) {
          uVar9 = uVar9 + 1;
        }
        uVar13 = 0;
        goto LAB_00154ee5;
      }
    }
    puVar8 = (uint *)_ipc_splay_traverse_next(task + 0x20,0);
  }
  _ipc_splay_traverse_finish(task + 0x20);
  LOCK();
  *(undefined4 *)(task + 8) = 0;
  UNLOCK();
  if (local_10 == 0) {
    local_14 = (mach_port_name_array_t)0x0;
    local_18 = (mach_port_type_array_t)0x0;
    if (local_30 == 0) goto LAB_00155078;
    _kmem_free(_ipc_kernel_map,local_8,local_30);
  }
  else {
    uVar10 = _page_mask + local_10 * 4 & ~_page_mask;
    _vm_map_pageable(_ipc_kernel_map,local_8,uVar10 + local_8,1);
    _vm_map_pageable(_ipc_kernel_map,local_c,uVar10 + local_c,1);
    _vm_move(_ipc_kernel_map,local_8,_ipc_soft_map,uVar10,1,&local_14);
    _vm_move(_ipc_kernel_map,local_c,_ipc_soft_map,uVar10,1,&local_18);
    if (local_30 == uVar10) goto LAB_00155078;
    local_30 = local_30 - uVar10;
    _kmem_free(_ipc_kernel_map,local_8 + uVar10,local_30);
    local_c = local_c + uVar10;
  }
  _kmem_free(_ipc_kernel_map,local_c,local_30);
LAB_00155078:
  *names = local_14;
  *namesCnt = local_10;
  *types = local_18;
  *typesCnt = local_10;
  return 0;
}

