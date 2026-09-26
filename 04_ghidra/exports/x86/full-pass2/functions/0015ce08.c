/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015ce08 */

undefined4
FUN_0015ce08(int param_1,undefined4 param_2,int param_3,uint param_4,int param_5,undefined4 param_6,
            uint *param_7)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  vm_address_t local_10;
  undefined4 local_c;
  uint local_8;
  
  if ((uint)(*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x24)) <= param_4) {
    uVar4 = *(int *)(param_1 + 0x1c) + _page_mask & ~_page_mask;
    if (-1 < (int)uVar4) {
      if (uVar4 == 0) {
        return 0;
      }
      local_8 = ~_page_mask & *(uint *)(param_1 + 0x18);
      iVar2 = _vm_map_find(param_6,0,0,&local_8,uVar4,0);
      if (iVar2 != 0) {
        return 5;
      }
      uVar6 = *(int *)(param_1 + 0x24) + _page_mask & ~_page_mask;
      param_3 = *(int *)(param_1 + 0x20) + param_3;
      if (-1 < (int)uVar6) {
        if (0 < (int)uVar6) {
          uVar3 = _pmap_create(uVar6,0,uVar6,1);
          uVar3 = _vm_map_create(uVar3);
          local_c = 0;
          iVar2 = _vm_allocate_with_pager(uVar3,&local_c,uVar6,0,param_2,param_3);
          if (iVar2 != 0) {
            _vm_map_deallocate(uVar3);
            return 5;
          }
          uVar1 = *(uint *)(param_1 + 0x24);
          uVar5 = uVar6;
          if ((uVar6 != uVar1) && ((param_5 == 0 || (param_5 != param_3 + uVar1)))) {
            uVar5 = uVar1 & ~_page_mask;
            local_10 = 0;
            iVar2 = _vm_map_find(_kernel_map,0,0,&local_10,_page_size,1);
            if (iVar2 != 0) {
              _vm_map_deallocate(uVar3);
              return 5;
            }
            iVar2 = _vm_map_copy(_kernel_map,uVar3,local_10,_page_size,uVar5,0,0);
            if (iVar2 != 0) {
              _vm_deallocate(_kernel_map,local_10,_page_size);
              _vm_map_deallocate(uVar3);
              return 4;
            }
            _bzero((void *)((*(int *)(param_1 + 0x24) - uVar5) + local_10),
                   uVar6 - *(int *)(param_1 + 0x24));
            iVar2 = _vm_map_copy(param_6,_kernel_map,uVar5 + local_8,_page_size,local_10,0,0);
            _vm_deallocate(_kernel_map,local_10,_page_size);
            if (iVar2 != 0) {
              _vm_map_deallocate(uVar3);
              return 4;
            }
          }
          iVar2 = _vm_map_copy(param_6,uVar3,local_8,uVar5,local_c,0,0);
          _vm_map_deallocate(uVar3);
          if (iVar2 != 0) {
            return 4;
          }
        }
        if (*(int *)(param_1 + 0x28) != 3) {
          _vm_map_protect(param_6,local_8,uVar4 + local_8,*(int *)(param_1 + 0x28),1);
        }
        if (*(int *)(param_1 + 0x2c) != 3) {
          _vm_map_protect(param_6,local_8,uVar4 + local_8,*(int *)(param_1 + 0x2c),0);
        }
        if (*(int *)(param_1 + 0x20) == 0) {
          *param_7 = local_8;
        }
        return 0;
      }
    }
  }
  return 2;
}

