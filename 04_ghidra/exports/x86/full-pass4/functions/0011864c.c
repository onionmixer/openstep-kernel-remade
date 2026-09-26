/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011864c */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011864c(void)

{
  int *piVar1;
  int unaff_EBX;
  int unaff_ESI;
  
  if (unaff_EBX == 0) {
    piVar1 = (int *)_kalloc();
    _bzero(piVar1,0x24);
    *(int **)(unaff_ESI + 8) = piVar1;
    *piVar1 = unaff_ESI;
  }
  return;
}

