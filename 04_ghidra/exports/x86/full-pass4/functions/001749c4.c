/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001749c4 */

undefined4 _vm_map_lookup_entry(int param_1,uint param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  piVar1 = (int *)(param_1 + 0x3c);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  puVar4 = *(undefined4 **)(param_1 + 0x38);
  LOCK();
  *(undefined4 *)(param_1 + 0x3c) = 0;
  UNLOCK();
  puVar3 = (undefined4 *)(param_1 + 0xc);
  if (puVar4 == puVar3) {
    puVar4 = *(undefined4 **)(param_1 + 0x10);
  }
  if (param_2 < (uint)puVar4[2]) {
    puVar3 = (undefined4 *)puVar4[1];
    puVar4 = *(undefined4 **)(param_1 + 0x10);
  }
  else {
    if (puVar4 == puVar3) goto LAB_00174a5b;
    if (param_2 < (uint)puVar4[3]) {
      *param_3 = puVar4;
      return 1;
    }
  }
  for (; puVar4 != puVar3; puVar4 = (undefined4 *)puVar4[1]) {
    if (param_2 < (uint)puVar4[3]) {
      if ((uint)puVar4[2] <= param_2) {
        *param_3 = puVar4;
        piVar1 = (int *)(param_1 + 0x3c);
        do {
          do {
          } while (*piVar1 != 0);
          LOCK();
          iVar2 = *piVar1;
          *piVar1 = 1;
          UNLOCK();
        } while (iVar2 == 1);
        *(undefined4 **)(param_1 + 0x38) = puVar4;
        LOCK();
        *(undefined4 *)(param_1 + 0x3c) = 0;
        UNLOCK();
        return 1;
      }
      break;
    }
  }
LAB_00174a5b:
  *param_3 = *puVar4;
  piVar1 = (int *)(param_1 + 0x3c);
  do {
    do {
    } while (*piVar1 != 0);
    LOCK();
    iVar2 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar2 == 1);
  *(undefined4 *)(param_1 + 0x38) = *param_3;
  LOCK();
  *(undefined4 *)(param_1 + 0x3c) = 0;
  UNLOCK();
  return 0;
}

