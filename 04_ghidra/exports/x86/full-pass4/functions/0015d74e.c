/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015d74e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0015d74e(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  uint unaff_EDI;
  
LAB_0015d751:
  *(undefined2 *)((int)unaff_ESI + 10) = 1;
  _DAT_001e917c = _DAT_001e917c + -1;
  _DAT_001e917e = _DAT_001e917e + 1;
  _mfree = (undefined4 *)*unaff_ESI;
  *unaff_ESI = 0;
  unaff_ESI[1] = 0xc;
  do {
    _splx();
    if (unaff_ESI == (undefined4 *)0x0) {
      _m_freem();
      return;
    }
    if (unaff_EDI < _page_size >> 1) {
LAB_0015d834:
      uVar3 = 0x70;
      if ((int)unaff_EDI < 0x71) {
LAB_0015d83e:
        uVar3 = unaff_EDI;
      }
    }
    else {
      uVar2 = _splimp();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
      if (_mclfree == (undefined4 *)0x0) {
        _m_clalloc(1,1);
      }
      puVar1 = _mclfree;
      if (_mclfree != (undefined4 *)0x0) {
        (&_mclrefcnt)[(int)_mclfree - __mbutl >> 10] =
             (&_mclrefcnt)[(int)_mclfree - __mbutl >> 10] + '\x01';
        _DAT_001e916c = _DAT_001e916c + -1;
        _mclfree = (undefined4 *)*_mclfree;
      }
      _splx();
      if (puVar1 == (undefined4 *)0x0) {
        *(undefined2 *)(unaff_ESI + 2) = 0x70;
      }
      else {
        unaff_ESI[1] = (int)puVar1 - (int)unaff_ESI;
        *(undefined2 *)(unaff_ESI + 2) = 0x400;
        *(undefined2 *)(unaff_ESI + 3) = 1;
      }
      uVar3 = (uint)*(short *)(unaff_ESI + 2);
      if (_page_size != uVar3) goto LAB_0015d834;
      if (unaff_EDI <= uVar3) goto LAB_0015d83e;
    }
    *(short *)(unaff_ESI + 2) = (short)uVar3;
    _bcopy(*(void **)(unaff_EBP + -0x10),(void *)((int)unaff_ESI + unaff_ESI[1]),uVar3);
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + uVar3;
    unaff_EDI = unaff_EDI - uVar3;
    **(undefined4 **)(unaff_EBP + -0xc) = unaff_ESI;
    *(undefined4 **)(unaff_EBP + -0xc) = unaff_ESI;
    if ((int)unaff_EDI < 1) {
      if (DAT_001def18 != *(int *)(*(int *)(unaff_EBP + -8) + 0x28)) {
        if (DAT_001def10 != 0) {
          if (*(short *)(DAT_001def10 + 0x26) == 1) {
            _rtfree();
          }
          else {
            *(short *)(DAT_001def10 + 0x26) = *(short *)(DAT_001def10 + 0x26) + -1;
          }
        }
        DAT_001def10 = 0;
      }
      _ip_output(*(undefined4 *)(unaff_EBP + -4),0,&DAT_001def10);
      return;
    }
    _splimp();
    if (_mfree != (undefined4 *)0x0) break;
    unaff_ESI = (undefined4 *)_m_more(1);
  } while( true );
  unaff_ESI = _mfree;
  if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&DAT_001def24);
  }
  goto LAB_0015d751;
}

