/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019cd0e */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019cd0e(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  undefined4 unaff_EBX;
  int iVar6;
  int unaff_EBP;
  int unaff_ESI;
  int iVar7;
  
  while (*(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x3c) + -1,
        *(int *)(unaff_EBP + -0x3c) != -1) {
    iVar7 = *(int *)(unaff_EBP + -0x34);
    *(int *)(unaff_EBP + -0x34) = iVar7 + 1;
    uVar1 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar1 < 4) {
      if (uVar1 < 2) {
        if (uVar1 != 1) goto LAB_0019cc88;
        *(int *)(unaff_EBP + -0x40) =
             iVar7 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) +
             *(int *)(unaff_EBP + -0x80);
      }
      else {
        *(int *)(unaff_EBP + -0x40) =
             iVar7 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) +
             *(int *)(unaff_EBP + -0x80) * 2;
      }
    }
    else {
      if (uVar1 != 4) {
LAB_0019cc88:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      *(int *)(unaff_EBP + -0x40) =
           iVar7 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) +
           *(int *)(unaff_EBP + -0x80) * 4;
    }
    iVar7 = *(int *)(unaff_EBP + -0x38);
    uVar1 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar1 < 4) {
      if (uVar1 < 2) {
        if (uVar1 != 1) {
LAB_0019cd04:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        puVar3 = *(undefined1 **)(unaff_EBP + -0x40);
        while (iVar7 = iVar7 + -1, iVar7 != -1) {
          *puVar3 = (char)unaff_EBX;
          puVar3 = puVar3 + 1;
        }
      }
      else {
        puVar4 = *(undefined2 **)(unaff_EBP + -0x40);
        while (iVar7 = iVar7 + -1, iVar7 != -1) {
          *puVar4 = (short)unaff_EBX;
          puVar4 = puVar4 + 1;
        }
      }
    }
    else {
      if (uVar1 != 4) goto LAB_0019cd04;
      puVar5 = *(undefined4 **)(unaff_EBP + -0x40);
      while (iVar7 = iVar7 + -1, iVar7 != -1) {
        *puVar5 = unaff_EBX;
        puVar5 = puVar5 + 1;
      }
    }
  }
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -0x74) = 0x17;
  do {
    iVar6 = *(int *)(unaff_EBP + -0x10) + *(int *)(unaff_ESI + 0x8c) + -2;
    *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x10) + *(int *)(unaff_ESI + 0x90) + -2;
    *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_ESI + 0xbc);
    iVar7 = *(int *)(unaff_EBP + -0x74) + -1;
    *(int *)(unaff_EBP + -0x80) = iVar7;
    while (iVar7 != -1) {
      iVar7 = *(int *)(unaff_EBP + -0x44);
      *(int *)(unaff_EBP + -0x44) = iVar7 + 1;
      uVar1 = *(uint *)(unaff_ESI + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019cdb8;
          *(int *)(unaff_EBP + -0x48) =
               iVar7 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar6;
        }
        else {
          *(int *)(unaff_EBP + -0x48) =
               iVar7 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar6 * 2;
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019cdb8:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        *(int *)(unaff_EBP + -0x48) =
             iVar7 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar6 * 4;
      }
      uVar1 = *(uint *)(unaff_ESI + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019ce30;
          puVar3 = *(undefined1 **)(unaff_EBP + -0x48);
          iVar7 = 0;
          do {
            *puVar3 = *(undefined1 *)(unaff_EBP + -0x7c);
            puVar3 = puVar3 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != -1);
        }
        else {
          puVar4 = *(undefined2 **)(unaff_EBP + -0x48);
          iVar7 = 0;
          do {
            *puVar4 = *(undefined2 *)(unaff_EBP + -0x7c);
            puVar4 = puVar4 + 1;
            iVar7 = iVar7 + -1;
          } while (iVar7 != -1);
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019ce30:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        puVar5 = *(undefined4 **)(unaff_EBP + -0x48);
        iVar7 = 0;
        do {
          *puVar5 = *(undefined4 *)(unaff_EBP + -0x7c);
          puVar5 = puVar5 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != -1);
      }
      *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + -1;
      iVar7 = *(int *)(unaff_EBP + -0x80);
    }
    *(int *)(unaff_EBP + -0x74) = *(int *)(unaff_EBP + -0x74) + -2;
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
  } while (*(int *)(unaff_EBP + -0x10) < 2);
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  *(undefined4 *)(unaff_EBP + -0x70) = 0x15;
  do {
    iVar7 = *(int *)(unaff_EBP + -0x10) + -1 +
            *(int *)(unaff_ESI + 0x8c) + *(int *)(unaff_ESI + 0x98);
    *(int *)(unaff_EBP + -0x4c) = *(int *)(unaff_ESI + 0x90) - *(int *)(unaff_EBP + -0x10);
    *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_ESI + 0xb8);
    iVar6 = *(int *)(unaff_EBP + -0x70) + -1;
    *(int *)(unaff_EBP + -0x80) = iVar6;
    while (iVar6 != -1) {
      iVar6 = *(int *)(unaff_EBP + -0x4c);
      *(int *)(unaff_EBP + -0x4c) = iVar6 + 1;
      uVar1 = *(uint *)(unaff_ESI + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019cefc;
          *(int *)(unaff_EBP + -0x50) =
               iVar6 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar7;
        }
        else {
          *(int *)(unaff_EBP + -0x50) =
               iVar6 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar7 * 2;
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019cefc:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        *(int *)(unaff_EBP + -0x50) =
             iVar6 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar7 * 4;
      }
      uVar1 = *(uint *)(unaff_ESI + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019cf74;
          puVar3 = *(undefined1 **)(unaff_EBP + -0x50);
          iVar6 = 0;
          do {
            *puVar3 = *(undefined1 *)(unaff_EBP + -0x7c);
            puVar3 = puVar3 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != -1);
        }
        else {
          puVar4 = *(undefined2 **)(unaff_EBP + -0x50);
          iVar6 = 0;
          do {
            *puVar4 = *(undefined2 *)(unaff_EBP + -0x7c);
            puVar4 = puVar4 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != -1);
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019cf74:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        puVar5 = *(undefined4 **)(unaff_EBP + -0x50);
        iVar6 = 0;
        do {
          *puVar5 = *(undefined4 *)(unaff_EBP + -0x7c);
          puVar5 = puVar5 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != -1);
      }
      *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + -1;
      iVar6 = *(int *)(unaff_EBP + -0x80);
    }
    *(int *)(unaff_EBP + -0x70) = *(int *)(unaff_EBP + -0x70) + 2;
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
  } while (*(int *)(unaff_EBP + -0x10) < 3);
  *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_ESI + 0x8c) + -3;
  *(int *)(unaff_EBP + -0x54) = *(int *)(unaff_ESI + 0x90) + 0x15;
  *(int *)(unaff_EBP + -0x58) = *(int *)(unaff_ESI + 0x98) + 6;
  uVar2 = *(undefined4 *)(unaff_ESI + 0xb4);
  *(undefined4 *)(unaff_EBP + -0x5c) = 0;
  do {
    iVar7 = *(int *)(unaff_EBP + -0x54);
    *(int *)(unaff_EBP + -0x54) = iVar7 + 1;
    uVar1 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar1 < 4) {
      if (uVar1 < 2) {
        if (uVar1 != 1) goto LAB_0019d030;
        *(int *)(unaff_EBP + -0x60) =
             iVar7 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) +
             *(int *)(unaff_EBP + -0x80);
      }
      else {
        *(int *)(unaff_EBP + -0x60) =
             iVar7 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) +
             *(int *)(unaff_EBP + -0x80) * 2;
      }
    }
    else {
      if (uVar1 != 4) {
LAB_0019d030:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      *(int *)(unaff_EBP + -0x60) =
           iVar7 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) +
           *(int *)(unaff_EBP + -0x80) * 4;
    }
    iVar7 = *(int *)(unaff_EBP + -0x58);
    uVar1 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar1 < 4) {
      if (uVar1 < 2) {
        if (uVar1 != 1) goto LAB_0019d0ac;
        puVar3 = *(undefined1 **)(unaff_EBP + -0x60);
        while (iVar7 = iVar7 + -1, iVar7 != -1) {
          *puVar3 = (char)uVar2;
          puVar3 = puVar3 + 1;
        }
      }
      else {
        puVar4 = *(undefined2 **)(unaff_EBP + -0x60);
        while (iVar7 = iVar7 + -1, iVar7 != -1) {
          *puVar4 = (short)uVar2;
          puVar4 = puVar4 + 1;
        }
      }
    }
    else {
      if (uVar1 != 4) {
LAB_0019d0ac:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
      }
      puVar5 = *(undefined4 **)(unaff_EBP + -0x60);
      while (iVar7 = iVar7 + -1, iVar7 != -1) {
        *puVar5 = uVar2;
        puVar5 = puVar5 + 1;
      }
    }
    *(int *)(unaff_EBP + -0x5c) = *(int *)(unaff_EBP + -0x5c) + -1;
  } while (*(int *)(unaff_EBP + -0x5c) != -1);
  *(int *)(unaff_ESI + 0x90) = *(int *)(unaff_ESI + 0x90) + 0x18;
  *(int *)(unaff_ESI + 0x9c) = *(int *)(unaff_ESI + 0x9c) + -2;
  *(int *)(unaff_ESI + 0xa0) = *(int *)(unaff_ESI + 0xa0) + -0x18;
  *(undefined4 *)(unaff_ESI + 0xa8) = *(undefined4 *)(unaff_EBP + -8);
  if (*(int *)(unaff_EBP + -4) < 1) {
    iVar6 = *(int *)(unaff_ESI + 0x8c);
    iVar7 = iVar6 + *(int *)(unaff_EBP + -8) * 8;
    *(int *)(unaff_EBP + -100) = *(int *)(unaff_ESI + 0x90) + *(int *)(unaff_ESI + 0xa4) * 0xc;
    *(int *)(unaff_EBP + -0x68) = *(int *)(unaff_ESI + 0x98) - (iVar7 - iVar6);
    *(undefined4 *)(unaff_EBP + -0x80) = 0;
    do {
      iVar6 = *(int *)(unaff_EBP + -100);
      *(int *)(unaff_EBP + -100) = iVar6 + 1;
      uVar1 = *(uint *)(unaff_ESI + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019d18c;
          *(int *)(unaff_EBP + -0x6c) =
               iVar6 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar7;
        }
        else {
          *(int *)(unaff_EBP + -0x6c) =
               iVar6 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar7 * 2;
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019d18c:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        *(int *)(unaff_EBP + -0x6c) =
             iVar6 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar7 * 4;
      }
      *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_ESI + 0xb0);
      iVar6 = *(int *)(unaff_EBP + -0x68);
      uVar1 = *(uint *)(unaff_ESI + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019d21c;
          puVar3 = *(undefined1 **)(unaff_EBP + -0x6c);
          while (iVar6 = iVar6 + -1, iVar6 != -1) {
            *puVar3 = *(undefined1 *)(unaff_EBP + -0x7c);
            puVar3 = puVar3 + 1;
          }
        }
        else {
          puVar4 = *(undefined2 **)(unaff_EBP + -0x6c);
          while (iVar6 = iVar6 + -1, iVar6 != -1) {
            *puVar4 = *(undefined2 *)(unaff_EBP + -0x7c);
            puVar4 = puVar4 + 1;
          }
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019d21c:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        puVar5 = *(undefined4 **)(unaff_EBP + -0x6c);
        while (iVar6 = iVar6 + -1, iVar6 != -1) {
          *puVar5 = *(undefined4 *)(unaff_EBP + -0x7c);
          puVar5 = puVar5 + 1;
        }
      }
      *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + 1;
    } while (*(int *)(unaff_EBP + -0x80) < 0xc);
  }
  else {
    *(int *)(unaff_ESI + 0xa4) = *(int *)(unaff_EBP + -4) + -2;
  }
  FUN_0019ba18();
  *(undefined4 *)(unaff_ESI + 0xc0) = 1;
  return;
}

