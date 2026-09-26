
undefined4 _ipc_port_dnrequest(int param_1,int param_2,int param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  piVar3 = *(int **)(param_1 + 0x28);
  if ((piVar3 == (int *)0x0) || (iVar2 = *piVar3, iVar2 == 0)) {
    uVar4 = 3;
  }
  else {
    piVar1 = piVar3 + iVar2 * 2;
    *piVar3 = *piVar1;
    piVar1[1] = param_2;
    *piVar1 = param_3;
    *param_4 = iVar2;
    uVar4 = 0;
  }
  return uVar4;
}

