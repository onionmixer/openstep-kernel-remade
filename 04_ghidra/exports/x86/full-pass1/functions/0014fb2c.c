/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014fb2c */

undefined4
_ipc_right_copyout(undefined4 param_1,undefined4 param_2,uint *param_3,uint param_4,int param_5,
                  undefined4 *param_6)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *param_3;
  if (param_4 != 0x11) {
    if (param_4 < 0x12) {
      if (param_4 == 0x10) {
        iVar2 = param_6[3];
        param_6[4] = param_2;
        param_6[3] = param_1;
        if ((uVar1 & 0x10000) == 0) {
          LOCK();
          *param_6 = 0;
          UNLOCK();
        }
        else {
          param_6[1] = param_6[1] + -1;
          LOCK();
          *param_6 = 0;
          UNLOCK();
          _ipc_hash_delete(param_1,param_6,param_2,param_3);
        }
        *param_3 = uVar1 | 0x20000;
        if (iVar2 == 0) {
          return 0;
        }
        _ipc_object_release(iVar2);
        return 0;
      }
    }
    else if (param_4 == 0x12) {
      LOCK();
      *param_6 = 0;
      UNLOCK();
      *param_3 = uVar1 | 0x40001;
      return 0;
    }
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_right_copyout__strange_right_001de9ff);
  }
  if ((uVar1 & 0x10000) == 0) {
    if ((uVar1 & 0x20000) == 0) {
      LOCK();
      *param_6 = 0;
      UNLOCK();
      _ipc_hash_insert(param_1,param_6,param_2,param_3);
      goto LAB_0014fbd4;
    }
  }
  else {
    if ((short)uVar1 == -2) {
      if (param_5 != 0) {
        param_6[7] = param_6[7] + -1;
        param_6[1] = param_6[1] + -1;
        LOCK();
        *param_6 = 0;
        UNLOCK();
        return 0;
      }
      LOCK();
      *param_6 = 0;
      UNLOCK();
      return 0x13;
    }
    param_6[7] = param_6[7] + -1;
  }
  param_6[1] = param_6[1] + -1;
  LOCK();
  *param_6 = 0;
  UNLOCK();
LAB_0014fbd4:
  *param_3 = (uVar1 | 0x10000) + 1;
  return 0;
}

