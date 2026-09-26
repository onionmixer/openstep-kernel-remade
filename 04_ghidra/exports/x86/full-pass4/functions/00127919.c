/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00127919 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00127919(void)

{
  short *psVar1;
  int iVar2;
  int *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  void *unaff_EDI;
  
  *(undefined2 *)((int)unaff_EBX + 10) = 2;
  _DAT_001e917c = _DAT_001e917c + -1;
  _DAT_001e9180 = _DAT_001e9180 + 1;
  _mfree = *unaff_EBX;
  *unaff_EBX = 0;
  unaff_EBX[1] = 0xc;
  _splx();
  if (unaff_EBX != (int *)0x0) {
    *(short *)(unaff_ESI + 8) = *(short *)(unaff_ESI + 8) + -0x14;
    *(int *)(unaff_ESI + 4) = *(int *)(unaff_ESI + 4) + 0x14;
    *unaff_EBX = unaff_ESI;
    unaff_EBX[1] = 0x68 - *(int *)(unaff_EBP + -8);
    *(short *)(unaff_EBX + 2) = *(short *)(unaff_EBP + -8) + 0x14;
    _bcopy(unaff_EDI,(void *)((int)unaff_EBX + unaff_EBX[1]),0x14);
    iVar2 = unaff_EBX[1];
    _bcopy((void *)(*(int *)(unaff_EBP + -4) + 4),(void *)((int)unaff_EBX + iVar2 + 0x14),
           *(size_t *)(unaff_EBP + -8));
    **(int **)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + -8) + 0x14;
    psVar1 = (short *)((int)unaff_EBX + iVar2 + 2);
    *psVar1 = *psVar1 + *(short *)(unaff_EBP + -8);
  }
  return;
}

