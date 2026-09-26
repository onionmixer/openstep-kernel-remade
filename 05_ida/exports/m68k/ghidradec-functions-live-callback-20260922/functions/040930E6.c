
int _strlen(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = -1;
  do {
    iVar2 = iVar2 + 1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return iVar2;
}

