/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00176064 */

void _vm_map_entry_unwire(undefined4 param_1,int param_2)

{
  _vm_fault_unwire(param_1,param_2);
  *(undefined2 *)(param_2 + 0x28) = 0;
  return;
}

