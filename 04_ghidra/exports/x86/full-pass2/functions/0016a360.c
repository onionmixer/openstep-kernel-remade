/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016a360 */

int * FUN_0016a360(int param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  
  piVar2 = *(int **)(param_1 + 8);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    uVar1 = piVar2[1];
    if (uVar1 < param_2) {
      uVar1 = *(uint *)(param_1 + 0x18);
      uVar7 = param_2 >> ((byte)*(undefined4 *)(param_1 + 0x10) & 0x1f);
      if ((int)uVar1 < (int)uVar7) {
        uVar7 = uVar1;
      }
      piVar8 = (int *)(uVar7 * 0x10 + *(int *)(param_1 + 0x14) + -0x10);
      if ((int)uVar7 < (int)uVar1) {
        do {
          piVar2 = (int *)*piVar8;
          if (piVar2 != (int *)0x0) {
            piVar5 = (int *)*piVar2;
            if (piVar5 == (int *)0x0) goto LAB_0016a433;
            goto LAB_0016a428;
          }
          uVar7 = uVar7 + 1;
          piVar8 = piVar8 + 4;
        } while ((int)uVar7 < *(int *)(param_1 + 0x18));
      }
      piVar2 = (int *)*piVar8;
      if (piVar2 != (int *)0x0) {
        if ((uint)piVar2[1] < param_2) {
          for (piVar2 = (int *)*piVar2; (piVar2 != (int *)0x0 && ((uint)piVar2[1] < param_2));
              piVar2 = (int *)*piVar2) {
          }
        }
        else {
          piVar5 = (int *)*piVar2;
          if (piVar5 != (int *)0x0) {
            do {
              if (*(uint *)(param_1 + 4) <= (uint)piVar5[1]) break;
              piVar5 = (int *)*piVar5;
            } while (piVar5 != (int *)0x0);
          }
          *piVar8 = (int)piVar5;
        }
      }
    }
    else {
      uVar7 = *(uint *)(param_1 + 0x18);
      uVar6 = uVar1 >> ((byte)*(undefined4 *)(param_1 + 0x10) & 0x1f);
      if ((int)uVar7 < (int)uVar6) {
        uVar6 = uVar7;
      }
      iVar3 = uVar6 * 0x10 + *(int *)(param_1 + 0x14);
      if (*(int **)(iVar3 + -0x10) == piVar2) {
        if ((int)uVar6 < (int)uVar7) {
          for (puVar4 = (undefined4 *)*piVar2; (puVar4 != (undefined4 *)0x0 && (puVar4[1] != uVar1))
              ; puVar4 = (undefined4 *)*puVar4) {
          }
        }
        else {
          puVar4 = (undefined4 *)*piVar2;
          if (puVar4 != (undefined4 *)0x0) {
            do {
              if (*(uint *)(param_1 + 4) <= (uint)puVar4[1]) break;
              puVar4 = (undefined4 *)*puVar4;
            } while (puVar4 != (undefined4 *)0x0);
          }
        }
        *(undefined4 **)(iVar3 + -0x10) = puVar4;
      }
    }
  }
  return piVar2;
  while (piVar5 = (int *)*piVar5, piVar5 != (int *)0x0) {
LAB_0016a428:
    if (piVar5[1] == piVar2[1]) break;
  }
LAB_0016a433:
  *piVar8 = (int)piVar5;
  return piVar2;
}

