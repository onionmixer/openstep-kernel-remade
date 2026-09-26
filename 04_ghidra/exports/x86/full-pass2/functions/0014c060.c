/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014c060 */

int _ipc_object_rename(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 local_8;
  
  iVar1 = _ipc_entry_alloc_name(param_1,param_3,&local_8);
  if (iVar1 == 0) {
    iVar1 = _ipc_right_inuse(param_1,param_3,local_8);
    if (iVar1 == 0) {
      if ((param_2 != param_3) && (iVar1 = _ipc_entry_lookup(param_1,param_2), iVar1 != 0)) {
        iVar1 = _ipc_right_rename(param_1,param_2,iVar1,param_3,local_8);
        return iVar1;
      }
      _ipc_entry_dealloc(param_1,param_3,local_8);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      iVar1 = 0xf;
    }
    else {
      iVar1 = 0xd;
    }
  }
  return iVar1;
}

