
int sub_4028598(int param_1,int param_2)

{
  int iVar1;
  int iStack_8;
  
  if ((((param_2 != 0) && (iVar1 = _getvfs(param_1), iVar1 != 0)) &&
      (iVar1 = (**(code **)(*(int *)(iVar1 + 4) + 0x14))(iVar1,&iStack_8,param_1 + 8), iVar1 == 0))
     && (iStack_8 != 0)) {
    return iStack_8;
  }
  return 0;
}
