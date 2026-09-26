
int _disksort_remove(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  sub_4036D3E(param_1);
  if (*(char *)(param_1 + 0xc) < '\0') {
    iVar5 = (*dword_40C1094)(param_1,param_2);
  }
  else {
    piVar4 = (int *)(param_1 + 0xe);
    piVar6 = (int *)*piVar4;
    if (piVar6 == piVar4) {
      iVar5 = 0;
    }
    else {
      do {
        iVar5 = *piVar6;
        if (param_2 == iVar5) {
          *piVar6 = *(int *)(iVar5 + 0xc);
          if (piVar6 == *(int **)(param_1 + 0xe)) {
            *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xef;
            *(undefined4 *)(param_1 + 0x1a) = *(undefined4 *)(iVar5 + 0x38);
          }
          break;
        }
        if (*(int *)(iVar5 + 0xc) != 0) {
          do {
            iVar1 = *(int *)(iVar5 + 0xc);
            iVar7 = iVar5;
            if (param_2 == iVar1) break;
            iVar5 = iVar1;
            iVar7 = iVar1;
          } while (*(int *)(iVar1 + 0xc) != 0);
          iVar5 = iVar7;
          if (*(int *)(iVar7 + 0xc) != 0) {
            iVar1 = *(int *)(param_2 + 0xc);
            *(int *)(iVar7 + 0xc) = iVar1;
            iVar5 = param_2;
            if (iVar1 == 0) {
              piVar6[1] = iVar7;
            }
            break;
          }
        }
        piVar6 = (int *)piVar6[4];
      } while (piVar6 != piVar4);
      while (((piVar6 = *(int **)(param_1 + 0xe), (*(byte *)(param_1 + 0xc) & 0x10) == 0 &&
              (piVar4 = (int *)(param_1 + 0xe), piVar4 != (int *)*piVar4)) && (*piVar6 == 0))) {
        piVar2 = (int *)piVar6[4];
        puVar3 = (undefined4 *)piVar6[5];
        if (piVar2 == piVar4) {
          *(undefined4 **)(param_1 + 0x12) = puVar3;
        }
        else {
          piVar2[5] = (int)puVar3;
        }
        if (puVar3 == (undefined4 *)(param_1 + 0xe)) {
          *puVar3 = piVar2;
        }
        else {
          puVar3[4] = piVar2;
        }
        _kfree(piVar6,0x18);
        *(int *)(param_1 + 0x16) = *(int *)(param_1 + 0x16) + 1;
      }
    }
  }
  return iVar5;
}

