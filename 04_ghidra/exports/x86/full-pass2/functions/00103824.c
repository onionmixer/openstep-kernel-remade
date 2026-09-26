/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00103824 */

bool _core(void)

{
  int iVar1;
  int *piVar2;
  vm_map_t target_task;
  undefined1 uVar3;
  int iVar4;
  kern_return_t kVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int local_10c;
  int local_108;
  int *local_104;
  int local_fc;
  int local_f4;
  int local_f0;
  int local_e8;
  mach_port_t local_d8;
  mach_msg_type_number_t local_d4;
  uint local_d0;
  uint local_cc;
  vm_size_t local_c8;
  vm_address_t local_c4;
  undefined4 *local_c0;
  uint local_bc;
  int local_b8;
  int local_b4 [20];
  char local_64 [32];
  undefined4 local_44;
  undefined2 local_40;
  short local_30;
  undefined4 local_2c;
  
  if ((*(byte *)(*_active_u + 0x2b) & 2) == 0) {
    *(undefined2 *)(_active_u[7] + 2) = *(undefined2 *)(_active_u[7] + 6);
    *(undefined2 *)(*_active_u + 0x2c) = *(undefined2 *)(_active_u[7] + 6);
    *(undefined2 *)(_active_u[7] + 4) = *(undefined2 *)(_active_u[7] + 8);
    *(undefined1 *)(_active_u + 0x98) = 0;
    piVar2 = *(int **)(_active_threads + 0xc);
    target_task = piVar2[3];
    if (*(uint *)(target_task + 0x28) < (uint)_active_u[0xa1]) {
      _task_halt(piVar2);
      _pcb_synch(_active_threads);
      *(undefined1 *)(DAT_001e875c + 0x68) = 0;
      _vattr_null(&local_44);
      local_44 = 1;
      local_40 = 0x1a4;
      _sprintf(local_64,s__cores_core__d_001da62a,(int)*(short *)(*_active_u + 0x30));
      uVar3 = _vn_create(local_64,1,&local_44,0,0x80,&local_b8,_active_u[7]);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
      if (*(char *)(DAT_001e875c + 0x68) != '\0') {
        *(undefined1 *)(DAT_001e875c + 0x68) = 0;
        _vattr_null(&local_44);
        local_44 = 1;
        local_40 = 0x1a4;
        uVar3 = _vn_create(&DAT_001da639,1,&local_44,0,0x80,&local_b8,_active_u[7]);
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
        if (*(char *)(DAT_001e875c + 0x68) != '\0') {
          return false;
        }
      }
      if (local_30 == 1) {
        _vattr_null(&local_44);
        local_2c = 0;
        (**(code **)(*(int *)(local_b8 + 0x1c) + 0x18))(local_b8,&local_44,_active_u[7]);
        *(byte *)(_active_u + 0x91) = *(byte *)(_active_u + 0x91) | 8;
        local_e8 = piVar2[9];
        iVar7 = *(int *)(target_task + 0x1c);
        local_bc = 0x14;
        iVar4 = _thread_getstatus(_active_threads,0,local_b4,&local_bc);
        if (iVar4 != 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_core_flavor_list_001da63e);
        }
        local_bc = local_bc >> 1;
        local_f0 = 0;
        uVar8 = 0;
        if (local_bc != 0) {
          local_10c = 0;
          do {
            local_f0 = *(int *)(local_10c + 4 + (int)local_b4) * 4 + 8 + local_f0;
            local_10c = local_10c + 8;
            uVar8 = uVar8 + 1;
          } while (uVar8 < local_bc);
        }
        iVar1 = local_f0 * local_e8 + (iVar7 * 7 + local_e8) * 8;
        iVar4 = iVar1 + 0x1c;
        _kmem_alloc_wired(_kernel_map,&local_c0,iVar4);
        *local_c0 = 0xfeedface;
        local_c0[1] = DAT_001e8e04;
        local_c0[2] = DAT_001e8e08;
        local_c0[3] = 4;
        local_c0[4] = local_e8 + iVar7;
        local_c0[5] = iVar1;
        local_f4 = 0x1c;
        uVar8 = iVar4 + _page_mask & ~_page_mask;
        local_c4 = 0;
        while ((0 < iVar7 &&
               (kVar5 = _vm_region(target_task,&local_c4,&local_c8,(vm_region_flavor_t)&local_cc,
                                   (vm_region_info_t)&local_d0,&local_d4,&local_d8), kVar5 != 3))) {
          puVar6 = (undefined4 *)(local_f4 + (int)local_c0);
          *puVar6 = 1;
          puVar6[1] = 0x38;
          puVar6[6] = local_c4;
          puVar6[7] = local_c8;
          puVar6[8] = uVar8;
          puVar6[9] = local_c8;
          puVar6[10] = local_d0;
          puVar6[0xb] = local_cc;
          puVar6[0xc] = 0;
          if ((local_cc & 1) == 0) {
            _vm_protect(target_task,local_c4,local_c8,0,local_cc | 1);
          }
          if ((local_d0 & 1) != 0) {
            _vn_rdwr(1,local_b8,local_c4,local_c8,uVar8,0,1,0);
          }
          local_f4 = local_f4 + 0x38;
          uVar8 = uVar8 + local_c8;
          local_c4 = local_c4 + local_c8;
          iVar7 = iVar7 + -1;
        }
        do {
          do {
          } while (*piVar2 != 0);
          LOCK();
          iVar7 = *piVar2;
          *piVar2 = 1;
          UNLOCK();
        } while (iVar7 == 1);
        local_fc = piVar2[7];
        if (0 < local_e8) {
          do {
            *(undefined4 *)(local_f4 + (int)local_c0) = 4;
            ((undefined4 *)(local_f4 + (int)local_c0))[1] = local_f0 + 8;
            local_f4 = local_f4 + 8;
            uVar8 = 0;
            if (local_bc != 0) {
              local_108 = 0;
              local_104 = local_b4;
              do {
                iVar7 = local_b4[uVar8 * 2 + 1];
                *(int *)(local_f4 + (int)local_c0) = local_b4[uVar8 * 2];
                *(int *)(local_f4 + 4 + (int)local_c0) = iVar7;
                _thread_getstatus(local_fc,*local_104,(int)local_c0 + local_f4 + 8,local_104 + 1);
                local_f4 = local_f4 + 8 + *(int *)(local_108 + 4 + (int)local_b4) * 4;
                local_104 = local_104 + 2;
                local_108 = local_108 + 8;
                uVar8 = uVar8 + 1;
              } while (uVar8 < local_bc);
            }
            local_fc = *(int *)(local_fc + 0x10);
            local_e8 = local_e8 + -1;
          } while (0 < local_e8);
        }
        LOCK();
        *piVar2 = 0;
        UNLOCK();
        iVar7 = _vn_rdwr(1,local_b8,local_c0,iVar4,0,1,1,0);
        _kmem_free(_kernel_map,local_c0,iVar4);
      }
      else {
        iVar7 = 0xe;
      }
      _vn_rele(local_b8);
      *(char *)(DAT_001e875c + 0x68) = (char)iVar7;
      return iVar7 == 0;
    }
  }
  return false;
}

