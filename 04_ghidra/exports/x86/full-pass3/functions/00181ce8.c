/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00181ce8 */

undefined4 _create_dev_port(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _ipc_port_alloc_special(_ipc_space_kernel);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    _ipc_kobject_set(iVar1,param_1,0xc);
    uVar2 = _IOConvertPort(iVar1,0,1);
  }
  return uVar2;
}

