/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114461 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00114461(void)

{
  short sVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_EDI;
  
  while( true ) {
    *(short *)(&DAT_001e917c + *(short *)((int)unaff_EBX + 10) * 2) =
         *(short *)(&DAT_001e917c + *(short *)((int)unaff_EBX + 10) * 2) + -1;
    _DAT_001e917c = _DAT_001e917c + 1;
    *(undefined2 *)((int)unaff_EBX + 10) = 0;
    if (0x7f < (uint)unaff_EBX[1]) {
      _mclput();
    }
    piVar3 = (int *)*unaff_EBX;
    *unaff_EBX = (int)_mfree;
    unaff_EBX[1] = 0;
    unaff_EBX[0x1f] = 0;
    _mfree = unaff_EBX;
    _splx();
    if (_m_want != 0) {
      _m_want = 0;
      _wakeup();
    }
    if (piVar3 == (int *)0x0) {
      return;
    }
    uVar2 = unaff_EDI[1];
    if (0x7b < uVar2) break;
    iVar4 = unaff_EDI[2];
    sVar1 = *(short *)(piVar3 + 2);
    *(int *)(unaff_EBP + -8) = (int)sVar1;
    if (0x7c < (int)(short)iVar4 + uVar2 + (int)sVar1) break;
    _bcopy((void *)((int)piVar3 + piVar3[1]),(void *)((int)unaff_EDI + (int)(short)iVar4 + uVar2),
           *(size_t *)(unaff_EBP + -8));
    *(short *)(unaff_EDI + 2) = (short)unaff_EDI[2] + *(short *)(piVar3 + 2);
    uVar5 = _splimp();
    *(undefined4 *)(unaff_EBP + -4) = uVar5;
    unaff_EBX = piVar3;
    if (*(short *)((int)piVar3 + 10) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_mfree_001db1dd);
    }
  }
  *unaff_EDI = (int)piVar3;
  return;
}

