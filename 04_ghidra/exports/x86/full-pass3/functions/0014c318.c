/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014c318 */

int _ipc_object_copyout_name_compat(uint param_1,int *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  uint local_14;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  uint *local_8;
  
  while( true ) {
    iVar1 = _ipc_entry_alloc_name(param_1,param_4,&local_8);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = _ipc_right_inuse(param_1,param_4,local_8);
    if (iVar1 != 0) {
      return 0xd;
    }
    if ((param_3 != 0x12) &&
       (iVar1 = _ipc_right_reverse(param_1,param_2,local_c,local_10), iVar1 != 0)) {
      LOCK();
      *param_2 = 0;
      UNLOCK();
      _ipc_entry_dealloc(param_1,param_4,local_8);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      return 0x15;
    }
    do {
      do {
      } while (*param_2 != 0);
      LOCK();
      iVar1 = *param_2;
      *param_2 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if (-1 < param_2[2]) break;
    iVar1 = _ipc_port_dnrequest(param_2,param_4,param_1 | 1,&local_14);
    if (iVar1 == 0) {
      _ipc_space_reference(param_1);
      local_8[1] = (uint)param_2;
      local_8[2] = local_14;
      *local_8 = *local_8 | 0x400000;
      iVar1 = _ipc_right_copyout(param_1,param_4,local_8,param_3,1,param_2);
      LOCK();
      *(undefined4 *)(param_1 + 8) = 0;
      UNLOCK();
      return iVar1;
    }
    _ipc_entry_dealloc(param_1,param_4,local_8);
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    iVar1 = _ipc_port_dngrow(param_2);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  LOCK();
  *param_2 = 0;
  UNLOCK();
  _ipc_entry_dealloc(param_1,param_4,local_8);
  LOCK();
  *(undefined4 *)(param_1 + 8) = 0;
  UNLOCK();
  return 0x14;
}

