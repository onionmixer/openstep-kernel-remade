
undefined4 _vm_copy(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = ~_page_mask;
  uVar1 = uVar3 & _page_mask + param_2;
  if (((param_2 == uVar1) && (uVar2 = uVar3 & _page_mask + param_4, param_4 == uVar2)) &&
     (uVar3 = uVar3 & _page_mask + param_3, param_3 == uVar3)) {
    uVar4 = _vm_map_copy(param_1,param_1,uVar2,uVar3,uVar1,0,0);
  }
  else {
    uVar4 = 4;
  }
  return uVar4;
}

