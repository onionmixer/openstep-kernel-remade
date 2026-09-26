/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016f57c */

void FUN_0016f57c(int *param_1,uint *param_2)

{
  ipc_space_t task;
  uint uVar1;
  uint local_8;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e02ec)) {
    task = _convert_port_to_space(param_1[2]);
    uVar1 = _mach_port_get_set_status
                      (task,param_1[7],(mach_port_name_array_t *)(param_2 + 0xb),&local_8);
    param_2[7] = uVar1;
    _space_deallocate(task);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x30;
      param_2[8] = DAT_001e02f0;
      param_2[9] = DAT_001e02f4;
      param_2[10] = DAT_001e02f8;
      param_2[10] = local_8;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

