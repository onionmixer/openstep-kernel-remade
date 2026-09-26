/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016393e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_0016393e(void)

{
  int unaff_EBX;
  
  LOCK();
  *(undefined4 *)(unaff_EBX + 0x20) = 0;
  UNLOCK();
  __c_thread_invoke_hits = __c_thread_invoke_hits + 1;
  _spl0();
  _call_continuation();
  return 1;
}

