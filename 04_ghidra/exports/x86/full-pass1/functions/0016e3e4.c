/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016e3e4 */

void FUN_0016e3e4(int *param_1,uint *param_2)

{
  host_t host;
  uint uVar1;
  processor_set_t *new_set;
  processor_set_name_t *new_name;
  processor_set_name_t local_c;
  processor_set_t local_8;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    new_name = &local_c;
    new_set = &local_8;
    host = _convert_port_to_host(param_1[2]);
    uVar1 = _processor_set_create(host,new_set,new_name);
    param_2[7] = uVar1;
    if (uVar1 == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x30;
      param_2[8] = DAT_001e0128;
      uVar1 = _convert_pset_to_port(local_8);
      param_2[9] = uVar1;
      param_2[10] = DAT_001e012c;
      uVar1 = _convert_pset_name_to_port(local_c);
      param_2[0xb] = uVar1;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

