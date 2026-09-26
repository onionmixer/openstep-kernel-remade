/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016eccc */

void FUN_0016eccc(int *param_1,uint *param_2)

{
  processor_set_t processor_set;
  uint uVar1;
  uint local_8;
  
  if ((param_1[1] == 0x18) && (-1 < *param_1)) {
    processor_set = _convert_port_to_pset(param_1[2]);
    uVar1 = _processor_set_threads(processor_set,(thread_act_array_t *)(param_2 + 0xb),&local_8);
    param_2[7] = uVar1;
    _pset_deallocate(processor_set);
    if (param_2[7] == 0) {
      *param_2 = *param_2 | 0x80000000;
      param_2[1] = 0x30;
      param_2[8] = DAT_001e01a4;
      param_2[9] = DAT_001e01a8;
      param_2[10] = DAT_001e01ac;
      param_2[10] = local_8;
    }
  }
  else {
    param_2[7] = 0xfffffed0;
  }
  return;
}

