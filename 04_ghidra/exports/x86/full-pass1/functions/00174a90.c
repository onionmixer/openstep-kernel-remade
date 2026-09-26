/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00174a90 */

undefined4 _vm_map_find(int param_1,int param_2,int param_3,uint *param_4,int param_5,int param_6)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  uint local_18;
  int local_c;
  undefined4 *local_8;
  
  local_18 = *param_4;
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  if (param_6 == 0) {
LAB_00174c4b:
    uVar4 = param_5 + local_18;
    if (((local_18 < *(uint *)(param_1 + 0x14)) || (*(uint *)(param_1 + 0x18) < uVar4)) ||
       (uVar4 <= local_18)) {
      uVar2 = 1;
    }
    else {
      iVar3 = _vm_map_lookup_entry(param_1,local_18,&local_c);
      if ((iVar3 == 0) &&
         ((*(int *)(local_c + 4) == param_1 + 0xc || (uVar4 <= *(uint *)(*(int *)(local_c + 4) + 8))
          ))) {
        if ((((param_2 == 0) && (local_c != param_1 + 0xc)) &&
            ((*(uint *)(local_c + 0xc) == local_18 &&
             (((((*(byte *)(local_c + 0x18) & 5) == 0 && (*(int *)(local_c + 0x24) == 1)) &&
               (*(int *)(local_c + 0x1c) == 3)) &&
              ((*(int *)(local_c + 0x20) == 7 && (*(short *)(local_c + 0x28) == 0)))))))) &&
           (iVar3 = _vm_object_coalesce(*(undefined4 *)(local_c + 0x10),0,
                                        *(undefined4 *)(local_c + 0x14),0,
                                        local_18 - *(int *)(local_c + 8),uVar4 - local_18),
           iVar3 != 0)) {
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (uVar4 - *(int *)(local_c + 0xc));
          *(uint *)(local_c + 0xc) = uVar4;
        }
        else {
          uVar2 = _vm_map_kentry_zone;
          if (*(int *)(param_1 + 0x20) != 0) {
            uVar2 = _vm_map_entry_zone;
          }
          piVar5 = (int *)_zalloc(uVar2);
          if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_vm_map_entry_create_001e0ab0);
          }
          piVar5[2] = local_18;
          piVar5[3] = uVar4;
          *(byte *)(piVar5 + 6) = *(byte *)(piVar5 + 6) & 0xfa;
          piVar5[4] = param_2;
          piVar5[5] = param_3;
          *(byte *)(piVar5 + 6) = *(byte *)(piVar5 + 6) & 0xb7;
          if (*(int *)(param_1 + 0x2c) != 0) {
            piVar5[9] = 1;
            piVar5[7] = 3;
            piVar5[8] = 7;
            *(undefined2 *)(piVar5 + 10) = 0;
          }
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
          *piVar5 = local_c;
          piVar5[1] = *(int *)(local_c + 4);
          iVar3 = *piVar5;
          *(int **)piVar5[1] = piVar5;
          *(int **)(iVar3 + 4) = piVar5;
          *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (piVar5[3] - piVar5[2]);
          if ((*(int *)(param_1 + 0x40) == local_c) && ((uint)piVar5[2] <= *(uint *)(local_c + 0xc))
             ) {
            *(int **)(param_1 + 0x40) = piVar5;
          }
        }
        uVar2 = 0;
      }
      else {
        uVar2 = 3;
      }
    }
    _lock_done(param_1);
    return uVar2;
  }
  uVar4 = *(uint *)(param_1 + 0x14);
  if (local_18 < uVar4) {
    local_18 = uVar4;
  }
  if (*(uint *)(param_1 + 0x18) < local_18) {
    _lock_done(param_1);
    return 3;
  }
  if (local_18 == uVar4) {
    puVar6 = *(undefined4 **)(param_1 + 0x40);
    puVar1 = puVar6;
    if (puVar6 == (undefined4 *)(param_1 + 0xc)) goto LAB_00174bd8;
    do {
      local_18 = puVar6[3];
      puVar1 = puVar6;
LAB_00174bd8:
      uVar4 = local_18 + param_5;
      if ((*(uint *)(param_1 + 0x18) < uVar4) || (uVar4 < local_18)) {
        _lock_done(param_1);
        return 3;
      }
      puVar6 = (undefined4 *)puVar1[1];
    } while ((puVar6 != (undefined4 *)(param_1 + 0xc)) && ((uint)puVar6[2] < uVar4));
    *param_4 = local_18;
    piVar5 = (int *)(param_1 + 0x3c);
    do {
      do {
      } while (*piVar5 != 0);
      LOCK();
      iVar3 = *piVar5;
      *piVar5 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    *(undefined4 **)(param_1 + 0x38) = puVar1;
    LOCK();
    *(undefined4 *)(param_1 + 0x3c) = 0;
    UNLOCK();
    goto LAB_00174c4b;
  }
  piVar5 = (int *)(param_1 + 0x3c);
  do {
    do {
    } while (*piVar5 != 0);
    LOCK();
    iVar3 = *piVar5;
    *piVar5 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  local_8 = *(undefined4 **)(param_1 + 0x38);
  LOCK();
  *(undefined4 *)(param_1 + 0x3c) = 0;
  UNLOCK();
  puVar1 = (undefined4 *)(param_1 + 0xc);
  if (local_8 == puVar1) {
    local_8 = *(undefined4 **)(param_1 + 0x10);
  }
  if (local_18 < (uint)local_8[2]) {
    puVar1 = (undefined4 *)local_8[1];
    local_8 = *(undefined4 **)(param_1 + 0x10);
  }
  else {
    if (local_8 == puVar1) goto LAB_00174b9b;
    if (local_18 < (uint)local_8[3]) {
LAB_00174bcc:
      local_18 = local_8[3];
      puVar1 = local_8;
      goto LAB_00174bd8;
    }
  }
  for (; local_8 != puVar1; local_8 = (undefined4 *)local_8[1]) {
    if (local_18 < (uint)local_8[3]) {
      if ((uint)local_8[2] <= local_18) {
        piVar5 = (int *)(param_1 + 0x3c);
        do {
          do {
          } while (*piVar5 != 0);
          LOCK();
          iVar3 = *piVar5;
          *piVar5 = 1;
          UNLOCK();
        } while (iVar3 == 1);
        *(undefined4 **)(param_1 + 0x38) = local_8;
        LOCK();
        *(undefined4 *)(param_1 + 0x3c) = 0;
        UNLOCK();
        goto LAB_00174bcc;
      }
      break;
    }
  }
LAB_00174b9b:
  puVar1 = (undefined4 *)*local_8;
  piVar5 = (int *)(param_1 + 0x3c);
  do {
    do {
    } while (*piVar5 != 0);
    LOCK();
    iVar3 = *piVar5;
    *piVar5 = 1;
    UNLOCK();
  } while (iVar3 == 1);
  *(undefined4 **)(param_1 + 0x38) = puVar1;
  LOCK();
  *(undefined4 *)(param_1 + 0x3c) = 0;
  UNLOCK();
  local_8 = puVar1;
  goto LAB_00174bd8;
}

