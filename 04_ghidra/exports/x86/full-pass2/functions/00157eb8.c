/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00157eb8 */

void _ipc_pset_terminate(int param_1)

{
  _ipc_port_dealloc_special(*(undefined4 *)(param_1 + 0x15c),_ipc_space_kernel);
  _ipc_port_dealloc_special(*(undefined4 *)(param_1 + 0x160),_ipc_space_kernel);
  return;
}

