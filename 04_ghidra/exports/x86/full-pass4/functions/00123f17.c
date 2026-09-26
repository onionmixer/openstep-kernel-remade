/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00123f17 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00123f17(void)

{
  undefined4 *unaff_EBX;
  int unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 *unaff_EDI;
  
  *(undefined2 *)((int)unaff_EBX + 10) = 2;
  _DAT_001e917c = _DAT_001e917c + -1;
  _DAT_001e9180 = _DAT_001e9180 + 1;
  _mfree = *unaff_EBX;
  *unaff_EBX = 0;
  unaff_EBX[1] = 0xc;
  _splx();
  if (unaff_EBX != (undefined4 *)0x0) {
    unaff_EBX[1] = 0xc;
    *(undefined2 *)(unaff_EBX + 2) = 4;
    *unaff_EBX = unaff_ESI;
    if (unaff_EBX != (undefined4 *)0x0) {
      *(undefined4 *)(unaff_EBX[1] + (int)unaff_EBX) = *(undefined4 *)(unaff_EBP + 8);
      unaff_EBX[0x1f] = 0;
      if (unaff_EDI[1] == 0) {
        *unaff_EDI = unaff_EBX;
      }
      else {
        *(undefined4 **)(unaff_EDI[1] + 0x7c) = unaff_EBX;
      }
      unaff_EDI[1] = unaff_EBX;
      unaff_EDI[2] = unaff_EDI[2] + 1;
      goto LAB_00123fac;
    }
  }
  unaff_EDI[4] = unaff_EDI[4] + 1;
  _m_freem();
LAB_00123fac:
  _splx();
  return;
}

