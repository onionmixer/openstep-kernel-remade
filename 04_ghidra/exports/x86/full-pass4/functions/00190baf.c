/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00190baf */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00190baf(void)

{
  int iVar1;
  byte *pbVar2;
  int unaff_EBP;
  
  if (*(int *)(unaff_EBP + 0x10) == 0) {
    if ((*(byte *)(*(int *)(unaff_EBP + -0xc) + 1) & 2) != 0) {
      FUN_001910e4();
    }
  }
  else if ((*(byte *)(*(int *)(unaff_EBP + -0xc) + 1) & 2) == 0) {
    FUN_0019108c();
  }
  iVar1 = _ptes_per_vm_page;
  if (0 < _ptes_per_vm_page) {
    *(byte *)(unaff_EBP + -8) = (*(byte *)(unaff_EBP + 0x10) & 1) * '\x02';
    pbVar2 = (byte *)(*(int *)(unaff_EBP + -0xc) + 1);
    do {
      iVar1 = iVar1 + -1;
      *pbVar2 = *pbVar2 & 0xfd | *(byte *)(unaff_EBP + -8);
      pbVar2 = pbVar2 + 4;
    } while (0 < iVar1);
  }
  _splx();
  return;
}

