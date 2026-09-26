
void _ipc_kmsg_enqueue(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    *param_1 = (int)param_2;
    *param_2 = (int)param_2;
    param_2[1] = (int)param_2;
  }
  else {
    puVar2 = *(undefined4 **)(iVar1 + 4);
    *param_2 = iVar1;
    param_2[1] = (int)puVar2;
    *(int **)(iVar1 + 4) = param_2;
    *puVar2 = param_2;
  }
  return;
}

