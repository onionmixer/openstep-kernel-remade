/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001765fc */

undefined4 _vm_map_check_protection(int param_1,uint param_2,uint param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *local_8;
  
  piVar1 = (int *)(param_1 + 0x3c);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  local_8 = *(undefined4 **)(param_1 + 0x38);
  LOCK();
  *(undefined4 *)(param_1 + 0x3c) = 0;
  UNLOCK();
  puVar3 = (undefined4 *)(param_1 + 0xc);
  if (local_8 == puVar3) {
    local_8 = *(undefined4 **)(param_1 + 0x10);
  }
  if (param_2 < (uint)local_8[2]) {
    puVar3 = (undefined4 *)local_8[1];
    local_8 = *(undefined4 **)(param_1 + 0x10);
LAB_00176687:
    if (local_8 != puVar3) {
      if ((uint)local_8[3] <= param_2) goto LAB_00176684;
      if ((uint)local_8[2] <= param_2) {
        piVar1 = (int *)(param_1 + 0x3c);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar2 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        *(undefined4 **)(param_1 + 0x38) = local_8;
        LOCK();
        *(undefined4 *)(param_1 + 0x3c) = 0;
        UNLOCK();
        goto LAB_001766b8;
      }
    }
    goto LAB_0017668b;
  }
  if (local_8 == puVar3) {
LAB_0017668b:
    uVar4 = *local_8;
    piVar1 = (int *)(param_1 + 0x3c);
    do {
      do {
      } while (*piVar1 != 0);
      LOCK();
      iVar2 = *piVar1;
      *piVar1 = 1;
      UNLOCK();
    } while (iVar2 == 1);
    *(undefined4 *)(param_1 + 0x38) = uVar4;
    LOCK();
    *(undefined4 *)(param_1 + 0x3c) = 0;
    UNLOCK();
LAB_001766b3:
    uVar4 = 0;
  }
  else {
    if ((uint)local_8[3] <= param_2) goto LAB_00176687;
LAB_001766b8:
    if (param_2 < param_3) {
      do {
        if (((local_8 == (undefined4 *)(param_1 + 0xc)) || (param_2 < (uint)local_8[2])) ||
           (param_4 != (param_4 & local_8[7]))) goto LAB_001766b3;
        param_2 = local_8[3];
        local_8 = (undefined4 *)local_8[1];
      } while (param_2 < param_3);
    }
    uVar4 = 1;
  }
  return uVar4;
LAB_00176684:
  local_8 = (undefined4 *)local_8[1];
  goto LAB_00176687;
}

