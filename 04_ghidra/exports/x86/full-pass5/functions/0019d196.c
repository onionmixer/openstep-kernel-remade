/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019d196 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019d196(void)

{
  int iVar1;
  uint uVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
LAB_0019d199:
  do {
    *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_ESI + 0xb0);
    iVar1 = *(int *)(unaff_EBP + -0x68);
    uVar2 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) goto LAB_0019d21c;
        puVar3 = *(undefined1 **)(unaff_EBP + -0x6c);
        while (iVar1 = iVar1 + -1, iVar1 != -1) {
          *puVar3 = *(undefined1 *)(unaff_EBP + -0x7c);
          puVar3 = puVar3 + 1;
        }
      }
      else {
        puVar4 = *(undefined2 **)(unaff_EBP + -0x6c);
        while (iVar1 = iVar1 + -1, iVar1 != -1) {
          *puVar4 = *(undefined2 *)(unaff_EBP + -0x7c);
          puVar4 = puVar4 + 1;
        }
      }
    }
    else {
      if (uVar2 != 4) {
LAB_0019d21c:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
      }
      puVar5 = *(undefined4 **)(unaff_EBP + -0x6c);
      while (iVar1 = iVar1 + -1, iVar1 != -1) {
        *puVar5 = *(undefined4 *)(unaff_EBP + -0x7c);
        puVar5 = puVar5 + 1;
      }
    }
    *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + 1;
    if (0xb < *(int *)(unaff_EBP + -0x80)) {
      FUN_0019ba18();
      *(undefined4 *)(unaff_ESI + 0xc0) = 1;
      return;
    }
    iVar1 = *(int *)(unaff_EBP + -100);
    *(int *)(unaff_EBP + -100) = iVar1 + 1;
    uVar2 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) {
LAB_0019d18c:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        *(int *)(unaff_EBP + -0x6c) =
             iVar1 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + unaff_EBX;
      }
      else {
        *(int *)(unaff_EBP + -0x6c) =
             iVar1 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + unaff_EBX * 2;
      }
      goto LAB_0019d199;
    }
    if (uVar2 != 4) goto LAB_0019d18c;
    *(int *)(unaff_EBP + -0x6c) =
         iVar1 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + unaff_EBX * 4;
  } while( true );
}

