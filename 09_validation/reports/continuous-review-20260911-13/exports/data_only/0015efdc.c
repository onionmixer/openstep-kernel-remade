
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _mfs_io(int *param_1,int param_2,int param_3,uint param_4,short *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  int iVar13;
  uint uVar14;
  uint local_28;
  int local_24;
  uint local_1c;
  uint local_c;
  undefined4 local_8;
  
  iVar9 = *(int *)(param_2 + 0x14);
  if (iVar9 == 0) {
    iVar9 = 0;
  }
  else {
    iVar1 = *(int *)(param_2 + 8);
    if ((iVar1 < 0) || (iVar9 + iVar1 < 0)) {
      iVar9 = 0x16;
    }
    else {
      _mfs_get(param_1,iVar1,iVar9);
      iVar1 = *param_1;
      iVar2 = *(int *)(iVar1 + 0x14);
      if ((param_3 == 1) && ((param_4 & 2) != 0)) {
        *(int *)(param_2 + 8) = iVar2;
      }
      uVar14 = *(uint *)(param_2 + 8);
      iVar3 = *(int *)(param_2 + 0x14);
      uVar4 = *(uint *)(param_1[9] + 0x10);
      if ((param_3 == 1) || ((param_3 == 0 && (*(int *)(iVar1 + 0x30) == 0)))) {
        *param_5 = *param_5 + 1;
        if (*(int *)(iVar1 + 0x30) != 0) {
          _crfree(*(int *)(iVar1 + 0x30));
        }
        *(short **)(iVar1 + 0x30) = param_5;
      }
      *(undefined4 *)(iVar1 + 0x34) = 0;
      local_1c = *(uint *)(param_2 + 8);
      local_24 = 0;
      do {
        local_c = uVar4;
        if (*(uint *)(param_2 + 0x14) <= uVar4) {
          local_c = *(uint *)(param_2 + 0x14);
        }
        if (param_3 == 0) {
          uVar11 = iVar2 - *(int *)(param_2 + 8);
          if ((int)uVar11 < 1) {
            _vmp_put(*param_1);
            return 0;
          }
          if ((int)uVar11 < (int)local_c) {
            local_c = uVar11;
          }
        }
        if ((param_3 == 1) &&
           (uVar11 = local_c + *(int *)(param_2 + 8), *(uint *)(iVar1 + 0x14) < uVar11)) {
          *(uint *)(iVar1 + 0x14) = uVar11;
        }
        uVar11 = *(uint *)(param_2 + 8);
        if ((uVar11 < *(uint *)(iVar1 + 0x10)) ||
           (*(uint *)(iVar1 + 0x10) + *(int *)(iVar1 + 0xc) < local_c + uVar11)) {
          puVar5 = (undefined4 *)*param_1;
          if (puVar5[3] != 0) {
            _mfs_map_remove(puVar5,puVar5[2],puVar5[3] + puVar5[2],1);
          }
          uVar10 = ~_page_mask & uVar11;
          local_28 = (local_c + uVar11 + _page_mask & ~_page_mask) - uVar10;
          if (local_28 < 0x10000) {
            local_28 = 0x10000;
          }
          do {
            local_8 = *(undefined4 *)(_mfs_map + 0x14);
            _lock_write(&_mfs_alloc_lock_data);
            iVar9 = _vm_allocate_with_pager(_mfs_map,&local_8,local_28,1,*puVar5,uVar10);
            if (iVar9 == 3) {
              do {
              } while (_vm_info_lock_data != 0);
              LOCK();
              UNLOCK();
              puVar8 = (undefined4 *)_vm_info_queue;
              puVar12 = (undefined4 *)0x0;
              if (puVar8 != &_vm_info_queue) {
                puVar12 = (undefined4 *)puVar8[10];
                puVar6 = (undefined4 *)puVar8[0xb];
                if (puVar12 == &_vm_info_queue) {
                  DAT_001f64d4 = puVar6;
                }
                else {
                  puVar12[0xb] = puVar6;
                }
                if (puVar6 == &_vm_info_queue) {
                  _vm_info_queue = puVar12;
                }
                else {
                  puVar6[10] = puVar12;
                }
                *(byte *)(puVar8 + 0xe) = *(byte *)(puVar8 + 0xe) & 0xfe;
                uVar7 = _mfs_files_mapped;
                iVar13 = _mfs_files_mapped;
                _mfs_files_mapped = iVar13 + -1;
                uVar7 = _mfs_files_mapped;
                uVar7 = _mfs_files_mapped;
                uVar7 = _mfs_files_mapped;
                uVar7 = _vm_info_version;
                iVar13 = _vm_info_version;
                _vm_info_version = iVar13 + 1;
                uVar7 = _vm_info_version;
                uVar7 = _vm_info_version;
                uVar7 = _vm_info_version;
                puVar12 = puVar8;
              }
              LOCK();
              _vm_info_lock_data = 0;
              UNLOCK();
              if (puVar12 == (undefined4 *)0x0) {
                _mfs_alloc_wanted = 1;
                _assert_wait(&_mfs_map,0);
                __mfs_alloc_blocks = __mfs_alloc_blocks + 1;
                _lock_done(&_mfs_alloc_lock_data);
                _thread_block();
              }
              else {
                _lock_done(&_mfs_alloc_lock_data);
                _mfs_memfree(puVar12,1);
              }
              _lock_write(&_mfs_alloc_lock_data);
            }
            else if (iVar9 != 0) {
              _printf(s_Unexpected_error_on_file_map__re_001def7c,iVar9);
                    /* WARNING: Subroutine does not return */
              _panic(s_remap_vnode_001defa5);
            }
            _lock_done(&_mfs_alloc_lock_data);
          } while (iVar9 != 0);
          puVar5[2] = local_8;
          puVar5[3] = local_28;
          puVar5[4] = uVar10;
        }
        iVar9 = _uiomove((*(int *)(iVar1 + 8) + *(int *)(param_2 + 8)) - *(int *)(iVar1 + 0x10),
                         local_c,param_3,param_2);
        if (param_3 == 1) {
          *(byte *)(iVar1 + 0x38) = *(byte *)(iVar1 + 0x38) | 2;
        }
        iVar13 = *(int *)(iVar1 + 0x34);
        if (iVar13 != 0) {
          *(undefined4 *)(iVar1 + 0x34) = 0;
          _crfree(*(undefined4 *)(iVar1 + 0x30));
          *(undefined4 *)(iVar1 + 0x30) = 0;
          iVar9 = iVar13;
        }
        if (((param_3 == 1) && ((*(byte *)(param_1[9] + 0xd) & 1) != 0)) &&
           (local_24 = local_24 + 1, _nmfsbuf <= local_24)) {
          if (iVar9 == 0) {
            _vmp_push(iVar1);
            iVar13 = 0;
            if (0 < local_24) {
              do {
                uVar11 = (**(code **)(param_1[7] + 0x80))(param_1,uVar4);
                _blkflush(param_1,local_1c / uVar11);
                local_1c = local_1c + uVar4;
                iVar13 = iVar13 + 1;
              } while (iVar13 < local_24);
            }
            iVar13 = *(int *)(iVar1 + 0x34);
            if (iVar13 != 0) {
              *(undefined4 *)(iVar1 + 0x34) = 0;
              iVar9 = iVar13;
            }
          }
          local_24 = 0;
        }
        if (iVar9 != 0) goto LAB_0015f450;
      } while ((0 < *(int *)(param_2 + 0x14)) && (local_c != 0));
      if ((param_3 == 1) && (((param_4 & 4) != 0 || ((*(byte *)(param_1[9] + 0xd) & 1) != 0)))) {
        _vmp_push(iVar1);
        uVar11 = iVar3 + uVar14;
        for (; uVar14 < uVar11; uVar14 = uVar14 + uVar4) {
          uVar10 = (**(code **)(param_1[7] + 0x80))(param_1,uVar4);
          _blkflush(param_1,uVar14 / uVar10);
        }
        iVar2 = *(int *)(iVar1 + 0x34);
        if (iVar2 != 0) {
          *(undefined4 *)(iVar1 + 0x34) = 0;
          iVar9 = iVar2;
        }
      }
LAB_0015f450:
      _vmp_put(*param_1);
    }
  }
  return iVar9;
}

