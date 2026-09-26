
char * _strcpy(char *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  cVar1 = *param_2;
  *param_1 = cVar1;
  pcVar3 = param_1 + 1;
  for (pcVar2 = param_2 + 1;
      ((((cVar1 != '\0' && (cVar1 = *pcVar2, *pcVar3 = cVar1, cVar1 != '\0')) &&
        (cVar1 = pcVar2[1], pcVar3[1] = cVar1, cVar1 != '\0')) &&
       ((cVar1 = pcVar2[2], pcVar3[2] = cVar1, cVar1 != '\0' &&
        (cVar1 = pcVar2[3], pcVar3[3] = cVar1, cVar1 != '\0')))) &&
      ((cVar1 = pcVar2[4], pcVar3[4] = cVar1, cVar1 != '\0' &&
       ((cVar1 = pcVar2[5], pcVar3[5] = cVar1, cVar1 != '\0' &&
        (cVar1 = pcVar2[6], pcVar3[6] = cVar1, cVar1 != '\0')))))); pcVar2 = pcVar2 + 8) {
    cVar1 = pcVar2[7];
    pcVar3[7] = cVar1;
    pcVar3 = pcVar3 + 8;
  }
  return param_1;
}

