/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00187b44 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00187b44(void)

{
  undefined2 unaff_SI;
  
  DAT_001e75d8._0_1_ = (undefined1)unaff_SI;
  out(0x40,(undefined1)DAT_001e75d8);
  LOCK();
  UNLOCK();
  out(0x40,(char)((ushort)unaff_SI >> 8));
  LOCK();
  _DAT_001e75c4 = _DAT_001e75c4 + 2;
  UNLOCK();
  DAT_001e75d8 = unaff_SI;
  DAT_001e75da = unaff_SI;
  _splx();
  return;
}

