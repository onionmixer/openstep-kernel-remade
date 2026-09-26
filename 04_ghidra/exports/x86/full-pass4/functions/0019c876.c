/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019c876 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019c876(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined4 *puVar6;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
LAB_0019c879:
  do {
    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 1;
    if (0xb < *(int *)(unaff_EBP + -0x2c)) {
      FUN_0019ba18();
      return;
    }
    iVar1 = *(int *)(unaff_EBP + -0x1c);
    *(int *)(unaff_EBP + -0x1c) = iVar1 + 1;
    uVar2 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) goto LAB_0019c7e8;
        *(int *)(unaff_EBP + -0x24) =
             iVar1 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + unaff_EBX;
      }
      else {
        *(int *)(unaff_EBP + -0x24) =
             iVar1 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + unaff_EBX * 2;
      }
    }
    else {
      if (uVar2 != 4) {
LAB_0019c7e8:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      *(int *)(unaff_EBP + -0x24) =
           iVar1 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + unaff_EBX * 4;
    }
    uVar3 = *(undefined4 *)(unaff_ESI + 0xb0);
    iVar1 = *(int *)(unaff_EBP + -0x20);
    uVar2 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) {
LAB_0019c86c:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        puVar4 = *(undefined1 **)(unaff_EBP + -0x24);
        while (iVar1 = iVar1 + -1, iVar1 != -1) {
          *puVar4 = (char)uVar3;
          puVar4 = puVar4 + 1;
        }
      }
      else {
        puVar5 = *(undefined2 **)(unaff_EBP + -0x24);
        while (iVar1 = iVar1 + -1, iVar1 != -1) {
          *puVar5 = (short)uVar3;
          puVar5 = puVar5 + 1;
        }
      }
      goto LAB_0019c879;
    }
    if (uVar2 != 4) goto LAB_0019c86c;
    puVar6 = *(undefined4 **)(unaff_EBP + -0x24);
    while (iVar1 = iVar1 + -1, iVar1 != -1) {
      *puVar6 = uVar3;
      puVar6 = puVar6 + 1;
    }
  } while( true );
}

