/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00157d30 */

void _ipc_processor_init(int param_1)

{
  int iVar1;
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_processor_init_001debbc);
  }
  *(int *)(param_1 + 0x140) = iVar1;
  _ipc_kobject_set(iVar1,param_1,5);
  return;
}

