/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014cb0c */

void _ipc_port_delete_compat(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int local_8;
  
  iVar1 = _ipc_right_lookup_write(param_2,param_3,&local_8);
  if (iVar1 == 0) {
    if (*(int *)(local_8 + 4) == param_1) {
      iVar1 = _ipc_port_copy_send(*(undefined4 *)(param_2 + 0x44));
      _ipc_right_destroy(param_2,param_3,local_8);
    }
    else {
      LOCK();
      *(undefined4 *)(param_2 + 8) = 0;
      UNLOCK();
      iVar1 = 0;
    }
    if ((iVar1 != 0) && (iVar1 != -1)) {
      _ipc_notify_port_deleted_compat(iVar1,param_3);
    }
  }
  _ipc_space_release(param_2);
  return;
}

