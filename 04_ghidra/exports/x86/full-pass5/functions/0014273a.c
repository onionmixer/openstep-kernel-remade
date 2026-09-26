/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014273a */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0014273a(void)

{
  int unaff_EBX;
  int unaff_EBP;
  uint unaff_ESI;
  uint unaff_EDI;
  
  while( true ) {
    while( true ) {
      if (unaff_EBX == 0) {
        return 0;
      }
      if ((((*(byte *)(unaff_EBP + 0x10) & 1) == 0) ||
          (*(int *)(unaff_EBX + 0xc) == *(int *)(*(int *)(unaff_EBP + 0xc) + 0xc))) &&
         (((*(byte *)(unaff_EBP + 0x10) & 2) == 0 ||
          (*(int *)(unaff_EBX + 0xc) != *(int *)(*(int *)(unaff_EBP + 0xc) + 0xc))))) break;
      **(int **)(unaff_EBP + 0x14) = unaff_EBX + 0x14;
      unaff_EBX = *(int *)(unaff_EBX + 0x14);
      **(int **)(unaff_EBP + 0x18) = unaff_EBX;
    }
    if (((*(uint *)(unaff_EBX + 8) == 0xffffffff) || (unaff_EDI <= *(uint *)(unaff_EBX + 8))) &&
       ((unaff_ESI == 0xffffffff || (*(uint *)(unaff_EBX + 4) <= unaff_ESI)))) break;
    if ((((*(byte *)(unaff_EBP + 0x10) & 1) != 0) && (unaff_ESI != 0xffffffff)) &&
       (unaff_ESI < *(uint *)(unaff_EBX + 4))) {
      return 0;
    }
    **(int **)(unaff_EBP + 0x14) = unaff_EBX + 0x14;
    unaff_EBX = *(int *)(unaff_EBX + 0x14);
    **(int **)(unaff_EBP + 0x18) = unaff_EBX;
  }
  if ((*(uint *)(unaff_EBX + 4) == unaff_EDI) && (*(uint *)(unaff_EBX + 8) == unaff_ESI)) {
    return 1;
  }
  if (((*(uint *)(unaff_EBX + 4) <= unaff_EDI) && (unaff_ESI != 0xffffffff)) &&
     ((unaff_ESI <= *(uint *)(unaff_EBX + 8) || (*(uint *)(unaff_EBX + 8) == 0xffffffff)))) {
    return 2;
  }
  if ((unaff_EDI <= *(uint *)(unaff_EBX + 4)) &&
     ((unaff_ESI == 0xffffffff ||
      ((*(uint *)(unaff_EBX + 8) != 0xffffffff && (*(uint *)(unaff_EBX + 8) <= unaff_ESI)))))) {
    return 3;
  }
  if ((*(uint *)(unaff_EBX + 4) < unaff_EDI) &&
     ((unaff_EDI <= *(uint *)(unaff_EBX + 8) || (*(uint *)(unaff_EBX + 8) == 0xffffffff)))) {
    return 4;
  }
  if (((unaff_EDI < *(uint *)(unaff_EBX + 4)) && (unaff_ESI != 0xffffffff)) &&
     ((unaff_ESI < *(uint *)(unaff_EBX + 8) || (*(uint *)(unaff_EBX + 8) == 0xffffffff)))) {
    return 5;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_lf_findoverlap__default_001de08a);
}

