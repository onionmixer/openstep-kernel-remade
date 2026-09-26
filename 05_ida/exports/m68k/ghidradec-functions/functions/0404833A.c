
void _ipc_pset_init(int param_1)

{
  int iVar1;
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcPsetInit);
  }
  *(int *)(param_1 + 0x14c) = iVar1;
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcPsetInit);
  }
  *(int *)(param_1 + 0x150) = iVar1;
  return;
}
