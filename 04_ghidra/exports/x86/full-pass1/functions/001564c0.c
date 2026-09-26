/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001564c0 */

undefined4 _port_set_remove(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_10 [4];
  uint local_c;
  int local_8;
  
  if (((param_1 != 0) && (iVar1 = _ipc_right_lookup_write(param_1,param_2,&local_8), iVar1 == 0)) &&
     (iVar1 = _ipc_right_info(param_1,param_2,local_8,&local_c,local_10), iVar1 == 0)) {
    if ((local_c & 0x20000) != 0) {
      uVar2 = _ipc_pset_move(param_1,*(undefined4 *)(local_8 + 4),0);
      return uVar2;
    }
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    if ((local_c & 0x170000) != 0) {
      return 7;
    }
  }
  return 4;
}

