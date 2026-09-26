/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012ec1c */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0012ec1c(void)

{
  int unaff_EBP;
  
  **(int **)(unaff_EBP + -4) = **(int **)(unaff_EBP + -4) + 1;
  if ((*(byte *)(*(int *)(unaff_EBP + 8) + 0x14) & 5) == 5) {
    _clntkudp_interruptable(**(undefined4 **)(unaff_EBP + -0xc));
  }
  return **(undefined4 **)(unaff_EBP + -0xc);
}

