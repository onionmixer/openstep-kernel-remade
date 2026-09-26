
int _retrieve_task_notify(int param_1)

{
  int iVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x7c) + 4) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0x7c) + 0x3c);
    if ((iVar1 != 0) && (iVar1 != -1)) {
      _ipc_object_reference(iVar1);
    }
  }
  return iVar1;
}

