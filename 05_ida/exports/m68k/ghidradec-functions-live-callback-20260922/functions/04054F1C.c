
int * sub_4054F1C(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar3 = *(int **)(param_1 + 8);
  if (piVar3 == (int *)0x0) {
    return (int *)0x0;
  }
  if (param_2 <= (uint)piVar3[1]) {
    sub_4054D62(param_1,piVar3);
    return piVar3;
  }
  uVar1 = *(uint *)(param_1 + 0x18);
  uVar2 = param_2 >> (*(uint *)(param_1 + 0x10) & 0x3f);
  if ((int)uVar1 < (int)uVar2) {
    uVar2 = uVar1;
  }
  piVar3 = (int *)(uVar2 * 0x10 + *(int *)(param_1 + 0x14) + -0x10);
  if ((int)uVar2 < (int)uVar1) {
    do {
      piVar5 = (int *)*piVar3;
      if (piVar5 != (int *)0x0) {
        piVar4 = (int *)*piVar5;
        if (piVar4 == (int *)0x0) goto loc_4054FD4;
        goto loc_4054F82;
      }
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 4;
    } while ((int)uVar2 < *(int *)(param_1 + 0x18));
  }
  piVar5 = (int *)*piVar3;
  if (piVar5 == (int *)0x0) {
    return (int *)0x0;
  }
  if ((uint)piVar5[1] < param_2) {
    piVar5 = (int *)*piVar5;
    while( true ) {
      if (piVar5 == (int *)0x0) {
        return (int *)0x0;
      }
      if (param_2 <= (uint)piVar5[1]) break;
      piVar5 = (int *)*piVar5;
    }
    return piVar5;
  }
  piVar4 = (int *)*piVar5;
  if (piVar4 != (int *)0x0) {
    do {
      if (*(uint *)(param_1 + 4) <= (uint)piVar4[1]) break;
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)0x0);
  }
loc_4054FD4:
  *piVar3 = (int)piVar4;
  return piVar5;
  while (piVar4 = (int *)*piVar4, piVar4 != (int *)0x0) {
loc_4054F82:
    if (piVar5[1] == piVar4[1]) break;
  }
  goto loc_4054FD4;
}

