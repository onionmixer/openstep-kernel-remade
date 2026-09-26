/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113deb */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00113deb(void)

{
  undefined4 *unaff_EBX;
  int unaff_ESI;
  
  *(short *)((int)unaff_EBX + 10) = (short)unaff_ESI;
  _DAT_001e917c = _DAT_001e917c + -1;
  *(short *)(&DAT_001e917c + unaff_ESI * 2) = *(short *)(&DAT_001e917c + unaff_ESI * 2) + 1;
  _mfree = *unaff_EBX;
  *unaff_EBX = 0;
  unaff_EBX[1] = 0xc;
  _splx();
  return;
}

