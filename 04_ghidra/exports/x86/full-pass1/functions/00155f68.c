/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00155f68 */

int _port_rename(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else if ((param_3 == 0) || (param_3 == -1)) {
    iVar1 = 0x12;
  }
  else {
    iVar1 = _ipc_object_rename(param_1,param_2,param_3);
    if (iVar1 == 0) {
      return 0;
    }
  }
  if (iVar1 != 0xd) {
    iVar1 = 4;
  }
  return iVar1;
}

