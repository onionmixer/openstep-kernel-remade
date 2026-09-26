
int * _snd_get_owner(int *param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  while( true ) {
    if (piVar1 == param_1) {
      return (int *)0x0;
    }
    if (param_2 == *piVar1) break;
    piVar1 = (int *)piVar1[2];
  }
  return piVar1;
}

