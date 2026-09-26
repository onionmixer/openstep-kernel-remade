
undefined4 _pn_getcomponent(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = 0xff;
  for (pcVar3 = *(char **)(param_1 + 4); (0 < iVar1 && (*pcVar3 != '/')); pcVar3 = pcVar3 + 1) {
    iVar2 = iVar2 + -1;
    if (iVar2 < 0) {
      return 0x3f;
    }
    *param_2 = *pcVar3;
    iVar1 = iVar1 + -1;
    param_2 = param_2 + 1;
  }
  *(char **)(param_1 + 4) = pcVar3;
  *(int *)(param_1 + 8) = iVar1;
  *param_2 = '\0';
  return 0;
}

