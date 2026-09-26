/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017ae2b */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_0017ae2b(void)

{
  int *piVar1;
  int iVar2;
  uint unaff_EBX;
  int unaff_ESI;
  int *unaff_EDI;
  
  *(int **)(unaff_ESI + 0x14) = unaff_EDI;
  *(uint *)(unaff_ESI + 0x18) = unaff_EBX;
  piVar1 = (int *)(_vm_page_buckets +
                  ((unaff_EBX >> ((byte)_page_shift & 0x1f)) + (int)unaff_EDI & __vm_page_hash_mask)
                  * 8);
  _splimp();
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  *(int *)(unaff_ESI + 0x10) = piVar1[1];
  piVar1[1] = unaff_ESI;
  LOCK();
  *piVar1 = 0;
  UNLOCK();
  _splx();
  piVar1 = (int *)unaff_EDI[1];
  if (unaff_EDI == piVar1) {
    *unaff_EDI = unaff_ESI;
  }
  else {
    piVar1[2] = unaff_ESI;
  }
  *(int **)(unaff_ESI + 0xc) = piVar1;
  *(int **)(unaff_ESI + 8) = unaff_EDI;
  unaff_EDI[1] = unaff_ESI;
  *(byte *)(unaff_ESI + 0x20) = *(byte *)(unaff_ESI + 0x20) | 4;
  *(short *)((int)unaff_EDI + 0x1a) = *(short *)((int)unaff_EDI + 0x1a) + 1;
  return;
}

