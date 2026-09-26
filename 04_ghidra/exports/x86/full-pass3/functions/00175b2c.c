/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00175b2c */

undefined4 _vm_map_pageable(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  bool bVar8;
  int *local_8;
  
  bVar8 = true;
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
  piVar5 = (int *)(param_1 + 0x3c);
  do {
    do {
    } while (*piVar5 != 0);
    LOCK();
    iVar4 = *piVar5;
    *piVar5 = 1;
    UNLOCK();
  } while (iVar4 == 1);
  local_8 = *(int **)(param_1 + 0x38);
  LOCK();
  *(undefined4 *)(param_1 + 0x3c) = 0;
  UNLOCK();
  piVar5 = (int *)(param_1 + 0xc);
  if (local_8 == piVar5) {
    local_8 = *(int **)(param_1 + 0x10);
  }
  if ((uint)local_8[2] <= param_2) {
    if (local_8 == piVar5) {
LAB_00175c0b:
      iVar4 = *local_8;
      piVar5 = (int *)(param_1 + 0x3c);
      do {
        do {
        } while (*piVar5 != 0);
        LOCK();
        iVar1 = *piVar5;
        *piVar5 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      *(int *)(param_1 + 0x38) = iVar4;
      LOCK();
      *(undefined4 *)(param_1 + 0x3c) = 0;
      UNLOCK();
      local_8 = *(int **)(iVar4 + 4);
    }
    else {
      if ((uint)local_8[3] <= param_2) goto LAB_00175c07;
LAB_00175c40:
      if ((uint)local_8[2] < param_2) {
        uVar2 = _vm_map_kentry_zone;
        if (*(int *)(param_1 + 0x20) != 0) {
          uVar2 = _vm_map_entry_zone;
        }
        piVar5 = (int *)_zalloc(uVar2);
        if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
          _panic(s_vm_map_entry_create_001e0ab0);
        }
        piVar3 = local_8;
        piVar6 = piVar5;
        for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
          *piVar6 = *piVar3;
          piVar3 = piVar3 + 1;
          piVar6 = piVar6 + 1;
        }
        piVar5[3] = param_2;
        local_8[5] = local_8[5] + (param_2 - local_8[2]);
        local_8[2] = param_2;
        *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
        *piVar5 = *local_8;
        piVar5[1] = *(int *)(*local_8 + 4);
        iVar4 = *piVar5;
        *(int **)piVar5[1] = piVar5;
        *(int **)(iVar4 + 4) = piVar5;
        if ((*(byte *)(local_8 + 6) & 5) == 0) {
          _vm_object_reference(piVar5[4]);
        }
        else {
          iVar4 = piVar5[4];
          if (iVar4 != 0) {
            piVar5 = (int *)(iVar4 + 0x34);
            do {
              do {
              } while (*piVar5 != 0);
              LOCK();
              iVar1 = *piVar5;
              *piVar5 = 1;
              UNLOCK();
            } while (iVar1 == 1);
            *(int *)(iVar4 + 0x30) = *(int *)(iVar4 + 0x30) + 1;
            LOCK();
            *(undefined4 *)(iVar4 + 0x34) = 0;
            UNLOCK();
          }
        }
      }
    }
    piVar5 = local_8;
    if (param_4 == 0) {
      for (; (piVar5 != (int *)(param_1 + 0xc) && ((uint)piVar5[2] < param_3));
          piVar5 = (int *)piVar5[1]) {
        if (param_3 < (uint)piVar5[3]) {
          uVar2 = _vm_map_kentry_zone;
          if (*(int *)(param_1 + 0x20) != 0) {
            uVar2 = _vm_map_entry_zone;
          }
          piVar3 = (int *)_zalloc(uVar2);
          if (piVar3 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_vm_map_entry_create_001e0ab0);
          }
          piVar6 = piVar5;
          piVar7 = piVar3;
          for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
            *piVar7 = *piVar6;
            piVar6 = piVar6 + 1;
            piVar7 = piVar7 + 1;
          }
          piVar5[3] = param_3;
          piVar3[2] = param_3;
          piVar3[5] = piVar3[5] + (param_3 - piVar5[2]);
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
          *piVar3 = (int)piVar5;
          piVar3[1] = piVar5[1];
          iVar4 = *piVar3;
          *(int **)piVar3[1] = piVar3;
          *(int **)(iVar4 + 4) = piVar3;
          if ((*(byte *)(piVar5 + 6) & 5) == 0) {
            _vm_object_reference(piVar3[4]);
          }
          else {
            iVar4 = piVar3[4];
            if (iVar4 != 0) {
              piVar3 = (int *)(iVar4 + 0x34);
              do {
                do {
                } while (*piVar3 != 0);
                LOCK();
                iVar1 = *piVar3;
                *piVar3 = 1;
                UNLOCK();
              } while (iVar1 == 1);
              *(int *)(iVar4 + 0x30) = *(int *)(iVar4 + 0x30) + 1;
              LOCK();
              *(undefined4 *)(iVar4 + 0x34) = 0;
              UNLOCK();
            }
          }
        }
        iVar4 = piVar5[10];
        *(short *)(piVar5 + 10) = (short)iVar4 + 1;
        if (((short)iVar4 == 0) && ((*(byte *)(piVar5 + 6) & 1) == 0)) {
          if (((*(byte *)(piVar5 + 6) & 0x40) == 0) || ((*(byte *)(piVar5 + 7) & 2) == 0)) {
            if (piVar5[4] == 0) {
              iVar4 = _vm_object_allocate(piVar5[3] - piVar5[2]);
              piVar5[4] = iVar4;
              piVar5[5] = 0;
            }
          }
          else {
            _vm_object_shadow(piVar5 + 4,piVar5 + 5,piVar5[3] - piVar5[2]);
            *(byte *)(piVar5 + 6) = *(byte *)(piVar5 + 6) & 0xbf;
          }
        }
      }
      bVar8 = _kernel_map != param_1;
      if (bVar8) {
        _lock_set_recursive(param_1);
        _lock_write_to_read(param_1);
      }
      else {
        _lock_done(param_1);
      }
      for (; (local_8 != (int *)(param_1 + 0xc) && ((uint)local_8[2] < param_3));
          local_8 = (int *)local_8[1]) {
        if ((short)local_8[10] == 1) {
          _vm_fault_wire(param_1,local_8);
        }
      }
      if (!bVar8) {
        return 0;
      }
      _lock_clear_recursive(param_1);
    }
    else {
      for (; (piVar5 != (int *)(param_1 + 0xc) && ((uint)piVar5[2] < param_3));
          piVar5 = (int *)piVar5[1]) {
        if ((short)piVar5[10] == 0) {
          _lock_done(param_1);
          return 4;
        }
      }
      for (; (local_8 != (int *)(param_1 + 0xc) && ((uint)local_8[2] < param_3));
          local_8 = (int *)local_8[1]) {
        if (param_3 < (uint)local_8[3]) {
          uVar2 = _vm_map_kentry_zone;
          if (*(int *)(param_1 + 0x20) != 0) {
            uVar2 = _vm_map_entry_zone;
          }
          piVar5 = (int *)_zalloc(uVar2);
          if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_vm_map_entry_create_001e0ab0);
          }
          piVar3 = local_8;
          piVar6 = piVar5;
          for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
            *piVar6 = *piVar3;
            piVar3 = piVar3 + 1;
            piVar6 = piVar6 + 1;
          }
          local_8[3] = param_3;
          piVar5[2] = param_3;
          piVar5[5] = piVar5[5] + (param_3 - local_8[2]);
          *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
          *piVar5 = (int)local_8;
          piVar5[1] = local_8[1];
          iVar4 = *piVar5;
          *(int **)piVar5[1] = piVar5;
          *(int **)(iVar4 + 4) = piVar5;
          if ((*(byte *)(local_8 + 6) & 5) == 0) {
            _vm_object_reference(piVar5[4]);
          }
          else {
            iVar4 = piVar5[4];
            if (iVar4 != 0) {
              piVar5 = (int *)(iVar4 + 0x34);
              do {
                do {
                } while (*piVar5 != 0);
                LOCK();
                iVar1 = *piVar5;
                *piVar5 = 1;
                UNLOCK();
              } while (iVar1 == 1);
              *(int *)(iVar4 + 0x30) = *(int *)(iVar4 + 0x30) + 1;
              LOCK();
              *(undefined4 *)(iVar4 + 0x34) = 0;
              UNLOCK();
            }
          }
        }
        iVar4 = local_8[10];
        *(short *)(local_8 + 10) = (short)iVar4 + -1;
        if ((short)iVar4 == 1) {
          _vm_fault_unwire(param_1,local_8);
        }
      }
    }
    if (bVar8) {
      _lock_done(param_1);
    }
    return 0;
  }
  piVar5 = (int *)local_8[1];
  local_8 = *(int **)(param_1 + 0x10);
LAB_00175c07:
  if (local_8 != piVar5) {
    if ((uint)local_8[3] <= param_2) goto LAB_00175c04;
    if ((uint)local_8[2] <= param_2) {
      piVar5 = (int *)(param_1 + 0x3c);
      do {
        do {
        } while (*piVar5 != 0);
        LOCK();
        iVar4 = *piVar5;
        *piVar5 = 1;
        UNLOCK();
      } while (iVar4 == 1);
      *(int **)(param_1 + 0x38) = local_8;
      LOCK();
      *(undefined4 *)(param_1 + 0x3c) = 0;
      UNLOCK();
      goto LAB_00175c40;
    }
  }
  goto LAB_00175c0b;
LAB_00175c04:
  local_8 = (int *)local_8[1];
  goto LAB_00175c07;
}

