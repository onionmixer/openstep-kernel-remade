/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015fc58 */

int _vmp_push(int param_1)

{
  int *piVar1;
  int iVar2;
  byte bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  
  if ((*(byte *)(param_1 + 0x38) & 2) != 0) {
    *(byte *)(param_1 + 0x38) = *(byte *)(param_1 + 0x38) & 0xfd;
    uVar12 = *(uint *)(param_1 + 0x10);
    iVar10 = *(int *)(param_1 + 0xc);
    iVar4 = *(int *)(param_1 + 0x24);
    if (iVar4 != 0) {
      do {
      } while (_vm_page_queue_lock != 0);
      LOCK();
      _vm_page_queue_lock = 1;
      UNLOCK();
      piVar1 = (int *)(iVar4 + 0x10);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar2 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      uVar11 = iVar10 + uVar12 + _page_mask;
      uVar8 = ~_page_mask;
      uVar12 = uVar12 & uVar8;
      do {
        while( true ) {
          if ((uVar11 & uVar8) <= uVar12) {
            LOCK();
            *(undefined4 *)(iVar4 + 0x10) = 0;
            UNLOCK();
            LOCK();
            UNLOCK();
            iVar10 = _vm_page_queue_lock;
            _vm_page_queue_lock = 0;
            return iVar10;
          }
          puVar9 = (undefined4 *)_vm_page_lookup(iVar4,uVar12);
          if ((puVar9 != (undefined4 *)0x0) && ((*(byte *)((int)puVar9 + 0x21) & 8) == 0)) break;
LAB_0015fe48:
          uVar12 = uVar12 + _page_size;
        }
        if ((*(byte *)(puVar9 + 8) & 1) == 0) {
          if ((*(byte *)((int)puVar9 + 0x1e) & 2) == 0) {
            _vm_page_activate(puVar9);
          }
          _vm_page_deactivate(puVar9);
          puVar5 = (undefined4 *)*puVar9;
          puVar6 = (undefined4 *)puVar9[1];
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
          *(byte *)((int)puVar9 + 0x1e) = *(byte *)((int)puVar9 + 0x1e) & 0xfe;
          _vm_page_inactive_count = _vm_page_inactive_count + -1;
          *(byte *)(puVar9 + 8) = *(byte *)(puVar9 + 8) | 1;
          if ((*(byte *)((int)puVar9 + 0x1e) & 4) != 0) {
            _pmap_remove_all(puVar9[9]);
            *(short *)(iVar4 + 0x44) = *(short *)(iVar4 + 0x44) + 1;
            LOCK();
            *(undefined4 *)(iVar4 + 0x10) = 0;
            UNLOCK();
            LOCK();
            _vm_page_queue_lock = 0;
            UNLOCK();
            iVar10 = _vnode_pageout(puVar9);
            do {
            } while (_vm_page_queue_lock != 0);
            LOCK();
            _vm_page_queue_lock = 1;
            UNLOCK();
            piVar1 = (int *)(iVar4 + 0x10);
            do {
              do {
              } while (*piVar1 != 0);
              LOCK();
              iVar2 = *piVar1;
              *piVar1 = 1;
              UNLOCK();
            } while (iVar2 == 1);
            *(short *)(iVar4 + 0x44) = *(short *)(iVar4 + 0x44) + -1;
            if (iVar10 == 0) {
              *(byte *)((int)puVar9 + 0x1e) = *(byte *)((int)puVar9 + 0x1e) & 0xfb;
            }
          }
          _vm_page_activate(puVar9);
          bVar3 = *(byte *)(puVar9 + 8);
          *(byte *)(puVar9 + 8) = bVar3 & 0xfe;
          if ((bVar3 & 2) != 0) {
            *(byte *)(puVar9 + 8) = bVar3 & 0xfc;
            _thread_wakeup_prim(puVar9,0,0);
          }
          goto LAB_0015fe48;
        }
        *(byte *)(puVar9 + 8) = *(byte *)(puVar9 + 8) | 2;
        _assert_wait(puVar9,0);
        LOCK();
        *(undefined4 *)(iVar4 + 0x10) = 0;
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
        piVar1 = (int *)(iVar4 + 0x10);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar10 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar10 == 1);
      } while( true );
    }
  }
  return param_1;
}

