
void _ipc_host_init(void)

{
  int iVar1;
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcHostInit);
  }
  _ipc_kobject_set(iVar1,&_realhost,3);
  _realhost = iVar1;
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(aIpcHostInit);
  }
  _ipc_kobject_set(iVar1,&_realhost,4);
  dword_40B67DC = iVar1;
  _ipc_pset_init(_default_pset);
  _ipc_pset_enable(_default_pset);
  _ipc_processor_init(_master_processor);
  return;
}

