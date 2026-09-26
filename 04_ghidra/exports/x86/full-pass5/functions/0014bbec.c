/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014bbec */

int _ipc_object_copyin(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int local_c;
  int local_8;
  
  iVar1 = _ipc_right_lookup_write(param_1,param_2,&local_8);
  if (iVar1 == 0) {
    iVar1 = _ipc_right_copyin(param_1,param_2,local_8,param_3,1,param_4,&local_c);
    if ((*(byte *)(local_8 + 2) & 0x1f) == 0) {
      _ipc_entry_dealloc(param_1,param_2,local_8);
    }
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    if ((iVar1 == 0) && (local_c != 0)) {
      _ipc_notify_port_deleted(local_c,param_2);
    }
  }
  return iVar1;
}

