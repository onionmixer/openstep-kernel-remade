/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00146efd */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

void __analysis_fragment_00146efd(void)

{
  int unaff_EBP;
  
  _ipc_soft_map = *(undefined4 *)(_ipc_soft_task + 0xc);
  _ipc_kernel_map = _kmem_suballoc(_kernel_map,unaff_EBP + -4,unaff_EBP + -8,_ipc_kernel_map_size);
  _ipc_host_init();
  return;
}

