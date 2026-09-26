/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014f938 */

undefined4
_ipc_right_copyin_two
          (undefined4 param_1,undefined4 param_2,uint *param_3,undefined4 *param_4,
          undefined4 *param_5)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 local_10;
  
  uVar2 = *param_3;
  local_10 = 0;
  if (((uVar2 & 0x10000) != 0) && (1 < (uVar2 & 0xffff))) {
    piVar3 = (int *)param_3[1];
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if (piVar3[2] < 0) {
      if ((uVar2 & 0xffff) == 2) {
        if ((uVar2 & 0x20000) == 0) {
          if (param_3[2] == 0) {
            local_10 = 0;
          }
          else {
            local_10 = _ipc_port_dncancel(piVar3,param_2,param_3[2]);
            param_3[2] = 0;
            if ((*param_3 & 0x400000) != 0) {
              _ipc_space_release(param_1);
              local_10 = 0;
            }
          }
          _ipc_hash_delete(param_1,piVar3,param_2,param_3);
          if ((uVar2 & 0x200000) != 0) {
            _ipc_marequest_cancel(param_1,param_2);
          }
          piVar3[7] = piVar3[7] + 1;
          piVar3[1] = piVar3[1] + 1;
          param_3[1] = 0;
        }
        else {
          piVar3[7] = piVar3[7] + 1;
          piVar3[1] = piVar3[1] + 2;
        }
        *param_3 = uVar2 & 0xfffe0000;
      }
      else {
        piVar3[7] = piVar3[7] + 2;
        piVar3[1] = piVar3[1] + 2;
        *param_3 = uVar2 - 2;
      }
      LOCK();
      *piVar3 = 0;
      UNLOCK();
      *param_4 = piVar3;
      *param_5 = local_10;
      return 0;
    }
    LOCK();
    *piVar3 = 0;
    UNLOCK();
    uVar4 = *param_3;
    if ((uVar4 & 0x10000) != 0) {
      if ((uVar4 & 0x200000) != 0) {
        uVar4 = uVar4 & 0xffdfffff;
        _ipc_marequest_cancel(param_1,param_2);
      }
      _ipc_hash_delete(param_1,piVar3,param_2,param_3);
    }
    _ipc_object_release(piVar3);
    if ((uVar4 & 0x400000) == 0) {
      uVar4 = uVar4 & 0xffe0ffff | 0x100000;
      if (param_3[2] != 0) {
        param_3[2] = 0;
        uVar4 = uVar4 + 1;
      }
      *param_3 = uVar4;
      param_3[1] = 0;
    }
    else {
      param_3[2] = 0;
      param_3[1] = 0;
      _ipc_entry_dealloc(param_1,param_2,param_3);
    }
    if ((uVar2 & 0x400000) != 0) {
      return 0xf;
    }
  }
  return 0x11;
}

