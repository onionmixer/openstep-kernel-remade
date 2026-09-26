
int _chgprot(uint param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _vm_map_protect(*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),~_page_mask & param_1
                          ,~_page_mask & param_1 + 1 + _page_mask,param_2,0);
  return -(int)-(iVar1 == 0);
}

