/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014beb4 */

int _ipc_object_copyout_name(int param_1,int *param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined1 local_10 [4];
  int local_c;
  int local_8;
  
  iVar1 = _ipc_entry_alloc_name(param_1,param_5,&local_8);
  if (iVar1 != 0) {
    return iVar1;
  }
  if ((param_3 == 0x12) ||
     (iVar1 = _ipc_right_reverse(param_1,param_2,&local_c,local_10), iVar1 == 0)) {
    iVar1 = _ipc_right_inuse(param_1,param_5,local_8);
    if (iVar1 != 0) {
      return 0xd;
    }
    do {
      do {
      } while (*param_2 != 0);
      LOCK();
      iVar1 = *param_2;
      *param_2 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if (-1 < param_2[2]) {
      LOCK();
      *param_2 = 0;
      UNLOCK();
      _ipc_entry_dealloc(param_1,param_5,local_8);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      return 0x14;
    }
    *(int **)(local_8 + 4) = param_2;
  }
  else if (local_c != param_5) {
    LOCK();
    *param_2 = 0;
    UNLOCK();
    if ((*(byte *)(local_8 + 2) & 0x1f) == 0) {
      _ipc_entry_dealloc(param_1,param_5,local_8);
    }
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    return 0x15;
  }
  iVar1 = _ipc_right_copyout(param_1,param_5,local_8,param_3,param_4,param_2);
  LOCK();
  *(undefined4 *)(param_1 + 8) = 0;
  UNLOCK();
  return iVar1;
}

