/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001141e6 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001141e6(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  while ((short)unaff_ESI[2] <= unaff_EDI) {
    unaff_EDI = unaff_EDI - (short)unaff_ESI[2];
    unaff_ESI = (int *)*unaff_ESI;
    if (unaff_EDI < 1) break;
    if (unaff_ESI == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_m_copy_001db1fc);
    }
  }
  *(int *)(unaff_EBP + -8) = unaff_EBP + -4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar5 = *(int *)(unaff_EBP + 0x10);
  do {
    if (iVar5 < 1) {
LAB_00114318:
      return *(undefined4 *)(unaff_EBP + -4);
    }
    if (unaff_ESI == (int *)0x0) {
      if (*(int *)(unaff_EBP + 0x10) != 1000000000) {
                    /* WARNING: Subroutine does not return */
        _panic(s_m_copy_001db203);
      }
      goto LAB_00114318;
    }
    uVar2 = _splimp();
    *(undefined4 *)(unaff_EBP + -0xc) = uVar2;
    puVar3 = _mfree;
    if (_mfree == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)_m_more(0);
    }
    else {
      if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&DAT_001db20a);
      }
      *(undefined2 *)((int)_mfree + 10) = *(undefined2 *)((int)unaff_ESI + 10);
      _DAT_001e917c = _DAT_001e917c + -1;
      *(short *)(&DAT_001e917c + *(short *)((int)unaff_ESI + 10) * 2) =
           *(short *)(&DAT_001e917c + *(short *)((int)unaff_ESI + 10) * 2) + 1;
      puVar1 = (undefined4 *)*_mfree;
      *_mfree = 0;
      _mfree = puVar1;
      puVar3[1] = 0xc;
    }
    _splx();
    **(undefined4 **)(unaff_EBP + -8) = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = *(undefined4 **)(unaff_EBP + -4);
      if (puVar3 != (undefined4 *)0x0) {
        uVar2 = _splimp();
        *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
        do {
          _splimp();
          if (*(short *)((int)puVar3 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_mfree_001db1ef);
          }
          *(short *)(&DAT_001e917c + *(short *)((int)puVar3 + 10) * 2) =
               *(short *)(&DAT_001e917c + *(short *)((int)puVar3 + 10) * 2) + -1;
          _DAT_001e917c = _DAT_001e917c + 1;
          *(undefined2 *)((int)puVar3 + 10) = 0;
          if (0x7f < (uint)puVar3[1]) {
            _mclput();
          }
          puVar1 = (undefined4 *)*puVar3;
          *puVar3 = _mfree;
          puVar3[1] = 0;
          puVar3[0x1f] = 0;
          _mfree = puVar3;
          _splx();
          if (_m_want != 0) {
            _m_want = 0;
            _wakeup();
          }
          puVar3 = puVar1;
        } while (puVar1 != (undefined4 *)0x0);
        _splx();
      }
      return 0;
    }
    iVar4 = (short)unaff_ESI[2] - unaff_EDI;
    iVar5 = *(int *)(unaff_EBP + 0x10);
    if (iVar4 < *(int *)(unaff_EBP + 0x10)) {
      iVar5 = iVar4;
    }
    *(short *)(puVar3 + 2) = (short)iVar5;
    if (((uint)unaff_ESI[1] < 0x7d) || ((short)iVar5 < 0x71)) {
      _bcopy((void *)((int)unaff_ESI + unaff_EDI + unaff_ESI[1]),(void *)((int)puVar3 + puVar3[1]),
             (int)*(short *)(puVar3 + 2));
    }
    else {
      _mcldup(unaff_ESI,puVar3);
      puVar3[1] = puVar3[1] + unaff_EDI;
    }
    if (*(int *)(unaff_EBP + 0x10) != 1000000000) {
      *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) - (int)*(short *)(puVar3 + 2);
    }
    unaff_EDI = 0;
    unaff_ESI = (int *)*unaff_ESI;
    *(undefined4 **)(unaff_EBP + -8) = puVar3;
    iVar5 = *(int *)(unaff_EBP + 0x10);
  } while( true );
}

