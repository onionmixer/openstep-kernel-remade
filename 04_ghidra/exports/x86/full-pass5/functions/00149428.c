/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00149428 */

void _ipc_kmsg_copyout_dest(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  vm_address_t vVar3;
  bool bVar4;
  byte bVar5;
  uint uVar6;
  vm_address_t *pvVar7;
  uint uVar8;
  vm_address_t *pvVar9;
  int iVar10;
  vm_address_t *pvVar11;
  vm_address_t vVar12;
  vm_address_t *local_20;
  uint local_1c;
  undefined4 local_8;
  
  uVar8 = *(uint *)(param_1 + 0x14);
  piVar2 = *(int **)(param_1 + 0x1c);
  iVar10 = *(int *)(param_1 + 0x20);
  uVar6 = (uVar8 & 0xff00) >> 8;
  do {
    do {
    } while (*piVar2 != 0);
    LOCK();
    iVar1 = *piVar2;
    *piVar2 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  if (piVar2[2] < 0) {
    _ipc_object_copyout_dest(param_2,piVar2,uVar8 & 0xff,&local_8);
  }
  else {
    iVar1 = piVar2[1];
    piVar2[1] = iVar1 + -1;
    LOCK();
    *piVar2 = 0;
    UNLOCK();
    if (iVar1 == 1) {
      _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar2 + 10) & 0x7fff],piVar2);
    }
    local_8 = 0xffffffff;
  }
  if ((iVar10 != 0) && (iVar10 != -1)) {
    _ipc_object_destroy(iVar10,uVar6);
    iVar10 = 0;
  }
  *(uint *)(param_1 + 0x14) = uVar8 & 0xffff0000 | (uVar8 & 0xff) << 8 | uVar6;
  *(undefined4 *)(param_1 + 0x20) = local_8;
  *(int *)(param_1 + 0x1c) = iVar10;
  if ((int)uVar8 < 0) {
    pvVar7 = (vm_address_t *)(*(int *)(param_1 + 0x18) + 0x14 + param_1);
    pvVar11 = (vm_address_t *)(param_1 + 0x2c);
    while (pvVar11 < pvVar7) {
      bVar5 = *(byte *)((int)pvVar11 + 3) >> 4;
      if ((*pvVar11 & 0x20000000) == 0) {
        local_1c = (uint)(byte)*pvVar11;
        uVar8 = (uint)*(byte *)((int)pvVar11 + 1);
        vVar12 = *(ushort *)((int)pvVar11 + 2) & 0xfff;
        pvVar11 = pvVar11 + 1;
      }
      else {
        local_1c = (uint)(ushort)pvVar11[1];
        uVar8 = (uint)*(ushort *)((int)pvVar11 + 6);
        vVar12 = pvVar11[2];
        pvVar11 = pvVar11 + 3;
      }
      uVar8 = uVar8 * vVar12 + 7 >> 3;
      bVar4 = local_1c - 0x10 < 6;
      if (bVar4) {
        if ((bVar5 & 1) == 0) {
          local_20 = (vm_address_t *)*pvVar11;
        }
        else {
          for (pvVar9 = pvVar11 + vVar12; local_20 = pvVar11, pvVar7 < pvVar9; pvVar9 = pvVar9 + -1)
          {
            vVar12 = vVar12 - 1;
          }
        }
        uVar6 = 0;
        if (vVar12 != 0) {
          do {
            vVar3 = local_20[uVar6];
            if ((vVar3 != 0) && (vVar3 != 0xffffffff)) {
              _ipc_object_destroy(vVar3,local_1c);
            }
            uVar6 = uVar6 + 1;
          } while (uVar6 < vVar12);
        }
      }
      if ((bVar5 & 1) == 0) {
        if (uVar8 != 0) {
          if (bVar4) {
            _kfree(*pvVar11,uVar8);
          }
          else {
            _vm_deallocate(_ipc_soft_map,*pvVar11,uVar8);
          }
        }
        pvVar11 = pvVar11 + 1;
      }
      else {
        pvVar11 = (vm_address_t *)((int)pvVar11 + (uVar8 + 3 & 0xfffffffc));
      }
    }
  }
  return;
}

