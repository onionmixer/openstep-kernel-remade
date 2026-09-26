/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014dec0 */

undefined4 _ipc_right_check(undefined4 param_1,int *param_2,undefined4 param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  do {
    do {
    } while (*param_2 != 0);
    LOCK();
    iVar1 = *param_2;
    *param_2 = 1;
    UNLOCK();
  } while (iVar1 == 1);
  if (param_2[2] < 0) {
    uVar2 = 0;
  }
  else {
    LOCK();
    *param_2 = 0;
    UNLOCK();
    uVar3 = *param_4;
    if ((uVar3 & 0x10000) != 0) {
      if ((uVar3 & 0x200000) != 0) {
        uVar3 = uVar3 & 0xffdfffff;
        _ipc_marequest_cancel(param_1,param_3);
      }
      _ipc_hash_delete(param_1,param_2,param_3,param_4);
    }
    _ipc_object_release(param_2);
    if ((uVar3 & 0x400000) == 0) {
      uVar3 = uVar3 & 0xffe0ffff | 0x100000;
      if (param_4[2] != 0) {
        param_4[2] = 0;
        uVar3 = uVar3 + 1;
      }
      *param_4 = uVar3;
      param_4[1] = 0;
    }
    else {
      param_4[2] = 0;
      param_4[1] = 0;
      _ipc_entry_dealloc(param_1,param_3,param_4);
    }
    uVar2 = 1;
  }
  return uVar2;
}

