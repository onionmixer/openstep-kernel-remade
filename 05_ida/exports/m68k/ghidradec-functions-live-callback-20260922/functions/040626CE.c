
undefined4 _vm_write(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar1 = ~_page_mask & _page_mask + param_2;
  if ((param_2 == uVar1) && (uVar2 = ~_page_mask & _page_mask + param_4, param_4 == uVar2)) {
    uVar3 = _vm_map_copy(param_1,_ipc_soft_map,uVar1,uVar2,param_3,0,1);
  }
  else {
    uVar3 = 4;
  }
  return uVar3;
}

