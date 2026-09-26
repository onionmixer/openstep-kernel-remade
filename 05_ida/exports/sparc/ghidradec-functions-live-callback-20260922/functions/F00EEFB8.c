
undefined4 _NXNextMapState(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  iVar2 = *param_2;
  while( true ) {
    *param_2 = iVar2 + -1;
    if (iVar2 + -1 == -1) {
      return 0;
    }
    iVar2 = *param_2;
    iVar1 = *(int *)(iVar3 + iVar2 * 8);
    if (iVar1 != -1) break;
    iVar2 = *param_2;
  }
  *param_3 = iVar1;
  *param_4 = *(undefined4 *)(iVar3 + iVar2 * 8 + 4);
  return 1;
}

