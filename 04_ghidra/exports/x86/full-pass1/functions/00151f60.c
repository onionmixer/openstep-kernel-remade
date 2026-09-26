/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00151f60 */

kern_return_t
_mach_port_space_info
          (ipc_space_t task,ipc_info_space_t *space_info,ipc_info_name_array_t *table_info,
          mach_msg_type_number_t *table_infoCnt,ipc_info_tree_name_array_t *tree_info,
          mach_msg_type_number_t *tree_infoCnt)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  kern_return_t kVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  ipc_info_tree_name_array_t piVar10;
  uint local_38;
  uint local_2c;
  ipc_info_tree_name_array_t local_24;
  uint local_20;
  ipc_info_tree_name_array_t local_18;
  ipc_info_tree_name_array_t local_14;
  ipc_info_name_array_t local_10;
  ipc_info_tree_name_array_t local_c;
  ipc_info_tree_name_array_t local_8;
  
  local_20 = 0;
  local_2c = 0;
  if (task == 0) {
LAB_00151f7d:
    kVar4 = 0x10;
  }
  else {
    local_18 = (ipc_info_tree_name_array_t)*table_info;
    uVar7 = *table_infoCnt;
    local_24 = *tree_info;
    uVar8 = *tree_infoCnt;
    piVar5 = (int *)(task + 8);
    while( true ) {
      do {
        do {
          do {
          } while (*piVar5 != 0);
          LOCK();
          iVar6 = *piVar5;
          *piVar5 = 1;
          UNLOCK();
        } while (iVar6 == 1);
        if (*(int *)(task + 0xc) == 0) {
          LOCK();
          *(undefined4 *)(task + 8) = 0;
          UNLOCK();
          if ((ipc_info_tree_name_array_t)*table_info != local_18) {
            _kmem_free(_ipc_kernel_map,local_8,local_20);
          }
          if (*tree_info != local_24) {
            _kmem_free(_ipc_kernel_map,local_c,local_2c);
          }
          goto LAB_00151f7d;
        }
        uVar1 = *(uint *)(task + 0x18);
        uVar2 = *(uint *)(task + 0x38);
        if ((uVar1 <= uVar7) && (uVar2 <= uVar8)) {
          space_info->iis_genno_mask = 0xff;
          space_info->iis_table_size = *(natural_t *)(task + 0x18);
          space_info->iis_table_next = **(natural_t **)(task + 0x1c);
          space_info->iis_tree_size = *(natural_t *)(task + 0x38);
          space_info->iis_tree_small = *(natural_t *)(task + 0x3c);
          space_info->iis_tree_hash = *(natural_t *)(task + 0x40);
          puVar9 = *(uint **)(task + 0x14);
          uVar7 = *(uint *)(task + 0x18);
          uVar8 = 0;
          if (uVar7 != 0) {
            local_38 = 0;
            piVar10 = local_18;
            do {
              uVar3 = *puVar9;
              (piVar10->iitn_name).iin_name = uVar3 >> 0x18 | local_38;
              (piVar10->iitn_name).iin_collision = uVar3 >> 0x17 & 1;
              (piVar10->iitn_name).iin_type = uVar3 >> 0x16 & 1;
              (piVar10->iitn_name).iin_urefs = uVar3 >> 0x15 & 1;
              (piVar10->iitn_name).iin_object = uVar3 & 0x1f0000;
              (piVar10->iitn_name).iin_next = uVar3 & 0xffff;
              (piVar10->iitn_name).iin_hash = puVar9[1];
              piVar10->iitn_lchild = puVar9[2];
              piVar10->iitn_rchild = puVar9[3];
              piVar10 = piVar10 + 1;
              local_38 = local_38 + 0x100;
              puVar9 = puVar9 + 4;
              uVar8 = uVar8 + 1;
            } while (uVar8 < uVar7);
          }
          puVar9 = (uint *)_ipc_splay_traverse_start(task + 0x20);
          piVar10 = local_24;
          while (puVar9 != (uint *)0x0) {
            uVar7 = *puVar9;
            (piVar10->iitn_name).iin_name = puVar9[4];
            (piVar10->iitn_name).iin_collision = uVar7 >> 0x17 & 1;
            (piVar10->iitn_name).iin_type = uVar7 >> 0x16 & 1;
            (piVar10->iitn_name).iin_urefs = uVar7 >> 0x15 & 1;
            (piVar10->iitn_name).iin_object = uVar7 & 0x1f0000;
            (piVar10->iitn_name).iin_next = uVar7 & 0xffff;
            (piVar10->iitn_name).iin_hash = puVar9[1];
            piVar10->iitn_lchild = puVar9[2];
            piVar10->iitn_rchild = puVar9[3];
            if (puVar9[6] == 0) {
              piVar10[1].iitn_name.iin_name = 0;
            }
            else {
              piVar10[1].iitn_name.iin_name = *(mach_port_type_t *)(puVar9[6] + 0x10);
            }
            if (puVar9[7] == 0) {
              piVar10[1].iitn_name.iin_collision = 0;
            }
            else {
              piVar10[1].iitn_name.iin_collision = *(mach_port_urefs_t *)(puVar9[7] + 0x10);
            }
            puVar9 = (uint *)_ipc_splay_traverse_next(task + 0x20,0);
            piVar10 = (ipc_info_tree_name_array_t)&piVar10[1].iitn_name.iin_type;
          }
          _ipc_splay_traverse_finish(task + 0x20);
          LOCK();
          *(undefined4 *)(task + 8) = 0;
          UNLOCK();
          if ((ipc_info_tree_name_array_t)*table_info == local_18) {
            *table_infoCnt = uVar1;
          }
          else if (uVar1 == 0) {
            _kmem_free(_ipc_kernel_map,local_8,local_20);
            *table_infoCnt = 0;
          }
          else {
            uVar7 = ~_page_mask & _page_mask + uVar1 * 0x24;
            if (local_20 != uVar7) {
              _kmem_free(_ipc_kernel_map,(int)&(local_8->iitn_name).iin_name + uVar7,
                         local_20 - uVar7);
            }
            if (uVar1 * 0x24 - uVar7 != 0) {
              _bzero(local_8 + uVar1,uVar7 + uVar1 * -0x24);
            }
            _vm_move(_ipc_kernel_map,local_8,_ipc_soft_map,uVar7,1,&local_10);
            *table_info = local_10;
            *table_infoCnt = uVar1;
          }
          if (*tree_info != local_24) {
            if (uVar2 == 0) {
              _kmem_free(_ipc_kernel_map,local_c,local_2c);
              *tree_infoCnt = 0;
              return 0;
            }
            iVar6 = uVar2 * 0x2c;
            uVar7 = ~_page_mask & _page_mask + iVar6;
            if (local_2c != uVar7) {
              _kmem_free(_ipc_kernel_map,(int)&(local_c->iitn_name).iin_name + uVar7,
                         local_2c - uVar7);
            }
            if (iVar6 - uVar7 != 0) {
              _bzero((void *)((int)local_c + iVar6),uVar7 + uVar2 * -0x2c);
            }
            _vm_move(_ipc_kernel_map,local_c,_ipc_soft_map,uVar7,1,&local_14);
            *tree_info = local_14;
          }
          *tree_infoCnt = uVar2;
          return 0;
        }
        LOCK();
        *(undefined4 *)(task + 8) = 0;
        UNLOCK();
        if (uVar7 < uVar1) {
          if ((ipc_info_tree_name_array_t)*table_info != local_18) {
            _kmem_free(_ipc_kernel_map,local_8,local_20);
          }
          local_20 = ~_page_mask & _page_mask + uVar1 * 0x24;
          iVar6 = _kmem_alloc(_ipc_kernel_map,&local_8,local_20);
          if (iVar6 != 0) {
            if (*tree_info == local_24) goto LAB_0015214c;
            goto LAB_00152147;
          }
          local_18 = local_8;
          uVar7 = local_20 / 0x24;
        }
      } while (uVar2 <= uVar8);
      if (*tree_info != local_24) {
        _kmem_free(_ipc_kernel_map,local_c,local_2c);
      }
      local_2c = ~_page_mask & _page_mask + uVar2 * 0x2c;
      iVar6 = _kmem_alloc(_ipc_kernel_map,&local_c,local_2c);
      if (iVar6 != 0) break;
      local_24 = local_c;
      uVar8 = local_2c / 0x2c;
    }
    local_c = local_8;
    local_2c = local_20;
    if ((ipc_info_tree_name_array_t)*table_info != local_18) {
LAB_00152147:
      _kmem_free(_ipc_kernel_map,local_c,local_2c);
    }
LAB_0015214c:
    kVar4 = 6;
  }
  return kVar4;
}

