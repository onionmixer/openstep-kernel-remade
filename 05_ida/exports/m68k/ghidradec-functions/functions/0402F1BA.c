
int * _ku_recvfrom(int param_1,undefined4 *param_2)

{
  int iVar1;
  sword sVar2;
  sword *psVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  
  psVar3 = (sword *)(param_1 + 0x22);
  iVar5 = 0;
  piVar4 = *(int **)(param_1 + 0x2e);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    iVar1 = piVar4[0x1f];
    puVar6 = (undefined4 *)(piVar4[1] + (int)piVar4);
    *param_2 = *puVar6;
    param_2[1] = puVar6[1];
    param_2[2] = puVar6[2];
    param_2[3] = puVar6[3];
    do {
      if (*(sword *)((int)piVar4 + 10) == 1) break;
      *psVar3 = *psVar3 - *(sword *)(piVar4 + 2);
      sVar2 = *(sword *)(param_1 + 0x26);
      *(sword *)(param_1 + 0x26) = sVar2 + -0x80;
      if (0x7c < (uint)piVar4[1]) {
        *(sword *)(param_1 + 0x26) = sVar2 + -0x480;
      }
      piVar4 = (int *)_m_free(piVar4);
    } while (piVar4 != (int *)0x0);
    piVar7 = piVar4;
    if (piVar4 == (int *)0x0) {
      _printf(aKuRecvfromNoBo);
      *(int *)(param_1 + 0x2e) = iVar1;
      piVar4 = (int *)0x0;
    }
    else {
      do {
        *psVar3 = *psVar3 - *(sword *)(piVar7 + 2);
        sVar2 = *(sword *)(param_1 + 0x26);
        *(sword *)(param_1 + 0x26) = sVar2 + -0x80;
        if (0x7c < (uint)piVar7[1]) {
          *(sword *)(param_1 + 0x26) = sVar2 + -0x480;
        }
        iVar5 = *(sword *)(piVar7 + 2) + iVar5;
        piVar7 = (int *)*piVar7;
      } while (piVar7 != (int *)0x0);
      *(int *)(param_1 + 0x2e) = iVar1;
      if (0x2260 < iVar5) {
        _printf(aKuRecvfromLenD,iVar5);
      }
    }
  }
  return piVar4;
}
