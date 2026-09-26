
undefined4 _vm_inherit(int param_1,uint param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else {
    uVar1 = _vm_map_inherit(param_1,~_page_mask & param_2,
                            ~_page_mask & _page_mask + param_3 + param_2,param_4);
  }
  return uVar1;
}
