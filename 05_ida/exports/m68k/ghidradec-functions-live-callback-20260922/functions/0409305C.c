
char * _strcat(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = param_1;
  do {
    pcVar3 = pcVar2;
    pcVar2 = pcVar3 + 1;
  } while (*pcVar3 != '\0');
  do {
    cVar1 = *param_2;
    *pcVar3 = cVar1;
    pcVar3 = pcVar3 + 1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  return param_1;
}

