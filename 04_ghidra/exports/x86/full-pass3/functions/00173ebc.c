/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00173ebc */

undefined4 FUN_00173ebc(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_3 != 0) {
    piVar2 = (int *)(param_1 + 0x10);
    do {
      do {
        do {
        } while (*piVar2 != 0);
        LOCK();
        iVar1 = *piVar2;
        *piVar2 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      while (iVar1 = _vm_page_alloc_sequential(param_1,param_2,1), iVar1 == 0) {
        LOCK();
        *(undefined4 *)(param_1 + 0x10) = 0;
        UNLOCK();
        if (param_4 == 0) {
          return 0;
        }
        do {
        } while (_vm_pages_needed_lock != 0);
        LOCK();
        _vm_pages_needed_lock = 1;
        UNLOCK();
        _thread_wakeup_prim(&_vm_pages_needed,0,0);
        _thread_sleep(&_vm_page_free_count,&_vm_pages_needed_lock,0);
        piVar3 = (int *)(param_1 + 0x10);
        do {
          do {
          } while (*piVar3 != 0);
          LOCK();
          iVar1 = *piVar3;
          *piVar3 = 1;
          UNLOCK();
        } while (iVar1 == 1);
      }
      LOCK();
      *(undefined4 *)(param_1 + 0x10) = 0;
      UNLOCK();
      _vm_page_zero_fill(iVar1);
      *(byte *)(iVar1 + 0x20) = *(byte *)(iVar1 + 0x20) & 0xfe;
      param_3 = param_3 - _page_size;
      param_2 = param_2 + _page_size;
    } while (param_3 != 0);
  }
  return 1;
}

