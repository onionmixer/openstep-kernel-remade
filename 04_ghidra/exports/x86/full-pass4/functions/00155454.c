/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00155454 */

int _mach_port_set_qlimit(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 *local_8;
  
  if (param_1 == 0) {
    iVar1 = 0x10;
  }
  else if (param_3 < 0x11) {
    iVar1 = _ipc_object_translate(param_1,param_2,1,&local_8);
    if (iVar1 == 0) {
      _ipc_port_set_qlimit(local_8,param_3);
      LOCK();
      *local_8 = 0;
      UNLOCK();
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 0x12;
  }
  return iVar1;
}

