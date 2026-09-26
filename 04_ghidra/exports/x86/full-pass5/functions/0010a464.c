/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010a464 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0010a464(void)

{
  int *piVar1;
  int iVar2;
  int *unaff_ESI;
  undefined1 unaff_DI;
  
  while ((piVar1 = (int *)*unaff_ESI, piVar1[1] < 1 || (unaff_ESI[5] < 1))) {
    unaff_ESI[1] = unaff_ESI[1] + -1;
    *unaff_ESI = *unaff_ESI + 8;
    if (unaff_ESI[1] == 0) {
                    /* WARNING: Subroutine does not return */
      _panic(s_ureadc_001daa4e);
    }
  }
  iVar2 = unaff_ESI[3];
  if (iVar2 == 1) {
    *(undefined1 *)*piVar1 = unaff_DI;
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 != 0) goto LAB_0010a4c0;
      iVar2 = _subyte(*piVar1);
    }
    else {
      if (iVar2 != 2) goto LAB_0010a4c0;
      iVar2 = _suibyte(*piVar1);
    }
    if (iVar2 < 0) {
      return 0xe;
    }
  }
LAB_0010a4c0:
  *piVar1 = *piVar1 + 1;
  piVar1[1] = piVar1[1] + -1;
  unaff_ESI[5] = unaff_ESI[5] + -1;
  unaff_ESI[2] = unaff_ESI[2] + 1;
  return 0;
}

