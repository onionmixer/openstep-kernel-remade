/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014f804 */

void _ipc_right_copyin_undo
               (undefined4 param_1,undefined4 param_2,uint *param_3,int param_4,int *param_5,
               int param_6)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_3;
  if (param_6 == 0) {
    if ((uVar2 & 0x1f0000) == 0) {
      *param_3 = uVar2 & 0xff800000 | 0x100001;
    }
    else if ((uVar2 & 0x1f0000) == 0x100000) {
      if (param_4 != 0x13) {
        *param_3 = uVar2 + 1;
      }
    }
    else {
      if (param_4 != 0x13) {
        *param_3 = uVar2 + 1;
      }
      do {
        do {
        } while (*param_5 != 0);
        LOCK();
        iVar1 = *param_5;
        *param_5 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      if (-1 < param_5[2]) {
        LOCK();
        *param_5 = 0;
        UNLOCK();
        uVar2 = *param_3;
        if ((uVar2 & 0x10000) != 0) {
          if ((uVar2 & 0x200000) != 0) {
            uVar2 = uVar2 & 0xffdfffff;
            _ipc_marequest_cancel(param_1,param_2);
          }
          _ipc_hash_delete(param_1,param_5,param_2,param_3);
        }
        _ipc_object_release(param_5);
        if ((uVar2 & 0x400000) == 0) {
          uVar2 = uVar2 & 0xffe0ffff | 0x100000;
          if (param_3[2] != 0) {
            param_3[2] = 0;
            uVar2 = uVar2 + 1;
          }
          *param_3 = uVar2;
          param_3[1] = 0;
        }
        else {
          param_3[2] = 0;
          param_3[1] = 0;
          _ipc_entry_dealloc(param_1,param_2,param_3);
        }
      }
    }
  }
  else {
    *param_3 = uVar2 & 0xff800000 | 0x100002;
  }
  if (param_5 != (int *)0xffffffff) {
    _ipc_object_release(param_5);
  }
  return;
}

