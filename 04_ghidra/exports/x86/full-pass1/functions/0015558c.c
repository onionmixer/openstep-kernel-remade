/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015558c */

kern_return_t
_mach_port_get_set_status
          (ipc_space_t task,mach_port_name_t name,mach_port_name_array_t *members,
          mach_msg_type_number_t *membersCnt)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  vm_address_t vVar4;
  kern_return_t kVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint local_34;
  uint local_1c;
  mach_port_name_array_t local_14;
  uint local_10;
  uint *local_c;
  vm_address_t local_8;
  
  if (task == 0) {
    kVar5 = 0x10;
  }
  else {
    local_1c = _page_size;
    iVar9 = task + 0x20;
    while (kVar5 = _vm_allocate(_ipc_kernel_map,&local_8,local_1c,1), kVar5 == 0) {
      _vm_map_pageable(_ipc_kernel_map,local_8,local_1c + local_8,0);
      iVar6 = _ipc_right_lookup_write(task,name,&local_c);
      vVar4 = local_8;
      if (iVar6 != 0) {
        _kmem_free(_ipc_kernel_map,local_8,local_1c);
        return iVar6;
      }
      if ((*local_c & 0x1f0000) != 0x80000) {
        LOCK();
        *(undefined4 *)(task + 8) = 0;
        UNLOCK();
        _kmem_free(_ipc_kernel_map,local_8,local_1c);
        return 0x11;
      }
      uVar7 = local_c[1];
      uVar8 = local_1c >> 2;
      local_10 = 0;
      iVar6 = *(int *)(task + 0x14);
      uVar2 = *(uint *)(task + 0x18);
      local_34 = 0;
      if (uVar2 != 0) {
        do {
          if ((*(byte *)(iVar6 + 2) & 2) != 0) {
            piVar3 = *(int **)(iVar6 + 4);
            do {
              do {
              } while (*piVar3 != 0);
              LOCK();
              iVar1 = *piVar3;
              *piVar3 = 1;
              UNLOCK();
            } while (iVar1 == 1);
            LOCK();
            *piVar3 = 0;
            UNLOCK();
            if (uVar7 == piVar3[0xc]) {
              if (local_10 < uVar8) {
                *(int *)(local_8 + local_10 * 4) = piVar3[4];
              }
              local_10 = local_10 + 1;
            }
          }
          iVar6 = iVar6 + 0x10;
          local_34 = local_34 + 1;
        } while (local_34 < uVar2);
      }
      iVar6 = _ipc_splay_traverse_start(iVar9);
      while (iVar6 != 0) {
        if ((*(byte *)(iVar6 + 2) & 2) != 0) {
          piVar3 = *(int **)(iVar6 + 4);
          do {
            do {
            } while (*piVar3 != 0);
            LOCK();
            iVar6 = *piVar3;
            *piVar3 = 1;
            UNLOCK();
          } while (iVar6 == 1);
          LOCK();
          *piVar3 = 0;
          UNLOCK();
          if (uVar7 == piVar3[0xc]) {
            if (local_10 < uVar8) {
              *(int *)(vVar4 + local_10 * 4) = piVar3[4];
            }
            local_10 = local_10 + 1;
          }
        }
        iVar6 = _ipc_splay_traverse_next(iVar9,0);
      }
      _ipc_splay_traverse_finish(iVar9);
      LOCK();
      *(undefined4 *)(task + 8) = 0;
      UNLOCK();
      if (local_10 <= uVar8) {
        if (local_10 == 0) {
          local_14 = (mach_port_name_array_t)0x0;
        }
        else {
          uVar7 = _page_mask + local_10 * 4 & ~_page_mask;
          _vm_map_pageable(_ipc_kernel_map,local_8,uVar7 + local_8,1);
          _vm_move(_ipc_kernel_map,local_8,_ipc_soft_map,uVar7,1,&local_14);
          if (local_1c == uVar7) goto LAB_0015583a;
          local_1c = local_1c - uVar7;
          local_8 = local_8 + uVar7;
        }
        _kmem_free(_ipc_kernel_map,local_8,local_1c);
LAB_0015583a:
        *members = local_14;
        *membersCnt = local_10;
        return 0;
      }
      _kmem_free(_ipc_kernel_map,local_8,local_1c);
      local_1c = (local_10 * 4 + _page_mask & ~_page_mask) + _page_size;
    }
    kVar5 = 6;
  }
  return kVar5;
}

