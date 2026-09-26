/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013b7b7 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013b7b7(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  int iStack0000000c;
  code *pcStack00000014;
  
  if ((*(int *)(unaff_EBX + 0x30) != *(int *)(unaff_EBP + 0x10)) ||
     (*(int *)(unaff_EBX + 0xc4) != 0)) {
    if (*(short *)(*(int *)(_active_u + 0x1c) + 2) != 0) {
      *(int *)(unaff_EBP + -4) =
           (*(int *)(unaff_EBX + 0xc4) << ((byte)*(undefined4 *)(unaff_EBX + 0x60) & 0x1f)) +
           *(int *)(unaff_EBX + 0xcc);
      *(int *)(unaff_EBP + -0xc) = *(int *)(unaff_EBX + 0x28) * *(int *)(unaff_EBX + 0x3c);
      if (*(int *)(unaff_EBP + -4) - *(int *)(unaff_EBP + -0xc) / 100 < 1) goto LAB_0013b8ac;
    }
    if (*(int *)(unaff_EBX + 0x24) <= unaff_ESI) {
      unaff_ESI = 0;
    }
    if (unaff_ESI == 0) {
      uVar1 = *(uint *)(unaff_EDI + 0x48) / *(uint *)(unaff_EBX + 0xb8);
    }
    else {
      uVar1 = unaff_ESI / *(int *)(unaff_EBX + 0xbc);
    }
    *(uint *)(unaff_EBP + -0xc) = uVar1;
    pcStack00000014 = _alloccg;
    iStack0000000c = unaff_ESI;
    iVar2 = _hashalloc();
    if (0 < iVar2) {
      pcStack00000014 = (code *)(unaff_EDI + 0xc);
      uVar3 = (**(code **)(*(int *)(unaff_EDI + 0x28) + 0x80))();
      *(undefined4 *)(unaff_EBP + -0xc) = uVar3;
      *(int *)(unaff_EDI + 0xcc) =
           *(int *)(unaff_EDI + 0xcc) + *(int *)(unaff_EBP + 0x10) / *(int *)(unaff_EBP + -0xc);
      *(byte *)(unaff_EDI + 0x44) = *(byte *)(unaff_EDI + 0x44) | 0x42;
      iStack0000000c = iVar2 << ((byte)*(undefined4 *)(unaff_EBX + 100) & 0x1f);
      *(int *)(unaff_EBP + -4) = iStack0000000c;
      iVar2 = _getblk();
      _blkclr();
      *(undefined4 *)(iVar2 + 0x28) = 0;
      return iVar2;
    }
  }
LAB_0013b8ac:
  pcStack00000014 = (code *)0x1;
  iStack0000000c = 0x13b8b4;
  _fsfull();
  return 0;
}

