/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001593be */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001593be(void)

{
  int unaff_ESI;
  
  LOCK();
  *(undefined4 *)(unaff_ESI + 0x20) = 0;
  UNLOCK();
  _splx();
  __c_thread_handoff_hits = __c_thread_handoff_hits + 1;
  return 1;
}

