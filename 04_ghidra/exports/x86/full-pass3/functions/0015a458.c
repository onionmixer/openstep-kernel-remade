/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015a458 */

int __lookupd_port(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  int local_8;
  
  iVar2 = *(int *)(_active_threads + 0xc);
  if (param_1 == 0) {
    local_8 = _lookupd_port;
    if (_lookupd_port == 0) {
      local_c = 0;
      param_1 = local_c;
    }
    else {
      uVar3 = _ipc_port_copy_send(_lookupd_port,0x11,1,&local_c);
      _ipc_object_copyout(*(undefined4 *)(iVar2 + 0x88),uVar3);
      param_1 = local_c;
    }
  }
  else {
    iVar1 = _suser();
    if ((iVar1 == 0) ||
       (iVar2 = _ipc_object_copyin(*(undefined4 *)(iVar2 + 0x88),param_1,0x14,&local_8), iVar2 != 0)
       ) {
      param_1 = 0;
    }
    else {
      if (_lookupd_port != 0) {
        _ipc_port_release_send(_lookupd_port);
      }
      _lookupd_port = local_8;
    }
  }
  return param_1;
}

