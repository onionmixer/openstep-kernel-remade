
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _mfs_trunc(int *param_1,uint param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  size_t sVar11;
  undefined4 *puVar12;
  uint local_20;
  uint local_10;
  undefined4 local_8;
  
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x38) & 0x10) == 0) {
    *(uint *)(iVar2 + 0x14) = param_2;
    uVar8 = 0;
  }
  else {
    _vmp_get(iVar2);
    uVar10 = param_2 + _page_mask & ~_page_mask;
    local_20 = 0;
    if (*(uint *)(iVar2 + 0x10) <= uVar10) {
      local_20 = uVar10 - *(uint *)(iVar2 + 0x10);
    }
    if (local_20 < *(uint *)(iVar2 + 0xc)) {
      _mfs_map_remove(iVar2,*(int *)(iVar2 + 8) + local_20,
                      *(uint *)(iVar2 + 0xc) + *(int *)(iVar2 + 8),0);
      *(uint *)(iVar2 + 0xc) = local_20;
    }
    if (uVar10 < *(uint *)(iVar2 + 0x14)) {
      _vno_flush(param_1,uVar10,*(uint *)(iVar2 + 0x14) - uVar10);
    }
    *(uint *)(iVar2 + 0x14) = param_2;
    if (param_2 != uVar10) {
      sVar11 = uVar10 - param_2;
      if ((param_2 < *(uint *)(iVar2 + 0x10)) ||
         (*(uint *)(iVar2 + 0x10) + *(int *)(iVar2 + 0xc) < param_2 + sVar11)) {
        puVar3 = (undefined4 *)*param_1;
        if (puVar3[3] != 0) {
          _mfs_map_remove(puVar3,puVar3[2],puVar3[3] + puVar3[2],1);
        }
        uVar10 = param_2 & ~_page_mask;
        local_10 = (param_2 + sVar11 + _page_mask & ~_page_mask) - uVar10;
        if (local_10 < 0x10000) {
          local_10 = 0x10000;
        }
        do {
          local_8 = *(undefined4 *)(_mfs_map + 0x14);
          _lock_write(&_mfs_alloc_lock_data);
          iVar9 = _vm_allocate_with_pager(_mfs_map,&local_8,local_10,1,*puVar3,uVar10);
          puVar6 = _vm_info_queue;
          if (iVar9 == 3) {
            do {
              iVar5 = _vm_info_lock_data;
              do {
              } while (iVar5 != 0);
              LOCK();
              iVar5 = _vm_info_lock_data;
              _vm_info_lock_data = 1;
              UNLOCK();
            } while (iVar5 == 1);
            puVar12 = (undefined4 *)0x0;
            if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
              puVar12 = (undefined4 *)_vm_info_queue[10];
              puVar4 = (undefined4 *)_vm_info_queue[0xb];
              puVar7 = puVar4;
              if ((undefined4 **)puVar12 != &_vm_info_queue) {
                puVar12[0xb] = puVar4;
                puVar7 = DAT_001f64d4;
              }
              DAT_001f64d4 = puVar7;
              if ((undefined4 **)puVar4 != &_vm_info_queue) {
                puVar4[10] = puVar12;
                puVar12 = _vm_info_queue;
              }
              _vm_info_queue = puVar12;
              pbVar1 = (byte *)(puVar6 + 0xe);
              *pbVar1 = *pbVar1 & 0xfe;
              _mfs_files_mapped = _mfs_files_mapped + -1;
              _vm_info_version = _vm_info_version + 1;
              puVar12 = puVar6;
            }
            LOCK();
            uVar8 = _vm_info_lock_data;
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
        puVar3[2] = local_8;
        puVar3[3] = local_10;
        puVar3[4] = uVar10;
      }
      _bzero((void *)((param_2 + *(int *)(iVar2 + 8)) - *(int *)(iVar2 + 0x10)),sVar11);
      *(short *)(iVar2 + 4) = *(short *)(iVar2 + 4) + 1;
      *(byte *)(iVar2 + 0x38) = *(byte *)(iVar2 + 0x38) | 2;
      _vmp_push(iVar2);
      *(short *)(iVar2 + 4) = *(short *)(iVar2 + 4) + -1;
    }
    _vmp_put(iVar2);
    uVar8 = 1;
  }
  return uVar8;
}

