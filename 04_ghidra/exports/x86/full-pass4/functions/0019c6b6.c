/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019c6b6 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019c6b6(void)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int unaff_EBP;
  int unaff_ESI;
  
  iVar8 = *(int *)(unaff_ESI + 0x8c);
  iVar1 = *(int *)(unaff_ESI + 0x90);
  uVar2 = *(uint *)(unaff_ESI + 0x1c);
  if (uVar2 < 4) {
    if (uVar2 < 2) {
      if (uVar2 != 1) goto LAB_0019c714;
      *(int *)(unaff_EBP + -0x14) =
           iVar1 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar8;
    }
    else {
      *(int *)(unaff_EBP + -0x14) =
           iVar1 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar8 * 2;
    }
  }
  else {
    if (uVar2 != 4) {
LAB_0019c714:
                    /* WARNING: Subroutine does not return */
      _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
    }
    *(int *)(unaff_EBP + -0x14) =
         iVar1 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar8 * 4;
  }
  iVar8 = 0xc;
  if (0xc < *(int *)(unaff_ESI + 0xa0)) {
    do {
      pvVar3 = *(void **)(unaff_EBP + -0x14);
      _memmove(pvVar3,*(void **)(unaff_EBP + -0x10),*(size_t *)(unaff_EBP + -0x18));
      iVar1 = *(int *)(unaff_ESI + 0x10);
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar1;
      *(int *)(unaff_EBP + -0x14) = (int)pvVar3 + iVar1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < *(int *)(unaff_ESI + 0xa0));
  }
  *(undefined4 *)(unaff_ESI + 0xa8) = 0;
  iVar8 = *(int *)(unaff_ESI + 0x8c);
  *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_ESI + 0x90) + *(int *)(unaff_ESI + 0xa4) * 0xc;
  *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_ESI + 0x98);
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  do {
    iVar1 = *(int *)(unaff_EBP + -0x1c);
    *(int *)(unaff_EBP + -0x1c) = iVar1 + 1;
    uVar2 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) goto LAB_0019c7e8;
        *(int *)(unaff_EBP + -0x24) =
             iVar1 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar8;
      }
      else {
        *(int *)(unaff_EBP + -0x24) =
             iVar1 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar8 * 2;
      }
    }
    else {
      if (uVar2 != 4) {
LAB_0019c7e8:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      *(int *)(unaff_EBP + -0x24) =
           iVar1 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar8 * 4;
    }
    uVar4 = *(undefined4 *)(unaff_ESI + 0xb0);
    iVar1 = *(int *)(unaff_EBP + -0x20);
    uVar2 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) goto LAB_0019c86c;
        puVar5 = *(undefined1 **)(unaff_EBP + -0x24);
        while (iVar1 = iVar1 + -1, iVar1 != -1) {
          *puVar5 = (char)uVar4;
          puVar5 = puVar5 + 1;
        }
      }
      else {
        puVar6 = *(undefined2 **)(unaff_EBP + -0x24);
        while (iVar1 = iVar1 + -1, iVar1 != -1) {
          *puVar6 = (short)uVar4;
          puVar6 = puVar6 + 1;
        }
      }
    }
    else {
      if (uVar2 != 4) {
LAB_0019c86c:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
      }
      puVar7 = *(undefined4 **)(unaff_EBP + -0x24);
      while (iVar1 = iVar1 + -1, iVar1 != -1) {
        *puVar7 = uVar4;
        puVar7 = puVar7 + 1;
      }
    }
    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 1;
    if (0xb < *(int *)(unaff_EBP + -0x2c)) {
      FUN_0019ba18();
      return;
    }
  } while( true );
}

