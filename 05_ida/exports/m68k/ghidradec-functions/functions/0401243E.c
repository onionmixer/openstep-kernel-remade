
void _m_adj(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  sword sVar3;
  int iVar4;
  
  if (param_1 != (int *)0x0) {
    if (param_2 < 0) {
      iVar4 = (int)*(sword *)(param_1 + 2);
      iVar1 = *param_1;
      piVar2 = param_1;
      while (iVar1 != 0) {
        piVar2 = (int *)*piVar2;
        iVar4 = *(sword *)(piVar2 + 2) + iVar4;
        iVar1 = *piVar2;
      }
      sVar3 = *(sword *)(piVar2 + 2);
      if (-(int)sVar3 == param_2 || -param_2 < (int)sVar3) {
        *(sword *)(piVar2 + 2) = sVar3 - (sword)-param_2;
      }
      else {
        iVar4 = iVar4 + param_2;
        for (; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
          if (iVar4 <= *(sword *)(param_1 + 2)) {
            *(sword *)(param_1 + 2) = (sword)iVar4;
            break;
          }
          iVar4 = iVar4 - *(sword *)(param_1 + 2);
        }
        while (param_1 = (int *)*param_1, param_1 != (int *)0x0) {
          *(undefined2 *)(param_1 + 2) = 0;
        }
      }
    }
    else {
      do {
        if (param_2 < 1) {
          return;
        }
        sVar3 = *(sword *)(param_1 + 2);
        if (param_2 < sVar3) {
          *(sword *)(param_1 + 2) = sVar3 - (sword)param_2;
          param_1[1] = param_2 + param_1[1];
          return;
        }
        param_2 = param_2 - sVar3;
        *(undefined2 *)(param_1 + 2) = 0;
        param_1 = (int *)*param_1;
      } while (param_1 != (int *)0x0);
    }
  }
  return;
}
