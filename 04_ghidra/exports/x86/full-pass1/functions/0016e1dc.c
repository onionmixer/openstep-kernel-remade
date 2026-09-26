/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016e1dc */

void FUN_0016e1dc(int *param_1,uint *param_2)

{
  processor_t processor;
  uint uVar1;
  int flavor;
  host_t *host;
  uint *processor_info_out;
  mach_msg_type_number_t *processor_info_outCnt;
  mach_msg_type_number_t local_c;
  host_t local_8;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e0110)) {
    local_c = 0x400;
    processor_info_outCnt = &local_c;
    processor_info_out = param_2 + 0xd;
    host = &local_8;
    flavor = param_1[7];
    processor = _convert_port_to_processor(param_1[2]);
    uVar1 = _processor_info(processor,flavor,host,(processor_info_t)processor_info_out,
                            processor_info_outCnt);
    param_2[7] = uVar1;
    if (uVar1 == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[8] = DAT_001e0114;
      uVar1 = _convert_host_to_port(local_8);
      param_2[9] = uVar1;
      param_2[10] = DAT_001e0118;
      param_2[0xb] = (uint)PTR_s__62I__001e011c;
      param_2[0xc] = DAT_001e0120;
      param_2[0xc] = local_c;
      param_2[1] = local_c * 4 + 0x34;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

