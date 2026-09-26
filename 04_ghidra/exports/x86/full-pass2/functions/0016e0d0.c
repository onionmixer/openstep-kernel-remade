/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016e0d0 */

void FUN_0016e0d0(int *param_1,uint *param_2)

{
  host_priv_t host_priv;
  uint uVar1;
  processor_array_t *out_processor_list;
  uint *out_processor_listCnt;
  uint local_8;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    out_processor_listCnt = &local_8;
    out_processor_list = (processor_array_t *)(param_2 + 0xb);
    host_priv = _convert_port_to_host_priv(param_1[2]);
    uVar1 = _host_processors(host_priv,out_processor_list,out_processor_listCnt);
    param_2[7] = uVar1;
    if (uVar1 == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x30;
      param_2[8] = DAT_001e00f4;
      param_2[9] = DAT_001e00f8;
      param_2[10] = DAT_001e00fc;
      param_2[10] = local_8;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

