/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001491ac */

uint _ipc_kmsg_copyout_pseudo(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_2c;
  int *local_10;
  int *local_c;
  int *local_8;
  
  uVar6 = *(uint *)(param_1 + 0x14);
  piVar2 = *(int **)(param_1 + 0x1c);
  piVar3 = *(int **)(param_1 + 0x20);
  uVar7 = uVar6 & 0xff;
  uVar4 = (uVar6 & 0xff00) >> 8;
  piVar1 = piVar2;
  if ((piVar2 == (int *)0x0) || (piVar2 == (int *)0xffffffff)) {
LAB_001492df:
    local_8 = piVar1;
    local_2c = 0;
  }
  else {
    if (uVar7 == 0x11) {
      piVar1 = (int *)(param_2 + 8);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar5 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar5 == 1);
      if (*(int *)(param_2 + 0xc) != 0) {
        do {
          do {
          } while (*piVar2 != 0);
          LOCK();
          iVar5 = *piVar2;
          *piVar2 = 1;
          UNLOCK();
        } while (iVar5 == 1);
        if ((piVar2[2] < 0) &&
           (iVar5 = _ipc_hash_local_lookup(param_2,piVar2,&local_8,&local_10), iVar5 != 0)) {
          piVar2[7] = piVar2[7] + -1;
          piVar2[1] = piVar2[1] + -1;
          LOCK();
          *piVar2 = 0;
          UNLOCK();
          if ((short)(*local_10 + 1) != -1) {
            *local_10 = *local_10 + 1;
          }
          LOCK();
          *(undefined4 *)(param_2 + 8) = 0;
          UNLOCK();
          piVar1 = local_8;
          goto LAB_001492df;
        }
        LOCK();
        *piVar2 = 0;
        UNLOCK();
      }
      LOCK();
      *(undefined4 *)(param_2 + 8) = 0;
      UNLOCK();
    }
    iVar5 = _ipc_object_copyout(param_2,piVar2,uVar7,1,&local_8);
    piVar1 = local_8;
    if (iVar5 == 0) goto LAB_001492df;
    _ipc_object_destroy(piVar2,uVar7);
    if (iVar5 == 0x14) {
      local_8 = (int *)0xffffffff;
      piVar1 = local_8;
      goto LAB_001492df;
    }
    local_8 = (int *)0x0;
    local_2c = 0x2000;
    if (iVar5 == 6) {
      local_2c = 0x800;
    }
  }
  piVar2 = piVar3;
  if ((piVar3 != (int *)0x0) && (piVar3 != (int *)0xffffffff)) {
    if (uVar4 == 0x11) {
      piVar2 = (int *)(param_2 + 8);
      do {
        do {
        } while (*piVar2 != 0);
        LOCK();
        iVar5 = *piVar2;
        *piVar2 = 1;
        UNLOCK();
      } while (iVar5 == 1);
      if (*(int *)(param_2 + 0xc) != 0) {
        do {
          do {
          } while (*piVar3 != 0);
          LOCK();
          iVar5 = *piVar3;
          *piVar3 = 1;
          UNLOCK();
        } while (iVar5 == 1);
        if ((piVar3[2] < 0) &&
           (iVar5 = _ipc_hash_local_lookup(param_2,piVar3,&local_c,&local_10), iVar5 != 0)) {
          piVar3[7] = piVar3[7] + -1;
          piVar3[1] = piVar3[1] + -1;
          LOCK();
          *piVar3 = 0;
          UNLOCK();
          if ((short)(*local_10 + 1) != -1) {
            *local_10 = *local_10 + 1;
          }
          LOCK();
          *(undefined4 *)(param_2 + 8) = 0;
          UNLOCK();
          piVar2 = local_c;
          goto LAB_001493d7;
        }
        LOCK();
        *piVar3 = 0;
        UNLOCK();
      }
      LOCK();
      *(undefined4 *)(param_2 + 8) = 0;
      UNLOCK();
    }
    iVar5 = _ipc_object_copyout(param_2,piVar3,uVar4,1,&local_c);
    piVar2 = local_c;
    if (iVar5 != 0) {
      _ipc_object_destroy(piVar3,uVar4);
      if (iVar5 != 0x14) {
        local_c = (int *)0x0;
        uVar4 = 0x2000;
        if (iVar5 == 6) {
          uVar4 = 0x800;
        }
        goto LAB_001493d9;
      }
      local_c = (int *)0xffffffff;
      piVar2 = local_c;
    }
  }
LAB_001493d7:
  local_c = piVar2;
  uVar4 = 0;
LAB_001493d9:
  local_2c = local_2c | uVar4;
  *(uint *)(param_1 + 0x14) = uVar6 & 0xbfffffff;
  *(int **)(param_1 + 0x1c) = local_8;
  *(int **)(param_1 + 0x20) = local_c;
  if ((int)uVar6 < 0) {
    uVar6 = _ipc_kmsg_copyout_body
                      (param_1 + 0x2c,*(int *)(param_1 + 0x18) + 0x14 + param_1,param_2,param_3);
    local_2c = local_2c | uVar6;
  }
  return local_2c;
}

