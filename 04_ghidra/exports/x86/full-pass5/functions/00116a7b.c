/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116a7b */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00116a7b(void)

{
  short *unaff_EBX;
  
  while (unaff_EBX[2] != 0) {
    _sbdrop();
  }
  if (((*unaff_EBX == 0) && (unaff_EBX[2] == 0)) && (*(int *)(unaff_EBX + 6) == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_sbflush_2_001db37a);
}

