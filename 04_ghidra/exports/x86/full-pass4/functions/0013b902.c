/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013b902 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0013b902(void)

{
  int unaff_EBP;
  int unaff_EDI;
  
  if ((*(uint *)(unaff_EBP + 0xc) & (int)*(char *)(unaff_EDI + 0xd3)) == 0) {
    _fserr();
  }
  *(byte *)(unaff_EDI + 0xd3) = *(byte *)(unaff_EDI + 0xd3) | *(byte *)(unaff_EBP + 0xc);
  if ((*(byte *)(_active_u + 0x260) & 8) == 0) {
    _uprintf(s__s___s_001dda0e,unaff_EDI + 0xd4);
  }
  if (*(int *)(DAT_001e875c + 0x6c) == 0) {
    *(int *)(DAT_001e875c + 0x6c) = unaff_EDI;
    *(undefined1 *)(DAT_001e875c + 0x70) = *(undefined1 *)(unaff_EBP + 0xc);
  }
  *(undefined1 *)(DAT_001e875c + 0x68) = 0x1c;
  return;
}

