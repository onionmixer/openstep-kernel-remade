/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114253 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00114253(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_EBX;
  undefined4 *puVar5;
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
LAB_00114256:
  *(undefined2 *)((int)unaff_EBX + 10) = *(undefined2 *)((int)unaff_ESI + 10);
  _DAT_001e917c = _DAT_001e917c + -1;
  *(short *)(&DAT_001e917c + *(short *)((int)unaff_ESI + 10) * 2) =
       *(short *)(&DAT_001e917c + *(short *)((int)unaff_ESI + 10) * 2) + 1;
  _mfree = (undefined4 *)*unaff_EBX;
  *unaff_EBX = 0;
  unaff_EBX[1] = 0xc;
  do {
    _splx();
    **(undefined4 **)(unaff_EBP + -8) = unaff_EBX;
    if (unaff_EBX == (undefined4 *)0x0) {
      puVar5 = *(undefined4 **)(unaff_EBP + -4);
      if (puVar5 != (undefined4 *)0x0) {
        uVar2 = _splimp();
        *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
        do {
          _splimp();
          if (*(short *)((int)puVar5 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_mfree_001db1ef);
          }
          *(short *)(&DAT_001e917c + *(short *)((int)puVar5 + 10) * 2) =
               *(short *)(&DAT_001e917c + *(short *)((int)puVar5 + 10) * 2) + -1;
          _DAT_001e917c = _DAT_001e917c + 1;
          *(undefined2 *)((int)puVar5 + 10) = 0;
          if (0x7f < (uint)puVar5[1]) {
            _mclput();
          }
          puVar1 = (undefined4 *)*puVar5;
          *puVar5 = _mfree;
          puVar5[1] = 0;
          puVar5[0x1f] = 0;
          _mfree = puVar5;
          _splx();
          if (_m_want != 0) {
            _m_want = 0;
            _wakeup();
          }
          puVar5 = puVar1;
        } while (puVar1 != (undefined4 *)0x0);
        _splx();
      }
      return 0;
    }
    iVar3 = (short)unaff_ESI[2] - unaff_EDI;
    iVar4 = *(int *)(unaff_EBP + 0x10);
    if (iVar3 < *(int *)(unaff_EBP + 0x10)) {
      iVar4 = iVar3;
    }
    *(short *)(unaff_EBX + 2) = (short)iVar4;
    if (((uint)unaff_ESI[1] < 0x7d) || ((short)iVar4 < 0x71)) {
      _bcopy((void *)((int)unaff_ESI + unaff_EDI + unaff_ESI[1]),
             (void *)((int)unaff_EBX + unaff_EBX[1]),(int)*(short *)(unaff_EBX + 2));
    }
    else {
      _mcldup(unaff_ESI,unaff_EBX);
      unaff_EBX[1] = unaff_EBX[1] + unaff_EDI;
    }
    if (*(int *)(unaff_EBP + 0x10) != 1000000000) {
      *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + 0x10) - (int)*(short *)(unaff_EBX + 2);
    }
    unaff_EDI = 0;
    unaff_ESI = (int *)*unaff_ESI;
    *(undefined4 **)(unaff_EBP + -8) = unaff_EBX;
    if (*(int *)(unaff_EBP + 0x10) < 1) {
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
    if (_mfree != (undefined4 *)0x0) break;
    unaff_EBX = (undefined4 *)_m_more(0);
  } while( true );
  unaff_EBX = _mfree;
  if (*(short *)((int)_mfree + 10) != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(&DAT_001db20a);
  }
  goto LAB_00114256;
}

