/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114782 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00114782(void)

{
  int *piVar1;
  undefined4 uVar2;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  *(short *)(&DAT_001e917c + *(short *)((int)unaff_EDI + 10) * 2) =
       *(short *)(&DAT_001e917c + *(short *)((int)unaff_EDI + 10) * 2) + -1;
  _DAT_001e917c = _DAT_001e917c + 1;
  *(undefined2 *)((int)unaff_EDI + 10) = 0;
  if (0x7f < (uint)unaff_EDI[1]) {
    _mclput();
  }
  *unaff_EDI = (int)_mfree;
  unaff_EDI[1] = 0;
  unaff_EDI[0x1f] = 0;
  _mfree = unaff_EDI;
  _splx();
  if (_m_want != 0) {
    _m_want = 0;
    _wakeup();
  }
  if (unaff_ESI != (int *)0x0) {
    uVar2 = _splimp();
    *(undefined4 *)(unaff_EBP + -0xc) = uVar2;
    do {
      _splimp();
      if (*(short *)((int)unaff_ESI + 10) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_mfree_001db1ef);
      }
      *(short *)(&DAT_001e917c + *(short *)((int)unaff_ESI + 10) * 2) =
           *(short *)(&DAT_001e917c + *(short *)((int)unaff_ESI + 10) * 2) + -1;
      _DAT_001e917c = _DAT_001e917c + 1;
      *(undefined2 *)((int)unaff_ESI + 10) = 0;
      if (0x7f < (uint)unaff_ESI[1]) {
        _mclput();
      }
      piVar1 = (int *)*unaff_ESI;
      *unaff_ESI = (int)_mfree;
      unaff_ESI[1] = 0;
      unaff_ESI[0x1f] = 0;
      _mfree = unaff_ESI;
      _splx();
      if (_m_want != 0) {
        _m_want = 0;
        _wakeup();
      }
      unaff_ESI = piVar1;
    } while (piVar1 != (int *)0x0);
    _splx();
  }
  return 0;
}

