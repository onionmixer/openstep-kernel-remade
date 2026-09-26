/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00118a92 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00118a92(void)

{
  short *psVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  int unaff_EDI;
  
  do {
    iVar2 = *unaff_ESI;
    *(int *)(*(int *)(_active_u + 0x150) + unaff_EDI * 4) = iVar2;
    psVar1 = (short *)(iVar2 + 0x10);
    *psVar1 = *psVar1 + -1;
    _unp_rights = _unp_rights + -1;
    *unaff_ESI = unaff_EDI;
    unaff_ESI = unaff_ESI + 1;
    unaff_EBX = unaff_EBX + 1;
    if (*(int *)(unaff_EBP + -4) <= unaff_EBX) {
      return 0;
    }
    unaff_EDI = _ufalloc();
  } while (-1 < unaff_EDI);
                    /* WARNING: Subroutine does not return */
  _panic(s_unp_externalize_001db420);
}

