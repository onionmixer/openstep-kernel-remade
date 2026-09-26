/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0015612c */

int _port_set_backup(int param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint local_18;
  undefined1 local_14 [4];
  uint local_10;
  int local_c;
  int *local_8;
  
  if (param_1 != 0) {
    if (param_3 == 0xffffffff) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      if (param_3 != 0) {
        uVar2 = param_3 | 1;
      }
    }
    iVar1 = _ipc_right_lookup_write(param_1,param_2,&local_c);
    if ((iVar1 == 0) &&
       (iVar1 = _ipc_right_info(param_1,param_2,local_c,&local_10,local_14), iVar1 == 0)) {
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
      _ipc_port_pdrequest(local_8,uVar2,&local_18);
      if (local_18 != 0) {
        if ((local_18 & 1) == 0) {
          _ipc_notify_send_once(local_18);
          local_18 = 0;
        }
        else {
          local_18 = local_18 & 0xfffffffe;
        }
      }
      *param_4 = local_18;
      return 0;
    }
  }
  return 4;
}

