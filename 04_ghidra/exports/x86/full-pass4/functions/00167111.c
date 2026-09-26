/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00167111 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00167111(void)

{
  int unaff_EBP;
  int unaff_ESI;
  
  _task_deallocate();
  if ((*(byte *)(unaff_ESI + 0x4d) & 1) == 0) {
    _splsched();
    _stack_free();
    _splx(*(undefined4 *)(unaff_EBP + -0x14));
    __thread_deallocate_stack = __thread_deallocate_stack + 1;
  }
  if (*(int *)(unaff_ESI + 0x30) != 0) {
    _freeStack();
  }
  _pcb_terminate();
  __nthreads = __nthreads + -1;
  _uthread_free(*(undefined4 *)(unaff_ESI + 0x84));
  _zfree(_thread_zone);
  return;
}

