/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001477c0 */

undefined4 _ipc_kmsg_copyin_header(uint *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  uint3 uVar5;
  bool bVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int *piVar14;
  int local_3c;
  int local_18;
  int local_14;
  int *local_10;
  int local_c;
  int *local_8;
  
  uVar8 = *param_1;
  uVar5 = (uint3)(uVar8 >> 8);
  piVar2 = (int *)param_1[2];
  piVar3 = (int *)param_1[3];
  if (param_3 == 0) {
    uVar7 = uVar8 & 0xffff;
    if (uVar7 == 0x13) {
      if (piVar3 == (int *)0x0) {
        piVar14 = (int *)(param_2 + 8);
        do {
          do {
          } while (*piVar14 != 0);
          LOCK();
          iVar10 = *piVar14;
          *piVar14 = 1;
          UNLOCK();
        } while (iVar10 == 1);
        if (*(int *)(param_2 + 0xc) != 0) {
          if (((uint)piVar2 >> 8 < *(uint *)(param_2 + 0x18)) &&
             (puVar9 = (uint *)(((uint)piVar2 >> 8) * 0x10 + *(int *)(param_2 + 0x14)),
             (*puVar9 & 0xff010000) == ((int)piVar2 << 0x18 | 0x10000U))) {
            piVar14 = (int *)puVar9[1];
            do {
              do {
              } while (*piVar14 != 0);
              LOCK();
              iVar10 = *piVar14;
              *piVar14 = 1;
              UNLOCK();
            } while (iVar10 == 1);
            LOCK();
            *(undefined4 *)(param_2 + 8) = 0;
            UNLOCK();
            if (piVar14[2] < 0) {
              piVar14[7] = piVar14[7] + 1;
              piVar14[1] = piVar14[1] + 1;
              LOCK();
              *piVar14 = 0;
              UNLOCK();
              uVar8 = CONCAT31(uVar5 & 0xbfff00,0x11);
LAB_00147ab2:
              *param_1 = uVar8;
              param_1[2] = (uint)piVar14;
              return 0;
            }
            LOCK();
            *piVar14 = 0;
            UNLOCK();
            goto LAB_00147acd;
          }
        }
        goto LAB_00147ac8;
      }
    }
    else if (uVar7 < 0x14) {
      if ((uVar7 == 0x12) && (piVar3 == (int *)0x0)) {
        piVar14 = (int *)(param_2 + 8);
        do {
          do {
          } while (*piVar14 != 0);
          LOCK();
          iVar10 = *piVar14;
          *piVar14 = 1;
          UNLOCK();
        } while (iVar10 == 1);
        if (*(int *)(param_2 + 0xc) != 0) {
          iVar10 = *(int *)(param_2 + 0x14);
          uVar7 = (uint)piVar2 >> 8;
          if (((uVar7 < *(uint *)(param_2 + 0x18)) &&
              (puVar9 = (uint *)(uVar7 * 0x10 + iVar10),
              (*puVar9 & 0xff840000) == ((int)piVar2 << 0x18 | 0x40000U))) && (puVar9[2] == 0)) {
            piVar14 = (int *)puVar9[1];
            do {
              do {
              } while (*piVar14 != 0);
              LOCK();
              iVar11 = *piVar14;
              *piVar14 = 1;
              UNLOCK();
            } while (iVar11 == 1);
            if (piVar14[2] < 0) {
              LOCK();
              *piVar14 = 0;
              UNLOCK();
              puVar9[2] = *(uint *)(iVar10 + 8);
              *(uint *)(iVar10 + 8) = uVar7;
              *puVar9 = (int)piVar2 << 0x18;
              puVar9[1] = 0;
              LOCK();
              *(undefined4 *)(param_2 + 8) = 0;
              UNLOCK();
              uVar8 = CONCAT31(uVar5 & 0xbfff00,0x12);
              goto LAB_00147ab2;
            }
            LOCK();
            *piVar14 = 0;
            UNLOCK();
          }
        }
LAB_00147ac8:
        LOCK();
        *(undefined4 *)(param_2 + 8) = 0;
        UNLOCK();
      }
    }
    else if (uVar7 == 0x1513) {
      piVar14 = (int *)(param_2 + 8);
      do {
        do {
        } while (*piVar14 != 0);
        LOCK();
        iVar10 = *piVar14;
        *piVar14 = 1;
        UNLOCK();
      } while (iVar10 == 1);
      if (*(int *)(param_2 + 0xc) != 0) {
        if (((uint)piVar2 >> 8 < *(uint *)(param_2 + 0x18)) &&
           (puVar9 = (uint *)(*(int *)(param_2 + 0x14) + ((uint)piVar2 >> 8) * 0x10),
           (*puVar9 & 0xff010000) == ((int)piVar2 << 0x18 | 0x10000U))) {
          piVar14 = (int *)puVar9[1];
          if (((uint)piVar3 >> 8 < *(uint *)(param_2 + 0x18)) &&
             (puVar9 = (uint *)(*(int *)(param_2 + 0x14) + ((uint)piVar3 >> 8) * 0x10),
             (*puVar9 & 0xff020000) == ((int)piVar3 << 0x18 | 0x20000U))) {
            piVar4 = (int *)puVar9[1];
            do {
              do {
              } while (*piVar14 != 0);
              LOCK();
              iVar10 = *piVar14;
              *piVar14 = 1;
              UNLOCK();
            } while (iVar10 == 1);
            if (piVar14[2] < 0) {
              LOCK();
              iVar10 = *piVar4;
              *piVar4 = 1;
              UNLOCK();
              if (iVar10 != 1) {
                LOCK();
                *(undefined4 *)(param_2 + 8) = 0;
                UNLOCK();
                piVar14[7] = piVar14[7] + 1;
                piVar14[1] = piVar14[1] + 1;
                LOCK();
                *piVar14 = 0;
                UNLOCK();
                piVar4[8] = piVar4[8] + 1;
                piVar4[1] = piVar4[1] + 1;
                LOCK();
                *piVar4 = 0;
                UNLOCK();
                *param_1 = uVar8 & 0xbfff0000 | 0x1211;
                param_1[2] = (uint)piVar14;
                param_1[3] = (uint)piVar4;
                return 0;
              }
            }
            LOCK();
            *piVar14 = 0;
            UNLOCK();
          }
        }
      }
      goto LAB_00147ac8;
    }
  }
LAB_00147acd:
  uVar13 = uVar8 & 0xff;
  uVar7 = (uVar8 & 0xff00) >> 8;
  local_3c = 0;
  if (4 < uVar13 - 0x11) {
    return 0x10000010;
  }
  if (uVar7 == 0) {
    if (piVar3 != (int *)0x0) {
      return 0x10000010;
    }
  }
  else if (4 < uVar7 - 0x11) {
    return 0x10000010;
  }
  piVar14 = (int *)(param_2 + 8);
  do {
    do {
    } while (*piVar14 != 0);
    LOCK();
    iVar10 = *piVar14;
    *piVar14 = 1;
    UNLOCK();
  } while (iVar10 == 1);
  if (*(int *)(param_2 + 0xc) != 0) {
    if (param_3 != 0) {
      iVar10 = _ipc_entry_lookup(param_2,param_3);
      if ((iVar10 == 0) || ((*(byte *)(iVar10 + 2) & 2) == 0)) {
        LOCK();
        *(undefined4 *)(param_2 + 8) = 0;
        UNLOCK();
        return 0x1000000b;
      }
      local_3c = *(int *)(iVar10 + 4);
    }
    if (piVar2 == piVar3) {
      iVar10 = _ipc_entry_lookup(param_2,piVar3);
      if (iVar10 != 0) {
        iVar11 = _ipc_right_copyin_check(param_2,piVar3,iVar10,uVar7);
        if (iVar11 == 0) {
LAB_00147ff4:
          LOCK();
          *(undefined4 *)(param_2 + 8) = 0;
          UNLOCK();
          return 0x10000009;
        }
        if ((uVar13 != 0x12) && (uVar7 != 0x12)) {
          if ((uVar13 - 0x14 < 2) || (uVar7 - 0x14 < 2)) {
            iVar11 = _ipc_right_copyin(param_2,piVar3,iVar10,uVar13,0,&local_8,&local_c);
            if (iVar11 == 0) {
              _ipc_right_copyin(param_2,piVar3,iVar10,uVar7,1,&local_10,&local_14);
              goto LAB_00147f5b;
            }
          }
          else if ((uVar13 == 0x13) && (uVar7 == 0x13)) {
            iVar10 = _ipc_right_copyin(param_2,piVar3,iVar10,0x13,0,&local_8,&local_c);
            if (iVar10 == 0) {
              local_10 = (int *)_ipc_port_copy_send(local_8);
              local_14 = 0;
              goto LAB_00147f5b;
            }
          }
          else if ((uVar13 == 0x11) && (uVar7 == 0x11)) {
            iVar11 = _ipc_right_copyin_two(param_2,piVar3,iVar10,&local_8,&local_c);
            if (iVar11 == 0) {
              if ((*(byte *)(iVar10 + 2) & 0x1f) == 0) {
                _ipc_entry_dealloc(param_2,piVar3,iVar10);
              }
              local_10 = local_8;
              local_14 = 0;
LAB_00147f5b:
              if ((param_3 != 0) && (local_3c == local_c)) {
                _ipc_port_release_sonce(local_c);
                local_c = 0;
              }
              LOCK();
              *(undefined4 *)(param_2 + 8) = 0;
              UNLOCK();
              if (local_c != 0) {
                _ipc_notify_port_deleted(local_c,piVar2);
              }
              if (local_14 != 0) {
                _ipc_notify_port_deleted(local_14,piVar3);
              }
              uVar13 = _ipc_object_copyin_type(uVar13);
              iVar10 = _ipc_object_copyin_type(uVar7);
              *param_1 = uVar8 & 0xbfff0000 | iVar10 << 8 | uVar13;
              param_1[2] = (uint)local_8;
              param_1[3] = (uint)local_10;
              return 0;
            }
          }
          else {
            iVar11 = _ipc_right_copyin(param_2,piVar3,iVar10,0x11,0,&local_8,&local_18);
            if (iVar11 == 0) {
              if ((*(byte *)(iVar10 + 2) & 0x1f) == 0) {
                _ipc_entry_dealloc(param_2,piVar3,iVar10);
              }
              local_10 = (int *)_ipc_port_copy_send(local_8);
              if (uVar13 == 0x11) {
                local_c = local_18;
                local_14 = 0;
              }
              else {
                local_c = 0;
                local_14 = local_18;
              }
              goto LAB_00147f5b;
            }
          }
        }
      }
    }
    else if ((piVar3 == (int *)0x0) || (piVar3 == (int *)0xffffffff)) {
      iVar10 = _ipc_entry_lookup(param_2,piVar2);
      if ((iVar10 != 0) &&
         (iVar11 = _ipc_right_copyin(param_2,piVar2,iVar10,uVar13,0,&local_8,&local_c), iVar11 == 0)
         ) {
        if ((*(byte *)(iVar10 + 2) & 0x1f) == 0) {
          _ipc_entry_dealloc(param_2,piVar2,iVar10);
        }
        local_14 = 0;
        local_10 = piVar3;
        goto LAB_00147f5b;
      }
    }
    else {
      iVar10 = _ipc_entry_lookup(param_2,piVar2);
      if (iVar10 != 0) {
        iVar11 = _ipc_entry_lookup(param_2,piVar3);
        if ((iVar11 == 0) ||
           (iVar12 = _ipc_right_copyin_check(param_2,piVar3,iVar11,uVar7), iVar12 == 0))
        goto LAB_00147ff4;
        iVar12 = _ipc_right_copyin(param_2,piVar2,iVar10,uVar13,0,&local_8,&local_c);
        if (iVar12 == 0) {
          piVar14 = *(int **)(iVar11 + 4);
          if (piVar14 != (int *)0x0) {
            _ipc_object_reference(piVar14);
          }
          iVar12 = _ipc_right_copyin(param_2,piVar3,iVar11,uVar7,1,&local_10,&local_14);
          if (iVar12 == 0) {
            if ((piVar14 != (int *)0x0) && (local_10 == (int *)0xffffffff)) {
              do {
                do {
                } while (*piVar14 != 0);
                LOCK();
                iVar12 = *piVar14;
                *piVar14 = 1;
                UNLOCK();
              } while (iVar12 == 1);
              iVar12 = piVar14[3];
              LOCK();
              *piVar14 = 0;
              UNLOCK();
              do {
                do {
                } while (*local_8 != 0);
                LOCK();
                iVar1 = *local_8;
                *local_8 = 1;
                UNLOCK();
              } while (iVar1 == 1);
              bVar6 = false;
              if ((-1 < local_8[2]) && (local_8[3] - iVar12 < 0)) {
                bVar6 = true;
              }
              LOCK();
              *local_8 = 0;
              UNLOCK();
              if (bVar6) {
                _ipc_right_copyin_undo(param_2,piVar2,iVar10,uVar13,local_8,local_c);
                _ipc_right_copyin_undo(param_2,piVar3,iVar11,uVar7,local_10,local_14);
                LOCK();
                *(undefined4 *)(param_2 + 8) = 0;
                UNLOCK();
                if (local_c != 0) {
                  _ipc_notify_dead_name(local_c,piVar2);
                }
                _ipc_object_release(piVar14);
                return 0x10000003;
              }
            }
            if ((*(byte *)(iVar11 + 2) & 0x1f) == 0) {
              _ipc_entry_dealloc(param_2,piVar3,iVar11);
            }
          }
          else {
            local_10 = (int *)0xffffffff;
            local_14 = 0;
          }
          if ((*(byte *)(iVar10 + 2) & 0x1f) == 0) {
            _ipc_entry_dealloc(param_2,piVar2,iVar10);
          }
          if (piVar14 != (int *)0x0) {
            _ipc_object_release(piVar14);
          }
          goto LAB_00147f5b;
        }
      }
    }
  }
  LOCK();
  *(undefined4 *)(param_2 + 8) = 0;
  UNLOCK();
  return 0x10000003;
}

