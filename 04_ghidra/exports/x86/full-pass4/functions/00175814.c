/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00175814 */

undefined4 _vm_map_inherit(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  int *local_8;
  
  if ((param_4 < 3) && (-1 < param_4)) {
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
    piVar4 = (int *)(param_1 + 0x3c);
    do {
      do {
      } while (*piVar4 != 0);
      LOCK();
      iVar3 = *piVar4;
      *piVar4 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    local_8 = *(int **)(param_1 + 0x38);
    LOCK();
    *(undefined4 *)(param_1 + 0x3c) = 0;
    UNLOCK();
    piVar4 = (int *)(param_1 + 0xc);
    if (local_8 == piVar4) {
      local_8 = *(int **)(param_1 + 0x10);
    }
    if (param_2 < (uint)local_8[2]) {
      piVar4 = (int *)local_8[1];
      local_8 = *(int **)(param_1 + 0x10);
LAB_001758ff:
      if (local_8 != piVar4) {
        if ((uint)local_8[3] <= param_2) goto LAB_001758fc;
        if ((uint)local_8[2] <= param_2) {
          piVar4 = (int *)(param_1 + 0x3c);
          do {
            do {
            } while (*piVar4 != 0);
            LOCK();
            iVar3 = *piVar4;
            *piVar4 = 1;
            UNLOCK();
          } while (iVar3 == 1);
          *(int **)(param_1 + 0x38) = local_8;
          LOCK();
          *(undefined4 *)(param_1 + 0x3c) = 0;
          UNLOCK();
          goto LAB_00175938;
        }
      }
      goto LAB_00175903;
    }
    if (local_8 == piVar4) {
LAB_00175903:
      iVar3 = *local_8;
      piVar4 = (int *)(param_1 + 0x3c);
      do {
        do {
        } while (*piVar4 != 0);
        LOCK();
        iVar1 = *piVar4;
        *piVar4 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      *(int *)(param_1 + 0x38) = iVar3;
      LOCK();
      *(undefined4 *)(param_1 + 0x3c) = 0;
      UNLOCK();
      local_8 = *(int **)(iVar3 + 4);
    }
    else {
      if ((uint)local_8[3] <= param_2) goto LAB_001758ff;
LAB_00175938:
      if ((uint)local_8[2] < param_2) {
        uVar2 = _vm_map_kentry_zone;
        if (*(int *)(param_1 + 0x20) != 0) {
          uVar2 = _vm_map_entry_zone;
        }
        piVar4 = (int *)_zalloc(uVar2);
        if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_entry_create_001e0ab0);
        }
        piVar5 = local_8;
        piVar6 = piVar4;
        for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar6 = *piVar5;
          piVar5 = piVar5 + 1;
          piVar6 = piVar6 + 1;
        }
        piVar4[3] = param_2;
        local_8[5] = local_8[5] + (param_2 - local_8[2]);
        local_8[2] = param_2;
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
        *piVar4 = *local_8;
        piVar4[1] = *(int *)(*local_8 + 4);
        iVar3 = *piVar4;
        *(int **)piVar4[1] = piVar4;
        *(int **)(iVar3 + 4) = piVar4;
        if ((*(byte *)(local_8 + 6) & 5) == 0) {
          _vm_object_reference(piVar4[4]);
        }
        else {
          iVar3 = piVar4[4];
          if (iVar3 != 0) {
            piVar4 = (int *)(iVar3 + 0x34);
            do {
              do {
              } while (*piVar4 != 0);
              LOCK();
              iVar1 = *piVar4;
              *piVar4 = 1;
              UNLOCK();
            } while (iVar1 == 1);
            *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x30) + 1;
            LOCK();
            *(undefined4 *)(iVar3 + 0x34) = 0;
            UNLOCK();
          }
        }
      }
    }
    for (; (local_8 != (int *)(param_1 + 0xc) && ((uint)local_8[2] < param_3));
        local_8 = (int *)local_8[1]) {
      if (param_3 < (uint)local_8[3]) {
        uVar2 = _vm_map_kentry_zone;
        if (*(int *)(param_1 + 0x20) != 0) {
          uVar2 = _vm_map_entry_zone;
        }
        piVar4 = (int *)_zalloc(uVar2);
        if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_entry_create_001e0ab0);
        }
        piVar5 = local_8;
        piVar6 = piVar4;
        for (iVar3 = 0xb; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar6 = *piVar5;
          piVar5 = piVar5 + 1;
          piVar6 = piVar6 + 1;
        }
        local_8[3] = param_3;
        piVar4[2] = param_3;
        piVar4[5] = piVar4[5] + (param_3 - local_8[2]);
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
        *piVar4 = (int)local_8;
        piVar4[1] = local_8[1];
        iVar3 = *piVar4;
        *(int **)piVar4[1] = piVar4;
        *(int **)(iVar3 + 4) = piVar4;
        if ((*(byte *)(local_8 + 6) & 5) == 0) {
          _vm_object_reference(piVar4[4]);
        }
        else {
          iVar3 = piVar4[4];
          if (iVar3 != 0) {
            piVar4 = (int *)(iVar3 + 0x34);
            do {
              do {
              } while (*piVar4 != 0);
              LOCK();
              iVar1 = *piVar4;
              *piVar4 = 1;
              UNLOCK();
            } while (iVar1 == 1);
            *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x30) + 1;
            LOCK();
            *(undefined4 *)(iVar3 + 0x34) = 0;
            UNLOCK();
          }
        }
      }
      local_8[9] = param_4;
    }
    _lock_done(param_1);
    uVar2 = 0;
  }
  else {
    uVar2 = 4;
  }
  return uVar2;
LAB_001758fc:
  local_8 = (int *)local_8[1];
  goto LAB_001758ff;
}

