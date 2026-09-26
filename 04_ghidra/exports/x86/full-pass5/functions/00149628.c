/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00149628 */

undefined4 _ipc_kmsg_copyin_compat(int param_1,undefined4 param_2,vm_map_t param_3)

{
  byte bVar1;
  vm_address_t vVar2;
  bool bVar3;
  bool bVar4;
  vm_address_t *pvVar5;
  byte bVar6;
  undefined4 uVar7;
  vm_address_t *pvVar8;
  kern_return_t kVar9;
  int iVar10;
  int iVar11;
  vm_address_t *pvVar12;
  vm_address_t *pvVar13;
  byte bVar14;
  uint uVar15;
  byte bVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  uint local_68;
  vm_address_t *local_64;
  undefined2 local_5c;
  uint local_48;
  uint local_44;
  vm_address_t local_34;
  vm_address_t *local_30;
  int local_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar17 = (undefined4 *)(param_1 + 0x14);
  puVar18 = &local_1c;
  for (iVar11 = 6; iVar11 != 0; iVar11 = iVar11 + -1) {
    *puVar18 = *puVar17;
    puVar17 = puVar17 + 1;
    puVar18 = puVar18 + 1;
  }
  iVar11 = _ipc_object_copyin_header(param_2,local_c,&local_20,&local_24);
  if (iVar11 == 0) {
    if (local_10 == 0) {
      local_28 = 0;
      local_2c = 0;
    }
    else {
      iVar11 = _ipc_object_copyin_header(param_2,local_10,&local_28,&local_2c);
      if (iVar11 != 0) {
        _ipc_object_destroy(local_20,local_24);
        return 0x10000009;
      }
    }
    *(uint *)(param_1 + 0x14) = local_2c << 8 | local_24;
    *(undefined4 *)(param_1 + 0x18) = local_18;
    *(undefined4 *)(param_1 + 0x1c) = local_20;
    *(undefined4 *)(param_1 + 0x20) = local_28;
    *(undefined4 *)(param_1 + 0x24) = local_14;
    *(undefined4 *)(param_1 + 0x28) = local_8;
    if (local_1c._3_1_ == '\0') {
      bVar4 = false;
      pvVar8 = (vm_address_t *)(*(int *)(param_1 + 0x18) + 0x14 + param_1);
      pvVar13 = (vm_address_t *)(param_1 + 0x2c);
      while (pvVar5 = pvVar13, pvVar5 < pvVar8) {
        if ((uint)((int)pvVar8 - (int)pvVar5) < 4) {
LAB_001497a8:
          _ipc_kmsg_clean_partial(param_1,pvVar5,0,0);
          return 0x10000008;
        }
        bVar6 = *(byte *)((int)pvVar5 + 3) >> 5;
        if (((bVar6 & 1) != 0) && ((uint)((int)pvVar8 - (int)pvVar5) < 0xc)) goto LAB_001497a8;
        bVar1 = *(byte *)((int)pvVar5 + 3);
        bVar14 = bVar1 >> 6;
        bVar16 = bVar14 & 1;
        if ((bVar6 & 1) == 0) {
          local_44 = (uint)(byte)*pvVar5;
          uVar15 = (uint)*(byte *)((int)pvVar5 + 1);
          local_48 = *(ushort *)((int)pvVar5 + 2) & 0xfff;
          pvVar12 = pvVar5 + 1;
        }
        else {
          local_44 = (uint)(ushort)pvVar5[1];
          uVar15 = (uint)*(ushort *)((int)pvVar5 + 6);
          local_48 = pvVar5[2];
          pvVar12 = pvVar5 + 3;
        }
        bVar3 = local_44 - 5 < 2;
        if ((bVar3) && (uVar15 != 0x20)) {
          _ipc_kmsg_clean_partial(param_1,pvVar5,0,0);
          return 0x1000000f;
        }
        *(byte *)((int)pvVar5 + 3) = *(byte *)((int)pvVar5 + 3) & 0x7f;
        if ((bVar6 & 1) != 0) {
          *(byte *)pvVar5 = 0;
          *(byte *)((int)pvVar5 + 1) = 0;
          *(ushort *)((int)pvVar5 + 2) = *(ushort *)((int)pvVar5 + 2) & 0xf000;
        }
        uVar15 = local_48 * uVar15 + 7 >> 3;
        if ((bVar1 >> 4 & 1) == 0) {
          if ((uint)((int)pvVar8 - (int)pvVar12) < 4) {
            _ipc_kmsg_clean_partial(param_1,pvVar5,0,0);
            return 0x10000008;
          }
          vVar2 = *pvVar12;
          if (uVar15 == 0) {
            local_64 = (vm_address_t *)0x0;
          }
          else if (bVar3) {
            local_64 = (vm_address_t *)_kalloc(uVar15);
            if (local_64 == (vm_address_t *)0x0) {
LAB_0014994a:
              _ipc_kmsg_clean_partial(param_1,pvVar5,0,0);
              return 0x1000000c;
            }
            iVar11 = _copyinmap(param_3,vVar2,local_64,uVar15);
            if ((iVar11 != 0) ||
               (((bVar14 & 1) != 0 && (kVar9 = _vm_deallocate(param_3,vVar2,uVar15), kVar9 != 0))))
            {
              _kfree(local_64,uVar15);
              goto LAB_0014994a;
            }
          }
          else {
            iVar11 = _vm_move(param_3,vVar2,_ipc_soft_map,uVar15,bVar16,&local_30);
            if (iVar11 != 0) goto LAB_0014994a;
            local_64 = local_30;
          }
          *pvVar12 = (vm_address_t)local_64;
          pvVar13 = pvVar12 + 1;
          bVar4 = true;
        }
        else {
          uVar15 = uVar15 + 3 & 0xfffffffc;
          if ((uint)((int)pvVar8 - (int)pvVar12) < uVar15) {
            _ipc_kmsg_clean_partial(param_1,pvVar5,0,0);
            return 0x10000008;
          }
          pvVar13 = (vm_address_t *)((int)pvVar12 + uVar15);
          local_64 = pvVar12;
        }
        if (bVar3) {
          iVar11 = _ipc_object_copyin_type(local_44);
          if ((bVar6 & 1) == 0) {
            local_5c._0_1_ = (byte)iVar11;
            *(byte *)pvVar5 = (byte)local_5c;
          }
          else {
            local_5c = (undefined2)iVar11;
            *(undefined2 *)(pvVar5 + 1) = local_5c;
          }
          local_68 = 0;
          if (local_48 != 0) {
            do {
              vVar2 = *local_64;
              if ((vVar2 != 0) && (vVar2 != 0xffffffff)) {
                iVar10 = _ipc_object_copyin_compat(param_2,vVar2,local_44,bVar16,&local_34);
                if (iVar10 != 0) {
                  _ipc_kmsg_clean_partial(param_1,pvVar5,1,local_68);
                  return 0x1000000a;
                }
                if ((iVar11 == 0x10) &&
                   (iVar10 = _ipc_port_check_circularity(local_34,local_20), iVar10 != 0)) {
                  *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x40000000;
                }
                *local_64 = local_34;
              }
              local_64 = local_64 + 1;
              local_68 = local_68 + 1;
            } while (local_68 < local_48);
          }
          bVar4 = true;
        }
      }
      if (bVar4) {
        *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) | 0x80000000;
      }
      uVar7 = 0;
    }
    else {
      uVar7 = 0;
    }
  }
  else {
    uVar7 = 0x10000003;
  }
  return uVar7;
}

