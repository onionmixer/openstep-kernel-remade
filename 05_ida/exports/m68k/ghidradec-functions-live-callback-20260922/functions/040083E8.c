
void _ruadd(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  _timevaladd(param_1,param_2);
  _timevaladd(param_1 + 8,param_2 + 8);
  if (*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10)) {
    *(int *)(param_1 + 0x10) = *(int *)(param_2 + 0x10);
  }
  iVar1 = 0xc;
  piVar2 = (int *)(param_1 + 0x14);
  piVar3 = (int *)(param_2 + 0x14);
  do {
    *piVar2 = *piVar3 + *piVar2;
    iVar1 = iVar1 + -1;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (0 < iVar1);
  return;
}

