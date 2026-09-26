/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019c596 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019c596(void)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  int unaff_EBX;
  int iVar8;
  int unaff_EBP;
  int unaff_ESI;
  
  while( true ) {
    *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + *(int *)(unaff_ESI + 0x10);
    unaff_EBX = unaff_EBX + 1;
    if (*(int *)(unaff_ESI + 0xa0) <= unaff_EBX) break;
    uVar3 = *(undefined4 *)(unaff_ESI + 0xb0);
    iVar8 = *(int *)(unaff_ESI + 0x98);
    uVar1 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar1 < 4) {
      if (uVar1 < 2) {
        if (uVar1 != 1) {
LAB_0019c58c:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        puVar7 = *(undefined1 **)(unaff_EBP + -0x2c);
        while (iVar8 = iVar8 + -1, iVar8 != -1) {
          *puVar7 = (char)uVar3;
          puVar7 = puVar7 + 1;
        }
      }
      else {
        puVar5 = *(undefined2 **)(unaff_EBP + -0x2c);
        while (iVar8 = iVar8 + -1, iVar8 != -1) {
          *puVar5 = (short)uVar3;
          puVar5 = puVar5 + 1;
        }
      }
    }
    else {
      if (uVar1 != 4) goto LAB_0019c58c;
      puVar6 = *(undefined4 **)(unaff_EBP + -0x2c);
      while (iVar8 = iVar8 + -1, iVar8 != -1) {
        *puVar6 = uVar3;
        puVar6 = puVar6 + 1;
      }
    }
  }
  if (*(int *)(unaff_ESI + 0x94) <= *(int *)(unaff_ESI + 0xa8)) {
    *(undefined4 *)(unaff_ESI + 0xa8) = 0;
    *(int *)(unaff_ESI + 0xa4) = *(int *)(unaff_ESI + 0xa4) + 1;
  }
  if (*(int *)(unaff_ESI + 0x9c) <= *(int *)(unaff_ESI + 0xa4)) {
    *(int *)(unaff_ESI + 0xa4) = *(int *)(unaff_ESI + 0x9c) + -1;
    uVar1 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar1 < 4) {
      if (uVar1 < 2) {
        if (uVar1 != 1) goto LAB_0019c644;
        *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_ESI + 0x98);
      }
      else {
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_ESI + 0x98) * 2;
      }
    }
    else {
      if (uVar1 != 4) {
LAB_0019c644:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_FBPutC__bogus_bitsPerP_001e47a3);
      }
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_ESI + 0x98) << 2;
    }
    iVar8 = *(int *)(unaff_ESI + 0x8c);
    iVar4 = *(int *)(unaff_ESI + 0x90) + 0xc;
    uVar1 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar1 < 4) {
      if (uVar1 < 2) {
        if (uVar1 != 1) goto LAB_0019c6ac;
        *(int *)(unaff_EBP + -0x10) =
             iVar4 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar8;
      }
      else {
        *(int *)(unaff_EBP + -0x10) =
             iVar4 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar8 * 2;
      }
    }
    else {
      if (uVar1 != 4) {
LAB_0019c6ac:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      *(int *)(unaff_EBP + -0x10) =
           iVar4 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar8 * 4;
    }
    iVar8 = *(int *)(unaff_ESI + 0x8c);
    iVar4 = *(int *)(unaff_ESI + 0x90);
    uVar1 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar1 < 4) {
      if (uVar1 < 2) {
        if (uVar1 != 1) goto LAB_0019c714;
        *(int *)(unaff_EBP + -0x14) =
             iVar4 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar8;
      }
      else {
        *(int *)(unaff_EBP + -0x14) =
             iVar4 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar8 * 2;
      }
    }
    else {
      if (uVar1 != 4) {
LAB_0019c714:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      *(int *)(unaff_EBP + -0x14) =
           iVar4 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar8 * 4;
    }
    iVar8 = 0xc;
    if (0xc < *(int *)(unaff_ESI + 0xa0)) {
      do {
        pvVar2 = *(void **)(unaff_EBP + -0x14);
        _memmove(pvVar2,*(void **)(unaff_EBP + -0x10),*(size_t *)(unaff_EBP + -0x18));
        iVar4 = *(int *)(unaff_ESI + 0x10);
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + iVar4;
        *(int *)(unaff_EBP + -0x14) = (int)pvVar2 + iVar4;
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(unaff_ESI + 0xa0));
    }
    *(undefined4 *)(unaff_ESI + 0xa8) = 0;
    iVar8 = *(int *)(unaff_ESI + 0x8c);
    *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_ESI + 0x90) + *(int *)(unaff_ESI + 0xa4) * 0xc;
    *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(unaff_ESI + 0x98);
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    do {
      iVar4 = *(int *)(unaff_EBP + -0x1c);
      *(int *)(unaff_EBP + -0x1c) = iVar4 + 1;
      uVar1 = *(uint *)(unaff_ESI + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019c7e8;
          *(int *)(unaff_EBP + -0x24) =
               iVar4 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar8;
        }
        else {
          *(int *)(unaff_EBP + -0x24) =
               iVar4 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar8 * 2;
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019c7e8:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        *(int *)(unaff_EBP + -0x24) =
             iVar4 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar8 * 4;
      }
      uVar3 = *(undefined4 *)(unaff_ESI + 0xb0);
      iVar4 = *(int *)(unaff_EBP + -0x20);
      uVar1 = *(uint *)(unaff_ESI + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019c86c;
          puVar7 = *(undefined1 **)(unaff_EBP + -0x24);
          while (iVar4 = iVar4 + -1, iVar4 != -1) {
            *puVar7 = (char)uVar3;
            puVar7 = puVar7 + 1;
          }
        }
        else {
          puVar5 = *(undefined2 **)(unaff_EBP + -0x24);
          while (iVar4 = iVar4 + -1, iVar4 != -1) {
            *puVar5 = (short)uVar3;
            puVar5 = puVar5 + 1;
          }
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019c86c:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        puVar6 = *(undefined4 **)(unaff_EBP + -0x24);
        while (iVar4 = iVar4 + -1, iVar4 != -1) {
          *puVar6 = uVar3;
          puVar6 = puVar6 + 1;
        }
      }
      *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 1;
    } while (*(int *)(unaff_EBP + -0x2c) < 0xc);
  }
  FUN_0019ba18();
  return;
}

