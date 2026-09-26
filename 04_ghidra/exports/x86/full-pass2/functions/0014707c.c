/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014707c */

void _ipc_kmsg_clean_body(vm_address_t *param_1,vm_address_t *param_2)

{
  vm_address_t vVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  vm_address_t *pvVar5;
  uint uVar6;
  vm_address_t vVar7;
  vm_address_t *local_10;
  uint local_8;
  
  while (param_1 < param_2) {
    bVar3 = *(byte *)((int)param_1 + 3) >> 4;
    if ((*(byte *)((int)param_1 + 3) & 0x20) == 0) {
      local_8 = (uint)(byte)*param_1;
      uVar4 = (uint)*(byte *)((int)param_1 + 1);
      vVar7 = *(ushort *)((int)param_1 + 2) & 0xfff;
      param_1 = param_1 + 1;
    }
    else {
      local_8 = (uint)(ushort)param_1[1];
      uVar4 = (uint)*(ushort *)((int)param_1 + 6);
      vVar7 = param_1[2];
      param_1 = param_1 + 3;
    }
    uVar4 = uVar4 * vVar7 + 7 >> 3;
    bVar2 = local_8 - 0x10 < 6;
    if (bVar2) {
      if ((bVar3 & 1) == 0) {
        local_10 = (vm_address_t *)*param_1;
      }
      else {
        for (pvVar5 = param_1 + vVar7; local_10 = param_1, param_2 < pvVar5; pvVar5 = pvVar5 + -1) {
          vVar7 = vVar7 - 1;
        }
      }
      uVar6 = 0;
      if (vVar7 != 0) {
        do {
          vVar1 = local_10[uVar6];
          if ((vVar1 != 0) && (vVar1 != 0xffffffff)) {
            _ipc_object_destroy(vVar1,local_8);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < vVar7);
      }
    }
    if ((bVar3 & 1) == 0) {
      if (uVar4 != 0) {
        if (bVar2) {
          _kfree(*param_1,uVar4);
        }
        else {
          _vm_deallocate(_ipc_soft_map,*param_1,uVar4);
        }
      }
      param_1 = param_1 + 1;
    }
    else {
      param_1 = (vm_address_t *)((int)param_1 + (uVar4 + 3 & 0xfffffffc));
    }
  }
  return;
}

