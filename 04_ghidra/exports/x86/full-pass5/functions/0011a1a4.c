/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011a1a4 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011a1a4(void)

{
  byte *unaff_EBX;
  uint unaff_ESI;
  int unaff_EDI;
  
  (**(code **)(*(int *)(*(int *)(unaff_EBX + 0x40) + 0x1c) + 0x54))();
  if ((unaff_ESI & 0x100) == 0) {
    _biowait();
    _brelse();
  }
  else if (unaff_EDI != 0) {
    *unaff_EBX = *unaff_EBX | 0x80;
  }
  return;
}

