/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017bd9c */

void _vsunlock(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_3 != 0) {
    uVar1 = *(undefined4 *)(*(int *)(*(int *)(_active_threads + 0xc) + 0xc) + 0x24);
    uVar4 = param_1 & ~_page_mask;
    if (uVar4 < (_page_mask + param_2 + param_1 & ~_page_mask)) {
      do {
        uVar2 = _pmap_extract(uVar1,uVar4);
        iVar3 = _vm_phys_to_vm_page(uVar2);
        *(byte *)(iVar3 + 0x1e) = *(byte *)(iVar3 + 0x1e) & 0xdf;
        uVar4 = uVar4 + _page_size;
      } while (uVar4 < (_page_mask + param_2 + param_1 & ~_page_mask));
    }
  }
  _vm_map_pageable(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 0xc),~_page_mask & param_1,
                   param_2 + param_1 + _page_mask & ~_page_mask,1);
  return;
}

