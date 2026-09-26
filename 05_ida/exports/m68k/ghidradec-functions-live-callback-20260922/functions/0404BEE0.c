
undefined4
sub_404BEE0(int param_1,undefined4 param_2,int param_3,uint param_4,int param_5,undefined4 param_6,
           uint *param_7)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  uint **ppuVar7;
  uint *puStack_44;
  uint *puStack_40;
  int iStack_3c;
  uint uStack_10;
  uint *puStack_c;
  uint uStack_8;
  
  if ((uint)(*(int *)(param_1 + 0x24) + *(int *)(param_1 + 0x20)) <= param_4) {
    uVar2 = ~_page_mask & _page_mask + *(int *)(param_1 + 0x1c);
    if (-1 < (int)uVar2) {
      if (uVar2 != 0) {
        uStack_8 = *(uint *)(param_1 + 0x18) & ~_page_mask;
        iStack_3c = 0;
        puStack_44 = &uStack_8;
        puStack_40 = (uint *)uVar2;
        iVar4 = _vm_map_find(param_6,0,0);
        if (iVar4 != 0) {
          return 5;
        }
        puVar3 = (uint *)(~_page_mask & _page_mask + *(int *)(param_1 + 0x24));
        param_3 = param_3 + *(int *)(param_1 + 0x20);
        if ((int)puVar3 < 0) {
          return 2;
        }
        if (0 < (int)puVar3) {
          iStack_3c = 1;
          puStack_44 = (uint *)0x0;
          puStack_40 = puVar3;
          uVar5 = _pmap_create(puVar3);
          uVar5 = _vm_map_create(uVar5);
          puStack_c = (uint *)0x0;
          iVar4 = _vm_allocate_with_pager(uVar5,&puStack_c,puVar3,0,param_2,param_3);
          if (iVar4 != 0) {
loc_404BFFA:
            puStack_40 = (uint *)0x404c002;
            iStack_3c = uVar5;
            _vm_map_deallocate();
            return 5;
          }
          puVar1 = *(uint **)(param_1 + 0x24);
          puVar6 = puVar3;
          if ((puVar1 != puVar3) && ((param_5 == 0 || (param_5 != (int)puVar1 + param_3)))) {
            puVar6 = (uint *)(~_page_mask & (uint)puVar1);
            uStack_10 = 0;
            iStack_3c = 1;
            puStack_40 = (uint *)_page_size;
            puStack_44 = &uStack_10;
            iVar4 = _vm_map_find(_kernel_map,0,0);
            if (iVar4 != 0) goto loc_404BFFA;
            iStack_3c = 0;
            puStack_40 = (uint *)0x0;
            puStack_44 = puVar6;
            iVar4 = _vm_map_copy(_kernel_map,uVar5,uStack_10,_page_size);
            if (iVar4 != 0) {
              iStack_3c = _page_size;
              puStack_40 = (uint *)uStack_10;
              ppuVar7 = &puStack_44;
              puStack_44 = _kernel_map;
              _vm_deallocate();
loc_404C0A2:
              *(undefined4 *)((int)ppuVar7 + -4) = uVar5;
              *(undefined4 *)((int)ppuVar7 + -8) = 0x404c0aa;
              _vm_map_deallocate();
              return 4;
            }
            iStack_3c = (int)puVar3 - *(int *)(param_1 + 0x24);
            puStack_40 = (uint *)(uStack_10 + (*(int *)(param_1 + 0x24) - (int)puVar6));
            puStack_44 = (uint *)0x404c05e;
            _bzero();
            puStack_44 = (uint *)0x0;
            iVar4 = _vm_map_copy(param_6,_kernel_map,(int)puVar6 + uStack_8,_page_size,uStack_10,0);
            iStack_3c = _page_size;
            puStack_40 = (uint *)uStack_10;
            puStack_44 = _kernel_map;
            _vm_deallocate();
            ppuVar7 = (uint **)&stack0xffffffc8;
            if (iVar4 != 0) goto loc_404C0A2;
          }
          iStack_3c = 0;
          puStack_40 = (uint *)0x0;
          puStack_44 = puStack_c;
          iVar4 = _vm_map_copy(param_6,uVar5,uStack_8,puVar6);
          _vm_map_deallocate(uVar5);
          if (iVar4 != 0) {
            return 4;
          }
        }
        puStack_40 = *(uint **)(param_1 + 0x28);
        if (puStack_40 != (uint *)0x3) {
          iStack_3c = 1;
          puStack_44 = (uint *)(uStack_8 + uVar2);
          _vm_map_protect(param_6,uStack_8);
        }
        puStack_40 = *(uint **)(param_1 + 0x2c);
        if (puStack_40 != (uint *)0x3) {
          iStack_3c = 0;
          puStack_44 = (uint *)(uStack_8 + uVar2);
          _vm_map_protect(param_6,uStack_8);
        }
        if (*(int *)(param_1 + 0x20) == 0) {
          *param_7 = uStack_8;
        }
      }
      return 0;
    }
  }
  return 2;
}

