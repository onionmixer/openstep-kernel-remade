/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0019e1be */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0019e1be(void)

{
  uint uVar1;
  uint *unaff_EBX;
  int unaff_EBP;
  
  uVar1 = *(uint *)(unaff_EBP + 0xc);
  *unaff_EBX = uVar1;
  if (uVar1 != 2) {
    if (uVar1 < 3) {
      if (uVar1 != 1) {
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

