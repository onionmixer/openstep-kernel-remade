/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016f068 */

void FUN_0016f068(int *param_1,uint *param_2)

{
  ipc_space_t task;
  uint uVar1;
  uint local_c;
  uint local_8;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    task = _convert_port_to_space(param_1[2]);
    uVar1 = _mach_port_names(task,(mach_port_name_array_t *)(param_2 + 0xb),&local_8,
                             (mach_port_type_array_t *)(param_2 + 0xf),&local_c);
    param_2[7] = uVar1;
    _space_deallocate(task);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x40;
      param_2[8] = DAT_001e027c;
      param_2[9] = DAT_001e0280;
      param_2[10] = DAT_001e0284;
      param_2[10] = local_8;
      param_2[0xc] = DAT_001e0288;
      param_2[0xd] = (uint)PTR_s__62I__001e028c;
      param_2[0xe] = DAT_001e0290;
      param_2[0xe] = local_c;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

