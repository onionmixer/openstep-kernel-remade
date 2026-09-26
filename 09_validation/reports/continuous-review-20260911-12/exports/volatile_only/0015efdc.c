
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _mfs_io(int *param_1,int param_2,int param_3,uint param_4,short *param_5)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined4 *puVar14;
  int iVar15;
  uint uVar16;
  uint local_28;
  int local_24;
  uint local_1c;
  uint local_c;
  undefined4 local_8;
  
  iVar11 = *(int *)(param_2 + 0x14);
  if (iVar11 == 0) {
    iVar11 = 0;
  }
  else {
    iVar2 = *(int *)(param_2 + 8);
    if ((iVar2 < 0) || (iVar11 + iVar2 < 0)) {
      iVar11 = 0x16;
    }
    else {
      _mfs_get(param_1,iVar2,iVar11);
      iVar2 = *param_1;
      iVar3 = *(int *)(iVar2 + 0x14);
      if ((param_3 == 1) && ((param_4 & 2) != 0)) {
        *(int *)(param_2 + 8) = iVar3;
      }
      uVar16 = *(uint *)(param_2 + 8);
      iVar4 = *(int *)(param_2 + 0x14);
      uVar5 = *(uint *)(param_1[9] + 0x10);
      if ((param_3 == 1) || ((param_3 == 0 && (*(int *)(iVar2 + 0x30) == 0)))) {
        *param_5 = *param_5 + 1;
        if (*(int *)(iVar2 + 0x30) != 0) {
          _crfree(*(int *)(iVar2 + 0x30));
        }
        *(short **)(iVar2 + 0x30) = param_5;
      }
      *(undefined4 *)(iVar2 + 0x34) = 0;
      local_1c = *(uint *)(param_2 + 8);
      local_24 = 0;
      do {
        local_c = uVar5;
        if (*(uint *)(param_2 + 0x14) <= uVar5) {
          local_c = *(uint *)(param_2 + 0x14);
        }
        if (param_3 == 0) {
          uVar13 = iVar3 - *(int *)(param_2 + 8);
          if ((int)uVar13 < 1) {
            _vmp_put(*param_1);
            return 0;
          }
          if ((int)uVar13 < (int)local_c) {
            local_c = uVar13;
          }
        }
        if ((param_3 == 1) &&
           (uVar13 = local_c + *(int *)(param_2 + 8), *(uint *)(iVar2 + 0x14) < uVar13)) {
          *(uint *)(iVar2 + 0x14) = uVar13;
        }
        uVar13 = *(uint *)(param_2 + 8);
        if ((uVar13 < *(uint *)(iVar2 + 0x10)) ||
           (*(uint *)(iVar2 + 0x10) + *(int *)(iVar2 + 0xc) < local_c + uVar13)) {
          puVar6 = (undefined4 *)*param_1;
          if (puVar6[3] != 0) {
            _mfs_map_remove(puVar6,puVar6[2],puVar6[3] + puVar6[2],1);
          }
          uVar12 = ~_page_mask & uVar13;
          local_28 = (local_c + uVar13 + _page_mask & ~_page_mask) - uVar12;
          if (local_28 < 0x10000) {
            local_28 = 0x10000;
          }
          do {
            local_8 = *(undefined4 *)(_mfs_map + 0x14);
            _lock_write(&_mfs_alloc_lock_data);
            iVar11 = _vm_allocate_with_pager(_mfs_map,&local_8,local_28,1,*puVar6,uVar12);
            puVar9 = _vm_info_queue;
            if (iVar11 == 3) {
              do {
                iVar15 = _vm_info_lock_data;
                do {
                } while (iVar15 != 0);
                LOCK();
                iVar15 = _vm_info_lock_data;
                _vm_info_lock_data = 1;
                UNLOCK();
              } while (iVar15 == 1);
              puVar14 = (undefined4 *)0x0;
              if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
                puVar14 = (undefined4 *)_vm_info_queue[10];
                puVar7 = (undefined4 *)_vm_info_queue[0xb];
                puVar10 = puVar7;
                if ((undefined4 **)puVar14 != &_vm_info_queue) {
                  puVar14[0xb] = puVar7;
                  puVar10 = DAT_001f64d4;
                }
                DAT_001f64d4 = puVar10;
                if ((undefined4 **)puVar7 != &_vm_info_queue) {
                  puVar7[10] = puVar14;
                  puVar14 = _vm_info_queue;
                }
                _vm_info_queue = puVar14;
                pbVar1 = (byte *)(puVar9 + 0xe);
                *pbVar1 = *pbVar1 & 0xfe;
                _mfs_files_mapped = _mfs_files_mapped + -1;
                _vm_info_version = _vm_info_version + 1;
                puVar14 = puVar9;
              }
              LOCK();
              uVar8 = _vm_info_lock_data;
              _vm_info_lock_data = 0;
              UNLOCK();
              if (puVar14 == (undefined4 *)0x0) {
                _mfs_alloc_wanted = 1;
                _assert_wait(&_mfs_map,0);
                __mfs_alloc_blocks = __mfs_alloc_blocks + 1;
                _lock_done(&_mfs_alloc_lock_data);
                _thread_block();
              }
              else {
                _lock_done(&_mfs_alloc_lock_data);
                _mfs_memfree(puVar14,1);
              }
              _lock_write(&_mfs_alloc_lock_data);
            }
            else if (iVar11 != 0) {
              _printf(s_Unexpected_error_on_file_map__re_001def7c,iVar11);
                    /* WARNING: Subroutine does not return */
              _panic(s_remap_vnode_001defa5);
            }
            _lock_done(&_mfs_alloc_lock_data);
          } while (iVar11 != 0);
          puVar6[2] = local_8;
          puVar6[3] = local_28;
          puVar6[4] = uVar12;
        }
        iVar11 = _uiomove((*(int *)(iVar2 + 8) + *(int *)(param_2 + 8)) - *(int *)(iVar2 + 0x10),
                          local_c,param_3,param_2);
        if (param_3 == 1) {
          *(byte *)(iVar2 + 0x38) = *(byte *)(iVar2 + 0x38) | 2;
        }
        iVar15 = *(int *)(iVar2 + 0x34);
        if (iVar15 != 0) {
          *(undefined4 *)(iVar2 + 0x34) = 0;
          _crfree(*(undefined4 *)(iVar2 + 0x30));
          *(undefined4 *)(iVar2 + 0x30) = 0;
          iVar11 = iVar15;
        }
        if (((param_3 == 1) && ((*(byte *)(param_1[9] + 0xd) & 1) != 0)) &&
           (local_24 = local_24 + 1, _nmfsbuf <= local_24)) {
          if (iVar11 == 0) {
            _vmp_push(iVar2);
            iVar15 = 0;
            if (0 < local_24) {
              do {
                uVar13 = (**(code **)(param_1[7] + 0x80))(param_1,uVar5);
                _blkflush(param_1,local_1c / uVar13);
                local_1c = local_1c + uVar5;
                iVar15 = iVar15 + 1;
              } while (iVar15 < local_24);
            }
            iVar15 = *(int *)(iVar2 + 0x34);
            if (iVar15 != 0) {
              *(undefined4 *)(iVar2 + 0x34) = 0;
              iVar11 = iVar15;
            }
          }
          local_24 = 0;
        }
        if (iVar11 != 0) goto LAB_0015f450;
      } while ((0 < *(int *)(param_2 + 0x14)) && (local_c != 0));
      if ((param_3 == 1) && (((param_4 & 4) != 0 || ((*(byte *)(param_1[9] + 0xd) & 1) != 0)))) {
        _vmp_push(iVar2);
        uVar13 = iVar4 + uVar16;
        for (; uVar16 < uVar13; uVar16 = uVar16 + uVar5) {
          uVar12 = (**(code **)(param_1[7] + 0x80))(param_1,uVar5);
          _blkflush(param_1,uVar16 / uVar12);
        }
        iVar3 = *(int *)(iVar2 + 0x34);
        if (iVar3 != 0) {
          *(undefined4 *)(iVar2 + 0x34) = 0;
          iVar11 = iVar3;
        }
      }
LAB_0015f450:
      _vmp_put(*param_1);
    }
  }
  return iVar11;
}

