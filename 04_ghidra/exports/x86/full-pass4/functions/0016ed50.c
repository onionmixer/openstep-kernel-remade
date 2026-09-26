/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016ed50 */

void FUN_0016ed50(int *param_1,uint *param_2)

{
  host_priv_t host_priv;
  uint uVar1;
  processor_set_name_array_t *processor_sets;
  uint *processor_setsCnt;
  uint local_8;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    processor_setsCnt = &local_8;
    processor_sets = (processor_set_name_array_t *)(param_2 + 0xb);
    host_priv = _convert_port_to_host(param_1[2]);
    uVar1 = _host_processor_sets(host_priv,processor_sets,processor_setsCnt);
    param_2[7] = uVar1;
    if (uVar1 == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x30;
      param_2[8] = DAT_001e01b0;
      param_2[9] = DAT_001e01b4;
      param_2[10] = DAT_001e01b8;
      param_2[10] = local_8;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

