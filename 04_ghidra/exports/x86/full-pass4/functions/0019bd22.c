/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019bd22 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019bd22(void)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  undefined2 *puVar5;
  
  do {
    while( true ) {
      unaff_ESI = unaff_ESI + 1;
      if (*(int *)(unaff_EBP + -4) <= unaff_ESI) {
        return;
      }
      uVar1 = *(uint *)(unaff_EBX + 0x1c);
      if (3 < uVar1) break;
      if (uVar1 < 2) {
        if (uVar1 != 1) goto LAB_0019bd18;
        puVar2 = (undefined1 *)
                 (unaff_ESI * *(int *)(unaff_EBX + 0x10) + *(int *)(unaff_EBX + 0x18) +
                 *(int *)(unaff_EBP + -0xc));
        iVar4 = 7;
        do {
          *puVar2 = *(undefined1 *)(unaff_EBX + 0xb0);
          puVar2 = puVar2 + 1;
          iVar4 = iVar4 + -1;
        } while (-1 < iVar4);
      }
      else {
        if (uVar1 < 4) {
          if (uVar1 < 2) {
            if (uVar1 != 1) goto LAB_0019bccc;
            puVar5 = (undefined2 *)
                     (*(int *)(unaff_EBP + -0xc) +
                     unaff_ESI * *(int *)(unaff_EBX + 0x10) + *(int *)(unaff_EBX + 0x18));
          }
          else {
            puVar5 = (undefined2 *)
                     (unaff_ESI * *(int *)(unaff_EBX + 0x10) + *(int *)(unaff_EBX + 0x18) +
                     *(int *)(unaff_EBP + -0xc) * 2);
          }
        }
        else {
          if (uVar1 != 4) {
LAB_0019bccc:
                    /* WARNING: Subroutine does not return */
            _panic(s_FBConsole_PixelAddress__bogus_bi_001e4704);
          }
          puVar5 = (undefined2 *)
                   (unaff_ESI * *(int *)(unaff_EBX + 0x10) + *(int *)(unaff_EBX + 0x18) +
                   *(int *)(unaff_EBP + -0xc) * 4);
        }
        iVar4 = 7;
        do {
          *puVar5 = *(undefined2 *)(unaff_EBX + 0xb0);
          puVar5 = puVar5 + 1;
          iVar4 = iVar4 + -1;
        } while (-1 < iVar4);
      }
    }
    if (uVar1 != 4) {
LAB_0019bd18:
                    /* WARNING: Subroutine does not return */
      _panic(s_FBConsole_Erase__bogus_bits_per_p_001e477d);
    }
    puVar3 = (undefined4 *)
             (unaff_ESI * *(int *)(unaff_EBX + 0x10) + *(int *)(unaff_EBX + 0x18) +
             *(int *)(unaff_EBP + -0xc) * 4);
    iVar4 = 7;
    do {
      *puVar3 = *(undefined4 *)(unaff_EBX + 0xb0);
      puVar3 = puVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (-1 < iVar4);
  } while( true );
}

