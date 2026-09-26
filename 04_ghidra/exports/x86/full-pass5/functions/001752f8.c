/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001752f8 */

undefined4 _vm_map_protect(int param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int *piVar12;
  int *piVar13;
  undefined4 *local_c;
  int *local_8;
  
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  if (param_2 < *(uint *)(param_1 + 0x14)) {
    param_2 = *(uint *)(param_1 + 0x14);
  }
  if (*(uint *)(param_1 + 0x18) < param_3) {
    param_3 = *(uint *)(param_1 + 0x18);
  }
  if (param_3 < param_2) {
    param_2 = param_3;
  }
  piVar10 = (int *)(param_1 + 0x3c);
  do {
    do {
    } while (*piVar10 != 0);
    LOCK();
    iVar9 = *piVar10;
    *piVar10 = 1;
    UNLOCK();
  } while (iVar9 == 1);
  local_8 = *(int **)(param_1 + 0x38);
  LOCK();
  *(undefined4 *)(param_1 + 0x3c) = 0;
  UNLOCK();
  piVar10 = (int *)(param_1 + 0xc);
  if (local_8 == piVar10) {
    local_8 = *(int **)(param_1 + 0x10);
  }
  if (param_2 < (uint)local_8[2]) {
    piVar10 = (int *)local_8[1];
    local_8 = *(int **)(param_1 + 0x10);
LAB_001753cb:
    if (local_8 != piVar10) {
      if ((uint)local_8[3] <= param_2) goto LAB_001753c8;
      if ((uint)local_8[2] <= param_2) {
        piVar10 = (int *)(param_1 + 0x3c);
        do {
          do {
          } while (*piVar10 != 0);
          LOCK();
          iVar9 = *piVar10;
          *piVar10 = 1;
          UNLOCK();
        } while (iVar9 == 1);
        *(int **)(param_1 + 0x38) = local_8;
        LOCK();
        *(undefined4 *)(param_1 + 0x3c) = 0;
        UNLOCK();
        goto LAB_00175404;
      }
    }
    goto LAB_001753cf;
  }
  if (local_8 == piVar10) {
LAB_001753cf:
    iVar9 = *local_8;
    piVar10 = (int *)(param_1 + 0x3c);
    do {
      do {
      } while (*piVar10 != 0);
      LOCK();
      iVar1 = *piVar10;
      *piVar10 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    *(int *)(param_1 + 0x38) = iVar9;
    LOCK();
    *(undefined4 *)(param_1 + 0x3c) = 0;
    UNLOCK();
    local_8 = *(int **)(iVar9 + 4);
  }
  else {
    if ((uint)local_8[3] <= param_2) goto LAB_001753cb;
LAB_00175404:
    if ((uint)local_8[2] < param_2) {
      uVar3 = _vm_map_kentry_zone;
      if (*(int *)(param_1 + 0x20) != 0) {
        uVar3 = _vm_map_entry_zone;
      }
      piVar10 = (int *)_zalloc(uVar3);
      if (piVar10 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_map_entry_create_001e0ab0);
      }
      piVar11 = local_8;
      piVar12 = piVar10;
      for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {
        *piVar12 = *piVar11;
        piVar11 = piVar11 + 1;
        piVar12 = piVar12 + 1;
      }
      piVar10[3] = param_2;
      local_8[5] = local_8[5] + (param_2 - local_8[2]);
      local_8[2] = param_2;
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      *piVar10 = *local_8;
      piVar10[1] = *(int *)(*local_8 + 4);
      iVar9 = *piVar10;
      *(int **)piVar10[1] = piVar10;
      *(int **)(iVar9 + 4) = piVar10;
      if ((*(byte *)(local_8 + 6) & 5) == 0) {
        _vm_object_reference(piVar10[4]);
      }
      else {
        iVar9 = piVar10[4];
        if (iVar9 != 0) {
          piVar10 = (int *)(iVar9 + 0x34);
          do {
            do {
            } while (*piVar10 != 0);
            LOCK();
            iVar1 = *piVar10;
            *piVar10 = 1;
            UNLOCK();
          } while (iVar1 == 1);
          *(int *)(iVar9 + 0x30) = *(int *)(iVar9 + 0x30) + 1;
          LOCK();
          *(undefined4 *)(iVar9 + 0x34) = 0;
          UNLOCK();
        }
      }
    }
  }
  for (piVar10 = local_8;
      (piVar11 = local_8, piVar10 != (int *)(param_1 + 0xc) && ((uint)piVar10[2] < param_3));
      piVar10 = (int *)piVar10[1]) {
    if ((*(byte *)(piVar10 + 6) & 4) != 0) {
      _lock_done(param_1);
      return 4;
    }
    if (param_4 != (param_4 & piVar10[8])) {
      _lock_done(param_1);
      return 2;
    }
  }
  do {
    if ((piVar11 == (int *)(param_1 + 0xc)) || (param_3 <= (uint)piVar11[2])) {
      _lock_done(param_1);
      return 0;
    }
    if (param_3 < (uint)piVar11[3]) {
      uVar3 = _vm_map_kentry_zone;
      if (*(int *)(param_1 + 0x20) != 0) {
        uVar3 = _vm_map_entry_zone;
      }
      piVar10 = (int *)_zalloc(uVar3);
      if (piVar10 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_map_entry_create_001e0ab0);
      }
      piVar12 = piVar11;
      piVar13 = piVar10;
      for (iVar9 = 0xb; iVar9 != 0; iVar9 = iVar9 + -1) {
        *piVar13 = *piVar12;
        piVar12 = piVar12 + 1;
        piVar13 = piVar13 + 1;
      }
      piVar11[3] = param_3;
      piVar10[2] = param_3;
      piVar10[5] = piVar10[5] + (param_3 - piVar11[2]);
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      *piVar10 = (int)piVar11;
      piVar10[1] = piVar11[1];
      iVar9 = *piVar10;
      *(int **)piVar10[1] = piVar10;
      *(int **)(iVar9 + 4) = piVar10;
      if ((*(byte *)(piVar11 + 6) & 5) == 0) {
        _vm_object_reference(piVar10[4]);
      }
      else {
        iVar9 = piVar10[4];
        if (iVar9 != 0) {
          piVar10 = (int *)(iVar9 + 0x34);
          do {
            do {
            } while (*piVar10 != 0);
            LOCK();
            iVar1 = *piVar10;
            *piVar10 = 1;
            UNLOCK();
          } while (iVar1 == 1);
          *(int *)(iVar9 + 0x30) = *(int *)(iVar9 + 0x30) + 1;
          LOCK();
          *(undefined4 *)(iVar9 + 0x34) = 0;
          UNLOCK();
        }
      }
    }
    uVar5 = piVar11[7];
    if (param_5 == 0) {
      piVar11[7] = param_4;
    }
    else {
      piVar11[8] = param_4;
      piVar11[7] = param_4 & uVar5;
    }
    uVar6 = piVar11[7];
    if (uVar6 != uVar5) {
      if ((*(byte *)(piVar11 + 6) & 1) == 0) {
        if ((*(byte *)(local_8 + 6) & 8) == 0) {
          uVar6 = uVar6 & 7;
        }
        else {
          uVar6 = uVar6 & 0xfffffffd;
        }
        _pmap_protect(*(undefined4 *)(param_1 + 0x24),piVar11[2],piVar11[3],uVar6);
      }
      else {
        _lock_write(piVar11[4]);
        *(int *)(piVar11[4] + 0x4c) = *(int *)(piVar11[4] + 0x4c) + 1;
        iVar9 = piVar11[4];
        uVar5 = piVar11[5];
        piVar10 = (int *)(iVar9 + 0x3c);
        do {
          do {
          } while (*piVar10 != 0);
          LOCK();
          iVar1 = *piVar10;
          *piVar10 = 1;
          UNLOCK();
        } while (iVar1 == 1);
        local_c = *(undefined4 **)(iVar9 + 0x38);
        LOCK();
        *(undefined4 *)(iVar9 + 0x3c) = 0;
        UNLOCK();
        puVar4 = (undefined4 *)(iVar9 + 0xc);
        if (local_c == puVar4) {
          local_c = *(undefined4 **)(iVar9 + 0x10);
        }
        if (uVar5 < (uint)local_c[2]) {
          puVar4 = (undefined4 *)local_c[1];
          local_c = *(undefined4 **)(iVar9 + 0x10);
LAB_001756ff:
          if (local_c != puVar4) {
            if ((uint)local_c[3] <= uVar5) goto LAB_001756fc;
            if ((uint)local_c[2] <= uVar5) {
              piVar10 = (int *)(iVar9 + 0x3c);
              do {
                do {
                } while (*piVar10 != 0);
                LOCK();
                iVar1 = *piVar10;
                *piVar10 = 1;
                UNLOCK();
              } while (iVar1 == 1);
              *(undefined4 **)(iVar9 + 0x38) = local_c;
              LOCK();
              *(undefined4 *)(iVar9 + 0x3c) = 0;
              UNLOCK();
              goto LAB_00175732;
            }
          }
          goto LAB_00175703;
        }
        if (local_c == puVar4) {
LAB_00175703:
          local_c = (undefined4 *)*local_c;
          piVar10 = (int *)(iVar9 + 0x3c);
          do {
            do {
            } while (*piVar10 != 0);
            LOCK();
            iVar1 = *piVar10;
            *piVar10 = 1;
            UNLOCK();
          } while (iVar1 == 1);
          *(undefined4 **)(iVar9 + 0x38) = local_c;
          LOCK();
          *(undefined4 *)(iVar9 + 0x3c) = 0;
          UNLOCK();
        }
        else if ((uint)local_c[3] <= uVar5) goto LAB_001756ff;
LAB_00175732:
        uVar5 = (piVar11[3] - piVar11[2]) + piVar11[5];
        for (; (local_c != (undefined4 *)(piVar11[4] + 0xc) && ((uint)local_c[2] < uVar5));
            local_c = (undefined4 *)local_c[1]) {
          if ((*(byte *)(local_c + 6) & 8) == 0) {
            uVar6 = piVar11[7] & 7;
          }
          else {
            uVar6 = piVar11[7] & 0xfffffffd;
          }
          uVar7 = local_c[3];
          if ((uint)local_c[3] < uVar5) {
            uVar7 = uVar5;
          }
          uVar2 = piVar11[5];
          uVar8 = local_c[2];
          if ((uint)local_c[2] < uVar2) {
            uVar8 = uVar2;
          }
          _pmap_protect(*(undefined4 *)(param_1 + 0x24),(uVar8 - uVar2) + piVar11[2],
                        (uVar7 - uVar2) + piVar11[2],uVar6);
        }
        _lock_done(piVar11[4]);
      }
    }
    piVar11 = (int *)piVar11[1];
  } while( true );
LAB_001753c8:
  local_8 = (int *)local_8[1];
  goto LAB_001753cb;
LAB_001756fc:
  local_c = (undefined4 *)local_c[1];
  goto LAB_001756ff;
}

