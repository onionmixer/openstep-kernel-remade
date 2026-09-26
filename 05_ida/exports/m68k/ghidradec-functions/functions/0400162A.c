
undefined4 _copystr(char *param_1,char *param_2,sword param_3,int *param_4)

{
  char cVar1;
  sword sVar2;
  
  sVar2 = param_3;
  do {
    sVar2 = sVar2 + -1;
    if (sVar2 == -1) {
      sVar2 = 0;
      break;
    }
    cVar1 = *param_1;
    *param_2 = cVar1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  if (param_4 != (int *)0x0) {
    *param_4 = (int)(sword)(param_3 - sVar2);
  }
  return 0;
}
