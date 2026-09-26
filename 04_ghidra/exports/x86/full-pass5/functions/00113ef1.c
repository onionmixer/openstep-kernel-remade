/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00113ef1 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00113ef1(void)

{
  undefined4 uVar1;
  undefined4 *unaff_EBX;
  
  *(short *)(&DAT_001e917c + *(short *)((int)unaff_EBX + 10) * 2) =
       *(short *)(&DAT_001e917c + *(short *)((int)unaff_EBX + 10) * 2) + -1;
  _DAT_001e917c = _DAT_001e917c + 1;
  *(undefined2 *)((int)unaff_EBX + 10) = 0;
  if (0x7f < (uint)unaff_EBX[1]) {
    _mclput();
  }
  uVar1 = *unaff_EBX;
  *unaff_EBX = _mfree;
  unaff_EBX[1] = 0;
  unaff_EBX[0x1f] = 0;
  _mfree = unaff_EBX;
  _splx();
  if (_m_want != 0) {
    _m_want = 0;
    _wakeup();
  }
  return uVar1;
}

