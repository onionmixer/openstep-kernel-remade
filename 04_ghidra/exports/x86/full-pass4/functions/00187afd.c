/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00187afd */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00187afd(void)

{
  uint uVar1;
  int unaff_EBX;
  uint unaff_ESI;
  
  uVar1 = 9 - unaff_EBX;
  if (5 < uVar1) {
                    /* WARNING: Subroutine does not return */
    _panic(s_clock_timer_constant_2_001e1813);
  }
  for (; 0 < (int)uVar1; uVar1 = uVar1 - 1) {
    unaff_ESI = unaff_ESI / 10;
  }
  if (0xffff < unaff_ESI) {
                    /* WARNING: Subroutine does not return */
    _panic(s_clock_timer_constant_3_001e182a);
  }
  DAT_001e75da = (undefined2)unaff_ESI;
  DAT_001e75d8._0_1_ = (undefined1)unaff_ESI;
  out(0x40,(undefined1)DAT_001e75d8);
  LOCK();
  UNLOCK();
  out(0x40,(char)(unaff_ESI >> 8));
  LOCK();
  _DAT_001e75c4 = _DAT_001e75c4 + 2;
  UNLOCK();
  DAT_001e75d8 = DAT_001e75da;
  _splx();
  return;
}

