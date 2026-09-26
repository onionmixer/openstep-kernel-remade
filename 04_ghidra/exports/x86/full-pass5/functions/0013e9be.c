/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013e9be */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013e9be(void)

{
  int iVar1;
  int unaff_EBP;
  int unaff_EDI;
  
  _itrunc();
  *(short *)(unaff_EDI + 0x66) = *(short *)(unaff_EDI + 0x66) + -1;
  *(byte *)(unaff_EDI + 0x44) = *(byte *)(unaff_EDI + 0x44) | 0x40;
  if ((*(int *)(unaff_EBP + 8) != unaff_EDI) &&
     (iVar1 = FUN_0013e9f8(*(undefined4 *)(unaff_EBP + 0xc),*(undefined4 *)(unaff_EBP + 8)),
     iVar1 != 0)) {
    return iVar1;
  }
  return 0;
}

