/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001563c8 */

int _port_set_deallocate(int param_1,undefined4 param_2)

{
  int iVar1;
  int local_8;
  
  if (param_1 == 0) {
    iVar1 = 4;
  }
  else {
    iVar1 = _ipc_right_lookup_write(param_1,param_2,&local_8);
    if (iVar1 == 0) {
      if ((*(byte *)(local_8 + 2) & 8) == 0) {
        LOCK();
        *(undefined4 *)(param_1 + 8) = 0;
        UNLOCK();
        iVar1 = 4;
      }
      else {
        iVar1 = _ipc_right_destroy(param_1,param_2,local_8);
      }
    }
  }
  return iVar1;
}

