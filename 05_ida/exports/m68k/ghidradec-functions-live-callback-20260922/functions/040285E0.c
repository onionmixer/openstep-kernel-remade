
int sub_40285E0(sword *param_1,sword *param_2)

{
  int iVar1;
  
  if ((*param_1 == *param_2) && (*param_1 == 2)) {
    iVar1 = -(int)-(*(int *)(param_1 + 2) == *(int *)(param_2 + 2));
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

