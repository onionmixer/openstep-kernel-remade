/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019d03a */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019d03a(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined2 *puVar5;
  undefined4 *puVar6;
  undefined4 unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  
LAB_0019d03d:
  do {
    iVar1 = *(int *)(unaff_EBP + -0x58);
    uVar2 = *(uint *)(unaff_ESI + 0x1c);
    if (uVar2 < 4) {
      if (uVar2 < 2) {
        if (uVar2 != 1) goto LAB_0019d0ac;
        puVar4 = *(undefined1 **)(unaff_EBP + -0x60);
        while (iVar1 = iVar1 + -1, iVar1 != -1) {
          *puVar4 = (char)unaff_EBX;
          puVar4 = puVar4 + 1;
        }
      }
      else {
        puVar5 = *(undefined2 **)(unaff_EBP + -0x60);
        while (iVar1 = iVar1 + -1, iVar1 != -1) {
          *puVar5 = (short)unaff_EBX;
          puVar5 = puVar5 + 1;
        }
      }
    }
    else {
      if (uVar2 != 4) {
LAB_0019d0ac:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
      }
      puVar6 = *(undefined4 **)(unaff_EBP + -0x60);
      while (iVar1 = iVar1 + -1, iVar1 != -1) {
        *puVar6 = unaff_EBX;
        puVar6 = puVar6 + 1;
      }
    }
    *(int *)(unaff_EBP + -0x5c) = *(int *)(unaff_EBP + -0x5c) + -1;
    if (*(int *)(unaff_EBP + -0x5c) == -1) {
      *(int *)(unaff_ESI + 0x90) = *(int *)(unaff_ESI + 0x90) + 0x18;
      *(int *)(unaff_ESI + 0x9c) = *(int *)(unaff_ESI + 0x9c) + -2;
      *(int *)(unaff_ESI + 0xa0) = *(int *)(unaff_ESI + 0xa0) + -0x18;
      *(undefined4 *)(unaff_ESI + 0xa8) = *(undefined4 *)(unaff_EBP + -8);
      if (0 < *(int *)(unaff_EBP + -4)) {
        *(int *)(unaff_ESI + 0xa4) = *(int *)(unaff_EBP + -4) + -2;
        goto LAB_0019d236;
      }
      iVar3 = *(int *)(unaff_ESI + 0x8c);
      iVar1 = iVar3 + *(int *)(unaff_EBP + -8) * 8;
      *(int *)(unaff_EBP + -100) = *(int *)(unaff_ESI + 0x90) + *(int *)(unaff_ESI + 0xa4) * 0xc;
      *(int *)(unaff_EBP + -0x68) = *(int *)(unaff_ESI + 0x98) - (iVar1 - iVar3);
      *(undefined4 *)(unaff_EBP + -0x80) = 0;
      break;
    }
    iVar1 = *(int *)(unaff_EBP + -0x54);
    *(int *)(unaff_EBP + -0x54) = iVar1 + 1;
    uVar2 = *(uint *)(unaff_ESI + 0x1c);
    if (3 < uVar2) {
      if (uVar2 != 4) {
LAB_0019d030:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
      }
      *(int *)(unaff_EBP + -0x60) =
           iVar1 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) +
           *(int *)(unaff_EBP + -0x80) * 4;
      goto LAB_0019d03d;
    }
    if (uVar2 < 2) {
      if (uVar2 != 1) goto LAB_0019d030;
      *(int *)(unaff_EBP + -0x60) =
           iVar1 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) +
           *(int *)(unaff_EBP + -0x80);
    }
    else {
      *(int *)(unaff_EBP + -0x60) =
           iVar1 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) +
           *(int *)(unaff_EBP + -0x80) * 2;
    }
  } while( true );
LAB_0019d134:
  iVar3 = *(int *)(unaff_EBP + -100);
  *(int *)(unaff_EBP + -100) = iVar3 + 1;
  uVar2 = *(uint *)(unaff_ESI + 0x1c);
  if (uVar2 < 4) {
    if (uVar2 < 2) {
      if (uVar2 != 1) goto LAB_0019d18c;
      *(int *)(unaff_EBP + -0x6c) =
           iVar3 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar1;
    }
    else {
      *(int *)(unaff_EBP + -0x6c) =
           iVar3 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar1 * 2;
    }
  }
  else {
    if (uVar2 != 4) {
LAB_0019d18c:
                    /* WARNING: Subroutine does not return */
      _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
    }
    *(int *)(unaff_EBP + -0x6c) =
         iVar3 * *(int *)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + iVar1 * 4;
  }
  *(undefined4 *)(unaff_EBP + -0x7c) = *(undefined4 *)(unaff_ESI + 0xb0);
  iVar3 = *(int *)(unaff_EBP + -0x68);
  uVar2 = *(uint *)(unaff_ESI + 0x1c);
  if (uVar2 < 4) {
    if (uVar2 < 2) {
      if (uVar2 != 1) goto LAB_0019d21c;
      puVar4 = *(undefined1 **)(unaff_EBP + -0x6c);
      while (iVar3 = iVar3 + -1, iVar3 != -1) {
        *puVar4 = *(undefined1 *)(unaff_EBP + -0x7c);
        puVar4 = puVar4 + 1;
      }
    }
    else {
      puVar5 = *(undefined2 **)(unaff_EBP + -0x6c);
      while (iVar3 = iVar3 + -1, iVar3 != -1) {
        *puVar5 = *(undefined2 *)(unaff_EBP + -0x7c);
        puVar5 = puVar5 + 1;
      }
    }
  }
  else {
    if (uVar2 != 4) {
LAB_0019d21c:
                    /* WARNING: Subroutine does not return */
      _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
    }
    puVar6 = *(undefined4 **)(unaff_EBP + -0x6c);
    while (iVar3 = iVar3 + -1, iVar3 != -1) {
      *puVar6 = *(undefined4 *)(unaff_EBP + -0x7c);
      puVar6 = puVar6 + 1;
    }
  }
  *(int *)(unaff_EBP + -0x80) = *(int *)(unaff_EBP + -0x80) + 1;
  if (0xb < *(int *)(unaff_EBP + -0x80)) {
LAB_0019d236:
    FUN_0019ba18();
    *(undefined4 *)(unaff_ESI + 0xc0) = 1;
    return;
  }
  goto LAB_0019d134;
}

