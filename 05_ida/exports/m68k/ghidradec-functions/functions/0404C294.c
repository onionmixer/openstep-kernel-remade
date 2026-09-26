
undefined4 sub_404C294(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  while( true ) {
    if (param_3 == 0) {
      return 0;
    }
    iVar1 = param_2[1];
    param_3 = param_3 + (iVar1 + 2) * -4;
    iVar2 = _thread_setstatus(param_1,*param_2,param_2 + 2,iVar1);
    if (iVar2 != 0) break;
    param_2 = param_2 + 2 + iVar1;
  }
  return 4;
}
