/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019bb36 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019bb36(void)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  byte *pbVar5;
  uint *puVar6;
  int unaff_EBP;
  uint uVar7;
  int unaff_EDI;
  
LAB_0019bb39:
  uVar7 = 0;
  do {
    sVar4 = (short)*(undefined4 *)(unaff_EDI + 0xb0);
    if (**(short **)(unaff_EBP + -8) == sVar4) {
      **(short **)(unaff_EBP + -8) = *(short *)(unaff_EDI + 0xb4);
    }
    else {
      **(short **)(unaff_EBP + -8) = sVar4;
    }
    *(int *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -8) + 2;
    uVar7 = uVar7 + 1;
  } while (uVar7 < 8);
  do {
    while( true ) {
      *(int *)(unaff_EBP + -4) = *(int *)(unaff_EBP + -4) + 1;
      if (*(int *)(unaff_EBP + -0xc) <= *(int *)(unaff_EBP + -4)) {
        return;
      }
      uVar7 = *(uint *)(unaff_EDI + 0x1c);
      if (uVar7 < 4) break;
      if (uVar7 != 4) {
LAB_0019bbb8:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_FlipCursor__bogus_bits_001e4752);
      }
      puVar6 = (uint *)(*(int *)(unaff_EBP + -4) * *(int *)(unaff_EDI + 0x10) +
                        *(int *)(unaff_EDI + 0x18) + *(int *)(unaff_EBP + -0x10) * 4);
      uVar7 = 0;
      do {
        uVar2 = *puVar6;
        uVar3 = *(uint *)(unaff_EDI + 0xb0);
        *(uint *)(unaff_EBP + -0x18) = uVar3;
        if ((uVar2 & 0xffffff) == (uVar3 & 0xffffff)) {
          *puVar6 = *(uint *)(unaff_EDI + 0xb4);
        }
        else {
          *puVar6 = *(uint *)(unaff_EBP + -0x18);
        }
        puVar6 = puVar6 + 1;
        uVar7 = uVar7 + 1;
      } while (uVar7 < 8);
    }
    if (1 < uVar7) break;
    if (uVar7 != 1) goto LAB_0019bbb8;
    pbVar5 = (byte *)(*(int *)(unaff_EBP + -0x10) +
                     *(int *)(unaff_EBP + -4) * *(int *)(unaff_EDI + 0x10) +
                     *(int *)(unaff_EDI + 0x18));
    uVar7 = 0;
    do {
      bVar1 = *pbVar5;
      uVar2 = *(uint *)(unaff_EDI + 0xb0);
      *(uint *)(unaff_EBP + -0x18) = uVar2;
      if ((uint)bVar1 == (uVar2 & 0xffff)) {
        *pbVar5 = *(byte *)(unaff_EDI + 0xb4);
      }
      else {
        *pbVar5 = *(byte *)(unaff_EBP + -0x18);
      }
      pbVar5 = pbVar5 + 1;
      uVar7 = uVar7 + 1;
    } while (uVar7 < 8);
  } while( true );
  if (uVar7 < 4) {
    if (uVar7 < 2) {
      if (uVar7 != 1) goto LAB_0019bb2c;
      *(int *)(unaff_EBP + -8) =
           *(int *)(unaff_EBP + -4) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
           *(int *)(unaff_EBP + -0x10);
    }
    else {
      *(int *)(unaff_EBP + -8) =
           *(int *)(unaff_EBP + -4) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
           *(int *)(unaff_EBP + -0x10) * 2;
    }
  }
  else {
    if (uVar7 != 4) {
LAB_0019bb2c:
                    /* WARNING: Subroutine does not return */
      _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
    }
    *(int *)(unaff_EBP + -8) =
         *(int *)(unaff_EBP + -4) * *(int *)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x18) +
         *(int *)(unaff_EBP + -0x10) * 4;
  }
  goto LAB_0019bb39;
}

