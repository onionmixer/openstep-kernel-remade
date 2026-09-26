
undefined4 _nb_write(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if ((uint)(int)*(sword *)(param_1 + 8) < (uint)(param_3 + param_2)) {
    uVar1 = 0xffffffff;
  }
  else {
    _bcopy(param_4,*(int *)(param_1 + 4) + param_1 + param_2,param_3);
    uVar1 = 0;
  }
  return uVar1;
}

