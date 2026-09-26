/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001189b8 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_001189b8(void)

{
  int *piVar1;
  int *unaff_EBX;
  int *unaff_ESI;
  int unaff_EDI;
  
  do {
    piVar1 = (int *)unaff_EBX[5];
    if (piVar1 == unaff_ESI) {
      unaff_EBX[5] = unaff_ESI[5];
      unaff_ESI[5] = 0;
      *(byte *)(*unaff_ESI + 6) = *(byte *)(*unaff_ESI + 6) & 0xfd;
      if (*(int *)(unaff_EDI + 0x10) != 0) {
        *(undefined4 *)(unaff_EDI + 8) = 0;
        _m_freem();
        _kfree();
        _sofree();
      }
      return;
    }
    unaff_EBX = piVar1;
  } while (piVar1 != (int *)0x0);
                    /* WARNING: Subroutine does not return */
  _panic(s_unp_disconnect_001db411);
}

