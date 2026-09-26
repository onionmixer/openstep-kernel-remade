/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001745b4 */

void _kmem_free_wakeup(int param_1,uint param_2,int param_3)

{
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  _vm_map_delete(param_1,param_2 & ~_page_mask,param_3 + param_2 + _page_mask & ~_page_mask);
  _thread_wakeup_prim(param_1,0,0);
  _lock_done(param_1);
  return;
}

