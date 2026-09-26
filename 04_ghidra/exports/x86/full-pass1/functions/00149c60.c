/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00149c60 */

undefined4 _ipc_kmsg_copyout_compat(int param_1,undefined4 param_2,vm_map_t param_3)

{
  int *piVar1;
  vm_address_t vVar2;
  bool bVar3;
  byte bVar4;
  undefined2 uVar5;
  int iVar6;
  uint uVar7;
  kern_return_t kVar8;
  vm_address_t *pvVar9;
  int iVar10;
  vm_address_t *pvVar11;
  vm_address_t *pvVar12;
  byte bVar13;
  uint uVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  vm_address_t vVar17;
  uint local_68;
  uint local_64;
  vm_address_t *local_58;
  uint local_50;
  uint local_3c;
  uint local_38;
  vm_address_t local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar7 = *(uint *)(param_1 + 0x14);
  piVar1 = *(int **)(param_1 + 0x1c);
  iVar10 = *(int *)(param_1 + 0x20);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar6 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar6 == 1);
  if (piVar1[2] < 0) {
    _ipc_object_copyout_dest(param_2,piVar1,uVar7 & 0xff,&local_20);
  }
  else {
    iVar6 = piVar1[1];
    piVar1[1] = iVar6 + -1;
    LOCK();
    *piVar1 = 0;
    UNLOCK();
    if (iVar6 == 1) {
      _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar1 + 10) & 0x7fff],piVar1);
    }
    local_20 = 0;
  }
  if ((iVar10 == 0) || (iVar10 == -1)) {
    local_24 = 0;
  }
  else {
    uVar14 = (uVar7 & 0xff00) >> 8;
    iVar6 = _ipc_object_copyout_compat(param_2,iVar10,uVar14,&local_24);
    if (iVar6 != 0) {
      _ipc_object_destroy(iVar10,uVar14);
      local_24 = 0;
    }
  }
  local_1c = (uVar7 >> 0x1f) << 0x18 ^ 0x1000000;
  local_18 = *(undefined4 *)(param_1 + 0x18);
  local_14 = *(undefined4 *)(param_1 + 0x24);
  local_10 = local_20;
  local_c = local_24;
  local_8 = *(undefined4 *)(param_1 + 0x28);
  puVar15 = &local_1c;
  puVar16 = (undefined4 *)(param_1 + 0x14);
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar16 = *puVar15;
    puVar15 = puVar15 + 1;
    puVar16 = puVar16 + 1;
  }
  if (local_1c._3_1_ == '\0') {
    pvVar11 = (vm_address_t *)(param_1 + 0x2c);
    iVar10 = *(int *)(param_1 + 0x18);
    while (pvVar11 < (vm_address_t *)(iVar10 + 0x14 + param_1)) {
      bVar4 = *(byte *)((int)pvVar11 + 3) >> 4;
      bVar13 = *(byte *)((int)pvVar11 + 3) >> 5;
      if ((bVar13 & 1) == 0) {
        local_38 = (uint)(byte)*pvVar11;
        uVar7 = (uint)*(byte *)((int)pvVar11 + 1);
        local_3c = *(ushort *)((int)pvVar11 + 2) & 0xfff;
        pvVar12 = pvVar11 + 1;
      }
      else {
        local_38 = (uint)(ushort)pvVar11[1];
        uVar7 = (uint)*(ushort *)((int)pvVar11 + 6);
        local_3c = pvVar11[2];
        pvVar12 = pvVar11 + 3;
      }
      uVar7 = uVar7 * local_3c + 7 >> 3;
      bVar3 = 5 < local_38 - 0x10;
      if (bVar3) {
LAB_0014a027:
        if ((bVar4 & 1) == 0) {
          vVar17 = *pvVar12;
          if (uVar7 == 0) goto LAB_0014a0b2;
          if (bVar3) {
            iVar6 = _vm_move(_ipc_soft_map,vVar17,param_3,uVar7,0,&local_28);
            _vm_deallocate(_ipc_soft_map,vVar17,uVar7);
            if (iVar6 != 0) goto LAB_0014a0b2;
          }
          else {
            _copyoutmap(param_3,vVar17,local_28,uVar7);
            _kfree(vVar17,uVar7);
          }
          goto LAB_0014a0b9;
        }
        pvVar11 = (vm_address_t *)((int)pvVar12 + (uVar7 + 3 & 0xfffffffc));
      }
      else {
        if ((((bVar4 & 1) != 0) || (uVar7 == 0)) ||
           (kVar8 = _vm_allocate(param_3,&local_28,uVar7,1), kVar8 == 0)) {
          uVar5 = _ipc_object_copyout_type_compat(local_38);
          if ((bVar13 & 1) == 0) {
            *(byte *)pvVar11 = (byte)uVar5;
          }
          else {
            *(undefined2 *)(pvVar11 + 1) = uVar5;
          }
          pvVar11 = pvVar12;
          if ((bVar4 & 1) == 0) {
            pvVar11 = (vm_address_t *)*pvVar12;
          }
          local_68 = 0;
          if (local_3c != 0) {
            do {
              vVar17 = *pvVar11;
              if ((vVar17 == 0) || (vVar17 == 0xffffffff)) {
                *pvVar11 = 0;
              }
              else {
                iVar6 = _ipc_object_copyout_compat(param_2,vVar17,local_38,pvVar11);
                if (iVar6 != 0) {
                  _ipc_object_destroy(vVar17,local_38);
                  *pvVar11 = 0;
                }
              }
              pvVar11 = pvVar11 + 1;
              local_68 = local_68 + 1;
            } while (local_68 < local_3c);
          }
          goto LAB_0014a027;
        }
        while (pvVar11 < pvVar12) {
          bVar4 = *(byte *)((int)pvVar11 + 3) >> 4;
          if ((*pvVar11 & 0x20000000) == 0) {
            local_50 = (uint)(byte)*pvVar11;
            uVar7 = (uint)*(byte *)((int)pvVar11 + 1);
            vVar17 = *(ushort *)((int)pvVar11 + 2) & 0xfff;
            pvVar11 = pvVar11 + 1;
          }
          else {
            local_50 = (uint)(ushort)pvVar11[1];
            uVar7 = (uint)*(ushort *)((int)pvVar11 + 6);
            vVar17 = pvVar11[2];
            pvVar11 = pvVar11 + 3;
          }
          uVar7 = uVar7 * vVar17 + 7 >> 3;
          bVar3 = local_50 - 0x10 < 6;
          if (bVar3) {
            if ((bVar4 & 1) == 0) {
              local_58 = (vm_address_t *)*pvVar11;
            }
            else {
              for (pvVar9 = pvVar11 + vVar17; local_58 = pvVar11, pvVar12 < pvVar9;
                  pvVar9 = pvVar9 + -1) {
                vVar17 = vVar17 - 1;
              }
            }
            local_64 = 0;
            if (vVar17 != 0) {
              do {
                vVar2 = local_58[local_64];
                if ((vVar2 != 0) && (vVar2 != 0xffffffff)) {
                  _ipc_object_destroy(vVar2,local_50);
                }
                local_64 = local_64 + 1;
              } while (local_64 < vVar17);
            }
          }
          if ((bVar4 & 1) == 0) {
            if (uVar7 != 0) {
              if (bVar3) {
                _kfree(*pvVar11,uVar7);
              }
              else {
                _vm_deallocate(_ipc_soft_map,*pvVar11,uVar7);
              }
            }
            pvVar11 = pvVar11 + 1;
          }
          else {
            pvVar11 = (vm_address_t *)((int)pvVar11 + (uVar7 + 3 & 0xfffffffc));
          }
        }
LAB_0014a0b2:
        local_28 = 0;
LAB_0014a0b9:
        *pvVar12 = local_28;
        pvVar11 = pvVar12 + 1;
      }
    }
  }
  return 0;
}

