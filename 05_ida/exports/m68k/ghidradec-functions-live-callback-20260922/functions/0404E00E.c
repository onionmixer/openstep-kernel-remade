
undefined4 sub_404E00E(char *param_1,char *param_2)

{
  char cVar1;
  char cVar2;
  
  while ((((*param_1 != '\0' && (cVar1 = *param_2, cVar1 != ' ')) && (1 < (byte)(cVar1 - 9U))) &&
         (cVar1 != '\0'))) {
    param_2 = param_2 + 1;
    cVar2 = *param_1;
    param_1 = param_1 + 1;
    if (cVar1 != cVar2) {
      return 1;
    }
  }
  return 0;
}

