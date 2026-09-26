/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015f2a9 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0015f2a9(void)

{
  byte *pbVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  do {
    _lock_done();
    if (unaff_EDI == 0) {
      iVar4 = *(int *)(unaff_EBP + -0x28);
      *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(unaff_EBP + -4);
      *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(unaff_EBP + -0x24);
      *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(unaff_EBP + -0x2c);
      do {
        *(int *)(unaff_EBP + -0x34) =
             (*(int *)(unaff_ESI + 8) + *(int *)(*(int *)(unaff_EBP + 0xc) + 8)) -
             *(int *)(unaff_ESI + 0x10);
        iVar4 = _uiomove(*(undefined4 *)(unaff_EBP + -0x34));
        if (*(int *)(unaff_EBP + 0x10) == 1) {
          *(byte *)(unaff_ESI + 0x38) = *(byte *)(unaff_ESI + 0x38) | 2;
        }
        iVar7 = *(int *)(unaff_ESI + 0x34);
        if (iVar7 != 0) {
          *(undefined4 *)(unaff_ESI + 0x34) = 0;
          _crfree();
          *(undefined4 *)(unaff_ESI + 0x30) = 0;
          iVar4 = iVar7;
        }
        if (((*(int *)(unaff_EBP + 0x10) == 1) &&
            ((*(byte *)(*(int *)(*(int *)(unaff_EBP + 8) + 0x24) + 0xd) & 1) != 0)) &&
           (*(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1,
           _nmfsbuf <= *(int *)(unaff_EBP + -0x20))) {
          if (iVar4 == 0) {
            _vmp_push();
            iVar7 = 0;
            if (0 < *(int *)(unaff_EBP + -0x20)) {
              do {
                (**(code **)(*(int *)(*(int *)(unaff_EBP + 8) + 0x1c) + 0x80))();
                _blkflush();
                *(int *)(unaff_EBP + -0x18) =
                     *(int *)(unaff_EBP + -0x18) + *(int *)(unaff_EBP + -0xc);
                iVar7 = iVar7 + 1;
              } while (iVar7 < *(int *)(unaff_EBP + -0x20));
            }
            iVar7 = *(int *)(unaff_ESI + 0x34);
            if (iVar7 != 0) {
              *(undefined4 *)(unaff_ESI + 0x34) = 0;
              iVar4 = iVar7;
            }
          }
          *(undefined4 *)(unaff_EBP + -0x20) = 0;
        }
        if (iVar4 != 0) goto LAB_0015f450;
        if ((*(int *)(*(int *)(unaff_EBP + 0xc) + 0x14) < 1) || (*(int *)(unaff_EBP + -8) == 0)) {
          if ((*(int *)(unaff_EBP + 0x10) == 1) &&
             (((*(uint *)(unaff_EBP + 0x14) & 4) != 0 ||
              ((*(byte *)(*(int *)(*(int *)(unaff_EBP + 8) + 0x24) + 0xd) & 1) != 0)))) {
            _vmp_push();
            uVar8 = *(uint *)(unaff_EBP + -0x14);
            uVar5 = *(int *)(unaff_EBP + -0x1c) + uVar8;
            if (uVar8 < uVar5) {
              *(uint *)(unaff_EBP + -0x30) = uVar5;
              do {
                (**(code **)(*(int *)(*(int *)(unaff_EBP + 8) + 0x1c) + 0x80))();
                _blkflush();
                uVar8 = uVar8 + *(int *)(unaff_EBP + -0xc);
              } while (uVar8 < *(uint *)(unaff_EBP + -0x30));
            }
            iVar7 = *(int *)(unaff_ESI + 0x34);
            if (iVar7 != 0) {
              *(undefined4 *)(unaff_ESI + 0x34) = 0;
              iVar4 = iVar7;
            }
          }
LAB_0015f450:
          _vmp_put();
          return iVar4;
        }
        uVar8 = *(uint *)(*(int *)(unaff_EBP + 0xc) + 0x14);
        *(uint *)(unaff_EBP + -8) = *(uint *)(unaff_EBP + -0xc);
        if (uVar8 <= *(uint *)(unaff_EBP + -0xc)) {
          *(uint *)(unaff_EBP + -8) = uVar8;
        }
        if (*(int *)(unaff_EBP + 0x10) == 0) {
          iVar4 = *(int *)(unaff_EBP + -0x10) - *(int *)(*(int *)(unaff_EBP + 0xc) + 8);
          if (iVar4 < 1) {
            _vmp_put();
            return 0;
          }
          if (iVar4 < *(int *)(unaff_EBP + -8)) {
            *(int *)(unaff_EBP + -8) = iVar4;
          }
        }
        if ((*(int *)(unaff_EBP + 0x10) == 1) &&
           (uVar8 = *(int *)(unaff_EBP + -8) + *(int *)(*(int *)(unaff_EBP + 0xc) + 8),
           *(uint *)(unaff_ESI + 0x14) < uVar8)) {
          *(uint *)(unaff_ESI + 0x14) = uVar8;
        }
        uVar8 = *(uint *)(*(int *)(unaff_EBP + 0xc) + 8);
      } while ((*(uint *)(unaff_ESI + 0x10) <= uVar8) &&
              (*(int *)(unaff_EBP + -8) + uVar8 <=
               *(uint *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0xc)));
      iVar4 = **(int **)(unaff_EBP + 8);
      *(int *)(unaff_EBP + -0x28) = iVar4;
      if (*(int *)(iVar4 + 0xc) != 0) {
        *(int *)(unaff_EBP + -0x34) = *(int *)(iVar4 + 0xc) + *(int *)(iVar4 + 8);
        _mfs_map_remove(iVar4);
      }
      uVar5 = ~_page_mask;
      *(uint *)(unaff_EBP + -0x38) = uVar5;
      uVar5 = uVar5 & uVar8;
      *(uint *)(unaff_EBP + -0x2c) = uVar5;
      uVar5 = (*(int *)(unaff_EBP + -8) + uVar8 + _page_mask & *(uint *)(unaff_EBP + -0x38)) - uVar5
      ;
      *(uint *)(unaff_EBP + -0x24) = uVar5;
      if (uVar5 < 0x10000) {
        *(undefined4 *)(unaff_EBP + -0x24) = 0x10000;
      }
    }
    *(undefined4 *)(unaff_EBP + -4) = *(undefined4 *)(_mfs_map + 0x14);
    _lock_write();
    unaff_EDI = _vm_allocate_with_pager
                          (_mfs_map,unaff_EBP + -4,*(undefined4 *)(unaff_EBP + -0x24),1);
    puVar3 = _vm_info_queue;
    if (unaff_EDI == 3) {
      do {
      } while (_vm_info_lock_data != 0);
      LOCK();
      UNLOCK();
      puVar6 = (undefined4 *)0x0;
      if ((undefined4 **)_vm_info_queue != &_vm_info_queue) {
        puVar6 = (undefined4 *)_vm_info_queue[10];
        uVar2 = _vm_info_queue[0xb];
        *(undefined4 *)(unaff_EBP + -0x38) = uVar2;
        if ((undefined4 **)puVar6 != &_vm_info_queue) {
          puVar6[0xb] = *(undefined4 *)(unaff_EBP + -0x38);
          uVar2 = DAT_001f64d4;
        }
        DAT_001f64d4 = uVar2;
        if ((undefined4 **)*(undefined4 **)(unaff_EBP + -0x38) != &_vm_info_queue) {
          *(undefined4 **)(*(int *)(unaff_EBP + -0x38) + 0x28) = puVar6;
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
    else if (unaff_EDI != 0) {
      _printf(s_Unexpected_error_on_file_map__re_001def7c);
                    /* WARNING: Subroutine does not return */
      _panic(s_remap_vnode_001defa5);
    }
  } while( true );
}

