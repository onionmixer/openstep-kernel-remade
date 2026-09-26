/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011e805 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011e805(void)

{
  short sVar1;
  int unaff_EBX;
  
  sVar1 = *(short *)(unaff_EBX + 6);
  *(short *)(unaff_EBX + 6) = sVar1 + -1;
  if (sVar1 == 1) {
    (**(code **)(*(int *)(unaff_EBX + 0x1c) + 0x4c))();
  }
  return;
}

