/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019c7f2 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019c7f2(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined4 *puVar6;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
LAB_0019c7f5:
  do {
    uVar1 = *(undefined4 *)(unaff_ESI + 0xb0);
    iVar2 = *(int *)(unaff_EBP + -0x20);
    uVar3 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar3 < 4) {
      if (uVar3 < 2) {
        if (uVar3 != 1) goto LAB_0019c86c;
        puVar4 = *(undefined1 **)(unaff_EBP + -0x24);
        while (iVar2 = iVar2 + -1, iVar2 != -1) {
          *puVar4 = (char)uVar1;
          puVar4 = puVar4 + 1;
        }
      }
      else {
        puVar5 = *(undefined2 **)(unaff_EBP + -0x24);
        while (iVar2 = iVar2 + -1, iVar2 != -1) {
          *puVar5 = (short)uVar1;
          puVar5 = puVar5 + 1;
        }
      }
    }
    else {
      if (uVar3 != 4) {
LAB_0019c86c:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
      }
      puVar6 = *(undefined4 **)(unaff_EBP + -0x24);
      while (iVar2 = iVar2 + -1, iVar2 != -1) {
        *puVar6 = uVar1;
        puVar6 = puVar6 + 1;
      }
    }
    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 1;
    if (0xb < *(int *)(unaff_EBP + -0x2c)) {
      FUN_0019ba18();
      return;
    }
    iVar2 = *(int *)(unaff_EBP + -0x1c);
    *(int *)(unaff_EBP + -0x1c) = iVar2 + 1;
    uVar3 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar3 < 4) {
      if (uVar3 < 2) {
        if (uVar3 != 1) {
LAB_0019c7e8:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        *(int *)(unaff_EBP + -0x24) =
             iVar2 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + unaff_EBX;
      }
      else {
        *(int *)(unaff_EBP + -0x24) =
             iVar2 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + unaff_EBX * 2;
      }
      goto LAB_0019c7f5;
    }
    if (uVar3 != 4) goto LAB_0019c7e8;
    *(int *)(unaff_EBP + -0x24) =
         iVar2 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + unaff_EBX * 4;
  } while( true );
}

