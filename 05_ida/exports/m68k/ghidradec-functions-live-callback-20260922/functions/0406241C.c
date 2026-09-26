
undefined4 _vm_allocate(int param_1,uint *param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 4;
  }
  else if (param_3 == 0) {
    *param_2 = 0;
    uVar1 = 0;
  }
  else {
    if (param_4 == 0) {
      *param_2 = ~_page_mask & *param_2;
    }
    else {
      *param_2 = *(uint *)(param_1 + 0x10);
    }
    uVar1 = _vm_map_find(param_1,0,0,param_2,~_page_mask & _page_mask + param_3,param_4);
  }
  return uVar1;
}

