/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001146e1 */

/* WARNING: Removing unreachable block (ram,0x0011480a) */
/* WARNING: Removing unreachable block (ram,0x00114814) */
/* WARNING: Removing unreachable block (ram,0x00114822) */
/* WARNING: Removing unreachable block (ram,0x0011482f) */
/* WARNING: Removing unreachable block (ram,0x0011484e) */
/* WARNING: Removing unreachable block (ram,0x00114857) */
/* WARNING: Removing unreachable block (ram,0x00114887) */
/* WARNING: Removing unreachable block (ram,0x0011489e) */
/* WARNING: Removing unreachable block (ram,0x001148a8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_001146e1(void)

{
  int *piVar1;
  short sVar2;
  size_t sVar3;
  undefined4 uVar4;
  size_t sVar5;
  int unaff_EBP;
  int *unaff_ESI;
  int *unaff_EDI;
  
  do {
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
    while( true ) {
      if (*(int *)(unaff_EBP + 0xc) < 1) {
        *unaff_EDI = (int)piVar1;
        return;
      }
      if (piVar1 == (int *)0x0) {
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
        *unaff_EDI = (int)_mfree;
        unaff_EDI[1] = 0;
        unaff_EDI[0x1f] = 0;
        _mfree = unaff_EDI;
        _splx();
        if (_m_want == 0) {
          return;
        }
        _m_want = 0;
        _wakeup();
        return;
      }
      *(int *)(unaff_EBP + -0x10) = (int)(short)piVar1[2];
      sVar3 = *(int *)(unaff_EBP + 0xc) + 0x20;
      sVar5 = *(int *)(unaff_EBP + -4) - (int)(short)unaff_EDI[2];
      if ((int)sVar3 < (int)sVar5) {
        sVar5 = sVar3;
      }
      if (*(int *)(unaff_EBP + -0x10) < (int)sVar5) {
        sVar5 = *(size_t *)(unaff_EBP + -0x10);
      }
      _bcopy((void *)((int)piVar1 + piVar1[1]),
             (void *)((int)unaff_EDI + (int)(short)unaff_EDI[2] + unaff_EDI[1]),sVar5);
      *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) - sVar5;
      *(short *)(unaff_EDI + 2) = (short)unaff_EDI[2] + (short)sVar5;
      sVar2 = (short)piVar1[2] - (short)sVar5;
      *(short *)(piVar1 + 2) = sVar2;
      if (sVar2 == 0) break;
      piVar1[1] = piVar1[1] + sVar5;
    }
    uVar4 = _splimp();
    *(undefined4 *)(unaff_EBP + -8) = uVar4;
    unaff_ESI = piVar1;
    if (*(short *)((int)piVar1 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_mfree_001db1dd);
    }
  } while( true );
}

