/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011891c */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0011891c(void)

{
  int *piVar1;
  int *unaff_EBX;
  int *unaff_ESI;
  
  do {
    piVar1 = (int *)unaff_EBX[5];
    if (piVar1 == unaff_ESI) {
      unaff_EBX[5] = unaff_ESI[5];
      unaff_ESI[5] = 0;
      *(byte *)(*unaff_ESI + 6) = *(byte *)(*unaff_ESI + 6) & 0xfd;
      return;
    }
    unaff_EBX = piVar1;
  } while (piVar1 != (int *)0x0);
                    /* WARNING: Subroutine does not return */
  _panic(s_unp_disconnect_001db411);
}

