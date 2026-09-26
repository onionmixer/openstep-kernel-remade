
void _pset_remove_thread(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_2 + 0x18);
  piVar2 = *(int **)(param_2 + 0x1c);
  if (iVar1 == param_1 + 0x130) {
    *(int **)(param_1 + 0x134) = piVar2;
  }
  else {
    *(int **)(iVar1 + 0x1c) = piVar2;
  }
  if (piVar2 == (int *)(param_1 + 0x130)) {
    *piVar2 = iVar1;
  }
  else {
    piVar2[6] = iVar1;
  }
  *(undefined4 *)(param_2 + 0x178) = 0;
  *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + -1;
  return;
}

