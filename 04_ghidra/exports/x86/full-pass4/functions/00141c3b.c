/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00141c3b */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_00141c3b(void)

{
  byte *pbVar1;
  int iVar2;
  int unaff_EBX;
  int iVar3;
  int unaff_EBP;
  
  while (unaff_EBX = unaff_EBX + 1, unaff_EBX < 3) {
    if (*(int *)(*(int *)(unaff_EBP + -0x104) + 0xbc + unaff_EBX * 4) !=
        *(int *)(*(int *)(unaff_EBP + 8) + 0xbc + unaff_EBX * 4)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_itrunc1_001de044);
    }
  }
  iVar3 = 0;
  do {
    if (*(int *)(*(int *)(unaff_EBP + -0x104) + 0x8c + iVar3 * 4) !=
        *(int *)(*(int *)(unaff_EBP + 8) + 0x8c + iVar3 * 4)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_itrunc2_001de04c);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xc);
  iVar2 = *(int *)(*(int *)(unaff_EBP + 8) + 0xcc) - *(int *)(unaff_EBP + -0x114);
  iVar3 = *(int *)(unaff_EBP + 8);
  *(int *)(iVar3 + 0xcc) = iVar2;
  if (iVar2 < 0) {
    *(undefined4 *)(iVar3 + 0xcc) = 0;
  }
  pbVar1 = (byte *)(*(int *)(unaff_EBP + 8) + 0x44);
  *pbVar1 = *pbVar1 | 0x40;
  return (int)*(char *)(DAT_001e875c + 0x68);
}

