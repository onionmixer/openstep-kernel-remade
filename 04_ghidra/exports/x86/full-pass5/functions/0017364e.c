/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017364e */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0017364e(void)

{
  undefined4 uVar1;
  uint unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  do {
    _pmap_change_wiring();
    uVar1 = _vm_phys_to_vm_page(unaff_ESI);
    _vm_page_unwire(uVar1);
    unaff_EBX = unaff_EBX + _page_size;
    if (*(uint *)(unaff_EBP + -4) <= unaff_EBX) {
      LOCK();
      _vm_page_queue_lock = 0;
      UNLOCK();
      _pmap_pageable();
      return;
    }
    unaff_ESI = _pmap_extract();
  } while (unaff_ESI != 0);
                    /* WARNING: Subroutine does not return */
  _panic(s_unwire__page_not_in_pmap_001e09c1);
}

