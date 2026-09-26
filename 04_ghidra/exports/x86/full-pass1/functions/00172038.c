/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00172038 */

/* WARNING: Removing unreachable block (ram,0x001731e5) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _vm_fault(int param_1,undefined4 param_2,uint param_3,int param_4,undefined4 param_5)

{
  short *psVar1;
  byte bVar2;
  undefined4 *puVar3;
  bool bVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  undefined4 *puVar12;
  int local_50;
  uint local_3c;
  undefined4 *local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  _DAT_001f6514 = _DAT_001f6514 + 1;
LAB_00172047:
  do {
    iVar6 = _vm_map_lookup(&param_1,param_2,param_3,&local_8,&local_c,&local_10,&local_14,&local_18,
                           &local_1c);
    if (iVar6 != 0) {
      return iVar6;
    }
    bVar4 = true;
    if (local_18 != 0) {
      param_3 = local_14;
    }
    local_30 = (undefined4 *)0x0;
    piVar10 = (int *)(local_c + 0x10);
    do {
      do {
      } while (*piVar10 != 0);
      LOCK();
      iVar6 = *piVar10;
      *piVar10 = 1;
      UNLOCK();
    } while (iVar6 == 1);
    *(short *)(local_c + 0x18) = *(short *)(local_c + 0x18) + 1;
    *(short *)(local_c + 0x44) = *(short *)(local_c + 0x44) + 1;
    local_2c = local_10;
    iVar6 = local_c;
LAB_001720cc:
    puVar7 = (undefined4 *)_vm_page_lookup(iVar6,local_2c);
    if (puVar7 == (undefined4 *)0x0) {
      if ((((*(int *)(iVar6 + 0x28) != 0) && ((param_4 == 0 || (local_18 != 0)))) ||
          (local_c == iVar6)) &&
         (puVar7 = (undefined4 *)_vm_page_alloc_sequential(iVar6,local_2c,1),
         puVar7 == (undefined4 *)0x0)) {
        *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
        LOCK();
        *(undefined4 *)(iVar6 + 0x10) = 0;
        UNLOCK();
        if (iVar6 != local_c) {
          piVar10 = (int *)(local_c + 0x10);
          do {
            do {
            } while (*piVar10 != 0);
            LOCK();
            iVar6 = *piVar10;
            *piVar10 = 1;
            UNLOCK();
          } while (iVar6 == 1);
          bVar2 = *(byte *)(local_30 + 8);
          *(byte *)(local_30 + 8) = bVar2 & 0xfe;
          if ((bVar2 & 2) != 0) {
            *(byte *)(local_30 + 8) = bVar2 & 0xfc;
            _thread_wakeup_prim(local_30,0,0);
          }
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          _vm_page_queue_lock = 1;
          UNLOCK();
          _vm_page_free(local_30);
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
          *(short *)(local_c + 0x44) = *(short *)(local_c + 0x44) + -1;
          LOCK();
          *(undefined4 *)(local_c + 0x10) = 0;
          UNLOCK();
        }
        if (bVar4) {
          _vm_map_lookup_done(param_1,local_8);
        }
        _vm_object_deallocate(local_c);
        do {
        } while (_vm_pages_needed_lock != 0);
        LOCK();
        UNLOCK();
        goto LAB_00172e63;
      }
      if ((*(int *)(iVar6 + 0x28) == 0) || ((param_4 != 0 && (local_18 == 0)))) {
LAB_00172998:
        if (local_c == iVar6) goto LAB_0017299d;
      }
      else {
        piVar10 = (int *)(iVar6 + 0x10);
        LOCK();
        *(undefined4 *)(iVar6 + 0x10) = 0;
        UNLOCK();
        if (bVar4) {
          _vm_map_lookup_done(param_1,local_8);
          bVar4 = false;
        }
        iVar9 = _vm_pager_get(*(undefined4 *)(iVar6 + 0x28),puVar7,param_5);
        if (iVar9 == 0) break;
        if (iVar9 == 2) {
          do {
            do {
            } while (*piVar10 != 0);
            LOCK();
            iVar9 = *piVar10;
            *piVar10 = 1;
            UNLOCK();
          } while (iVar9 == 1);
          bVar2 = *(byte *)(puVar7 + 8);
          *(byte *)(puVar7 + 8) = bVar2 & 0xfe;
          if ((bVar2 & 2) != 0) {
            *(byte *)(puVar7 + 8) = bVar2 & 0xfc;
            _thread_wakeup_prim(puVar7,0,0);
          }
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          _vm_page_queue_lock = 1;
          UNLOCK();
          _vm_page_free(puVar7);
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
          *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
          LOCK();
          *(undefined4 *)(iVar6 + 0x10) = 0;
          UNLOCK();
          if (iVar6 != local_c) {
            piVar10 = (int *)(local_c + 0x10);
            do {
              do {
              } while (*piVar10 != 0);
              LOCK();
              iVar6 = *piVar10;
              *piVar10 = 1;
              UNLOCK();
            } while (iVar6 == 1);
            bVar2 = *(byte *)(local_30 + 8);
            *(byte *)(local_30 + 8) = bVar2 & 0xfe;
            if ((bVar2 & 2) != 0) {
              *(byte *)(local_30 + 8) = bVar2 & 0xfc;
              _thread_wakeup_prim(local_30,0,0);
            }
            do {
            } while (_vm_page_queue_lock != 0);
            LOCK();
            _vm_page_queue_lock = 1;
            UNLOCK();
            _vm_page_free(local_30);
            LOCK();
            _vm_page_queue_lock = 0;
            UNLOCK();
            *(short *)(local_c + 0x44) = *(short *)(local_c + 0x44) + -1;
            LOCK();
            *(undefined4 *)(local_c + 0x10) = 0;
            UNLOCK();
          }
          if (bVar4) {
            _vm_map_lookup_done(param_1,local_8);
          }
          _vm_object_deallocate(local_c);
          return 10;
        }
        do {
          do {
          } while (*piVar10 != 0);
          LOCK();
          iVar9 = *piVar10;
          *piVar10 = 1;
          UNLOCK();
        } while (iVar9 == 1);
        if (local_c != iVar6) {
          bVar2 = *(byte *)(puVar7 + 8);
          *(byte *)(puVar7 + 8) = bVar2 & 0xfe;
          if ((bVar2 & 2) != 0) {
            *(byte *)(puVar7 + 8) = bVar2 & 0xfc;
            _thread_wakeup_prim(puVar7,0,0);
          }
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          _vm_page_queue_lock = 1;
          UNLOCK();
          _vm_page_free(puVar7);
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
          goto LAB_00172998;
        }
LAB_0017299d:
        local_30 = puVar7;
      }
      local_2c = local_2c + *(int *)(iVar6 + 0x24);
      local_50 = *(int *)(iVar6 + 0x20);
      if (local_50 != 0) {
        piVar10 = (int *)(local_50 + 0x10);
        do {
          do {
          } while (*piVar10 != 0);
          LOCK();
          iVar9 = *piVar10;
          *piVar10 = 1;
          UNLOCK();
        } while (iVar9 == 1);
        if (local_c != iVar6) {
          *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
        }
        goto LAB_00172a1d;
      }
      if (iVar6 != local_c) {
        *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
        LOCK();
        *(undefined4 *)(iVar6 + 0x10) = 0;
        UNLOCK();
        piVar10 = (int *)(local_c + 0x10);
        do {
          do {
          } while (*piVar10 != 0);
          LOCK();
          iVar9 = *piVar10;
          *piVar10 = 1;
          UNLOCK();
          puVar7 = local_30;
          iVar6 = local_c;
        } while (iVar9 == 1);
      }
      local_30 = (undefined4 *)0x0;
      _vm_page_zero_fill(puVar7);
      _DAT_001f6504 = _DAT_001f6504 + 1;
      *(byte *)(puVar7 + 8) = *(byte *)(puVar7 + 8) & 0xdf;
      goto LAB_00172a30;
    }
    bVar2 = *(byte *)(puVar7 + 8);
    if ((bVar2 & 0x40) != 0) {
      *(byte *)(puVar7 + 8) = bVar2 & 0xfe;
      if ((bVar2 & 2) != 0) {
        *(byte *)(puVar7 + 8) = bVar2 & 0xfc;
        _thread_wakeup_prim(puVar7,0,0);
      }
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      _vm_page_free(puVar7);
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
      LOCK();
      *(undefined4 *)(iVar6 + 0x10) = 0;
      UNLOCK();
      if (iVar6 != local_c) {
        piVar10 = (int *)(local_c + 0x10);
        do {
          do {
          } while (*piVar10 != 0);
          LOCK();
          iVar6 = *piVar10;
          *piVar10 = 1;
          UNLOCK();
        } while (iVar6 == 1);
        bVar2 = *(byte *)(local_30 + 8);
        *(byte *)(local_30 + 8) = bVar2 & 0xfe;
        if ((bVar2 & 2) != 0) {
          *(byte *)(local_30 + 8) = bVar2 & 0xfc;
          _thread_wakeup_prim(local_30,0,0);
        }
        do {
        } while (_vm_page_queue_lock != 0);
        LOCK();
        _vm_page_queue_lock = 1;
        UNLOCK();
        _vm_page_free(local_30);
        LOCK();
        _vm_page_queue_lock = 0;
        UNLOCK();
        *(short *)(local_c + 0x44) = *(short *)(local_c + 0x44) + -1;
        LOCK();
        *(undefined4 *)(local_c + 0x10) = 0;
        UNLOCK();
      }
      if (bVar4) {
        _vm_map_lookup_done(param_1,local_8);
      }
      _vm_object_deallocate(local_c);
      return 10;
    }
    if ((bVar2 & 1) == 0) {
      if ((bVar2 & 0x20) == 0) goto LAB_001724c0;
      local_2c = local_2c + *(int *)(iVar6 + 0x24);
      local_50 = *(int *)(iVar6 + 0x20);
      if (local_50 == 0) {
        if (local_c != iVar6) {
          *(byte *)(puVar7 + 8) = bVar2 & 0xde;
          *(byte *)(puVar7 + 8) = bVar2 & 0xde;
          if ((bVar2 & 2) != 0) {
            *(byte *)(puVar7 + 8) = bVar2 & 0xdc;
            _thread_wakeup_prim(puVar7,0,0);
          }
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          _vm_page_queue_lock = 1;
          UNLOCK();
          _vm_page_free(puVar7);
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
          *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
          LOCK();
          *(undefined4 *)(iVar6 + 0x10) = 0;
          UNLOCK();
          piVar10 = (int *)(local_c + 0x10);
          do {
            do {
            } while (*piVar10 != 0);
            LOCK();
            iVar9 = *piVar10;
            *piVar10 = 1;
            UNLOCK();
            puVar7 = local_30;
            iVar6 = local_c;
          } while (iVar9 == 1);
        }
        local_30 = (undefined4 *)0x0;
        _vm_page_zero_fill(puVar7);
        _DAT_001f6504 = _DAT_001f6504 + 1;
        *(byte *)(puVar7 + 8) = *(byte *)(puVar7 + 8) & 0xdf;
LAB_001724c0:
        if ((puVar7[10] & param_3) != 0) {
          *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
          LOCK();
          *(undefined4 *)(iVar6 + 0x10) = 0;
          UNLOCK();
          if (iVar6 != local_c) {
            piVar10 = (int *)(local_c + 0x10);
            do {
              do {
              } while (*piVar10 != 0);
              LOCK();
              iVar6 = *piVar10;
              *piVar10 = 1;
              UNLOCK();
            } while (iVar6 == 1);
            bVar2 = *(byte *)(local_30 + 8);
            *(byte *)(local_30 + 8) = bVar2 & 0xfe;
            if ((bVar2 & 2) != 0) {
              *(byte *)(local_30 + 8) = bVar2 & 0xfc;
              _thread_wakeup_prim(local_30,0,0);
            }
            do {
            } while (_vm_page_queue_lock != 0);
            LOCK();
            _vm_page_queue_lock = 1;
            UNLOCK();
            _vm_page_free(local_30);
            LOCK();
            _vm_page_queue_lock = 0;
            UNLOCK();
            *(short *)(local_c + 0x44) = *(short *)(local_c + 0x44) + -1;
            LOCK();
            *(undefined4 *)(local_c + 0x10) = 0;
            UNLOCK();
          }
          if (bVar4) {
            _vm_map_lookup_done(param_1,local_8);
          }
          _vm_object_deallocate(local_c);
          return 10;
        }
        do {
        } while (_vm_page_queue_lock != 0);
        LOCK();
        UNLOCK();
        if ((*(byte *)((int)puVar7 + 0x1e) & 1) != 0) {
          puVar12 = (undefined4 *)*puVar7;
          puVar3 = (undefined4 *)puVar7[1];
          puVar5 = puVar3;
          if ((undefined4 **)puVar12 != &_vm_page_queue_inactive) {
            puVar12[1] = puVar3;
            puVar5 = DAT_001f64e4;
          }
          DAT_001f64e4 = puVar5;
          if ((undefined4 **)puVar3 != &_vm_page_queue_inactive) {
            *puVar3 = puVar12;
            puVar12 = _vm_page_queue_inactive;
          }
          _vm_page_queue_inactive = puVar12;
          *(byte *)((int)puVar7 + 0x1e) = *(byte *)((int)puVar7 + 0x1e) & 0xfe;
          _vm_page_inactive_count = _vm_page_inactive_count + -1;
          _DAT_001f6508 = _DAT_001f6508 + 1;
        }
        if ((*(byte *)((int)puVar7 + 0x1e) & 2) != 0) {
          puVar12 = (undefined4 *)*puVar7;
          puVar3 = (undefined4 *)puVar7[1];
          puVar5 = puVar3;
          if ((undefined4 **)puVar12 != &_vm_page_queue_active) {
            puVar12[1] = puVar3;
            puVar5 = DAT_001f6e44;
          }
          DAT_001f6e44 = puVar5;
          if ((undefined4 **)puVar3 != &_vm_page_queue_active) {
            *puVar3 = puVar12;
            puVar12 = _vm_page_queue_active;
          }
          _vm_page_queue_active = puVar12;
          *(byte *)((int)puVar7 + 0x1e) = *(byte *)((int)puVar7 + 0x1e) & 0xfd;
          _vm_page_active_count = _vm_page_active_count + -1;
        }
        if ((*(byte *)((int)puVar7 + 0x1e) & 8) != 0) {
          puVar12 = (undefined4 *)*puVar7;
          puVar3 = (undefined4 *)puVar7[1];
          puVar5 = puVar3;
          if ((undefined4 **)puVar12 != &_vm_page_queue_free) {
            puVar12[1] = puVar3;
            puVar5 = DAT_001f6e4c;
          }
          DAT_001f6e4c = puVar5;
          if ((undefined4 **)puVar3 != &_vm_page_queue_free) {
            *puVar3 = puVar12;
            puVar12 = _vm_page_queue_free;
          }
          _vm_page_queue_free = puVar12;
          *(byte *)((int)puVar7 + 0x1e) = *(byte *)((int)puVar7 + 0x1e) & 0xf7;
          _vm_page_free_count = _vm_page_free_count + -1;
          _DAT_001f6508 = _DAT_001f6508 + 1;
        }
        LOCK();
        _vm_page_queue_lock = 0;
        UNLOCK();
        *(byte *)(puVar7 + 8) = *(byte *)(puVar7 + 8) & 0xdf | 1;
        goto LAB_00172a30;
      }
      if (local_c == iVar6) {
        *(byte *)(puVar7 + 8) = bVar2 & 0xdf;
        local_30 = puVar7;
      }
      else {
        *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
        bVar2 = *(byte *)(puVar7 + 8);
        *(byte *)(puVar7 + 8) = bVar2 & 0xfe;
        if ((bVar2 & 2) != 0) {
          *(byte *)(puVar7 + 8) = bVar2 & 0xfc;
          _thread_wakeup_prim(puVar7,0,0);
        }
        do {
        } while (_vm_page_queue_lock != 0);
        LOCK();
        _vm_page_queue_lock = 1;
        UNLOCK();
        _vm_page_free(puVar7);
        LOCK();
        _vm_page_queue_lock = 0;
        UNLOCK();
      }
      piVar10 = (int *)(local_50 + 0x10);
      do {
        do {
        } while (*piVar10 != 0);
        LOCK();
        iVar9 = *piVar10;
        *piVar10 = 1;
        UNLOCK();
      } while (iVar9 == 1);
LAB_00172a1d:
      LOCK();
      *(undefined4 *)(iVar6 + 0x10) = 0;
      UNLOCK();
      *(short *)(local_50 + 0x44) = *(short *)(local_50 + 0x44) + 1;
      iVar6 = local_50;
      goto LAB_001720cc;
    }
    *(byte *)(puVar7 + 8) = bVar2 | 2;
    _assert_wait(puVar7,param_4 == 0);
    if (bVar4) {
      _vm_map_lookup_done(param_1,local_8);
      bVar4 = false;
    }
    piVar10 = (int *)(iVar6 + 0x10);
    LOCK();
    *(undefined4 *)(iVar6 + 0x10) = 0;
    UNLOCK();
    _thread_block();
    iVar9 = *(int *)(_active_threads + 0x44);
    do {
      do {
      } while (*piVar10 != 0);
      LOCK();
      iVar8 = *piVar10;
      *piVar10 = 1;
      UNLOCK();
    } while (iVar8 == 1);
    if (iVar9 != 4) {
      if (iVar9 != 0) {
        *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
        LOCK();
        *(undefined4 *)(iVar6 + 0x10) = 0;
        UNLOCK();
        if (iVar6 != local_c) {
          piVar10 = (int *)(local_c + 0x10);
          do {
            do {
            } while (*piVar10 != 0);
            LOCK();
            iVar6 = *piVar10;
            *piVar10 = 1;
            UNLOCK();
          } while (iVar6 == 1);
          bVar2 = *(byte *)(local_30 + 8);
          *(byte *)(local_30 + 8) = bVar2 & 0xfe;
          if ((bVar2 & 2) != 0) {
            *(byte *)(local_30 + 8) = bVar2 & 0xfc;
            _thread_wakeup_prim(local_30,0,0);
          }
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          _vm_page_queue_lock = 1;
          UNLOCK();
          _vm_page_free(local_30);
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
          *(short *)(local_c + 0x44) = *(short *)(local_c + 0x44) + -1;
          LOCK();
          *(undefined4 *)(local_c + 0x10) = 0;
          UNLOCK();
        }
        if (bVar4) {
          _vm_map_lookup_done(param_1,local_8);
        }
        _vm_object_deallocate(local_c);
        return 0;
      }
      goto LAB_001720cc;
    }
    *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
    LOCK();
    *(undefined4 *)(iVar6 + 0x10) = 0;
    UNLOCK();
    if (iVar6 != local_c) {
      piVar10 = (int *)(local_c + 0x10);
      do {
        do {
        } while (*piVar10 != 0);
        LOCK();
        iVar6 = *piVar10;
        *piVar10 = 1;
        UNLOCK();
      } while (iVar6 == 1);
      bVar2 = *(byte *)(local_30 + 8);
      *(byte *)(local_30 + 8) = bVar2 & 0xfe;
      if ((bVar2 & 2) != 0) {
        *(byte *)(local_30 + 8) = bVar2 & 0xfc;
        _thread_wakeup_prim(local_30,0,0);
      }
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      UNLOCK();
LAB_001733bf:
      _vm_page_queue_lock = 1;
      _vm_page_free(local_30);
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      *(short *)(local_c + 0x44) = *(short *)(local_c + 0x44) + -1;
      LOCK();
      *(undefined4 *)(local_c + 0x10) = 0;
      UNLOCK();
    }
LAB_001733df:
    if (bVar4) {
      _vm_map_lookup_done(param_1,local_8);
    }
    _vm_object_deallocate(local_c);
  } while( true );
  do {
    do {
    } while (*piVar10 != 0);
    LOCK();
    iVar9 = *piVar10;
    *piVar10 = 1;
    UNLOCK();
  } while (iVar9 == 1);
  puVar7 = (undefined4 *)_vm_page_lookup(iVar6,local_2c);
  _DAT_001f650c = _DAT_001f650c + 1;
  _pmap_clear_modify(puVar7[9]);
LAB_00172a30:
  if ((((*(byte *)(puVar7 + 8) & 0x20) != 0) || ((*(byte *)((int)puVar7 + 0x1e) & 3) != 0)) ||
     ((*(byte *)(puVar7 + 8) & 1) == 0)) {
                    /* WARNING: Subroutine does not return */
    _panic(s_vm_fault__absent_or_active_or_in_001e08e2);
  }
  puVar12 = puVar7;
  if (local_c != iVar6) {
    if ((param_3 & 2) == 0) {
      local_14 = local_14 & 0xfffffffd;
      *(byte *)((int)puVar7 + 0x21) = *(byte *)((int)puVar7 + 0x21) | 4;
    }
    else {
      _vm_page_copy(puVar7,local_30);
      *(byte *)(local_30 + 8) = *(byte *)(local_30 + 8) & 0xdf;
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      _vm_page_activate(puVar7);
      _vm_page_deactivate(puVar7);
      if (local_1c == 0) {
        _pmap_remove_all(puVar7[9]);
      }
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      bVar2 = *(byte *)(puVar7 + 8);
      *(byte *)(puVar7 + 8) = bVar2 & 0xfe;
      if ((bVar2 & 2) != 0) {
        *(byte *)(puVar7 + 8) = bVar2 & 0xfc;
        _thread_wakeup_prim(puVar7,0,0);
      }
      iVar9 = local_c;
      *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
      LOCK();
      *(undefined4 *)(iVar6 + 0x10) = 0;
      UNLOCK();
      _DAT_001f6518 = _DAT_001f6518 + 1;
      piVar10 = (int *)(local_c + 0x10);
      do {
        do {
        } while (*piVar10 != 0);
        LOCK();
        iVar6 = *piVar10;
        *piVar10 = 1;
        UNLOCK();
      } while (iVar6 == 1);
      *(short *)(local_c + 0x44) = *(short *)(local_c + 0x44) + -1;
      _vm_object_collapse(local_c);
      psVar1 = (short *)(iVar9 + 0x44);
      *psVar1 = *psVar1 + 1;
      puVar12 = local_30;
      iVar6 = iVar9;
    }
  }
  if ((*(byte *)((int)puVar12 + 0x1e) & 3) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_vm_fault__active_or_inactive_bef_001e0925);
  }
LAB_00172b3f:
  iVar9 = *(int *)(local_c + 0x1c);
  if (iVar9 == 0) goto LAB_00173090;
  if ((param_3 & 2) == 0) {
    local_14 = local_14 & 0xfffffffd;
    *(byte *)((int)puVar12 + 0x21) = *(byte *)((int)puVar12 + 0x21) | 4;
    goto LAB_00173090;
  }
  LOCK();
  iVar8 = *(int *)(iVar9 + 0x10);
  *(int *)(iVar9 + 0x10) = 1;
  UNLOCK();
  if (iVar8 == 1) goto code_r0x00172b7a;
  *(short *)(iVar9 + 0x18) = *(short *)(iVar9 + 0x18) + 1;
  iVar11 = local_10 - *(int *)(iVar9 + 0x24);
  iVar8 = _vm_page_lookup(iVar9,iVar11);
  local_3c = (uint)(iVar8 != 0);
  if (local_3c != 0) {
    if ((*(byte *)(iVar8 + 0x20) & 1) != 0) {
      *(byte *)(iVar8 + 0x20) = *(byte *)(iVar8 + 0x20) | 2;
      _assert_wait(iVar8,param_4 == 0);
      bVar2 = *(byte *)(puVar12 + 8);
      *(byte *)(puVar12 + 8) = bVar2 & 0xfe;
      if ((bVar2 & 2) != 0) {
        *(byte *)(puVar12 + 8) = bVar2 & 0xfc;
        _thread_wakeup_prim(puVar12,0,0);
      }
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      _vm_page_activate(puVar12);
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      *(short *)(iVar9 + 0x18) = *(short *)(iVar9 + 0x18) + -1;
      LOCK();
      *(undefined4 *)(iVar9 + 0x10) = 0;
      UNLOCK();
      *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
      LOCK();
      *(undefined4 *)(iVar6 + 0x10) = 0;
      UNLOCK();
      if (iVar6 != local_c) {
        piVar10 = (int *)(local_c + 0x10);
        do {
          do {
          } while (*piVar10 != 0);
          LOCK();
          iVar6 = *piVar10;
          *piVar10 = 1;
          UNLOCK();
        } while (iVar6 == 1);
        bVar2 = *(byte *)(local_30 + 8);
        *(byte *)(local_30 + 8) = bVar2 & 0xfe;
        if ((bVar2 & 2) != 0) {
          *(byte *)(local_30 + 8) = bVar2 & 0xfc;
          _thread_wakeup_prim(local_30,0,0);
        }
        do {
        } while (_vm_page_queue_lock != 0);
        LOCK();
        _vm_page_queue_lock = 1;
        UNLOCK();
        _vm_page_free(local_30);
        LOCK();
        _vm_page_queue_lock = 0;
        UNLOCK();
        *(short *)(local_c + 0x44) = *(short *)(local_c + 0x44) + -1;
        LOCK();
        *(undefined4 *)(local_c + 0x10) = 0;
        UNLOCK();
      }
      if (bVar4) {
        _vm_map_lookup_done(param_1,local_8);
      }
      _thread_block();
      iVar6 = *(int *)(_active_threads + 0x44);
      _vm_object_deallocate(local_c);
      if (iVar6 != 0) {
        return 0;
      }
      goto LAB_00172047;
    }
    if (local_3c != 0) goto LAB_00173080;
  }
  iVar8 = _vm_page_alloc_sequential(iVar9,iVar11,1);
  if (iVar8 != 0) {
    if (*(int *)(iVar9 + 0x28) == 0) goto LAB_00173007;
    LOCK();
    *(undefined4 *)(iVar6 + 0x10) = 0;
    UNLOCK();
    piVar10 = (int *)(iVar9 + 0x10);
    LOCK();
    *(undefined4 *)(iVar9 + 0x10) = 0;
    UNLOCK();
    if (bVar4) {
      _vm_map_lookup_done(param_1,local_8);
      bVar4 = false;
    }
    local_3c = _vm_pager_has_page(*(undefined4 *)(iVar9 + 0x28),iVar11 + *(int *)(iVar9 + 0x2c));
    do {
      do {
      } while (*piVar10 != 0);
      LOCK();
      iVar11 = *piVar10;
      *piVar10 = 1;
      UNLOCK();
    } while (iVar11 == 1);
    if ((*(int *)(iVar9 + 0x20) != iVar6) || (*(short *)(iVar9 + 0x18) == 1)) {
      bVar2 = *(byte *)(iVar8 + 0x20);
      *(byte *)(iVar8 + 0x20) = bVar2 & 0xfe;
      if ((bVar2 & 2) != 0) {
        *(byte *)(iVar8 + 0x20) = bVar2 & 0xfc;
        _thread_wakeup_prim(iVar8,0,0);
      }
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      _vm_page_free(iVar8);
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      LOCK();
      *(undefined4 *)(iVar9 + 0x10) = 0;
      UNLOCK();
      _vm_object_deallocate(iVar9);
      piVar10 = (int *)(iVar6 + 0x10);
      do {
        do {
        } while (*piVar10 != 0);
        LOCK();
        iVar9 = *piVar10;
        *piVar10 = 1;
        UNLOCK();
      } while (iVar9 == 1);
      goto LAB_00172b3f;
    }
    piVar10 = (int *)(iVar6 + 0x10);
    do {
      do {
      } while (*piVar10 != 0);
      LOCK();
      iVar11 = *piVar10;
      *piVar10 = 1;
      UNLOCK();
    } while (iVar11 == 1);
    if (local_3c == 0) {
LAB_0017300d:
      _vm_page_copy(puVar12,iVar8);
      *(byte *)(iVar8 + 0x20) = *(byte *)(iVar8 + 0x20) & 0xdf;
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      _pmap_remove_all(puVar7[9]);
      *(byte *)(iVar8 + 0x1e) = *(byte *)(iVar8 + 0x1e) & 0xdf;
      _vm_page_activate(iVar8);
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      bVar2 = *(byte *)(iVar8 + 0x20);
      *(byte *)(iVar8 + 0x20) = bVar2 & 0xfe;
      if ((bVar2 & 2) != 0) {
        *(byte *)(iVar8 + 0x20) = bVar2 & 0xfc;
        _thread_wakeup_prim(iVar8,0,0);
      }
    }
    else {
      bVar2 = *(byte *)(iVar8 + 0x20);
      *(byte *)(iVar8 + 0x20) = bVar2 & 0xfe;
      if ((bVar2 & 2) != 0) {
        *(byte *)(iVar8 + 0x20) = bVar2 & 0xfc;
        _thread_wakeup_prim(iVar8,0,0);
      }
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      _vm_page_free(iVar8);
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
LAB_00173007:
      if (local_3c == 0) goto LAB_0017300d;
    }
LAB_00173080:
    *(short *)(iVar9 + 0x18) = *(short *)(iVar9 + 0x18) + -1;
    LOCK();
    *(undefined4 *)(iVar9 + 0x10) = 0;
    UNLOCK();
    *(byte *)((int)puVar12 + 0x21) = *(byte *)((int)puVar12 + 0x21) & 0xfb;
LAB_00173090:
    if ((*(byte *)((int)puVar12 + 0x1e) & 3) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_fault__active_or_inactive_bef_001e095e);
    }
    if (bVar4) {
LAB_00173408:
      if ((local_14 & 2) != 0) {
        *(byte *)((int)puVar12 + 0x21) = *(byte *)((int)puVar12 + 0x21) & 0xfb;
      }
      if ((*(byte *)((int)puVar12 + 0x1e) & 3) == 0) {
        piVar10 = (int *)(iVar6 + 0x10);
        LOCK();
        *(undefined4 *)(iVar6 + 0x10) = 0;
        UNLOCK();
        _pmap_enter(*(undefined4 *)(param_1 + 0x24),param_2,puVar12[9],~puVar12[10] & local_14,
                    local_18);
        do {
          do {
          } while (*piVar10 != 0);
          LOCK();
          iVar9 = *piVar10;
          *piVar10 = 1;
          UNLOCK();
        } while (iVar9 == 1);
        do {
        } while (_vm_page_queue_lock != 0);
        LOCK();
        _vm_page_queue_lock = 1;
        UNLOCK();
        if (param_4 == 0) {
          _vm_page_activate(puVar12);
        }
        else if (local_18 == 0) {
          _vm_page_unwire(puVar12);
        }
        else {
          _vm_page_wire(puVar12);
        }
        LOCK();
        _vm_page_queue_lock = 0;
        UNLOCK();
        bVar2 = *(byte *)(puVar12 + 8);
        *(byte *)(puVar12 + 8) = bVar2 & 0xfe;
        if ((bVar2 & 2) != 0) {
          *(byte *)(puVar12 + 8) = bVar2 & 0xfc;
          _thread_wakeup_prim(puVar12,0,0);
        }
        *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
        LOCK();
        *(undefined4 *)(iVar6 + 0x10) = 0;
        UNLOCK();
        if (iVar6 != local_c) {
          piVar10 = (int *)(local_c + 0x10);
          do {
            do {
            } while (*piVar10 != 0);
            LOCK();
            iVar6 = *piVar10;
            *piVar10 = 1;
            UNLOCK();
          } while (iVar6 == 1);
          bVar2 = *(byte *)(local_30 + 8);
          *(byte *)(local_30 + 8) = bVar2 & 0xfe;
          if ((bVar2 & 2) != 0) {
            *(byte *)(local_30 + 8) = bVar2 & 0xfc;
            _thread_wakeup_prim(local_30,0,0);
          }
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          _vm_page_queue_lock = 1;
          UNLOCK();
          _vm_page_free(local_30);
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
          *(short *)(local_c + 0x44) = *(short *)(local_c + 0x44) + -1;
          LOCK();
          *(undefined4 *)(local_c + 0x10) = 0;
          UNLOCK();
        }
        _vm_map_lookup_done(param_1,local_8);
        _vm_object_deallocate(local_c);
        return 0;
      }
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_fault__active_or_inactive_bef_001e0992);
    }
    piVar10 = (int *)(iVar6 + 0x10);
    LOCK();
    *(undefined4 *)(iVar6 + 0x10) = 0;
    UNLOCK();
    iVar9 = _vm_map_lookup(&param_1,param_2,param_3 & 0xfffffffd,&local_8,&local_20,&local_24,
                           &local_28,&local_18,&local_1c);
    do {
      do {
      } while (*piVar10 != 0);
      LOCK();
      iVar8 = *piVar10;
      *piVar10 = 1;
      UNLOCK();
    } while (iVar8 == 1);
    if (iVar9 != 0) {
      bVar2 = *(byte *)(puVar12 + 8);
      *(byte *)(puVar12 + 8) = bVar2 & 0xfe;
      if ((bVar2 & 2) != 0) {
        *(byte *)(puVar12 + 8) = bVar2 & 0xfc;
        _thread_wakeup_prim(puVar12,0,0);
      }
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      _vm_page_activate(puVar12);
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
      LOCK();
      *(undefined4 *)(iVar6 + 0x10) = 0;
      UNLOCK();
      if (iVar6 != local_c) {
        piVar10 = (int *)(local_c + 0x10);
        do {
          do {
          } while (*piVar10 != 0);
          LOCK();
          iVar6 = *piVar10;
          *piVar10 = 1;
          UNLOCK();
        } while (iVar6 == 1);
        bVar2 = *(byte *)(local_30 + 8);
        *(byte *)(local_30 + 8) = bVar2 & 0xfe;
        if ((bVar2 & 2) != 0) {
          *(byte *)(local_30 + 8) = bVar2 & 0xfc;
          _thread_wakeup_prim(local_30,0,0);
        }
        do {
        } while (_vm_page_queue_lock != 0);
        LOCK();
        _vm_page_queue_lock = 1;
        UNLOCK();
        _vm_page_free(local_30);
        LOCK();
        _vm_page_queue_lock = 0;
        UNLOCK();
        *(short *)(local_c + 0x44) = *(short *)(local_c + 0x44) + -1;
        LOCK();
        *(undefined4 *)(local_c + 0x10) = 0;
        UNLOCK();
      }
      _vm_object_deallocate(local_c);
      return iVar9;
    }
    bVar4 = true;
    if ((local_20 != local_c) || (local_24 != local_10)) {
      bVar2 = *(byte *)(puVar12 + 8);
      *(byte *)(puVar12 + 8) = bVar2 & 0xfe;
      if ((bVar2 & 2) != 0) {
        *(byte *)(puVar12 + 8) = bVar2 & 0xfc;
        _thread_wakeup_prim(puVar12,0,0);
      }
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      _vm_page_activate(puVar12);
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
      LOCK();
      *(undefined4 *)(iVar6 + 0x10) = 0;
      UNLOCK();
      if (iVar6 == local_c) goto LAB_001733df;
      piVar10 = (int *)(local_c + 0x10);
      do {
        do {
        } while (*piVar10 != 0);
        LOCK();
        iVar6 = *piVar10;
        *piVar10 = 1;
        UNLOCK();
      } while (iVar6 == 1);
      bVar2 = *(byte *)(local_30 + 8);
      *(byte *)(local_30 + 8) = bVar2 & 0xfe;
      if ((bVar2 & 2) != 0) {
        *(byte *)(local_30 + 8) = bVar2 & 0xfc;
        _thread_wakeup_prim(local_30,0,0);
      }
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      UNLOCK();
      goto LAB_001733bf;
    }
    local_14 = local_14 & local_28;
    if ((*(byte *)((int)puVar12 + 0x21) & 4) != 0) {
      local_14 = local_14 & 0xfffffffd;
    }
    if ((local_18 == 0) || (local_14 == param_3)) goto LAB_00173408;
    bVar2 = *(byte *)(puVar12 + 8);
    *(byte *)(puVar12 + 8) = bVar2 & 0xfe;
    if ((bVar2 & 2) != 0) {
      *(byte *)(puVar12 + 8) = bVar2 & 0xfc;
      _thread_wakeup_prim(puVar12,0,0);
    }
    do {
    } while (_vm_page_queue_lock != 0);
    LOCK();
    _vm_page_queue_lock = 1;
    UNLOCK();
    _vm_page_activate(puVar12);
    LOCK();
    _vm_page_queue_lock = 0;
    UNLOCK();
    *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
    LOCK();
    *(undefined4 *)(iVar6 + 0x10) = 0;
    UNLOCK();
    if (iVar6 != local_c) {
      piVar10 = (int *)(local_c + 0x10);
      do {
        do {
        } while (*piVar10 != 0);
        LOCK();
        iVar6 = *piVar10;
        *piVar10 = 1;
        UNLOCK();
      } while (iVar6 == 1);
      bVar2 = *(byte *)(local_30 + 8);
      *(byte *)(local_30 + 8) = bVar2 & 0xfe;
      if ((bVar2 & 2) != 0) {
        *(byte *)(local_30 + 8) = bVar2 & 0xfc;
        _thread_wakeup_prim(local_30,0,0);
      }
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      UNLOCK();
      goto LAB_001733bf;
    }
    goto LAB_001733df;
  }
  bVar2 = *(byte *)(puVar12 + 8);
  *(byte *)(puVar12 + 8) = bVar2 & 0xfe;
  if ((bVar2 & 2) != 0) {
    *(byte *)(puVar12 + 8) = bVar2 & 0xfc;
    _thread_wakeup_prim(puVar12,0,0);
  }
  do {
  } while (_vm_page_queue_lock != 0);
  LOCK();
  _vm_page_queue_lock = 1;
  UNLOCK();
  _vm_page_activate(puVar12);
  LOCK();
  _vm_page_queue_lock = 0;
  UNLOCK();
  *(short *)(iVar9 + 0x18) = *(short *)(iVar9 + 0x18) + -1;
  LOCK();
  *(undefined4 *)(iVar9 + 0x10) = 0;
  UNLOCK();
  *(short *)(iVar6 + 0x44) = *(short *)(iVar6 + 0x44) + -1;
  LOCK();
  *(undefined4 *)(iVar6 + 0x10) = 0;
  UNLOCK();
  if (iVar6 != local_c) {
    piVar10 = (int *)(local_c + 0x10);
    do {
      do {
      } while (*piVar10 != 0);
      LOCK();
      iVar6 = *piVar10;
      *piVar10 = 1;
      UNLOCK();
    } while (iVar6 == 1);
    bVar2 = *(byte *)(local_30 + 8);
    *(byte *)(local_30 + 8) = bVar2 & 0xfe;
    if ((bVar2 & 2) != 0) {
      *(byte *)(local_30 + 8) = bVar2 & 0xfc;
      _thread_wakeup_prim(local_30,0,0);
    }
    do {
    } while (_vm_page_queue_lock != 0);
    LOCK();
    _vm_page_queue_lock = 1;
    UNLOCK();
    _vm_page_free(local_30);
    LOCK();
    _vm_page_queue_lock = 0;
    UNLOCK();
    *(short *)(local_c + 0x44) = *(short *)(local_c + 0x44) + -1;
    LOCK();
    *(undefined4 *)(local_c + 0x10) = 0;
    UNLOCK();
  }
  if (bVar4) {
    _vm_map_lookup_done(param_1,local_8);
  }
  _vm_object_deallocate(local_c);
  do {
  } while (_vm_pages_needed_lock != 0);
  LOCK();
  UNLOCK();
LAB_00172e63:
  _vm_pages_needed_lock = 1;
  _thread_wakeup_prim(&_vm_pages_needed,0,0);
  _thread_sleep(&_vm_page_free_count,&_vm_pages_needed_lock,0);
  goto LAB_00172047;
code_r0x00172b7a:
  piVar10 = (int *)(iVar6 + 0x10);
  LOCK();
  *(undefined4 *)(iVar6 + 0x10) = 0;
  UNLOCK();
  do {
    do {
    } while (*piVar10 != 0);
    LOCK();
    iVar9 = *piVar10;
    *piVar10 = 1;
    UNLOCK();
  } while (iVar9 == 1);
  goto LAB_00172b3f;
}

