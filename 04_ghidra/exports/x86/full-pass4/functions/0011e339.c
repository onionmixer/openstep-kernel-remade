/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011e339 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

int __analysis_fragment_0011e339(void)

{
  short sVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int *unaff_EDI;
  
  sVar1 = *(short *)(unaff_EBX + 6);
  *(short *)(unaff_EBX + 6) = sVar1 + -1;
  if (sVar1 == 1) {
    (**(code **)(*(int *)(unaff_EBX + 0x1c) + 0x4c))();
  }
  if (unaff_ESI == 0) {
    if (**(int **)(unaff_EBP + 0x10) == 2) {
      iVar2 = *unaff_EDI;
      if (iVar2 == 0) {
        *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1c);
        unaff_ESI = (**(code **)(*(int *)(unaff_EBP + -0x14) + 0x34))
                              (*(int *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -8),
                               *(undefined4 *)(unaff_EBP + 0x10));
      }
      else {
        if (*(short *)(iVar2 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_vn_rele_001db786);
        }
        sVar1 = *(short *)(iVar2 + 6);
        *(short *)(iVar2 + 6) = sVar1 + -1;
        if (sVar1 == 1) {
          (**(code **)(*(int *)(iVar2 + 0x1c) + 0x4c))(iVar2);
        }
        unaff_ESI = 0x11;
      }
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(*(int *)(unaff_EBP + -0x10) + 0x1c);
      unaff_ESI = (**(code **)(*(int *)(unaff_EBP + -0x14) + 0x24))
                            (*(int *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -8),
                             *(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14),
                             *(undefined4 *)(unaff_EBP + 0x18));
    }
  }
  _pn_free();
  iVar2 = *(int *)(unaff_EBP + -0x10);
  if (*(short *)(iVar2 + 6) == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_vn_rele_001db786);
  }
  sVar1 = *(short *)(iVar2 + 6);
  *(short *)(iVar2 + 6) = sVar1 + -1;
  if (sVar1 == 1) {
    (**(code **)(*(int *)(iVar2 + 0x1c) + 0x4c))(iVar2);
  }
  return unaff_ESI;
}

