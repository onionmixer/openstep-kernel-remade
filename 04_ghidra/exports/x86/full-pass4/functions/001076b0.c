/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001076b0 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_001076b0(void)

{
  int unaff_EBX;
  int unaff_ESI;
  
  if (*(int *)(*(int *)(unaff_EBX + 0x10) + 4) == 0) {
    _pgdelete();
  }
  *(undefined4 *)(unaff_EBX + 0x10) = 0;
  *(undefined2 *)(unaff_ESI + 0x2e) = 0;
  return;
}

