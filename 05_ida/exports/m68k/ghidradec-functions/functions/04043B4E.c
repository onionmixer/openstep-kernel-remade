
int _ipc_thread_dequeue(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x8c);
    if (iVar1 == iVar2) {
      *param_1 = 0;
    }
    else {
      iVar3 = *(int *)(iVar1 + 0x90);
      *param_1 = iVar2;
      *(int *)(iVar2 + 0x90) = iVar3;
      *(int *)(iVar3 + 0x8c) = iVar2;
      *(int *)(iVar1 + 0x8c) = iVar1;
      *(int *)(iVar1 + 0x90) = iVar1;
    }
  }
  return iVar1;
}
