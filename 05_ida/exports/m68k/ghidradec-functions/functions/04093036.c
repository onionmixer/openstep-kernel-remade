
char * _strncpy(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar3 = param_1;
  do {
    iVar2 = param_3 + -1;
    if (param_3 < 1) {
      return param_1;
    }
    cVar1 = *param_2;
    pcVar4 = pcVar3 + 1;
    *pcVar3 = cVar1;
    param_3 = iVar2;
    pcVar3 = pcVar4;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  while (0 < iVar2) {
    *pcVar4 = '\0';
    iVar2 = iVar2 + -1;
    pcVar4 = pcVar4 + 1;
  }
  return param_1;
}
