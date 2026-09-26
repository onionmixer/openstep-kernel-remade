
void _useracc(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 2;
  if (param_3 == 1) {
    uVar1 = 1;
  }
  _vm_map_check_protection
            (*(undefined4 *)(*(int *)(_active_threads + 0xc) + 8),~_page_mask & param_1,
             ~_page_mask & _page_mask + param_2 + param_1,uVar1);
  return;
}
