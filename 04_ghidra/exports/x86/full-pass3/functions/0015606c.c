/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015606c */

int _port_set_backlog(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 local_14 [4];
  uint local_10;
  int local_c;
  int *local_8;
  
  if ((((param_1 == 0) || (0xf < param_3 - 1U)) ||
      (iVar1 = _ipc_right_lookup_write(param_1,param_2,&local_c), iVar1 != 0)) ||
     (iVar1 = _ipc_right_info(param_1,param_2,local_c,&local_10,local_14), iVar1 != 0)) {
    return 4;
  }
  if ((local_10 & 0x20000) == 0) {
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    iVar1 = 4;
    if ((local_10 & 0x170000) != 0) {
      return 7;
    }
  }
  else {
    local_8 = *(int **)(local_c + 4);
    do {
      do {
      } while (*local_8 != 0);
      LOCK();
      iVar1 = *local_8;
      *local_8 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    iVar1 = 0;
  }
  if (iVar1 != 0) {
    return iVar1;
  }
  _ipc_port_set_qlimit(local_8,param_3);
  LOCK();
  *local_8 = 0;
  UNLOCK();
  return 0;
}

