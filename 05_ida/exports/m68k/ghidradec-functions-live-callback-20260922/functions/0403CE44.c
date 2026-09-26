
int _ipc_kmsg_queue_next(int *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (iVar1 == *param_1) {
    iVar1 = 0;
  }
  return iVar1;
}

