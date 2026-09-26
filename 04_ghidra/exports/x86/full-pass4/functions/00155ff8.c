/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00155ff8 */

undefined4 _port_deallocate(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_10 [4];
  undefined1 local_c [2];
  byte local_a;
  undefined4 local_8;
  
  if (((param_1 != 0) && (iVar1 = _ipc_right_lookup_write(param_1,param_2,&local_8), iVar1 == 0)) &&
     (iVar1 = _ipc_right_info(param_1,param_2,local_8,local_c,local_10), iVar1 == 0)) {
    if ((local_a & 0x17) != 0) {
      _ipc_right_destroy(param_1,param_2,local_8);
      return 0;
    }
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    return 4;
  }
  return 4;
}

