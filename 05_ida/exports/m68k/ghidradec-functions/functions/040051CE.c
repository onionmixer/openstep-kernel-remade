
void _create_unix_stack(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uStack_8;
  
  *(int *)(*_active_u + 0x82) = param_2;
  uVar1 = ~_page_mask & _page_mask + *(int *)((int)_active_u + 0x26e);
  uStack_8 = ~_page_mask & param_2 - uVar1;
  _vm_map_find(param_1,0,0,&uStack_8,uVar1,0);
  return;
}
