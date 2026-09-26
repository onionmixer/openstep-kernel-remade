
undefined4 _ipc_port_check_circularity(int *param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_2 == param_1) {
loc_4041192:
    uVar2 = 1;
  }
  else {
    piVar3 = param_2;
    if (((param_2[1] < 0) && (param_2[3] == 0)) && (piVar1 = param_2, param_2[2] != 0)) {
      do {
        piVar3 = piVar1;
        if ((-1 < piVar3[1]) || (piVar3[3] != 0)) break;
        piVar1 = (int *)piVar3[2];
      } while ((int *)piVar3[2] != (int *)0x0);
      if (piVar3 == param_1) {
        for (; param_2 != (int *)0x0; param_2 = (int *)param_2[2]) {
        }
        goto loc_4041192;
      }
    }
    *param_2 = *param_2 + 1;
    param_1[2] = (int)param_2;
    for (; piVar3 != param_1; param_1 = (int *)param_1[2]) {
    }
    uVar2 = 0;
  }
  return uVar2;
}

