/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00176164 */

undefined4 _vm_map_delete(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *local_8;
  
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
  if (param_2 < (uint)local_8[2]) {
    piVar5 = (int *)local_8[1];
    local_8 = *(int **)(param_1 + 0x10);
LAB_00176203:
    if (local_8 != piVar5) {
      if ((uint)local_8[3] <= param_2) goto LAB_00176200;
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
        goto LAB_00176244;
      }
    }
    goto LAB_00176207;
  }
  if (local_8 == piVar5) {
LAB_00176207:
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
    if ((uint)local_8[3] <= param_2) goto LAB_00176203;
LAB_00176244:
    if ((uint)local_8[2] < param_2) {
      uVar3 = _vm_map_kentry_zone;
      if (*(int *)(param_1 + 0x20) != 0) {
        uVar3 = _vm_map_entry_zone;
      }
      piVar5 = (int *)_zalloc(uVar3);
      if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_map_entry_create_001e0ab0);
      }
      piVar6 = local_8;
      piVar7 = piVar5;
      for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar7 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar7 = piVar7 + 1;
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
    piVar5 = (int *)(param_1 + 0x3c);
    do {
      do {
      } while (*piVar5 != 0);
      LOCK();
      iVar4 = *piVar5;
      *piVar5 = 1;
      UNLOCK();
    } while (iVar4 == 1);
    *(int *)(param_1 + 0x38) = *local_8;
    LOCK();
    *(undefined4 *)(param_1 + 0x3c) = 0;
    UNLOCK();
  }
  if (param_2 <= *(uint *)(*(int *)(param_1 + 0x40) + 8)) {
    *(int *)(param_1 + 0x40) = *local_8;
  }
  do {
    if ((local_8 == (int *)(param_1 + 0xc)) || (param_3 <= (uint)local_8[2])) {
      return 0;
    }
    if (param_3 < (uint)local_8[3]) {
      uVar3 = _vm_map_kentry_zone;
      if (*(int *)(param_1 + 0x20) != 0) {
        uVar3 = _vm_map_entry_zone;
      }
      piVar5 = (int *)_zalloc(uVar3);
      if (piVar5 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_map_entry_create_001e0ab0);
      }
      piVar6 = local_8;
      piVar7 = piVar5;
      for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
        *piVar7 = *piVar6;
        piVar6 = piVar6 + 1;
        piVar7 = piVar7 + 1;
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
    piVar5 = (int *)local_8[1];
    iVar4 = local_8[2];
    iVar1 = local_8[3];
    iVar2 = local_8[4];
    if ((short)local_8[10] != 0) {
      _vm_fault_unwire(param_1,local_8);
      *(undefined2 *)(local_8 + 10) = 0;
    }
    if (_kernel_object == iVar2) {
      _vm_object_page_remove(iVar2,local_8[5],(iVar1 - iVar4) + local_8[5]);
    }
    if (*(int *)(param_1 + 0x2c) == 0) {
      _vm_object_pmap_remove(iVar2,local_8[5],(iVar1 - iVar4) + local_8[5]);
    }
    _pmap_remove(*(undefined4 *)(param_1 + 0x24),iVar4,iVar1);
    if ((short)local_8[10] != 0) {
      _vm_fault_unwire(param_1,local_8);
      *(undefined2 *)(local_8 + 10) = 0;
    }
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
    *(int *)local_8[1] = *local_8;
    *(int *)(*local_8 + 4) = local_8[1];
    *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - (local_8[3] - local_8[2]);
    if ((*(byte *)(local_8 + 6) & 5) == 0) {
      _vm_object_deallocate(local_8[4]);
    }
    else {
      iVar4 = local_8[4];
      if (iVar4 != 0) {
        piVar6 = (int *)(iVar4 + 0x34);
        do {
          do {
          } while (*piVar6 != 0);
          LOCK();
          iVar1 = *piVar6;
          *piVar6 = 1;
          UNLOCK();
        } while (iVar1 == 1);
        iVar1 = *(int *)(iVar4 + 0x30);
        *(int *)(iVar4 + 0x30) = iVar1 + -1;
        LOCK();
        *(undefined4 *)(iVar4 + 0x34) = 0;
        UNLOCK();
        if (iVar1 == 1 || iVar1 + -1 < 0) {
          _lock_write(iVar4);
          *(int *)(iVar4 + 0x4c) = *(int *)(iVar4 + 0x4c) + 1;
          _vm_map_delete(iVar4,*(undefined4 *)(iVar4 + 0x14),*(undefined4 *)(iVar4 + 0x18));
          _pmap_destroy(*(undefined4 *)(iVar4 + 0x24));
          _zfree(_vm_map_zone,iVar4);
        }
      }
    }
    uVar3 = _vm_map_kentry_zone;
    if (*(int *)(param_1 + 0x20) != 0) {
      uVar3 = _vm_map_entry_zone;
    }
    _zfree(uVar3,local_8);
    local_8 = piVar5;
  } while( true );
LAB_00176200:
  local_8 = (int *)local_8[1];
  goto LAB_00176203;
}

