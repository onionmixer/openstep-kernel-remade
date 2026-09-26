/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013d722 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0013d722(void)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int unaff_EBX;
  int iVar5;
  int unaff_EBP;
  int unaff_EDI;
  int iStack0000000c;
  int iStack00000010;
  
  iStack0000000c = ((*(int *)(unaff_EBP + -0x14) + unaff_EDI) - unaff_EBX) * 8;
  *(int *)(*(int *)(unaff_EBP + 0xc) + 0x2c) = iStack0000000c;
  *(int *)(unaff_EBP + -4) = iStack0000000c + 8;
  if (iStack0000000c < iStack0000000c + 8) {
    do {
      iVar5 = iStack0000000c;
      if (iStack0000000c < 0) {
        iVar5 = iStack0000000c + 7;
      }
      bVar1 = *(byte *)((iVar5 >> 3) + 0x3d8 + *(int *)(unaff_EBP + 0xc));
      uVar2 = *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x38);
      *(undefined4 *)(unaff_EBP + -0x10) = uVar2;
      *(int *)(unaff_EBP + -8) =
           (int)(uint)bVar1 >> ((char)iStack0000000c + (char)(iVar5 >> 3) * -8 & 0x1fU) &
           0xff >> (8U - (char)uVar2 & 0x1f);
      *(int *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -8) << 1;
      *(undefined4 *)(unaff_EBP + -0x14) =
           *(undefined4 *)(&_around + *(int *)(unaff_EBP + 0x14) * 4);
      uVar4 = *(uint *)(&_inside + *(int *)(unaff_EBP + 0x14) * 4);
      iVar5 = 0;
      uVar3 = *(int *)(unaff_EBP + -0x10) - *(int *)(unaff_EBP + 0x14);
      if (uVar3 < 0x80000000) {
        *(uint *)(unaff_EBP + -0xc) = uVar3;
        do {
          if ((*(uint *)(unaff_EBP + -8) & *(uint *)(unaff_EBP + -0x14)) == uVar4) {
            return iVar5 + iStack0000000c;
          }
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) << 1;
          uVar4 = uVar4 * 2;
          iVar5 = iVar5 + 1;
        } while (iVar5 <= *(int *)(unaff_EBP + -0xc));
      }
      iStack0000000c = iStack0000000c + *(int *)(*(int *)(unaff_EBP + 8) + 0x38);
    } while (iStack0000000c < *(int *)(unaff_EBP + -4));
  }
  iStack00000010 = *(int *)(unaff_EBP + 8) + 0xd4;
  _printf(s_bno____d__fs____s_001dddc3);
                    /* WARNING: Subroutine does not return */
  _panic(s_alloccg__block_not_in_map_001dddd6);
}

