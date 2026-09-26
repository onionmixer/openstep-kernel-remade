/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019da6e */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019da6e(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined4 *puVar6;
  undefined4 unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int iVar7;
  int unaff_EDI;
  
  while (*(int *)(unaff_EBP + -0x4c) = *(int *)(unaff_EBP + -0x4c) + -1,
        *(int *)(unaff_EBP + -0x4c) != -1) {
    *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x48);
    *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x48) + 1;
    uVar2 = *(uint *)(unaff_EDI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) goto LAB_0019d9e0;
        *(int *)(unaff_EBP + -0x50) =
             *(int *)(unaff_EBP + -0x80) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
             unaff_ESI;
      }
      else {
        *(int *)(unaff_EBP + -0x50) =
             *(int *)(unaff_EBP + -0x80) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
             unaff_ESI * 2;
      }
    }
    else {
      if (uVar2 != 4) {
LAB_0019d9e0:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      *(int *)(unaff_EBP + -0x50) =
           *(int *)(unaff_EBP + -0x80) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
           unaff_ESI * 4;
    }
    uVar2 = *(uint *)(unaff_EDI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) {
LAB_0019da64:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        puVar4 = *(undefined1 **)(unaff_EBP + -0x50);
        *(undefined4 *)(unaff_EBP + -0x80) = 0;
        do {
          *puVar4 = (char)unaff_EBX;
          puVar4 = puVar4 + 1;
          *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + -1;
        } while (*(int *)(unaff_EBP + -0x80) != -1);
      }
      else {
        puVar5 = *(undefined2 **)(unaff_EBP + -0x50);
        *(undefined4 *)(unaff_EBP + -0x80) = 0;
        do {
          *puVar5 = (short)unaff_EBX;
          puVar5 = puVar5 + 1;
          *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + -1;
        } while (*(int *)(unaff_EBP + -0x80) != -1);
      }
    }
    else {
      if (uVar2 != 4) goto LAB_0019da64;
      puVar6 = *(undefined4 **)(unaff_EBP + -0x50);
      *(undefined4 *)(unaff_EBP + -0x80) = 0;
      do {
        *puVar6 = unaff_EBX;
        puVar6 = puVar6 + 1;
        *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + -1;
      } while (*(int *)(unaff_EBP + -0x80) != -1);
    }
  }
  iVar7 = *(int *)(unaff_EDI + 0x8c) + -2;
  *(int *)(unaff_EBP + -0x54) = *(int *)(unaff_EDI + 0x90) + -2;
  uVar1 = *(undefined4 *)(unaff_EDI + 0xb0);
  iVar3 = *(int *)(unaff_EBP + 0x10) + 3;
  *(int *)(unaff_EBP + -0x58) = iVar3;
  while (iVar3 != -1) {
    *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x54);
    *(int *)(unaff_EBP + -0x54) = *(int *)(unaff_EBP + -0x54) + 1;
    uVar2 = *(uint *)(unaff_EDI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) goto LAB_0019db10;
        *(int *)(unaff_EBP + -0x5c) =
             *(int *)(unaff_EBP + -0x80) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
             iVar7;
      }
      else {
        *(int *)(unaff_EBP + -0x5c) =
             *(int *)(unaff_EBP + -0x80) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
             iVar7 * 2;
      }
    }
    else {
      if (uVar2 != 4) {
LAB_0019db10:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      *(int *)(unaff_EBP + -0x5c) =
           *(int *)(unaff_EBP + -0x80) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
           iVar7 * 4;
    }
    uVar2 = *(uint *)(unaff_EDI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) goto LAB_0019db94;
        puVar4 = *(undefined1 **)(unaff_EBP + -0x5c);
        *(undefined4 *)(unaff_EBP + -0x80) = 1;
        do {
          *puVar4 = (char)uVar1;
          puVar4 = puVar4 + 1;
          *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + -1;
        } while (*(int *)(unaff_EBP + -0x80) != -1);
      }
      else {
        puVar5 = *(undefined2 **)(unaff_EBP + -0x5c);
        *(undefined4 *)(unaff_EBP + -0x80) = 1;
        do {
          *puVar5 = (short)uVar1;
          puVar5 = puVar5 + 1;
          *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + -1;
        } while (*(int *)(unaff_EBP + -0x80) != -1);
      }
    }
    else {
      if (uVar2 != 4) {
LAB_0019db94:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
      }
      puVar6 = *(undefined4 **)(unaff_EBP + -0x5c);
      *(undefined4 *)(unaff_EBP + -0x80) = 1;
      do {
        *puVar6 = uVar1;
        puVar6 = puVar6 + 1;
        *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + -1;
      } while (*(int *)(unaff_EBP + -0x80) != -1);
    }
    *(int *)(unaff_EBP + -0x58) = *(int *)(unaff_EBP + -0x58) + -1;
    iVar3 = *(int *)(unaff_EBP + -0x58);
  }
  iVar7 = *(int *)(unaff_EBP + 0xc) + *(int *)(unaff_EDI + 0x8c);
  *(int *)(unaff_EBP + -0x60) = *(int *)(unaff_EDI + 0x90) + -2;
  uVar1 = *(undefined4 *)(unaff_EDI + 0xb0);
  iVar3 = *(int *)(unaff_EBP + 0x10) + 3;
  *(int *)(unaff_EBP + -100) = iVar3;
  while (iVar3 != -1) {
    *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x60);
    *(int *)(unaff_EBP + -0x60) = *(int *)(unaff_EBP + -0x60) + 1;
    uVar2 = *(uint *)(unaff_EDI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) goto LAB_0019dc40;
        *(int *)(unaff_EBP + -0x68) =
             *(int *)(unaff_EBP + -0x80) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
             iVar7;
      }
      else {
        *(int *)(unaff_EBP + -0x68) =
             *(int *)(unaff_EBP + -0x80) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
             iVar7 * 2;
      }
    }
    else {
      if (uVar2 != 4) {
LAB_0019dc40:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      *(int *)(unaff_EBP + -0x68) =
           *(int *)(unaff_EBP + -0x80) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
           iVar7 * 4;
    }
    uVar2 = *(uint *)(unaff_EDI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) goto LAB_0019dcc4;
        puVar4 = *(undefined1 **)(unaff_EBP + -0x68);
        *(undefined4 *)(unaff_EBP + -0x80) = 1;
        do {
          *puVar4 = (char)uVar1;
          puVar4 = puVar4 + 1;
          *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + -1;
        } while (*(int *)(unaff_EBP + -0x80) != -1);
      }
      else {
        puVar5 = *(undefined2 **)(unaff_EBP + -0x68);
        *(undefined4 *)(unaff_EBP + -0x80) = 1;
        do {
          *puVar5 = (short)uVar1;
          puVar5 = puVar5 + 1;
          *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + -1;
        } while (*(int *)(unaff_EBP + -0x80) != -1);
      }
    }
    else {
      if (uVar2 != 4) {
LAB_0019dcc4:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
      }
      puVar6 = *(undefined4 **)(unaff_EBP + -0x68);
      *(undefined4 *)(unaff_EBP + -0x80) = 1;
      do {
        *puVar6 = uVar1;
        puVar6 = puVar6 + 1;
        *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + -1;
      } while (*(int *)(unaff_EBP + -0x80) != -1);
    }
    *(int *)(unaff_EBP + -100) = *(int *)(unaff_EBP + -100) + -1;
    iVar3 = *(int *)(unaff_EBP + -100);
  }
  iVar7 = *(int *)(unaff_EBP + 0xc) + *(int *)(unaff_EDI + 0x8c) + 2;
  *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EDI + 0x90) + -3;
  *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EDI + 0xb4);
  for (iVar3 = *(int *)(unaff_EBP + 0x10) + 5; iVar3 != -1; iVar3 = iVar3 + -1) {
    *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x6c);
    *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EBP + -0x6c) + 1;
    uVar2 = *(uint *)(unaff_EDI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) goto LAB_0019dd74;
        *(int *)(unaff_EBP + -0x70) =
             *(int *)(unaff_EBP + -0x7c) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
             iVar7;
      }
      else {
        *(int *)(unaff_EBP + -0x70) =
             *(int *)(unaff_EBP + -0x7c) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
             iVar7 * 2;
      }
    }
    else {
      if (uVar2 != 4) {
LAB_0019dd74:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      *(int *)(unaff_EBP + -0x70) =
           *(int *)(unaff_EBP + -0x7c) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
           iVar7 * 4;
    }
    uVar2 = *(uint *)(unaff_EDI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) goto LAB_0019de04;
        puVar4 = *(undefined1 **)(unaff_EBP + -0x70);
        *(undefined4 *)(unaff_EBP + -0x7c) = 0;
        do {
          *puVar4 = *(undefined1 *)(unaff_EBP + -0x80);
          puVar4 = puVar4 + 1;
          *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x7c) + -1;
        } while (*(int *)(unaff_EBP + -0x7c) != -1);
      }
      else {
        puVar5 = *(undefined2 **)(unaff_EBP + -0x70);
        *(undefined4 *)(unaff_EBP + -0x7c) = 0;
        do {
          *puVar5 = *(undefined2 *)(unaff_EBP + -0x80);
          puVar5 = puVar5 + 1;
          *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x7c) + -1;
        } while (*(int *)(unaff_EBP + -0x7c) != -1);
      }
    }
    else {
      if (uVar2 != 4) {
LAB_0019de04:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
      }
      puVar6 = *(undefined4 **)(unaff_EBP + -0x70);
      *(undefined4 *)(unaff_EBP + -0x7c) = 0;
      do {
        *puVar6 = *(undefined4 *)(unaff_EBP + -0x80);
        puVar6 = puVar6 + 1;
        *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x7c) + -1;
      } while (*(int *)(unaff_EBP + -0x7c) != -1);
    }
  }
  iVar3 = *(int *)(unaff_EDI + 0x8c);
  iVar7 = *(int *)(unaff_EDI + 0x90);
  uVar2 = *(uint *)(unaff_EDI + 0x1c);
  if (uVar2 < 4) {
    if (uVar2 < 2) {
      if (uVar2 != 1) goto LAB_0019de7c;
      *(int *)(unaff_EBP + -0x74) =
           iVar7 * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) + iVar3;
    }
    else {
      *(int *)(unaff_EBP + -0x74) =
           iVar7 * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) + iVar3 * 2;
    }
  }
  else {
    if (uVar2 != 4) {
LAB_0019de7c:
                    /* WARNING: Subroutine does not return */
      _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
    }
    *(int *)(unaff_EBP + -0x74) =
         iVar7 * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) + iVar3 * 4;
  }
  iVar3 = 0;
  if (0 < *(int *)(unaff_EDI + 0xa0)) {
    do {
      *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EDI + 0xb0);
      iVar7 = *(int *)(unaff_EDI + 0x98);
      uVar2 = *(uint *)(unaff_EDI + 0x1c);
      if (uVar2 < 4) {
        if (uVar2 < 2) {
          if (uVar2 != 1) goto LAB_0019df1c;
          puVar4 = *(undefined1 **)(unaff_EBP + -0x74);
          while (iVar7 = iVar7 + -1, iVar7 != -1) {
            *puVar4 = *(undefined1 *)(unaff_EBP + -0x80);
            puVar4 = puVar4 + 1;
          }
        }
        else {
          puVar5 = *(undefined2 **)(unaff_EBP + -0x74);
          while (iVar7 = iVar7 + -1, iVar7 != -1) {
            *puVar5 = *(undefined2 *)(unaff_EBP + -0x80);
            puVar5 = puVar5 + 1;
          }
        }
      }
      else {
        if (uVar2 != 4) {
LAB_0019df1c:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        puVar6 = *(undefined4 **)(unaff_EBP + -0x74);
        while (iVar7 = iVar7 + -1, iVar7 != -1) {
          *puVar6 = *(undefined4 *)(unaff_EBP + -0x80);
          puVar6 = puVar6 + 1;
        }
      }
      *(int *)(unaff_EBP + -0x74) = *(int *)(unaff_EBP + -0x74) + *(int *)(unaff_EDI + 0x10);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(unaff_EDI + 0xa0));
  }
  FUN_0019ba18();
  FUN_0019c898();
  return;
}

