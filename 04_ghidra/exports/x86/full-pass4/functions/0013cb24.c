/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013cb24 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013cb24(void)

{
  int *piVar1;
  short *psVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_EBP;
  int unaff_EDI;
  int iStack0000000c;
  int iStack00000010;
  
  iStack00000010 = *(undefined4 *)(unaff_EDI + 0x38);
  iStack0000000c = *(undefined4 *)(unaff_EBP + 0x10);
  iVar4 = _mapsearch();
  *(int *)(unaff_EBP + -4) = iVar4;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  else {
    *(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 0x28) = *(undefined4 *)(unaff_EBP + -4);
    iStack00000010 = *(int *)(unaff_EBP + -4) >> ((byte)*(undefined4 *)(unaff_EDI + 0x60) & 0x1f);
    iStack0000000c = *(int *)(unaff_EBP + 0xc) + 0x3d8;
    _clrblock();
    iVar4 = *(int *)(unaff_EBP + 0xc);
    piVar1 = (int *)(iVar4 + 0x1c);
    *piVar1 = *piVar1 + -1;
    *(int *)(unaff_EDI + 0xc4) = *(int *)(unaff_EDI + 0xc4) + -1;
    iVar4 = *(int *)(iVar4 + 0xc);
    *(int *)(unaff_EBP + -0x14) = iVar4;
    uVar3 = *(uint *)(unaff_EDI + 0x6c);
    iVar4 = *(int *)(unaff_EDI + 0x2d8 +
                    (iVar4 >> ((byte)*(undefined4 *)(unaff_EDI + 0x70) & 0x1f)) * 4);
    *(int *)(unaff_EBP + -0x10) = iVar4;
    iVar6 = (*(uint *)(unaff_EBP + -0x14) & ~uVar3) * 0x10;
    *(int *)(unaff_EBP + -0xc) = iVar6;
    piVar1 = (int *)(iVar4 + 4 + iVar6);
    *piVar1 = *piVar1 + -1;
    iVar5 = *(int *)(unaff_EBP + -4) * *(int *)(unaff_EDI + 0x7c);
    iVar4 = *(int *)(unaff_EDI + 0xac);
    iVar6 = iVar5 / iVar4;
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + 0xc) + 0xd4 + iVar6 * 0x10;
    psVar2 = (short *)(*(int *)(unaff_EBP + -0x10) +
                      (((iVar5 % iVar4) % *(int *)(unaff_EDI + 0xa8) << 3) /
                      *(int *)(unaff_EDI + 0xa8)) * 2);
    *psVar2 = *psVar2 + -1;
    iVar4 = *(int *)(unaff_EBP + 0xc);
    piVar1 = (int *)(iVar4 + 0x54 + iVar6 * 4);
    *piVar1 = *piVar1 + -1;
    *(char *)(unaff_EDI + 0xd0) = *(char *)(unaff_EDI + 0xd0) + '\x01';
    iVar4 = *(int *)(iVar4 + 0xc) * *(int *)(unaff_EDI + 0xbc) + *(int *)(unaff_EBP + -4);
  }
  return iVar4;
}

