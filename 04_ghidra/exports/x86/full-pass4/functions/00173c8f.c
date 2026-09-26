/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00173c8f */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00173c8f(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  int unaff_ESI;
  
  iVar3 = *(int *)(*(int *)(unaff_EBP + -0xc) + 0x10);
  _vm_object_reference();
  piVar1 = (int *)(iVar3 + 0x10);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  if (*(int *)(iVar3 + 0x14) != *(int *)(unaff_EBP + -0x14)) {
                    /* WARNING: Subroutine does not return */
    _panic(s_kmem_realloc_001e0a09);
  }
  *(int *)(iVar3 + 0x14) = unaff_ESI;
  LOCK();
  *(undefined4 *)(iVar3 + 0x10) = 0;
  UNLOCK();
  iVar2 = *(int *)(unaff_EBP + -8);
  *(int *)(iVar2 + 0x10) = iVar3;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  uVar4 = *(undefined4 *)(unaff_EBP + 8);
  _lock_done();
  FUN_00173ebc(iVar3,*(undefined4 *)(unaff_EBP + -0x14));
  _vm_map_pageable(uVar4,*(int *)(unaff_EBP + -4),unaff_ESI + *(int *)(unaff_EBP + -4),0);
  **(undefined4 **)(unaff_EBP + 0x14) = *(undefined4 *)(unaff_EBP + -4);
  return 0;
}

