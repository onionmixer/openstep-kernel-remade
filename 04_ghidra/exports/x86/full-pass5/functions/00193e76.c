/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00193e76 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00193e76(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 in_CR3;
  
  for (; 0 < unaff_ESI; unaff_ESI = unaff_ESI + -0x1000) {
    puVar1 = (undefined4 *)_pmap_pt_entry(_kernel_pmap);
    puVar2 = (undefined4 *)_pmap_pt_entry(_kernel_pmap,unaff_EDI);
    *puVar2 = *puVar1;
    *puVar1 = 0;
    *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 0x1000;
    unaff_EDI = unaff_EDI + 0x1000;
  }
  return in_CR3;
}

