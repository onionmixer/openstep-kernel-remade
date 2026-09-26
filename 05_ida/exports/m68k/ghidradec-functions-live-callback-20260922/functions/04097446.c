
int _pmap_map(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,
             undefined4 param_6)

{
  int iVar1;
  
  iVar1 = _page_size;
  for (; param_2 < param_3; param_2 = iVar1 + param_2) {
    _pmap_enter_mapping(_kernel_pmap,param_1,param_2,param_4,0,param_5,param_6);
    param_1 = iVar1 + param_1;
  }
  return param_1;
}

