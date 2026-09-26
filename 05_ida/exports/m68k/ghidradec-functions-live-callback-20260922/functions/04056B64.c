
void _kern_serv_unwire_range(undefined4 param_1,uint param_2,int param_3)

{
  _vm_map_pageable(*(undefined4 *)(_kernel_task + 8),~_page_mask & param_2,
                   ~_page_mask & _page_mask + param_3 + param_2,1);
  return;
}

