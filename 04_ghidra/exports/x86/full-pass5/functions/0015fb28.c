/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015fb28 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __regparm1 _vmp_invalidate(uint param_1,int param_2)

{
  uint *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  puVar3 = *(undefined4 **)(param_2 + 0x24);
  if (puVar3 != (undefined4 *)0x0) {
    do {
    } while (_vm_page_queue_lock != 0);
    LOCK();
    _vm_page_queue_lock = 1;
    UNLOCK();
    puVar1 = puVar3 + 4;
    do {
      do {
      } while (*puVar1 != 0);
      LOCK();
      param_1 = *puVar1;
      *puVar1 = 1;
      UNLOCK();
      param_1 = param_1 ^ 1;
    } while (param_1 == 0);
    if (*(undefined4 **)(param_2 + 0x24) == puVar3) {
      puVar4 = (undefined4 *)*puVar3;
      while (puVar6 = puVar4, puVar3 != puVar6) {
        puVar4 = (undefined4 *)puVar6[2];
        if ((*(byte *)((int)puVar6 + 0x21) & 8) == 0) {
          if ((*(byte *)(puVar6 + 8) & 1) == 0) {
            if (*(short *)(puVar6 + 7) == 0) {
              _pmap_remove_all(puVar6[9]);
              if (((*(byte *)((int)puVar6 + 0x1e) & 0x20) == 0) ||
                 (iVar5 = _pmap_is_modified(puVar6[9]), iVar5 != 0)) {
                __mfs_mdirty = __mfs_mdirty + 1;
              }
              else {
                __mfs_mclean = __mfs_mclean + 1;
                _vm_page_free(puVar6);
              }
            }
          }
          else {
            *(byte *)(puVar6 + 8) = *(byte *)(puVar6 + 8) | 2;
            _assert_wait(puVar6,0);
            LOCK();
            puVar3[4] = 0;
            UNLOCK();
            LOCK();
            _vm_page_queue_lock = 0;
            UNLOCK();
            _thread_block();
            do {
            } while (_vm_page_queue_lock != 0);
            LOCK();
            _vm_page_queue_lock = 1;
            UNLOCK();
            piVar2 = puVar3 + 4;
            do {
              do {
              } while (*piVar2 != 0);
              LOCK();
              iVar5 = *piVar2;
              *piVar2 = 1;
              UNLOCK();
              puVar4 = puVar6;
            } while (iVar5 == 1);
          }
        }
      }
      LOCK();
      puVar3[4] = 0;
      param_1 = _vm_page_queue_lock;
      UNLOCK();
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
    }
  }
  return param_1;
}

