
void _ipc_processor_init(int param_1)

{
  int iVar1;
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcProcessorIn);
  }
  *(int *)(param_1 + 0x138) = iVar1;
  _ipc_kobject_set(iVar1,param_1,5);
  return;
}

