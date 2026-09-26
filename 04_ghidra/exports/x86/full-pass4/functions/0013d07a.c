/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013d07a */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0013d07a(void)

{
  int *piVar1;
  short *psVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_EBP;
  int unaff_ESI;
  undefined4 uStack00000004;
  int iStack00000010;
  
  iStack00000010 = *(int *)(unaff_EBP + 0xc) >> ((byte)*(undefined4 *)(unaff_ESI + 0x60) & 0x1f);
  uStack00000004 = 0x13d08f;
  _setblock();
  piVar1 = (int *)(*(int *)(unaff_EBP + -0xc) + 0x1c);
  *piVar1 = *piVar1 + 1;
  *(int *)(unaff_ESI + 0xc4) = *(int *)(unaff_ESI + 0xc4) + 1;
  uVar3 = *(uint *)(unaff_ESI + 0x6c);
  iVar4 = *(int *)(unaff_ESI + 0x2d8 +
                  (*(int *)(unaff_EBP + -0x14) >> ((byte)*(undefined4 *)(unaff_ESI + 0x70) & 0x1f))
                  * 4);
  *(int *)(unaff_EBP + -0x38) = iVar4;
  iVar5 = (~uVar3 & *(uint *)(unaff_EBP + -0x14)) * 0x10;
  *(int *)(unaff_EBP + -0x80) = iVar5;
  piVar1 = (int *)(iVar4 + 4 + iVar5);
  *piVar1 = *piVar1 + 1;
  iVar6 = *(int *)(unaff_EBP + 0xc) * *(int *)(unaff_ESI + 0x7c);
  iVar5 = *(int *)(unaff_ESI + 0xac);
  iVar4 = iVar6 / iVar5;
  *(int *)(unaff_EBP + -0x20) = iVar4;
  iVar4 = *(int *)(unaff_EBP + -0xc) + 0xd4 + iVar4 * 0x10;
  *(int *)(unaff_EBP + -0x40) = iVar4;
  psVar2 = (short *)(iVar4 + (((iVar6 % iVar5) % *(int *)(unaff_ESI + 0xa8) << 3) /
                             *(int *)(unaff_ESI + 0xa8)) * 2);
  *psVar2 = *psVar2 + 1;
  piVar1 = (int *)(*(int *)(unaff_EBP + -0xc) + 0x54 + *(int *)(unaff_EBP + -0x20) * 4);
  *piVar1 = *piVar1 + 1;
  *(char *)(unaff_ESI + 0xd0) = *(char *)(unaff_ESI + 0xd0) + '\x01';
  iStack00000010 = *(undefined4 *)(unaff_EBP + -0xc);
  _byte_swap_cylgroup();
  _bdwrite();
  if (((*(byte *)(unaff_ESI + 0xd3) & 1) != 0) &&
     (*(int *)(unaff_ESI + 0x88) <
      (*(int *)(unaff_ESI + 0xc4) << ((byte)*(undefined4 *)(unaff_ESI + 0x60) & 0x1f)) +
      *(int *)(unaff_ESI + 0xcc))) {
    iStack00000010 = unaff_ESI + 0xcc;
    _wakeup();
    *(byte *)(unaff_ESI + 0xd3) = *(byte *)(unaff_ESI + 0xd3) & 0xfe;
  }
  return;
}

