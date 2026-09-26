/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001245ce */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001245ce(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  size_t sVar5;
  int iVar6;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  size_t unaff_EDI;
  
LAB_001245d1:
  *(undefined2 *)((int)unaff_ESI + 10) = 1;
  _DAT_001e917c = _DAT_001e917c + -1;
  _DAT_001e917e = _DAT_001e917e + 1;
  _mfree = (undefined4 *)*unaff_ESI;
  *unaff_ESI = 0;
  unaff_ESI[1] = 0xc;
  do {
    _splx();
    if ((int)unaff_EDI < 0x200) {
LAB_001246ac:
      sVar5 = 0x70;
      if ((int)unaff_EDI < 0x71) {
LAB_001246b6:
        sVar5 = unaff_EDI;
      }
    }
    else {
      uVar4 = _splimp();
      *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
      if (_mclfree == (undefined4 *)0x0) {
        _m_clalloc(1,1);
      }
      puVar2 = _mclfree;
      if (_mclfree != (undefined4 *)0x0) {
        (&_mclrefcnt)[(int)_mclfree - __mbutl >> 10] =
             (&_mclrefcnt)[(int)_mclfree - __mbutl >> 10] + '\x01';
        _DAT_001e916c = _DAT_001e916c + -1;
        _mclfree = (undefined4 *)*_mclfree;
      }
      _splx();
      if (puVar2 == (undefined4 *)0x0) {
        *(undefined2 *)(unaff_ESI + 2) = 0x70;
      }
      else {
        unaff_ESI[1] = (int)puVar2 - (int)unaff_ESI;
        *(undefined2 *)(unaff_ESI + 2) = 0x400;
        *(undefined2 *)(unaff_ESI + 3) = 1;
      }
      if (*(short *)(unaff_ESI + 2) != 0x400) goto LAB_001246ac;
      sVar5 = 0x400;
      if ((int)unaff_EDI < 0x401) goto LAB_001246b6;
    }
    _bcopy(*(void **)(unaff_EBP + -0xc),(void *)((int)unaff_ESI + unaff_ESI[1]),sVar5);
    unaff_EDI = unaff_EDI - sVar5;
    *(int *)(unaff_EBP + -0xc) = *(int *)(unaff_EBP + -0xc) + sVar5;
    *(short *)(unaff_ESI + 2) = (short)sVar5;
    **(undefined4 **)(unaff_EBP + -8) = unaff_ESI;
    *(undefined4 **)(unaff_EBP + -8) = unaff_ESI;
    if ((int)unaff_EDI < 1) {
      iVar1 = *(int *)(unaff_EBP + -4);
      iVar6 = iVar1 + *(int *)(iVar1 + 4);
      *(undefined2 *)(iVar6 + 10) = 0;
      uVar3 = _in_cksum(iVar1);
      *(undefined2 *)(iVar6 + 10) = uVar3;
      return *(undefined4 *)(unaff_EBP + -4);
    }
    _splimp();
    if (_mfree != (undefined4 *)0x0) break;
    unaff_ESI = (undefined4 *)_m_more(1);
  } while( true );
  unaff_ESI = _mfree;
  if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&DAT_001dbab5);
  }
  goto LAB_001245d1;
}

