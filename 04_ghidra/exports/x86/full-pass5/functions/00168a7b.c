/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00168a7b */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_00168a7b(void)

{
  int unaff_EBX;
  
  if (*(int *)(unaff_EBX + 0x30) == 0) {
    *(undefined4 *)(unaff_EBX + 0x30) = _active_stacks;
  }
  LOCK();
  *(undefined4 *)(unaff_EBX + 0x20) = 0;
  UNLOCK();
  _splx();
  return 0;
}

