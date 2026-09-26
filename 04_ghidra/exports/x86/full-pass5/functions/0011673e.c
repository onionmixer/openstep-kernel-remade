/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011673e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0011673e(void)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *unaff_EBX;
  int unaff_EBP;
  short *unaff_ESI;
  
  *(undefined2 *)((int)unaff_EBX + 10) = 8;
  _DAT_001e917c = _DAT_001e917c + -1;
  _DAT_001e918c = _DAT_001e918c + 1;
  _mfree = *unaff_EBX;
  *unaff_EBX = 0;
  unaff_EBX[1] = 0xc;
  _splx();
  if (unaff_EBX == (int *)0x0) {
    uVar3 = 0;
  }
  else {
    iVar4 = unaff_EBX[1];
    *(undefined4 *)(iVar4 + (int)unaff_EBX) = **(undefined4 **)(unaff_EBP + 0xc);
    *(undefined4 *)(iVar4 + 4 + (int)unaff_EBX) = *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 4);
    *(undefined4 *)(iVar4 + 8 + (int)unaff_EBX) = *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 8);
    *(undefined4 *)(iVar4 + 0xc + (int)unaff_EBX) = *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0xc)
    ;
    *(undefined2 *)(unaff_EBX + 2) = 0x10;
    if ((*(int *)(unaff_EBP + 0x14) != 0) && (*(short *)(*(int *)(unaff_EBP + 0x14) + 8) != 0)) {
      iVar4 = _m_copy(*(int *)(unaff_EBP + 0x14),0);
      *unaff_EBX = iVar4;
      if (iVar4 == 0) {
        _m_freem();
        return 0;
      }
      *unaff_ESI = *unaff_ESI + *(short *)(iVar4 + 8);
      sVar1 = unaff_ESI[2];
      unaff_ESI[2] = sVar1 + 0x80;
      if (0x7c < *(uint *)(*unaff_EBX + 4)) {
        unaff_ESI[2] = sVar1 + 0x480;
      }
    }
    *unaff_ESI = *unaff_ESI + (short)unaff_EBX[2];
    sVar1 = unaff_ESI[2];
    unaff_ESI[2] = sVar1 + 0x80;
    if (0x7c < (uint)unaff_EBX[1]) {
      unaff_ESI[2] = sVar1 + 0x480;
    }
    iVar4 = *(int *)(unaff_ESI + 6);
    if (iVar4 == 0) {
      *(int **)(unaff_ESI + 6) = unaff_EBX;
    }
    else {
      iVar2 = *(int *)(iVar4 + 0x7c);
      while (iVar2 != 0) {
        iVar4 = *(int *)(iVar4 + 0x7c);
        iVar2 = *(int *)(iVar4 + 0x7c);
      }
      *(int **)(iVar4 + 0x7c) = unaff_EBX;
    }
    if (*(int *)(unaff_EBP + 0x10) != 0) {
      _sbcompress();
    }
    uVar3 = 1;
  }
  return uVar3;
}

