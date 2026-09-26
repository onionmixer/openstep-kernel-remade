/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011a627 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0011a627(void)

{
  uint unaff_EBX;
  byte *unaff_EDI;
  
  (**(code **)(*(int *)(*(int *)(unaff_EDI + 0x40) + 0x1c) + 0x54))();
  if ((unaff_EBX & 0x100) == 0) {
    _biowait();
    _brelse();
  }
  else {
    *unaff_EDI = *unaff_EDI | 0x80;
  }
  return 0;
}

