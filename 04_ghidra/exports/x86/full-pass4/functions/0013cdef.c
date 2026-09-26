/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013cdef */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013cdef(void)

{
  int *piVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int iVar5;
  int unaff_EDI;
  
  iVar3 = (*(int *)(unaff_EBP + -0x10) + *(int *)(unaff_EBP + -0x14)) - unaff_ESI;
  iVar5 = iVar3 * 8;
  uVar4 = 1;
  do {
    if ((uVar4 & (int)*(char *)(iVar3 + 0x2d4 + unaff_EDI)) == 0) {
      *(int *)(unaff_EDI + 0x30) = iVar5;
      iVar3 = iVar5;
      if (iVar5 < 0) {
        iVar3 = iVar5 + 7;
      }
      pbVar2 = (byte *)(unaff_EDI + 0x2d4 + (iVar3 >> 3));
      *pbVar2 = *pbVar2 | (byte)(1 << ((char)iVar5 + (char)(iVar3 >> 3) * -8 & 0x1fU));
      *(int *)(unaff_EDI + 0x20) = *(int *)(unaff_EDI + 0x20) + -1;
      *(int *)(unaff_EBX + 200) = *(int *)(unaff_EBX + 200) + -1;
      piVar1 = (int *)(*(int *)(unaff_EBX + 0x2d8 +
                               (*(int *)(unaff_EBP + 0xc) >>
                               ((byte)*(undefined4 *)(unaff_EBX + 0x70) & 0x1f)) * 4) + 8 +
                      (~*(uint *)(unaff_EBX + 0x6c) & *(uint *)(unaff_EBP + 0xc)) * 0x10);
      *piVar1 = *piVar1 + -1;
      *(char *)(unaff_EBX + 0xd0) = *(char *)(unaff_EBX + 0xd0) + '\x01';
      if ((*(uint *)(unaff_EBP + 0x14) & 0xf000) == 0x4000) {
        *(int *)(unaff_EDI + 0x18) = *(int *)(unaff_EDI + 0x18) + 1;
        *(int *)(unaff_EBX + 0xc0) = *(int *)(unaff_EBX + 0xc0) + 1;
        piVar1 = (int *)(*(int *)(unaff_EBX + 0x2d8 +
                                 (*(int *)(unaff_EBP + 0xc) >>
                                 ((byte)*(undefined4 *)(unaff_EBX + 0x70) & 0x1f)) * 4) +
                        (~*(uint *)(unaff_EBX + 0x6c) & *(uint *)(unaff_EBP + 0xc)) * 0x10);
        *piVar1 = *piVar1 + 1;
      }
      _byte_swap_cylgroup();
      _bdwrite();
      return *(int *)(unaff_EBP + 0xc) * *(int *)(unaff_EBX + 0xb8) + iVar5;
    }
    uVar4 = uVar4 * 2;
    iVar5 = iVar5 + 1;
  } while ((int)uVar4 < 0x100);
  _printf(s_fs____s_001ddc2e);
                    /* WARNING: Subroutine does not return */
  _panic(s_ialloccg__block_not_in_map_001ddc37);
}

