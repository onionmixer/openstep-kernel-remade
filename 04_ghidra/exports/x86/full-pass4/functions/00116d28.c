/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116d28 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00116d28(void)

{
  short sVar1;
  int *piVar2;
  undefined4 uVar3;
  int *unaff_EBX;
  int unaff_EBP;
  short *unaff_ESI;
  
  while( true ) {
    *(short *)(&DAT_001e917c + *(short *)((int)unaff_EBX + 10) * 2) =
         *(short *)(&DAT_001e917c + *(short *)((int)unaff_EBX + 10) * 2) + -1;
    _DAT_001e917c = _DAT_001e917c + 1;
    *(undefined2 *)((int)unaff_EBX + 10) = 0;
    if (0x7f < (uint)unaff_EBX[1]) {
      _mclput();
    }
    piVar2 = (int *)*unaff_EBX;
    *unaff_EBX = (int)_mfree;
    unaff_EBX[1] = 0;
    unaff_EBX[0x1f] = 0;
    _mfree = unaff_EBX;
    _splx();
    if (_m_want != 0) {
      _m_want = 0;
      _wakeup();
    }
    if (piVar2 == (int *)0x0) break;
    *unaff_ESI = *unaff_ESI - *(short *)(piVar2 + 2);
    sVar1 = unaff_ESI[2];
    unaff_ESI[2] = sVar1 + -0x80;
    if (0x7c < (uint)piVar2[1]) {
      unaff_ESI[2] = sVar1 + -0x480;
    }
    uVar3 = _splimp();
    *(undefined4 *)(unaff_EBP + -4) = uVar3;
    unaff_EBX = piVar2;
    if (*(short *)((int)piVar2 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_mfree_001db397);
    }
  }
  return;
}

