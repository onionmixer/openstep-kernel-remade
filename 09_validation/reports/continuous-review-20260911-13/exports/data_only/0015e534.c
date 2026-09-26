
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _mfs_trunc(int *param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  size_t sVar9;
  undefined4 *puVar10;
  uint local_20;
  uint local_10;
  undefined4 local_8;
  
  iVar1 = *param_1;
  if ((*(byte *)(iVar1 + 0x38) & 0x10) == 0) {
    *(uint *)(iVar1 + 0x14) = param_2;
    uVar6 = 0;
  }
  else {
    _vmp_get(iVar1);
    uVar8 = param_2 + _page_mask & ~_page_mask;
    local_20 = 0;
    if (*(uint *)(iVar1 + 0x10) <= uVar8) {
      local_20 = uVar8 - *(uint *)(iVar1 + 0x10);
    }
    if (local_20 < *(uint *)(iVar1 + 0xc)) {
      _mfs_map_remove(iVar1,*(int *)(iVar1 + 8) + local_20,
                      *(uint *)(iVar1 + 0xc) + *(int *)(iVar1 + 8),0);
      *(uint *)(iVar1 + 0xc) = local_20;
    }
    if (uVar8 < *(uint *)(iVar1 + 0x14)) {
      _vno_flush(param_1,uVar8,*(uint *)(iVar1 + 0x14) - uVar8);
    }
    *(uint *)(iVar1 + 0x14) = param_2;
    if (param_2 != uVar8) {
      sVar9 = uVar8 - param_2;
      if ((param_2 < *(uint *)(iVar1 + 0x10)) ||
         (*(uint *)(iVar1 + 0x10) + *(int *)(iVar1 + 0xc) < param_2 + sVar9)) {
        puVar2 = (undefined4 *)*param_1;
        if (puVar2[3] != 0) {
          _mfs_map_remove(puVar2,puVar2[2],puVar2[3] + puVar2[2],1);
        }
        uVar8 = param_2 & ~_page_mask;
        local_10 = (param_2 + sVar9 + _page_mask & ~_page_mask) - uVar8;
        if (local_10 < 0x10000) {
          local_10 = 0x10000;
        }
        do {
          local_8 = *(undefined4 *)(_mfs_map + 0x14);
          _lock_write(&_mfs_alloc_lock_data);
          iVar7 = _vm_allocate_with_pager(_mfs_map,&local_8,local_10,1,*puVar2,uVar8);
          if (iVar7 == 3) {
            do {
            } while (_vm_info_lock_data != 0);
            LOCK();
            UNLOCK();
            puVar5 = (undefined4 *)_vm_info_queue;
            puVar10 = (undefined4 *)0x0;
            if (puVar5 != &_vm_info_queue) {
              puVar10 = (undefined4 *)puVar5[10];
              puVar3 = (undefined4 *)puVar5[0xb];
              if (puVar10 == &_vm_info_queue) {
                DAT_001f64d4 = puVar3;
              }
              else {
                puVar10[0xb] = puVar3;
              }
              if (puVar3 == &_vm_info_queue) {
                _vm_info_queue = puVar10;
              }
              else {
                puVar3[10] = puVar10;
              }
              *(byte *)(puVar5 + 0xe) = *(byte *)(puVar5 + 0xe) & 0xfe;
              uVar6 = _mfs_files_mapped;
              iVar4 = _mfs_files_mapped;
              _mfs_files_mapped = iVar4 + -1;
              uVar6 = _mfs_files_mapped;
              uVar6 = _mfs_files_mapped;
              uVar6 = _mfs_files_mapped;
              uVar6 = _vm_info_version;
              iVar4 = _vm_info_version;
              _vm_info_version = iVar4 + 1;
              uVar6 = _vm_info_version;
              uVar6 = _vm_info_version;
              uVar6 = _vm_info_version;
              puVar10 = puVar5;
            }
            LOCK();
            _vm_info_lock_data = 0;
            UNLOCK();
            if (puVar10 == (undefined4 *)0x0) {
              _mfs_alloc_wanted = 1;
              _assert_wait(&_mfs_map,0);
              __mfs_alloc_blocks = __mfs_alloc_blocks + 1;
              _lock_done(&_mfs_alloc_lock_data);
              _thread_block();
            }
            else {
              _lock_done(&_mfs_alloc_lock_data);
              _mfs_memfree(puVar10,1);
            }
            _lock_write(&_mfs_alloc_lock_data);
          }
          else if (iVar7 != 0) {
            _printf(s_Unexpected_error_on_file_map__re_001def7c,iVar7);
                    /* WARNING: Subroutine does not return */
            _panic(s_remap_vnode_001defa5);
          }
          _lock_done(&_mfs_alloc_lock_data);
        } while (iVar7 != 0);
        puVar2[2] = local_8;
        puVar2[3] = local_10;
        puVar2[4] = uVar8;
      }
      _bzero((void *)((param_2 + *(int *)(iVar1 + 8)) - *(int *)(iVar1 + 0x10)),sVar9);
      *(short *)(iVar1 + 4) = *(short *)(iVar1 + 4) + 1;
      *(byte *)(iVar1 + 0x38) = *(byte *)(iVar1 + 0x38) | 2;
      _vmp_push(iVar1);
      *(short *)(iVar1 + 4) = *(short *)(iVar1 + 4) + -1;
    }
    _vmp_put(iVar1);
    uVar6 = 1;
  }
  return uVar6;
}

