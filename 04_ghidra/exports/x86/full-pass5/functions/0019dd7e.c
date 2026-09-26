/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019dd7e */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019dd7e(void)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  int unaff_EBX;
  int iVar6;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
LAB_0019dd81:
  do {
    uVar1 = *(uint *)(unaff_EDI + 0x1c);
    if (uVar1 < 4) {
      if (uVar1 < 2) {
        if (uVar1 != 1) goto LAB_0019de04;
        puVar3 = *(undefined1 **)(unaff_EBP + -0x70);
        *(undefined4 *)(unaff_EBP + -0x7c) = 0;
        do {
          *puVar3 = *(undefined1 *)(unaff_EBP + -0x80);
          puVar3 = puVar3 + 1;
          *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x7c) + -1;
        } while (*(int *)(unaff_EBP + -0x7c) != -1);
      }
      else {
        puVar4 = *(undefined2 **)(unaff_EBP + -0x70);
        *(undefined4 *)(unaff_EBP + -0x7c) = 0;
        do {
          *puVar4 = *(undefined2 *)(unaff_EBP + -0x80);
          puVar4 = puVar4 + 1;
          *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x7c) + -1;
        } while (*(int *)(unaff_EBP + -0x7c) != -1);
      }
    }
    else {
      if (uVar1 != 4) {
LAB_0019de04:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
      }
      puVar5 = *(undefined4 **)(unaff_EBP + -0x70);
      *(undefined4 *)(unaff_EBP + -0x7c) = 0;
      do {
        *puVar5 = *(undefined4 *)(unaff_EBP + -0x80);
        puVar5 = puVar5 + 1;
        *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x7c) + -1;
      } while (*(int *)(unaff_EBP + -0x7c) != -1);
    }
    unaff_ESI = unaff_ESI + -1;
    if (unaff_ESI == -1) {
      iVar6 = *(int *)(unaff_EDI + 0x8c);
      iVar2 = *(int *)(unaff_EDI + 0x90);
      uVar1 = *(uint *)(unaff_EDI + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019de7c;
          *(int *)(unaff_EBP + -0x74) =
               iVar2 * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) + iVar6;
        }
        else {
          *(int *)(unaff_EBP + -0x74) =
               iVar2 * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) + iVar6 * 2;
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019de7c:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
        }
        *(int *)(unaff_EBP + -0x74) =
             iVar2 * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) + iVar6 * 4;
      }
      iVar6 = 0;
      if (0 < *(int *)(unaff_EDI + 0xa0)) break;
      goto LAB_0019df3c;
    }
    *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x6c);
    *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EBP + -0x6c) + 1;
    uVar1 = *(uint *)(unaff_EDI + 0x1c);
    if (3 < uVar1) {
      if (uVar1 != 4) {
LAB_0019dd74:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      *(int *)(unaff_EBP + -0x70) =
           *(int *)(unaff_EBP + -0x7c) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
           unaff_EBX * 4;
      goto LAB_0019dd81;
    }
    if (uVar1 < 2) {
      if (uVar1 != 1) goto LAB_0019dd74;
      *(int *)(unaff_EBP + -0x70) =
           *(int *)(unaff_EBP + -0x7c) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
           unaff_EBX;
    }
    else {
      *(int *)(unaff_EBP + -0x70) =
           *(int *)(unaff_EBP + -0x7c) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
           unaff_EBX * 2;
    }
  } while( true );
LAB_0019de98:
  *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EDI + 0xb0);
  iVar2 = *(int *)(unaff_EDI + 0x98);
  uVar1 = *(uint *)(unaff_EDI + 0x1c);
  if (uVar1 < 4) {
    if (uVar1 < 2) {
      if (uVar1 != 1) goto LAB_0019df1c;
      puVar3 = *(undefined1 **)(unaff_EBP + -0x74);
      while (iVar2 = iVar2 + -1, iVar2 != -1) {
        *puVar3 = *(undefined1 *)(unaff_EBP + -0x80);
        puVar3 = puVar3 + 1;
      }
    }
    else {
      puVar4 = *(undefined2 **)(unaff_EBP + -0x74);
      while (iVar2 = iVar2 + -1, iVar2 != -1) {
        *puVar4 = *(undefined2 *)(unaff_EBP + -0x80);
        puVar4 = puVar4 + 1;
      }
    }
  }
  else {
    if (uVar1 != 4) {
LAB_0019df1c:
                    /* WARNING: Subroutine does not return */
      _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
    }
    puVar5 = *(undefined4 **)(unaff_EBP + -0x74);
    while (iVar2 = iVar2 + -1, iVar2 != -1) {
      *puVar5 = *(undefined4 *)(unaff_EBP + -0x80);
      puVar5 = puVar5 + 1;
    }
  }
  *(int *)(unaff_EBP + -0x74) = *(int *)(unaff_EBP + -0x74) + *(int *)(unaff_EDI + 0x10);
  iVar6 = iVar6 + 1;
  if (*(int *)(unaff_EDI + 0xa0) <= iVar6) {
LAB_0019df3c:
    FUN_0019ba18();
    FUN_0019c898();
    return;
  }
  goto LAB_0019de98;
}

