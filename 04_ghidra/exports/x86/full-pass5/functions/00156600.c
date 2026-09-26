/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00156600 */

int _port_insert_receive(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((((param_1 == 0) || (param_3 == 0)) || (param_3 == -1)) || ((param_2 == 0 || (param_2 == -1)))
     ) {
    return 4;
  }
  iVar1 = _ipc_object_copyout_name_compat(param_1,param_2,0x10,param_3);
  if (iVar1 != 6) {
    if (iVar1 < 7) {
      if (iVar1 == 0) {
        return 0;
      }
    }
    else {
      if (iVar1 == 0xd) {
        return 0xd;
      }
      if (iVar1 == 0x15) {
        return 5;
      }
    }
    iVar1 = 4;
  }
  return iVar1;
}

