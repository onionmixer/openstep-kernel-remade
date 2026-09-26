
void _pset_remove_task(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == *(int *)(param_2 + 0x24)) {
    iVar1 = *(int *)(param_2 + 0xc);
    piVar2 = *(int **)(param_2 + 0x10);
    if (iVar1 == param_1 + 0x124) {
      *(int **)(param_1 + 0x128) = piVar2;
    }
    else {
      *(int **)(iVar1 + 0x10) = piVar2;
    }
    if (piVar2 == (int *)(param_1 + 0x124)) {
      *piVar2 = iVar1;
    }
    else {
      piVar2[3] = iVar1;
    }
    *(undefined4 *)(param_2 + 0x24) = 0;
    *(int *)(param_1 + 300) = *(int *)(param_1 + 300) + -1;
  }
  return;
}

