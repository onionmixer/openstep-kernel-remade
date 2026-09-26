
int _dequeue_tail(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (param_1 == iVar1) {
    iVar1 = 0;
  }
  else {
    **(int **)(iVar1 + 4) = param_1;
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar1 + 4);
  }
  return iVar1;
}

