/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019e149 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019e149(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint *unaff_EBX;
  int unaff_EBP;
  undefined4 *unaff_ESI;
  
  uVar1 = *(undefined4 *)(unaff_EBP + -4);
  iVar2 = *(int *)(unaff_EBP + -8);
  uVar3 = unaff_EBX[7];
  if (uVar3 < 4) {
    if (uVar3 < 2) {
      if (uVar3 != 1) goto LAB_0019e1b4;
      while (iVar2 = iVar2 + -1, iVar2 != -1) {
        *(char *)unaff_ESI = (char)uVar1;
        unaff_ESI = (undefined4 *)((int)unaff_ESI + 1);
      }
    }
    else {
      while (iVar2 = iVar2 + -1, iVar2 != -1) {
        *(short *)unaff_ESI = (short)uVar1;
        unaff_ESI = (undefined4 *)((int)unaff_ESI + 2);
      }
    }
  }
  else {
    if (uVar3 != 4) {
LAB_0019e1b4:
                    /* WARNING: Subroutine does not return */
      _panic(s_FBConsole_Fill__bogus_bitsPerPix_001e472f);
    }
    while (iVar2 = iVar2 + -1, iVar2 != -1) {
      *unaff_ESI = uVar1;
      unaff_ESI = unaff_ESI + 1;
    }
  }
  uVar3 = *(uint *)(unaff_EBP + 0xc);
  *unaff_EBX = uVar3;
  if (uVar3 != 2) {
    if (uVar3 < 3) {
      if (uVar3 != 1) {
LAB_0019e228:
                    /* WARNING: Subroutine does not return */
        _panic(s_FBConsole_FBInitConsole__can_t_i_001e47ec);
      }
    }
    else if (*(int *)(unaff_EBP + 0xc) != 3) goto LAB_0019e228;
    FUN_0019d254();
  }
  return;
}

