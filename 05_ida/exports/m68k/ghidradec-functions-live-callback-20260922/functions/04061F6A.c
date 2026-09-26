
undefined4 _unix_pid(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x34) == 0)) {
    *param_2 = -1;
    uVar1 = 5;
  }
  else {
    *param_2 = (int)*(sword *)(*(int *)(param_1 + 0x34) + 0x30);
    uVar1 = 0;
  }
  return uVar1;
}

