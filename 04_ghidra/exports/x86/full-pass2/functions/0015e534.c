/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015e534 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _mfs_trunc(int *param_1,uint param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  size_t sVar10;
  undefined4 *puVar11;
  uint local_20;
  uint local_10;
  undefined4 local_8;
  
  iVar2 = *param_1;
  if ((*(byte *)(iVar2 + 0x38) & 0x10) == 0) {
    *(uint *)(iVar2 + 0x14) = param_2;
    uVar7 = 0;
  }
  else {
    _vmp_get(iVar2);
    uVar9 = param_2 + _page_mask & ~_page_mask;
    local_20 = 0;
    if (*(uint *)(iVar2 + 0x10) <= uVar9) {
      local_20 = uVar9 - *(uint *)(iVar2 + 0x10);
    }
    if (local_20 < *(uint *)(iVar2 + 0xc)) {
      _mfs_map_remove(iVar2,*(int *)(iVar2 + 8) + local_20,
                      *(uint *)(iVar2 + 0xc) + *(int *)(iVar2 + 8),0);
      *(uint *)(iVar2 + 0xc) = local_20;
    }
    if (uVar9 < *(uint *)(iVar2 + 0x14)) {
      _vno_flush(param_1,uVar9,*(uint *)(iVar2 + 0x14) - uVar9);
    }
    *(uint *)(iVar2 + 0x14) = param_2;
    if (param_2 != uVar9) {
      sVar10 = uVar9 - param_2;
      if ((param_2 < *(uint *)(iVar2 + 0x10)) ||
         (*(uint *)(iVar2 + 0x10) + *(int *)(iVar2 + 0xc) < param_2 + sVar10)) {
        puVar3 = (undefined4 *)*param_1;
        if (puVar3[3] != 0) {
          _mfs_map_remove(puVar3,puVar3[2],puVar3[3] + puVar3[2],1);
        }
        uVar9 = param_2 & ~_page_mask;
        local_10 = (param_2 + sVar10 + _page_mask & ~_page_mask) - uVar9;
        if (local_10 < 0x10000) {
          local_10 = 0x10000;
        }
        do {
          local_8 = *(undefined4 *)(_mfs_map + 0x14);
          _lock_write(&_mfs_alloc_lock_data);
          iVar8 = _vm_allocate_with_pager(_mfs_map,&local_8,local_10,1,*puVar3,uVar9);
          puVar5 = _vm_info_queue;
          if (iVar8 == 3) {
            do {
            } while (_vm_info_lock_data != 0);
            LOCK();
            UNLOCK();
            puVar11 = (undefined4 *)0x0;
            if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
              puVar11 = (undefined4 *)_vm_info_queue[10];
              puVar4 = (undefined4 *)_vm_info_queue[0xb];
              puVar6 = puVar4;
              if ((undefined4 **)puVar11 != &_vm_info_queue) {
                puVar11[0xb] = puVar4;
                puVar6 = DAT_001f64d4;
              }
              DAT_001f64d4 = puVar6;
              if ((undefined4 **)puVar4 != &_vm_info_queue) {
                puVar4[10] = puVar11;
                puVar11 = _vm_info_queue;
              }
              _vm_info_queue = puVar11;
              pbVar1 = (byte *)(puVar5 + 0xe);
              *pbVar1 = *pbVar1 & 0xfe;
              _mfs_files_mapped = _mfs_files_mapped + -1;
              _vm_info_version = _vm_info_version + 1;
              puVar11 = puVar5;
            }
            LOCK();
            _vm_info_lock_data = 0;
            UNLOCK();
            if (puVar11 == (undefined4 *)0x0) {
              _mfs_alloc_wanted = 1;
              _assert_wait(&_mfs_map,0);
              __mfs_alloc_blocks = __mfs_alloc_blocks + 1;
              _lock_done(&_mfs_alloc_lock_data);
              _thread_block();
            }
            else {
              _lock_done(&_mfs_alloc_lock_data);
              _mfs_memfree(puVar11,1);
            }
            _lock_write(&_mfs_alloc_lock_data);
          }
          else if (iVar8 != 0) {
            _printf(s_Unexpected_error_on_file_map__re_001def7c,iVar8);
                    /* WARNING: Subroutine does not return */
            _panic(s_remap_vnode_001defa5);
          }
          _lock_done(&_mfs_alloc_lock_data);
        } while (iVar8 != 0);
        puVar3[2] = local_8;
        puVar3[3] = local_10;
        puVar3[4] = uVar9;
      }
      _bzero((void *)((param_2 + *(int *)(iVar2 + 8)) - *(int *)(iVar2 + 0x10)),sVar10);
      *(short *)(iVar2 + 4) = *(short *)(iVar2 + 4) + 1;
      *(byte *)(iVar2 + 0x38) = *(byte *)(iVar2 + 0x38) | 2;
      _vmp_push(iVar2);
      *(short *)(iVar2 + 4) = *(short *)(iVar2 + 4) + -1;
    }
    _vmp_put(iVar2);
    uVar7 = 1;
  }
  return uVar7;
}

