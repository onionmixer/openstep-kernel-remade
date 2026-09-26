/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00173e90 */

void _kmem_free(undefined4 param_1,uint param_2,int param_3)

{
  _vm_map_remove(param_1,param_2 & ~_page_mask,param_2 + param_3 + _page_mask & ~_page_mask);
  return;
}

