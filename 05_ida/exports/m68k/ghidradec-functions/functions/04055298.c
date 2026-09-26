
void _zone_collect(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined8 *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  
  iVar3 = *(int *)(param_1 + 0x18);
  puVar4 = *(undefined8 **)(param_1 + 0x32);
  if ((puVar4 != (undefined8 *)0x0) && (puVar4 != &__zone_default_space)) {
    piVar11 = (int *)(puVar4 + 1);
    piVar6 = *(int **)(param_1 + 0xc);
    while (piVar6 != (int *)0x0) {
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) - iVar3;
      piVar1 = (int *)*piVar6;
      piVar10 = (int *)*piVar11;
      if (piVar10 == (int *)0x0) {
loc_40552FC:
        piVar6[1] = iVar3;
        *piVar6 = (int)piVar10;
        if (piVar10 != (int *)0x0) {
          piVar10[2] = (int)piVar6;
        }
        piVar6[2] = (int)piVar11;
        *piVar11 = (int)piVar6;
        *(int *)((int)puVar4 + 0xc) = *(int *)((int)puVar4 + 0xc) + 1;
        uVar7 = (uint)piVar6[1] >> (*(uint *)(puVar4 + 2) & 0x3f);
        if ((int)*(uint *)(puVar4 + 3) < (int)uVar7) {
          uVar7 = *(uint *)(puVar4 + 3);
        }
        puVar8 = (undefined4 *)(uVar7 * 0x10 + *(int *)((int)puVar4 + 0x14) + -0x10);
        piVar10 = (int *)*puVar8;
        if ((piVar10 == (int *)0x0) || (piVar6 < piVar10)) {
          *puVar8 = piVar6;
        }
      }
      else {
        do {
          piVar9 = piVar10;
          piVar10 = piVar9;
          if (piVar6 <= (int *)(piVar9[1] + (int)piVar9)) break;
          piVar10 = (int *)*piVar9;
          piVar11 = piVar9;
        } while (piVar10 != (int *)0x0);
        if ((piVar10 == (int *)0x0) || ((int *)((int)piVar6 + iVar3) < piVar10)) goto loc_40552FC;
        if (piVar10 == (int *)((int)piVar6 + iVar3)) {
          iVar5 = piVar10[1];
          piVar6[1] = iVar3 + iVar5;
          iVar2 = *piVar10;
          *piVar6 = iVar2;
          if (iVar2 != 0) {
            *(int **)(iVar2 + 8) = piVar6;
          }
          piVar6[2] = (int)piVar11;
          *piVar11 = (int)piVar6;
          sub_4054DD6(puVar4,piVar6,iVar5,piVar10);
        }
        else {
          iVar2 = piVar10[1];
          if (piVar6 == (int *)((int)piVar10 + iVar2)) {
            piVar10[1] = iVar3 + iVar2;
            iVar5 = (int)piVar10 + iVar3 + iVar2;
            if (iVar5 == *piVar10) {
              sub_4054D62(puVar4,iVar5);
              piVar10[1] = *(int *)(*piVar10 + 4) + piVar10[1];
              iVar5 = *(int *)*piVar10;
              *piVar10 = iVar5;
              if (iVar5 != 0) {
                *(int **)(iVar5 + 8) = piVar10;
              }
              *(int *)((int)puVar4 + 0xc) = *(int *)((int)puVar4 + 0xc) + -1;
            }
            sub_4054E7E(puVar4,piVar10,iVar2);
          }
        }
      }
      *(int **)(param_1 + 0xc) = piVar1;
      piVar6 = piVar1;
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}
