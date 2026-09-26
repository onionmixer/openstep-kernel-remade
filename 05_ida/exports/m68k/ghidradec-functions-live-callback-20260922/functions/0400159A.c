
undefined4 _copyoutstr(char *param_1,char *param_2,uint param_3,int *param_4)

{
  char cVar1;
  uint uVar2;
  word wVar3;
  
  uVar2 = param_3;
  if ((int)param_3 < 1) {
    return 1;
  }
  do {
    wVar3 = (sword)uVar2 - 1;
    if (wVar3 == 0xffff) {
      wVar3 = 0;
      break;
    }
    cVar1 = *param_1;
    *param_2 = cVar1;
    uVar2 = (uint)wVar3;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  if (param_4 != (int *)0x0) {
    *param_4 = (int)(sword)((sword)param_3 - wVar3);
  }
  return 0;
}

