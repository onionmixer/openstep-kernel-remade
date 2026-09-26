/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014fc44 */

undefined4 _ipc_right_rename(int param_1,undefined4 param_2,uint *param_3,int param_4,uint *param_5)

{
  int iVar1;
  uint local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  local_8 = *param_3;
  local_c = param_3[2];
  local_10 = (int *)param_3[1];
  if (local_c != 0) {
    do {
      do {
      } while (*local_10 != 0);
      LOCK();
      iVar1 = *local_10;
      *local_10 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if (local_10[2] < 0) {
      *(int *)(local_c * 8 + local_10[0xb] + 4) = param_4;
      LOCK();
      *local_10 = 0;
      UNLOCK();
      param_3[2] = 0;
    }
    else {
      LOCK();
      *local_10 = 0;
      UNLOCK();
      local_14 = *param_3;
      if ((local_14 & 0x10000) != 0) {
        if ((local_14 & 0x200000) != 0) {
          local_14 = local_14 & 0xffdfffff;
          _ipc_marequest_cancel(param_1,param_2);
        }
        _ipc_hash_delete(param_1,local_10,param_2,param_3);
      }
      _ipc_object_release(local_10);
      if ((local_14 & 0x400000) == 0) {
        local_14 = local_14 & 0xffe0ffff | 0x100000;
        if (param_3[2] != 0) {
          param_3[2] = 0;
          local_14 = local_14 + 1;
        }
        *param_3 = local_14;
        param_3[1] = 0;
      }
      else {
        param_3[2] = 0;
        param_3[1] = 0;
        _ipc_entry_dealloc(param_1,param_2,param_3);
      }
      if ((local_8 & 0x400000) != 0) {
        _ipc_entry_dealloc(param_1,param_4,param_5);
        LOCK();
        *(undefined4 *)(param_1 + 8) = 0;
        UNLOCK();
        return 0xf;
      }
      local_8 = *param_3;
      local_c = 0;
      local_10 = (int *)0x0;
    }
  }
  if ((local_8 & 0x200000) != 0) {
    _ipc_marequest_rename(param_1,param_2,param_4);
  }
  *param_5 = *param_5 | local_8 & 0x7fffff;
  param_5[2] = local_c;
  param_5[1] = (uint)local_10;
  local_8 = local_8 & 0x1f0000;
  if (local_8 == 0x30000) {
LAB_0014fe58:
    do {
      do {
      } while (*local_10 != 0);
      LOCK();
      iVar1 = *local_10;
      *local_10 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    local_10[4] = param_4;
  }
  else {
    if (local_8 < 0x30001) {
      if (local_8 == 0x10000) {
        _ipc_hash_delete(param_1,local_10,param_2,param_3);
        _ipc_hash_insert(param_1,local_10,param_4,param_5);
        goto LAB_0014fea5;
      }
      if (local_8 != 0x20000) goto LAB_0014fe98;
      goto LAB_0014fe58;
    }
    if (local_8 != 0x80000) {
      if (local_8 < 0x80001) {
        if (local_8 != 0x40000) {
LAB_0014fe98:
                    /* WARNING: Subroutine does not return */
          _panic(s_ipc_right_rename__strange_rights_001dea21);
        }
      }
      else if (local_8 != 0x100000) goto LAB_0014fe98;
      goto LAB_0014fea5;
    }
    do {
      do {
      } while (*local_10 != 0);
      LOCK();
      iVar1 = *local_10;
      *local_10 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    local_10[3] = param_4;
  }
  LOCK();
  *local_10 = 0;
  UNLOCK();
LAB_0014fea5:
  param_3[1] = 0;
  _ipc_entry_dealloc(param_1,param_2,param_3);
  LOCK();
  *(undefined4 *)(param_1 + 8) = 0;
  UNLOCK();
  return 0;
}

