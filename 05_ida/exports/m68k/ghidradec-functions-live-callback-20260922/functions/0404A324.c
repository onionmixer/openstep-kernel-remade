
int * _malloc(int param_1)

{
  int *piVar1;
  
  param_1 = param_1 + 8;
  piVar1 = (int *)_kalloc(param_1);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    _bzero(piVar1,param_1);
    *piVar1 = param_1;
    piVar1 = piVar1 + 2;
  }
  return piVar1;
}

