
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
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  int iVar14;
  uint uVar15;
  uint local_28;
  int local_24;
  uint local_1c;
  uint local_c;
  undefined4 local_8;
  
  iVar10 = *(int *)(param_2 + 0x14);
  if (iVar10 == 0) {
    iVar10 = 0;
  }
  else {
    iVar2 = *(int *)(param_2 + 8);
    if ((iVar2 < 0) || (iVar10 + iVar2 < 0)) {
      iVar10 = 0x16;
    }
    else {
      _mfs_get(param_1,iVar2,iVar10);
      iVar2 = *param_1;
      iVar3 = *(int *)(iVar2 + 0x14);
      if ((param_3 == 1) && ((param_4 & 2) != 0)) {
        *(int *)(param_2 + 8) = iVar3;
      }
      uVar15 = *(uint *)(param_2 + 8);
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
          uVar12 = iVar3 - *(int *)(param_2 + 8);
          if ((int)uVar12 < 1) {
            _vmp_put(*param_1);
            return 0;
          }
          if ((int)uVar12 < (int)local_c) {
            local_c = uVar12;
          }
        }
        if ((param_3 == 1) &&
           (uVar12 = local_c + *(int *)(param_2 + 8), *(uint *)(iVar2 + 0x14) < uVar12)) {
          *(uint *)(iVar2 + 0x14) = uVar12;
        }
        uVar12 = *(uint *)(param_2 + 8);
        if ((uVar12 < *(uint *)(iVar2 + 0x10)) ||
           (*(uint *)(iVar2 + 0x10) + *(int *)(iVar2 + 0xc) < local_c + uVar12)) {
          puVar6 = (undefined4 *)*param_1;
          if (puVar6[3] != 0) {
            _mfs_map_remove(puVar6,puVar6[2],puVar6[3] + puVar6[2],1);
          }
          uVar11 = ~_page_mask & uVar12;
          local_28 = (local_c + uVar12 + _page_mask & ~_page_mask) - uVar11;
          if (local_28 < 0x10000) {
            local_28 = 0x10000;
          }
          do {
            local_8 = *(undefined4 *)(_mfs_map + 0x14);
            _lock_write(&_mfs_alloc_lock_data);
            iVar10 = _vm_allocate_with_pager(_mfs_map,&local_8,local_28,1,*puVar6,uVar11);
            puVar8 = _vm_info_queue;
            if (iVar10 == 3) {
              do {
              } while (_vm_info_lock_data != 0);
              LOCK();
              UNLOCK();
              puVar13 = (undefined4 *)0x0;
              if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
                puVar13 = (undefined4 *)_vm_info_queue[10];
                puVar7 = (undefined4 *)_vm_info_queue[0xb];
                puVar9 = puVar7;
                if ((undefined4 **)puVar13 != &_vm_info_queue) {
                  puVar13[0xb] = puVar7;
                  puVar9 = DAT_001f64d4;
                }
                DAT_001f64d4 = puVar9;
                if ((undefined4 **)puVar7 != &_vm_info_queue) {
                  puVar7[10] = puVar13;
                  puVar13 = _vm_info_queue;
                }
                _vm_info_queue = puVar13;
                pbVar1 = (byte *)(puVar8 + 0xe);
                *pbVar1 = *pbVar1 & 0xfe;
                _mfs_files_mapped = _mfs_files_mapped + -1;
                _vm_info_version = _vm_info_version + 1;
                puVar13 = puVar8;
              }
              LOCK();
              _vm_info_lock_data = 0;
              UNLOCK();
              if (puVar13 == (undefined4 *)0x0) {
                _mfs_alloc_wanted = 1;
                _assert_wait(&_mfs_map,0);
                __mfs_alloc_blocks = __mfs_alloc_blocks + 1;
                _lock_done(&_mfs_alloc_lock_data);
                _thread_block();
              }
              else {
                _lock_done(&_mfs_alloc_lock_data);
                _mfs_memfree(puVar13,1);
              }
              _lock_write(&_mfs_alloc_lock_data);
            }
            else if (iVar10 != 0) {
              _printf(s_Unexpected_error_on_file_map__re_001def7c,iVar10);
                    /* WARNING: Subroutine does not return */
              _panic(s_remap_vnode_001defa5);
            }
            _lock_done(&_mfs_alloc_lock_data);
          } while (iVar10 != 0);
          puVar6[2] = local_8;
          puVar6[3] = local_28;
          puVar6[4] = uVar11;
        }
        iVar10 = _uiomove((*(int *)(iVar2 + 8) + *(int *)(param_2 + 8)) - *(int *)(iVar2 + 0x10),
                          local_c,param_3,param_2);
        if (param_3 == 1) {
          *(byte *)(iVar2 + 0x38) = *(byte *)(iVar2 + 0x38) | 2;
        }
        iVar14 = *(int *)(iVar2 + 0x34);
        if (iVar14 != 0) {
          *(undefined4 *)(iVar2 + 0x34) = 0;
          _crfree(*(undefined4 *)(iVar2 + 0x30));
          *(undefined4 *)(iVar2 + 0x30) = 0;
          iVar10 = iVar14;
        }
        if (((param_3 == 1) && ((*(byte *)(param_1[9] + 0xd) & 1) != 0)) &&
           (local_24 = local_24 + 1, _nmfsbuf <= local_24)) {
          if (iVar10 == 0) {
            _vmp_push(iVar2);
            iVar14 = 0;
            if (0 < local_24) {
              do {
                uVar12 = (**(code **)(param_1[7] + 0x80))(param_1,uVar5);
                _blkflush(param_1,local_1c / uVar12);
                local_1c = local_1c + uVar5;
                iVar14 = iVar14 + 1;
              } while (iVar14 < local_24);
            }
            iVar14 = *(int *)(iVar2 + 0x34);
            if (iVar14 != 0) {
              *(undefined4 *)(iVar2 + 0x34) = 0;
              iVar10 = iVar14;
            }
          }
          local_24 = 0;
        }
        if (iVar10 != 0) goto LAB_0015f450;
      } while ((0 < *(int *)(param_2 + 0x14)) && (local_c != 0));
      if ((param_3 == 1) && (((param_4 & 4) != 0 || ((*(byte *)(param_1[9] + 0xd) & 1) != 0)))) {
        _vmp_push(iVar2);
        uVar12 = iVar4 + uVar15;
        for (; uVar15 < uVar12; uVar15 = uVar15 + uVar5) {
          uVar11 = (**(code **)(param_1[7] + 0x80))(param_1,uVar5);
          _blkflush(param_1,uVar15 / uVar11);
        }
        iVar3 = *(int *)(iVar2 + 0x34);
        if (iVar3 != 0) {
          *(undefined4 *)(iVar2 + 0x34) = 0;
          iVar10 = iVar3;
        }
      }
LAB_0015f450:
      _vmp_put(*param_1);
    }
  }
  return iVar10;
}

