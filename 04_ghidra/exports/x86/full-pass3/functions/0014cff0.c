/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014cff0 */

int _ipc_port_copyout_send(int param_1,undefined4 param_2)

{
  int iVar1;
  int local_8;
  
  if ((param_1 == 0) || (param_1 == -1)) {
    local_8 = param_1;
  }
  else {
    iVar1 = _ipc_object_copyout(param_2,param_1,0x11,1,&local_8);
    if (iVar1 != 0) {
      _ipc_port_release_send(param_1);
      if (iVar1 == 0x14) {
        local_8 = -1;
      }
      else {
        local_8 = 0;
      }
    }
  }
  return local_8;
}

