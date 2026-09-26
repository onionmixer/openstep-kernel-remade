
int _host_zone_info(int param_1,int *param_2,uint *param_3,int *param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int *piVar9;
  bool bVar10;
  bool bVar11;
  undefined4 *puStack_4a;
  undefined auStack_46 [4];
  undefined4 uStack_42;
  undefined4 uStack_36;
  undefined4 uStack_32;
  undefined4 uStack_2e;
  undefined4 uStack_2a;
  undefined4 uStack_22;
  uint uStack_1e;
  undefined8 *puStack_14;
  undefined4 *puStack_c;
  int iStack_8;
  
  uVar1 = _num_zones;
  piVar9 = _first_zone;
  uVar6 = 0;
  uVar7 = 0;
  if (param_1 == 0) {
    iVar2 = 0x16;
  }
  else {
    if (*param_3 < _num_zones) {
      uVar6 = ~_page_mask & _page_mask + _num_zones * 0x50;
      iVar3 = _kmem_alloc_pageable(_ipc_kernel_map,&iStack_8,uVar6);
      iVar2 = iStack_8;
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    else {
      iVar2 = *param_2;
    }
    if (*param_5 < uVar1) {
      uVar7 = ~_page_mask & _page_mask + uVar1 * 0x24;
      iVar3 = _kmem_alloc_pageable(_ipc_kernel_map,&puStack_c,uVar7);
      if (iVar3 != 0) {
        if (iVar2 == *param_2) {
          return iVar3;
        }
        _kmem_free(_ipc_kernel_map,iStack_8,uVar6);
        return iVar3;
      }
      puStack_4a = puStack_c;
    }
    else {
      puStack_4a = (undefined4 *)*param_4;
    }
    uVar5 = 0;
    bVar11 = false;
    puVar8 = puStack_4a;
    iVar3 = iVar2;
    if (uVar1 != 0) {
      do {
        bVar10 = *(char *)(piVar9 + 10) < '\0';
        if (bVar10) {
          _lock_write((int)piVar9 + 0x2a);
        }
        else {
          *piVar9 = (int)(sword)(word)(byte)(bVar11 << 4 | bVar10 << 3 |
                                            (*(char *)(piVar9 + 10) == '\0') << 2);
        }
        _bcopy(piVar9,auStack_46,0x3a);
        if (*(char *)(piVar9 + 10) < '\0') {
          _lock_done((int)piVar9 + 0x2a);
        }
        piVar9 = *(int **)((int)piVar9 + 0x36);
        _strncpy(iVar3,uStack_22,0x50);
        *puVar8 = uStack_42;
        puVar8[1] = uStack_36;
        puVar8[2] = uStack_32;
        puVar8[3] = uStack_2e;
        puVar8[4] = uStack_2a;
        puVar8[5] = uStack_1e >> 0x1f;
        puVar8[6] = (uStack_1e & 0x7fffffff) >> 0x1e;
        puVar8[7] = (uStack_1e & 0x3fffffff) >> 0x1d;
        uVar4 = 0;
        if ((puStack_14 != (undefined8 *)0x0) && (puStack_14 != &__zone_default_space)) {
          uVar4 = 1;
        }
        puVar8[8] = uVar4;
        uVar5 = uVar5 + 1;
        bVar11 = uVar1 < uVar5;
        puVar8 = puVar8 + 9;
        iVar3 = iVar3 + 0x50;
      } while (uVar5 < uVar1);
    }
    if (iVar2 != *param_2) {
      if (uVar6 != uVar1 * 0x50) {
        _bzero(iStack_8 + uVar1 * 0x50,uVar6 + uVar1 * -0x50);
      }
      _vm_move(_ipc_kernel_map,iStack_8,_ipc_soft_map,uVar6,1,&iStack_8);
      *param_2 = iStack_8;
    }
    *param_3 = uVar1;
    if (puStack_4a != (undefined4 *)*param_4) {
      if (uVar7 != uVar1 * 0x24) {
        _bzero(puStack_c + uVar1 * 9,uVar7 + uVar1 * -0x24);
      }
      _vm_move(_ipc_kernel_map,puStack_c,_ipc_soft_map,uVar7,1,&puStack_c);
      *param_4 = (int)puStack_c;
    }
    *param_5 = uVar1;
    iVar2 = 0;
  }
  return iVar2;
}
