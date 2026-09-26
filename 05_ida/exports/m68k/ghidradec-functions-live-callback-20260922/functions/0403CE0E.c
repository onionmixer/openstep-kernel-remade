
void _ipc_kmsg_rmqueue(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)*param_2;
  piVar2 = (int *)param_2[1];
  if (param_2 == piVar1) {
    *param_1 = 0;
  }
  else {
    if (param_2 == (int *)*param_1) {
      *param_1 = (int)piVar1;
    }
    piVar1[1] = (int)piVar2;
    *piVar2 = (int)piVar1;
  }
  return;
}

