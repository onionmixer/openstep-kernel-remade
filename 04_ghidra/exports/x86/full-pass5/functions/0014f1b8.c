/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0014f1b8 */

undefined4
_ipc_right_copyin(undefined4 param_1,undefined4 param_2,uint *param_3,undefined4 param_4,int param_5
                 ,undefined4 *param_6,undefined4 *param_7)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 local_c;
  uint local_8;
  
  local_8 = *param_3;
  switch(param_4) {
  case 0x10:
    uVar2 = 0;
    if ((local_8 & 0x20000) != 0) {
      piVar3 = (int *)param_3[1];
      do {
        do {
        } while (*piVar3 != 0);
        LOCK();
        iVar1 = *piVar3;
        *piVar3 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      if ((local_8 & 0x10000) == 0) {
        if (param_3[2] == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = _ipc_port_dncancel(piVar3,param_2,param_3[2]);
          param_3[2] = 0;
          if ((*param_3 & 0x400000) != 0) {
            _ipc_space_release(param_1);
            uVar2 = 0;
          }
        }
        if ((local_8 & 0x200000) != 0) {
          _ipc_marequest_cancel(param_1,param_2);
        }
        param_3[1] = 0;
      }
      else {
        _ipc_hash_insert(param_1,piVar3,param_2,param_3);
        piVar3[1] = piVar3[1] + 1;
      }
      *param_3 = local_8 & 0xfffdffff;
      _ipc_port_clear_receiver(piVar3);
      piVar3[4] = 0;
      piVar3[3] = 0;
      LOCK();
      *piVar3 = 0;
      UNLOCK();
      *param_6 = piVar3;
      *param_7 = uVar2;
      return 0;
    }
    return 0x11;
  case 0x11:
    local_c = 0;
    if ((local_8 & 0x100000) == 0) {
      if ((local_8 & 0x50000) == 0) {
        return 0x11;
      }
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
        if ((local_8 & 0x10000) != 0) {
          if ((short)local_8 == 1) {
            if ((local_8 & 0x20000) == 0) {
              if (param_3[2] == 0) {
                local_c = 0;
              }
              else {
                local_c = _ipc_port_dncancel(piVar3,param_2,param_3[2]);
                param_3[2] = 0;
                if ((*param_3 & 0x400000) != 0) {
                  _ipc_space_release(param_1);
                  local_c = 0;
                }
              }
              _ipc_hash_delete(param_1,piVar3,param_2,param_3);
              if ((local_8 & 0x200000) != 0) {
                _ipc_marequest_cancel(param_1,param_2);
              }
              param_3[1] = 0;
            }
            else {
              piVar3[1] = piVar3[1] + 1;
            }
            *param_3 = local_8 & 0xfffe0000;
          }
          else {
            piVar3[7] = piVar3[7] + 1;
            piVar3[1] = piVar3[1] + 1;
            *param_3 = local_8 - 1;
          }
          LOCK();
          *piVar3 = 0;
          UNLOCK();
          *param_6 = piVar3;
          *param_7 = local_c;
          return 0;
        }
LAB_0014f73f:
        LOCK();
        *piVar3 = 0;
        UNLOCK();
        return 0x11;
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
      if ((local_8 & 0x400000) != 0) {
        return 0xf;
      }
      local_8 = *param_3;
    }
    break;
  case 0x12:
    if ((local_8 & 0x100000) == 0) {
      if ((local_8 & 0x50000) == 0) {
        return 0x11;
      }
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
        if ((local_8 & 0x40000) != 0) {
          if (param_3[2] == 0) {
            uVar2 = 0;
          }
          else {
            uVar2 = _ipc_port_dncancel(piVar3,param_2,param_3[2]);
            param_3[2] = 0;
            if ((*param_3 & 0x400000) != 0) {
              _ipc_space_release(param_1);
              uVar2 = 0;
            }
          }
          LOCK();
          *piVar3 = 0;
          UNLOCK();
          param_3[1] = 0;
          *param_3 = local_8 & 0xfffbffff;
          *param_6 = piVar3;
          *param_7 = uVar2;
          return 0;
        }
        goto LAB_0014f73f;
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
      if ((local_8 & 0x400000) != 0) {
        return 0xf;
      }
      local_8 = *param_3;
    }
    break;
  case 0x13:
    if ((local_8 & 0x100000) == 0) {
      if ((local_8 & 0x50000) == 0) {
        return 0x11;
      }
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
        if ((local_8 & 0x10000) == 0) {
          LOCK();
          *piVar3 = 0;
          UNLOCK();
          return 0x11;
        }
        goto LAB_0014f450;
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
      if ((local_8 & 0x400000) != 0) {
        return 0xf;
      }
    }
    if (param_5 == 0) {
      return 0x11;
    }
    goto LAB_0014f7d6;
  case 0x14:
    if ((local_8 & 0x20000) == 0) {
      return 0x11;
    }
    piVar3 = (int *)param_3[1];
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    piVar3[6] = piVar3[6] + 1;
LAB_0014f450:
    piVar3[7] = piVar3[7] + 1;
    piVar3[1] = piVar3[1] + 1;
    LOCK();
    *piVar3 = 0;
    UNLOCK();
    *param_6 = piVar3;
    goto LAB_0014f7df;
  case 0x15:
    if ((local_8 & 0x20000) == 0) {
      return 0x11;
    }
    piVar3 = (int *)param_3[1];
    do {
      do {
      } while (*piVar3 != 0);
      LOCK();
      iVar1 = *piVar3;
      *piVar3 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    piVar3[8] = piVar3[8] + 1;
    piVar3[1] = piVar3[1] + 1;
    LOCK();
    *piVar3 = 0;
    UNLOCK();
    *param_6 = piVar3;
    *param_7 = 0;
    return 0;
  default:
                    /* WARNING: Subroutine does not return */
    _panic(s_ipc_right_copyin__strange_rights_001de9de);
  }
  if (param_5 == 0) {
    return 0x11;
  }
  if ((short)local_8 == 1) {
    *param_3 = local_8 & 0xffefffff;
  }
  else {
    *param_3 = local_8 - 1;
  }
LAB_0014f7d6:
  *param_6 = 0xffffffff;
LAB_0014f7df:
  *param_7 = 0;
  return 0;
}

