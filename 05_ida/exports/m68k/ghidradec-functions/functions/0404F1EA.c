
void _pset_add_thread(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x134);
  if (piVar1 == (int *)(param_1 + 0x130)) {
    *piVar1 = param_2;
  }
  else {
    piVar1[6] = param_2;
  }
  *(int **)(param_2 + 0x1c) = piVar1;
  *(int *)(param_2 + 0x18) = param_1 + 0x130;
  *(int *)(param_1 + 0x134) = param_2;
  *(int *)(param_2 + 0x178) = param_1;
  *(int *)(param_1 + 0x138) = *(int *)(param_1 + 0x138) + 1;
  return;
}
