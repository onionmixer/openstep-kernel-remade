/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016a694 */

int * _zone_free_space_add(undefined *param_1,int param_2,int *param_3,int param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int *local_14;
  uint local_10;
  
  if (param_1 == (undefined *)0x0) {
    param_1 = &__zone_default_space;
  }
  piVar4 = *(int **)(param_1 + 8);
  local_14 = (int *)(param_1 + 8);
  while (piVar5 = piVar4, piVar5 != (int *)0x0) {
    if ((param_3 <= piVar5) || ((int *)((int)piVar5 + piVar5[1]) == param_3)) {
      if (piVar5 != (int *)0x0) {
        uVar7 = piVar5[1];
        if (param_3 <= (int *)(uVar7 + (int)piVar5)) {
          if ((int *)(uVar7 + (int)piVar5) != param_3) {
            return param_3;
          }
          uVar1 = *(uint *)(param_1 + 0x18);
          local_10 = uVar7 >> ((byte)*(undefined4 *)(param_1 + 0x10) & 0x1f);
          if ((int)uVar1 < (int)local_10) {
            local_10 = uVar1;
          }
          iVar6 = local_10 * 0x10 + *(int *)(param_1 + 0x14);
          piVar4 = (int *)(iVar6 + -0x10);
          if (*(int **)(iVar6 + -0x10) != piVar5) goto LAB_0016a790;
          if ((int)local_10 < (int)uVar1) {
            for (puVar2 = (undefined4 *)*piVar5;
                (puVar2 != (undefined4 *)0x0 && (puVar2[1] != uVar7));
                puVar2 = (undefined4 *)*puVar2) {
            }
            *piVar4 = (int)puVar2;
            goto LAB_0016a790;
          }
          piVar3 = (int *)*piVar5;
          if (piVar3 == (int *)0x0) goto LAB_0016a78b;
          goto LAB_0016a780;
        }
      }
      break;
    }
    local_14 = piVar5;
    piVar4 = (int *)*piVar5;
  }
  if ((uint)(param_4 - param_2) < 0x10) {
    return param_3;
  }
  if (piVar5 != (int *)0x0) {
    local_14 = piVar5;
  }
  piVar4 = (int *)(param_2 + (int)param_3);
  piVar4[1] = param_4 - param_2;
  iVar6 = *local_14;
  *piVar4 = iVar6;
  if (iVar6 != 0) {
    *(int **)(iVar6 + 8) = piVar4;
  }
  piVar4[2] = (int)local_14;
  *local_14 = (int)piVar4;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  piVar5 = param_3;
  goto LAB_0016a7b6;
  while (piVar3 = (int *)*piVar3, piVar3 != (int *)0x0) {
LAB_0016a780:
    if (*(uint *)(param_1 + 4) <= (uint)piVar3[1]) break;
  }
LAB_0016a78b:
  *piVar4 = (int)piVar3;
LAB_0016a790:
  piVar4 = (int *)(param_2 + (int)piVar5);
  piVar4[1] = (param_4 + piVar5[1]) - param_2;
  iVar6 = *piVar5;
  *piVar4 = iVar6;
  if (iVar6 != 0) {
    *(int **)(iVar6 + 8) = piVar4;
  }
  piVar4[2] = (int)local_14;
  *local_14 = (int)piVar4;
LAB_0016a7b6:
  uVar7 = (uint)piVar4[1] >> ((byte)*(undefined4 *)(param_1 + 0x10) & 0x1f);
  if ((int)*(uint *)(param_1 + 0x18) < (int)uVar7) {
    uVar7 = *(uint *)(param_1 + 0x18);
  }
  iVar6 = *(int *)(param_1 + 0x14) + uVar7 * 0x10;
  piVar3 = *(int **)(iVar6 + -0x10);
  if ((piVar3 == (int *)0x0) || (piVar4 < piVar3)) {
    *(int **)(iVar6 + -0x10) = piVar4;
  }
  return piVar5;
}

