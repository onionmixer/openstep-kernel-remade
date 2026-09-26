/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00178458 */

kern_return_t
_vm_region(vm_map_t target_task,vm_address_t *address,vm_size_t *size,vm_region_flavor_t flavor,
          vm_region_info_t info,mach_msg_type_number_t *infoCnt,mach_port_t *object_name)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  vm_address_t vVar4;
  kern_return_t kVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *in_stack_00000020;
  uint *in_stack_00000024;
  undefined4 *local_8;
  
  if (target_task == 0) {
    kVar5 = 4;
  }
  else {
    uVar3 = *address;
    _lock_read(target_task);
    piVar9 = (int *)(target_task + 0x3c);
    do {
      do {
      } while (*piVar9 != 0);
      LOCK();
      iVar1 = *piVar9;
      *piVar9 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    piVar8 = *(int **)(target_task + 0x38);
    LOCK();
    *(undefined4 *)(target_task + 0x3c) = 0;
    UNLOCK();
    piVar9 = (int *)(target_task + 0xc);
    if (piVar8 == piVar9) {
      piVar8 = *(int **)(target_task + 0x10);
    }
    if (uVar3 < (uint)piVar8[2]) {
      piVar9 = (int *)piVar8[1];
      piVar8 = *(int **)(target_task + 0x10);
LAB_00178517:
      if (piVar8 != piVar9) {
        if ((uint)piVar8[3] <= uVar3) goto LAB_00178514;
        if ((uint)piVar8[2] <= uVar3) {
          piVar9 = (int *)(target_task + 0x3c);
          do {
            do {
            } while (*piVar9 != 0);
            LOCK();
            iVar1 = *piVar9;
            *piVar9 = 1;
            UNLOCK();
          } while (iVar1 == 1);
          *(int **)(target_task + 0x38) = piVar8;
          LOCK();
          *(undefined4 *)(target_task + 0x3c) = 0;
          UNLOCK();
          goto LAB_0017856f;
        }
      }
      goto LAB_0017851b;
    }
    if (piVar8 == piVar9) {
LAB_0017851b:
      iVar1 = *piVar8;
      piVar9 = (int *)(target_task + 0x3c);
      do {
        do {
        } while (*piVar9 != 0);
        LOCK();
        iVar2 = *piVar9;
        *piVar9 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      *(int *)(target_task + 0x38) = iVar1;
      LOCK();
      *(undefined4 *)(target_task + 0x3c) = 0;
      UNLOCK();
      piVar8 = *(int **)(iVar1 + 4);
      if (piVar8 == (int *)(target_task + 0xc)) {
        _lock_done(target_task);
        return 3;
      }
    }
    else if ((uint)piVar8[3] <= uVar3) goto LAB_00178517;
LAB_0017856f:
    vVar4 = piVar8[2];
    *(int *)flavor = piVar8[7];
    *info = piVar8[8];
    *infoCnt = piVar8[9];
    *address = vVar4;
    *size = piVar8[3] - vVar4;
    uVar3 = piVar8[5];
    if ((*(byte *)(piVar8 + 6) & 1) == 0) {
      if ((*(byte *)(piVar8 + 6) & 4) == 0) {
        *object_name = 0;
        uVar7 = _vm_object_name(piVar8[4]);
        *in_stack_00000020 = uVar7;
        *in_stack_00000024 = uVar3;
      }
      else {
        *object_name = 0;
        *in_stack_00000020 = 0;
        *in_stack_00000024 = uVar3;
      }
    }
    else {
      iVar1 = piVar8[4];
      _lock_read(iVar1);
      piVar9 = (int *)(iVar1 + 0x3c);
      do {
        do {
        } while (*piVar9 != 0);
        LOCK();
        iVar2 = *piVar9;
        *piVar9 = 1;
        UNLOCK();
      } while (iVar2 == 1);
      local_8 = *(undefined4 **)(iVar1 + 0x38);
      LOCK();
      *(undefined4 *)(iVar1 + 0x3c) = 0;
      UNLOCK();
      puVar6 = (undefined4 *)(iVar1 + 0xc);
      if (local_8 == puVar6) {
        local_8 = *(undefined4 **)(iVar1 + 0x10);
      }
      if (uVar3 < (uint)local_8[2]) {
        puVar6 = (undefined4 *)local_8[1];
        local_8 = *(undefined4 **)(iVar1 + 0x10);
LAB_00178633:
        if (local_8 != puVar6) {
          if ((uint)local_8[3] <= uVar3) goto LAB_00178630;
          if ((uint)local_8[2] <= uVar3) {
            piVar9 = (int *)(iVar1 + 0x3c);
            do {
              do {
              } while (*piVar9 != 0);
              LOCK();
              iVar2 = *piVar9;
              *piVar9 = 1;
              UNLOCK();
            } while (iVar2 == 1);
            *(undefined4 **)(iVar1 + 0x38) = local_8;
            goto LAB_0017865a;
          }
        }
        goto LAB_00178637;
      }
      if (local_8 == puVar6) {
LAB_00178637:
        local_8 = (undefined4 *)*local_8;
        piVar9 = (int *)(iVar1 + 0x3c);
        do {
          do {
          } while (*piVar9 != 0);
          LOCK();
          iVar2 = *piVar9;
          *piVar9 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        *(undefined4 **)(iVar1 + 0x38) = local_8;
LAB_0017865a:
        LOCK();
        *(undefined4 *)(iVar1 + 0x3c) = 0;
        UNLOCK();
      }
      else if ((uint)local_8[3] <= uVar3) goto LAB_00178633;
      if (local_8[3] - uVar3 < *size) {
        *size = local_8[3] - uVar3;
      }
      uVar7 = _vm_object_name(local_8[4]);
      *in_stack_00000020 = uVar7;
      *in_stack_00000024 = (uVar3 - local_8[2]) + local_8[5];
      *object_name = (uint)(*(int *)(iVar1 + 0x30) != 1);
      _lock_done(iVar1);
    }
    _lock_done(target_task);
    kVar5 = 0;
  }
  return kVar5;
LAB_00178514:
  piVar8 = (int *)piVar8[1];
  goto LAB_00178517;
LAB_00178630:
  local_8 = (undefined4 *)local_8[1];
  goto LAB_00178633;
}

