
void _pset_add_processor(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x118);
  if (piVar1 == (int *)(param_1 + 0x114)) {
    *piVar1 = param_2;
  }
  else {
    piVar1[0x4c] = param_2;
  }
  *(int **)(param_2 + 0x134) = piVar1;
  *(int *)(param_2 + 0x130) = param_1 + 0x114;
  *(int *)(param_1 + 0x118) = param_2;
  *(int *)(param_2 + 0x128) = param_1;
  *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + 1;
  _quantum_set(param_1);
  return;
}
