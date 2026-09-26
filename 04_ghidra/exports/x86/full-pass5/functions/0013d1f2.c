/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013d1f2 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0013d1f2(void)

{
  int *piVar1;
  short *psVar2;
  byte *pbVar3;
  char cVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  uint uStack00000008;
  int iStack0000000c;
  int iStack00000010;
  
  do {
    *(int *)(unaff_EBP + -0x80) = 1 << ((byte)*(undefined4 *)(unaff_EBP + -0x50) & 0x1f);
    pbVar3 = (byte *)(*(int *)(unaff_EBP + -0xc) + 0x3d8 + unaff_EDI);
    *pbVar3 = *pbVar3 | *(byte *)(unaff_EBP + -0x80);
    *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
    if (*(int *)(unaff_EBP + -0x18) <= *(int *)(unaff_EBP + -0x20)) {
      iVar8 = *(int *)(unaff_EBP + -0x20);
      piVar1 = (int *)(*(int *)(unaff_EBP + -0xc) + 0x24);
      *piVar1 = *piVar1 + iVar8;
      *(int *)(unaff_ESI + 0xcc) = *(int *)(unaff_ESI + 0xcc) + iVar8;
      uVar6 = *(uint *)(unaff_ESI + 0x6c);
      iVar8 = *(int *)(unaff_ESI + 0x2d8 +
                      (*(int *)(unaff_EBP + -0x14) >>
                      ((byte)*(undefined4 *)(unaff_ESI + 0x70) & 0x1f)) * 4);
      *(int *)(unaff_EBP + -0x80) = iVar8;
      iVar7 = (*(uint *)(unaff_EBP + -0x14) & ~uVar6) * 0x10;
      *(int *)(unaff_EBP + -0x5c) = iVar7;
      piVar1 = (int *)(iVar8 + 0xc + iVar7);
      *piVar1 = *piVar1 + *(int *)(unaff_EBP + -0x20);
      iVar8 = *(int *)(unaff_EBP + -0x1c);
      if (iVar8 < 0) {
        iVar8 = iVar8 + 7;
      }
      iVar8 = iVar8 >> 3;
      *(int *)(unaff_EBP + -0x80) = iVar8;
      *(uint *)(unaff_EBP + -0x60) = (uint)*(byte *)(iVar8 + 0x3d8 + *(int *)(unaff_EBP + -0xc));
      uVar5 = *(undefined4 *)(unaff_ESI + 0x38);
      *(undefined4 *)(unaff_EBP + -0x80) = 0xff;
      *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) >> (8U - (char)uVar5 & 0x1f);
      uStack00000008 =
           *(int *)(unaff_EBP + -0x60) >>
           ((char)*(undefined4 *)(unaff_EBP + -0x1c) + (char)iVar8 * -8 & 0x1fU) &
           *(uint *)(unaff_EBP + -0x80);
      iStack00000010 = 1;
      iStack0000000c = *(int *)(unaff_EBP + -0xc) + 0x34;
      _fragacct();
      iVar8 = _isblock();
      if (iVar8 != 0) {
        piVar1 = (int *)(*(int *)(unaff_EBP + -0xc) + 0x24);
        *piVar1 = *piVar1 - *(int *)(unaff_ESI + 0x38);
        *(int *)(unaff_ESI + 0xcc) = *(int *)(unaff_ESI + 0xcc) - *(int *)(unaff_ESI + 0x38);
        uVar6 = *(uint *)(unaff_ESI + 0x6c);
        iVar8 = *(int *)(unaff_ESI + 0x2d8 +
                        (*(int *)(unaff_EBP + -0x14) >>
                        ((byte)*(undefined4 *)(unaff_ESI + 0x70) & 0x1f)) * 4);
        *(int *)(unaff_EBP + -0x6c) = iVar8;
        iVar7 = (~uVar6 & *(uint *)(unaff_EBP + -0x14)) * 0x10;
        *(int *)(unaff_EBP + -0x80) = iVar7;
        piVar1 = (int *)(iVar8 + 0xc + iVar7);
        *piVar1 = *piVar1 - *(int *)(unaff_ESI + 0x38);
        piVar1 = (int *)(*(int *)(unaff_EBP + -0xc) + 0x1c);
        *piVar1 = *piVar1 + 1;
        *(int *)(unaff_ESI + 0xc4) = *(int *)(unaff_ESI + 0xc4) + 1;
        uVar6 = *(uint *)(unaff_ESI + 0x6c);
        iVar8 = *(int *)(unaff_ESI + 0x2d8 +
                        (*(int *)(unaff_EBP + -0x14) >>
                        ((byte)*(undefined4 *)(unaff_ESI + 0x70) & 0x1f)) * 4);
        *(int *)(unaff_EBP + -0x74) = iVar8;
        iVar7 = (~uVar6 & *(uint *)(unaff_EBP + -0x14)) * 0x10;
        *(int *)(unaff_EBP + -0x80) = iVar7;
        piVar1 = (int *)(iVar8 + 4 + iVar7);
        *piVar1 = *piVar1 + 1;
        iVar9 = *(int *)(unaff_EBP + -0x1c) * *(int *)(unaff_ESI + 0x7c);
        iVar7 = *(int *)(unaff_ESI + 0xac);
        iVar8 = iVar9 / iVar7;
        *(int *)(unaff_EBP + -0x20) = iVar8;
        iVar8 = *(int *)(unaff_EBP + -0xc) + 0xd4 + iVar8 * 0x10;
        *(int *)(unaff_EBP + -0x7c) = iVar8;
        psVar2 = (short *)(iVar8 + ((((iVar9 % iVar7) % *(int *)(unaff_ESI + 0xa8)) * 8) /
                                   *(int *)(unaff_ESI + 0xa8)) * 2);
        *psVar2 = *psVar2 + 1;
        piVar1 = (int *)(*(int *)(unaff_EBP + -0xc) + 0x54 + *(int *)(unaff_EBP + -0x20) * 4);
        *piVar1 = *piVar1 + 1;
      }
      *(char *)(unaff_ESI + 0xd0) = *(char *)(unaff_ESI + 0xd0) + '\x01';
      iStack00000010 = *(undefined4 *)(unaff_EBP + -0xc);
      iStack0000000c = 0x13d3a2;
      _byte_swap_cylgroup();
      iStack0000000c = *(undefined4 *)(unaff_EBP + -0x10);
      uStack00000008 = 0x13d3ab;
      _bdwrite();
      if (((*(byte *)(unaff_ESI + 0xd3) & 1) != 0) &&
         (*(int *)(unaff_ESI + 0x88) <
          (*(int *)(unaff_ESI + 0xc4) << ((byte)*(undefined4 *)(unaff_ESI + 0x60) & 0x1f)) +
          *(int *)(unaff_ESI + 0xcc))) {
        iStack00000010 = unaff_ESI + 0xcc;
        iStack0000000c = 0x13d3dc;
        _wakeup();
        *(byte *)(unaff_ESI + 0xd3) = *(byte *)(unaff_ESI + 0xd3) & 0xfe;
      }
      return;
    }
    iStack0000000c = *(int *)(unaff_EBP + 0xc) + *(int *)(unaff_EBP + -0x20);
    iVar8 = iStack0000000c;
    if (iStack0000000c < 0) {
      iVar8 = iStack0000000c + 7;
    }
    unaff_EDI = iVar8 >> 3;
    cVar4 = *(char *)(*(int *)(unaff_EBP + -0xc) + 0x3d8 + unaff_EDI);
    uVar6 = iStack0000000c + unaff_EDI * -8;
    *(uint *)(unaff_EBP + -0x50) = uVar6;
  } while (((uint)(int)cVar4 >> (uVar6 & 0x1f) & 1) == 0);
  iStack00000010 = unaff_ESI + 0xd4;
  uStack00000008 = (uint)*(short *)(*(int *)(unaff_EBP + 8) + 0x46);
  _printf(s_dev___0x_x__block____d__fs____s_001ddce9);
                    /* WARNING: Subroutine does not return */
  _panic(s_free_block__freeing_free_frag_001ddd0a);
}

