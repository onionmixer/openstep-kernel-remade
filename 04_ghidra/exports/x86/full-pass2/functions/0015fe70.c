/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015fe70 */

int _vmp_push_all(int param_1)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  
  *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) & 0xfd;
  puVar4 = *(undefined4 **)(param_1 + 0x24);
  if (puVar4 == (undefined4 *)0x0) {
    return param_1;
  }
  do {
  } while (_vm_page_queue_lock != 0);
  LOCK();
  _vm_page_queue_lock = 1;
  UNLOCK();
  piVar1 = puVar4 + 4;
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar9 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar9 == 1);
LAB_0015febc:
  puVar5 = (undefined4 *)*puVar4;
  do {
    if (puVar4 == puVar5) {
      LOCK();
      puVar4[4] = 0;
      UNLOCK();
      LOCK();
      UNLOCK();
      iVar9 = _vm_page_queue_lock;
      _vm_page_queue_lock = 0;
      return iVar9;
    }
    if ((*(byte *)((int)puVar5 + 0x21) & 8) == 0) {
      if ((*(byte *)(puVar5 + 8) & 1) != 0) break;
      if ((*(byte *)((int)puVar5 + 0x1e) & 2) == 0) {
        _vm_page_activate(puVar5);
      }
      _vm_page_deactivate(puVar5);
      puVar6 = (undefined4 *)*puVar5;
      puVar7 = (undefined4 *)puVar5[1];
      puVar8 = puVar7;
      if ((undefined4 **)puVar6 != &_vm_page_queue_inactive) {
        puVar6[1] = puVar7;
        puVar8 = DAT_001f64e4;
      }
      DAT_001f64e4 = puVar8;
      if ((undefined4 **)puVar7 != &_vm_page_queue_inactive) {
        *puVar7 = puVar6;
        puVar6 = _vm_page_queue_inactive;
      }
      _vm_page_queue_inactive = puVar6;
      *(byte *)((int)puVar5 + 0x1e) = *(byte *)((int)puVar5 + 0x1e) & 0xfe;
      _vm_page_inactive_count = _vm_page_inactive_count + -1;
      *(byte *)(puVar5 + 8) = *(byte *)(puVar5 + 8) | 1;
      if ((*(byte *)((int)puVar5 + 0x1e) & 4) != 0) {
        _pmap_remove_all(puVar5[9]);
        *(short *)(puVar4 + 0x11) = *(short *)(puVar4 + 0x11) + 1;
        LOCK();
        puVar4[4] = 0;
        UNLOCK();
        LOCK();
        _vm_page_queue_lock = 0;
        UNLOCK();
        iVar9 = _vnode_pageout(puVar5);
        do {
        } while (_vm_page_queue_lock != 0);
        LOCK();
        _vm_page_queue_lock = 1;
        UNLOCK();
        piVar1 = puVar4 + 4;
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar2 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        *(short *)(puVar4 + 0x11) = *(short *)(puVar4 + 0x11) + -1;
        if (iVar9 == 0) {
          *(byte *)((int)puVar5 + 0x1e) = *(byte *)((int)puVar5 + 0x1e) & 0xfb;
        }
      }
      _vm_page_activate(puVar5);
      bVar3 = *(byte *)(puVar5 + 8);
      *(byte *)(puVar5 + 8) = bVar3 & 0xfe;
      if ((bVar3 & 2) != 0) {
        *(byte *)(puVar5 + 8) = bVar3 & 0xfc;
        _thread_wakeup_prim(puVar5,0,0);
      }
    }
    puVar5 = (undefined4 *)puVar5[2];
  } while( true );
  *(byte *)(puVar5 + 8) = *(byte *)(puVar5 + 8) | 2;
  _assert_wait(puVar5,0);
  LOCK();
  puVar4[4] = 0;
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
  piVar1 = puVar4 + 4;
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar9 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar9 == 1);
  goto LAB_0015febc;
}

