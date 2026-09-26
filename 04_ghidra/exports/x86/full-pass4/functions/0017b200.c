/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017b200 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * _vm_page_alloc_sequential(undefined4 *param_1,uint param_2,int param_3)

{
  byte *pbVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  
  uVar4 = _splimp();
  puVar5 = _vm_page_queue_free;
  do {
  } while (_vm_page_queue_free_lock != 0);
  LOCK();
  UNLOCK();
  if ((undefined4 **)_vm_page_queue_free == &_vm_page_queue_free) {
    LOCK();
    _vm_page_queue_free_lock = 0;
    UNLOCK();
    _splx(uVar4);
    puVar5 = (undefined4 *)0x0;
  }
  else if ((_vm_page_free_count < _vm_page_free_reserved) && (*(int *)(_active_threads + 0x78) == 0)
          ) {
    LOCK();
    _vm_page_queue_free_lock = 0;
    UNLOCK();
    _splx(uVar4);
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar6 = (undefined4 *)*_vm_page_queue_free;
    if ((undefined4 **)puVar6 == &_vm_page_queue_free) {
      DAT_001f6e4c = &_vm_page_queue_free;
    }
    else {
      puVar6[1] = &_vm_page_queue_free;
    }
    pbVar1 = (byte *)((int)_vm_page_queue_free + 0x1e);
    _vm_page_queue_free = puVar6;
    *pbVar1 = *pbVar1 & 0xf7;
    _vm_page_free_count = _vm_page_free_count + -1;
    LOCK();
    _vm_page_queue_free_lock = 0;
    UNLOCK();
    _splx(uVar4);
    if ((*(byte *)(puVar5 + 8) & 4) != 0) {
      piVar2 = (int *)(_vm_page_buckets +
                      (((uint)puVar5[6] >> ((byte)_page_shift & 0x1f)) + puVar5[5] &
                      __vm_page_hash_mask) * 8);
      uVar4 = _splimp();
      do {
        do {
        } while (*piVar2 != 0);
        LOCK();
        iVar7 = *piVar2;
        *piVar2 = 1;
        UNLOCK();
      } while (iVar7 == 1);
      puVar6 = (undefined4 *)piVar2[1];
      if (puVar5 == puVar6) {
        piVar2[1] = puVar5[4];
      }
      else {
        do {
          puVar8 = puVar6 + 4;
          puVar6 = (undefined4 *)puVar6[4];
        } while (puVar5 != puVar6);
        *puVar8 = puVar6[4];
      }
      LOCK();
      *piVar2 = 0;
      UNLOCK();
      _splx(uVar4);
      iVar7 = puVar5[2];
      piVar2 = (int *)puVar5[3];
      if (puVar5[5] == iVar7) {
        *(int **)(iVar7 + 4) = piVar2;
      }
      else {
        *(int **)(iVar7 + 0xc) = piVar2;
      }
      if ((int *)puVar5[5] == piVar2) {
        *piVar2 = iVar7;
      }
      else {
        piVar2[2] = iVar7;
      }
      *(short *)(puVar5[5] + 0x1a) = *(short *)(puVar5[5] + 0x1a) + -1;
      *(byte *)(puVar5 + 8) = *(byte *)(puVar5 + 8) & 0xfb;
    }
    uVar4 = puVar5[9];
    puVar6 = &_vm_page_template;
    puVar8 = puVar5;
    for (iVar7 = 0xc; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    puVar5[9] = uVar4;
    if ((*(byte *)(puVar5 + 8) & 4) != 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_page_insert_001e0d84);
    }
    puVar5[5] = param_1;
    puVar5[6] = param_2;
    piVar2 = (int *)(_vm_page_buckets +
                    ((param_2 >> ((byte)_page_shift & 0x1f)) + (int)param_1 & __vm_page_hash_mask) *
                    8);
    uVar4 = _splimp();
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar7 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar7 == 1);
    puVar5[4] = piVar2[1];
    piVar2[1] = (int)puVar5;
    LOCK();
    *piVar2 = 0;
    UNLOCK();
    _splx(uVar4);
    puVar6 = (undefined4 *)param_1[1];
    if (param_1 == puVar6) {
      *param_1 = puVar5;
    }
    else {
      puVar6[2] = puVar5;
    }
    puVar5[3] = puVar6;
    puVar5[2] = param_1;
    param_1[1] = puVar5;
    *(byte *)(puVar5 + 8) = *(byte *)(puVar5 + 8) | 4;
    *(short *)((int)param_1 + 0x1a) = *(short *)((int)param_1 + 0x1a) + 1;
    if ((_vm_page_free_count < _vm_page_free_min) ||
       ((_vm_page_free_count < _vm_page_free_target &&
        (_vm_page_inactive_count < _vm_page_inactive_target)))) {
      _thread_wakeup_prim(&_vm_pages_needed,0,0);
    }
    if (((*(byte *)(param_1 + 0x12) & 3) != 0) && (param_3 != 0)) {
      uVar3 = param_1[0x15];
      iVar7 = param_2 - uVar3;
      if (iVar7 < 0) {
        iVar7 = -iVar7;
      }
      if (_page_size == iVar7) {
        piVar2 = (int *)(_vm_page_buckets +
                        ((uVar3 >> ((byte)_page_shift & 0x1f)) + (int)param_1 & __vm_page_hash_mask)
                        * 8);
        uVar4 = _splimp();
        do {
          do {
          } while (*piVar2 != 0);
          LOCK();
          iVar7 = *piVar2;
          *piVar2 = 1;
          UNLOCK();
        } while (iVar7 == 1);
        for (iVar7 = piVar2[1];
            (iVar7 != 0 &&
            ((*(undefined4 **)(iVar7 + 0x14) != param_1 || (*(uint *)(iVar7 + 0x18) != uVar3))));
            iVar7 = *(int *)(iVar7 + 0x10)) {
        }
        LOCK();
        *piVar2 = 0;
        UNLOCK();
        _splx(uVar4);
        if (iVar7 != 0) {
          uVar4 = 0;
          if ((*(short *)(param_1 + 0x12) != 1) && (*(short *)(param_1 + 0x12) == 2)) {
            uVar4 = 1;
          }
          _vm_policy_apply(param_1,iVar7,uVar4);
        }
      }
    }
    param_1[0x15] = param_2;
  }
  return puVar5;
}

