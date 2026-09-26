/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016ead4 */

void FUN_0016ead4(int *param_1,int param_2)

{
  processor_set_t processor_set;
  kern_return_t kVar1;
  
  if ((((param_1[1] == 0x28) && (-1 < *param_1)) && (param_1[6] == DAT_001e017c)) &&
     (param_1[8] == DAT_001e0180)) {
    processor_set = _convert_port_to_pset(param_1[2]);
    kVar1 = _processor_set_max_priority(processor_set,param_1[7],param_1[9]);
    *(kern_return_t *)(param_2 + 0x1c) = kVar1;
    _pset_deallocate(processor_set);
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0xfffffed0;
  }
  return;
}

