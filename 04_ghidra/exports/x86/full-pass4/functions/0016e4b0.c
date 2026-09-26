/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016e4b0 */

void FUN_0016e4b0(int *param_1,uint *param_2)

{
  processor_set_name_t set_name;
  uint uVar1;
  mach_msg_type_number_t local_c;
  host_t local_8;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e0130)) {
    set_name = _convert_port_to_pset_name(param_1[2]);
    local_c = 0x400;
    uVar1 = _processor_set_info(set_name,param_1[7],&local_8,(processor_set_info_t)(param_2 + 0xd),
                                &local_c);
    param_2[7] = uVar1;
    _pset_deallocate(set_name);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[8] = DAT_001e0134;
      uVar1 = _convert_host_to_port(local_8);
      param_2[9] = uVar1;
      param_2[10] = DAT_001e0138;
      param_2[0xb] = (uint)PTR_s__62I__001e013c;
      param_2[0xc] = DAT_001e0140;
      param_2[0xc] = local_c;
      param_2[1] = local_c * 4 + 0x34;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

