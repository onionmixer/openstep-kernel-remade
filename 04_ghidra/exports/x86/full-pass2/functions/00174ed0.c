/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00174ed0 */

undefined4 * __vm_map_clip_end(int param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  
  uVar2 = _vm_map_kentry_zone;
  if (*(int *)(param_1 + 0x14) != 0) {
    uVar2 = _vm_map_entry_zone;
  }
  piVar3 = (int *)_zalloc(uVar2);
  if (piVar3 != (int *)0x0) {
    piVar6 = param_2;
    piVar7 = piVar3;
    for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar7 = *piVar6;
      piVar6 = piVar6 + 1;
      piVar7 = piVar7 + 1;
    }
    param_2[3] = param_3;
    piVar3[2] = param_3;
    piVar3[5] = piVar3[5] + (param_3 - param_2[2]);
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    *piVar3 = (int)param_2;
    piVar3[1] = param_2[1];
    iVar5 = *piVar3;
    puVar4 = (undefined4 *)piVar3[1];
    *puVar4 = piVar3;
    *(int **)(iVar5 + 4) = piVar3;
    if ((*(byte *)(param_2 + 6) & 5) == 0) {
      puVar4 = (undefined4 *)_vm_object_reference(piVar3[4]);
    }
    else {
      iVar5 = piVar3[4];
      if (iVar5 != 0) {
        piVar3 = (int *)(iVar5 + 0x34);
        do {
          do {
          } while (*piVar3 != 0);
          LOCK();
          iVar1 = *piVar3;
          *piVar3 = 1;
          UNLOCK();
        } while (iVar1 == 1);
        *(int *)(iVar5 + 0x30) = *(int *)(iVar5 + 0x30) + 1;
        LOCK();
        puVar4 = *(undefined4 **)(iVar5 + 0x34);
        *(undefined4 *)(iVar5 + 0x34) = 0;
        UNLOCK();
      }
    }
    return puVar4;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_vm_map_entry_create_001e0ab0);
}

