/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114600 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00114600(void)

{
  short sVar1;
  size_t sVar2;
  undefined4 uVar3;
  size_t sVar4;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  undefined4 *puVar5;
  undefined4 *unaff_EDI;
  
  *(undefined2 *)((int)unaff_EDI + 10) = *(undefined2 *)((int)unaff_ESI + 10);
  _DAT_001e917c = _DAT_001e917c + -1;
  *(short *)(&DAT_001e917c + *(short *)((int)unaff_ESI + 10) * 2) =
       *(short *)(&DAT_001e917c + *(short *)((int)unaff_ESI + 10) * 2) + 1;
  _mfree = (undefined4 *)*unaff_EDI;
  *unaff_EDI = 0;
  unaff_EDI[1] = 0xc;
  _splx();
  if (unaff_EDI != (undefined4 *)0x0) {
    *(undefined2 *)(unaff_EDI + 2) = 0;
    *(int *)(unaff_EBP + -4) = 0x7c - unaff_EDI[1];
    do {
      *(int *)(unaff_EBP + -0x10) = (int)*(short *)(unaff_ESI + 2);
      sVar2 = *(int *)(unaff_EBP + 0xc) + 0x20;
      sVar4 = *(int *)(unaff_EBP + -4) - (int)*(short *)(unaff_EDI + 2);
      if ((int)sVar2 < (int)sVar4) {
        sVar4 = sVar2;
      }
      if (*(int *)(unaff_EBP + -0x10) < (int)sVar4) {
        sVar4 = *(size_t *)(unaff_EBP + -0x10);
      }
      _bcopy((void *)((int)unaff_ESI + unaff_ESI[1]),
             (void *)((int)unaff_EDI + (int)*(short *)(unaff_EDI + 2) + unaff_EDI[1]),sVar4);
      *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) - sVar4;
      *(short *)(unaff_EDI + 2) = *(short *)(unaff_EDI + 2) + (short)sVar4;
      sVar1 = *(short *)(unaff_ESI + 2) - (short)sVar4;
      *(short *)(unaff_ESI + 2) = sVar1;
      if (sVar1 == 0) {
        uVar3 = _splimp();
        *(undefined4 *)(unaff_EBP + -8) = uVar3;
        if (*(short *)((int)unaff_ESI + 10) == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_mfree_001db1dd);
        }
        *(short *)(&DAT_001e917c + *(short *)((int)unaff_ESI + 10) * 2) =
             *(short *)(&DAT_001e917c + *(short *)((int)unaff_ESI + 10) * 2) + -1;
        _DAT_001e917c = _DAT_001e917c + 1;
        *(undefined2 *)((int)unaff_ESI + 10) = 0;
        if (0x7f < (uint)unaff_ESI[1]) {
          _mclput();
        }
        puVar5 = (undefined4 *)*unaff_ESI;
        *unaff_ESI = _mfree;
        unaff_ESI[1] = 0;
        unaff_ESI[0x1f] = 0;
        _mfree = unaff_ESI;
        _splx();
        if (_m_want != 0) {
          _m_want = 0;
          _wakeup();
        }
      }
      else {
        unaff_ESI[1] = unaff_ESI[1] + sVar4;
        puVar5 = unaff_ESI;
      }
      if (*(int *)(unaff_EBP + 0xc) < 1) {
        *unaff_EDI = puVar5;
        return;
      }
      unaff_ESI = puVar5;
    } while (puVar5 != (undefined4 *)0x0);
    _splimp();
    if (*(short *)((int)unaff_EDI + 10) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_mfree_001db1dd);
    }
    *(short *)(&DAT_001e917c + *(short *)((int)unaff_EDI + 10) * 2) =
         *(short *)(&DAT_001e917c + *(short *)((int)unaff_EDI + 10) * 2) + -1;
    _DAT_001e917c = _DAT_001e917c + 1;
    *(undefined2 *)((int)unaff_EDI + 10) = 0;
    if (0x7f < (uint)unaff_EDI[1]) {
      _mclput();
    }
    *unaff_EDI = _mfree;
    unaff_EDI[1] = 0;
    unaff_EDI[0x1f] = 0;
    _mfree = unaff_EDI;
    _splx();
    unaff_ESI = (undefined4 *)0x0;
    if (_m_want != 0) {
      _m_want = 0;
      _wakeup();
    }
  }
  if (unaff_ESI != (undefined4 *)0x0) {
    uVar3 = _splimp();
    *(undefined4 *)(unaff_EBP + -0xc) = uVar3;
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
      puVar5 = (undefined4 *)*unaff_ESI;
      *unaff_ESI = _mfree;
      unaff_ESI[1] = 0;
      unaff_ESI[0x1f] = 0;
      _mfree = unaff_ESI;
      _splx();
      if (_m_want != 0) {
        _m_want = 0;
        _wakeup();
      }
      unaff_ESI = puVar5;
    } while (puVar5 != (undefined4 *)0x0);
    _splx();
  }
  return;
}

