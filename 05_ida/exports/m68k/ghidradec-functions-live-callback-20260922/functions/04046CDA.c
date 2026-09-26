
int _port_names(undefined4 param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,
               uint *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 uStack_c;
  undefined4 *puStack_8;
  
  iVar3 = _mach_port_names(param_1,param_2,param_3,param_4,param_5);
  if (iVar3 == 0) {
    uVar1 = *param_5;
    uStack_c = *param_4;
    uVar2 = ~_page_mask & _page_mask + uVar1 * 4;
    iVar3 = _vm_move(_ipc_soft_map,uStack_c,_ipc_kernel_map,uVar2,0,&puStack_8);
    if (iVar3 == 0) {
      _vm_deallocate(_ipc_soft_map,uStack_c,uVar2);
      uVar5 = 0;
      puVar6 = puStack_8;
      if (uVar1 != 0) {
        do {
          uVar4 = _convert_port_type(*puVar6);
          *puVar6 = uVar4;
          uVar5 = uVar5 + 1;
          puVar6 = puVar6 + 1;
        } while (uVar5 < uVar1);
      }
      iVar3 = _vm_move(_ipc_kernel_map,puStack_8,_ipc_soft_map,uVar2,1,&uStack_c);
      *param_4 = uStack_c;
    }
    else {
      _kmem_free(_ipc_soft_map,*param_4,~_page_mask & _page_mask + *param_5 * 4);
      _kmem_free(_ipc_soft_map,*param_2,~_page_mask & _page_mask + *param_3 * 4);
      iVar3 = 6;
    }
  }
  else if (iVar3 != 6) {
    iVar3 = 4;
  }
  return iVar3;
}

