
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _remap_vnode(int *param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 local_8;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1[3] != 0) {
    _mfs_map_remove(puVar1,puVar1[2],puVar1[3] + puVar1[2],1);
  }
  uVar7 = ~_page_mask & param_2;
  param_3 = (param_3 + param_2 + _page_mask & ~_page_mask) - uVar7;
  if (param_3 < 0x10000) {
    param_3 = 0x10000;
  }
  do {
    local_8 = *(undefined4 *)(_mfs_map + 0x14);
    _lock_write(&_mfs_alloc_lock_data);
    iVar6 = _vm_allocate_with_pager(_mfs_map,&local_8,param_3,1,*puVar1,uVar7);
    if (iVar6 == 3) {
      do {
      } while (_vm_info_lock_data != 0);
      LOCK();
      UNLOCK();
      puVar5 = (undefined4 *)_vm_info_queue;
      puVar8 = (undefined4 *)0x0;
      if (puVar5 != &_vm_info_queue) {
        puVar8 = (undefined4 *)puVar5[10];
        puVar2 = (undefined4 *)puVar5[0xb];
        if (puVar8 == &_vm_info_queue) {
          DAT_001f64d4 = puVar2;
        }
        else {
          puVar8[0xb] = puVar2;
        }
        if (puVar2 == &_vm_info_queue) {
          _vm_info_queue = puVar8;
        }
        else {
          puVar2[10] = puVar8;
        }
        *(byte *)(puVar5 + 0xe) = *(byte *)(puVar5 + 0xe) & 0xfe;
        uVar3 = _mfs_files_mapped;
        iVar4 = _mfs_files_mapped;
        _mfs_files_mapped = iVar4 + -1;
        uVar3 = _mfs_files_mapped;
        uVar3 = _mfs_files_mapped;
        uVar3 = _mfs_files_mapped;
        uVar3 = _vm_info_version;
        iVar4 = _vm_info_version;
        _vm_info_version = iVar4 + 1;
        uVar3 = _vm_info_version;
        uVar3 = _vm_info_version;
        uVar3 = _vm_info_version;
        puVar8 = puVar5;
      }
      LOCK();
      _vm_info_lock_data = 0;
      UNLOCK();
      if (puVar8 == (undefined4 *)0x0) {
        _mfs_alloc_wanted = 1;
        _assert_wait(&_mfs_map,0);
        __mfs_alloc_blocks = __mfs_alloc_blocks + 1;
        _lock_done(&_mfs_alloc_lock_data);
        _thread_block();
      }
      else {
        _lock_done(&_mfs_alloc_lock_data);
        _mfs_memfree(puVar8,1);
      }
      _lock_write(&_mfs_alloc_lock_data);
    }
    else if (iVar6 != 0) {
      _printf(s_Unexpected_error_on_file_map__re_001def7c,iVar6);
                    /* WARNING: Subroutine does not return */
      _panic(s_remap_vnode_001defa5);
    }
    _lock_done(&_mfs_alloc_lock_data);
  } while (iVar6 != 0);
  puVar1[2] = local_8;
  puVar1[3] = param_3;
  puVar1[4] = uVar7;
  return 1;
}

