/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017bd68 */

void _vslock(uint param_1,int param_2)

{
  _vm_map_pageable(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc),param_1 & ~_page_mask,
                   param_1 + param_2 + _page_mask & ~_page_mask,0);
  return;
}

