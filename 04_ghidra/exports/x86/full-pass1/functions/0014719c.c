/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014719c */

void _ipc_kmsg_clean(int param_1)

{
  int iVar1;
  vm_address_t vVar2;
  bool bVar3;
  byte bVar4;
  vm_address_t *pvVar5;
  uint uVar6;
  vm_address_t *pvVar7;
  uint uVar8;
  vm_address_t *pvVar9;
  vm_address_t vVar10;
  vm_address_t *local_14;
  uint local_10;
  
  uVar6 = *(uint *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0xc) != 0) {
    _ipc_marequest_destroy(*(int *)(param_1 + 0xc));
  }
  iVar1 = *(int *)(param_1 + 0x1c);
  if ((iVar1 != 0) && (iVar1 != -1)) {
    _ipc_object_destroy(iVar1,uVar6 & 0xff);
  }
  iVar1 = *(int *)(param_1 + 0x20);
  if ((iVar1 != 0) && (iVar1 != -1)) {
    _ipc_object_destroy(iVar1,(uVar6 & 0xff00) >> 8);
  }
  if ((int)uVar6 < 0) {
    pvVar5 = (vm_address_t *)(*(int *)(param_1 + 0x18) + 0x14 + param_1);
    pvVar9 = (vm_address_t *)(param_1 + 0x2c);
    while (pvVar9 < pvVar5) {
      bVar4 = *(byte *)((int)pvVar9 + 3) >> 4;
      if ((*(byte *)((int)pvVar9 + 3) & 0x20) == 0) {
        local_10 = (uint)(byte)*pvVar9;
        uVar6 = (uint)*(byte *)((int)pvVar9 + 1);
        vVar10 = *(ushort *)((int)pvVar9 + 2) & 0xfff;
        pvVar9 = pvVar9 + 1;
      }
      else {
        local_10 = (uint)(ushort)pvVar9[1];
        uVar6 = (uint)*(ushort *)((int)pvVar9 + 6);
        vVar10 = pvVar9[2];
        pvVar9 = pvVar9 + 3;
      }
      uVar6 = uVar6 * vVar10 + 7 >> 3;
      bVar3 = local_10 - 0x10 < 6;
      if (bVar3) {
        if ((bVar4 & 1) == 0) {
          local_14 = (vm_address_t *)*pvVar9;
        }
        else {
          for (pvVar7 = pvVar9 + vVar10; local_14 = pvVar9, pvVar5 < pvVar7; pvVar7 = pvVar7 + -1) {
            vVar10 = vVar10 - 1;
          }
        }
        uVar8 = 0;
        if (vVar10 != 0) {
          do {
            vVar2 = local_14[uVar8];
            if ((vVar2 != 0) && (vVar2 != 0xffffffff)) {
              _ipc_object_destroy(vVar2,local_10);
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < vVar10);
        }
      }
      if ((bVar4 & 1) == 0) {
        if (uVar6 != 0) {
          if (bVar3) {
            _kfree(*pvVar9,uVar6);
          }
          else {
            _vm_deallocate(_ipc_soft_map,*pvVar9,uVar6);
          }
        }
        pvVar9 = pvVar9 + 1;
      }
      else {
        pvVar9 = (vm_address_t *)((int)pvVar9 + (uVar6 + 3 & 0xfffffffc));
      }
    }
  }
  return;
}

