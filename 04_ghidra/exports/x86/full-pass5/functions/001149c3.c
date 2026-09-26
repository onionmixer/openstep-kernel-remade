/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001149c3 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_001149c3(void)

{
  undefined4 *unaff_EBX;
  int unaff_EBP;
  
  *(undefined2 *)((int)unaff_EBX + 10) = 1;
  _DAT_001e917c = _DAT_001e917c + -1;
  _DAT_001e917e = _DAT_001e917e + 1;
  _mfree = *unaff_EBX;
  *unaff_EBX = 0;
  unaff_EBX[1] = 0xc;
  _splx();
  if (unaff_EBX != (undefined4 *)0x0) {
    unaff_EBX[1] = *(int *)(unaff_EBP + 0x10) - (int)unaff_EBX;
    *(undefined2 *)(unaff_EBX + 2) = *(undefined2 *)(unaff_EBP + 0x14);
    *(undefined2 *)(unaff_EBX + 3) = 2;
    unaff_EBX[4] = *(undefined4 *)(unaff_EBP + 8);
    unaff_EBX[5] = *(undefined4 *)(unaff_EBP + 0xc);
    unaff_EBX[6] = 0;
  }
  return;
}

