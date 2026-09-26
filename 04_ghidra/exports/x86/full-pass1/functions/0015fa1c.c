/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015fa1c */

int _vno_flush(int *param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = *param_1;
  iVar2 = *(int *)(iVar4 + 0x24);
  if (iVar2 != 0) {
    do {
    } while (_vm_page_queue_lock != 0);
    LOCK();
    _vm_page_queue_lock = 1;
    UNLOCK();
    piVar1 = (int *)(iVar2 + 0x10);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar4 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    uVar5 = param_3 + param_2 + _page_mask;
    uVar3 = ~_page_mask;
    param_2 = param_2 & uVar3;
    while (param_2 < (uVar5 & uVar3)) {
      iVar4 = _vm_page_lookup(iVar2,param_2);
      if (iVar4 == 0) {
LAB_0015fb05:
        param_2 = param_2 + _page_size;
      }
      else {
        if ((*(byte *)(iVar4 + 0x20) & 1) == 0) {
          _vm_page_free(iVar4);
          goto LAB_0015fb05;
        }
        *(byte *)(iVar4 + 0x20) = *(byte *)(iVar4 + 0x20) | 2;
        _assert_wait(iVar4,0);
        LOCK();
        *(undefined4 *)(iVar2 + 0x10) = 0;
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
        piVar1 = (int *)(iVar2 + 0x10);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar4 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar4 == 1);
      }
    }
    LOCK();
    *(undefined4 *)(iVar2 + 0x10) = 0;
    iVar4 = _vm_page_queue_lock;
    UNLOCK();
    LOCK();
    _vm_page_queue_lock = 0;
    UNLOCK();
  }
  return iVar4;
}

