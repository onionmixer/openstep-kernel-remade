/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00172b3c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00172b3c(void)

{
  byte *pbVar1;
  short *psVar2;
  int iVar3;
  byte bVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int *piVar11;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
LAB_00172b3f:
  do {
    iVar8 = *(int *)(*(int *)(unaff_EBP + -8) + 0x1c);
    if (iVar8 != 0) {
      *(int *)(unaff_EBP + -0x40) = iVar8;
      if ((*(uint *)(unaff_EBP + 0x10) & 2) == 0) {
        *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
        *(byte *)((int)unaff_ESI + 0x21) = *(byte *)((int)unaff_ESI + 0x21) | 4;
      }
      else {
        LOCK();
        piVar11 = (int *)(*(int *)(unaff_EBP + -0x40) + 0x10);
        iVar8 = *piVar11;
        *piVar11 = 1;
        UNLOCK();
        if (iVar8 == 1) {
          piVar11 = (int *)(unaff_EDI + 0x10);
          LOCK();
          *(undefined4 *)(unaff_EDI + 0x10) = 0;
          UNLOCK();
          do {
            do {
            } while (*piVar11 != 0);
            LOCK();
            iVar8 = *piVar11;
            *piVar11 = 1;
            UNLOCK();
          } while (iVar8 == 1);
          goto LAB_00172b3f;
        }
        iVar8 = *(int *)(unaff_EBP + -0x40);
        *(short *)(iVar8 + 0x18) = *(short *)(iVar8 + 0x18) + 1;
        *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0xc) - *(int *)(iVar8 + 0x24);
        iVar8 = _vm_page_lookup(iVar8);
        *(int *)(unaff_EBP + -0x4c) = iVar8;
        *(uint *)(unaff_EBP + -0x38) = (uint)(iVar8 != 0);
        if ((iVar8 != 0) == 0) {
LAB_00172d26:
          iVar8 = _vm_page_alloc_sequential
                            (*(undefined4 *)(unaff_EBP + -0x40),*(undefined4 *)(unaff_EBP + -0x44));
          *(int *)(unaff_EBP + -0x4c) = iVar8;
          if (iVar8 == 0) {
            bVar4 = *(byte *)(unaff_ESI + 8);
            *(byte *)(unaff_ESI + 8) = bVar4 & 0xfe;
            if ((bVar4 & 2) != 0) {
              *(byte *)(unaff_ESI + 8) = bVar4 & 0xfc;
              _thread_wakeup_prim(unaff_ESI,0);
            }
            do {
            } while (_vm_page_queue_lock != 0);
            LOCK();
            _vm_page_queue_lock = 1;
            UNLOCK();
            _vm_page_activate();
            LOCK();
            _vm_page_queue_lock = 0;
            UNLOCK();
            iVar8 = *(int *)(unaff_EBP + -0x40);
            psVar2 = (short *)(iVar8 + 0x18);
            *psVar2 = *psVar2 + -1;
            LOCK();
            *(undefined4 *)(iVar8 + 0x10) = 0;
            UNLOCK();
            *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
            LOCK();
            *(undefined4 *)(unaff_EDI + 0x10) = 0;
            UNLOCK();
            if (unaff_EDI != *(int *)(unaff_EBP + -8)) {
              piVar11 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
              do {
                do {
                } while (*piVar11 != 0);
                LOCK();
                iVar8 = *piVar11;
                *piVar11 = 1;
                UNLOCK();
              } while (iVar8 == 1);
              iVar8 = *(int *)(unaff_EBP + -0x2c);
              bVar4 = *(byte *)(iVar8 + 0x20);
              *(byte *)(iVar8 + 0x20) = bVar4 & 0xfe;
              if ((bVar4 & 2) != 0) {
                *(byte *)(iVar8 + 0x20) = bVar4 & 0xfc;
                _thread_wakeup_prim(iVar8,0);
              }
              do {
              } while (_vm_page_queue_lock != 0);
              LOCK();
              _vm_page_queue_lock = 1;
              UNLOCK();
              _vm_page_free();
              LOCK();
              _vm_page_queue_lock = 0;
              UNLOCK();
              iVar8 = *(int *)(unaff_EBP + -8);
              psVar2 = (short *)(iVar8 + 0x44);
              *psVar2 = *psVar2 + -1;
              LOCK();
              *(undefined4 *)(iVar8 + 0x10) = 0;
              UNLOCK();
            }
            if (*(int *)(unaff_EBP + -0x34) != 0) {
              _vm_map_lookup_done(*(undefined4 *)(unaff_EBP + 8));
            }
            _vm_object_deallocate();
            do {
            } while (_vm_pages_needed_lock != 0);
            LOCK();
            UNLOCK();
            goto LAB_00172e63;
          }
          iVar8 = *(int *)(unaff_EBP + -0x40);
          if (*(int *)(iVar8 + 0x28) == 0) {
LAB_00173007:
            if (*(int *)(unaff_EBP + -0x38) != 0) goto LAB_00173080;
          }
          else {
            LOCK();
            *(undefined4 *)(unaff_EDI + 0x10) = 0;
            UNLOCK();
            *(int *)(unaff_EBP + -0x48) = iVar8 + 0x10;
            LOCK();
            *(undefined4 *)(*(int *)(unaff_EBP + -0x40) + 0x10) = 0;
            UNLOCK();
            if (*(int *)(unaff_EBP + -0x34) != 0) {
              _vm_map_lookup_done(*(undefined4 *)(unaff_EBP + 8));
              *(undefined4 *)(unaff_EBP + -0x34) = 0;
            }
            uVar9 = _vm_pager_has_page(*(undefined4 *)(*(int *)(unaff_EBP + -0x40) + 0x28));
            *(undefined4 *)(unaff_EBP + -0x38) = uVar9;
            piVar11 = *(int **)(unaff_EBP + -0x48);
            do {
              do {
              } while (*piVar11 != 0);
              LOCK();
              iVar8 = *piVar11;
              *piVar11 = 1;
              UNLOCK();
            } while (iVar8 == 1);
            if ((*(int *)(*(int *)(unaff_EBP + -0x40) + 0x20) != unaff_EDI) ||
               (*(short *)(*(int *)(unaff_EBP + -0x40) + 0x18) == 1)) {
              iVar8 = *(int *)(unaff_EBP + -0x4c);
              bVar4 = *(byte *)(iVar8 + 0x20);
              *(byte *)(iVar8 + 0x20) = bVar4 & 0xfe;
              if ((bVar4 & 2) != 0) {
                *(byte *)(iVar8 + 0x20) = bVar4 & 0xfc;
                _thread_wakeup_prim(iVar8,0);
              }
              do {
              } while (_vm_page_queue_lock != 0);
              LOCK();
              _vm_page_queue_lock = 1;
              UNLOCK();
              _vm_page_free();
              LOCK();
              _vm_page_queue_lock = 0;
              UNLOCK();
              LOCK();
              *(undefined4 *)(*(int *)(unaff_EBP + -0x40) + 0x10) = 0;
              UNLOCK();
              _vm_object_deallocate();
              piVar11 = (int *)(unaff_EDI + 0x10);
              do {
                do {
                } while (*piVar11 != 0);
                LOCK();
                iVar8 = *piVar11;
                *piVar11 = 1;
                UNLOCK();
              } while (iVar8 == 1);
              goto LAB_00172b3f;
            }
            piVar11 = (int *)(unaff_EDI + 0x10);
            do {
              do {
              } while (*piVar11 != 0);
              LOCK();
              iVar8 = *piVar11;
              *piVar11 = 1;
              UNLOCK();
            } while (iVar8 == 1);
            if (*(int *)(unaff_EBP + -0x38) != 0) {
              iVar8 = *(int *)(unaff_EBP + -0x4c);
              bVar4 = *(byte *)(iVar8 + 0x20);
              *(byte *)(iVar8 + 0x20) = bVar4 & 0xfe;
              if ((bVar4 & 2) != 0) {
                *(byte *)(iVar8 + 0x20) = bVar4 & 0xfc;
                _thread_wakeup_prim(iVar8,0);
              }
              do {
              } while (_vm_page_queue_lock != 0);
              LOCK();
              _vm_page_queue_lock = 1;
              UNLOCK();
              _vm_page_free();
              LOCK();
              _vm_page_queue_lock = 0;
              UNLOCK();
              goto LAB_00173007;
            }
          }
          iVar8 = *(int *)(unaff_EBP + -0x4c);
          _vm_page_copy(unaff_ESI);
          pbVar1 = (byte *)(iVar8 + 0x20);
          *pbVar1 = *pbVar1 & 0xdf;
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          _vm_page_queue_lock = 1;
          UNLOCK();
          _pmap_remove_all();
          iVar8 = *(int *)(unaff_EBP + -0x4c);
          *(byte *)(iVar8 + 0x1e) = *(byte *)(iVar8 + 0x1e) & 0xdf;
          _vm_page_activate(iVar8);
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
          bVar4 = *(byte *)(iVar8 + 0x20);
          *(byte *)(iVar8 + 0x20) = bVar4 & 0xfe;
          if ((bVar4 & 2) != 0) {
            *(byte *)(iVar8 + 0x20) = bVar4 & 0xfc;
            _thread_wakeup_prim(iVar8,0);
          }
        }
        else {
          iVar8 = *(int *)(unaff_EBP + -0x4c);
          if ((*(byte *)(iVar8 + 0x20) & 1) != 0) {
            *(byte *)(iVar8 + 0x20) = *(byte *)(iVar8 + 0x20) | 2;
            _assert_wait(iVar8);
            bVar4 = *(byte *)(unaff_ESI + 8);
            *(byte *)(unaff_ESI + 8) = bVar4 & 0xfe;
            if ((bVar4 & 2) != 0) {
              *(byte *)(unaff_ESI + 8) = bVar4 & 0xfc;
              _thread_wakeup_prim(unaff_ESI,0);
            }
            do {
            } while (_vm_page_queue_lock != 0);
            LOCK();
            _vm_page_queue_lock = 1;
            UNLOCK();
            _vm_page_activate();
            LOCK();
            _vm_page_queue_lock = 0;
            UNLOCK();
            iVar8 = *(int *)(unaff_EBP + -0x40);
            psVar2 = (short *)(iVar8 + 0x18);
            *psVar2 = *psVar2 + -1;
            LOCK();
            *(undefined4 *)(iVar8 + 0x10) = 0;
            UNLOCK();
            *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
            LOCK();
            *(undefined4 *)(unaff_EDI + 0x10) = 0;
            UNLOCK();
            if (unaff_EDI != *(int *)(unaff_EBP + -8)) {
              piVar11 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
              do {
                do {
                } while (*piVar11 != 0);
                LOCK();
                iVar8 = *piVar11;
                *piVar11 = 1;
                UNLOCK();
              } while (iVar8 == 1);
              iVar8 = *(int *)(unaff_EBP + -0x2c);
              bVar4 = *(byte *)(iVar8 + 0x20);
              *(byte *)(iVar8 + 0x20) = bVar4 & 0xfe;
              if ((bVar4 & 2) != 0) {
                *(byte *)(iVar8 + 0x20) = bVar4 & 0xfc;
                _thread_wakeup_prim(iVar8,0);
              }
              do {
              } while (_vm_page_queue_lock != 0);
              LOCK();
              _vm_page_queue_lock = 1;
              UNLOCK();
              _vm_page_free();
              LOCK();
              _vm_page_queue_lock = 0;
              UNLOCK();
              iVar8 = *(int *)(unaff_EBP + -8);
              psVar2 = (short *)(iVar8 + 0x44);
              *psVar2 = *psVar2 + -1;
              LOCK();
              *(undefined4 *)(iVar8 + 0x10) = 0;
              UNLOCK();
            }
            if (*(int *)(unaff_EBP + -0x34) != 0) {
              _vm_map_lookup_done(*(undefined4 *)(unaff_EBP + 8));
            }
            _thread_block();
            *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(_active_threads + 0x44);
            _vm_object_deallocate();
            if (*(int *)(unaff_EBP + -0x4c) == 0) goto LAB_00172047;
            return 0;
          }
          if (*(int *)(unaff_EBP + -0x38) == 0) goto LAB_00172d26;
        }
LAB_00173080:
        iVar8 = *(int *)(unaff_EBP + -0x40);
        psVar2 = (short *)(iVar8 + 0x18);
        *psVar2 = *psVar2 + -1;
        LOCK();
        *(undefined4 *)(iVar8 + 0x10) = 0;
        UNLOCK();
        *(byte *)((int)unaff_ESI + 0x21) = *(byte *)((int)unaff_ESI + 0x21) & 0xfb;
      }
    }
    if ((*(byte *)((int)unaff_ESI + 0x1e) & 3) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_fault__active_or_inactive_bef_001e095e);
    }
    if (*(int *)(unaff_EBP + -0x34) != 0) {
LAB_00173408:
      if ((*(byte *)(unaff_EBP + -0x10) & 2) != 0) {
        *(byte *)((int)unaff_ESI + 0x21) = *(byte *)((int)unaff_ESI + 0x21) & 0xfb;
      }
      if ((*(byte *)((int)unaff_ESI + 0x1e) & 3) == 0) {
        *(int *)(unaff_EBP + -0x4c) = unaff_EDI + 0x10;
        LOCK();
        *(undefined4 *)(unaff_EDI + 0x10) = 0;
        UNLOCK();
        _pmap_enter(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),*(undefined4 *)(unaff_EBP + 0xc)
                    ,unaff_ESI[9],~unaff_ESI[10] & *(uint *)(unaff_EBP + -0x10));
        piVar11 = *(int **)(unaff_EBP + -0x4c);
        do {
          do {
          } while (*piVar11 != 0);
          LOCK();
          iVar8 = *piVar11;
          *piVar11 = 1;
          UNLOCK();
        } while (iVar8 == 1);
        do {
        } while (_vm_page_queue_lock != 0);
        LOCK();
        _vm_page_queue_lock = 1;
        UNLOCK();
        if (*(int *)(unaff_EBP + 0x14) == 0) {
          _vm_page_activate();
        }
        else if (*(int *)(unaff_EBP + -0x14) == 0) {
          _vm_page_unwire();
        }
        else {
          _vm_page_wire();
        }
        LOCK();
        _vm_page_queue_lock = 0;
        UNLOCK();
        bVar4 = *(byte *)(unaff_ESI + 8);
        *(byte *)(unaff_ESI + 8) = bVar4 & 0xfe;
        if ((bVar4 & 2) != 0) {
          *(byte *)(unaff_ESI + 8) = bVar4 & 0xfc;
          _thread_wakeup_prim(unaff_ESI,0);
        }
        *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
        LOCK();
        *(undefined4 *)(unaff_EDI + 0x10) = 0;
        UNLOCK();
        if (unaff_EDI != *(int *)(unaff_EBP + -8)) {
          piVar11 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
          do {
            do {
            } while (*piVar11 != 0);
            LOCK();
            iVar8 = *piVar11;
            *piVar11 = 1;
            UNLOCK();
          } while (iVar8 == 1);
          iVar8 = *(int *)(unaff_EBP + -0x2c);
          bVar4 = *(byte *)(iVar8 + 0x20);
          *(byte *)(iVar8 + 0x20) = bVar4 & 0xfe;
          if ((bVar4 & 2) != 0) {
            *(byte *)(iVar8 + 0x20) = bVar4 & 0xfc;
            _thread_wakeup_prim(iVar8,0);
          }
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          _vm_page_queue_lock = 1;
          UNLOCK();
          _vm_page_free();
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
          iVar8 = *(int *)(unaff_EBP + -8);
          psVar2 = (short *)(iVar8 + 0x44);
          *psVar2 = *psVar2 + -1;
          LOCK();
          *(undefined4 *)(iVar8 + 0x10) = 0;
          UNLOCK();
        }
        if (*(int *)(unaff_EBP + -0x34) != 0) {
          _vm_map_lookup_done(*(undefined4 *)(unaff_EBP + 8));
        }
        _vm_object_deallocate();
        return 0;
      }
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_fault__active_or_inactive_bef_001e0992);
    }
    *(int *)(unaff_EBP + -0x4c) = unaff_EDI + 0x10;
    LOCK();
    *(undefined4 *)(unaff_EDI + 0x10) = 0;
    UNLOCK();
    uVar9 = _vm_map_lookup(unaff_EBP + 8,*(undefined4 *)(unaff_EBP + 0xc),
                           *(uint *)(unaff_EBP + 0x10) & 0xfffffffd,unaff_EBP + -4,unaff_EBP + -0x1c
                           ,unaff_EBP + -0x20,unaff_EBP + -0x24,unaff_EBP + -0x14);
    *(undefined4 *)(unaff_EBP + -0x30) = uVar9;
    piVar11 = *(int **)(unaff_EBP + -0x4c);
    do {
      do {
      } while (*piVar11 != 0);
      LOCK();
      iVar8 = *piVar11;
      *piVar11 = 1;
      UNLOCK();
    } while (iVar8 == 1);
    if (*(int *)(unaff_EBP + -0x30) != 0) {
      bVar4 = *(byte *)(unaff_ESI + 8);
      *(byte *)(unaff_ESI + 8) = bVar4 & 0xfe;
      if ((bVar4 & 2) != 0) {
        *(byte *)(unaff_ESI + 8) = bVar4 & 0xfc;
        _thread_wakeup_prim(unaff_ESI,0);
      }
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      _vm_page_activate();
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
      LOCK();
      *(undefined4 *)(unaff_EDI + 0x10) = 0;
      UNLOCK();
      if (unaff_EDI != *(int *)(unaff_EBP + -8)) {
        piVar11 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
        do {
          do {
          } while (*piVar11 != 0);
          LOCK();
          iVar8 = *piVar11;
          *piVar11 = 1;
          UNLOCK();
        } while (iVar8 == 1);
        iVar8 = *(int *)(unaff_EBP + -0x2c);
        bVar4 = *(byte *)(iVar8 + 0x20);
        *(byte *)(iVar8 + 0x20) = bVar4 & 0xfe;
        if ((bVar4 & 2) != 0) {
          *(byte *)(iVar8 + 0x20) = bVar4 & 0xfc;
          _thread_wakeup_prim(iVar8,0);
        }
        do {
        } while (_vm_page_queue_lock != 0);
        LOCK();
        _vm_page_queue_lock = 1;
        UNLOCK();
        _vm_page_free();
        LOCK();
        _vm_page_queue_lock = 0;
        UNLOCK();
        iVar8 = *(int *)(unaff_EBP + -8);
        psVar2 = (short *)(iVar8 + 0x44);
        *psVar2 = *psVar2 + -1;
        LOCK();
        *(undefined4 *)(iVar8 + 0x10) = 0;
        UNLOCK();
      }
      if (*(int *)(unaff_EBP + -0x34) != 0) {
        _vm_map_lookup_done(*(undefined4 *)(unaff_EBP + 8));
      }
      _vm_object_deallocate();
      return *(undefined4 *)(unaff_EBP + -0x30);
    }
    *(undefined4 *)(unaff_EBP + -0x34) = 1;
    if ((*(int *)(unaff_EBP + -0x1c) == *(int *)(unaff_EBP + -8)) &&
       (*(int *)(unaff_EBP + -0x20) == *(int *)(unaff_EBP + -0xc))) {
      uVar10 = *(uint *)(unaff_EBP + -0x10) & *(uint *)(unaff_EBP + -0x24);
      *(uint *)(unaff_EBP + -0x10) = uVar10;
      if ((*(byte *)((int)unaff_ESI + 0x21) & 4) != 0) {
        *(uint *)(unaff_EBP + -0x10) = uVar10 & 0xfffffffd;
      }
      if ((*(int *)(unaff_EBP + -0x14) == 0) ||
         (*(int *)(unaff_EBP + -0x10) == *(int *)(unaff_EBP + 0x10))) goto LAB_00173408;
      bVar4 = *(byte *)(unaff_ESI + 8);
      *(byte *)(unaff_ESI + 8) = bVar4 & 0xfe;
      if ((bVar4 & 2) != 0) {
        *(byte *)(unaff_ESI + 8) = bVar4 & 0xfc;
        _thread_wakeup_prim(unaff_ESI,0);
      }
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      _vm_page_activate();
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
      LOCK();
      *(undefined4 *)(unaff_EDI + 0x10) = 0;
      UNLOCK();
      if (unaff_EDI == *(int *)(unaff_EBP + -8)) goto LAB_001733df;
      piVar11 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
      do {
        do {
        } while (*piVar11 != 0);
        LOCK();
        iVar8 = *piVar11;
        *piVar11 = 1;
        UNLOCK();
      } while (iVar8 == 1);
      iVar8 = *(int *)(unaff_EBP + -0x2c);
      bVar4 = *(byte *)(iVar8 + 0x20);
      *(byte *)(iVar8 + 0x20) = bVar4 & 0xfe;
      if ((bVar4 & 2) != 0) {
        *(byte *)(iVar8 + 0x20) = bVar4 & 0xfc;
        _thread_wakeup_prim(iVar8,0);
      }
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      UNLOCK();
    }
    else {
      bVar4 = *(byte *)(unaff_ESI + 8);
      *(byte *)(unaff_ESI + 8) = bVar4 & 0xfe;
      if ((bVar4 & 2) != 0) {
        *(byte *)(unaff_ESI + 8) = bVar4 & 0xfc;
        _thread_wakeup_prim(unaff_ESI,0);
      }
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      _vm_page_activate();
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
      LOCK();
      *(undefined4 *)(unaff_EDI + 0x10) = 0;
      UNLOCK();
      if (unaff_EDI == *(int *)(unaff_EBP + -8)) goto LAB_001733df;
      piVar11 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
      do {
        do {
        } while (*piVar11 != 0);
        LOCK();
        iVar8 = *piVar11;
        *piVar11 = 1;
        UNLOCK();
      } while (iVar8 == 1);
      iVar8 = *(int *)(unaff_EBP + -0x2c);
      bVar4 = *(byte *)(iVar8 + 0x20);
      *(byte *)(iVar8 + 0x20) = bVar4 & 0xfe;
      if ((bVar4 & 2) != 0) {
        *(byte *)(iVar8 + 0x20) = bVar4 & 0xfc;
        _thread_wakeup_prim(iVar8,0);
      }
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      UNLOCK();
    }
LAB_001733bf:
    _vm_page_queue_lock = 1;
    _vm_page_free();
    LOCK();
    _vm_page_queue_lock = 0;
    UNLOCK();
    iVar8 = *(int *)(unaff_EBP + -8);
    psVar2 = (short *)(iVar8 + 0x44);
    *psVar2 = *psVar2 + -1;
    LOCK();
    *(undefined4 *)(iVar8 + 0x10) = 0;
    UNLOCK();
LAB_001733df:
    if (*(int *)(unaff_EBP + -0x34) != 0) {
      _vm_map_lookup_done(*(undefined4 *)(unaff_EBP + 8));
    }
    _vm_object_deallocate();
LAB_00172047:
    iVar8 = _vm_map_lookup(unaff_EBP + 8,*(undefined4 *)(unaff_EBP + 0xc),
                           *(undefined4 *)(unaff_EBP + 0x10),unaff_EBP + -4,unaff_EBP + -8,
                           unaff_EBP + -0xc,unaff_EBP + -0x10,unaff_EBP + -0x14);
    *(int *)(unaff_EBP + -0x30) = iVar8;
    if (iVar8 != 0) {
      return *(undefined4 *)(unaff_EBP + -0x30);
    }
    *(undefined4 *)(unaff_EBP + -0x34) = 1;
    if (*(int *)(unaff_EBP + -0x14) != 0) {
      *(undefined4 *)(unaff_EBP + 0x10) = *(undefined4 *)(unaff_EBP + -0x10);
    }
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    piVar11 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
    do {
      do {
      } while (*piVar11 != 0);
      LOCK();
      iVar8 = *piVar11;
      *piVar11 = 1;
      UNLOCK();
    } while (iVar8 == 1);
    unaff_EDI = *(int *)(unaff_EBP + -8);
    *(short *)(unaff_EDI + 0x18) = *(short *)(unaff_EDI + 0x18) + 1;
    *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + 1;
    *(undefined4 *)(unaff_EBP + -0x28) = *(undefined4 *)(unaff_EBP + -0xc);
LAB_001720cc:
    unaff_ESI = (undefined4 *)_vm_page_lookup(unaff_EDI);
    if (unaff_ESI != (undefined4 *)0x0) {
      bVar4 = *(byte *)(unaff_ESI + 8);
      if ((bVar4 & 0x40) != 0) {
        *(byte *)(unaff_ESI + 8) = bVar4 & 0xfe;
        if ((bVar4 & 2) != 0) {
          *(byte *)(unaff_ESI + 8) = bVar4 & 0xfc;
          _thread_wakeup_prim(unaff_ESI,0);
        }
        do {
        } while (_vm_page_queue_lock != 0);
        LOCK();
        _vm_page_queue_lock = 1;
        UNLOCK();
        _vm_page_free();
        LOCK();
        _vm_page_queue_lock = 0;
        UNLOCK();
        *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
        LOCK();
        *(undefined4 *)(unaff_EDI + 0x10) = 0;
        UNLOCK();
        if (unaff_EDI != *(int *)(unaff_EBP + -8)) {
          piVar11 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
          do {
            do {
            } while (*piVar11 != 0);
            LOCK();
            iVar8 = *piVar11;
            *piVar11 = 1;
            UNLOCK();
          } while (iVar8 == 1);
          iVar8 = *(int *)(unaff_EBP + -0x2c);
          bVar4 = *(byte *)(iVar8 + 0x20);
          *(byte *)(iVar8 + 0x20) = bVar4 & 0xfe;
          if ((bVar4 & 2) != 0) {
            *(byte *)(iVar8 + 0x20) = bVar4 & 0xfc;
            _thread_wakeup_prim(iVar8,0);
          }
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          _vm_page_queue_lock = 1;
          UNLOCK();
          _vm_page_free();
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
          iVar8 = *(int *)(unaff_EBP + -8);
          psVar2 = (short *)(iVar8 + 0x44);
          *psVar2 = *psVar2 + -1;
          LOCK();
          *(undefined4 *)(iVar8 + 0x10) = 0;
          UNLOCK();
        }
        if (*(int *)(unaff_EBP + -0x34) != 0) {
          _vm_map_lookup_done(*(undefined4 *)(unaff_EBP + 8));
        }
        _vm_object_deallocate();
        return 10;
      }
      if ((bVar4 & 1) == 0) {
        if ((bVar4 & 0x20) == 0) goto LAB_001724c0;
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + *(int *)(unaff_EDI + 0x24);
        iVar8 = *(int *)(unaff_EDI + 0x20);
        *(int *)(unaff_EBP + -0x4c) = iVar8;
        if (iVar8 == 0) {
          if (*(int *)(unaff_EBP + -8) != unaff_EDI) {
            *(byte *)(unaff_ESI + 8) = bVar4 & 0xde;
            *(byte *)(unaff_ESI + 8) = bVar4 & 0xde;
            if ((bVar4 & 2) != 0) {
              *(byte *)(unaff_ESI + 8) = bVar4 & 0xdc;
              _thread_wakeup_prim(unaff_ESI,0);
            }
            do {
            } while (_vm_page_queue_lock != 0);
            LOCK();
            _vm_page_queue_lock = 1;
            UNLOCK();
            _vm_page_free();
            LOCK();
            _vm_page_queue_lock = 0;
            UNLOCK();
            *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
            LOCK();
            *(undefined4 *)(unaff_EDI + 0x10) = 0;
            UNLOCK();
            unaff_EDI = *(int *)(unaff_EBP + -8);
            unaff_ESI = *(undefined4 **)(unaff_EBP + -0x2c);
            piVar11 = (int *)(unaff_EDI + 0x10);
            do {
              do {
              } while (*piVar11 != 0);
              LOCK();
              iVar8 = *piVar11;
              *piVar11 = 1;
              UNLOCK();
            } while (iVar8 == 1);
          }
          *(undefined4 *)(unaff_EBP + -0x2c) = 0;
          _vm_page_zero_fill();
          _DAT_001f6504 = _DAT_001f6504 + 1;
          *(byte *)(unaff_ESI + 8) = *(byte *)(unaff_ESI + 8) & 0xdf;
LAB_001724c0:
          if ((unaff_ESI[10] & *(uint *)(unaff_EBP + 0x10)) != 0) {
            *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
            LOCK();
            *(undefined4 *)(unaff_EDI + 0x10) = 0;
            UNLOCK();
            if (unaff_EDI != *(int *)(unaff_EBP + -8)) {
              piVar11 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
              do {
                do {
                } while (*piVar11 != 0);
                LOCK();
                iVar8 = *piVar11;
                *piVar11 = 1;
                UNLOCK();
              } while (iVar8 == 1);
              iVar8 = *(int *)(unaff_EBP + -0x2c);
              bVar4 = *(byte *)(iVar8 + 0x20);
              *(byte *)(iVar8 + 0x20) = bVar4 & 0xfe;
              if ((bVar4 & 2) != 0) {
                *(byte *)(iVar8 + 0x20) = bVar4 & 0xfc;
                _thread_wakeup_prim(iVar8,0);
              }
              do {
              } while (_vm_page_queue_lock != 0);
              LOCK();
              _vm_page_queue_lock = 1;
              UNLOCK();
              _vm_page_free();
              LOCK();
              _vm_page_queue_lock = 0;
              UNLOCK();
              iVar8 = *(int *)(unaff_EBP + -8);
              psVar2 = (short *)(iVar8 + 0x44);
              *psVar2 = *psVar2 + -1;
              LOCK();
              *(undefined4 *)(iVar8 + 0x10) = 0;
              UNLOCK();
            }
            if (*(int *)(unaff_EBP + -0x34) != 0) {
              _vm_map_lookup_done(*(undefined4 *)(unaff_EBP + 8));
            }
            _vm_object_deallocate();
            return 10;
          }
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          UNLOCK();
          if ((*(byte *)((int)unaff_ESI + 0x1e) & 1) != 0) {
            puVar5 = (undefined4 *)*unaff_ESI;
            puVar6 = (undefined4 *)unaff_ESI[1];
            puVar7 = puVar6;
            if ((undefined4 **)puVar5 != &_vm_page_queue_inactive) {
              puVar5[1] = puVar6;
              puVar7 = DAT_001f64e4;
            }
            DAT_001f64e4 = puVar7;
            if ((undefined4 **)puVar6 != &_vm_page_queue_inactive) {
              *puVar6 = puVar5;
              puVar5 = _vm_page_queue_inactive;
            }
            _vm_page_queue_inactive = puVar5;
            *(byte *)((int)unaff_ESI + 0x1e) = *(byte *)((int)unaff_ESI + 0x1e) & 0xfe;
            _vm_page_inactive_count = _vm_page_inactive_count + -1;
            _DAT_001f6508 = _DAT_001f6508 + 1;
          }
          if ((*(byte *)((int)unaff_ESI + 0x1e) & 2) != 0) {
            puVar5 = (undefined4 *)*unaff_ESI;
            puVar6 = (undefined4 *)unaff_ESI[1];
            puVar7 = puVar6;
            if ((undefined4 **)puVar5 != &_vm_page_queue_active) {
              puVar5[1] = puVar6;
              puVar7 = DAT_001f6e44;
            }
            DAT_001f6e44 = puVar7;
            if ((undefined4 **)puVar6 != &_vm_page_queue_active) {
              *puVar6 = puVar5;
              puVar5 = _vm_page_queue_active;
            }
            _vm_page_queue_active = puVar5;
            *(byte *)((int)unaff_ESI + 0x1e) = *(byte *)((int)unaff_ESI + 0x1e) & 0xfd;
            _vm_page_active_count = _vm_page_active_count + -1;
          }
          if ((*(byte *)((int)unaff_ESI + 0x1e) & 8) != 0) {
            puVar5 = (undefined4 *)*unaff_ESI;
            puVar6 = (undefined4 *)unaff_ESI[1];
            puVar7 = puVar6;
            if ((undefined4 **)puVar5 != &_vm_page_queue_free) {
              puVar5[1] = puVar6;
              puVar7 = DAT_001f6e4c;
            }
            DAT_001f6e4c = puVar7;
            if ((undefined4 **)puVar6 != &_vm_page_queue_free) {
              *puVar6 = puVar5;
              puVar5 = _vm_page_queue_free;
            }
            _vm_page_queue_free = puVar5;
            *(byte *)((int)unaff_ESI + 0x1e) = *(byte *)((int)unaff_ESI + 0x1e) & 0xf7;
            _vm_page_free_count = _vm_page_free_count + -1;
            _DAT_001f6508 = _DAT_001f6508 + 1;
          }
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
          *(byte *)(unaff_ESI + 8) = *(byte *)(unaff_ESI + 8) & 0xdf | 1;
          goto LAB_00172a30;
        }
        if (*(int *)(unaff_EBP + -8) == unaff_EDI) {
          *(undefined4 **)(unaff_EBP + -0x2c) = unaff_ESI;
          *(byte *)(unaff_ESI + 8) = bVar4 & 0xdf;
        }
        else {
          *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
          bVar4 = *(byte *)(unaff_ESI + 8);
          *(byte *)(unaff_ESI + 8) = bVar4 & 0xfe;
          if ((bVar4 & 2) != 0) {
            *(byte *)(unaff_ESI + 8) = bVar4 & 0xfc;
            _thread_wakeup_prim(unaff_ESI,0);
          }
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          _vm_page_queue_lock = 1;
          UNLOCK();
          _vm_page_free();
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
        }
        piVar11 = (int *)(*(int *)(unaff_EBP + -0x4c) + 0x10);
        do {
          do {
          } while (*piVar11 != 0);
          LOCK();
          iVar8 = *piVar11;
          *piVar11 = 1;
          UNLOCK();
        } while (iVar8 == 1);
LAB_00172a1d:
        LOCK();
        *(undefined4 *)(unaff_EDI + 0x10) = 0;
        UNLOCK();
        unaff_EDI = *(int *)(unaff_EBP + -0x4c);
        *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + 1;
        goto LAB_001720cc;
      }
      *(byte *)(unaff_ESI + 8) = bVar4 | 2;
      _assert_wait(unaff_ESI);
      if (*(int *)(unaff_EBP + -0x34) != 0) {
        _vm_map_lookup_done(*(undefined4 *)(unaff_EBP + 8));
        *(undefined4 *)(unaff_EBP + -0x34) = 0;
      }
      piVar11 = (int *)(unaff_EDI + 0x10);
      LOCK();
      *(undefined4 *)(unaff_EDI + 0x10) = 0;
      UNLOCK();
      _thread_block();
      iVar8 = *(int *)(_active_threads + 0x44);
      do {
        do {
        } while (*piVar11 != 0);
        LOCK();
        iVar3 = *piVar11;
        *piVar11 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      if (iVar8 != 4) {
        if (iVar8 != 0) {
          *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
          LOCK();
          *(undefined4 *)(unaff_EDI + 0x10) = 0;
          UNLOCK();
          if (unaff_EDI != *(int *)(unaff_EBP + -8)) {
            piVar11 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
            do {
              do {
              } while (*piVar11 != 0);
              LOCK();
              iVar8 = *piVar11;
              *piVar11 = 1;
              UNLOCK();
            } while (iVar8 == 1);
            iVar8 = *(int *)(unaff_EBP + -0x2c);
            bVar4 = *(byte *)(iVar8 + 0x20);
            *(byte *)(iVar8 + 0x20) = bVar4 & 0xfe;
            if ((bVar4 & 2) != 0) {
              *(byte *)(iVar8 + 0x20) = bVar4 & 0xfc;
              _thread_wakeup_prim(iVar8,0);
            }
            do {
            } while (_vm_page_queue_lock != 0);
            LOCK();
            _vm_page_queue_lock = 1;
            UNLOCK();
            _vm_page_free();
            LOCK();
            _vm_page_queue_lock = 0;
            UNLOCK();
            iVar8 = *(int *)(unaff_EBP + -8);
            psVar2 = (short *)(iVar8 + 0x44);
            *psVar2 = *psVar2 + -1;
            LOCK();
            *(undefined4 *)(iVar8 + 0x10) = 0;
            UNLOCK();
          }
          if (*(int *)(unaff_EBP + -0x34) != 0) {
            _vm_map_lookup_done(*(undefined4 *)(unaff_EBP + 8));
          }
          _vm_object_deallocate();
          return 0;
        }
        goto LAB_001720cc;
      }
      *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
      LOCK();
      *(undefined4 *)(unaff_EDI + 0x10) = 0;
      UNLOCK();
      if (unaff_EDI == *(int *)(unaff_EBP + -8)) goto LAB_001733df;
      piVar11 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
      do {
        do {
        } while (*piVar11 != 0);
        LOCK();
        iVar8 = *piVar11;
        *piVar11 = 1;
        UNLOCK();
      } while (iVar8 == 1);
      iVar8 = *(int *)(unaff_EBP + -0x2c);
      bVar4 = *(byte *)(iVar8 + 0x20);
      *(byte *)(iVar8 + 0x20) = bVar4 & 0xfe;
      if ((bVar4 & 2) != 0) {
        *(byte *)(iVar8 + 0x20) = bVar4 & 0xfc;
        _thread_wakeup_prim(iVar8,0);
      }
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      UNLOCK();
      goto LAB_001733bf;
    }
    if ((((*(int *)(unaff_EDI + 0x28) != 0) &&
         ((*(int *)(unaff_EBP + 0x14) == 0 || (*(int *)(unaff_EBP + -0x14) != 0)))) ||
        (*(int *)(unaff_EBP + -8) == unaff_EDI)) &&
       (unaff_ESI = (undefined4 *)
                    _vm_page_alloc_sequential(unaff_EDI,*(undefined4 *)(unaff_EBP + -0x28)),
       unaff_ESI == (undefined4 *)0x0)) break;
    if ((*(int *)(unaff_EDI + 0x28) == 0) ||
       ((*(int *)(unaff_EBP + 0x14) != 0 && (*(int *)(unaff_EBP + -0x14) == 0)))) {
LAB_00172998:
      if (*(int *)(unaff_EBP + -8) == unaff_EDI) {
LAB_0017299d:
        *(undefined4 **)(unaff_EBP + -0x2c) = unaff_ESI;
      }
      *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + *(int *)(unaff_EDI + 0x24);
      iVar8 = *(int *)(unaff_EDI + 0x20);
      *(int *)(unaff_EBP + -0x4c) = iVar8;
      if (iVar8 != 0) {
        piVar11 = (int *)(*(int *)(unaff_EBP + -0x4c) + 0x10);
        do {
          do {
          } while (*piVar11 != 0);
          LOCK();
          iVar8 = *piVar11;
          *piVar11 = 1;
          UNLOCK();
        } while (iVar8 == 1);
        if (*(int *)(unaff_EBP + -8) != unaff_EDI) {
          *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
        }
        goto LAB_00172a1d;
      }
      iVar8 = *(int *)(unaff_EBP + -8);
      if (unaff_EDI != iVar8) {
        *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
        LOCK();
        *(undefined4 *)(unaff_EDI + 0x10) = 0;
        UNLOCK();
        unaff_ESI = *(undefined4 **)(unaff_EBP + -0x2c);
        piVar11 = (int *)(iVar8 + 0x10);
        do {
          do {
          } while (*piVar11 != 0);
          LOCK();
          iVar3 = *piVar11;
          *piVar11 = 1;
          UNLOCK();
          unaff_EDI = iVar8;
        } while (iVar3 == 1);
      }
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      _vm_page_zero_fill();
      _DAT_001f6504 = _DAT_001f6504 + 1;
      *(byte *)(unaff_ESI + 8) = *(byte *)(unaff_ESI + 8) & 0xdf;
    }
    else {
      *(int *)(unaff_EBP + -0x4c) = unaff_EDI + 0x10;
      LOCK();
      *(undefined4 *)(unaff_EDI + 0x10) = 0;
      UNLOCK();
      if (*(int *)(unaff_EBP + -0x34) != 0) {
        _vm_map_lookup_done(*(undefined4 *)(unaff_EBP + 8));
        *(undefined4 *)(unaff_EBP + -0x34) = 0;
      }
      iVar8 = _vm_pager_get(*(undefined4 *)(unaff_EDI + 0x28),unaff_ESI);
      if (iVar8 != 0) {
        if (iVar8 == 2) {
          piVar11 = *(int **)(unaff_EBP + -0x4c);
          do {
            do {
            } while (*piVar11 != 0);
            LOCK();
            iVar8 = *piVar11;
            *piVar11 = 1;
            UNLOCK();
          } while (iVar8 == 1);
          bVar4 = *(byte *)(unaff_ESI + 8);
          *(byte *)(unaff_ESI + 8) = bVar4 & 0xfe;
          if ((bVar4 & 2) != 0) {
            *(byte *)(unaff_ESI + 8) = bVar4 & 0xfc;
            _thread_wakeup_prim(unaff_ESI,0);
          }
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          _vm_page_queue_lock = 1;
          UNLOCK();
          _vm_page_free();
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
          *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
          LOCK();
          *(undefined4 *)(unaff_EDI + 0x10) = 0;
          UNLOCK();
          if (unaff_EDI != *(int *)(unaff_EBP + -8)) {
            piVar11 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
            do {
              do {
              } while (*piVar11 != 0);
              LOCK();
              iVar8 = *piVar11;
              *piVar11 = 1;
              UNLOCK();
            } while (iVar8 == 1);
            iVar8 = *(int *)(unaff_EBP + -0x2c);
            bVar4 = *(byte *)(iVar8 + 0x20);
            *(byte *)(iVar8 + 0x20) = bVar4 & 0xfe;
            if ((bVar4 & 2) != 0) {
              *(byte *)(iVar8 + 0x20) = bVar4 & 0xfc;
              _thread_wakeup_prim(iVar8,0);
            }
            do {
            } while (_vm_page_queue_lock != 0);
            LOCK();
            _vm_page_queue_lock = 1;
            UNLOCK();
            _vm_page_free();
            LOCK();
            _vm_page_queue_lock = 0;
            UNLOCK();
            iVar8 = *(int *)(unaff_EBP + -8);
            psVar2 = (short *)(iVar8 + 0x44);
            *psVar2 = *psVar2 + -1;
            LOCK();
            *(undefined4 *)(iVar8 + 0x10) = 0;
            UNLOCK();
          }
          if (*(int *)(unaff_EBP + -0x34) != 0) {
            _vm_map_lookup_done(*(undefined4 *)(unaff_EBP + 8));
          }
          _vm_object_deallocate();
          return 10;
        }
        piVar11 = *(int **)(unaff_EBP + -0x4c);
        do {
          do {
          } while (*piVar11 != 0);
          LOCK();
          iVar8 = *piVar11;
          *piVar11 = 1;
          UNLOCK();
        } while (iVar8 == 1);
        if (*(int *)(unaff_EBP + -8) != unaff_EDI) {
          bVar4 = *(byte *)(unaff_ESI + 8);
          *(byte *)(unaff_ESI + 8) = bVar4 & 0xfe;
          if ((bVar4 & 2) != 0) {
            *(byte *)(unaff_ESI + 8) = bVar4 & 0xfc;
            _thread_wakeup_prim(unaff_ESI,0);
          }
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          _vm_page_queue_lock = 1;
          UNLOCK();
          _vm_page_free();
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
          goto LAB_00172998;
        }
        goto LAB_0017299d;
      }
      piVar11 = *(int **)(unaff_EBP + -0x4c);
      do {
        do {
        } while (*piVar11 != 0);
        LOCK();
        iVar8 = *piVar11;
        *piVar11 = 1;
        UNLOCK();
      } while (iVar8 == 1);
      unaff_ESI = (undefined4 *)_vm_page_lookup(unaff_EDI);
      _DAT_001f650c = _DAT_001f650c + 1;
      _pmap_clear_modify(unaff_ESI[9]);
    }
LAB_00172a30:
    if ((((*(byte *)(unaff_ESI + 8) & 0x20) != 0) || ((*(byte *)((int)unaff_ESI + 0x1e) & 3) != 0))
       || ((*(byte *)(unaff_ESI + 8) & 1) == 0)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_fault__absent_or_active_or_in_001e08e2);
    }
    *(undefined4 **)(unaff_EBP + -0x3c) = unaff_ESI;
    if (*(int *)(unaff_EBP + -8) != unaff_EDI) {
      if ((*(uint *)(unaff_EBP + 0x10) & 2) == 0) {
        *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffd;
        *(byte *)((int)unaff_ESI + 0x21) = *(byte *)((int)unaff_ESI + 0x21) | 4;
      }
      else {
        _vm_page_copy(unaff_ESI);
        pbVar1 = (byte *)(*(int *)(unaff_EBP + -0x2c) + 0x20);
        *pbVar1 = *pbVar1 & 0xdf;
        do {
        } while (_vm_page_queue_lock != 0);
        LOCK();
        _vm_page_queue_lock = 1;
        UNLOCK();
        _vm_page_activate();
        _vm_page_deactivate(unaff_ESI);
        if (*(int *)(unaff_EBP + -0x18) == 0) {
          _pmap_remove_all();
        }
        LOCK();
        _vm_page_queue_lock = 0;
        UNLOCK();
        bVar4 = *(byte *)(unaff_ESI + 8);
        *(byte *)(unaff_ESI + 8) = bVar4 & 0xfe;
        if ((bVar4 & 2) != 0) {
          *(byte *)(unaff_ESI + 8) = bVar4 & 0xfc;
          _thread_wakeup_prim(unaff_ESI,0);
        }
        *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
        LOCK();
        *(undefined4 *)(unaff_EDI + 0x10) = 0;
        UNLOCK();
        _DAT_001f6518 = _DAT_001f6518 + 1;
        unaff_ESI = *(undefined4 **)(unaff_EBP + -0x2c);
        unaff_EDI = *(int *)(unaff_EBP + -8);
        piVar11 = (int *)(unaff_EDI + 0x10);
        do {
          do {
          } while (*piVar11 != 0);
          LOCK();
          iVar8 = *piVar11;
          *piVar11 = 1;
          UNLOCK();
        } while (iVar8 == 1);
        *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
        _vm_object_collapse();
        *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + 1;
      }
    }
    if ((*(byte *)((int)unaff_ESI + 0x1e) & 3) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_fault__active_or_inactive_bef_001e0925);
    }
  } while( true );
  *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
  LOCK();
  *(undefined4 *)(unaff_EDI + 0x10) = 0;
  UNLOCK();
  if (unaff_EDI != *(int *)(unaff_EBP + -8)) {
    piVar11 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
    do {
      do {
      } while (*piVar11 != 0);
      LOCK();
      iVar8 = *piVar11;
      *piVar11 = 1;
      UNLOCK();
    } while (iVar8 == 1);
    iVar8 = *(int *)(unaff_EBP + -0x2c);
    bVar4 = *(byte *)(iVar8 + 0x20);
    *(byte *)(iVar8 + 0x20) = bVar4 & 0xfe;
    if ((bVar4 & 2) != 0) {
      *(byte *)(iVar8 + 0x20) = bVar4 & 0xfc;
      _thread_wakeup_prim(iVar8,0);
    }
    do {
    } while (_vm_page_queue_lock != 0);
    LOCK();
    _vm_page_queue_lock = 1;
    UNLOCK();
    _vm_page_free();
    LOCK();
    _vm_page_queue_lock = 0;
    UNLOCK();
    iVar8 = *(int *)(unaff_EBP + -8);
    psVar2 = (short *)(iVar8 + 0x44);
    *psVar2 = *psVar2 + -1;
    LOCK();
    *(undefined4 *)(iVar8 + 0x10) = 0;
    UNLOCK();
  }
  if (*(int *)(unaff_EBP + -0x34) != 0) {
    _vm_map_lookup_done(*(undefined4 *)(unaff_EBP + 8));
  }
  _vm_object_deallocate();
  do {
  } while (_vm_pages_needed_lock != 0);
  LOCK();
  UNLOCK();
LAB_00172e63:
  _vm_pages_needed_lock = 1;
  _thread_wakeup_prim(&_vm_pages_needed,0);
  _thread_sleep(&_vm_page_free_count,&_vm_pages_needed_lock,0);
  goto LAB_00172047;
}

