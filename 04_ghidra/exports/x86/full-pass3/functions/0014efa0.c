/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014efa0 */

undefined4 _ipc_right_info(int param_1,undefined4 param_2,uint *param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *param_3;
  if ((uVar4 & 0x50000) != 0) {
    piVar2 = (int *)param_3[1];
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar1 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if (piVar2[2] < 0) {
      LOCK();
      *piVar2 = 0;
      UNLOCK();
    }
    else {
      LOCK();
      *piVar2 = 0;
      UNLOCK();
      uVar3 = *param_3;
      if ((uVar3 & 0x10000) != 0) {
        if ((uVar3 & 0x200000) != 0) {
          uVar3 = uVar3 & 0xffdfffff;
          _ipc_marequest_cancel(param_1,param_2);
        }
        _ipc_hash_delete(param_1,piVar2,param_2,param_3);
      }
      _ipc_object_release(piVar2);
      if ((uVar3 & 0x400000) == 0) {
        uVar3 = uVar3 & 0xffe0ffff | 0x100000;
        if (param_3[2] != 0) {
          param_3[2] = 0;
          uVar3 = uVar3 + 1;
        }
        *param_3 = uVar3;
        param_3[1] = 0;
      }
      else {
        param_3[2] = 0;
        param_3[1] = 0;
        _ipc_entry_dealloc(param_1,param_2,param_3);
      }
      if ((uVar4 & 0x400000) != 0) {
        LOCK();
        *(undefined4 *)(param_1 + 8) = 0;
        UNLOCK();
        return 0xf;
      }
      uVar4 = *param_3;
    }
  }
  uVar3 = uVar4 & 0x1f0000;
  if ((uVar4 & 0x400000) == 0) {
    if (param_3[2] != 0) {
      uVar3 = uVar3 | 0x80000000;
    }
  }
  else {
    uVar3 = uVar3 | 0x20000000;
  }
  if ((uVar4 & 0x200000) != 0) {
    uVar3 = uVar3 | 0x40000000;
  }
  *param_4 = uVar3;
  *param_5 = uVar4 & 0xffff;
  return 0;
}

