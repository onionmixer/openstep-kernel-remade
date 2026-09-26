
int _vm_read(undefined4 param_1,uint param_2,uint param_3,undefined4 *param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uStack_8;
  
  uVar1 = ~_page_mask & _page_mask + param_2;
  if ((param_2 == uVar1) && (uVar2 = _page_mask + param_3 & ~_page_mask, param_3 == uVar2)) {
    iVar3 = _vm_allocate(_ipc_soft_map,&uStack_8,uVar2,1);
    if (iVar3 == 0) {
      iVar3 = _vm_map_copy(_ipc_soft_map,param_1,uStack_8,uVar2,uVar1,0,0);
      if (iVar3 == 0) {
        *param_4 = uStack_8;
        *param_5 = uVar2;
      }
      else {
        _vm_deallocate(_ipc_soft_map,uStack_8,uVar2);
      }
    }
    else {
      _printf(aVmReadKernelEr,iVar3);
      iVar3 = 6;
    }
  }
  else {
    iVar3 = 4;
  }
  return iVar3;
}

