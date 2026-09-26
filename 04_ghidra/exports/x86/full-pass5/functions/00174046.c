/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00174046 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00174046(void)

{
  int iVar1;
  int unaff_EBP;
  int unaff_ESI;
  
  iVar1 = _vm_map_submap();
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_kmem_suballoc_3_001e0a36);
  }
  **(undefined4 **)(unaff_EBP + 0xc) = *(undefined4 *)(unaff_EBP + -4);
  **(int **)(unaff_EBP + 0x10) = unaff_ESI + *(int *)(unaff_EBP + -4);
  return *(undefined4 *)(unaff_EBP + -8);
}

