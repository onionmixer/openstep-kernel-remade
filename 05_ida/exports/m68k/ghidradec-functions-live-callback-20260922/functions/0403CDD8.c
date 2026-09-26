
int * _ipc_kmsg_dequeue(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    piVar2 = (int *)*piVar1;
    if (piVar1 == piVar2) {
      *param_1 = 0;
    }
    else {
      piVar3 = (int *)piVar1[1];
      *param_1 = (int)piVar2;
      piVar2[1] = (int)piVar3;
      *piVar3 = (int)piVar2;
    }
  }
  return piVar1;
}

