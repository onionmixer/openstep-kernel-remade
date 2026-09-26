
void _mig_strncpy(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (0 < param_3) {
    iVar2 = 1;
    pcVar3 = param_1;
    if (1 < param_3) {
      do {
        cVar1 = *param_2;
        param_1 = pcVar3 + 1;
        *pcVar3 = cVar1;
        if (cVar1 == '\0') {
          return;
        }
        iVar2 = iVar2 + 1;
        param_2 = param_2 + 1;
        pcVar3 = param_1;
      } while (iVar2 < param_3);
    }
    *param_1 = '\0';
  }
  return;
}

