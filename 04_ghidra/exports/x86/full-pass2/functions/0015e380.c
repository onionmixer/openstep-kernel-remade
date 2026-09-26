/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015e380 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _remap_vnode(int *param_1,uint param_2,uint param_3)

{
  byte *pbVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 local_8;
  
  puVar2 = (undefined4 *)*param_1;
  if (puVar2[3] != 0) {
    _mfs_map_remove(puVar2,puVar2[2],puVar2[3] + puVar2[2],1);
  }
  uVar7 = ~_page_mask & param_2;
  param_3 = (param_3 + param_2 + _page_mask & ~_page_mask) - uVar7;
  if (param_3 < 0x10000) {
    param_3 = 0x10000;
  }
  do {
    local_8 = *(undefined4 *)(_mfs_map + 0x14);
    _lock_write(&_mfs_alloc_lock_data);
    iVar6 = _vm_allocate_with_pager(_mfs_map,&local_8,param_3,1,*puVar2,uVar7);
    puVar4 = _vm_info_queue;
    if (iVar6 == 3) {
      do {
      } while (_vm_info_lock_data != 0);
      LOCK();
      UNLOCK();
      puVar8 = (undefined4 *)0x0;
      if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
        puVar8 = (undefined4 *)_vm_info_queue[10];
        puVar3 = (undefined4 *)_vm_info_queue[0xb];
        puVar5 = puVar3;
        if ((undefined4 **)puVar8 != &_vm_info_queue) {
          puVar8[0xb] = puVar3;
          puVar5 = DAT_001f64d4;
        }
        DAT_001f64d4 = puVar5;
        if ((undefined4 **)puVar3 != &_vm_info_queue) {
          puVar3[10] = puVar8;
          puVar8 = _vm_info_queue;
        }
        _vm_info_queue = puVar8;
        pbVar1 = (byte *)(puVar4 + 0xe);
        *pbVar1 = *pbVar1 & 0xfe;
        _mfs_files_mapped = _mfs_files_mapped + -1;
        _vm_info_version = _vm_info_version + 1;
        puVar8 = puVar4;
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
  puVar2[2] = local_8;
  puVar2[3] = param_3;
  puVar2[4] = uVar7;
  return 1;
}

