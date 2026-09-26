
int _retrieve_thread_reply(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xa4) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xb0);
    if ((iVar1 != 0) && (iVar1 != -1)) {
      _ipc_object_reference(iVar1);
    }
  }
  return iVar1;
}

