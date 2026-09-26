/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013cf36 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0013cf36(void)

{
  int *piVar1;
  short *psVar2;
  byte *pbVar3;
  char cVar4;
  undefined4 uVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int unaff_EBP;
  int unaff_ESI;
  uint unaff_EDI;
  byte *pbStack00000014;
  
  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + 0xc) / *(int *)(unaff_ESI + 0xbc);
  pbStack00000014 = *(byte **)(unaff_EBP + 0xc);
  iVar7 = _badblock();
  if (iVar7 == 0) {
    pbStack00000014 = *(byte **)(unaff_ESI + 0xa0);
    pbStack00000014 = (byte *)_bread();
    *(byte **)(unaff_EBP + -0x10) = pbStack00000014;
    *(undefined4 *)(unaff_EBP + -0xc) = *(undefined4 *)(pbStack00000014 + 0x20);
    if ((*pbStack00000014 & 4) == 0) {
      pbStack00000014 = *(byte **)(unaff_EBP + -0xc);
      _byte_swap_cylgroup();
      pbStack00000014 = *(byte **)(unaff_EBP + -0xc);
      if (*(int *)((int)pbStack00000014 + 0x3d4) == 0x90255) {
        bVar6 = true;
      }
      else {
        _byte_swap_cylgroup();
        _brelse();
        bVar6 = false;
      }
    }
    else {
      _brelse();
      bVar6 = false;
    }
    if (bVar6) {
      pbStack00000014 = (byte *)(unaff_EBP + -8);
      _getthetime();
      *(undefined4 *)(*(int *)(unaff_EBP + -0xc) + 8) = *(undefined4 *)(unaff_EBP + -8);
      iVar7 = *(int *)(unaff_EBP + 0xc) % *(int *)(unaff_ESI + 0xbc);
      *(int *)(unaff_EBP + 0xc) = iVar7;
      if (*(uint *)(unaff_ESI + 0x30) == unaff_EDI) {
        pbStack00000014 = (byte *)(iVar7 >> ((byte)*(undefined4 *)(unaff_ESI + 0x60) & 0x1f));
        iVar7 = _isblock();
        if (iVar7 != 0) {
          pbStack00000014 = (byte *)(unaff_ESI + 0xd4);
          _printf(s_dev___0x_x__block____d__fs____s_001ddca9);
                    /* WARNING: Subroutine does not return */
          _panic(s_free_block__freeing_free_block_001ddcca);
        }
        pbStack00000014 =
             (byte *)(*(int *)(unaff_EBP + 0xc) >> ((byte)*(undefined4 *)(unaff_ESI + 0x60) & 0x1f))
        ;
        _setblock();
        piVar1 = (int *)(*(int *)(unaff_EBP + -0xc) + 0x1c);
        *piVar1 = *piVar1 + 1;
        *(int *)(unaff_ESI + 0xc4) = *(int *)(unaff_ESI + 0xc4) + 1;
        uVar9 = *(uint *)(unaff_ESI + 0x6c);
        iVar7 = *(int *)(unaff_ESI + 0x2d8 +
                        (*(int *)(unaff_EBP + -0x14) >>
                        ((byte)*(undefined4 *)(unaff_ESI + 0x70) & 0x1f)) * 4);
        *(int *)(unaff_EBP + -0x38) = iVar7;
        iVar8 = (~uVar9 & *(uint *)(unaff_EBP + -0x14)) * 0x10;
        *(int *)(unaff_EBP + -0x80) = iVar8;
        piVar1 = (int *)(iVar7 + 4 + iVar8);
        *piVar1 = *piVar1 + 1;
        iVar10 = *(int *)(unaff_EBP + 0xc) * *(int *)(unaff_ESI + 0x7c);
        iVar8 = *(int *)(unaff_ESI + 0xac);
        iVar7 = iVar10 / iVar8;
        *(int *)(unaff_EBP + -0x20) = iVar7;
        iVar7 = *(int *)(unaff_EBP + -0xc) + 0xd4 + iVar7 * 0x10;
        *(int *)(unaff_EBP + -0x40) = iVar7;
        psVar2 = (short *)(iVar7 + (((iVar10 % iVar8) % *(int *)(unaff_ESI + 0xa8) << 3) /
                                   *(int *)(unaff_ESI + 0xa8)) * 2);
        *psVar2 = *psVar2 + 1;
        piVar1 = (int *)(*(int *)(unaff_EBP + -0xc) + 0x54 + *(int *)(unaff_EBP + -0x20) * 4);
        *piVar1 = *piVar1 + 1;
      }
      else {
        iVar7 = *(int *)(unaff_ESI + 0x38);
        uVar9 = -iVar7 & *(uint *)(unaff_EBP + 0xc);
        *(uint *)(unaff_EBP + -0x1c) = uVar9;
        *(uint *)(unaff_EBP + -0x84) = uVar9;
        if ((int)uVar9 < 0) {
          *(uint *)(unaff_EBP + -0x84) = uVar9 + 7;
        }
        iVar8 = *(int *)(unaff_EBP + -0x84) >> 3;
        *(int *)(unaff_EBP + -0x48) =
             (int)(uint)*(byte *)(iVar8 + 0x3d8 + *(int *)(unaff_EBP + -0xc)) >>
             ((char)*(undefined4 *)(unaff_EBP + -0x1c) + (char)iVar8 * -8 & 0x1fU);
        *(undefined4 *)(unaff_EBP + -0x80) = 0xff;
        *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) >> (8U - (char)iVar7 & 0x1f);
        pbStack00000014 = (byte *)0xffffffff;
        _fragacct();
        uVar9 = unaff_EDI >> ((byte)*(undefined4 *)(unaff_ESI + 0x54) & 0x1f);
        *(uint *)(unaff_EBP + -0x18) = uVar9;
        *(undefined4 *)(unaff_EBP + -0x20) = 0;
        if (*(int *)(unaff_EBP + -0x20) < (int)uVar9) {
          do {
            iVar8 = *(int *)(unaff_EBP + 0xc) + *(int *)(unaff_EBP + -0x20);
            iVar7 = iVar8;
            if (iVar8 < 0) {
              iVar7 = iVar8 + 7;
            }
            iVar7 = iVar7 >> 3;
            cVar4 = *(char *)(*(int *)(unaff_EBP + -0xc) + 0x3d8 + iVar7);
            uVar9 = iVar8 + iVar7 * -8;
            *(uint *)(unaff_EBP + -0x50) = uVar9;
            if (((uint)(int)cVar4 >> (uVar9 & 0x1f) & 1) != 0) {
              pbStack00000014 = (byte *)(unaff_ESI + 0xd4);
              _printf(s_dev___0x_x__block____d__fs____s_001ddce9);
                    /* WARNING: Subroutine does not return */
              _panic(s_free_block__freeing_free_frag_001ddd0a);
            }
            *(int *)(unaff_EBP + -0x80) = 1 << ((byte)*(undefined4 *)(unaff_EBP + -0x50) & 0x1f);
            pbVar3 = (byte *)(*(int *)(unaff_EBP + -0xc) + 0x3d8 + iVar7);
            *pbVar3 = *pbVar3 | *(byte *)(unaff_EBP + -0x80);
            *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
          } while (*(int *)(unaff_EBP + -0x20) < *(int *)(unaff_EBP + -0x18));
        }
        iVar7 = *(int *)(unaff_EBP + -0x20);
        piVar1 = (int *)(*(int *)(unaff_EBP + -0xc) + 0x24);
        *piVar1 = *piVar1 + iVar7;
        *(int *)(unaff_ESI + 0xcc) = *(int *)(unaff_ESI + 0xcc) + iVar7;
        uVar9 = *(uint *)(unaff_ESI + 0x6c);
        iVar7 = *(int *)(unaff_ESI + 0x2d8 +
                        (*(int *)(unaff_EBP + -0x14) >>
                        ((byte)*(undefined4 *)(unaff_ESI + 0x70) & 0x1f)) * 4);
        *(int *)(unaff_EBP + -0x80) = iVar7;
        iVar8 = (*(uint *)(unaff_EBP + -0x14) & ~uVar9) * 0x10;
        *(int *)(unaff_EBP + -0x5c) = iVar8;
        piVar1 = (int *)(iVar7 + 0xc + iVar8);
        *piVar1 = *piVar1 + *(int *)(unaff_EBP + -0x20);
        iVar7 = *(int *)(unaff_EBP + -0x1c);
        if (iVar7 < 0) {
          iVar7 = iVar7 + 7;
        }
        *(int *)(unaff_EBP + -0x80) = iVar7 >> 3;
        *(uint *)(unaff_EBP + -0x60) =
             (uint)*(byte *)((iVar7 >> 3) + 0x3d8 + *(int *)(unaff_EBP + -0xc));
        uVar5 = *(undefined4 *)(unaff_ESI + 0x38);
        *(undefined4 *)(unaff_EBP + -0x80) = 0xff;
        *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) >> (8U - (char)uVar5 & 0x1f);
        pbStack00000014 = (byte *)0x1;
        _fragacct();
        iVar7 = _isblock();
        if (iVar7 != 0) {
          piVar1 = (int *)(*(int *)(unaff_EBP + -0xc) + 0x24);
          *piVar1 = *piVar1 - *(int *)(unaff_ESI + 0x38);
          *(int *)(unaff_ESI + 0xcc) = *(int *)(unaff_ESI + 0xcc) - *(int *)(unaff_ESI + 0x38);
          uVar9 = *(uint *)(unaff_ESI + 0x6c);
          iVar7 = *(int *)(unaff_ESI + 0x2d8 +
                          (*(int *)(unaff_EBP + -0x14) >>
                          ((byte)*(undefined4 *)(unaff_ESI + 0x70) & 0x1f)) * 4);
          *(int *)(unaff_EBP + -0x6c) = iVar7;
          iVar8 = (~uVar9 & *(uint *)(unaff_EBP + -0x14)) * 0x10;
          *(int *)(unaff_EBP + -0x80) = iVar8;
          piVar1 = (int *)(iVar7 + 0xc + iVar8);
          *piVar1 = *piVar1 - *(int *)(unaff_ESI + 0x38);
          piVar1 = (int *)(*(int *)(unaff_EBP + -0xc) + 0x1c);
          *piVar1 = *piVar1 + 1;
          *(int *)(unaff_ESI + 0xc4) = *(int *)(unaff_ESI + 0xc4) + 1;
          uVar9 = *(uint *)(unaff_ESI + 0x6c);
          iVar7 = *(int *)(unaff_ESI + 0x2d8 +
                          (*(int *)(unaff_EBP + -0x14) >>
                          ((byte)*(undefined4 *)(unaff_ESI + 0x70) & 0x1f)) * 4);
          *(int *)(unaff_EBP + -0x74) = iVar7;
          iVar8 = (~uVar9 & *(uint *)(unaff_EBP + -0x14)) * 0x10;
          *(int *)(unaff_EBP + -0x80) = iVar8;
          piVar1 = (int *)(iVar7 + 4 + iVar8);
          *piVar1 = *piVar1 + 1;
          iVar10 = *(int *)(unaff_EBP + -0x1c) * *(int *)(unaff_ESI + 0x7c);
          iVar8 = *(int *)(unaff_ESI + 0xac);
          iVar7 = iVar10 / iVar8;
          *(int *)(unaff_EBP + -0x20) = iVar7;
          iVar7 = *(int *)(unaff_EBP + -0xc) + 0xd4 + iVar7 * 0x10;
          *(int *)(unaff_EBP + -0x7c) = iVar7;
          psVar2 = (short *)(iVar7 + ((((iVar10 % iVar8) % *(int *)(unaff_ESI + 0xa8)) * 8) /
                                     *(int *)(unaff_ESI + 0xa8)) * 2);
          *psVar2 = *psVar2 + 1;
          piVar1 = (int *)(*(int *)(unaff_EBP + -0xc) + 0x54 + *(int *)(unaff_EBP + -0x20) * 4);
          *piVar1 = *piVar1 + 1;
        }
      }
      *(char *)(unaff_ESI + 0xd0) = *(char *)(unaff_ESI + 0xd0) + '\x01';
      pbStack00000014 = *(byte **)(unaff_EBP + -0xc);
      _byte_swap_cylgroup();
      _bdwrite();
      if (((*(byte *)(unaff_ESI + 0xd3) & 1) != 0) &&
         (*(int *)(unaff_ESI + 0x88) <
          (*(int *)(unaff_ESI + 0xc4) << ((byte)*(undefined4 *)(unaff_ESI + 0x60) & 0x1f)) +
          *(int *)(unaff_ESI + 0xcc))) {
        pbStack00000014 = (byte *)(unaff_ESI + 0xcc);
        _wakeup();
        *(byte *)(unaff_ESI + 0xd3) = *(byte *)(unaff_ESI + 0xd3) & 0xfe;
      }
    }
  }
  else {
    pbStack00000014 = *(byte **)(*(int *)(unaff_EBP + 8) + 0x48);
    _printf(s_bad_block__d__ino__d_001ddc93);
  }
  return;
}

