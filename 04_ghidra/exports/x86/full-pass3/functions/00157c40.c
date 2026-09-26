/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00157c40 */

void _ipc_host_init(void)

{
  int iVar1;
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_host_init_001deba0);
  }
  _ipc_kobject_set(iVar1,&_realhost,3);
  _realhost = iVar1;
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_host_init_001debae);
  }
  _ipc_kobject_set(iVar1,&_realhost,4);
  DAT_001e97b4 = iVar1;
  _ipc_pset_init(&_default_pset);
  _ipc_pset_enable(&_default_pset);
  _ipc_processor_init(_master_processor);
  return;
}

