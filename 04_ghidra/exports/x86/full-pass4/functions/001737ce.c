/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001737ce */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_001737ce(void)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar2 = *(int *)(unaff_EBP + -0x1c);
  do {
    _vm_page_copy(iVar2);
    LOCK();
    *(undefined4 *)(*(int *)(unaff_EBP + -4) + 0x10) = 0;
    UNLOCK();
    LOCK();
    *(undefined4 *)(unaff_EDI + 0x10) = 0;
    UNLOCK();
    _pmap_enter(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),*(undefined4 *)(unaff_EBP + -0x14),
                *(undefined4 *)(unaff_ESI + 0x24),*(undefined4 *)(unaff_EBP + -0x10));
    piVar3 = (int *)(unaff_EDI + 0x10);
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar2 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    do {
    } while (_vm_page_queue_lock != 0);
    LOCK();
    _vm_page_queue_lock = 1;
    UNLOCK();
    _vm_page_activate();
    LOCK();
    _vm_page_queue_lock = 0;
    UNLOCK();
    bVar1 = *(byte *)(unaff_ESI + 0x20);
    *(byte *)(unaff_ESI + 0x20) = bVar1 & 0xfe;
    if ((bVar1 & 2) != 0) {
      *(byte *)(unaff_ESI + 0x20) = bVar1 & 0xfc;
      _thread_wakeup_prim(unaff_ESI,0);
    }
    LOCK();
    *(undefined4 *)(unaff_EDI + 0x10) = 0;
    iVar2 = _page_size;
    UNLOCK();
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + _page_size;
    *(int *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -8) + iVar2;
    if (*(uint *)(*(int *)(unaff_EBP + 0x10) + 0xc) <= *(uint *)(unaff_EBP + -0x14)) {
      return;
    }
    do {
      do {
      } while (**(int **)(unaff_EBP + -0x18) != 0);
      LOCK();
      iVar2 = **(int **)(unaff_EBP + -0x18);
      **(int **)(unaff_EBP + -0x18) = 1;
      UNLOCK();
    } while (iVar2 == 1);
    while (unaff_ESI = _vm_page_alloc_sequential(), unaff_ESI == 0) {
      LOCK();
      *(undefined4 *)(unaff_EDI + 0x10) = 0;
      UNLOCK();
      do {
      } while (_vm_pages_needed_lock != 0);
      LOCK();
      _vm_pages_needed_lock = 1;
      UNLOCK();
      _thread_wakeup_prim(&_vm_pages_needed,0);
      _thread_sleep(&_vm_page_free_count,&_vm_pages_needed_lock,0);
      piVar3 = (int *)(unaff_EDI + 0x10);
      do {
        do {
        } while (*piVar3 != 0);
        LOCK();
        iVar2 = *piVar3;
        *piVar3 = 1;
        UNLOCK();
      } while (iVar2 == 1);
    }
    piVar3 = (int *)(*(int *)(unaff_EBP + -4) + 0x10);
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar2 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    iVar2 = _vm_page_lookup(*(undefined4 *)(unaff_EBP + -4));
  } while (iVar2 != 0);
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
                    /* WARNING: Subroutine does not return */
  _panic(s_vm_fault_copy_wired__page_missin_001e09da);
}

