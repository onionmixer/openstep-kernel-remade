
undefined4
_mach_port_space_info
          (int param_1,undefined4 *param_2,int *param_3,uint *param_4,int *param_5,uint *param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint *puStack_1c;
  uint *puStack_18;
  int iStack_14;
  int iStack_10;
  uint *puStack_c;
  uint *puStack_8;
  
  uVar8 = 0;
  uVar9 = 0;
  if (param_1 != 0) {
    puStack_1c = (uint *)*param_3;
    uVar7 = *param_4;
    puStack_18 = (uint *)*param_5;
    uVar6 = *param_6;
    while (*(int *)(param_1 + 4) != 0) {
      uVar2 = *(uint *)(param_1 + 0x10);
      uVar3 = *(uint *)(param_1 + 0x30);
      if (uVar7 < uVar2) {
        if (puStack_1c != (uint *)*param_3) {
          _kmem_free(_ipc_kernel_map,puStack_8,uVar8);
        }
        uVar8 = ~_page_mask & _page_mask + uVar2 * 0x24;
        iVar4 = _kmem_alloc(_ipc_kernel_map,&puStack_8,uVar8);
        if (iVar4 == 0) {
          puStack_1c = puStack_8;
          uVar7 = uVar8 / 0x24;
          goto loc_4043F52;
        }
        uVar8 = uVar9;
        if (puStack_18 == (uint *)*param_5) {
          return 6;
        }
        goto loc_4043FC4;
      }
      if (uVar3 <= uVar6) {
        *param_2 = 0xff;
        param_2[1] = *(undefined4 *)(param_1 + 0x10);
        param_2[2] = **(undefined4 **)(param_1 + 0x14);
        param_2[3] = *(undefined4 *)(param_1 + 0x30);
        param_2[4] = *(undefined4 *)(param_1 + 0x34);
        param_2[5] = *(undefined4 *)(param_1 + 0x38);
        puVar5 = *(uint **)(param_1 + 0xc);
        uVar7 = *(uint *)(param_1 + 0x10);
        uVar6 = 0;
        puVar10 = puStack_1c;
        if (uVar7 != 0) {
          do {
            uVar1 = *puVar5;
            *puVar10 = CONCAT31((int3)uVar6,*(undefined *)puVar5);
            puVar10[1] = (uVar1 & 0xffffff) >> 0x17;
            puVar10[2] = (uVar1 & 0x7fffff) >> 0x16;
            puVar10[3] = (uVar1 & 0x3fffff) >> 0x15;
            puVar10[4] = uVar1 & 0x1f0000;
            *(undefined2 *)(puVar10 + 5) = 0;
            *(sword *)((int)puVar10 + 0x16) = (sword)uVar1;
            puVar10[6] = puVar5[1];
            puVar10[7] = puVar5[2];
            puVar10[8] = puVar5[3];
            puVar5 = puVar5 + 4;
            uVar6 = uVar6 + 1;
            puVar10 = puVar10 + 9;
          } while (uVar6 < uVar7);
        }
        puVar5 = (uint *)_ipc_splay_traverse_start(param_1 + 0x18);
        puVar10 = puStack_18;
        while (puVar5 != (uint *)0x0) {
          uVar7 = *puVar5;
          *puVar10 = puVar5[4];
          puVar10[1] = (uVar7 & 0xffffff) >> 0x17;
          puVar10[2] = (uVar7 & 0x7fffff) >> 0x16;
          puVar10[3] = (uVar7 & 0x3fffff) >> 0x15;
          puVar10[4] = uVar7 & 0x1f0000;
          *(undefined2 *)(puVar10 + 5) = 0;
          *(sword *)((int)puVar10 + 0x16) = (sword)uVar7;
          puVar10[6] = puVar5[1];
          puVar10[7] = puVar5[2];
          puVar10[8] = puVar5[3];
          if (puVar5[6] == 0) {
            puVar10[9] = 0;
          }
          else {
            puVar10[9] = *(uint *)(puVar5[6] + 0x10);
          }
          if (puVar5[7] == 0) {
            puVar10[10] = 0;
          }
          else {
            puVar10[10] = *(uint *)(puVar5[7] + 0x10);
          }
          puVar5 = (uint *)_ipc_splay_traverse_next(param_1 + 0x18,0);
          puVar10 = puVar10 + 0xb;
        }
        _ipc_splay_traverse_finish(param_1 + 0x18);
        if (puStack_1c == (uint *)*param_3) {
          *param_4 = uVar2;
        }
        else if (uVar2 == 0) {
          _kmem_free(_ipc_kernel_map,puStack_8,uVar8);
          *param_4 = 0;
        }
        else {
          uVar7 = ~_page_mask & _page_mask + uVar2 * 0x24;
          if (uVar8 != uVar7) {
            _kmem_free(_ipc_kernel_map,uVar7 + (int)puStack_8,uVar8 - uVar7);
          }
          if (uVar7 != uVar2 * 0x24) {
            _bzero(puStack_8 + uVar2 * 9,uVar7 + uVar2 * -0x24);
          }
          _vm_move(_ipc_kernel_map,puStack_8,_ipc_soft_map,uVar7,1,&iStack_10);
          *param_3 = iStack_10;
          *param_4 = uVar2;
        }
        if (puStack_18 != (uint *)*param_5) {
          if (uVar3 == 0) {
            _kmem_free(_ipc_kernel_map,puStack_c,uVar9);
            *param_6 = 0;
            return 0;
          }
          uVar8 = ~_page_mask & _page_mask + uVar3 * 0x2c;
          if (uVar9 != uVar8) {
            _kmem_free(_ipc_kernel_map,uVar8 + (int)puStack_c,uVar9 - uVar8);
          }
          if (uVar8 != uVar3 * 0x2c) {
            _bzero(puStack_c + uVar3 * 0xb,uVar8 + uVar3 * -0x2c);
          }
          _vm_move(_ipc_kernel_map,puStack_c,_ipc_soft_map,uVar8,1,&iStack_14);
          *param_5 = iStack_14;
        }
        *param_6 = uVar3;
        return 0;
      }
loc_4043F52:
      if (uVar6 < uVar3) {
        if (puStack_18 != (uint *)*param_5) {
          _kmem_free(_ipc_kernel_map,puStack_c,uVar9);
        }
        uVar9 = ~_page_mask & _page_mask + uVar3 * 0x2c;
        iVar4 = _kmem_alloc(_ipc_kernel_map,&puStack_c,uVar9);
        if (iVar4 != 0) {
          puStack_c = puStack_8;
          if (puStack_1c != (uint *)*param_3) {
loc_4043FC4:
            _kmem_free(_ipc_kernel_map,puStack_c,uVar8);
          }
          return 6;
        }
        puStack_18 = puStack_c;
        uVar6 = uVar9 / 0x2c;
      }
    }
    if (puStack_1c != (uint *)*param_3) {
      _kmem_free(_ipc_kernel_map,puStack_8,uVar8);
    }
    if (puStack_18 != (uint *)*param_5) {
      _kmem_free(_ipc_kernel_map,puStack_c,uVar9);
    }
  }
  return 0x10;
}
