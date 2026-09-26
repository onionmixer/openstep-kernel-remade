
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _mfs_get(int *param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  uint local_c;
  undefined4 local_8;
  
  iVar8 = *param_1;
  _vmp_get(iVar8);
  if (_mfs_max_window < param_3) {
    param_3 = _mfs_max_window;
  }
  if (*(uint *)(iVar8 + 0xc) < param_3) {
    puVar2 = (undefined4 *)*param_1;
    if (puVar2[3] != 0) {
      _mfs_map_remove(puVar2,puVar2[2],puVar2[3] + puVar2[2],1);
    }
    uVar9 = param_2 & ~_page_mask;
    local_c = (param_2 + param_3 + _page_mask & ~_page_mask) - uVar9;
    if (local_c < 0x10000) {
      local_c = 0x10000;
    }
    do {
      local_8 = *(undefined4 *)(_mfs_map + 0x14);
      _lock_write(&_mfs_alloc_lock_data);
      iVar8 = _vm_allocate_with_pager(_mfs_map,&local_8,local_c,1,*puVar2,uVar9);
      puVar6 = _vm_info_queue;
      if (iVar8 == 3) {
        do {
          iVar4 = _vm_info_lock_data;
          do {
          } while (iVar4 != 0);
          LOCK();
          iVar4 = _vm_info_lock_data;
          _vm_info_lock_data = 1;
          UNLOCK();
        } while (iVar4 == 1);
        puVar10 = (undefined4 *)0x0;
        if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
          puVar10 = (undefined4 *)_vm_info_queue[10];
          puVar3 = (undefined4 *)_vm_info_queue[0xb];
          puVar7 = puVar3;
          if ((undefined4 **)puVar10 != &_vm_info_queue) {
            puVar10[0xb] = puVar3;
            puVar7 = DAT_001f64d4;
          }
          DAT_001f64d4 = puVar7;
          if ((undefined4 **)puVar3 != &_vm_info_queue) {
            puVar3[10] = puVar10;
            puVar10 = _vm_info_queue;
          }
          _vm_info_queue = puVar10;
          pbVar1 = (byte *)(puVar6 + 0xe);
          *pbVar1 = *pbVar1 & 0xfe;
          _mfs_files_mapped = _mfs_files_mapped + -1;
          _vm_info_version = _vm_info_version + 1;
          puVar10 = puVar6;
        }
        LOCK();
        uVar5 = _vm_info_lock_data;
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
      else if (iVar8 != 0) {
        _printf(s_Unexpected_error_on_file_map__re_001def7c,iVar8);
                    /* WARNING: Subroutine does not return */
        _panic(s_remap_vnode_001defa5);
      }
      _lock_done(&_mfs_alloc_lock_data);
    } while (iVar8 != 0);
    puVar2[2] = local_8;
    puVar2[3] = local_c;
    puVar2[4] = uVar9;
  }
  return;
}

