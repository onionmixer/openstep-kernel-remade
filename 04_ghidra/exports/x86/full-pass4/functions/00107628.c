/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00107628 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00107628(void)

{
  int unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  
  if (*(int *)(*(int *)(unaff_ESI + 0x10) + 4) == 0) {
    _pgdelete();
  }
  *(int *)(unaff_ESI + 0x10) = unaff_EBX;
  *(undefined4 *)(unaff_ESI + 0xc) = *(undefined4 *)(unaff_EBX + 4);
  *(int *)(unaff_EBX + 4) = unaff_EDI;
  *(undefined2 *)(unaff_EDI + 0x2e) = *(undefined2 *)(*(int *)(unaff_ESI + 0x10) + 0xc);
  return;
}

