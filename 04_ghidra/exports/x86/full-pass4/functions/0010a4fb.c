/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010a4fb */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

uint __analysis_fragment_0010a4fb(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 *unaff_EDI;
  
  while (piVar1 = (int *)*unaff_EDI, piVar1[1] == 0) {
    *unaff_EDI = piVar1 + 2;
    iVar2 = unaff_EDI[1];
    unaff_EDI[1] = iVar2 + -1;
    if (iVar2 == 1) {
      return 0xffffffff;
    }
    if ((int)unaff_EDI[1] < 1) {
                    /* WARNING: Subroutine does not return */
      _panic(s_uwritec_001daa55);
    }
  }
  iVar2 = unaff_EDI[3];
  if (iVar2 == 1) {
    uVar3 = (uint)*(byte *)*piVar1;
  }
  else if (iVar2 < 2) {
    if (iVar2 != 0) {
LAB_0010a554:
                    /* WARNING: Subroutine does not return */
      _panic(s_uwritec__bogus_uio_segflg_001daa5d);
    }
    uVar3 = _fubyte();
  }
  else {
    if (iVar2 != 2) goto LAB_0010a554;
    uVar3 = _fuibyte();
  }
  if ((int)uVar3 < 0) {
    return 0xffffffff;
  }
  *piVar1 = *piVar1 + 1;
  piVar1[1] = piVar1[1] + -1;
  unaff_EDI[5] = unaff_EDI[5] + -1;
  unaff_EDI[2] = unaff_EDI[2] + 1;
  return uVar3 & 0xff;
}

