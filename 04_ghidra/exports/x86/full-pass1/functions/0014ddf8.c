/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014ddf8 */

undefined4 _ipc_right_inuse(int param_1,undefined4 param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar2 = *param_3;
  uVar4 = uVar2 & 0x1f0000;
  if (uVar4 == 0) {
LAB_0014deb4:
    uVar5 = 0;
  }
  else {
    if (((uVar2 & 0x400000) != 0) && ((uVar4 == 0x10000 || (uVar4 == 0x40000)))) {
      piVar3 = (int *)param_3[1];
      do {
        do {
        } while (*piVar3 != 0);
        LOCK();
        iVar1 = *piVar3;
        *piVar3 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      LOCK();
      *piVar3 = 0;
      UNLOCK();
      if (-1 < piVar3[2]) {
        if (uVar4 == 0x10000) {
          if ((uVar2 & 0x200000) != 0) {
            _ipc_marequest_cancel(param_1,param_2);
          }
          _ipc_hash_delete(param_1,piVar3,param_2,param_3);
        }
        _ipc_object_release(piVar3);
        param_3[2] = 0;
        param_3[1] = 0;
        *param_3 = *param_3 & 0xff800000;
        goto LAB_0014deb4;
      }
    }
    LOCK();
    *(undefined4 *)(param_1 + 8) = 0;
    UNLOCK();
    uVar5 = 1;
  }
  return uVar5;
}

