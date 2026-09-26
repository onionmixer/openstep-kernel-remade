
int _strcmp(char *param_1,char *param_2)

{
  char cVar1;
  
  do {
    if (*param_1 != *param_2) {
      return (int)*param_1 - (int)*param_2;
    }
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  return 0;
}

