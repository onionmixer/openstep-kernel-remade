
int _strncmp(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  
  while( true ) {
    if (param_3 < 1) {
      return 0;
    }
    cVar1 = *param_1;
    if (cVar1 != *param_2) break;
    param_3 = param_3 + -1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    if (cVar1 == '\0') {
      return 0;
    }
  }
  return (int)cVar1 - (int)*param_2;
}
