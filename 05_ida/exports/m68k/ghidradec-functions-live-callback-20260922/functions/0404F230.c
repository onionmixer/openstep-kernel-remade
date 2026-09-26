
void _thread_change_psets(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  piVar2 = *(int **)(param_1 + 0x1c);
  if (iVar1 == param_2 + 0x130) {
    *(int **)(param_2 + 0x134) = piVar2;
  }
  else {
    *(int **)(iVar1 + 0x1c) = piVar2;
  }
  if (piVar2 == (int *)(param_2 + 0x130)) {
    *piVar2 = iVar1;
  }
  else {
    piVar2[6] = iVar1;
  }
  *(int *)(param_2 + 0x138) = *(int *)(param_2 + 0x138) + -1;
  piVar2 = *(int **)(param_3 + 0x134);
  if (piVar2 == (int *)(param_3 + 0x130)) {
    *piVar2 = param_1;
  }
  else {
    piVar2[6] = param_1;
  }
  *(int **)(param_1 + 0x1c) = piVar2;
  *(int *)(param_1 + 0x18) = param_3 + 0x130;
  *(int *)(param_3 + 0x134) = param_1;
  *(int *)(param_1 + 0x178) = param_3;
  *(int *)(param_3 + 0x138) = *(int *)(param_3 + 0x138) + 1;
  return;
}

