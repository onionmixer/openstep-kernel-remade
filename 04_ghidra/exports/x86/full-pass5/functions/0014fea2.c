/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014fea2 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0014fea2(void)

{
  int iVar1;
  int unaff_EBP;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + 4) = 0;
  iVar1 = *(int *)(unaff_EBP + 8);
  _ipc_entry_dealloc(iVar1,*(undefined4 *)(unaff_EBP + 0xc));
  LOCK();
  *(undefined4 *)(iVar1 + 8) = 0;
  UNLOCK();
  return 0;
}

