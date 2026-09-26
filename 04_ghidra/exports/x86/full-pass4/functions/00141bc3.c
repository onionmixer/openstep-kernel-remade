/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00141bc3 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_00141bc3(void)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  uint unaff_EBX;
  int iVar4;
  int unaff_EBP;
  uint unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != unaff_EBX) {
    _free_block(*(undefined4 *)(unaff_EBP + -0x104),
                unaff_EDI +
                (unaff_EBX >> ((byte)*(undefined4 *)(*(int *)(unaff_EBP + -0x100) + 0x54) & 0x1f)));
    uVar2 = (**(code **)(*(int *)(*(int *)(unaff_EBP + 8) + 0x28) + 0x80))
                      (*(int *)(unaff_EBP + 8) + 0xc);
    *(int *)(unaff_EBP + -0x114) = *(int *)(unaff_EBP + -0x114) + (unaff_ESI - unaff_EBX) / uVar2;
  }
  iVar4 = 0;
  do {
    if (*(int *)(*(int *)(unaff_EBP + -0x104) + 0xbc + iVar4 * 4) !=
        *(int *)(*(int *)(unaff_EBP + 8) + 0xbc + iVar4 * 4)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_itrunc1_001de044);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  iVar4 = 0;
  do {
    if (*(int *)(*(int *)(unaff_EBP + -0x104) + 0x8c + iVar4 * 4) !=
        *(int *)(*(int *)(unaff_EBP + 8) + 0x8c + iVar4 * 4)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_itrunc2_001de04c);
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0xc);
  iVar3 = *(int *)(*(int *)(unaff_EBP + 8) + 0xcc) - *(int *)(unaff_EBP + -0x114);
  iVar4 = *(int *)(unaff_EBP + 8);
  *(int *)(iVar4 + 0xcc) = iVar3;
  if (iVar3 < 0) {
    *(undefined4 *)(iVar4 + 0xcc) = 0;
  }
  pbVar1 = (byte *)(*(int *)(unaff_EBP + 8) + 0x44);
  *pbVar1 = *pbVar1 | 0x40;
  return (int)*(char *)(DAT_001e875c + 0x68);
}

