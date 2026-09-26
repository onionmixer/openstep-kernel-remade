
int _ipc_port_dncancel(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x28);
  piVar1 = piVar3 + param_3 * 2;
  iVar2 = *piVar1;
  piVar1[1] = 0;
  *piVar1 = *piVar3;
  *piVar3 = param_3;
  return iVar2;
}
