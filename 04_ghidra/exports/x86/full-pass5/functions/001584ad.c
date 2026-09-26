/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001584ad */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

undefined4 __analysis_fragment_001584ad(void)

{
  int unaff_EBP;
  
  _ipc_kmsg_copyin_from_kernel();
  _ipc_mqueue_send(*(undefined4 *)(unaff_EBP + -4),0x10000,0);
  return 0;
}

