/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016a7f4 */

void _zone_collect(int param_1)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint local_3c;
  int *local_38;
  uint local_20;
  int *local_8;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  puVar2 = *(undefined **)(param_1 + 0x3c);
  if ((puVar2 != (undefined *)0x0) && (puVar2 != &__zone_default_space)) {
    local_8 = (int *)(puVar2 + 8);
    piVar5 = *(int **)(param_1 + 0x10);
    while (piVar5 != (int *)0x0) {
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - iVar1;
      piVar3 = (int *)*piVar5;
      local_38 = (int *)*local_8;
      if (local_38 == (int *)0x0) {
LAB_0016a881:
        piVar5[1] = iVar1;
        *piVar5 = (int)local_38;
        if (local_38 != (int *)0x0) {
          local_38[2] = (int)piVar5;
        }
        piVar5[2] = (int)local_8;
        *local_8 = (int)piVar5;
        *(int *)(puVar2 + 0xc) = *(int *)(puVar2 + 0xc) + 1;
        uVar11 = (uint)piVar5[1] >> ((byte)*(undefined4 *)(puVar2 + 0x10) & 0x1f);
        if ((int)*(uint *)(puVar2 + 0x18) < (int)uVar11) {
          uVar11 = *(uint *)(puVar2 + 0x18);
        }
        iVar9 = *(int *)(puVar2 + 0x14) + uVar11 * 0x10;
        piVar6 = *(int **)(iVar9 + -0x10);
        if ((piVar6 == (int *)0x0) || (piVar5 < piVar6)) {
          *(int **)(iVar9 + -0x10) = piVar5;
        }
      }
      else {
        do {
          if (piVar5 <= (int *)((int)local_38 + local_38[1])) break;
          local_8 = local_38;
          local_38 = (int *)*local_38;
        } while (local_38 != (int *)0x0);
        if ((local_38 == (int *)0x0) || ((int *)(iVar1 + (int)piVar5) < local_38))
        goto LAB_0016a881;
        if (local_38 == (int *)(iVar1 + (int)piVar5)) {
          uVar11 = local_38[1];
          piVar5[1] = uVar11 + iVar1;
          iVar9 = *local_38;
          *piVar5 = iVar9;
          if (iVar9 != 0) {
            *(int **)(iVar9 + 8) = piVar5;
          }
          piVar5[2] = (int)local_8;
          *local_8 = (int)piVar5;
          uVar4 = *(uint *)(puVar2 + 0x18);
          local_20 = (uint)piVar5[1] >> ((byte)*(undefined4 *)(puVar2 + 0x10) & 0x1f);
          if ((int)uVar4 < (int)local_20) {
            local_20 = uVar4;
          }
          uVar10 = uVar11 >> ((byte)*(undefined4 *)(puVar2 + 0x10) & 0x1f);
          if ((int)uVar4 < (int)uVar10) {
            uVar10 = uVar4;
          }
          iVar9 = uVar10 * 0x10 + *(int *)(puVar2 + 0x14);
          if (local_20 == uVar10) {
            if (*(int **)(iVar9 + -0x10) == local_38) {
              *(int **)(iVar9 + -0x10) = piVar5;
            }
          }
          else {
            if (*(int **)(iVar9 + -0x10) == local_38) {
              if ((int)uVar10 < (int)uVar4) {
                for (puVar7 = (undefined4 *)*piVar5;
                    (puVar7 != (undefined4 *)0x0 && (puVar7[1] != uVar11));
                    puVar7 = (undefined4 *)*puVar7) {
                }
                *(int *)(iVar9 + -0x10) = (int)puVar7;
              }
              else {
                piVar6 = (int *)*piVar5;
                if (piVar6 != (int *)0x0) {
                  do {
                    if (*(uint *)(puVar2 + 4) <= (uint)piVar6[1]) break;
                    piVar6 = (int *)*piVar6;
                  } while (piVar6 != (int *)0x0);
                }
                *(int *)(iVar9 + -0x10) = (int)piVar6;
              }
            }
            iVar9 = *(int *)(puVar2 + 0x14) + local_20 * 0x10;
            piVar6 = *(int **)(iVar9 + -0x10);
            if ((piVar6 == (int *)0x0) || (piVar5 < piVar6)) {
              *(int **)(iVar9 + -0x10) = piVar5;
            }
          }
        }
        else {
          uVar11 = local_38[1];
          if ((int *)((int)local_38 + uVar11) == piVar5) {
            local_38[1] = uVar11 + iVar1;
            puVar7 = (undefined4 *)(uVar11 + iVar1 + (int)local_38);
            if ((undefined4 *)*local_38 == puVar7) {
              uVar4 = *(uint *)(puVar2 + 0x18);
              uVar10 = (uint)puVar7[1] >> ((byte)*(undefined4 *)(puVar2 + 0x10) & 0x1f);
              if ((int)uVar4 < (int)uVar10) {
                uVar10 = uVar4;
              }
              iVar9 = uVar10 * 0x10 + *(int *)(puVar2 + 0x14);
              if (*(undefined4 **)(iVar9 + -0x10) == puVar7) {
                if ((int)uVar10 < (int)uVar4) {
                  for (puVar8 = (undefined4 *)*puVar7;
                      (puVar8 != (undefined4 *)0x0 && (puVar8[1] != puVar7[1]));
                      puVar8 = (undefined4 *)*puVar8) {
                  }
                }
                else {
                  puVar8 = (undefined4 *)*puVar7;
                  if (puVar8 != (undefined4 *)0x0) {
                    do {
                      if (*(uint *)(puVar2 + 4) <= (uint)puVar8[1]) break;
                      puVar8 = (undefined4 *)*puVar8;
                    } while (puVar8 != (undefined4 *)0x0);
                  }
                }
                *(undefined4 **)(iVar9 + -0x10) = puVar8;
              }
              local_38[1] = local_38[1] + *(int *)(*local_38 + 4);
              iVar9 = *(int *)*local_38;
              *local_38 = iVar9;
              if (iVar9 != 0) {
                *(int **)(iVar9 + 8) = local_38;
              }
              *(int *)(puVar2 + 0xc) = *(int *)(puVar2 + 0xc) + -1;
            }
            uVar4 = *(uint *)(puVar2 + 0x18);
            local_3c = (uint)local_38[1] >> ((byte)*(undefined4 *)(puVar2 + 0x10) & 0x1f);
            if ((int)uVar4 < (int)local_3c) {
              local_3c = uVar4;
            }
            uVar10 = uVar11 >> ((byte)*(undefined4 *)(puVar2 + 0x10) & 0x1f);
            if ((int)uVar4 < (int)uVar10) {
              uVar10 = uVar4;
            }
            if (local_3c != uVar10) {
              iVar9 = uVar10 * 0x10 + *(int *)(puVar2 + 0x14);
              if (*(int **)(iVar9 + -0x10) == local_38) {
                if ((int)uVar10 < (int)uVar4) {
                  for (puVar7 = (undefined4 *)*local_38;
                      (puVar7 != (undefined4 *)0x0 && (puVar7[1] != uVar11));
                      puVar7 = (undefined4 *)*puVar7) {
                  }
                }
                else {
                  puVar7 = (undefined4 *)*local_38;
                  if (puVar7 != (undefined4 *)0x0) {
                    do {
                      if (*(uint *)(puVar2 + 4) <= (uint)puVar7[1]) break;
                      puVar7 = (undefined4 *)*puVar7;
                    } while (puVar7 != (undefined4 *)0x0);
                  }
                }
                *(undefined4 **)(iVar9 + -0x10) = puVar7;
              }
              iVar9 = *(int *)(puVar2 + 0x14) + local_3c * 0x10;
              piVar5 = *(int **)(iVar9 + -0x10);
              if ((piVar5 == (int *)0x0) || (local_38 < piVar5)) {
                *(int **)(iVar9 + -0x10) = local_38;
              }
            }
          }
        }
      }
      *(int **)(param_1 + 0x10) = piVar3;
      piVar5 = piVar3;
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}

