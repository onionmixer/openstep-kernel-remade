
undefined4 sub_404C2E4(undefined4 param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  
  *param_4 = 0;
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    iVar1 = param_2[1];
    param_3 = param_3 + (iVar1 + 2) * -4;
    iVar2 = _thread_userstack(param_1,*param_2,param_2 + 2,iVar1,param_4);
    if (iVar2 != 0) break;
    param_2 = param_2 + 2 + iVar1;
  }
  return 4;
}
