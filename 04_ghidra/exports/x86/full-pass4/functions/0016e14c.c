/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016e14c */

void FUN_0016e14c(int *param_1,int param_2)

{
  host_t host;
  kern_return_t kVar1;
  int flavor;
  host_info_t host_info_out;
  mach_msg_type_number_t *host_info_outCnt;
  mach_msg_type_number_t local_8;
  
  if (((param_1[1] == 0x20) && (-1 < *param_1)) && (param_1[6] == DAT_001e0100)) {
    local_8 = 0x400;
    host_info_outCnt = &local_8;
    host_info_out = (host_info_t)(param_2 + 0x2c);
    flavor = param_1[7];
    host = _convert_port_to_host(param_1[2]);
    kVar1 = _host_info(host,flavor,host_info_out,host_info_outCnt);
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
    if (kVar1 == 0) {
      *(undefined4 *)(param_2 + 0x20) = DAT_001e0104;
      *(undefined **)(param_2 + 0x24) = PTR_s__62I__001e0108;
      *(undefined4 *)(param_2 + 0x28) = DAT_001e010c;
      *(mach_msg_type_number_t *)(param_2 + 0x28) = local_8;
      *(mach_msg_type_number_t *)(param_2 + 4) = local_8 * 4 + 0x2c;
    }
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

