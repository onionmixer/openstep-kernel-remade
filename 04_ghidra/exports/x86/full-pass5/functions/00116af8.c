/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00116af8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00116af8(void)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int unaff_EBP;
  short *unaff_EDI;
  
  do {
    puVar4 = *(undefined4 **)(unaff_EBP + -4);
    *(undefined4 *)(unaff_EBP + -4) = puVar4[0x1f];
    while( true ) {
      if (*(int *)(unaff_EBP + 0xc) < 1) goto LAB_00116c83;
      if (puVar4 == (undefined4 *)0x0) break;
      sVar1 = *(short *)(puVar4 + 2);
      if (*(int *)(unaff_EBP + 0xc) < (int)sVar1) {
        *(short *)(puVar4 + 2) = sVar1 - *(short *)(unaff_EBP + 0xc);
        puVar4[1] = puVar4[1] + *(int *)(unaff_EBP + 0xc);
        *unaff_EDI = *unaff_EDI - *(short *)(unaff_EBP + 0xc);
        goto LAB_00116c83;
      }
      *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) - (int)sVar1;
      *unaff_EDI = *unaff_EDI - sVar1;
      sVar1 = unaff_EDI[2];
      unaff_EDI[2] = sVar1 + -0x80;
      if (0x7c < (uint)puVar4[1]) {
        unaff_EDI[2] = sVar1 + -0x480;
      }
      uVar3 = _splimp();
      *(undefined4 *)(unaff_EBP + -8) = uVar3;
      if (*(short *)((int)puVar4 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_mfree_001db38b);
      }
      *(short *)(&DAT_001e917c + *(short *)((int)puVar4 + 10) * 2) =
           *(short *)(&DAT_001e917c + *(short *)((int)puVar4 + 10) * 2) + -1;
      _DAT_001e917c = _DAT_001e917c + 1;
      *(undefined2 *)((int)puVar4 + 10) = 0;
      if (0x7f < (uint)puVar4[1]) {
        _mclput();
      }
      puVar2 = (undefined4 *)*puVar4;
      *puVar4 = _mfree;
      puVar4[1] = 0;
      puVar4[0x1f] = 0;
      _mfree = puVar4;
      _splx();
      puVar4 = puVar2;
      if (_m_want != 0) {
        _m_want = 0;
        _wakeup();
      }
    }
    if (*(int *)(unaff_EBP + -4) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_sbdrop_001db384);
    }
  } while( true );
LAB_00116c83:
  if (puVar4 == (undefined4 *)0x0) {
LAB_00116cbc:
    *(undefined4 *)(unaff_EDI + 6) = *(undefined4 *)(unaff_EBP + -4);
    return;
  }
  if (*(short *)(puVar4 + 2) != 0) {
    if (puVar4 != (undefined4 *)0x0) {
      *(undefined4 **)(unaff_EDI + 6) = puVar4;
      puVar4[0x1f] = *(undefined4 *)(unaff_EBP + -4);
      return;
    }
    goto LAB_00116cbc;
  }
  *unaff_EDI = *unaff_EDI;
  sVar1 = unaff_EDI[2];
  unaff_EDI[2] = sVar1 + -0x80;
  if (0x7c < (uint)puVar4[1]) {
    unaff_EDI[2] = sVar1 + -0x480;
  }
  uVar3 = _splimp();
  *(undefined4 *)(unaff_EBP + -0xc) = uVar3;
  if (*(short *)((int)puVar4 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_mfree_001db391);
  }
  *(short *)(&DAT_001e917c + *(short *)((int)puVar4 + 10) * 2) =
       *(short *)(&DAT_001e917c + *(short *)((int)puVar4 + 10) * 2) + -1;
  _DAT_001e917c = _DAT_001e917c + 1;
  *(undefined2 *)((int)puVar4 + 10) = 0;
  if (0x7f < (uint)puVar4[1]) {
    _mclput();
  }
  puVar2 = (undefined4 *)*puVar4;
  *puVar4 = _mfree;
  puVar4[1] = 0;
  puVar4[0x1f] = 0;
  _mfree = puVar4;
  _splx();
  puVar4 = puVar2;
  if (_m_want != 0) {
    _m_want = 0;
    _wakeup();
  }
  goto LAB_00116c83;
}

