/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001144ec */

void _m_adj(int *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (param_1 != (int *)0x0) {
    if (param_2 < 0) {
      iVar4 = (int)(short)param_1[2];
      iVar2 = *param_1;
      piVar3 = param_1;
      while (iVar2 != 0) {
        piVar3 = (int *)*piVar3;
        iVar4 = iVar4 + (short)piVar3[2];
        iVar2 = *piVar3;
      }
      if ((int)(short)piVar3[2] < -param_2) {
        iVar4 = iVar4 + param_2;
        for (; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
          if (iVar4 <= (short)param_1[2]) {
            *(short *)(param_1 + 2) = (short)iVar4;
            break;
          }
          iVar4 = iVar4 - (short)param_1[2];
        }
        while (param_1 = (int *)*param_1, param_1 != (int *)0x0) {
          *(undefined2 *)(param_1 + 2) = 0;
        }
      }
      else {
        *(short *)(piVar3 + 2) = (short)piVar3[2] - (short)-param_2;
      }
    }
    else {
      do {
        if (param_2 < 1) {
          return;
        }
        sVar1 = (short)param_1[2];
        if (param_2 < sVar1) {
          *(short *)(param_1 + 2) = sVar1 - (short)param_2;
          param_1[1] = param_1[1] + param_2;
          return;
        }
        param_2 = param_2 - sVar1;
        *(undefined2 *)(param_1 + 2) = 0;
        param_1 = (int *)*param_1;
      } while (param_1 != (int *)0x0);
    }
  }
  return;
}

