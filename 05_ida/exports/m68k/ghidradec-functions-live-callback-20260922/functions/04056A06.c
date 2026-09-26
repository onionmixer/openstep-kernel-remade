
undefined4 _kern_serv_version(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 2) {
    uVar1 = 0x67;
  }
  else {
    *(int *)(*param_1 + 0x4c8) = param_2;
    uVar1 = 0;
  }
  return uVar1;
}

