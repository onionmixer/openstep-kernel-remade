/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013cac5 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013cac5(void)

{
  int *piVar1;
  short *psVar2;
  int iVar3;
  uint uVar4;
  int unaff_EBX;
  int iVar5;
  int unaff_EBP;
  int unaff_ESI;
  int iVar6;
  int unaff_EDI;
  int iStack0000000c;
  int iStack00000010;
  
  iVar5 = (int)*(short *)(unaff_ESI + unaff_EBX * 2);
  while( true ) {
    iVar6 = *(int *)(unaff_EBP + -4) + iVar5;
    iStack0000000c = *(int *)(unaff_EBP + 0xc) + 0x3d8;
    iStack00000010 = iVar6;
    iVar3 = _isblock();
    if (iVar3 != 0) {
      *(int *)(unaff_EBP + -4) = iVar6 << ((byte)*(undefined4 *)(unaff_EDI + 0x60) & 0x1f);
      iStack00000010 = *(int *)(unaff_EBP + -4) >> ((byte)*(undefined4 *)(unaff_EDI + 0x60) & 0x1f);
      iStack0000000c = *(int *)(unaff_EBP + 0xc) + 0x3d8;
      _clrblock();
      iVar5 = *(int *)(unaff_EBP + 0xc);
      piVar1 = (int *)(iVar5 + 0x1c);
      *piVar1 = *piVar1 + -1;
      *(int *)(unaff_EDI + 0xc4) = *(int *)(unaff_EDI + 0xc4) + -1;
      iVar5 = *(int *)(iVar5 + 0xc);
      *(int *)(unaff_EBP + -0x14) = iVar5;
      uVar4 = *(uint *)(unaff_EDI + 0x6c);
      iVar5 = *(int *)(unaff_EDI + 0x2d8 +
                      (iVar5 >> ((byte)*(undefined4 *)(unaff_EDI + 0x70) & 0x1f)) * 4);
      *(int *)(unaff_EBP + -0x10) = iVar5;
      iVar3 = (*(uint *)(unaff_EBP + -0x14) & ~uVar4) * 0x10;
      *(int *)(unaff_EBP + -0xc) = iVar3;
      piVar1 = (int *)(iVar5 + 4 + iVar3);
      *piVar1 = *piVar1 + -1;
      iVar6 = *(int *)(unaff_EBP + -4) * *(int *)(unaff_EDI + 0x7c);
      iVar5 = *(int *)(unaff_EDI + 0xac);
      iVar3 = iVar6 / iVar5;
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + 0xc) + 0xd4 + iVar3 * 0x10;
      psVar2 = (short *)(*(int *)(unaff_EBP + -0x10) +
                        (((iVar6 % iVar5) % *(int *)(unaff_EDI + 0xa8) << 3) /
                        *(int *)(unaff_EDI + 0xa8)) * 2);
      *psVar2 = *psVar2 + -1;
      iVar5 = *(int *)(unaff_EBP + 0xc);
      piVar1 = (int *)(iVar5 + 0x54 + iVar3 * 4);
      *piVar1 = *piVar1 + -1;
      *(char *)(unaff_EDI + 0xd0) = *(char *)(unaff_EDI + 0xd0) + '\x01';
      return *(int *)(iVar5 + 0xc) * *(int *)(unaff_EDI + 0xbc) + *(int *)(unaff_EBP + -4);
    }
    uVar4 = (uint)*(byte *)(iVar5 + 0x560 + unaff_EDI);
    if ((uVar4 == 0) || (0x1a9cU - iVar5 < uVar4)) break;
    iVar5 = iVar5 + uVar4;
  }
  iStack00000010 = unaff_EDI + 0xd4;
  iStack0000000c = iVar5;
  _printf(s_pos____d__i____d__fs____s_001ddbba);
                    /* WARNING: Subroutine does not return */
  _panic(s_alloccgblk__can_t_find_blk_in_cy_001ddbd5);
}

