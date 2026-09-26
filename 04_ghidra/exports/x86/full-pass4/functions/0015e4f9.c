/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015e4f9 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0015e4f9(void)

{
  byte *pbVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  undefined *puStack00000008;
  
  do {
    while( true ) {
      puStack00000008 = &_mfs_alloc_lock_data;
      _lock_done();
      if (unaff_ESI == 0) {
        *(undefined4 *)(unaff_EDI + 8) = *(undefined4 *)(unaff_EBP + -4);
        *(undefined4 *)(unaff_EDI + 0xc) = *(undefined4 *)(unaff_EBP + 0x10);
        *(undefined4 *)(unaff_EDI + 0x10) = *(undefined4 *)(unaff_EBP + -8);
        return 1;
      }
      *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(_mfs_map + 0x14);
      puStack00000008 = &_mfs_alloc_lock_data;
      _lock_write();
      unaff_ESI = _vm_allocate_with_pager
                            (_mfs_map,unaff_EBP + -4,*(undefined4 *)(unaff_EBP + 0x10),1);
      puVar3 = _vm_info_queue;
      if (unaff_ESI != 3) break;
      do {
      } while (_vm_info_lock_data != 0);
      LOCK();
      UNLOCK();
      puVar5 = (undefined4 *)0x0;
      if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
        puVar5 = (undefined4 *)_vm_info_queue[10];
        puVar2 = (undefined4 *)_vm_info_queue[0xb];
        puVar4 = puVar2;
        if ((undefined4 **)puVar5 != &_vm_info_queue) {
          puVar5[0xb] = puVar2;
          puVar4 = DAT_001f64d4;
        }
        DAT_001f64d4 = puVar4;
        if ((undefined4 **)puVar2 != &_vm_info_queue) {
          puVar2[10] = puVar5;
          puVar5 = _vm_info_queue;
        }
        _vm_info_queue = puVar5;
        pbVar1 = (byte *)(puVar3 + 0xe);
        *pbVar1 = *pbVar1 & 0xfe;
        _mfs_files_mapped = _mfs_files_mapped + -1;
        _vm_info_version = _vm_info_version + 1;
        puVar5 = puVar3;
      }
      LOCK();
      _vm_info_lock_data = 0;
      UNLOCK();
      if (puVar5 == (undefined4 *)0x0) {
        _mfs_alloc_wanted = 1;
        puStack00000008 = (undefined *)0x0;
        _assert_wait();
        __mfs_alloc_blocks = __mfs_alloc_blocks + 1;
        _lock_done();
        _thread_block();
      }
      else {
        puStack00000008 = &_mfs_alloc_lock_data;
        _lock_done();
        _mfs_memfree();
      }
      _lock_write(&_mfs_alloc_lock_data);
    }
  } while (unaff_ESI == 0);
  puStack00000008 = (undefined *)unaff_ESI;
  _printf(s_Unexpected_error_on_file_map__re_001def7c);
                    /* WARNING: Subroutine does not return */
  _panic(s_remap_vnode_001defa5);
}

