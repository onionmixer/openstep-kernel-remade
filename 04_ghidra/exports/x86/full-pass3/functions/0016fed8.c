/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016fed8 */

void FUN_0016fed8(int *param_1,uint *param_2)

{
  vm_map_t target_task;
  uint uVar1;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e03f0)) {
    target_task = _convert_port_to_map(param_1[2]);
    uVar1 = _vm_region(target_task,(vm_address_t *)(param_1 + 7),param_2 + 0xb,
                       (vm_region_flavor_t)(param_2 + 0xd),(vm_region_info_t)(param_2 + 0xf),
                       param_2 + 0x11,param_2 + 0x13);
    param_2[7] = uVar1;
    _vm_map_deallocate(target_task);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x60;
      param_2[8] = DAT_001e03f4;
      param_2[9] = param_1[7];
      param_2[10] = DAT_001e03f8;
      param_2[0xc] = DAT_001e03fc;
      param_2[0xe] = DAT_001e0400;
      param_2[0x10] = DAT_001e0404;
      param_2[0x12] = DAT_001e0408;
      param_2[0x14] = DAT_001e040c;
      param_2[0x16] = DAT_001e0410;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

