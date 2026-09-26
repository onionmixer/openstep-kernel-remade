/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019dc4a */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019dc4a(void)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  undefined4 *puVar4;
  undefined4 unaff_EBX;
  int iVar5;
  int unaff_EBP;
  int unaff_ESI;
  int iVar6;
  int unaff_EDI;
  
LAB_0019dc4d:
  do {
    uVar1 = *(uint *)(unaff_EDI + 0x1c);
    if (uVar1 < 4) {
      if (uVar1 < 2) {
        if (uVar1 != 1) goto LAB_0019dcc4;
        puVar2 = *(undefined1 **)(unaff_EBP + -0x68);
        *(undefined4 *)(unaff_EBP + -0x80) = 1;
        do {
          *puVar2 = (char)unaff_EBX;
          puVar2 = puVar2 + 1;
          *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + -1;
        } while (*(int *)(unaff_EBP + -0x80) != -1);
      }
      else {
        puVar3 = *(undefined2 **)(unaff_EBP + -0x68);
        *(undefined4 *)(unaff_EBP + -0x80) = 1;
        do {
          *puVar3 = (short)unaff_EBX;
          puVar3 = puVar3 + 1;
          *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + -1;
        } while (*(int *)(unaff_EBP + -0x80) != -1);
      }
    }
    else {
      if (uVar1 != 4) {
LAB_0019dcc4:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
      }
      puVar4 = *(undefined4 **)(unaff_EBP + -0x68);
      *(undefined4 *)(unaff_EBP + -0x80) = 1;
      do {
        *puVar4 = unaff_EBX;
        puVar4 = puVar4 + 1;
        *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + -1;
      } while (*(int *)(unaff_EBP + -0x80) != -1);
    }
    *(int *)(unaff_EBP + -100) = *(int *)(unaff_EBP + -100) + -1;
    if (*(int *)(unaff_EBP + -100) == -1) {
      iVar5 = *(int *)(unaff_EBP + 0xc) + *(int *)(unaff_EDI + 0x8c) + 2;
      *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EDI + 0x90) + -3;
      *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EDI + 0xb4);
      iVar6 = *(int *)(unaff_EBP + 0x10) + 5;
      break;
    }
    *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x60);
    *(int *)(unaff_EBP + -0x60) = *(int *)(unaff_EBP + -0x60) + 1;
    uVar1 = *(uint *)(unaff_EDI + 0x1c);
    if (3 < uVar1) {
      if (uVar1 != 4) {
LAB_0019dc40:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      *(int *)(unaff_EBP + -0x68) =
           *(int *)(unaff_EBP + -0x80) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
           unaff_ESI * 4;
      goto LAB_0019dc4d;
    }
    if (uVar1 < 2) {
      if (uVar1 != 1) goto LAB_0019dc40;
      *(int *)(unaff_EBP + -0x68) =
           *(int *)(unaff_EBP + -0x80) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
           unaff_ESI;
    }
    else {
      *(int *)(unaff_EBP + -0x68) =
           *(int *)(unaff_EBP + -0x80) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
           unaff_ESI * 2;
    }
  } while( true );
joined_r0x0019dd08:
  if (iVar6 == -1) goto LAB_0019de1b;
  *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x6c);
  *(int *)(unaff_EBP + -0x6c) = *(int *)(unaff_EBP + -0x6c) + 1;
  uVar1 = *(uint *)(unaff_EDI + 0x1c);
  if (uVar1 < 4) {
    if (uVar1 < 2) {
      if (uVar1 != 1) goto LAB_0019dd74;
      *(int *)(unaff_EBP + -0x70) =
           *(int *)(unaff_EBP + -0x7c) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
           iVar5;
    }
    else {
      *(int *)(unaff_EBP + -0x70) =
           *(int *)(unaff_EBP + -0x7c) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
           iVar5 * 2;
    }
  }
  else {
    if (uVar1 != 4) {
LAB_0019dd74:
                    /* WARNING: Subroutine does not return */
      _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
    }
    *(int *)(unaff_EBP + -0x70) =
         *(int *)(unaff_EBP + -0x7c) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
         iVar5 * 4;
  }
  uVar1 = *(uint *)(unaff_EDI + 0x1c);
  if (uVar1 < 4) {
    if (uVar1 < 2) {
      if (uVar1 != 1) goto LAB_0019de04;
      puVar2 = *(undefined1 **)(unaff_EBP + -0x70);
      *(undefined4 *)(unaff_EBP + -0x7c) = 0;
      do {
        *puVar2 = *(undefined1 *)(unaff_EBP + -0x80);
        puVar2 = puVar2 + 1;
        *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x7c) + -1;
      } while (*(int *)(unaff_EBP + -0x7c) != -1);
    }
    else {
      puVar3 = *(undefined2 **)(unaff_EBP + -0x70);
      *(undefined4 *)(unaff_EBP + -0x7c) = 0;
      do {
        *puVar3 = *(undefined2 *)(unaff_EBP + -0x80);
        puVar3 = puVar3 + 1;
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
    puVar4 = *(undefined4 **)(unaff_EBP + -0x70);
    *(undefined4 *)(unaff_EBP + -0x7c) = 0;
    do {
      *puVar4 = *(undefined4 *)(unaff_EBP + -0x80);
      puVar4 = puVar4 + 1;
      *(int *)(unaff_EBP + -0x7c) = *(int *)(unaff_EBP + -0x7c) + -1;
    } while (*(int *)(unaff_EBP + -0x7c) != -1);
  }
  iVar6 = iVar6 + -1;
  goto joined_r0x0019dd08;
LAB_0019de1b:
  iVar6 = *(int *)(unaff_EDI + 0x8c);
  iVar5 = *(int *)(unaff_EDI + 0x90);
  uVar1 = *(uint *)(unaff_EDI + 0x1c);
  if (uVar1 < 4) {
    if (uVar1 < 2) {
      if (uVar1 != 1) goto LAB_0019de7c;
      *(int *)(unaff_EBP + -0x74) =
           iVar5 * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) + iVar6;
    }
    else {
      *(int *)(unaff_EBP + -0x74) =
           iVar5 * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) + iVar6 * 2;
    }
  }
  else {
    if (uVar1 != 4) {
LAB_0019de7c:
                    /* WARNING: Subroutine does not return */
      _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
    }
    *(int *)(unaff_EBP + -0x74) =
         iVar5 * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) + iVar6 * 4;
  }
  iVar6 = 0;
  if (0 < *(int *)(unaff_EDI + 0xa0)) {
    do {
      *(undefined4 *)(unaff_EBP + -0x80) = *(undefined4 *)(unaff_EDI + 0xb0);
      iVar5 = *(int *)(unaff_EDI + 0x98);
      uVar1 = *(uint *)(unaff_EDI + 0x1c);
      if (uVar1 < 4) {
        if (uVar1 < 2) {
          if (uVar1 != 1) goto LAB_0019df1c;
          puVar2 = *(undefined1 **)(unaff_EBP + -0x74);
          while (iVar5 = iVar5 + -1, iVar5 != -1) {
            *puVar2 = *(undefined1 *)(unaff_EBP + -0x80);
            puVar2 = puVar2 + 1;
          }
        }
        else {
          puVar3 = *(undefined2 **)(unaff_EBP + -0x74);
          while (iVar5 = iVar5 + -1, iVar5 != -1) {
            *puVar3 = *(undefined2 *)(unaff_EBP + -0x80);
            puVar3 = puVar3 + 1;
          }
        }
      }
      else {
        if (uVar1 != 4) {
LAB_0019df1c:
                    /* WARNING: Subroutine does not return */
          _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
        }
        puVar4 = *(undefined4 **)(unaff_EBP + -0x74);
        while (iVar5 = iVar5 + -1, iVar5 != -1) {
          *puVar4 = *(undefined4 *)(unaff_EBP + -0x80);
          puVar4 = puVar4 + 1;
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

