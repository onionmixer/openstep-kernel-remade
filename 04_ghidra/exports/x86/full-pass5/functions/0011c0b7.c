/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011c0b7 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011c0b7(void)

{
  uint *puVar1;
  short sVar2;
  int unaff_EBX;
  int unaff_EBP;
  uint unaff_EDI;
  
  sVar2 = *(short *)(unaff_EBX + 10);
  *(short *)(unaff_EBX + 10) = sVar2 + -1;
  if ((sVar2 == 1) &&
     (*(byte *)(unaff_EBX + 4) = *(byte *)(unaff_EBX + 4) & 0xeb, (unaff_EDI & 0x10) != 0)) {
    _wakeup();
  }
  puVar1 = (uint *)(*(int *)(unaff_EBP + 8) + 8);
  *puVar1 = *puVar1 & 0xfffffeff;
  return;
}

