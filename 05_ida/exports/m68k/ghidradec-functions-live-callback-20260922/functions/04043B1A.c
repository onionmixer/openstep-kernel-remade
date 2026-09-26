
void _ipc_thread_enqueue(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    *param_1 = param_2;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x90);
    *(int *)(param_2 + 0x8c) = iVar1;
    *(int *)(param_2 + 0x90) = iVar2;
    *(int *)(iVar1 + 0x90) = param_2;
    *(int *)(iVar2 + 0x8c) = param_2;
  }
  return;
}

