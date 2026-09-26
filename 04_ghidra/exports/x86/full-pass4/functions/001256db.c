/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001256db */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_001256db(void)

{
  size_t sVar1;
  void *pvVar2;
  int unaff_EBP;
  int unaff_ESI;
  
  sVar1 = *(size_t *)(unaff_EBP + -4);
  *(int *)(unaff_ESI + 4) = *(int *)(unaff_ESI + 4) - sVar1;
  *(short *)(unaff_ESI + 8) = *(short *)(unaff_ESI + 8) + *(short *)(unaff_EBP + -4);
  pvVar2 = (void *)(unaff_ESI + *(int *)(unaff_ESI + 4));
  _bcopy(*(void **)(unaff_EBP + 8),pvVar2,sVar1);
  *(undefined2 *)((int)pvVar2 + 2) = *(undefined2 *)(unaff_ESI + 8);
  *(undefined1 *)((int)pvVar2 + 9) = 1;
  _icmp_reflect(pvVar2,*(undefined4 *)(unaff_EBP + 0x14));
  _m_freem();
  return;
}

