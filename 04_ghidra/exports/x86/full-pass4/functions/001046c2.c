/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001046c2 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_001046c2(void)

{
  undefined1 uVar1;
  int unaff_EBX;
  int unaff_EBP;
  
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    uVar1 = _copyout(unaff_EBP + -0x40,*(undefined4 *)(unaff_EBX + 4));
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
  }
  return;
}

