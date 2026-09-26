/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00173422 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00173422(void)

{
  short *psVar1;
  int iVar2;
  byte bVar3;
  int *piVar4;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  *(int *)(unaff_EBP + -0x4c) = unaff_EDI + 0x10;
  LOCK();
  *(undefined4 *)(unaff_EDI + 0x10) = 0;
  UNLOCK();
  _pmap_enter(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x24),*(undefined4 *)(unaff_EBP + 0xc),
              *(undefined4 *)(unaff_ESI + 0x24),
              ~*(uint *)(unaff_ESI + 0x28) & *(uint *)(unaff_EBP + -0x10));
  piVar4 = *(int **)(unaff_EBP + -0x4c);
  do {
    do {
    } while (*piVar4 != 0);
    LOCK();
    iVar2 = *piVar4;
    *piVar4 = 1;
    UNLOCK();
  } while (iVar2 == 1);
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
  bVar3 = *(byte *)(unaff_ESI + 0x20);
  *(byte *)(unaff_ESI + 0x20) = bVar3 & 0xfe;
  if ((bVar3 & 2) != 0) {
    *(byte *)(unaff_ESI + 0x20) = bVar3 & 0xfc;
    _thread_wakeup_prim();
  }
  *(short *)(unaff_EDI + 0x44) = *(short *)(unaff_EDI + 0x44) + -1;
  LOCK();
  *(undefined4 *)(unaff_EDI + 0x10) = 0;
  UNLOCK();
  if (unaff_EDI != *(int *)(unaff_EBP + -8)) {
    piVar4 = (int *)(*(int *)(unaff_EBP + -8) + 0x10);
    do {
      do {
      } while (*piVar4 != 0);
      LOCK();
      iVar2 = *piVar4;
      *piVar4 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    iVar2 = *(int *)(unaff_EBP + -0x2c);
    bVar3 = *(byte *)(iVar2 + 0x20);
    *(byte *)(iVar2 + 0x20) = bVar3 & 0xfe;
    if ((bVar3 & 2) != 0) {
      *(byte *)(iVar2 + 0x20) = bVar3 & 0xfc;
      _thread_wakeup_prim(iVar2,0);
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
    iVar2 = *(int *)(unaff_EBP + -8);
    psVar1 = (short *)(iVar2 + 0x44);
    *psVar1 = *psVar1 + -1;
    LOCK();
    *(undefined4 *)(iVar2 + 0x10) = 0;
    UNLOCK();
  }
  if (*(int *)(unaff_EBP + -0x34) != 0) {
    _vm_map_lookup_done(*(undefined4 *)(unaff_EBP + 8));
  }
  _vm_object_deallocate();
  return 0;
}

