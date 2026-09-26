/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011e7c2 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011e7c2(void)

{
  short sVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EBP;
  
  sVar1 = *(short *)(unaff_EBX + 6);
  *(short *)(unaff_EBX + 6) = sVar1 + -1;
  if (sVar1 == 1) {
    (**(code **)(*(int *)(unaff_EBX + 0x1c) + 0x4c))();
  }
  iVar2 = *(int *)(unaff_EBP + -0x24);
  if (iVar2 != 0) {
    if (*(short *)(iVar2 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vn_rele_001db786);
    }
    sVar1 = *(short *)(iVar2 + 6);
    *(short *)(iVar2 + 6) = sVar1 + -1;
    if (sVar1 == 1) {
      (**(code **)(*(int *)(iVar2 + 0x1c) + 0x4c))(iVar2);
    }
  }
  return;
}

