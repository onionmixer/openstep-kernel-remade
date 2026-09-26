/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001cb464 */

int _NXHashGet(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  uVar1 = (**(code **)*param_1)(param_1[4],param_2);
  piVar4 = (int *)((uVar1 % (uint)param_1[2]) * 8 + param_1[3]);
  iVar2 = *piVar4;
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      if ((piVar4[1] == param_2) ||
         (iVar2 = (**(code **)(*param_1 + 4))(param_1[4],param_2,piVar4[1]), iVar2 != 0)) {
        return piVar4[1];
      }
    }
    else {
      piVar4 = (int *)piVar4[1];
      while (iVar2 = iVar2 + -1, iVar2 != -1) {
        if ((*piVar4 == param_2) ||
           (iVar3 = (**(code **)(*param_1 + 4))(param_1[4],param_2,*piVar4), iVar3 != 0)) {
          return *piVar4;
        }
        piVar4 = piVar4 + 1;
      }
    }
  }
  return 0;
}

