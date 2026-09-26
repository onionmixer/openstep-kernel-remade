/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00148008 */

int _ipc_kmsg_copyin(int param_1,undefined4 param_2,vm_map_t param_3,undefined4 param_4)

{
  undefined4 uVar1;
  vm_address_t address;
  bool bVar2;
  bool bVar3;
  uint *puVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  kern_return_t kVar10;
  int iVar11;
  byte bVar12;
  uint uVar13;
  uint *puVar14;
  uint *puVar15;
  uint local_44;
  undefined2 local_38;
  uint local_24;
  uint local_20;
  uint local_c;
  uint *local_8;
  
  iVar7 = _ipc_kmsg_copyin_header(param_1 + 0x14,param_2,param_4);
  if (iVar7 == 0) {
    if (*(int *)(param_1 + 0x14) < 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x1c);
      bVar3 = false;
      puVar8 = (uint *)(*(int *)(param_1 + 0x18) + 0x14 + param_1);
      puVar15 = (uint *)(param_1 + 0x2c);
      while (puVar4 = puVar15, puVar4 < puVar8) {
        if ((uint)((int)puVar8 - (int)puVar4) < 4) {
LAB_001480e9:
          _ipc_kmsg_clean_partial(param_1,puVar4,0,0);
          return 0x10000008;
        }
        bVar5 = *(byte *)((int)puVar4 + 3) >> 5;
        if (((bVar5 & 1) != 0) && ((uint)((int)puVar8 - (int)puVar4) < 0xc)) goto LAB_001480e9;
        bVar6 = *(byte *)((int)puVar4 + 3) >> 4;
        bVar12 = *(byte *)((int)puVar4 + 3) >> 6;
        if ((bVar5 & 1) == 0) {
          local_20 = (uint)(byte)*puVar4;
          uVar13 = (uint)*(byte *)((int)puVar4 + 1);
          local_24 = *(ushort *)((int)puVar4 + 2) & 0xfff;
          puVar14 = puVar4 + 1;
        }
        else {
          local_20 = (uint)(ushort)puVar4[1];
          uVar13 = (uint)*(ushort *)((int)puVar4 + 6);
          local_24 = puVar4[2];
          puVar14 = puVar4 + 3;
        }
        bVar2 = local_20 - 0x10 < 6;
        if (((((bVar2) && (uVar13 != 0x20)) || (((bVar5 & 1) != 0 && ((*puVar4 & 0xfffffff) != 0))))
            || ((char)*(byte *)((int)puVar4 + 3) < '\0')) ||
           (((bVar12 & 1) != 0 && ((bVar6 & 1) != 0)))) {
          _ipc_kmsg_clean_partial(param_1,puVar4,0,0);
          return 0x1000000f;
        }
        uVar13 = local_24 * uVar13 + 7 >> 3;
        if ((bVar6 & 1) == 0) {
          if ((uint)((int)puVar8 - (int)puVar14) < 4) {
            _ipc_kmsg_clean_partial(param_1,puVar4,0,0);
            return 0x10000008;
          }
          address = *puVar14;
          if (uVar13 == 0) {
            puVar9 = (uint *)0x0;
          }
          else if (bVar2) {
            puVar9 = (uint *)_kalloc(uVar13);
            if (puVar9 == (uint *)0x0) {
LAB_00148298:
              _ipc_kmsg_clean_partial(param_1,puVar4,0,0);
              return 0x1000000c;
            }
            iVar7 = _copyinmap(param_3,address,puVar9,uVar13);
            if ((iVar7 != 0) ||
               (((bVar12 & 1) != 0 && (kVar10 = _vm_deallocate(param_3,address,uVar13), kVar10 != 0)
                ))) {
              _kfree(puVar9,uVar13);
              goto LAB_00148298;
            }
          }
          else {
            iVar7 = _vm_move(param_3,address,_ipc_soft_map,uVar13,bVar12 & 1,&local_8);
            puVar9 = local_8;
            if (iVar7 != 0) goto LAB_00148298;
          }
          *puVar14 = (uint)puVar9;
          puVar15 = puVar14 + 1;
          bVar3 = true;
        }
        else {
          uVar13 = uVar13 + 3 & 0xfffffffc;
          if ((uint)((int)puVar8 - (int)puVar14) < uVar13) {
            _ipc_kmsg_clean_partial(param_1,puVar4,0,0);
            return 0x10000008;
          }
          puVar15 = (uint *)((int)puVar14 + uVar13);
          puVar9 = puVar14;
        }
        if (bVar2) {
          iVar7 = _ipc_object_copyin_type(local_20);
          if ((bVar5 & 1) == 0) {
            local_38._0_1_ = (byte)iVar7;
            *(byte *)puVar4 = (byte)local_38;
          }
          else {
            local_38 = (undefined2)iVar7;
            *(undefined2 *)(puVar4 + 1) = local_38;
          }
          local_44 = 0;
          if (local_24 != 0) {
            do {
              uVar13 = *puVar9;
              if ((uVar13 != 0) && (uVar13 != 0xffffffff)) {
                iVar11 = _ipc_object_copyin(param_2,uVar13,local_20,&local_c);
                if (iVar11 != 0) {
                  _ipc_kmsg_clean_partial(param_1,puVar4,1,local_44);
                  return 0x1000000a;
                }
                if ((iVar7 == 0x10) &&
                   (iVar11 = _ipc_port_check_circularity(local_c,uVar1), iVar11 != 0)) {
                  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40000000;
                }
                *puVar9 = local_c;
              }
              puVar9 = puVar9 + 1;
              local_44 = local_44 + 1;
            } while (local_44 < local_24);
          }
          bVar3 = true;
        }
      }
      if (!bVar3) {
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) & 0x7fffffff;
      }
      iVar7 = 0;
    }
    else {
      iVar7 = 0;
    }
  }
  return iVar7;
}

