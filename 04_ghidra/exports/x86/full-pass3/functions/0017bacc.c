/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017bacc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0017bacc(int param_1,int param_2)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  
  iVar4 = *(int *)(param_1 + 0x28);
  do {
  } while (_vm_page_queue_lock != 0);
  LOCK();
  _vm_page_queue_lock = 1;
  UNLOCK();
  if (((*(byte *)(param_2 + 0x1e) & 0x20) == 0) ||
     (iVar3 = _pmap_is_modified(*(undefined4 *)(param_2 + 0x24)), iVar3 != 0)) {
    if ((*(byte *)(param_2 + 0x20) & 1) == 0) {
      *(short *)(param_1 + 0x44) = *(short *)(param_1 + 0x44) + 1;
      *(byte *)(param_2 + 0x20) = *(byte *)(param_2 + 0x20) | 1;
      if ((*(byte *)(param_2 + 0x1e) & 1) != 0) {
        _vm_page_activate(param_2);
      }
      _vm_page_deactivate(param_2);
      _pmap_remove_all(*(undefined4 *)(param_2 + 0x24));
      _DAT_001f6510 = _DAT_001f6510 + 1;
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      if (iVar4 == 0) {
        *(short *)(param_1 + 0x44) = *(short *)(param_1 + 0x44) + -1;
        uVar5 = 1;
      }
      else {
        piVar1 = (int *)(param_1 + 0x10);
        LOCK();
        *(undefined4 *)(param_1 + 0x10) = 0;
        UNLOCK();
        iVar4 = _vm_pager_put(iVar4,param_2);
        uVar5 = iVar4 != 0;
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar4 == 1);
        do {
        } while (_vm_page_queue_lock != 0);
        LOCK();
        _vm_page_queue_lock = 1;
        UNLOCK();
        bVar2 = *(byte *)(param_2 + 0x20);
        *(byte *)(param_2 + 0x20) = bVar2 & 0xfe;
        if ((bVar2 & 2) != 0) {
          *(byte *)(param_2 + 0x20) = bVar2 & 0xfc;
          _thread_wakeup_prim(param_2,0,0);
        }
        *(short *)(param_1 + 0x44) = *(short *)(param_1 + 0x44) + -1;
        LOCK();
        _vm_page_queue_lock = 0;
        UNLOCK();
      }
    }
    else {
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      *(byte *)(param_2 + 0x20) = *(byte *)(param_2 + 0x20) | 2;
      _assert_wait(param_2,0);
      piVar1 = (int *)(param_1 + 0x10);
      LOCK();
      *(undefined4 *)(param_1 + 0x10) = 0;
      UNLOCK();
      _thread_block();
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar4 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      uVar5 = 2;
    }
  }
  else {
    LOCK();
    _vm_page_queue_lock = 0;
    UNLOCK();
    uVar5 = 0;
  }
  return uVar5;
}

