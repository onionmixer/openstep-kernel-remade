
void _pset_add_task(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x128);
  if (piVar1 == (int *)(param_1 + 0x124)) {
    *piVar1 = param_2;
  }
  else {
    piVar1[3] = param_2;
  }
  *(int **)(param_2 + 0x10) = piVar1;
  *(int *)(param_2 + 0xc) = param_1 + 0x124;
  *(int *)(param_1 + 0x128) = param_2;
  *(int *)(param_2 + 0x24) = param_1;
  *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + 1;
  return;
}

