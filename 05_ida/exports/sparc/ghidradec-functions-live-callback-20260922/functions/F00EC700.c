
int sub_F00EC700(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != (int *)0x0) && (iVar1 = 0, 0 < *param_1)) {
    iVar2 = 0;
    do {
      iVar1 = iVar1 + 1;
      if (*(int *)((int)param_1 + iVar2 + 4) == param_2) {
        return (int)param_1 + iVar2 + 4;
      }
      iVar2 = iVar1 * 8;
    } while (iVar1 < *param_1);
  }
  return 0;
}

