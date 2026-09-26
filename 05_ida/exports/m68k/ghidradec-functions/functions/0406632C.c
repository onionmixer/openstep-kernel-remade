
undefined4 _busgo(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 0x22);
  piVar2 = (int *)piVar1[3];
  if ((((*(byte *)(*piVar1 + 0x31) & 1) == 0) || (*(sword *)(piVar2 + 2) < 1)) &&
     (*(sword *)((int)piVar2 + 10) == 0)) {
    *(sword *)(piVar2 + 2) = *(sword *)(piVar2 + 2) + 1;
    if ((*(byte *)(*piVar1 + 0x31) & 1) != 0) {
      *(undefined2 *)((int)piVar2 + 10) = 1;
    }
    piVar1[4] = param_1;
    (**(code **)(*piVar1 + 0xc))(piVar1);
    uVar3 = 1;
  }
  else {
    if (param_1 != *piVar2) {
      *(undefined4 *)(param_1 + 0x1e) = 0;
      if (*piVar2 == 0) {
        *piVar2 = param_1;
      }
      else {
        *(int *)(piVar2[1] + 0x1e) = param_1;
      }
      piVar2[1] = param_1;
    }
    uVar3 = 0;
  }
  return uVar3;
}
