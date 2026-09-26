
int * _dequeue_head(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (param_1 == piVar1) {
    piVar1 = (int *)0x0;
  }
  else {
    *(int **)(*piVar1 + 4) = param_1;
    *param_1 = *piVar1;
  }
  return piVar1;
}
