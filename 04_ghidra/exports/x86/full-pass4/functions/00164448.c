/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00164448 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00164448(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  int unaff_ESI;
  
  LOCK();
  *(undefined4 *)(unaff_ESI + 0x100) = 0;
  UNLOCK();
  piVar1 = (int *)(*(int *)(*(int *)(unaff_EBP + 8) + 300) + 0x100);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  _choose_pset_thread(*(undefined4 *)(unaff_EBP + 8));
  return;
}

