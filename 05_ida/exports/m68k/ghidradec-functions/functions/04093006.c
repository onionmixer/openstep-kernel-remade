
char * _index(char *param_1,int param_2)

{
  char *pcVar1;
  
  if (param_2 == 0) {
    do {
      pcVar1 = param_1;
      param_1 = pcVar1 + 1;
    } while (*pcVar1 != '\0');
    return pcVar1;
  }
  do {
    pcVar1 = param_1;
    if (*pcVar1 == '\0') {
      return (char *)0x0;
    }
    param_1 = pcVar1 + 1;
  } while ((char)param_2 != *pcVar1);
  return pcVar1;
}
