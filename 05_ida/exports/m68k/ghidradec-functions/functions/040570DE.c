
undefined4 _kern_serv_callout(int *param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = *param_1;
  iVar5 = _curipl();
  if ((iVar5 == 0) && (iVar5 = _task_self(), iVar5 == *(int *)(iVar1 + 8))) {
    (*param_2)(param_3);
  }
  else {
    piVar4 = (int *)(iVar1 + 0x3c);
    piVar2 = (int *)*piVar4;
    if (piVar2 == piVar4) {
      return 6;
    }
    piVar3 = (int *)piVar2[2];
    if (piVar3 == piVar4) {
      *(int **)(iVar1 + 0x40) = piVar3;
    }
    else {
      piVar3[3] = (int)piVar4;
    }
    *(int **)(iVar1 + 0x3c) = piVar3;
    *piVar2 = (int)param_2;
    piVar2[1] = param_3;
    piVar4 = *(int **)(iVar1 + 0x38);
    if (piVar4 == (int *)(iVar1 + 0x34)) {
      *piVar4 = (int)piVar2;
    }
    else {
      piVar4[2] = (int)piVar2;
    }
    piVar2[3] = (int)piVar4;
    piVar2[2] = iVar1 + 0x34;
    *(int **)(iVar1 + 0x38) = piVar2;
    _calloutDispatchUnique(sub_405718E,*(undefined4 *)(iVar1 + 0xc));
  }
  return 0;
}
