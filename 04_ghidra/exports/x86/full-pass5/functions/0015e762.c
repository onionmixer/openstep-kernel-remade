/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015e762 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0015e762(void)

{
  byte *pbVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int unaff_EBP;
  int unaff_EDI;
  
  do {
    while( true ) {
      _lock_done();
      if (*(int *)(unaff_EBP + -0x1c) == 0) {
        iVar5 = *(int *)(unaff_EBP + -0x10);
        *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(unaff_EBP + -4);
        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(unaff_EBP + -0xc);
        *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(unaff_EBP + -0x14);
        _bzero((void *)((*(int *)(unaff_EBP + 0xc) + *(int *)(unaff_EDI + 8)) -
                       *(int *)(unaff_EDI + 0x10)),*(size_t *)(unaff_EBP + -8));
        *(short *)(unaff_EDI + 4) = *(short *)(unaff_EDI + 4) + 1;
        *(byte *)(unaff_EDI + 0x38) = *(byte *)(unaff_EDI + 0x38) | 2;
        _vmp_push();
        *(short *)(unaff_EDI + 4) = *(short *)(unaff_EDI + 4) + -1;
        _vmp_put();
        return 1;
      }
      *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(_mfs_map + 0x14);
      _lock_write();
      iVar5 = _vm_allocate_with_pager(_mfs_map,unaff_EBP + -4,*(undefined4 *)(unaff_EBP + -0xc),1);
      *(int *)(unaff_EBP + -0x1c) = iVar5;
      puVar3 = _vm_info_queue;
      if (iVar5 != 3) break;
      do {
      } while (_vm_info_lock_data != 0);
      LOCK();
      UNLOCK();
      puVar6 = (undefined4 *)0x0;
      if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
        puVar6 = (undefined4 *)_vm_info_queue[10];
        puVar2 = (undefined4 *)_vm_info_queue[0xb];
        puVar4 = puVar2;
        if ((undefined4 **)puVar6 != &_vm_info_queue) {
          puVar6[0xb] = puVar2;
          puVar4 = DAT_001f64d4;
        }
        DAT_001f64d4 = puVar4;
        if ((undefined4 **)puVar2 != &_vm_info_queue) {
          puVar2[10] = puVar6;
          puVar6 = _vm_info_queue;
        }
        _vm_info_queue = puVar6;
        pbVar1 = (byte *)(puVar3 + 0xe);
        *pbVar1 = *pbVar1 & 0xfe;
        _mfs_files_mapped = _mfs_files_mapped + -1;
        _vm_info_version = _vm_info_version + 1;
        puVar6 = puVar3;
      }
      LOCK();
      _vm_info_lock_data = 0;
      UNLOCK();
      if (puVar6 == (undefined4 *)0x0) {
        _mfs_alloc_wanted = 1;
        _assert_wait();
        __mfs_alloc_blocks = __mfs_alloc_blocks + 1;
        _lock_done();
        _thread_block();
      }
      else {
        _lock_done();
        _mfs_memfree();
      }
      _lock_write(&_mfs_alloc_lock_data);
    }
  } while (*(int *)(unaff_EBP + -0x1c) == 0);
  _printf(s_Unexpected_error_on_file_map__re_001def7c);
                    /* WARNING: Subroutine does not return */
  _panic(s_remap_vnode_001defa5);
}

