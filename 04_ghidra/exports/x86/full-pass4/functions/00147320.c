/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00147320 */

void _ipc_kmsg_clean_partial(int param_1,vm_address_t *param_2,int param_3,uint param_4)

{
  int iVar1;
  vm_address_t vVar2;
  bool bVar3;
  byte bVar4;
  uint uVar5;
  vm_address_t *pvVar6;
  uint uVar7;
  vm_address_t *pvVar8;
  vm_address_t vVar9;
  uint local_24;
  vm_address_t *local_10;
  uint local_c;
  
  uVar5 = *(uint *)(param_1 + 0x14);
  _ipc_object_destroy(*(undefined4 *)(param_1 + 0x1c),uVar5 & 0xff);
  iVar1 = *(int *)(param_1 + 0x20);
  if ((iVar1 != 0) && (iVar1 != -1)) {
    _ipc_object_destroy(iVar1,(uVar5 & 0xff00) >> 8);
  }
  pvVar8 = (vm_address_t *)(param_1 + 0x2c);
  while (pvVar8 < param_2) {
    bVar4 = *(byte *)((int)pvVar8 + 3) >> 4;
    if ((*(byte *)((int)pvVar8 + 3) & 0x20) == 0) {
      local_c = (uint)(byte)*pvVar8;
      uVar5 = (uint)*(byte *)((int)pvVar8 + 1);
      vVar9 = *(ushort *)((int)pvVar8 + 2) & 0xfff;
      pvVar8 = pvVar8 + 1;
    }
    else {
      local_c = (uint)(ushort)pvVar8[1];
      uVar5 = (uint)*(ushort *)((int)pvVar8 + 6);
      vVar9 = pvVar8[2];
      pvVar8 = pvVar8 + 3;
    }
    uVar5 = uVar5 * vVar9 + 7 >> 3;
    bVar3 = local_c - 0x10 < 6;
    if (bVar3) {
      if ((bVar4 & 1) == 0) {
        local_10 = (vm_address_t *)*pvVar8;
      }
      else {
        for (pvVar6 = pvVar8 + vVar9; local_10 = pvVar8, param_2 < pvVar6; pvVar6 = pvVar6 + -1) {
          vVar9 = vVar9 - 1;
        }
      }
      uVar7 = 0;
      if (vVar9 != 0) {
        do {
          vVar2 = local_10[uVar7];
          if ((vVar2 != 0) && (vVar2 != 0xffffffff)) {
            _ipc_object_destroy(vVar2,local_c);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < vVar9);
      }
    }
    if ((bVar4 & 1) == 0) {
      if (uVar5 != 0) {
        if (bVar3) {
          _kfree(*pvVar8,uVar5);
        }
        else {
          _vm_deallocate(_ipc_soft_map,*pvVar8,uVar5);
        }
      }
      pvVar8 = pvVar8 + 1;
    }
    else {
      pvVar8 = (vm_address_t *)((int)pvVar8 + (uVar5 + 3 & 0xfffffffc));
    }
  }
  if (param_3 != 0) {
    bVar4 = *(byte *)((int)param_2 + 3) >> 4;
    if ((*(byte *)((int)param_2 + 3) & 0x20) == 0) {
      local_24 = (uint)(byte)*param_2;
      uVar5 = (uint)*(byte *)((int)param_2 + 1);
      vVar9 = *(ushort *)((int)param_2 + 2) & 0xfff;
      param_2 = param_2 + 1;
    }
    else {
      local_24 = (uint)(ushort)param_2[1];
      uVar5 = (uint)*(ushort *)((int)param_2 + 6);
      vVar9 = param_2[2];
      param_2 = param_2 + 3;
    }
    uVar5 = vVar9 * uVar5 + 7 >> 3;
    bVar3 = 5 < local_24 - 0x10;
    if (!bVar3) {
      pvVar8 = param_2;
      if ((bVar4 & 1) == 0) {
        pvVar8 = (vm_address_t *)*param_2;
      }
      uVar7 = 0;
      if (param_4 != 0) {
        do {
          vVar9 = pvVar8[uVar7];
          if ((vVar9 != 0) && (vVar9 != 0xffffffff)) {
            _ipc_object_destroy(vVar9,local_24);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < param_4);
      }
    }
    if (((bVar4 & 1) == 0) && (uVar5 != 0)) {
      if (bVar3) {
        _vm_deallocate(_ipc_soft_map,*param_2,uVar5);
      }
      else {
        _kfree(*param_2,uVar5);
      }
    }
  }
  return;
}

