
void _vslock(uint param_1,int param_2)

{
  _vm_map_pageable(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),~_page_mask & param_1,
                   ~_page_mask & _page_mask + param_2 + param_1,0);
  return;
}

