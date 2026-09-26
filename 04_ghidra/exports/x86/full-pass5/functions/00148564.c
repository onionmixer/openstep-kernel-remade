/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00148564 */

undefined4 _ipc_kmsg_copyout_header(uint *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined2 uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int *piVar10;
  int local_2c;
  uint local_14;
  undefined4 local_10;
  int local_c;
  int *local_8;
  
  uVar9 = *param_1;
  piVar2 = (int *)param_1[2];
  if (param_3 == 0) {
    uVar5 = uVar9 & 0xffff;
    uVar4 = (undefined2)(uVar9 >> 0x10);
    if (uVar5 == 0x12) {
      do {
        do {
        } while (*piVar2 != 0);
        LOCK();
        iVar7 = *piVar2;
        *piVar2 = 1;
        UNLOCK();
      } while (iVar7 == 1);
      if (piVar2[2] < 0) {
        if (piVar2[3] == param_2) {
          piVar2[1] = piVar2[1] + -1;
          piVar2[8] = piVar2[8] + -1;
          uVar9 = piVar2[4];
          LOCK();
          *piVar2 = 0;
          UNLOCK();
        }
        else {
          LOCK();
          *piVar2 = 0;
          UNLOCK();
          _ipc_notify_send_once(piVar2);
          uVar9 = 0;
        }
        *param_1 = CONCAT22(uVar4,0x1200);
        param_1[3] = uVar9;
        param_1[2] = 0;
        return 0;
      }
LAB_00148792:
      LOCK();
      *piVar2 = 0;
      UNLOCK();
    }
    else if (uVar5 < 0x13) {
      if (uVar5 == 0x11) {
        do {
          do {
          } while (*piVar2 != 0);
          LOCK();
          iVar7 = *piVar2;
          *piVar2 = 1;
          UNLOCK();
        } while (iVar7 == 1);
        if (piVar2[2] < 0) {
          piVar2[1] = piVar2[1] + -1;
          uVar9 = 0;
          if (piVar2[3] == param_2) {
            uVar9 = piVar2[4];
          }
          iVar7 = piVar2[7];
          piVar2[7] = iVar7 + -1;
          if ((iVar7 == 1) && (iVar7 = piVar2[9], iVar7 != 0)) {
            piVar2[9] = 0;
            LOCK();
            *piVar2 = 0;
            UNLOCK();
            _ipc_notify_no_senders(iVar7,piVar2[6]);
          }
          else {
            LOCK();
            *piVar2 = 0;
            UNLOCK();
          }
          *param_1 = CONCAT22(uVar4,0x1100);
          param_1[3] = uVar9;
          param_1[2] = 0;
          return 0;
        }
        goto LAB_00148792;
      }
    }
    else if (((uVar5 == 0x1211) && (piVar10 = (int *)param_1[3], piVar10 != (int *)0x0)) &&
            (piVar10 != (int *)0xffffffff)) {
      piVar8 = (int *)(param_2 + 8);
      do {
        do {
        } while (*piVar8 != 0);
        LOCK();
        iVar7 = *piVar8;
        *piVar8 = 1;
        UNLOCK();
      } while (iVar7 == 1);
      if (*(int *)(param_2 + 0xc) != 0) {
        iVar7 = *(int *)(param_2 + 0x14);
        iVar3 = *(int *)(iVar7 + 8);
        if (iVar3 != 0) {
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
            iVar1 = *piVar10;
            *piVar10 = 1;
            UNLOCK();
            if (iVar1 != 1) {
              if (piVar10[2] < 0) {
                LOCK();
                *piVar10 = 0;
                UNLOCK();
                puVar6 = (uint *)(iVar3 * 0x10 + iVar7);
                *(uint *)(iVar7 + 8) = puVar6[2];
                puVar6[2] = 0;
                piVar8 = (int *)(*puVar6 + 0x1000000 >> 0x18 | iVar3 << 8);
                *puVar6 = *puVar6 + 0x1000000 | 0x40001;
                puVar6[1] = (uint)piVar10;
                LOCK();
                *(undefined4 *)(param_2 + 8) = 0;
                UNLOCK();
                piVar2[1] = piVar2[1] + -1;
                uVar5 = 0;
                if (piVar2[3] == param_2) {
                  uVar5 = piVar2[4];
                }
                iVar7 = piVar2[7];
                piVar2[7] = iVar7 + -1;
                if ((iVar7 == 1) && (iVar7 = piVar2[9], iVar7 != 0)) {
                  piVar2[9] = 0;
                  LOCK();
                  *piVar2 = 0;
                  UNLOCK();
                  _ipc_notify_no_senders(iVar7,piVar2[6]);
                }
                else {
                  LOCK();
                  *piVar2 = 0;
                  UNLOCK();
                }
                *param_1 = uVar9 & 0xffff0000 | 0x1112;
                param_1[3] = uVar5;
                goto LAB_00148c0f;
              }
              LOCK();
              *piVar10 = 0;
              UNLOCK();
            }
          }
          LOCK();
          *piVar2 = 0;
          UNLOCK();
        }
      }
      LOCK();
      *(undefined4 *)(param_2 + 8) = 0;
      UNLOCK();
    }
  }
  uVar5 = (uVar9 & 0xff00) >> 8;
  piVar10 = (int *)param_1[3];
  if ((piVar10 != (int *)0x0) && (piVar10 != (int *)0xffffffff)) {
    piVar8 = (int *)(param_2 + 8);
    do {
      do {
      } while (*piVar8 != 0);
      LOCK();
      iVar7 = *piVar8;
      *piVar8 = 1;
      UNLOCK();
    } while (iVar7 == 1);
LAB_00148830:
    if (*(int *)(param_2 + 0xc) == 0) {
      LOCK();
      *(undefined4 *)(param_2 + 8) = 0;
      UNLOCK();
      return 0x1000600b;
    }
    if (param_3 == 0) {
      local_2c = 0;
    }
    else {
      local_2c = _ipc_port_lookup_notify(param_2,param_3);
      if (local_2c == 0) {
        LOCK();
        *(undefined4 *)(param_2 + 8) = 0;
        UNLOCK();
        return 0x10004007;
      }
    }
    if ((uVar5 == 0x12) ||
       (iVar7 = _ipc_right_reverse(param_2,piVar10,&local_8,&local_c), iVar7 == 0)) {
      do {
        do {
        } while (*piVar10 != 0);
        LOCK();
        iVar7 = *piVar10;
        *piVar10 = 1;
        UNLOCK();
      } while (iVar7 == 1);
      if (-1 < piVar10[2]) {
        iVar7 = piVar10[1];
        piVar10[1] = iVar7 + -1;
        LOCK();
        *piVar10 = 0;
        UNLOCK();
        if (iVar7 == 1) {
          _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar10 + 10) & 0x7fff],piVar10);
        }
        if (local_2c != 0) {
          _ipc_port_release_sonce(local_2c);
        }
        do {
          do {
          } while (*piVar2 != 0);
          LOCK();
          iVar7 = *piVar2;
          *piVar2 = 1;
          UNLOCK();
        } while (iVar7 == 1);
        LOCK();
        *(undefined4 *)(param_2 + 8) = 0;
        UNLOCK();
        piVar10 = (int *)0xffffffff;
        local_8 = (int *)0xffffffff;
        goto LAB_00148b27;
      }
      iVar7 = _ipc_entry_get(param_2,&local_8,&local_c);
      if (iVar7 != 0) goto code_r0x00148934;
      if (local_2c == 0) {
        *(int **)(local_c + 4) = piVar10;
        goto LAB_00148a4b;
      }
      iVar7 = _ipc_port_dnrequest(piVar10,local_8,local_2c,&local_10);
      if (iVar7 != 0) {
        LOCK();
        *piVar10 = 0;
        UNLOCK();
        _ipc_port_release_sonce(local_2c);
        _ipc_entry_dealloc(param_2,local_8,local_c);
        LOCK();
        *(undefined4 *)(param_2 + 8) = 0;
        UNLOCK();
        do {
          do {
          } while (*piVar10 != 0);
          LOCK();
          iVar7 = *piVar10;
          *piVar10 = 1;
          UNLOCK();
        } while (iVar7 == 1);
        if (piVar10[2] < 0) {
          iVar7 = _ipc_port_dngrow(piVar10);
          if (iVar7 != 0) {
            return 0x1000480b;
          }
          piVar8 = (int *)(param_2 + 8);
          do {
            do {
            } while (*piVar8 != 0);
            LOCK();
            iVar7 = *piVar8;
            *piVar8 = 1;
            UNLOCK();
          } while (iVar7 == 1);
        }
        else {
          LOCK();
          *piVar10 = 0;
          UNLOCK();
          piVar8 = (int *)(param_2 + 8);
          do {
            do {
            } while (*piVar8 != 0);
            LOCK();
            iVar7 = *piVar8;
            *piVar8 = 1;
            UNLOCK();
          } while (iVar7 == 1);
        }
        goto LAB_00148830;
      }
      local_2c = 0;
      *(int **)(local_c + 4) = piVar10;
      *(undefined4 *)(local_c + 8) = local_10;
    }
LAB_00148a4b:
    piVar10[1] = piVar10[1] + 1;
    _ipc_right_copyout(param_2,local_8,local_c,uVar5,1,piVar10);
    if (local_2c != 0) {
      _ipc_port_release_sonce(local_2c);
    }
    do {
      do {
      } while (*piVar2 != 0);
      LOCK();
      iVar7 = *piVar2;
      *piVar2 = 1;
      UNLOCK();
    } while (iVar7 == 1);
    LOCK();
    *(undefined4 *)(param_2 + 8) = 0;
    UNLOCK();
    goto LAB_00148b27;
  }
  piVar8 = (int *)(param_2 + 8);
  do {
    do {
    } while (*piVar8 != 0);
    LOCK();
    iVar7 = *piVar8;
    *piVar8 = 1;
    UNLOCK();
  } while (iVar7 == 1);
  if (*(int *)(param_2 + 0xc) == 0) {
    LOCK();
    *(undefined4 *)(param_2 + 8) = 0;
    UNLOCK();
    return 0x1000600b;
  }
  if ((param_3 != 0) &&
     ((iVar7 = _ipc_entry_lookup(param_2,param_3), iVar7 == 0 || ((*(byte *)(iVar7 + 2) & 2) == 0)))
     ) {
    LOCK();
    *(undefined4 *)(param_2 + 8) = 0;
    UNLOCK();
    return 0x10004007;
  }
  do {
    do {
    } while (*piVar2 != 0);
    LOCK();
    iVar7 = *piVar2;
    *piVar2 = 1;
    UNLOCK();
  } while (iVar7 == 1);
  LOCK();
  *(undefined4 *)(param_2 + 8) = 0;
  UNLOCK();
  local_8 = piVar10;
LAB_00148b27:
  if (piVar2[2] < 0) {
    _ipc_object_copyout_dest(param_2,piVar2,uVar9 & 0xff,&local_14);
  }
  else {
    iVar7 = piVar2[3];
    iVar3 = piVar2[1];
    piVar2[1] = iVar3 + -1;
    LOCK();
    *piVar2 = 0;
    UNLOCK();
    if (iVar3 == 1) {
      _zfree((&_ipc_object_zones)[*(ushort *)((int)piVar2 + 10) & 0x7fff],piVar2);
    }
    if ((piVar10 == (int *)0x0) || (piVar10 == (int *)0xffffffff)) {
      local_14 = 0xffffffff;
    }
    else {
      do {
        do {
        } while (*piVar10 != 0);
        LOCK();
        iVar3 = *piVar10;
        *piVar10 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      if ((piVar10[2] < 0) || (iVar7 - piVar10[3] < 0)) {
        local_14 = 0xffffffff;
      }
      else {
        local_14 = 0;
      }
      LOCK();
      *piVar10 = 0;
      UNLOCK();
    }
  }
  if ((piVar10 != (int *)0x0) && (piVar10 != (int *)0xffffffff)) {
    _ipc_object_release(piVar10);
  }
  *param_1 = uVar9 & 0xffff0000 | (uVar9 & 0xff) << 8 | uVar5;
  param_1[3] = local_14;
  piVar8 = local_8;
LAB_00148c0f:
  param_1[2] = (uint)piVar8;
  return 0;
code_r0x00148934:
  LOCK();
  *piVar10 = 0;
  UNLOCK();
  if (local_2c != 0) {
    _ipc_port_release_sonce(local_2c);
  }
  iVar7 = _ipc_entry_grow_table(param_2);
  if (iVar7 != 0) {
    if (iVar7 == 6) {
      return 0x1000480b;
    }
    return 0x1000600b;
  }
  goto LAB_00148830;
}

