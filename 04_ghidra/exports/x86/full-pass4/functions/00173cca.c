/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00173cca */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00173cca(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
  *(int *)(unaff_EBX + 0x14) = unaff_ESI;
  LOCK();
  *(undefined4 *)(unaff_EBX + 0x10) = 0;
  UNLOCK();
  iVar1 = *(int *)(unaff_EBP + -8);
  *(int *)(iVar1 + 0x10) = unaff_EBX;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  _lock_done();
  FUN_00173ebc();
  _vm_map_pageable(uVar2,*(int *)(unaff_EBP + -4),unaff_ESI + *(int *)(unaff_EBP + -4),0);
  **(undefined4 **)(unaff_EBP + 0x14) = *(undefined4 *)(unaff_EBP + -4);
  return 0;
}

