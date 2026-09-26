/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00157d74 */

void _ipc_pset_init(int param_1)

{
  int iVar1;
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_pset_init_001debcf);
  }
  *(int *)(param_1 + 0x15c) = iVar1;
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_pset_init_001debdd);
  }
  *(int *)(param_1 + 0x160) = iVar1;
  return;
}

