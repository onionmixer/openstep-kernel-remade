/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016fd5c */

void FUN_0016fd5c(int *param_1,uint *param_2)

{
  vm_map_t target_task;
  uint uVar1;
  uint local_8;
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == DAT_001e03cc)) &&
     (param_1[8] == DAT_001e03d0)) {
    target_task = _convert_port_to_map(param_1[2]);
    uVar1 = _vm_read(target_task,param_1[7],param_1[9],param_2 + 0xb,&local_8);
    param_2[7] = uVar1;
    _vm_map_deallocate(target_task);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x30;
      param_2[8] = DAT_001e03d4;
      param_2[9] = DAT_001e03d8;
      param_2[10] = DAT_001e03dc;
      param_2[10] = local_8;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

