
undefined4 sub_4038D40(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &param_1;
  while( true ) {
    if (param_1 == 0) {
      return 0;
    }
    iVar1 = *piVar2;
    if (param_2 == iVar1) break;
    piVar2 = (int *)(iVar1 + 0x18);
    param_1 = *piVar2;
  }
  *piVar2 = *(int *)(iVar1 + 0x18);
  return 1;
}
