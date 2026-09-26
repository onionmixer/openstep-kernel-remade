
void _vsunlock(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  if (param_3 != 0) {
    uVar1 = *(undefined4 *)(*(int *)(*(int *)(_active_threads + 0xc) + 8) + 0x20);
    uVar4 = ~_page_mask & param_1;
    if (uVar4 < (~_page_mask & param_2 + param_1 + _page_mask)) {
      do {
        uVar2 = _pmap_extract(uVar1,uVar4);
        iVar3 = _vm_phys_to_vm_page(uVar2);
        *(byte *)(iVar3 + 0x1e) = *(byte *)(iVar3 + 0x1e) & 0xfb;
        uVar4 = _page_size + uVar4;
      } while (uVar4 < (~_page_mask & _page_mask + param_2 + param_1));
    }
  }
  _vm_map_pageable(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),~_page_mask & param_1,
                   ~_page_mask & _page_mask + param_2 + param_1,1);
  return;
}

