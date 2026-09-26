
undefined4
-[HashTable nextState:key:value:]
          (int param_1,undefined4 param_2,int *param_3,undefined4 *param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = param_3[1];
  iVar4 = *(int *)(param_1 + 0x14);
  while( true ) {
    if (iVar1 != 0) {
      iVar3 = param_3[1];
      param_3[1] = iVar3 + -1;
      iVar1 = *(int *)(iVar4 + *param_3 * 8 + 4);
      iVar4 = (iVar3 + -1) * 8;
      uVar2 = *(undefined4 *)(iVar1 + iVar4 + 4);
      *param_4 = *(undefined4 *)(iVar1 + iVar4);
      *param_5 = uVar2;
      return 1;
    }
    iVar1 = *param_3 + -1;
    if (*param_3 == 0) break;
    *param_3 = iVar1;
    iVar1 = *(int *)(iVar4 + iVar1 * 8);
    param_3[1] = iVar1;
  }
  *param_4 = 0;
  *param_5 = 0;
  return 0;
}

