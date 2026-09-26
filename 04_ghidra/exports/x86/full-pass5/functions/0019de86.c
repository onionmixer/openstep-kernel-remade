/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019de86 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019de86(void)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int unaff_EBP;
  int unaff_EDI;
  
  iVar6 = 0;
  if (0 < *(int *)(unaff_EDI + 0xa0)) {
    do {
      *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EDI + 0xb0);
      iVar1 = *(int *)(unaff_EDI + 0x98);
      uVar2 = *(uint *)(unaff_EDI + 0x1c);
      if (uVar2 < 4) {
        if (uVar2 < 2) {
          if (uVar2 != 1) goto LAB_0019df1c;
          puVar3 = *(undefined1 **)(unaff_EBP + -0x74);
          while (iVar1 = iVar1 + -1, iVar1 != -1) {
            *puVar3 = *(undefined1 *)(unaff_EBP + -0x80);
            puVar3 = puVar3 + 1;
          }
        }
        else {
          puVar4 = *(undefined2 **)(unaff_EBP + -0x74);
          while (iVar1 = iVar1 + -1, iVar1 != -1) {
            *puVar4 = *(undefined2 *)(unaff_EBP + -0x80);
            puVar4 = puVar4 + 1;
          }
        }
      }
      else {
        if (uVar2 != 4) {
LAB_0019df1c:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        puVar5 = *(undefined4 **)(unaff_EBP + -0x74);
        while (iVar1 = iVar1 + -1, iVar1 != -1) {
          *puVar5 = *(undefined4 *)(unaff_EBP + -0x80);
          puVar5 = puVar5 + 1;
        }
      }
      *(int *)(unaff_EBP + -0x74) = *(int *)(unaff_EBP + -0x74) + *(int *)(unaff_EDI + 0x10);
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(unaff_EDI + 0xa0));
  }
  FUN_0019ba18();
  FUN_0019c898();
  return;
}

