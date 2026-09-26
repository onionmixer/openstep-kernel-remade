
void _ipc_thread_rmqueue(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + 0x8c);
  iVar2 = *(int *)(param_2 + 0x90);
  if (param_2 == iVar1) {
    *param_1 = 0;
  }
  else {
    if (param_2 == *param_1) {
      *param_1 = iVar1;
    }
    *(int *)(iVar1 + 0x90) = iVar2;
    *(int *)(iVar2 + 0x8c) = iVar1;
    *(int *)(param_2 + 0x8c) = param_2;
    *(int *)(param_2 + 0x90) = param_2;
  }
  return;
}

