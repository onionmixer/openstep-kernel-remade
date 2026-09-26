
undefined4 _kern_serv_log_level(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 0x30);
  *(int *)(iVar1 + 0x30) = param_2;
  if (iVar2 == 0) {
    if (param_2 != 0) {
      sub_4057042(iVar1 + 0x24,500);
      return 0;
    }
  }
  else if (param_2 != 0) {
    return 0;
  }
  if (iVar2 != 0) {
    sub_405709E(iVar1 + 0x24);
  }
  return 0;
}

